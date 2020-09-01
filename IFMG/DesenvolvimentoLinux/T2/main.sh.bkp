#!/bin/bash
# Analisa as entradas e verifica se são entradas validas
cli(){
    #Verifica se o primeiro argumento passado é um arquivo 
    if [ -f $1 ]
    then
        arquivoConf=$1 #Arquivo onde será lido as configurações
        arquivoOutput=$2 #Arquivo de log
    else 
        echo "Não existe arquivo de configuração."
        exit # Encerra o programa
    fi
}
#Pega o Regex da linha específica
getFileConfig(){
    cat $arquivoConf
}
getValorRegex(){
    # Printa todo o arquivo enumerando cada linha
    # Filtra pela linha que começa por $1:
    # Pega apenas a parte em que o regex é compativel
    variavel=$(cat -|egrep -n ^ |egrep "^$1:"|egrep -o "$2")
    echo $variavel
}
#Retorna o valr da variavel
getValorVariavel(){
    #Regex para pegar a v
    regexVariavel="(( )*([a-zA-Z_]+([0-9]*[a-zA-Z_]*)*)( )*)"
    regexPlus="$regexVariavel="
    declaracaoVariavel=$(getFileConfig|getValorRegex $1 "$regexPlus"|getValorRegex "1" "$regexVariavel")
    echo $declaracaoVariavel
}
getLinhaLiteral(){
    literal=$1
    lLiteral=$(cat ex.conf | grep -n $literal|cut -d ':' -f1) 
    echo $lLiteral
}
# Verifica a sintaxy do arquivo de configuração
parse(){
    echo "Parse"
    # Ler o arquivo linha a linha
    # Pega o numero da linha em que tem o literal FATORES:
    lLiteral=$(getLinhaLiteral "FATORES:") 
    #Verifico se existe a strign FATORES:
    if [ -z $lLiteral ] # Não existe liteal FATORES:
    then
        echo "Erro na sintaxy do arquivo $arquivoConf"
        exit # Encerra o programa
    else # Existe o literal
        nextLine=$[ $lLiteral+1 ]
        loop=1
        while [ $loop -eq 1 ]
        do
            variavel=$(getValorVariavel $nextLine)
            echo "$nextLine $variavel"
            if [ -z $variavel ] #Verifica se o fator é valida
            then
                loop=0
            else # Cancela o Loop se fator é invalido
                variavel=''
                nextLine=$[ $nextLine+1 ] # verifica a proxima linha
            fi
        done
    fi
}

cli $1 $2
parse
#split(){}
#mask(){}
#replaceMask(){}
#fatorial(){}
##For
#exec(){}
#output_header(){}
#output_prog(){}
#