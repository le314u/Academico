// Trocar o nome para HEAP ou RAM

module.exports = class Mt_Heap{
    constructor(program, alias){
        this.program = program
        this.alias = alias
        this.block = Object
        this.state = 0 // Estado dentro do bloco atual
        this.stack = [];// Pilha de par ordenado bloco estado
    }
    
    // Empilha Bloco
    push(block, state=block['stateInit']){
        //Altera State do ultimo bloco
        this.setState(state)
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

    // Verifica se o symbol esta dentro de alias 
    // retorna symbol || false
    symbolInAlias(symbol, alias){
        let retorno = false // retorno padrão caso não ache nada
        this.alias.forEach(element => {
            if(element.alias == alias){// Verifica qual alias bate com o descritor
                if( element.content.includes(symbol) ){// Verifica se symbol faz parte do alias
                    retorno = symbol
                }
            }
        });
        return retorno
    }
    // Verifica se o symbol esta dentro de alias 
    // retorna symbol || false
    validAlias(alias){
        let retorno = false // retorno padrão caso não ache nada
        this.alias.forEach(element => {
            if(element.alias == alias){// Verifica se existe um descritor de alias que de match
                retorno = true
            }
        });
        return retorno
    }
    //Altera o Scopo
    _setBlock(block, state=block['stateInit'] ){
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
}