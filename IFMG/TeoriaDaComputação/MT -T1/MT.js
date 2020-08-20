let tape = require('./tape')
let parseN0 = require('./parseN0')
let parseN1 = require('./parseN1')
let input = require('./input')
let cli = require('./cli')

class MT{

    constructor() {
        this.X = new Tape();
        this.Y = new Tape();
        this.Z = new Tape();
        this.bloco = 'main';
    }
    compute(string){

    }
    alias(){

    }
    bloco(){

    }
    overflow(){
        console.log('queu overflow')
    }
}

code = `
$d = '0123456789'
inicio main 01
        01 X $d i -- 03 X $d i
        01 X ∗ i -- 05 X ∗ i
        03 copiaX 04
        04 aceita
        05 rejeita
fim main
inicio copiaX 01
        01 X $d i -- 03 Y $d e
        01 X ∗ i -- 02 X ∗ i
        02 retorne
        03 X $d e -- 01 Z $d e
fim copiaX
`
p=new parseN1()
declarations = code.split('\n')
console.log('-----------')
console.log('Sintaxy:'+p.allStringValid(declarations))
console.log('Semantica:'+(typeof p.getProgram(declarations)=='object'))
console.log(p.getProgram(declarations))
console.log('-----------')
//console.log(p.getBlock(code.split('\n'), meta.block[0]))