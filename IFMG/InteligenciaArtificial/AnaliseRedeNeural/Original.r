# Adiciona as bibliotecas necessarias. Se precisar instalar algum pacote, use: 'install.package("pacote")'
library('neuralnet')
library('datasets')

# Carrega o dataset do arquivo. É preciso estar na pasta de trabalho onde o arquivo em questão se
# encontra
arq.treinamento <- read.table(file='Dataset/Treinamento.csv', header=TRUE);
arq.verificacao <- read.table(file='Dataset/Verificacao.csv', header=TRUE);

# Gera o objeto frame a partir do dataset
dataset.trein <- data.frame(arq.treinamento);
dataset.verif <- data.frame(arq.verificacao);

# Este dataset contem os seguintes atributos:
# Age	Delivery.number	Delivery.time	Blood.pressure	Heart.problem	Caesarian
# 1. Age
# 2. Delivery.number
# 3. Delivery.time
# 4. Blood.pressure
# 5. Heart.problem
# 6. Caesarian    

# Cria a formula que associa a variavel 'Caesarian' com as variáveis 'Age Delivery.number Delivery.time Blood.pressure Heart.problem'
modelo <- as.formula('Caesarian ~ Age + Delivery.number + Delivery.time + Blood.pressure + Heart.problem');





gera=function(arquitetura,tamanhoDataSet){

    #Arquitetura Muda
    # Usa a funcao que cria a rede neural
    
    rede01 <- neuralnet(modelo, data=dataset.trein, hidden=arquitetura);

    # Exibe a rede gerada
    

    # Verifica os dados: resultado esperado = 1
    #compute(rede01, t(c(26,2,0,1,0)))$net.result

    # Verifica os dados: resultado esperado = 0
    #compute(rede01, t(c(31,2,2,1,0)))$net.result

    # Computa a saida para todos os valores de teste
    compute(rede01, dataset.verif[1:5])$net.result

    
    # Compara os resultados da rede neural com a classificação previa conhecida
    resultado <- (round(compute(rede01, dataset.verif[1:5])$net.result) == dataset.verif[6])

    #Analisa Precisao
    contacerto <- 0
    for( i in 1: length(resultado)){
        if(resultado[i]==TRUE){
            contacerto <- contacerto+1
        }
    }
    #Numero de Camadas
    cat(toString(length(arquitetura)),"|")
    #Disposição das Camadas
    cat(arquitetura,"|")
    #Erro
    cat(rede01$result.matrix[1],"|")
    #Steps
    cat(rede01$result.matrix[3],"|")
    #Precisao
    precisao <-(contacerto*100)/length(resultado)
    cat(precisao,"%\n")
    
    #cat(tamanhoDataSet,"\n")
    #plot(rede01);
    #nomeArquivo=toString(numeroCamada,"camadas-",arquitetura,".png")
    #dev.copy(png,nomeArquivo)
    #dev.off()

}

tryRecursivo = function(arquitetura,tamanhoDataSet){
    tryCatch({
            gera(arquitetura,tamanhoDataSet)}
        ,error = function(e){
            cat("\nNao Convergiu\n")
            tryRecursivo(arquitetura,tamanhoDataSet)}
        ,finally= function(e){}
    )

}
tamanhoDataSet=30
nInstancias=100
GeraValores = function(arquitetura,nInstancias,tamanhoDataSet){
    for(i in 1:nInstancias){
        tryCatch({
                tryRecursivo(arquitetura,tamanhoDataSet)}
            ,error = function(e){
                cat("\nNão era para chegar AKI")
            }
            ,finally= function(e){}
        )
    }
}

cat("\n\n",nInstancias," instancias de cada Caso com dataSet Treinamento=",tamanhoDataSet," Teste=",80-tamanhoDataSet,"\n\n")


cat("\n\n3Camadas\n\n")

arquitetura=c(5,3,1);
cat("\n",arquitetura," Funil Decrescente\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(1,3,5);
cat("\n",arquitetura," Funil Crescente\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(2,4,8);
cat("\n",arquitetura," Funil Crescente ²\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(8,16,32);
cat("\n",arquitetura," Funil Crescente ²\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(32,16,8);
cat("\n",arquitetura," Funil Decrescente ²\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(8,4,2);
cat("\n",arquitetura," Funil Decrescente ²\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(1,1,1);
cat("\n",arquitetura," Linha 'n'\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(5,5,5);
cat("\n",arquitetura,"linear 'n+' Camadas\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(10,10,10);
cat("\n",arquitetura,"linear 'n' Camadas\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)


cat("\n\n5Camadas\n\n")

arquitetura=c(5,4,3,2,1);
cat("\n",arquitetura," Funil Decrescente\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(1,2,3,4,5);
cat("\n",arquitetura," Funil Crescente\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(5,3,1,3,5);
cat("\n",arquitetura," Ampulheta\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(1,3,5,3,5);
cat("\n",arquitetura," Elipse\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(2,4,8,16,32);
cat("\n",arquitetura," Funil Crescente ²\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(32,16,8,4,2);
cat("\n",arquitetura," Funil Decrescente ²\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(1,1,1,1,1);
cat("\n",arquitetura," Linha 'n'\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(5,5,5,5,5);
cat("\n",arquitetura,"linear 'n+' Camadas\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

arquitetura=c(10,10,10,10,10);
cat("\n",arquitetura,"linear 'n' Camadas\n")
GeraValores(arquitetura,nInstancias,tamanhoDataSet)

