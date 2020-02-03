# -*- coding: utf-8 -*-
#Autor:Lucas Mateus Fernandes
#E-mail:lucasmfpiu@gmail.com
#Git:1ldomal2
#Tad Grafo por lista de Adjacencia
class Grafo():
    def  __init__(self): 
        self.qtdVertice = 0;
        self.qtdAresta = 0;
        self.listaArestaAdjacente = [];#Lista de Lista [Destino,Valor]
        self.listaArestaAdjacenteTransposta = []#Lista de Lista [Destino,Valor]
    ################################################
    #           Representação do Grafo
    ################################################
    def listaAdjacencia(self):
        #Le cabeçalho=
        cabecalho = input().split(" ")
        qtdVertice = int(cabecalho[0]);
        qtdAresta = int(cabecalho[1]);
        listaArestaAdjacente = [];
        #Cria 'n' Vertices
        #Cria uma lista com n Listas
        for i in range(qtdVertice):
            listaArestaAdjacente.append(list())
        #Cria 'n' Arestas
        for i in range(qtdAresta):
            entrada = input()
            entrada = entrada.split(' ')
            origen = int(entrada[0])
            destino = int(entrada[1])
            valor = float(entrada[2])
            self.inserirAresta(listaArestaAdjacente, origen, destino, valor)#Normal
            self.inserirAresta(listaArestaAdjacente, destino, origen, valor)#Inverso
        self.qtdVertice = qtdVertice;
        self.qtdAresta = qtdAresta;
        self.listaArestaAdjacente = listaArestaAdjacente
        return listaArestaAdjacente
    ################################################
    #           Manipulação de Aresta
    ################################################
    def inserirAresta(self, listaArestaAdjacente, verticeOrigem, verticeDestino, valorAresta):
        verticeOrigem = verticeOrigem - 1
        verticeDestino = verticeDestino - 1
        listaArestaAdjacente[verticeOrigem].append([verticeDestino,valorAresta])
    ################################################
    #           Menor caminho possivel
    ################################################
    def Dijkstra(self, listaArestaAdjacente, verticeOrigem):
        """
        Caminho minimo partindo do verticeOrigem
        Legenda $caminho:
        caminho é uma lista de tuplas sendo as tuplas compostas de (origem, custo, destino)  
        """
        caminho = []
        #IniciandoTabela 
        """
        Legenda $tabelaAux
        tabela aux é a simulação de uma matrix onde cada elemento é uma lista que pode estar vazia ou ter uma tupla sendo a tupla formado por (custo, origem)
        Matrix tem as seguintes caracteristicas:(Linha = Numero do Passo    Coluna = Vertice de Destino)
        """
        tabelaAux = []
        for i in range(self.qtdVertice + 1):
            tabelaAux.append([])
        for i in range(self.qtdVertice):
            tabelaAux[0].append([])
        #Iniciando Processamento Passo 0
        tabelaAux[0][verticeOrigem] = [(0.0, verticeOrigem)] #Pois o menor custo para chegar no vertice de origem é permanecer nele
        caminho.append( (verticeOrigem, 0, verticeOrigem) ) #(Origem, Custo, Destino)  
        #Passo 1 adiante
        for nPasso in range(1, self.qtdVertice):
            passoAnterior = nPasso - 1
            custoAtual = caminho[-1][1]# custoAtual é o custo até o ultimo vertice ja fechado/verificado
            verticeAtual = caminho[-1][2]# verticeAtual é o ultimo vertice fechado/verificado 
            #Copia o passo Anterior 
            tabelaAux[nPasso] = list(tabelaAux[passoAnterior])
            #Calcula o Menor Custo até o Vertice
            for destino, custo in listaArestaAdjacente[verticeAtual]:
                menorCusto = custoAtual + custo
                if len(tabelaAux[nPasso][destino]) != 0: #Verifica se tem outra maneira de chegar ao vertice
                    if menorCusto < tabelaAux[nPasso][destino][0][0]: #Verifica se mesmo tendo outro caminho este é o menor
                        tabelaAux[nPasso][destino] = [(menorCusto, verticeAtual)]#Atualiza o menor custo
                    else:
                        #Mantem o Custo
                        pass
                else:
                    #Caso ainda não tenha outra maneira de chegar ao vertice
                    tabelaAux[nPasso][destino] = [(menorCusto, verticeAtual)]
            #Verifica qual o proximo vertice a ser analisado
            listaAux = list(tabelaAux[nPasso]) #Copia a lista 
            def f(valor):
                if(len(valor) > 0):
                    return valor[0][0]
                else:
                    return 999999999999
            listaAux.sort(key=lambda x : f(x)) #Ordena a lista pelo primeiro indice da tupla
            menorRelativo = listaAux[nPasso][0][0] #Pega o menor de acordo com o passo atual ( o 5º Passo pega o 5º Menor ou seja o 4º elemento em ordem crescente)
            contadorMenor = 0
            indiceIgual = 0
            for nVertice, lista in enumerate(tabelaAux[nPasso]):
                """
                Legenda $lista
                lista é uma lista vazia ou que contem uma tupla
                Legenda $nVertice
                #nVertice é o Numero do vertice   
                """    
                if(lista != []):#Se lista não for vazia significa que o vertice ja foi alcançado e possui uma tupla
                    tupla = lista[0]
                    """
                    Legenda $tupla
                    tupla é um par ordenado que possui (custo, origem)
                    """
                    custo = tupla[0]
                    origem = tupla[0]
                    if(custo <= menorRelativo):
                        if(custo == menorRelativo):
                            indiceIgual = nVertice
                        contadorMenor = contadorMenor + 1
                        if(contadorMenor == nPasso + 1):
                            destino = indiceIgual
                            custo = tabelaAux[nPasso][destino][0][0]
                            origem = tabelaAux[nPasso][destino][0][1]
                            caminho.append( (origem, custo, destino) )
                            break               
        #Acabou porem so será valido se todos os vertices são alcançaveis a partir de verticeOrigem
        for vertice in tabelaAux[-1]:
            if(len(vertice) == 0):
                caminho = []
                break
        return caminho


#Processamento Especifico para o problema
while True:
    retorno =""
    G = Grafo()#Inicializa um Grafo
    G.listaAdjacencia()#Monta o grafo colocando as arestas
    if(G.qtdVertice == 0):
        break
    resposta = []
    #Aplica o dijkstra em todos os vertices
    for vertice in range(G.qtdVertice):
        caminho = G.Dijkstra(G.listaArestaAdjacente, vertice)
        if(len(caminho)!= 0):#Se o caminho percorrer todos os vertices #Tratamento feito dentro de Dijkstra
            custoCaminho = 0
            for custo in caminho:
                custoCaminho = custoCaminho + custo[1]
        else:
            custoCaminho = -1
        resposta.append( (custoCaminho, vertice) )
    listaAux = list( resposta )#Clona a lista
    listaAux.sort(key=lambda x : x[0]) #Ordena a lista pelo primeiro indice da tupla
    for i in range(len(resposta)):
        retorno = retorno + str(int(listaAux[i][1])+1) + " "
        if(len(listaAux) > 1):
            if(i < len(listaAux)-1):
                if(listaAux[i][0] != listaAux[i+1][0]):
                    break
        else:
            break
    print(retorno)


