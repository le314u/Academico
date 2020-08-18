const fs = require('fs')

module.exports = (pathFile)=>{
    return new Promise((resolve, reject)=>{
        fs.readFile(pathFile,'utf8', function(err,data){
            if(err){
                reject(err)
            }
            resolve(data)
        });
    });
}