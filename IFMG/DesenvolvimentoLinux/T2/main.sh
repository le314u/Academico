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
    local lLiteral=$(getNumberLineMatch "$1")
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
    local line=$1
    local fator=$(getValueRegex_campo1 "^( )*([a-zA-Z]+([0-9]*[a-zA-Z_]*)*)( )*" $line)|sed 's/ //g'|sed 's/=//g'
    GLOBAL_fatores+=("$fator")
}

# Auto incrementa a variavel passada
nextLine(){
# $1 == <Linha atual>
    echo $(incrementa $1)
}

#Adiciona 1 ao numero passado
incrementa(){
# $1 == <numero>
    local teste=$(echo $1 | grep -v "[^0-9]")
    if [ "-$teste" != "-" ]
    then
        echo $[ $1+1 ]
    fi
    echo ''
}

# Transforma o conteudo da linha 'x' em uma variavel
createVariable(){
# $1 == <linha onde é declarada o fato>
    local contentLine=$(showLine $line)
    local express=$(echo $contentLine | sed 's/,/ /g' | sed 's/ = /=/g')
    eval $express
}

# Le os fatores e transforma em um array e salva seus descritores em uma variavel Global
fatores(){
    hasLiteral "^FATORES:$" #Se o literal não existe aborta o programa
    local lLiteral=$(getNumberLineMatch "^FATORES:$") # Pega a linha onde deu match
    local line=$(nextLine $lLiteral) # Pega a proxima linha
    while [ 1 ]
    do
        # Pega o fator ou seja o <descritor de variavel>
        local fator=$(getValueRegex_campo1 "^( )*([a-zA-Z]+([0-9]*[a-zA-Z_]*)*)( )*=" $line)
        if [ -z $fator ] # Não existe Descritor
        then
            return
        fi
        # Transforma o conteudo da linha X em uma variavel
        createVariable $line
        saveFactor $line
        local line=$(nextLine $line) # Pega a proxima linha
    done
}

# Salva a lista de comandos
saveCommand(){
# $1 == linha onde o comando é declarado
    local line=$1
    local comand=$(showLine $line)
    GLOBAL_comandos+=("$comand")
}

