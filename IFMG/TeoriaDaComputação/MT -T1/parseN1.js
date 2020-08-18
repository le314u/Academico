module.exports=class Program{
    //  Verifica se existe bloco main
    //  verifica a sintaxi dos bloco

    // Verificar que so existem strings validas no programa
    allStringValid(strings){
        // Verifica se não há erro
        for (const string of strings.split('\n')) {
            if(Parse.whatIsComand(string) == 'error'){
                return false
            }
        }
        return true
    }
    
    getBlock(strings, metaBlock){
        let block = {
            stateInit:0,
            name:'',
            alias:[],
            cumputation:[],
            callFunction:[],
            returnFunction:[],
            special:[]
        }
        for (let index = metaBlock.init; index <= metaBlock.end; index++) {
            let cod = Parse.whatIsComand(strings[index])       
            if(cod == "initBlock"){
                let init = Parse.getMetaBlock(strings[index])
                block.name = init.name;
                block.stateInit = init.state
            }  
            if(cod == "endBlock"){
                let name = Parse.getMetaBlock(strings[index]).name
                if(block.name != name){
                    console.log("Erro de sintaxy: fechando "+name+" sem antes fechar "+block.name);
                    return false
                }
            } 
            if(cod == "returnBlock"){
                let returnBlock = Parse.getMetaBlock(strings[index])
                block.returnFunction.push(returnBlock)
            }  
            if(cod == "alias"){
                let alias = Parse.getAlias(strings[index])
                block.alias.push(alias)
            }  
            if(cod == "comand"){
                let comand = Parse.getComputation(strings[index])
                block.cumputation.push(comand)
            }
            if(cod == "function"){
                let func = Parse.getFunction(strings[index])
                block.callFunction.push(func)
            }  
        }
        return block
    }
    analize(program){
        let metaData={
            inBlock:false,
            line:-1,
            block:{
                init:0,
                end:0
            },
            return:{
                block:[],
                alias:[]
            }
        }
        
        for (const declaration of program.split('\n')) {
            metaData.line = metaData.line+1
            if(Parse.whatIsComand(declaration) == 'error'){
                return 'comando invalido'
            }
            if(metaData.inBlock){
                // Se encontrar inicio de bloco dentro de outro é um erro pois é necessário fechar o bloco para criar outro
                if(Parse.whatIsComand(declaration) == 'initBlock'){
                    return 'Erro de sintaxy na linha:'+metaData.line+' não é possivel criar blocos aninhados'
                }
                // Se encontrar um fim de Bloco termina o bloco
                if(Parse.whatIsComand(declaration) == 'endBlock'){
                    metaData.inBlock = false;
                    metaData.block.end = metaData.line;
                    metaData.return.block.push(metaData.block);
                    metaData.block = {// Reseta os metadados do bloco
                        init:0,
                        end:0
                    }
                }
            } else {
                // So pode encontrar inicio de bloco ou alias
                // Qualquer coisa fora disso é um erro
                if(Parse.whatIsComand(declaration) == 'initBlock'){
                    metaData.inBlock = true
                    metaData.block.init = metaData.line
                } else if(Parse.whatIsComand(declaration) == 'alias'){
                    metaData.return.alias.push(metaData.line)
                } else if(Parse.whatIsComand(declaration) == 'nothing'){
                    //ignora pois não é nada
                } else {
                    return 'Erro na linha'+metaData.line+'\n'
                }
            }
        }
        return metaData.return
    }
}