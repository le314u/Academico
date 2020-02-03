# -*- coding: utf-8 -*-
#Autor:Lucas Mateus Fernandes
#E-mail:lucasmfpiu@gmail.com
#Git:1ldomal2

#Tad Grafo por lista de Adjacencia
class Grafo():
    #Constantes
    __unvisited = 0#Não Visitado
    __visiting = 1#Vistando
    __visited = 2#Visitado

    def  __init__(self): 
        self.qtdVertice = 0;
        self.qtdAresta = 0;
        self.listaArestaAdjacente = [];#Lista de Lista [Destino,Valor]
        self.listaArestaAdjacenteTransposta = []#Lista de Lista [Destino,Valor]

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
            entrada = input().split(' ')
            origen = int(entrada[0])
            destino = int(entrada[1])
            valor = int(1)
            self.inserirAresta(listaArestaAdjacente, origen, destino, valor)
            self.inserirAresta(listaArestaAdjacente, destino, origen, valor)
        self.qtdVertice = qtdVertice;
        self.qtdAresta = qtdAresta;
        self.listaArestaAdjacente = listaArestaAdjacente
        return listaArestaAdjacente
    
    ################################################
    #           Manipulação de Aresta
    ################################################
    def inserirAresta(self, listaArestaAdjacente, verticeOrigem, verticeDestino, valorAresta = 1):
        #vertice 1 == Index 0
        verticeOrigem = verticeOrigem - 1
        verticeDestino = verticeDestino -1
        #Add Aresta
        listaArestaAdjacente[verticeOrigem].append([verticeDestino,valorAresta])

    ################################################
    #           Processamento
    ################################################
        
    def buscaProfundidade(self):
        #Cria um vetor onde informara se o vertice foi visitado ou não
        numeroPartesConexas = 0
        statusVertix = []
        visitation = []
        #Preparando para evitar ciclos
        for i in range(self.qtdVertice):
            statusVertix.append(self.__unvisited);
        #Percorre Todos os vertices 
        for verticeOrigem in range(self.qtdVertice):
            if(statusVertix[verticeOrigem] == self.__visited):
                continue;
            statusVertix[verticeOrigem] = self.__visiting;
            numeroPartesConexas = numeroPartesConexas + 1
            #Faz a busca
            visitation.append(verticeOrigem);
            while (len(visitation) != 0):
                #Desempilha
                currentVertice = visitation.pop()
                #Empilha todas arestas daquele Vertice
                for vertix, value in self.listaArestaAdjacente[currentVertice]:
                    if statusVertix[vertix] == self.__unvisited:
                        statusVertix[vertix] = self.__visiting;
                        visitation.append(vertix);
                statusVertix[currentVertice] = self.__visited;
            #apartir de um vertice eu chego em todos?
        return numeroPartesConexas

        
G = Grafo()#Inicializa um Grafo
G.listaAdjacencia()#Monta o grafo colocando as arestas
print(G.buscaProfundidade())
