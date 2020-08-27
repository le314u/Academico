let tape = require('./mt_tape')
let erro = require('./erro')
let heap = require('./mt_heap')
let mt_flags = require('./mt_flags')
let mt_print = require('./mt_print')
let Parse = require('./parseN1')

module.exports = class Mt{
    constructor(declarations, input, cliPayLoad) {
        // Fitas
        this.X = new tape();
        this.Y = new tape();
        this.Z = new tape();
        // Flags de controle (step's) Define se a maquina esta funcionando ou não;
        this.controll = new mt_flags(cliPayLoad)
        // Para Funcionar
        this.program = {}
        this.heap = Object
        this.print = Object
        // Comando
        this.comand = ''
        this.stringDebug = ''
        
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
            this.heap = new heap(this.program, this.program['alias'])
            // Seta o escopo como bloco main
            this.heap.push( this._whereIsBlock('main') )
        }
        let loadTools = ()=>{
            this.print = new mt_print()
        }

        // Verifica se tem erro de Sintaxy ou de Semantica
        if(checkSintaxy(declarations) && checkSemantica(declarations)){
            // Carrega a fita X
            initTap(inputTape)
            // Carrega o Programa na Memoria
            loadProgram( declarations );
            // Carrega o Gerenciador de Scopo
            loadScopoManeger();
            // Carrega demais Ferramenta
            loadTools();
        }else{
            throw new erro(
                "Entrada",
                "Programa não pode ser carregado na memória"
            )
        }        
    }
    compute(){
        let func = (comand)=>{
            // chama a função ou seja empilha o bloco e altera o scopo
            this.heap.push( this._whereIsBlock(comand.function), comand.return )
        }
        let ret = ()=>{
            //desempilha um bloco  e altera o escopo 
            this.heap.pop()
        }
        let cmd = (comand)=>{
            // Executa lado Esquerdo
            let left = comand.read
            let symbol = this[left.tape].read()//Le a Fita
            this[left.tape].move(left.move)//Move a fita
            //Executa lado direito
            let rigth = comand.write
            this.heap.setState(rigth.state)//Altera Estado
            // se *
            if(rigth.symbol == '*'){
                this[rigth.tape].write(symbol)//Escreve o que foi lido
            } else if(rigth.symbol.length > 1 && rigth.symbol[0] == '$' ) {// se alias
                if(left.symbol == rigth.symbol){
                    this[rigth.tape].write(symbol)//Escreve o que foi lido
                } else {
                    new Error (
                        'Semantica',
                        'Direita alias usa alias porem não é usado lado esquerdo'
                    )
                }
            } else {
                this[rigth.tape].write(rigth.symbol)//Escreve
            }
            this[rigth.tape].move(rigth.move)//Move
        }
        let special = (comand)=>{
            // Se especial faz o que se pede  Aceita || Recusa || Para
            this.controll.disable()
            this.controll.setSpecial(comand)
        }
        let undef = ()=>{
            // Comando Indefinido
            this.controll.setSpecial(Parse.PARE)
            this.controll.disable()
        }
        let exec = (comand) =>{
            if( comand[0] == Parse.FUNCTION ){
                func(comand[1])
            }else if( comand[0] == Parse.RETURN_BLOCK ){
                ret()
            }else if( comand[0] == Parse.COMAND ){
                cmd(comand[1])
            }else if( [Parse.ACEITE,Parse.REJEITE,Parse.PARE].includes(comand)  ){
                special(comand)
            }else{
                undef()
            }
        }

        //Existe um proximo passo  a ser dado?
        if( !(this.controll.hasNextStep()) ){
            //Se não tiver proximo passo pausa
            this.controll.disable()
        } else {
            //Verifica qual sera o comando a ser executado
            let comand = this._whatNextStep();// Qual o proximo passo ?
            this.comand = this.print.logic2String(comand);// Salva o codigo do proximo passo
            // Salva a strign de Debug
            if(this.controll.debug){
                this.stringDebug = this.print.machineDebug( this.comand, this.heap )
            }
            //Executa o comando
            exec(comand)
        }
        return this.controll.run()
    }
    machineState(){
        console.log(
            this.print.machineState( this.controll.getSpecial(), this.X,this.Y,this.Z, )
        )
    }
    _whatNextStep(){ // Verifica qual o proximo comando aceito (' de maneira deterministica ')
        let indiceAtual = 0
        let ultimoIndice = 0
        try {
            ultimoIndice = this.heap.block.order.length-1
        } catch {
            ultimoIndice = -1
        }
        let blocks = this.heap.block.order
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
            return this.heap.state == state
        }
        let blockExist=(block)=>{
            return (this._whereIsBlock(block) !== undefined)
        }
        // Passa por todos os comandos do bloco
        for (let index = indiceAtual; index <= ultimoIndice; index++) {
            let type = blocks[index][0]
            let payLoad = blocks[index][1]
            if( isComand(type) ){// Verifico se o comando pode ser computado
                if( state_sync(payLoad.read.state)){// Verifico se estou no mesmo Estado que o comando analisado
                    let symbol = payLoad.read.symbol
                    if(symbol == '*'){// se for um caracter especial aceita qualquer coisa 
                        return blocks[index]
                    }else if(symbol.length > 1 && symbol[0] == '$'){// se o symbol for um alias 
                        if( this.heap.symbolInAlias(this[payLoad.read.tape].read(),symbol) ){// se alias é compativel com o caracter da fita
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
    _whereIsBlock(blockName){
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