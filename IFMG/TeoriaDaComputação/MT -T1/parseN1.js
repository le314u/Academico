const error = require('./erro')
const Parse = require('./parseN0')
module.exports=class Program{
    // Verifica se existe bloco main
    // verifica a sintaxi dos bloco
    // Verificar que so existem strings validas no programa
    
    static allStringValid(declarations){
        // Verifica se não há erro
        for (const declaration of declarations) {
            if(Parse.whatIsComand(declaration) == Parse.ERROR){
                throw new error(
                    'Sintaxe do comando',
                    ''+declaration+' : Não é um comando válido'
                )
            }
        }
        return true
    }
    
    static getBlock(declarations, metaBlock){
        //Json Logico de um bloco com seus metaDados
        let block = {
            name:'',
            stateInit:0,
            aliasLocal:[],//Alias Local Sobressai sobre o Global
            order:[],//Codigo na ordem em que é escrito
            computation:[]
        }
        // Passa por todas as declarações que representam o bloco
        for (let index = metaBlock.init; index <= metaBlock.end; index++) {
            let cod = Parse.whatIsComand(declarations[index])
            // Se Declaração de bloco 
            if(cod == Parse.INIT_BLOCK){
                let init = Parse.getMetaBlock(declarations[index])
                block.name = init.name;
                block.stateInit = ''+init.state
            }
            // Se Encerramento de bloco
            if(cod == Parse.END_BLOCK){
                let name = Parse.getMetaBlock(declarations[index]).name
                // Fechando o Bloco errado
                if(block.name != name){
                    throw new error(
                        'Semantico',
                        'Abriu '+block.name+' e está fechando '+name,
                        {'declaration':declarations[index]}
                    )
                }
                // Fechou o Bloco prematuramente. So ocorrerá caso houver um erro lógico no metaBloco
                if(index != metaBlock.end){
                    throw new error(
                        'Semantico',
                        'Fechou '+name+' antes de percorrer todo o bloco',
                        {
                            'index':index,
                            'range':metaBlock
                        }
                    )
                }
            }
            // Se retorne Sai do bloco
            if(cod == Parse.RETURN_BLOCK){
                let returnBlock = Parse.getMetaBlock(declarations[index])
                block.order.push(returnBlock)
            }  
            // Se for Alias de escopo Local
            if(cod == Parse.ALIAS){
                let alias = Parse.getAlias(declarations[index])
                block.alias.push(alias)
            } 
            // Se for um comando
            if(cod == Parse.COMAND){
                let comand = Parse.getComputation(declarations[index])
                block.computation.push(comand)
                block.order.push(comand)
            }
            // Se for uma chamada função
            if(cod == Parse.FUNCTION){
                let func = Parse.getFunction(declarations[index])
                block.order.push(func)
                // Gerar erro caso for chamar um bloco não declarado
            }  
        }
        return block
    }
    static getProgram(declarations){
        // Variavel de controle
        let control = {
            inBlock:false,
            nameBlock:'',
            line:-1,
            block:{
                init:0,
                end:0
            }
        }
        // Json Logico de um programa separado em com seus metaDados
        let program = {
            order:[],
            block:[],
            alias:[]
        }
        //Functions internas
        let nextLine=()=>{control.line = control.line+1}
        let inBlock=()=>{return control.inBlock}
        let nameBlock=()=>{return control.nameBlock}
        let line=()=>{return control.line}

        // Passa por todas as declarações que representam um programa
        for (const declaration of declarations) {
            nextLine()//Proxima Declaração 

            // Analisando em escopo Global / fora de um bloco
            if(!inBlock()){
                // So pode encontrar inicio de bloco ou alias qualquer coisa fora disso é um erro
                if(Parse.whatIsComand(declaration) == Parse.INIT_BLOCK){
                    control.inBlock = true
                    control.nameBlock = Parse.getMetaBlock(declaration).name
                    control.block.init = line()
                } else if(Parse.whatIsComand(declaration) == Parse.ALIAS){
                    let auxAlias = Parse.getAlias(declaration)
                    program.order.push(auxAlias)
                    program.alias.push(auxAlias)
                } else if(Parse.whatIsComand(declaration) == Parse.NOTHING){
                    //ignora pois não é nada
                } else {
                    throw new error(
                        'Semantico',
                        ''+declaration+' esta em um local invalido'
                    )
                }
            // Analisando escopo Local / dentro de um bloco
            }else{
                // Se encontrar inicio de bloco dentro de outro é um erro pois é necessário fechar o bloco para criar outro
                if(Parse.whatIsComand(declaration) == Parse.INIT_BLOCK){
                    let aux = Parse.getMetaBlock(declaration)
                    throw new error(
                        'Semantico',
                        'Tentar abrir um bloco '+aux.name+' sem antes fechar o bloco '+nameBlock()+' que ja esta aberto',
                        {'declaration':declaration}
                    )
                }
                // Se encontrar um fim de Bloco termina o bloco
                if(Parse.whatIsComand(declaration) == Parse.END_BLOCK){
                    //Determina o fim fo bloco
                    control.block.end = line();
                    //Converte os metaDados em um Bloco
                    let blocoLogico = this.getBlock(declarations, control.block)
                    //Indexa o bloco
                    program.block.push(blocoLogico);
                    program.order.push(blocoLogico)
                    //Reseta o bloco
                    control.block = {// Reseta os metadados do bloco
                        init:0,
                        end:0
                    }
                    //Volta para o escopo Global
                    control.inBlock = false;
                    control.nameBlock = '';
                }
            } 
        }
        return program
    }
}