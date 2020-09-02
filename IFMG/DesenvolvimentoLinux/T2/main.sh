#!/bin/bash

# Analisa as entradas e verifica se são entradas validas
cli(){
# $1 == Input
# $2 == Output
    #Verifica se o primeiro argumento passado é um arquivo 
    if [ -f $1 ]
    then
        GLOBAL_arquivoConf=$1 #Arquivo onde será lido as configurações
        GLOBAL_arquivoOutput=$2 #Arquivo de log
    else 
        echo "Não existe arquivo de configuração."
        exit # Encerra o programa
    fi
}

# Retorna o numero da linha em que o regex deu Match
getNumberLineMatch(){
# $1 == <Regex a ser procurado>
    # Mostrar a linha do Literal
    awk -v entrada=$1 '{if ( $0 ~ entrada ) {print NR}}' $GLOBAL_arquivoConf
}

# Retorna o primeiro campo caso o regex esteja presente na linha 'X'
getValueRegex_campo1(){ 
# $1 == <Regex a ser procurado> 
# $2 == <Linha em que é para procurar o regex>

    # Mostrar o primeiro campo do conteudo que deu match
    awk -v regex="$1" -v line=$2 '{
        if ( $0 ~ regex && NR == line ) {
            print $1
        }    
    }' $GLOBAL_arquivoConf
}

# Retorna o conteudo da linha 'x'
showLine(){ 
# $1 == <Linha em que é para procurar o regex>

    # Mostrar o conteudo da linha 'x'
    awk -v line=$1 '{
        if ( NR == line ) {
            print $0
        }    
    }' $GLOBAL_arquivoConf
}

# Sai do programa caso literal não exista
hasLiteral(){
# $1 == <Regex a ser procurado>
    lLiteral=$(getNumberLineMatch "$1")
    if [ -z $lLiteral ] # Não existe liteal FATORES:
    then
        echo "Sintaxe incompativel"
        echo "--hasLiteral--"
        exit
    fi
}

# Salva o nome do fator em uma variavel Global <fatores>
saveFactor(){
# $1 == linha onde o fator é declarado
    line=$1
    fator=$(getValueRegex_campo1 "^( )*([a-zA-Z]+([0-9]*[a-zA-Z_]*)*)( )*" $line)|sed 's/ //g'|sed 's/=//g'
    GLOBAL_fatores+=("$fator")
}

# Auto incrementa a variavel passada
nextLine(){
# $1 == <Linha atual>
    echo $(contador $1)
}

#Adiciona 1 ao numero passado
contador(){
# $1 == <numero>
    teste=$(echo $1 | grep -v "[^0-9]")
    if [ "-$teste" != "-" ]
    then
        echo $[ $1+1 ]
    fi
    echo ''
}

# Transforma o conteudo da linha 'x' em uma variavel
createVariable(){
# $1 == <linha onde é declarada o fato>
    contentLine=$(showLine $line)
    express=$(echo $contentLine | sed 's/,/ /g' | sed 's/ = /=/g')
    eval $express
}

# Le os fatores e transforma em um array e salva seus descritores em uma variavel Global
fatores(){
    hasLiteral "^FATORES:$" #Se o literal não existe aborta o programa
    lLiteral=$(getNumberLineMatch "^FATORES:$") # Pega a linha onde deu match
    line=$(nextLine $lLiteral) # Pega a proxima linha
    while [ 1 ]
    do
        # Pega o fator ou seja o <descritor de variavel>
        fator=$(getValueRegex_campo1 "^( )*([a-zA-Z]+([0-9]*[a-zA-Z_]*)*)( )*=" $line)
        if [ -z $fator ] # Não existe Descritor
        then
            return
        fi
        # Transforma o conteudo da linha X em uma variavel
        createVariable $line
        saveFactor $line
        line=$(nextLine $line) # Pega a proxima linha
    done
}

# Salva a lista de comandos
saveCommand(){
# $1 == linha onde o comando é declarado
    line=$1
    comand=$(showLine $line)
    GLOBAL_comandos+=("$comand")
}

# Verifica se o comando tem apenas fatores validos
checkComand(){
# $1 == <comando> 
    comando=$1
    factors=$(echo $comando |tr " " "\n" | grep -o "^\$.*"| sed 's/\$//g') # Pega o fator
    flagReturn=0
    for element_X in $factors
    do
        if [ -n "$element_X" ] # so checa se for um fator
        then
            isValid=0 # Flag começo como falso porem durante a execução por se tornar verdadeira
            for element_Y in ${GLOBAL_fatores[@]}
            do
                if [ "$element_Y" = "$element_X" ]
                then
                    isValid=1
                fi
            done
        fi
        flagReturn=$isValid
        if [ "$isValid" = "0" ]
        then
            break
        fi
    done
    echo $flagReturn
}

# Le os comandose salva em uma variavel Global GLOBAL_comandos
comando(){
    hasLiteral "^COMANDO:$" #Se o literal não existe aborta o programa
    lLiteral=$(getNumberLineMatch "^COMANDO:$") # Pega a linha onde deu match
    line=$(nextLine $lLiteral) # Pega a proxima linha
    while [ 1 ]
    do
        # Procura o comando == <descritor de variavel>
        comand=$(showLine $line)
        if [ -z "$comand" ] # Parou de dar Match:
        then
            return
        fi
        isValid=$(checkComand "$comand")
        if [ "$isValid" = "1" ]
        then
            saveCommand $line # Salva o comando
            return # Comentar esta linah faz ler mais de um comando
            line=$(nextLine $line) # Pega a proxima linha
        else
            echo "Sintaxy de comando inadequada:"
            echo $comand
            exit
        fi
    done
}

# Salva a lista de ensaios
saveEnsaio(){
# $1 == instancia de ensaio
    GLOBAL_ensaios+=("$1")
}

# Trata o '*'
percorre(){ # *, *, *
# $1 == <Valores do ensaio>
    vetValores=$1
    cont=0
    for element in ${vetValores[@]};do
        if [ "$element" = "*" ]
        then
        echo $GLOBAL_comandos|grep -o $([a-zA-Z]+([0-9]*[a-zA-Z_]*)*)
            #Desdobro o * em todos os valores possíveis
        fi
        cont=$(contador cont)
    done
}

#ensaios
ensaios(){
    hasLiteral "^ENSAIOS:$" #Se o literal não existe aborta o programa
    lLiteral=$(getNumberLineMatch "^ENSAIOS:$") # Pega a linha onde deu match
    line=$(nextLine $lLiteral) # Pega a proxima linha
    while [ 1 ]
    do
        # Procura o comando == <descritor de variavel>
        ensaio=$(getValueRegex_campo1 "^( )*([0-9])+( )*=( )*" $line)
        if [ -z $ensaio ] # Parou de dar Match:
        then
            return
        fi
        valoresEnsaios=$(showLine $line|sed 's/^( )*([0-9])+( )*=( )*//g'|sed 's/, / /g')
        percorre $valoresEnsaios
        line=$(nextLine $line) # Pega a proxima linha
    done
}

# Verifica a sintaxy do arquivo de configuração e prepara o ambiente
parse(){
    fatores
    echo ${GLOBAL_fatores[@]}
    comando
    echo ${GLOBAL_comandos[@]}
    ensaios
}

cli $1 $2
parse


echo "Verificar Linha l_212 e função percorre l_185"