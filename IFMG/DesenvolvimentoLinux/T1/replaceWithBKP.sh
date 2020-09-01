#!/bin/bash

#Nome:  Lucas Mateus Fernandes
#Ra:    0035411

#set -o pipefail #Continua o pipline mesmo que uma instancia tenha dado errado

# Subistitui o arquivo criando os devidos backups
function replace(){
    local src=$1
    local destiny=$2
    bkp $src $destiny $destiny.bkp
}

# Substitui o arquivo fazendo o devido BackUp
function bkp(){ 
    local original=$1
    local desFile=$2
    local destBkp=$3

    if [ -e $original ]; then
        #Verifica se $destBkp é um arquivo inexistente e consequentimente valido
        [ -e $destBkp ] || { # <comand1>||<comand2> Comand2 so é executado se  Comand1 for False 
            # Cria um arq de backup
            mv $desFile $destBkp 2>/dev/null # 2>/dev/null Redireciona as mensagens de erro
            # Substitui
            cp -r $original $desFile
            return 0
        }
        # Recursividade
        bkp $original $destBkp $destBkp.bkp
    else
        echo "Arquivo Inexistente">&2
    fi
}


#Há uma execução diferente caso esteja em um pipeLine

if [ -t 0 ]; then #Verifica se o arquivo associado ao descritor de arquivo termina na janela do terminal.
    if [[ x$1 == 'x' ]]; then
        echo "Não foram passados argumentos">&2
    elif [[ x$2 == 'x' ]]; then
        replace $1 $1.bkp
    else
        replace $1 $2 
    fi
    exit
else #Caso o  descritor de arquivo esteja fora da janela do terminal.( ou seja dentro do pipeLine)
    while read LINE
    do
        replace $LINE $LINE.bkp 
    done
fi
