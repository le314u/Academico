const fs = require('fs')

module.exports = (pathFile)=>{
    return new Promise((resolve, reject)=>{
        fs.readFile(pathFile,'utf8', function(err,string){
            if(err){
                reject(err)
            }
            //Retorna ja separado em declarações em vez de apenas uma string
            resolve(string.split('\n'))
        });
    });
}