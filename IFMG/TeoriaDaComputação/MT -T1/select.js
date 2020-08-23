// Trocar o nome para HEAP ou RAM

module.exports = class Select{
    constructor(program, alias){
        this.program = program
        this.alias = alias
        this.block = Object
        this.state = 0 // Estado dentro do bloco atual
        this.stack = [];// Pilha de par ordenado bloco estado
    }
    
    // Empilha Bloco
    push(block){
        //Empilha
        this.stack.push({
            state:block['stateInit'],
            block:block
        })
        //Altera escopo
        this._setBlock(block)
    }
    // Desempilha Bloco
    pop(){
        // Tira o ultimo elemento da pilha
        this.stack.pop()
        // Altera Escopo
        let lastBlock = this.stack[this.stack.length-1]
        this._setBlock(lastBlock['block'], lastBlock['state'])
    }

    symbolInAlias(symbol, alias){
        // Verifica se o symbol esta dentro de alias 
        // retorna symbol || false
    }
    //Altera o Scopo
    _setBlock(block, state=block['stateInit'] ){
        this.block = block
        this._setState(state)
    }
    //Altera o Estado
    _setState(state){
        this.state = state
        try {
            this.stack[this.stack.length-1]['state']=state
        } catch (error) {}
    }
    comandMatch(symbol, state){ //Obsoleto
        // retorna uma lista com todos os 'comandos' que casam (state,symbol)
        // Respeitando o escopo ( 'nome do bloco') e a ordem que aparece 
    }

}