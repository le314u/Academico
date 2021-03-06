const clIFlags = require('./cli')
const mt = require('./mt')

module.exports = class Mt_Flags{
    static DISABLE = -1
    static RUN = -1
    static BREAK_POINT = -2

    constructor(cliPayload){
        // Atividade da maquina
        this._run = false
        // Flag
        this.debug = false
        // Controle
        this.step = 0
        this.maxStep = 0
        this.special = ''
        // Init
        this._setFlags(cliPayload)
    }
    _setFlags(cliPayload){
        let stepOff = ()=>{
            this.step = 0;
            this.maxStep = Mt_Flags.DISABLE;
        }
        if(cliPayload.option == clIFlags.HELP){
            this.disable();// Se -help não executa nada
        }else if(cliPayload.option == clIFlags.RESUME){
            this.enable();// Se -resume não tem steps
            stepOff()
        }else if(cliPayload.option == clIFlags.STEP){
            this.enable();
            this.step = 0;
            this.maxStep = parseInt( cliPayload.arg )
        }else if(cliPayload.option == clIFlags.DEBUG){
            this.debug = true
            this.enable();
            stepOff()
        }else{
            this.enable();
            stepOff()
        }
    }
    enable(){
        this._run = true
    }
    disable(){
        this._run = false
    }
    run(){
        return this._run
    }
    //-------------------------------------------
    hasNextStep(){
        if(this.maxStep != Mt_Flags.DISABLE){// Contando passos ?
            if( this.step < this.maxStep ){
                // Contabiliza um passo
                return true
            } else {
                // Atigiu o maximo de passos!
                return false
            }
        }
        // Retorana o estado de atividade da maquina
        return this._run;
    }
    nextStep(){
        if(this.maxStep != Mt_Flags.DISABLE){// Contando passos ?
            if( this.step < this.maxStep ){
                // Contabiliza um passo
                this.step = this.step + 1
            } else {
                // Atigiu o maximo de passos!
                this.disable()
            }
        }
        // Retorana o estado de atividade da maquina
        return this._run;
    }
    moreSteps(maxStep){
        this.enable()
        this.maxStep = maxStep;
        this.step = 0
    }
    isBreakPoint(){
        return this.maxStep == Mt_Flags.BREAK_POINT
    }
    setSpecial(special){
        this.special = special
    }
    getSpecial(){
        return this.special
    }
}