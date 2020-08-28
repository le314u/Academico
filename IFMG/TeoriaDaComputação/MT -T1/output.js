const fs = require("fs")
const erro = require("./erro")

module.exports = class Output {
    constructor(filePath) {
        this.stream = undefined
        this.nameFile = filePath
        this.fileOk = false
        this.file = this.createFile(this.nameFile)
    }

    // Cria um arquivo para salvar o relatório de debug
    createFile(filePath) {
        let stream = ()=>{// Cria uma stream
            this.stream = fs.createWriteStream(filePath, {flags: 'a' })
        }
        return new Promise( (res, rej)=>{
            let nameFile = this.nameFile
            fs.open(filePath, "w", function(err) {
                if (err) { // Caso de erro
                    rej()
                } else {
                    res(stream())
                }
            })
        })
    }

    // Método para escrever o conteúdo de debug no arquivo de relatório
    writeInFile(stringToWrite) {
        this.file.then(()=>{
            this.stream.write(stringToWrite+'\n')
        })
    }
    // Fecha Arquivo
    closeFile(stringToWrite) {
        this.file.then(()=>{
            this.stream.end()
        })
    }
}