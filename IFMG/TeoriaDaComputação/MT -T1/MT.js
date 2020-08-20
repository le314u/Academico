let tape = require('./tape')
let parseN0 = require('./parseN0')
let parseN1 = require('./parseN1')
let input = require('./input')
let cli = require('./cli')

module.exports = class MT{

    constructor(declarations) {
        this.flag = ''
        this.X = new tape();
        this.Y = new tape();
        this.Z = new tape();
        this.declarations = declarations
        this.bloco = 'main';
        this.stack = [];
        this.program = {}
        this.init('AbcdAC') // TODO  tirar HardCoe

    }
    init(stringFita){
        //Declaração de funções internas
        let initTap = (stringFita)=>{
            this.X.tape = stringFita.split('');
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
        initTap(stringFita)
        // Verifica se tem erro de Sintaxy e de Semantica
        if(checkSintaxy() && checkSemantica()){
            // Carrega o Programa na Memoria
            loadProgram();
        }
        this.compute()
    }
    compute(){
        console.log(this.program)

    }
    alias(alias){

    }
    bloco(){

    }
    overflow(){
        console.log('queu overflow')
    }
}