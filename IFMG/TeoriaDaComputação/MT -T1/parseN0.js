const error = require('./erro')
module.exports=class Parse {
    //Constantes
    static COMAND = 'comand'
    static FUNCTION = 'function'
    static PARE = 'pare'
    static REJEITE = 'rejeite'
    static ACEITE = 'aceite'
    static ALIAS = 'alias'
    static INIT_BLOCK = 'initBlock'
    static END_BLOCK = 'endBlock'
    static ERROR = 'error'
    static RETURN_BLOCK = 'returnBlock'
    static NOTHING = 'nothing'

    //Analise da String
    static whatIsComand(string){
        //Verifica se é uma computação
        if(this.checkComputation(string)){
            return this.COMAND;
        }
        // Verifica se é uma chamada de Bloco
        if(this.checkFunction(string)){
            return this.FUNCTION;
        }
        // Verifica se é um comando especial pare
        if(this.checkStop(string)){
            return this.PARE
        }
        // Verifica se é um comando especial rejeite
        if(this.checkReject(string)){
            return this.REJEITE
        }
        // Verifica se é um comando especial aceite
        if(this.checkAcept(string)){
            return this.ACEITE
        }
        // Verifica se é um alias
        if(this.checkAlias(string)){
            return this.ALIAS
        }
        // Verifica se é uma declaração de inicio de bloco
        if(this.checkInitBlock(string)){
            return this.INIT_BLOCK
        }
        // Verifica se é uma declaração de Fim de bloco
        if(this.checkEndBlock(string)){
            return this.END_BLOCK;
        }
        // Verifica se é uma declaração de retorno de bloco
        if(this.checkReturnBlock(string)){
            return this.RETURN_BLOCK;
        }
        // Verifica se é uma declaração de retorno de bloco
        if(this.checkNothing(string)){
            return this.NOTHING;
        }
        return this.ERROR
    }
    // Verifica se é um comando de computação
    // <estadoA> <fitaA> <simbA> <moveA> - - <estadoB> <fitaB> <simbB> <moveB>
    static checkComputation(string){
        let chunks = this.filter(string);
        if((this.hasNChunks(chunks, 9) || this.hasNChunks(chunks, 10)) && chunks[4] === '--'){
            let computation = this.getComputation(string)
            if(this.hasNChunks(chunks, 10) && chunks[9] != '!'){
                return false
            }
                // Erro sintaxy parte da leitura 
                this.erroState(computation.read.state, string)
                this.erroMove(computation.read.move, string)
                this.erroTape(computation.read.tape, string)
                // Erro sintaxy parte de escrita 
                this.erroState(computation.write.state, string)
                this.erroMove(computation.write.move, string)
                this.erroTape(computation.write.tape, string)

            
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
    // Verifica se é um comando Especial 'pare'
    // <estado atual> pare
    static checkStop(string){
        let chunks = this.filter(string);
        if( this.hasNChunks(chunks, 2) ){
            return (
                this.isState(chunks[0]) &&
                chunks[1] == 'pare'
            );
        } else {
            return false
        }
    }
    // Verifica se é um comando Especial 'aceite'
    // <estado atual> aceite
    static checkAcept(string){
        let chunks = this.filter(string);
        if( this.hasNChunks(chunks, 2) ){
            if(chunks[1] == 'aceite'){
                this.erroState(chunks[0], string)
                return this.isState(chunks[0])
            }
        }
        return false
    }
    // Verifica se é um comando Especial 'rejeite'
    // <estado atual> pare
    static checkReject(string){
        let chunks = this.filter(string);
        if( this.hasNChunks(chunks, 2) ){
            if(chunks[1] == 'rejeite'){
                this.erroState(chunks[0] ,string)
                return this.isState(chunks[0])
            }
        }
        return false
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
            if( chunks[0] == 'inicio' ){
                this.erroState(chunks[2], string)
                return this.isState(chunks[2])
            }
        } 
        return false
    }
    static checkEndBlock(string){
        // fim <identificador de bloco>
        let chunks = this.filter(string);
        if( this.hasNChunks(chunks, 2)){
            return chunks[0] == 'fim'
        }
        return false
    }
    static checkReturnBlock(string){
        // <estado atual> retorne
        let chunks = this.filter(string);
        if( this.hasNChunks(chunks, 2)){
            if(chunks[1] == 'retorne'){
                this.erroState(chunks[0], string)
                return this.isState(chunks[0])
            }
        }
        return false
    }
    // Analise do pedaço
    static checkNothing(string){
        let chunks = this.filter(string);
        return ( chunks.length <=1 && (chunks[0] == '' || chunks[0] == ' ' || chunks[0] == '!') )
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
        let aux = this.removeComent(string);
        aux = this.removeTab(aux);
        aux = this.removeSpaces(aux);
        aux = this.removeNewLine(aux);
        aux = aux.trim()
        aux = aux.split(' = ');
        return{
            alias:aux[0],
            content:aux[1].split('')
        }
    }
    static getMetaBlock(string){
        let chunks = this.filter(string);
        if(Parse.whatIsComand(string)==this.INIT_BLOCK){
            return {
                name:chunks[1],
                state:chunks[2]
            }
        }
        if(Parse.whatIsComand(string)==this.END_BLOCK){
            return {
                name:chunks[1]
            }
        }
        if(Parse.whatIsComand(string)==this.RETURN_BLOCK){
            return {
                state:chunks[0]
            }
        }
    }
    static erroState(state, comand){
        if(!this.isState(state)){
            throw new error('Estado invalido',''+state+' não é um estado valido:(inteiro 4 digitos)\n'+comand)
        }
    }
    static erroTape(tape, comand){
        if(!this.isTape(tape)){
            throw new error('Fita invalida',''+tape+' não é uma fita valida:(X || Y || Z)\n'+comand)
        }
    }
    static erroMove(move, comand){
        if(!this.isMove(move)){
            throw new error('Movimento invalido',''+move+' não é um movimento valido:(e || i || d)\n'+comand)
        }
    }
}