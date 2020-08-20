module.exports = class Select{
    constructor(program, alias){
        this.program = program
        this.alias = alias
        this.block = 0
        this.indiceOut = 0
        this.indiceIn = 0
    }
    //Altera o Scopo
    setBlock(block, indiceOut,indiceIn){
        this.block = block
        this.indiceOut = indiceOut
        this.indiceIn = indiceIn
    }
    symbolInAlias(symbol, alias){
        // Verifica se o symbol esta dentro de alias 
        // retorna symbol|| false
    }
    comandMatch(symbol, state){
        // retorna uma lista com todos os 'comandos' que casam (state,symbol)
        // Respeitando o escopo ( 'nome do bloco') e a ordem que aparece 
    }

}