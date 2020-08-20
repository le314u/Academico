const fs = require('fs')
const erro = require('./error')

module.exports = async (pathFile)=>{
    return new Promise((resolve, _)=>{
        fs.readFile(pathFile,'utf8', function(err,string){      
            try{
                //Retorna ja separado em declarações em vez de apenas uma string
                resolve(string.split('\n'))
            }catch{
                //Informa que o arquivo passado como argumento é invalido
                throw new erro('Arquivo invalido',
                    ''+pathFile+' não é um arquivo .mt valido')
            }
        });
    });
}