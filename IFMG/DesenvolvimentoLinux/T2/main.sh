#!/bin/bash
# Analisa as entradas e verifica se são entradas validas
cli(){
# $1 == Input
# $2 == Output
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

getLineMatch(){
# $1 == <Regex a ser procurado>
    # Mostrar a linha do Literal
    awk -v entrada=$1 '{if ( $0 ~ entrada ) {print NR}}' $arquivoConf
}
getValueRegex(){ 
# $1 == <Regex a ser procurado> 
# $2 == <Linha em que é para procurar o regex>

    # Mostrar o primeiro campo do conteudo que deu match
    awk -v regex="$1" -v line=$2 '{
        if ( $0 ~ regex && NR == line ) {
            print $1
        }    
    }' $arquivoConf
}

hasLiteral(){
# $1 == <Regex a ser procurado>
    lLiteral=$(getLineMatch "$1")
    if [ -z $lLiteral ] # Não existe liteal FATORES:
    then
        echo "Sintaxe incompativel"
        echo "--hasLiteral--"
        exit
    fi
}
nextLine(){
# $1 == <Linha atual>
    teste=$(echo $1 | grep -v "[^0-9]")
    if [ "-$teste" != "-" ]
    then
        echo $[ $1+1 ]
    fi
    echo ''
}
#fatores
fatores(){
    hasLiteral "^FATORES:$" #Se o literal não existe aborta o programa
    lLiteral=$(getLineMatch "^FATORES:$") # Pega a linha onde deu match
    line=$(nextLine $lLiteral) # Pega a proxima linha
    while [ 1 ]
    do
        # Procura o fator == <descritor de variavel>
        fator=$(getValueRegex "^( )*([a-zA-Z]+([0-9]*[a-zA-Z_]*)*)( )*=" $line)
        if [ -z $fator ] # Parou de dar Match:
        then
            return
        fi
        echo "$line $fator"
        line=$(nextLine $line) # Pega a proxima linha
    done
}

#comando
comando(){
    hasLiteral "^COMANDO:$" #Se o literal não existe aborta o programa
    lLiteral=$(getLineMatch "^COMANDO:$") # Pega a linha onde deu match
    line=$(nextLine $lLiteral) # Pega a proxima linha
    while [ 1 ]
    do
        # Procura o comando == <descritor de variavel>
        comand=$(getValueRegex "^( )*([a-zA-Z])+" $line)
        if [ -z $comand ] # Parou de dar Match:
        then
            return
        fi
        echo $comand
        line=$(nextLine $line) # Pega a proxima linha
    done
}

#ensaios
ensaios(){
    hasLiteral "^ENSAIOS:$" #Se o literal não existe aborta o programa
    lLiteral=$(getLineMatch "^ENSAIOS:$") # Pega a linha onde deu match
    line=$(nextLine $lLiteral) # Pega a proxima linha
    while [ 1 ]
    do
        # Procura o comando == <descritor de variavel>
        ensaio=$(getValueRegex "^( )*([0-9])+" $line)
        if [ -z $ensaio ] # Parou de dar Match:
        then
            return
        fi
        echo $ensaio
        line=$(nextLine $line) # Pega a proxima linha
    done
}

# Verifica a sintaxy do arquivo de configuração
parse(){
    fatores
    comando
    ensaios
}

cli $1 $2
parse