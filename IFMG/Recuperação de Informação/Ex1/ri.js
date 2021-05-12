let fs = require('fs');

class RI {
  constructor(pathIn,pathOut){
      this.pathIn = pathIn;
      this.pathOut = pathOut;
      this.meta = {};
  }

    scan(){// Cria uma estrutura intermediaria 
        let self = this
        return new Promise((resolve, reject)=>{
            fs.readFile(self.pathIn,'utf8', function(err,data){
                if (err){ reject(err) }//Erro
                else{//Leitura OK
                    let indexLine = 0;
                    //Quebra por linhas
                    let lines = data.split('\n');
                    lines.forEach( line=>{
                        ++indexLine;
                        //Quebra por palavra
                        let words = line.split(' ')
                        words.forEach(wordRAW=>{
                            //low Case
                            let word = String(wordRAW.toUpperCase())
                            //Tira pontuação
                            word = String(word.replace('_','').replace('.','').replace(',','').replace('!','').replace('?','').replace(':',''))
                            //Primeira Vez que a palavra aparece
                            if(!(word in self.meta) ){ 
                                self.meta[word] = {
                                    'occurrences':[indexLine],
                                    'amount':1,
                                }
                            // Apenas atualiza os meta dados sobre a palavra
                            }else{
                                if(self.meta[String(word)]['occurrences'] == undefined){
                                    console.log("Palavra "+word+" esta bugada ")
                                } else{
                                    ++self.meta[String(word)]['amount'];
                                    self.meta[String(word)]['occurrences'].push(indexLine);
                                }
                            }
                        })
                    })
                    resolve();
                }
            });
        });
    };

    write(data){
        return new Promise((resolve, reject)=>{
            fs.writeFile(this.pathOut, data,function (err) {
                if (err){reject(err)}
                else{ resolve()}
            });
        })
    }

    getWord(wordRAW){// Pega as ocorrencias de uma palavra no metadado
        let word = wordRAW.toUpperCase()
        let data = '';
        if(! (word in this.meta)){
            data = '0';
        }else{
            data = this.meta[word]['amount']
            this.meta[word]['occurrences'].forEach(numb=>{
                data = data+'\n'+numb;
            })
        }
        return data;
    }

    getWordIn(wordRAW){// Pega as ocorrencias de uma palavra no metadado
        let data = '';  
        let word = wordRAW.toUpperCase()
        let keys = Object.keys(this.meta)
        let total = 0
        let ocorrencias = []
        keys.forEach(oldKey=>{
            let key = oldKey.toUpperCase()
            let instancia = this.meta[key]
            if(key.indexOf(word) != -1){
                total = total + instancia['amount']
                ocorrencias = [].concat(ocorrencias, instancia['occurrences'])
            }
        })
        if( total != 0){
            data = total
            ocorrencias.sort()
            ocorrencias.forEach(numb=>{
                data = data + '\n'+numb
            })
        }
        return data;
    }
}

let args = process.argv.slice(2)
let words = args.slice(2)
let engine = new RI(args[0],args[1])
const run = async ()=>{
    console.log("Lendo "+args[0]+" e criando meta dados")
    await engine.scan()
    words.forEach(word=>{
        console.log("Salvando em '"+args[1]+"' meta dados sobre '"+word+"'")
        engine.write(engine.getWordIn(word))
    })
}
run()