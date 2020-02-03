# -*- coding: utf-8 -*-
#Autor:Lucas Mateus Fernandes
#E-mail:lucasmfpiu@gmail.com
#Git:1ldomal2

#Tad Grafo por lista de Adjacencia
class Grafo():
    
    def  __init__(self): 
        #Constantes
        self.__unvisited = 0#Não Visitado
        self.__visiting = 1#Vistando
        self.__visited = 2#Visitado
        self.qtdVertice = 0;
        self.qtdAresta = 0;
        self.listaArestaAdjacente = [];#Lista de Lista [Destino,Valor]
        self.listaArestaAdjacenteTransposta = []#Lista de Lista [Destino,Valor]
        self.listaAdjacencia()
    ################################################
    #           Representação do Grafo
    ################################################
    def listaTransposta(self, listaArestaAdjacente):
        """Cria lista Transposta"""
        listaArestaAdjacenteTransposta = []
        #Cria 'n' Vertices
        for i in range(0,self.qtdVertice):
            listaArestaAdjacenteTransposta.append(list())
            
        #Cria 'n' Arestas
        for vertice, vertices in enum(listaArestaAdjacente):
            for aresta in vertices:
                valorAresta = aresta[1]
                verticeOrigem = aresta[0]
                verticeDestino = vertice
                listaArestaAdjacenteTransposta[verticeOrigem].append([verticeDestino,valorAresta])
        return listaTransposta

    def listaAdjacencia(self):
        cabecalho = input()
        cabecalho = cabecalho.split(" ")
        #Le cabeçalho
        self.qtdVertice = int(cabecalho[0]);
        self.qtdAresta = int(cabecalho[1]);
        listaArestaAdjacente = [];
        matrixAdjacencia = []
        #Cria 'n' Vertices
        #Cria uma lista com n Listas
        for i in range(self.qtdVertice):
            listaArestaAdjacente.append(list())
            matrixAdjacencia.append(list())
            for j in range(0,self.qtdVertice):
                matrixAdjacencia[i].append(False)
        #Cria 'n' Arestas
        for i in range(self.qtdAresta):
            entrada = input()
            entrada = entrada.split(' ')
            origen = int(entrada[0])
            destino = int(entrada[1])
            valor = 1
            if(matrixAdjacencia[origen - 1][destino - 1] == False):
                self.inserirAresta(listaArestaAdjacente, origen, destino, valor)
                matrixAdjacencia[origen - 1][destino - 1] = True
        self.listaArestaAdjacente = listaArestaAdjacente
        return listaArestaAdjacente

    ################################################
    #           Manipulação de Aresta
    ################################################
    def inserirAresta(self, listaArestaAdjacente, verticeOrigem, verticeDestino, valorAresta = 1):
        verticeOrigem = verticeOrigem - 1
        verticeDestino = verticeDestino - 1
        listaArestaAdjacente[verticeOrigem].append([verticeDestino,valorAresta])

    
    ################################################
    #           Manipulação de Vertice
    ################################################
    def inserirVertice(self, numeroVertice):
        pass
    def removerVertice(self, numeroVertice):
        pass

    ################################################
    #           Percorrer o Grafo
    ################################################

    def hasLoop(self):
        #Verificar que mfaz parte da parte conexa
        #Cria um vetor onde informara se o vertice foi visitado ou não
        statusVertix = []
        visitation = []
        #Preparando terreno para evitar ciclos
        for i in range(0,self.qtdVertice):
            statusVertix.append(self.__unvisited);
        #Começa Busca em Largura/Profundidade
        for indice, status in enumerate(statusVertix):
            if status == self.__unvisited :
                statusVertix[indice] = self.__visiting;
                visitation.append(indice);
                statusModification = []
                #Enquanto A busca estiver ativa
                while (len(visitation) != 0):
                    #Desempilha
                    currentVertice = visitation.pop()
                    visitation.append(currentVertice)
                    statusVertix[currentVertice] = self.__visiting
                    statusModification.append(currentVertice)
                    #Empilha todas arestas daquele Vertice
                    for vertix, value in self.listaArestaAdjacente[currentVertice]:
                        if statusVertix[vertix] == self.__unvisited:
                            statusVertix[vertix] = self.__visiting;
                            statusModification.append(currentVertice)
                            visitation.append(vertix);
                        else:
                            if(statusVertix[vertix] == self.__visiting):
                                return "SIM"
                    statusVertix[visitation[0]] = self.__visited
                    visitation.pop()




    def hasLoop(self):
        #Cria um vetor onde informara se o vertice foi visitado ou não
        statusVertix = []
        visitation = []
        parteConexa = []
        statusParteConexa = []
        #Preparando terreno para evitar ciclos
        for i in range(0,self.qtdVertice):
            statusVertix.append(self.__unvisited);
            statusParteConexa.append(False);
       

        
        for i in range(len(statusParteConexa)):
            currentVertice = i
            if(statusParteConexa[i] == False):

                #Faz a Busca em largura para achar o vertice mais distante do vertice que esta sendo pesquisado
                parteConexa = []
                parteConexa.append(currentVertice)
                currentVertice = 0
                indiceParteConexa = 0
                while True:
                    #Verifica se Chegou no Fim das partes Conexas
                    if(indiceParteConexa >= len(parteConexa)):
                        break;
                    else:
                        #Se nao chegou ao fim verifica qual é o vertice corrente
                        currentVertice = parteConexa[indiceParteConexa]
            
                    #Adciona todas os vertices que se chega A partir de 'currentVertice'
                    for vertix, value in self.listaArestaAdjacente[currentVertice]:
                        #Se o vertice não estiver na lista o coloca
                        if(statusParteConexa[vertix] == False):
                            parteConexa.append(vertix);
                            statusParteConexa[vertix] = True
                        else:
                            #Se o vertice estiver na lista passa para o proximo
                            pass
                    #Verifica o proximo vertice
                    indiceParteConexa = indiceParteConexa + 1
                
                #Busca Profundidade na parte Conexa
                while (len(parteConexa) != 0):
                    #Atualiza o vertice Atual
                    currentVertice = parteConexa.pop()
                    parteConexa.append(currentVertice)
                    statusVertix[currentVertice] = self.__visiting
                    #Empilha todas arestas daquele Vertice
                    for vertix, value in self.listaArestaAdjacente[currentVertice]:
                        #Altera a Flag de não visitado para Visitando
                        if statusVertix[vertix] == self.__unvisited:
                            parteConexa.append(vertix)
                            #statusVertix[vertix] = self.__visiting;
                        else:
                            if(statusVertix[vertix] == self.__visiting):
                                #Tem loop
                                return "SIM"
                    if(currentVertice == parteConexa[-1]):
                        currentVertice = parteConexa.pop()
                        statusVertix[currentVertice] = self.__visited
        return "NAO";







        

numeroInstancias = int(input())
for instancia in range(numeroInstancias):
    G = Grafo()
    print(G.hasLoop())
print("")