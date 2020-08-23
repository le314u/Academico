// Trocar o nome para HEAP ou RAM

module.exports = class Select{
    constructor(program, alias){
        this.program = program
        this.alias = alias
        this.block = Object
        this.state = 0 // Estado dentro do bloco atual
        this.stack = [];// Pilha de par ordenado bloco estado
    }
    //Altera o Scopo
    setBlock(block, state=block['stateInit'] ){
        this.block = block
        this.setState(state)
    }
    //Altera o Estado
    setState(state){
        this.state = state
        try {
            this.stack[this.stack.length-1]['state']=state
        } catch (error) {}
    }
    // Empilha Bloco
    push(block){
        //Empilha
        this.stack.push({
            state:block['stateInit'],
            block:block
        })
        //Altera escopo
        this.setBlock(block)
    }
    // Desempilha Bloco
    pop(){
        // Tira o ultimo elemento da pilha
        this.stack.pop()
        // Altera Escopo
        let lastBlock = this.stack[this.stack.length-1]
        this.setBlock(lastBlock['block'], lastBlock['state'])
    }

    symbolInAlias(symbol, alias){
        // Verifica se o symbol esta dentro de alias 
        // retorna symbol || false
    }
    comandMatch(symbol, state){
        // retorna uma lista com todos os 'comandos' que casam (state,symbol)
        // Respeitando o escopo ( 'nome do bloco') e a ordem que aparece 
    }

}