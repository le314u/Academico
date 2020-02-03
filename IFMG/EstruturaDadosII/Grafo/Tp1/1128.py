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
        self.listaAdjacencia()
        self.listaAdjacenciaTransposta()
    def listaAdjacencia(self):
        #Le cabeçalho
        cabecalho = input()
        cabecalho = cabecalho.split(" ")
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
            entrada = entrada.split(" ")
            valor = int(1)
            self.inserirAresta(listaArestaAdjacente, int(entrada[0]), int(entrada[1]), valor)
            if(int(entrada[2]) == 2):#Duas mãos
                self.inserirAresta(listaArestaAdjacente, int(entrada[1]), int(entrada[0]), valor)
        self.qtdVertice = qtdVertice;
        self.qtdAresta = qtdAresta;
        self.listaArestaAdjacente = listaArestaAdjacente
        return listaArestaAdjacente
    def listaAdjacenciaTransposta(self):
        listaArestaAdjacenteTransposta = []
        for i in range(self.qtdVertice):
            listaArestaAdjacenteTransposta.append(list())
        for indice, lista in enumerate(self.listaArestaAdjacente):
            for aresta in lista:
                #Invertido
                #destino = indice + 1
                #origen = aresta[0] + 1
                #valor = aresta[1]
                self.inserirAresta(listaArestaAdjacenteTransposta, aresta[0] + 1, indice + 1, aresta[1])
        self.listaArestaAdjacenteTransposta = listaArestaAdjacenteTransposta 
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
    def buscaProfundidade(self, listaArestaAdjacente, verticeOrigem):
        #Cria um vetor onde informara se o vertice foi visitado ou não
        statusVertix = []
        visitation = []
        numeroNaoVisitados = self.qtdVertice
        #Preparando para evitar ciclos
        for i in range(self.qtdVertice):
            statusVertix.append(self.__unvisited);
        statusVertix[verticeOrigem] = self.__visiting;
        #Faz a busca
        visitation.append(verticeOrigem);
        while (len(visitation) != 0):
            #Desempilha
            currentVertice = visitation.pop()
            numeroNaoVisitados = numeroNaoVisitados -1
            #Empilha todas arestas daquele Vertice
            for vertix, value in listaArestaAdjacente[currentVertice]:
                if statusVertix[vertix] == self.__unvisited:
                    statusVertix[vertix] = self.__visiting;
                    visitation.append(vertix);
            statusVertix[currentVertice] = self.__visited;
        #apartir de um vertice eu chego em todos?
        return numeroNaoVisitados == 0
    def conexo(self):
        verticeOrigem = 0
        if self.buscaProfundidade(self.listaArestaAdjacente, verticeOrigem):
            if self.buscaProfundidade(self.listaArestaAdjacenteTransposta, verticeOrigem):
                return 1
            else:
                return 0
        else:
            return 0
        
while True:
    G = Grafo()#Inicializa um Grafo
    if(G.qtdAresta == 0 and G.qtdVertice == 0):
        print("\n")
        break
    #Mostra se é fortemente conexo
    print(G.conexo())
