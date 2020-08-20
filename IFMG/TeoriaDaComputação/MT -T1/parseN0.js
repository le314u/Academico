const error = require('./error')
module.exports=class Parse {
    //Analise da String
    static whatIsComand(string){
        //Verifica se é uma computação
        if(this.checkComputation(string)){
            return 'comand';
        }
        // Verifica se é uma chamada de Bloco
        if(this.checkFunction(string)){
            return 'function';
        }
        // Verifica se é um comando especial
        if(this.checkSpecial(string)){
            return 'special';
        }
        // Verifica se é um alias
        if(this.checkAlias(string)){
            return 'alias';
        }
        // Verifica se é uma declaração de inicio de bloco
        if(this.checkInitBlock(string)){
            return 'initBlock';
        }
        // Verifica se é uma declaração de Fim de bloco
        if(this.checkEndBlock(string)){
            return 'endBlock';
        }
        // Verifica se é uma declaração de retorno de bloco
        if(this.checkReturnBlock(string)){
            return 'returnBlock';
        }
        // Verifica se é uma declaração de retorno de bloco
        if(this.checkNothing(string)){
            return 'nothing';
        }
        return 'error'
    }
    // Verifica se é um comando de computação
    // <estadoA> <fitaA> <simbA> <moveA> - - <estadoB> <fitaB> <simbB> <moveB>
    static checkComputation(string){
        let chunks = this.filter(string);
        if((this.hasNChunks(chunks, 9) || this.hasNChunks(chunks, 10)) && chunks[4] === '--'){
            let computation = this.getComputation(string)
            return(
                this.isState(computation.read.state) &&
                this.isMove(computation.read.move)&&
                this.isTape(computation.read.tape)&&
                this.isState(computation.write.state)&&
                this.isMove(computation.write.move)&&
                this.isTape(computation.write.tape)
            )
        }
    }
    // Verifica se é a chamada de um bloco
    // <estado atual> <identificador de bloco> <estado de retorno>
    static checkFunction(string){
        let chunks = this.filter(string);
        if( this.hasNChunks(chunks, 3) ){
            let func = this.getFunction(string)
            return (
                this.isState(func.state) &&
                this.isState(func.return)
            )
        } else {
            return false
        }
    }
    // Verifica se é um comando Especial
    // <estado atual> pare
    // <estado atual> aceite
    // <estado atual> rejeite
    static checkSpecial(string){
        
        let chunks = this.filter(string);
        if( this.hasNChunks(chunks, 2) ){
            return (
                this.isState(chunks[0]) &&
                chunks[1] != 'retorne'
            );
        } else {
            return false
        }
    }
    // Verifica se é um Alias
    // $<letraMinuscula> = "<string>"
    static checkAlias(string){
        let chunks = this.filter(string);
        if( this.hasNChunks(chunks, 3)){
            return this.isAlias(chunks[0])
        } else{
            return false
        }
    }
    static checkInitBlock(string){
        // inicio <identificador de bloco> <estado inicial>
        let chunks = this.filter(string);
        if( this.hasNChunks(chunks, 3)){
            return chunks[0] == 'inicio' && this.isState(chunks[2])
        } else{
            return false
        }
    }
    static checkEndBlock(string){
        // fim <identificador de bloco>
        let chunks = this.filter(string);
        if( this.hasNChunks(chunks, 2)){
            return chunks[0] == 'fim'
        } else{
            return false
        }
    }
    static checkReturnBlock(string){
        // <estado atual> retorne
        let chunks = this.filter(string);
        if( this.hasNChunks(chunks, 2)){
            return this.isState(chunks[0]) && chunks[1] == 'retorne'
        } else{
            return false
        }
    }
    // Analise do pedaço
    static checkNothing(string){
        let chunks = this.filter(string);
        return ( chunks.length <=1 && (chunks[0] == '' || chunks[0] == ' ') )
    }
    static hasNChunks(chunks, chunksNumber){
        return chunks.length == chunksNumber
    }
    static isState(chunk){
        // Inteiro de até 4 dígitos.
        return !isNaN(parseInt(chunk)) && chunk.toString().length <=4
    }
    static isAlias(chunk){
        try {
            return chunk[0] == '$' && 
            chunk.length == 2 &&
            (chunk[1].charCodeAt(0) >= 97 && chunk[1].charCodeAt(0) <= 122);
        } catch (error) {
            return false
        }
    }
    // e i ou d
    static isMove(chunk){
        return chunk == 'e' || chunk == 'i' || chunk == 'd'
    }
    // X Y ou Z
    static isTape(chunk){
        return chunk == 'X' || chunk == 'Y' || chunk == 'Z'
    }
    // Filtros de string para chunk
    static removeComent(string){
        // Cuidado para ter certeza que ; não é um caracter valido
        return string.split(';')[0]
    }
    // Transforma espaços duplicados em espaços simples
    static removeSpaces(string){
        return string.replace(/\s{2,}/g, ' ');
    }
    // Transforma tabulação em espaço
    static removeTab(string){
        return string.replace(/\t/g, '');
    }
    static removeNewLine(string){
        return string.replace(/\n/g, '');
    }
    static filter(string){
        string = this.removeComent(string);
        string = this.removeTab(string);
        string = this.removeSpaces(string);
        string = this.removeNewLine(string);
        string = string.trim()
        return string.split(' ');
    }
    // transforma string->[..chunks]->partes Logicas
    static getComputation(string){
        let chunks = this.filter(string);
        return {
            read:{
                state:chunks[0],
                tape:chunks[1],
                symbol:chunks[2],
                move:chunks[3]
            },
            //--
            write:{
                state:chunks[5],
                tape:chunks[6],
                symbol:chunks[7],
                move:chunks[8]
            }
        }
    }
    static getFunction(string){
        let chunks = this.filter(string);
        return {
            state:chunks[0],
            function:chunks[1],
            return:chunks[2]
        }
    }
    static getAlias(string){
        let aux = string.split(' = ');
        return{
            alias:aux[0],
            content:aux[1].split('')
        }
    }
    static getMetaBlock(string){
        let chunks = this.filter(string);
        if(Parse.whatIsComand(string)=='initBlock'){
            return {
                name:chunks[1],
                state:chunks[2]
            }
        }
        if(Parse.whatIsComand(string)=='endBlock'){
            return {
                name:chunks[1]
            }
        }
        if(Parse.whatIsComand(string)=='returnBlock'){
            return {
                state:chunks[0]
            }
        }
    }
}