module.exports = class Cli{
    constructor(){
        this.args = process.argv;
        this.arg = ''
        this.option = 0
        this.file = ''
        this.input = ''
        this.RESUME=0
        this.STEP=1
        this.DEBUG=2
        this.HELP=3
        this.init()
    }
    init(){
        this.checkResume();
        this.checkStep();
        this.checkDebug();
        this.checkHelp();
    }
    getPayload(){
        return {
            option:this.option,
            arg:this.arg,
            file:this.file,
            input:this.input
        }
    }
    checkResume(){
        // -resume
        if( this.checkArgs(3,'-resume') ){
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
        if( this.checkArgs(4,'-step') && !isNaN( parseInt(this.args[3])) ){
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
        if( this.checkArgs(4,'-debug')){
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
        if( this.checkArgs(3,'-help') ){
            this.option = this.HELP;
            this.arg = '';
            this.file = this.args[3]
            this.input = this.args[4]
            return true
        }
        return false
    }
    checkArgs(n, cod){
        return (this.args.length == n && this.args[2] == cod);
    }
}