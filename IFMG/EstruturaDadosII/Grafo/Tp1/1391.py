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
        cabecalho1 = input().split(" ")
        qtdVertice = int(cabecalho1[0]);
        qtdAresta = int(cabecalho1[1]);
        listaArestaAdjacente = [];
        if(qtdVertice == 0):
            self.qtdVertice = 0
            return

        cabecalho2 = input().split(" ")
        self.origen = int(cabecalho2[0]);
        self.destino = int(cabecalho2[1]);
                                                                                                                                                                                             
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
            #self.inserirAresta(listaArestaAdjacente, destino, origen, valor)#Inverso
        self.qtdVertice = qtdVertice;
        self.qtdAresta = qtdAresta;
        self.listaArestaAdjacente = listaArestaAdjacente
        return listaArestaAdjacente
    ################################################
    #           Manipulação de Aresta
    ################################################
    def inserirAresta(self, listaArestaAdjacente, verticeOrigem, verticeDestino, valorAresta):
        verticeOrigem = verticeOrigem
        verticeDestino = verticeDestino
        listaArestaAdjacente[verticeOrigem].append([verticeDestino,valorAresta])
    ################################################
    #           Menor caminho possivel
    ################################################
    def Dijkstra(self, listaArestaAdjacente):
        verticeOrigem = self.origen
        verticeDestino = self.destino
        caminho = []
        tabelaAux = []
        #IniciandoTabela 
        for i in range(self.qtdVertice):
            tabelaAux.append([])
        for i in range(self.qtdVertice):
            tabelaAux[0].append([])

        #Iniciando Processamento Passo 0
        tabelaAux[0][verticeOrigem] = [(0.0, verticeOrigem)] #O menor custo para chegar no vertice de origem é permanecer nele
        caminho.append( (verticeOrigem, 0, verticeOrigem) ) #(Origem, Custo, Destino)
        #Passo 1 adiante (A cada iteração acha o menor caminho até um vertice)
        for nPasso in range(1, self.qtdVertice):
            passoAnterior = nPasso - 1
            custoAtual = caminho[-1][1]# custoAtual é o custo até o ultimo vertice ja fechado/verificado
            verticeAtual = caminho[-1][2]# verticeAtual é o ultimo vertice fechado/verificado 
            #Copia o passo Anterior 
            tabelaAux[nPasso] = list(tabelaAux[passoAnterior])
            #Calcula o Menor Custo até o Vertice
            if(len(listaArestaAdjacente[verticeAtual]) != 0):
                for destino, custo in listaArestaAdjacente[verticeAtual]:#Passa por todas arestas adjacentes a aquele vertice
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
                def f(valor): #Função Usada para Ordenar
                    if(len(valor) > 0):
                        return valor[0][0]
                    else:
                        return 999999999999
                listaAux.sort(key=lambda x : f(x)) #Ordena a lista pelo primeiro indice da tupla
                #Vertice é inalcançavel?
                if(len(listaAux[nPasso]) == 0):
                    break;
                menorRelativo = listaAux[nPasso][0][0] #Pega o menor de acordo com o passo atual ( o 5º Passo pega o 5º Menor ou seja o 4º elemento em ordem crescente)
                contadorMenor = 0
                indiceIgual = 0
                for nVertice, lista in enumerate(tabelaAux[nPasso]):
                    if(lista != []):#Se lista não for vazia significa que o vertice ja foi alcançado e possui uma tupla
                        tupla = lista[0]
                        custo = tupla[0]
                        origem = tupla[1]
                        if(custo <= menorRelativo):
                            if(custo == menorRelativo):
                                indiceIgual = nVertice
                            contadorMenor = contadorMenor + 1
                            if(contadorMenor == nPasso + 1):
                                destino = indiceIgual
                                custo = tabelaAux[nPasso][destino][0][0]
                                origem = tabelaAux[nPasso][destino][0][1]
                                caminho.append( (origem, custo, destino) )
                                if(destino == verticeDestino):
                                    return (True,caminho)
                                break
                else:
                    break
        return (False,[])

    def RemoveCaminho(self, listaArestaAdjacente, caminho):
        #Percorre todos os vertices do camiho
        for i in range(len(caminho)-1, -1, -1):
            origen = caminho[i][0]
            destino = caminho[i][2]
            custo = -1
            #Acha o Custo
            for j in listaArestaAdjacente[origen]:
                if j[0] == destino:
                    custo = j[1]
                    break
            listaArestaAdjacente[origen].remove([destino, custo])

    def CaminhoLimpo(self, listaArestaAdjacente, caminho):
        novoCaminho = [] #Vetor de retorno que existe apenas o caminho minimo
        verticeAtual = caminho[-1][2] #Vertice Final/Destino
        #Procura as arestas que formam o caminho (de origen a destino)
        for i in range(len(caminho)-1, 0, -1):
            origen = caminho[i][0]
            custo = caminho[i][1]
            destino = caminho[i][2]
            if(destino == verticeAtual):#Verifica se da origen chega ao verticeAtual
                novoCaminho.append([origen,custo,destino])
                verticeAtual = origen;
        return novoCaminho









#Processamento Especifico para o problema
while True:
    G = Grafo()#Inicializa um Grafo
    G.listaAdjacencia()#Monta o grafo colocando as arestas
    if(G.qtdVertice == 0):
        break
    resposta = []
    #Aplica o dijkstra 
    caminho = G.Dijkstra(G.listaArestaAdjacente)
    #Verifica se origem alcança destino
    if(caminho[0]):
        caminho =(True, G.CaminhoLimpo(G.listaArestaAdjacente, caminho[1]))
        custoAtual = caminho[1][0][1]
        custoAnterior = custoAtual
        while(custoAtual == custoAnterior):
            if(caminho[0]):
                #Remove as Arestas
                G.RemoveCaminho(G.listaArestaAdjacente, caminho[1])
                #Aplica Dijkistra novamente
                caminho = G.Dijkstra(G.listaArestaAdjacente)
                if(caminho[0] == False):
                    custoAtual = -1
                    break
                #Pega o caminho mínimo que vai de origen até Final
                caminho = (True, G.CaminhoLimpo(G.listaArestaAdjacente, caminho[1]))
                #Arruma as variaveis para Verificar se é o segundo melhor caminho
                custoAnterior = custoAtual
                custoAtual = caminho[1][0][1]
            else:
                custoAtual = -1
    else:
        custoAtual = -1
