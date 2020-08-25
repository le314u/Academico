const Parse = require('./parseN1')

module.exports = class Mt_Print{
    constructor(){}
    machineState(result, X, Y, Z){
        let print = (machine, nameTape)=>{
            let newTape = []
            let symbols = machine.tape
            for (let i = 0; i < symbols.length; i++) {
                if( i == machine.header){
                    newTape.push('['+symbols[i]+']') 
                } else {
                    newTape.push(symbols[i])
                }
            }
            return `Fita ${nameTape} : ${newTape}`
        }
        return (
            result.toUpperCase()+"\n"+
            "------------------------------------------\n"+
            print(X,'X')+'\n'+
            print(Y,'Y')+'\n'+
            print(Z,'Z')+'\n'+
            "------------------------------------------"
        )
    }
    machineDebug(comand, scop){
        let originalName = ()=>{
            return scop.stack[scop.stack.length-1].block.name
        }
        let formatedName = ()=>{
            let oldName = originalName()
            let newName = ''
            if(oldName.length < 16){ // Coloca prefixo ....
                let numberSpaces = 16 - originalName.length;
                let dots = ''
                for (let i = 0; i < numberSpaces; i++) {
                    dots = dots+'.'
                }
                newName = dots+oldName
            } else { // trunca o nome
                for (let i = 0; i < 16; i++) {
                    newName = newName+oldName[i]
                }
            }
            return newName
        }
        return formatedName()+' : '+comand
    }
    //Converte o comando logic em uma string ( semelhante a ao arquivo de entrada)
    logic2String(logic){
        let type = logic[0]
        let comand = logic[1]
        if(type == Parse.FUNCTION){
            return ''+comand.state+' '+comand.function+' '+comand.return
        }
        else if(type == Parse.COMAND){
            return ''+comand.read.state+' '+comand.read.tape+' '+comand.read.symbol+' '+comand.read.move+' -- '+comand.write.state+' '+comand.write.tape+' '+comand.write.symbol+' '+comand.write.move
        }
        else if(type == Parse.RETURN_BLOCK){
            return ''+comand.state+' retorne'
        }
        else if(type == Parse.ACEITE){
            return ''+comand.state+' aceite'
        }
        else if(type == Parse.REJEITE){
            return ''+comand.state+' rejeite'
        }
        else if(type == Parse.PARE){
            return ''+comand.state+' pare'
        }
    }
}