let tape = require('./tape')
let parseN1 = require('./parseN1')
let erro = require('./erro')

module.exports = class Mt{

    constructor(declarations, input) {
        this.flag = ''
        this.X = new tape();
        this.Y = new tape();
        this.Z = new tape();
        this.declarations = declarations
        this.bloco = 'main';
        this.stack = [];
        this.program = {}
        try { 
            this._init(input)
        } catch (error) {
            console.log(error.name,error.message)
        }

    }
    _init(inputTape){
        //Declaração de funções internas
        let initTap = (inputTape)=>{
            this.X.tape = inputTape.split('');
        }
        let checkSintaxy = ()=>{
            let bool = parseN1.allStringValid(this.declarations)
            console.log('Sintaxy:'+bool)
            return bool
        }
        let checkSemantica = ()=>{
            let bool = (typeof parseN1.getProgram(this.declarations)=='object')
            console.log('Semantica:'+bool)
            return bool
        }
        let loadProgram = ()=>{
            this.program = parseN1.getProgram(this.declarations)
        }

        // Carrega a fita X
        initTap(inputTape)

        // Verifica se tem erro de Sintaxy e de Semantica
        if(checkSintaxy() && checkSemantica()){
            // Carrega o Programa na Memoria
            loadProgram();
        }else{
            //Provavelmente nunca chega aki
            throw new erro(
                "Entrada",
                "Programa não pode ser carregado na memória"
            )
        }
        // Seta o escopo como bloco main
        // Pega o Estado que Inicia
        // Pega o indice do comando dentro do bloco

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
}