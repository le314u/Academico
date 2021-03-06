const mt = require('./mt')
const cli = require('./cli')
const input = require('./input');
const output = require('./output')
const readline = require('readline');


class Main{
    constructor(){
        this.machine = ''
        this.interface = new cli();
        this.rl = readline.createInterface({
            input: process.stdin,
            output: process.stdout
        });
        this._init()
            .then()
            .catch((erro)=>{
                console.log(erro.name,erro.message)
                //console.log('-------------------------')
                //console.log(erro)
            }); 
        console.log(
            "\n"+
            "Simulador de Máquinade Turing Suave\n"+
            "Desenvolvido como trabalho prático para a disciplina de Teoria da Computação - 2020\n"+
            "Autores:Lucas Mateus Fernandes e Marcus Vinícius Braga.\n"
        )
    }
    async _init(){
        // Pega os comandos passados por linha de comando
        this.cliPayload = this.interface.getPayload()
        let flag = this.cliPayload.option
        // Carrega a Maquina
        if(flag != cli.HELP){
            // Le o arquivo de entrada
            let declarations = await input(this.interface.file)
            // Instancia a MT
            this.machine = new mt(declarations,this.interface.input, this.cliPayload)
        } else if (this.cliPayload.option == cli.HELP) {
            const func = () => this.help
            func()
        }
        // Opera a maquina de acordo com a flag
        if(flag == cli.HELP){// se help executa this.help()
            this.help().catch((e)=>{throw e})
        } else if(flag == cli.RESUME){// se resume executa this.resume()
            this.resume().catch((e)=>{throw e})
        } else if(flag == cli.STEP){// se step executa this.step()
            this.step().catch((e)=>{throw e})
        } else if(flag == cli.DEBUG){// se debug executa this.debug()
            this.debug().catch((e)=>{throw e})
        }else{
            //Instancia um erro
        }//Erro
    }
    help(){
        const caracteresReservados = 'Qualquer ";" nas instruções da MT será considerado comentário portanto não use ";" como caracter da fita\n'
        const geral = '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        'Este simulador foi feito na linguagem de programação Javascript, por tal, é necessário instalar o "Node.js" na máquina.\n' +
        'Sua sintaxe de entrada segue as regras abaixo:\n'+
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        ' $ node <nome do arquivo a ser executado> <opções> <arquivo a ser lido> <string de entrada>\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        '-- Entre as opções possíveis, estas são:\n'

        const step = '   [ -step <n> ] - Esta flag faz com que o simulador execute "n" computações e pare, mostrando o conteúdo das 3 fitas, dando possibilidades\n' +
        'para se escrever um novo valor "n" para realizar computações reabrindo o prompt de comandos. Caso seja fornecido o valor "0", a simulação\n' +
        'termina imediatamente. Caso seja fornecido um valor negativo, o simulador passa a executar o programa considerando que se foi escrito a\n' +
        'opção "-resume".\n' +
        '   Ex: $ node main.js -step 3 teste.mt 0101010\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' 
        
        const resume = '   [ -resume ] - Esta flag executa o programa até o fim, computando todos os comandos na ordem em que foram apresentados, mostrando o\n' +
        'conteúdo das 3 fitas e o resultado da computação, se ACEITOU a string de entrada, ou se a REJEITOU. Esta opção é a padrão e será\n' +
        'executada se nenhuma opção "-step" for fornecida.\n' +
        '   Ex: $ node main.js -resume teste.mt 0101010\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' 
        
        const debug = '   [ -debug <arquivo log> ] - Esta flag produz um relatório mostrando linha por linha as computações executadas, as entradas e saídas\n' +
        'dos blocos e afins. O parâmetro <arquivo log> que deve ser fornecido logo após a opção de "debug" indica o arquivo de relatório que\n' +
        'será produzido contendo todas estas informações das computações.\n' +
        '   Ex: $ node main.js -debug export.mt teste.mt 0101010\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        '   [ -help ] - Esta flag irá exibir um pequeno "guia" demonstrando os padrões de entrada para este simulador de Máquina de Turing.\n' +
        'Utilize sempre que precisar de ajuda!\n' +
        '   Ex: $ node main.js -help\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n'
        
        const standart = 'Caso nenhuma flag seja passada será considerada a flag resume'
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        ' $ node <nome do arquivo a ser executado> <arquivo a ser lido> <string de entrada>\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        '   Ex: $ node main.js teste.mt 0101010\n' +
        '-------------------------------------------------------------------------------------------------------------------------------------------\n' +
        console.log( caracteresReservados+ geral+ step+ resume+ debug+ standart )
        this.rl.close();
    }
    // Executa o que deve ser feito com a flag -resume
    async resume(){
        // Continua a partir do breakpoint
        let _continue = async ()=>{
            // Abre o terminal esperando a tecla enter para continuar
            let _continuePromise = ()=>{
                return new Promise( (resolve, _)=>{
                    let machine = this.machine
                    this.rl.question("Digite enter para continua: ", function(answer) {
                        console.log('\n')
                        machine.setContinuePoint(); // Continua o Processamento
                        resolve()
                    });
                })
            }
            this.machine.machineState(); // Prita estado da Maquina
            await _continuePromise(); // Espera entrada do usuario
        }
        // Verifica se é um break point 
        let isBreakPoint = ()=>this.machine.controll.isBreakPoint()
        // Verifica se a maquina esta executando
        let itsRun = ()=> this.machine.controll.hasNextStep() || isBreakPoint()
        // Executa a maquina
        let exec = ()=>{
            while ( this.machine.compute() ){}
        }
        // Execução de acordo com a flag resume
        while ( itsRun() ){
            if( isBreakPoint() ){
                console.log("BreakPoint")
                await _continue();
            } else {
                exec()
            }
        }
        // Mostra o estado da Maquina  
        this.machine.machineState()
        this.rl.close();
    }
    // Executa o que deve ser feito com a flag -step
    async step(){
        let inExec = true
        // Pausa para perguntar o que fazer
        let _continue = ()=>{
            return new Promise( (resolve, reject)=>{
                try {
                    this.rl.question("(n=passos, 0=termina, -1=resume)\n>> Quais os próximos steps? ", function(answer) {
                        let option = parseInt(answer)
                        resolve(option)
                    });
                } catch (error) {
                    console.log("Argumento Invalido")
                    reject(error)
                }
            })
        }
        // Computa n Passos
        let exec = ()=>{
            inExec = true
            while ( this.machine.controll.hasNextStep() && this.machine.controll.run() ) {
                this.machine.compute()//Computa
                this.machine.controll.nextStep()//Contabiliza um passo
            }
            this.machine.machineState()// Printa Estado das Fitas
            inExec = false
        }
        

        while(inExec){
            if(this.machine.controll.getSpecial() != ''){ // Para a execução
                inExec = false
                this.rl.close();
                break
            }
            exec()// Contabiliza 'n' passos
            await _continue().then((option)=>{
                // Executar conforme a seleção do fluxo
                if ( option == -1 || option > 0 ) { 
                    inExec = true
                    this.machine.controll.moreSteps(option)
                    return cli.RESUME
                }else { // Encerrar a execução
                    this.rl.close();
                    return false
                }
            })
        }
    }
    async debug(){
        // Executa o que deve ser feito com a flag -debug
        // Cria o arquivo de Debug
        let createFileDebug = async ()=>{
            try {
                this.output = await new output(this.cliPayload.arg)
            } catch (error) {
                throw erro
            }
        }
        // Continua a partir do breakpoint
        let _continue = async ()=>{
            // Abre o terminal esperando a tecla enter para continuar
            let _continuePromise = ()=>{
                return new Promise( (resolve, _)=>{
                    let machine = this.machine
                    this.rl.question("Digite enter para continua: ", function(answer) {
                        console.log('\n')
                        machine.setContinuePoint(); // Continua o Processamento
                        resolve()
                    });
                })
            }
            this.machine.machineState(); // Prita estado da Maquina
            await _continuePromise(); // Espera entrada do usuario
        }
        // Verifica se é um break point 
        let isBreakPoint = ()=>this.machine.controll.isBreakPoint()
        // Verifica se a maquina esta executando
        let itsRun = ()=> this.machine.controll.hasNextStep() || isBreakPoint()
        // Executa a maquina
        let exec = ()=>{
            while ( this.machine.compute() ){
                this.output.writeInFile(this.machine.stringDebug)// Escreve no arquivo de Debug
            }
        }

        // Execução de acordo com a flag debug
        await createFileDebug()
        while ( itsRun() ){
            if( isBreakPoint() ){
                console.log("BreakPoint")
                await _continue();
            } else {
                exec()
            }
        }
        // Fecha a conexão com o console
        this.rl.close();
        // Fecha o Arquivo
        this.output.closeFile()
        // Mostra o estado da Maquina  
        this.machine.machineState()        
    }
}

// Executa pois main é o ponto de entrada
let run = new Main()