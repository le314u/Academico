const fs = require('fs')
const erro = require('./erro')

module.exports = async (pathFile)=>{
    return new Promise((resolve, reject)=>{
        fs.readFile(pathFile,'utf8', function(err,string){      
            try {
                // Retorna declarações em vez de apenas uma string
                resolve(string.split('\n'))
            } catch (error) {
                // Informa que o arquivo passado como argumento é invalido
                reject(
                    new erro('Arquivo invalido',
                    ''+pathFile+' não é um arquivo .mt valido')
                )
            }
        });
    });
}