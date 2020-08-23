const mt = require('./mt')
const cli = require('./cli')
const input = require('./input')


class Main{
    constructor(){
        this.machine = ''
        this.interface = new cli();
        this._init()
            .then()
            .catch((erro)=>{
                console.log(erro.name,erro.message)
            }); 
    }
    async _init(){
        // Pega os comandos passados por linah de comando
        this.flags = this.interface.getPayload()
        // Carrega a Maquina
        if(this.flags.option != this.interface.HELP){
            // Le o arquivo de entrada
            let declarations = await input(this.interface.file)
            // Instancia a MT
            this.machine = new mt(declarations,this.interface.input)
        }
        // Opera a maquina de acordo com a flag
        //switch
            // se help executa this.help()
            // se resume executa this.resume()
            // se step executa this.step()
            // se debug executa this.debug()
    }
    help(){
        // Executa o que deve ser feito com a flag -help
    }
    resume(){
        // Executa o que deve ser feito com a flag -resume
    }
    step(){
        // Executa o que deve ser feito com a flag -step
    }
    debug(){
        // Executa o que deve ser feito com a flag -debug
    }
}

// Executa pois main é o ponto de entrada
let run = new Main()