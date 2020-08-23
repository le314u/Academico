const erro = require('./erro')

module.exports = class Cli{
    constructor(){
        this.args = process.argv;
        this.arg = ''
        this.option = 0
        this.file = ''
        this.input = ''
        //Constantes para this.options
        this.RESUME=0
        this.STEP=1
        this.DEBUG=2
        this.HELP=3       
    }
    getPayload(){
        if(this.isValid()){
            return {
                option:this.option,
                arg:this.arg,
                file:this.file,
                input:this.input
            }
        } 
        throw new erro(
            'Entrada CLI',
            'Os parametros passados via linha de comando são invalidos use -help para entender a sintaxe'
        )
    }
    isValid(){
        return (
            this.checkStandard() ||
            this.checkHelp() ||
            this.checkResume() ||
            this.checkStep() ||
            this.checkDebug()
        )
    }
    checkResume(){
        // -resume
        if( this.checkArgs(5,'-resume') ){
            this.option = this.RESUME;
            this.arg = '';
            this.file = this.args[3]
            this.input = this.args[4]
            return true
        }
        return false
    }
    checkStep(){
        // -step <n>
        if( this.checkArgs(6,'-step') && !isNaN( parseInt(this.args[3])) ){
            this.option = this.STEP;
            this.arg = parseInt(this.args[3]);
            this.file = this.args[4]
            this.input = this.args[5]
            return true
        }
        return false
    }
    checkDebug(){
        // -debug <arquivoLog>
        if( this.checkArgs(6,'-debug')){
            this.option = this.DEBUG;
            this.arg = this.args[3];
            this.file = this.args[4]
            this.input = this.args[5]
            return true
        }
        return false
    }
    checkHelp(){
        // -help
        if( this.args[2] == '-help' ){
            this.option = this.HELP;
            this.arg = '';
            return true
        }
        return false
    }
    checkStandard(){
        // Omição da flag
        if( this.args.length == 4 ){
            if(this.args[2][0] != '-'){
                this.option = 0;
                this.arg = this.RESUME;
                this.file = this.args[2]
                this.input = this.args[3]
                return true
            }
        }
    }
    checkArgs(n, cod){
        return (this.args.length == n && this.args[2] == cod);
    }
}