# Verifica se o comando tem apenas fatores validos
checkComand(){
# $1 == <comando> 
    local comando=$1
    local factors=$(echo $comando |tr " " "\n" | grep -o "^\$.*"| sed 's/\$//g') # Pega o fator
    local flagReturn=0
    for element_X in $factors
    do
        if [ -n "$element_X" ] # so checa se for um fator
        then
            local isValid=0 # Flag começo como falso porem durante a execução por se tornar verdadeira
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
# Salva a ordem que as variaveis aparecem no comando
orderVariableInComand(){
# $1 == <Comando>
    local comando=$1
    for chunck in $comando;
    do
        local isVariable=$(echo $chunck|grep -o "\$[a-zA-Z]\+\([0-9]*[a-zA-Z]*\)*")
        if [ "-$isVariable" != "-" ]
        then
            #Salva a variavel
            saveOrderVariable $isVariable
        fi
    done
}
# Le os comandose salva em uma variavel Global GLOBAL_comandos
comando(){
    hasLiteral "^COMANDO:$" #Se o literal não existe aborta o programa
    local lLiteral=$(getNumberLineMatch "^COMANDO:$") # Pega a linha onde deu match
    local line=$(nextLine $lLiteral) # Pega a proxima linha
    while [ 1 ]
    do
        # Procura o comando == <descritor de variavel>
        local comand=$(showLine $line)
        if [ -z "$comand" ] # Parou de dar Match:
        then
            return
        fi
        local isValid=$(checkComand "$comand")
        if [ "$isValid" = "1" ]
        then
            saveCommand $line # Salva o comando
            orderVariableInComand "$(showLine $line)" # Pega a ordem que as variaveis aparecem no comando
            return # Comentar esta linah faz ler mais de um comando
            line=$(nextLine $line) # Pega a proxima linha
        else
            echo "Sintaxy de comando inadequada:"
            echo $comand
            exit
        fi
    done
}

# Salva a ordem em que as variaveis aparece dentro do comando
saveOrderVariable(){
# $1 == instancia de ensaio
    GLOBAL_orderVariable+=("$1")
}
#Verifico se a quantidade de niveis de um ensaio é igual a quantidade de Fatores dentro de um comando ou seja 1:1
ensaioCompativelComando(){
# $@ == <ensaio>
    local ensaio
    IFS=' ' read -a ensaio <<< $1
    local compativel=0
    if [ ${#GLOBAL_orderVariable[@]} -eq ${#ensaio[@]} ]
    then
        compativel=1
    else
        echo "Sintaxy do ensaio incorreta"
        exit
    fi
}

# Persiste um ensaio no arquivo de saida
saveInstancia(){
# $1 == <instancia>
    GLOBAL_instancia+=("$1")
}
#Verifica se no vetor possui asterisco
hasAsterisk(){
    local input=("$@")
    local has=0
	local i=0
	for (( i=0; i<${#GLOBAL_orderVariable[*]}; i++ ))
	do
		if [ ${input[$i]} = "\"*\"" ]
		then  		
			has=1
            break;
		fi
	done
	echo $has
}
#Le a linha da instancia do ensaio e altera caso for *
mask2Instancia(){
# $1 == <string contendo o Ensaio>
# $2 == <Index do nivel dentro de um ensaio> 
    local stringEnsaio="$1"
    local index="$2"
    # Transforma a entrada em um vetor
    local ensaio
    IFS=' ' read -a ensaio <<< $stringEnsaio
    # Quantidade de fatores no comando
    local tamanho=${#GLOBAL_orderVariable[*]}   
    local ultimoIndex=$[ $tamanho - 1 ]
    
    #Percorro todos os fatores do comando <$A $B $C>
    local i=''
    for (( i=$index; i < $tamanho; i++ ))
    do
    	if [ "${ensaio[$i]}" = "\"*\"" ] # Se for * altero pelos valores possiveis
    	then
        
            trocaMask2Instancia "$stringEnsaio" "$i"      
    	fi
    done
    # Verifico se está apto a salvar
    if [ $[ $i ] -ge $[ $ultimoIndex ] ]
    then
        
        if [ $(hasAsterisk "${ensaio[@]}") == "0" ]
        then
            #Caso base ou seja quando não há mais Fatos a ser desdobrado
            saveInstancia "$(echo ${ensaio[@]})"
            return
        fi
    fi
}

# Subistitui o * por todos os valores do vetor
trocaMask2Instancia(){
# $1 == <String com o Ensaio>
# $2 == <Index do fator dentro do ensaio que esta sendo alterado>
    local stringEnsaio="$1"
    local index=$[ $2+0 ]
    # Transforma a stringEnsaio em um vetor
    local ensaio
    IFS=' ' read -a ensaio <<< $stringEnsaio

    # Niveis = <vetor presente em $FATOR>
    local descritorVariable=$(echo $(echo ${GLOBAL_orderVariable[$index]}|sed 's/\$//g') )
    local Niveis
    eval $( echo Niveis=\$\{$descritorVariable\[\@\]\} )
    local vetNiveis
    IFS=' ' read -a vetNiveis <<< $Niveis
    local qtdNiveis=${#vetNiveis[@]}
    # Passa por todos os valores de um fator <valores> de um fator                
    local i=''
    for (( i=0; i<$qtdNiveis; i++ ))
    do
        # Faço a troca do elemento no ensaio
        local newElement=${vetNiveis[ $(($i)) ]}
        ensaio[ $(($index)) ]="$newElement"
        #Chama uma bifurcação
        local nextIndex=$(incrementa $index)
        mask2Instancia "$(echo ${ensaio[@]})" "$nextIndex"
    done
    return
}

#ensaios
ensaios(){
    hasLiteral "^ENSAIOS:$" #Se o literal não existe aborta o programa
    local lLiteral=$(getNumberLineMatch "^ENSAIOS:$") # Pega a linha onde deu match
    local line=$(nextLine $lLiteral) # Pega a proxima linha
    while [ 1 ]
    do
        # Procura o comando == <descritor de variavel>
        local ensaio=$(getValueRegex_campo1 "^( )*([0-9])+( )*=( )*" $line)       
        if [ -z $ensaio ] # Parou de dar Match:
        then
            return
        fi
        #pega os valores dos ensaior aindacom mascara ou seja '*'
        local ensaioMask=$(showLine $line| sed 's/\∗/\*/g' | sed 's/^ *[0-9]\+ *= *//g'| sed 's/,/ /g'| sed 's/  / /g'| sed 's/ *$//g'| sed 's/\*/"*"/g') # não sei mas passar apenas '*' estava causando u merro inesperado

        #Verifica se a quantidade de Fatores no comando é compativel com a quantidade de elementos no ensaio
        ensaioCompativelComando "$ensaioMask" # Caso contrário encerra a execução
        #Desdobra '*' em valores possiveis	
        mask2Instancia "$ensaioMask" "0"
        line=$(nextLine $line) # Pega a proxima linha
    done
}
stringComand(){
# $1 == Numero da Instancia
    local instancia=${GLOBAL_instancia[$1]}
    local vetInstancia
    read -a vetInstancia <<< $instancia

    # Para cada variavel em GLOBAL_orderVariable troca por um valor em vetInstancia
    local newComand="${GLOBAL_comandos[@]}"
    for (( i=0; i<${#GLOBAL_orderVariable[@]}; i++ ))
    do
        newComand=$( echo $newComand | sed "s/${GLOBAL_orderVariable[$i]}/${vetInstancia[$i]}/g" )
    done
    echo $newComand    
}

runAndLog(){
# $1 === <Meta Dados da instancia>
    local comand=$(cat -)
    local MetaInstancia=$1
    #Executa o comando
    local dataInit=`date +%s.%N`
    local outputComand=$($comand )
    local dataEnd=`date +%s.%N`
    #Calcula a diferença entre as datas
    local duration=$( echo "$dataEnd - $dataInit" | bc -l) 
    #Separa em esquerda e direita da virgula
    local LComma=$(echo "$duration"| cut -d'.' -f1)
    local RComma=$(echo "$duration"| cut -d'.' -f2)
    #POG
    if [ -z $LComma ]
    then
        LComma="0"
    fi
    local duration=$(echo $(date -u -d@"$(( $LComma ))" +"%H:%M:%S").$RComma)
    #Salva no Arquivo
    echo $outputComand | awk -v instancia="$MetaInstancia" -v duration="$duration" '
        BEGIN {
            printf("EXPERIMENTO %s  DURAÇÃO %s\n",instancia,duration);
        }
        {
            print $0
        }
        END {
            print "\n";
        } 
    ' >> $GLOBAL_arquivoOutput

}
allRun(){
    local i
    for (( i=0; i<${#GLOBAL_instancia[@]}; i++ ))
    do
        echo $(stringComand "$i")|runAndLog "${GLOBAL_instancia[$i]}"
    done
}
# Verifica a sintaxy do arquivo de configuração e prepara o ambiente
main(){
    # Pega os dados que entram via CLI
    cli $1 $2
    # Preparação
    fatores # Analisa e extrai os dados relevante aos fatores <variaveis>
    comando # Analisa e extra os dados relevantes ao comando
    ensaios # Analisa e expecifíca os valores de cada instância de execução
    #Cria um novo arquivo de log
    echo "">$GLOBAL_arquivoOutput
    #Execução salvando o Log
    allRun
}

main $1 $2