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
                console.log('-------------------------')
                console.log(erro)
            }); 
        console.log(
            "Simulador de Máquinade Turing Suave\n"+
            "Desenvolvido como trabalho prático para a disciplina de Teoria da Computação - 2020\n"+
            "Autores:Lucas Mateus Fernandes e Marcus Vinícius Braga.\n"
        )
        console.log("aaaaa")
    }
    async _init(){
        // Pega os comandos passados por linah de comando
        this.cliPayload = this.interface.getPayload()
        // Carrega a Maquina
        if(this.cliPayload.option != cli.HELP){
            // Le o arquivo de entrada
            let declarations = await input(this.interface.file)
            // Instancia a MT
            this.machine = new mt(declarations,this.interface.input, this.cliPayload)
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
        // TODO console log mostrando os parametros de entrada

        // Criar uma classe nova para escrita de arquivo (debug) ->
        /*  3 funções: 1 cria o arquivo(passa o path do arquivo), outra escreve no arquivo(string a ser escrita)
                       outra fecha o arquivo("sem parametro") */
        // flag indicando se o arquivo ta aberto ou não
    }
    resume(){
        // Executa o que deve ser feito com a flag -resume
        // TODO 
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