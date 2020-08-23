let tape = require('./tape')
let parseN1 = require('./parseN1')
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
            return parseN1.allStringValid(declarations)
        }
        let checkSemantica = (declarations)=>{
            return (typeof parseN1.getProgram(declarations)=='object')
        }
        let loadProgram = (declarations)=>{
            this.program = parseN1.getProgram(declarations)
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
            //Provavelmente nunca chega aki
            throw new erro(
                "Entrada",
                "Programa não pode ser carregado na memória"
            )
        }
        // Seta o escopo como bloco main
        this.scop.push( this.whereIsMain() )
        console.log(this.scop)

    }

    //Daqui pra baixo tem que revisar TUDO
    compute(){
        //Verifica o que é o comando
        let comand = this.whatNextStep()
        //Executa o comando
            // Se função  chama a função altera o scopo
            // Se retorno desempilha um bloco e e altera o escopo
            // Se computação altera a maquina
            // Se especial faz o que se pede
                //Aceita
                //Recusa
                //Para
    }
    whatNextStep(){
        for (let index = indiceAtual; index < ultimoIndice; index++) {
            // Verifico se o comando em index é valido
            // caso seja retorna o comando
            // caso não seja passa pro proximo
        }
        return 'erro'
    }
    overflow(){
        console.log('queu overflow')
    }
    whereIsMain(){
        // precorre todo o programa procurando um bloco main
        for (let index = 0; index < this.program['block'].length; index++) {
            if(this.program['block'][index]['name'] == 'main'){
                return this.program['block'][index]
            }
        }
        throw new erro(
            'Semantico',
            'Não possui Bloco main'
        )
    }
}