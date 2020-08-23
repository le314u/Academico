const error = require('./erro')

module.exports=class Tape{
    constructor() {
        this.tape = [];
        this.header = 0;
        this.state = 0;
        this.symbol = ''
    }
    read(){
        if(this.tapeEmpty() || !this.hasSlot()){
            this.symbol = '_'
            this.tape.push('_')
        }else {
            this.symbol = this.tape[this.header]
        }
        return this.symbol;
    }
    write(symbol){
        if(this.tapeEmpty() || !this.hasSlot()){
            this.tape.push(''+symbol)
        }else {
            this.tape[this.header] = ''+symbol
        }
    }
    move(direction){
        let move = {
            e:()=>{//Move para esquerda
                if(!this.hasSpaceInLeft()){
                    this.tape.unshift('_')
                }else{
                    this.header = this.header-1
                }
            },
            i:()=>{},//Imovel
            d:()=>{//Move para a direita
                if(!this.hasSpaceInRigth()){
                    this.tape.push('_')
                } 
                this.header = this.header+1 // De qualquer maneira o header muda sendo o ultimo ou não
            }
        }
        try {
            move[direction]()
        } catch (e) {
            //Dificilmente chegará aki
            throw new error(
                'Movimento de fita',
                "'"+direction+"'"+' não é uma direção valida'
            )
        }
        
    }
    hasSpaceInLeft(){
        return !(this.header == 0);
    }
    hasSpaceInRigth(){
        return !(this.header == this.tape.length || this.tape.length == 0);
    }
    tapeEmpty(){
        return this.tape.length == 0;
    }
    hasSlot(){
        return this.tape[this.header] !== undefined;
    }
    print(fita){
        let newTape = []
        for (let index = 0; index < this.tape.length; index++) {
            if( index == this.header){
                newTape.push('['+this.tape[index]+']') 
            } else {
                newTape.push(this.tape[index])
            }
        }
        console.log(`Fita ${fita}: ${newTape}`)
    }
}