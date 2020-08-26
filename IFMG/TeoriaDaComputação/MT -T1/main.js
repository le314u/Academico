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
    }
    async _init(){
        // Pega os comandos passados por linah de comando
        this.cliPayload = this.interface.getPayload()
        let flag = this.cliPayload.option
        // Carrega a Maquina
        if(flag != cli.HELP){
            // Le o arquivo de entrada
            let declarations = await input(this.interface.file)
            // Instancia a MT
            this.machine = new mt(declarations,this.interface.input, this.cliPayload)
        }
        // Opera a maquina de acordo com a flag
        //switch
            if(flag == cli.HELP){// se help executa this.help()
                this.help()
            } else if(flag == cli.RESUME){// se resume executa this.resume()
                this.resume()
            } else if(flag == cli.STEP){// se step executa this.step()
                this.step()
            } else if(flag == cli.DEBUG){// se debug executa this.debug()
                this.debug
            }else{
                //Instancia um erro
            }//Erro
    }
    help(){

        // Criar uma classe nova para escrita de arquivo (debug) ->
        /*  3 funções: 1 cria o arquivo(passa o path do arquivo), outra escreve no arquivo(string a ser escrita)
                       outra fecha o arquivo("sem parametro") */
        // flag indicando se o arquivo ta aberto ou não
        const helpString = '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        'Este simulador foi feito na linguagem de programação Javascript, por tal, sua sintaxe de entrada segue as regras abaixo:\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        ' $ node <nome do arquivo a ser executado> <opções> <arquivo a ser lido> <string de entrada>\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        '-- Entre as opções possíveis, estas são:\n' +
        '   [ -step <n> ] - Esta flag faz com que o simulador execute "n" computações e pare, mostrando o conteúdo das 3 fitas, dando possibilidades\n' +
        'para se escrever um novo valor "n" para realizar computações reabrindo o prompt de comandos. Caso seja fornecido o valor "0", a simulação\n' +
        'termina imediatamente. Caso seja fornecido um valor negativo, o simulador passa a executar o programa considerando que se foi escrito a\n' +
        'opção "-resume".\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        '   [ -resume ] - Esta flag executa o programa até o fim, computando todos os comandos na ordem em que foram apresentados, mostrando o\n' +
        'conteúdo das 3 fitas e o resultado da computação, se ACEITOU a string de entrada, ou se a REJEITOU. Esta opção é a padrão e será\n' +
        'executada se nenhuma opção "-step" for fornecida.\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        '   [ -debug <arquivo log> ] - Esta flag produz um relatório mostrando linha por linha as computações executadas, as entradas e saídas\n' +
        'dos blocos e afins. O parâmetro <arquivo log> que deve ser fornecido logo após a opção de "debug" indica o arquivo de relatório que\n' +
        'será produzido contendo todas estas informações das computações.\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        '   [ -help ] - Esta flag irá exibir um pequeno "guia" demonstrando os padrões de entrada para este simulador de Máquina de Turing.\n' +
        'Utilize sempre que precisar de ajuda!\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n'
        console.log(helpString)
    }
    resume(){
        // Executa o que deve ser feito com a flag -resume
        while ( this.machine.compute()  ){}
        this.machine.machineState()
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