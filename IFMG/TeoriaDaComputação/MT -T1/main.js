const mt = require('./MT')
const cli = require('./cli')
const input = require('./input')
const erro = require('./error')


class Exec{
    constructor(){
        let machine = ''
        let interface = new cli();
    }
    async init(){
        //Le o arquivo e instancia a MT
        let declarations = await input(interface.file)
        this.machine = new mt(declarations)
        this.machine.init(interface.input)
        this.machine.flag = interface.getPayload()
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
