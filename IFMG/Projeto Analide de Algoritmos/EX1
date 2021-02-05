import math
# -*- coding: utf-8 -*-

def debugMatriz(matrix,y):
    for i in range(y+1):
        print('\t'.join(str(matrix[i]).split(', ')))
    print('\n')

def createMatrix(qtdItens, carga):
    """Cria uma matriz 'qtdItens' x 'carga' """
    matrix = []
    for i in range(qtdItens+1):
        #Cria 'carga' linhas
        matrix.append([]) 
        for j in range(carga+1):
            #Cria 'qtdItens' colunas
            matrix[i].append(0)
    return matrix

def out(totalItens, queuItens):
    """Printa a resposta"""
    quantidade = 0
    peso = 0
    resto = totalItens - len(queuItens)
    #Manipula a Saida
    for item in queuItens:
        quantidade = quantidade + item['quantidade']
        peso = peso + item['peso']

    print(str(quantidade)+" brinquedos\nPeso: "+str(peso)+" kg\nsobra(m) "+str(resto)+" pacote(s)\n")

def Item(string):
    """Cria um objeto que representa o item"""
    chuncks = string.split(" ");
    quantidade = int(chuncks[0]);
    peso = int(chuncks[1]);
    return {
        "quantidade":quantidade,
        "peso":peso
    }

def keyTupla(item):
    """Função que define como será ordenado"""
    return item['peso']

def solveMatrix(matrix, itens, qtdItens, maxKg):
    """Retorna quais itens fazem parte do problema da mochila para 'qtdItens' e maxKg a partir da matrix"""
    queuItens = []
    cargaAtual = maxKg
    valorAtual = matrix[len(itens)][maxKg]

    #Procura a Linha em que o valor da coluna 'x' é alterado
    for item in range( len(itens),0,-1 ):
        #Caso Base, pois chegou ao fim da tabela
        if( item == 0 ):
            break
        #Se o valor da coluna 'x' é alterado significa que aquele item foi alterado
        if(matrix[item][cargaAtual] != matrix[item-1][cargaAtual]):
            #Adiciona o item a lista
            queuItens.append( itens[item-1] )
            #Procura Qual o ponto SubOtimo antes da adição de tal elemento
            valorAtual = valorAtual - itens[item-1]['quantidade']
            cargaAtual = cargaAtual - itens[item-1]['peso']
            for carga in range( cargaAtual,0,-1 ):
                #Caso Base pois chegou no final da tabela
                if(carga == 0 ):
                    break
                #Verifica se a celula atual representa o ponto SubOtimo 
                if(valorAtual == matrix[item-1][carga]):
                    cargaAtual = carga
                else:
                    break
    return queuItens

def solve(itens):
    """Resolve o problema da mochila"""
    maxKg = 50;
    qtdItens = 0;
    qtdPacotes = 0;
    pesoSaco = 0;
    matrix = createMatrix( len(itens), maxKg )
    #Preencher a matriz representando os melhores casos Pontuais e como consequencial o melhor caso Glboal 
    for carga in range( 1,maxKg+1 ):
        for item in range( len(itens)+1 ):
            #Linha 0 ou Coluna 0 São casos Bases onde nada pode ser adicionado na mochila
            if(item == 0 or carga == 0):
                matrix[item][carga] = 0
                continue;
            itemAtual = itens[item-1]
            ultimaConfiguracao = matrix[item-1][carga]
            #Verifica se é melhor com o item ou sem o item atual
            if(itemAtual['peso'] <= carga):#Verifica se o item pode ser adicionado
                configuracaoPontual = matrix[item-1][carga - itemAtual['peso']]
                melhorCasoPontual = max( ultimaConfiguracao, itemAtual['quantidade'] + configuracaoPontual )
            else:#Caso o item não possa ser adicionado devido ao processo intermediario que aumenta gradativamente o peso da mochila
                melhorCasoPontual = ultimaConfiguracao
            # Seta a melhor configuação Pontual
            matrix[item][carga] = melhorCasoPontual
    #debugMatriz(matrix,len(itens))
    #Faz o callBack da matriz para verificar quais itens faz parte da melhor resposta
    queuItens = solveMatrix(matrix, itens, qtdItens, maxKg)
    return queuItens

def Input():
    """Pega a entrada de Dados"""
        
    qtdTeste = int(input());
    for i in range(qtdTeste):
        qtdPac = int(input());
        arrayItens  =  []
        totalItens = 0
        for i in range(qtdPac):
            instanciaStr = input();
            item = Item(instanciaStr)
            arrayItens.append( item );
            totalItens = totalItens + 1
        #Ordena o vetor por Peso
        arrayItens.sort(key = keyTupla)
        #Soluciona o problema
        result = solve( arrayItens )
        #for i in arrayItens:
        #    print(i)
        #Mostra a saida formatada
        out(totalItens,result)

Input()