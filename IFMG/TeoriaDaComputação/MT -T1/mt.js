let tape = require('./tape')
let Parse = require('./parseN1')
let erro = require('./erro')
let scop = require('./select')
module.exports = class Mt{

    constructor(declarations, input) {
        this.X = new tape();
        this.Y = new tape();
        this.Z = new tape();
        // Para Funcionar
        this.program = {}
        this.scop = Object
        try { 
            this._init(declarations, input)
        } catch (error) {
            throw error
        }
    }
    _init(declarations, inputTape){
        //Declaração de funções internas
        let initTap = (inputTape)=>{
            this.X.tape = inputTape.split('');
        }
        let checkSintaxy = (declarations)=>{
            return Parse.allStringValid(declarations)
        }
        let checkSemantica = (declarations)=>{
            return (typeof Parse.getProgram(declarations)=='object')
        }
        let loadProgram = (declarations)=>{
            this.program = Parse.getProgram(declarations)
        }
        let loadScopoManeger = ()=>{
            this.scop = new scop(this.program, this.program['alias'])
        }

        // Carrega a fita X
        initTap(inputTape)

        // Verifica se tem erro de Sintaxy e de Semantica
        if(checkSintaxy(declarations) && checkSemantica(declarations)){
            // Carrega o Programa na Memoria
            loadProgram(declarations);
            loadScopoManeger();
        }else{
            throw new erro(
                "Entrada",
                "Programa não pode ser carregado na memória"
            )
        }
        // Seta o escopo como bloco main
        this.scop.push( this.whereIsBlock('main') )

        let i = 0
        while (this.compute() && i++ <= 10) {
            this.X.print('X')
            this.Y.print('Z')
            this.Z.print('Z')
            console.log("-----------")
            console.log(this.scop.stack)
        }
    }

    //Daqui pra baixo tem que revisar TUDO
    compute(){
        //Verifica o que é o comando
        let comand = this.whatNextStep()
        //Executa o comando
            // Se função
            if( comand[0] == Parse.FUNCTION ){
                // chama a função ou seja:
                // empilha o bloco e altera o scopo
                this.scop.push( this.whereIsBlock(comand[1].function), comand[1].return )
            }
            // Se retorno de função
            if( comand[0] == Parse.RETURN_BLOCK ){
                //desempilha um bloco  e altera o escopo 
                this.scop.pop()
            }
            // Se computação altera a maquina
            if( comand[0] == Parse.COMAND ){
                // Executa lado Esquerdo
                let left = comand[1].read
                let state = this[left.tape].read()//Le a Fita
                this[left.tape].move(left.move)//Move a fita
                
                //Executa lado direito
                let rigth = comand[1].write
                this.scop.setState(rigth.state)//Altera Estado
                this[rigth.tape].write(rigth.symbol)//Escreve
                this[rigth.tape].move(rigth.move)//Move
            }
            // Se especial faz o que se pede
            if([Parse.ACEITE,Parse.REJEITE,Parse.PARE].includes(comand)  ){
                //Aceita
                //Recusa
                //Para
                return false
            }
            if(comand=='error'){
                throw new erro("Erro","Não sei ainda")
            }
            return true
                
    }
    whatNextStep(){ // Verifica qual o proximo comando aceito (' de maneira deterministica ')
        let indiceAtual = 0
        let ultimoIndice = 0
        try {
            ultimoIndice = this.scop.block.order.length-1
        } catch {
            ultimoIndice = -1
        }
        let blocks = this.scop.block.order
        let isComand = (type)=>{
            return type == Parse.COMAND
        }
        let isFunction = (type)=>{
            return type == Parse.FUNCTION
        }
        let isSpecial = (type)=>{
            return [Parse.ACEITE, Parse.REJEITE,Parse.RETURN_BLOCK].includes( type )
        }
        let state_sync = (state)=>{// Verifica se o estado do comando é o mesmo da maquina
            return this.scop.state == state
        }
        let blockExist=(block)=>{
            return (this.whereIsBlock(block) !== undefined)
        }
        // Passa por todos os comandos do bloco
        for (let index = indiceAtual; index <= ultimoIndice; index++) {
            let type = blocks[index][0]
            let payLoad = blocks[index][1]
            if( isComand(type) ){
                if( state_sync(payLoad.read.state)){// Verifico se o comando pode ser computado
                    let symbol = payLoad.read.symbol
                    if(symbol == '*'){// se for um caracter especial
                        return blocks[index]
                    }else if(symbol.length > 1 && symbol[0] == '$'){// se for um alias 
                        if(this.scop.symbolInAlias(symbol, alias)){
                            return blocks[index]
                        }
                    }else if(symbol == this[payLoad.read.tape].read()){// se for um literal
                        return blocks[index]
                    }
                }
            }else if( isFunction(type) ){
                if( state_sync(payLoad.state) && blockExist(payLoad.function) ){// Verifico se o bloco pode ser chamado
                    return blocks[index]
                }
            }else if( isSpecial(type) ){
                if(state_sync(payLoad.state)){// Verifico se a declaração pode ser executada
                    return blocks[index]
                }
            }
        }
        return Parse.ERROR
    }
    
    whereIsBlock(blockName){
        // precorre todo o programa procurando o blockName
        for (let index = 0; index < this.program['block'].length; index++) {
            if(this.program['block'][index]['name'] == blockName){
                return this.program['block'][index]
            }
        }
        throw new erro(
            'Semantico',
            'Não possui Bloco '+blockName
        )
    }
    overflow(){
        console.log('queu overflow')
    }
}