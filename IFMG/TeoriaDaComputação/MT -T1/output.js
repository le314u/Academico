const fs = require("fs")
const error = require("./erro")

module.exports = class Output {
    constructor() {
        this.isOpened = false
    }

    // OS MÉTODOS "open" E "writeFile" JÁ AUTOMATICAMENTE FECHAM O ARQUIVO APÓS A ABERTURA E ESCRITA. NÃO É NECESSÁRIO CRIAR UMA FUNÇÃO PARA FECHAR O ARQUIVO
    
    /**
     * Método para abrir um arquivo para salvar o relatório de debug
     */
    async createFile(filePath) {
        return new Promise((res, rej) => {
            if ( !this.isOpened ) {
                this.isOpened = true

                // Abre uma arquivo novo
                try {
                    fs.open(filePath, "w", function(err, file) {
                        if (err) { // Caso de erro
                            throw new error("Erro ao criar arquivo.", "Não foi possível criar o arquivo.")
                        }
                    })
                } catch(error) {
                    rej(
                        new error("Erro ao criar arquivo.", "Não foi possível criar o arquivo.")
                    )
                }
            }
        })
    }

    /**
     * Método para escrever o conteúdo de debug no arquivo aberto de relatório
     */
    async writeInFile(filePath, stringToWrite) {
        return new Promise((res, rej) => {
            if ( this.isOpened ) {
                // Escreve no arquivo especificado
                try {
                    fs.writeFile(filePath, stringToWrite, function(err) {
                        if (err) {
                            throw new error("Erro ao criar arquivo", filePath + " não foi encontrado ou houve algum problema de memória.")
                        }
                        this.isOpened = false;
                    })
                } catch(error) {
                    rej(
                        new error("Erro ao criar arquivo", filePath + " não foi encontrado ou houve algum problema de memória.")
                    )
                }
            }
        })
    }
}