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

exemplo = `
$d = '0123456789'
inicio main 01
        01 X $d i -- 03 X $d i
        01 X ∗ i -- 05 X ∗ i
        03 copiaX 04
        04 aceita
        05 rejeita
fim main
inicio copiaX 1
        01 X $d i -- 03 Y $d e
        01 X ∗ i -- 02 X ∗ i
        02 retorne
        03 X $d e -- 01 Z $d e
fim copiaX
`
p=new parseN1.Program()
meta = p.analize(exemplo)

console.log(p.getBlock(exemplo.split('\n'), meta.block[0]))
console.log(p.getBlock(exemplo.split('\n'), meta.block[1]))
