# -*- coding: utf-8 -*-

#Autor:Lucas Mateus Fernandes
#Matricula: 0035411
#Data 21/11/2019
#E-mail:lucasmfpiu@gmail.com
#Git:1ldomal2

#Tad Grafo por lista de Adjacencia
class Grafo():

    def __str__(self):
        #como printar o Grafo
        msg = ""
        #msg = msg + "#Qtd vertices\n"
        msg = msg + str(self.qtdVertice) + "\n"
        #msg = msg + "#Qtd arestas\n"
        msg = msg + str(self.qtdAresta) + "\n"
        #msg = msg + "#(Origen, Destino, Valor)\n"
        for vertice in range(self.qtdVertice):
            for aresta in self.listaArestaAdjacente[vertice]:
                if aresta != []:
                    origen = str(vertice)
                    destino = str(aresta[0])
                    valor = str(aresta[1])
                    msg = msg + str(origen) + " " + str(destino) + " " + str(valor) + "\n"
        return msg;

    def sort(self):
        #Ordena as Arestas  para facilitar a visualização em alto nivel
        for vertice in range(self.qtdVertice):
            self.listaArestaAdjacente[vertice].sort()

    def  __init__(self, offset=0):
        #Variaveis essencias para um grafo
        self.qtdVertice = 0;
        self.qtdAresta = 0;
        self.listaArestaAdjacente = [];#Lista de Lista [Destino,Valor]
        self.listaArestaAdjacenteTransposta = []#Lista de Lista [Destino,Valor]
        self.agm = None
        self.direcional = True
        self.offset = offset
        self.unvisited = 0#Não Visitado
        self.visiting = 1#Vistando
        self.visited = 2#Visitado

    ################################################
    #           Representação do Grafo
    ################################################
    def listaTransposta(self, listaArestaAdjacente):
        """Cria lista Transposta de um grafo ja representado por lista de adjacencia"""
        listaArestaAdjacenteTransposta = []
        #Cria 'n' Vertices
        for i in range(0,self.qtdVertice):
            listaArestaAdjacenteTransposta.append(list())

        #Cria 'n' Arestas
        for vertice, vertices in enumerate(listaArestaAdjacente):
            for aresta in vertices:
                valorAresta = aresta[1]
                verticeOrigem = aresta[0]
                verticeDestino = vertice
                listaArestaAdjacenteTransposta[verticeOrigem].append([verticeDestino,valorAresta])

        self.listaArestaAdjacenteTransposta = listaArestaAdjacenteTransposta
        return listaArestaAdjacenteTransposta

    def listaAdjacencia(self, qtdVertice, arestas ,direcional = True):

        """Cria a representação do grafo por meio de uma lista de adjacencia"""
        self.direcional = direcional
        #Le cabeçalho
        self.qtdVertice = qtdVertice
        self.qtdAresta = len(arestas)
        listaArestaAdjacente = [];
        #Cria 'n' Vertices, ou seja 'n'' listas
        for i in range(0,qtdVertice):
            listaArestaAdjacente.append(list())
        #Cria 'n' Arestas
        for origen, destino, valor in arestas:
            self.inserirAresta(listaArestaAdjacente, origen, destino, valor)
            if(not direcional):
                self.inserirAresta(listaArestaAdjacente, destino, origen, valor)
        self.listaArestaAdjacente = listaArestaAdjacente
        return listaArestaAdjacente
       
    ################################################
    #           Manipulação de Arquivo
    ################################################
    def importarGrafo(self, nomeArquivo):
        arquivo = open(nomeArquivo, 'r');
        linhas = arquivo.readlines();
        #Le cabeçalho
        listaArestaAdjacente = [];
        qtdVertice = int(linhas[0]);
        qtdAresta = int(linhas[1]);
        #Cria 'n' Vertices
        #Cria uma lista com n Listas
        for i in range(0,qtdVertice):
            listaArestaAdjacente.append(list())
        #Cria 'n' Arestas
        for linha in linhas[2:]:
            dados = linha.split(' ')
            origen = int(dados[0])
            destino = int(dados[1])
            valor = float(dados[2])
            inserirAresta(listaArestaAdjacente,origen, destino, valor)
        #Fecha Arquivo
        arquivo.close();
        self.qtdVertice = qtdVertice
        self.qtdAresta = qtdAresta
        self.listaArestaAdjacente = listaArestaAdjacente

    def exportarGrafo(self, nomeArquivo):
        #Cria o Arquivo
        arquivo = open(nomeArquivo, 'w');
        self.sort();
        arquivo.write(str(self));
        arquivo.close();

    ################################################
    #           Manipulação de Aresta
    ################################################
    def inserirAresta(self, listaArestaAdjacente, verticeOrigem, verticeDestino, valorAresta = 1):
        listaArestaAdjacente[verticeOrigem - self.offset].append([verticeDestino-self.offset, valorAresta])

    def removerAresta(self, listaArestaAdjacente, verticeOrigem, verticeDestino, valorAresta = 1):
        for aresta in self.listaArestaAdjacente[verticeOrigem - self.offset]:
            try:
                listaArestaAdjacente.remove([verticeDestino-self.offset, valorAresta]);
                self.qtdAresta = self.qtdAresta - 1
            except:
                #Se der erro é porque a aresta não existia
                pass

    def arestaInGrafo(self, listaArestaAdjacente, verticeOrigem, verticeDestino, valorAresta = 1):
        arestaIn = False
        for aresta in self.listaArestaAdjacente[verticeOrigem - self.offset]:
            if(aresta[0] == verticeDestino and aresta[1] == valorAresta):
                arestaIn = True
                break
        return arestaIn
    
    def getArestas(self):
        """(origen,destino,valor)"""
        arestas = []
        for indexOrigen, linha in enumerate(self.listaArestaAdjacente):
            for destino, valor in linha:
                arestas.append( (indexOrigen+self.offset, destino+self.offset, valor) )
        return arestas

    ################################################
    #           Manipulação de Vertice
    ################################################
    def inserirVertice(self):
        self.listaArestaAdjacente.append(list())
        self.qtdVertice = self.qtdVertice+1
        
    def removerVertice(self, numeroVertice):
        pass

    ################################################
    #           Percorrer o Grafo
    ################################################
    def buscaProfundidade(self, verticeInicial):
        #Ajusta variavel
        verticeInicial = verticeInicial - self.offset   
        #Para evitar ciclos Cria um vetor onde informara se o vertice foi visitado ou não
        visitation = []
        for i in range(0,self.qtdVertice):
            visitation.append(self.unvisited);
        visitation[verticeInicial] = self.visiting;
        filo = [verticeInicial];

        #Enquanto A busca estiver ativa
        while (len(filo) != 0):
            #Desempilha
            currentVertice = filo.pop()
            #Empilha todas arestas daquele Vertice
            for vertix, value in self.listaArestaAdjacente[currentVertice]:
                if(visitation[vertix] == self.unvisited):#Se nunca foi visitado coloca na pilha de visitação
                    visitation[vertix] = self.visiting;#Seta como visitando
                    filo.append(vertix);#Adiciona a pilha
            #Seta o vertice como visitado
            visitation[currentVertice] = self.visited;
        return visitation;
    #Cria uma Agm

    def buscaLargura(self, verticeInicial):
        #Cria um vetor onde informara se o vertice foi visitado ou não
        statusVertix = []
        #Preparando terreno para evitar ciclos
        visitation = []
        for i in range(0,self.qtdVertice):
            statusVertix.append(self.unvisited);
        statusVertix[verticeInicial] = self.visiting;
        visitation.append(verticeInicial);

        #Enquanto A busca estiver ativa
        while (len(visitation) != 0):
            #Desenfileira
            currentVertice = visitation[0]
            visitation.remove(visitation[0])
            #Enfileira todas arestas daquele Vertice
            for vertix, value in self.listaArestaAdjacente[currentVertice]:
                if statusVertix[vertix] == self.unvisited:
                    statusVertix[vertix] = self.visiting;
                    visitation.append(vertix);
            statusVertix[currentVertice] = self.visited;
        return statusVertix;
    
    def grauDistancia(self, verticeInicial):
        verticeInicial = verticeInicial - self.offset
        anterior = [] #Quem é o vertice anterior ao vertice [ indice ]
        grau = [] #Grau de cada vertice [ indice ] ou seja o numero de arestas que tem que percorrer do vertice Inicial até chegar no vertice [ indice ]
        statusVertix = [] #Cria um vetor onde informara se o vertice foi visitado ou não

        #Preparando terreno para evitar ciclos
        visitation = [] #Lista de vertice a serem verificados
        for i in range(0,self.qtdVertice):
            statusVertix.append(self.unvisited);
            anterior.append(0)
            grau.append(0)
        statusVertix[verticeInicial] = self.visiting;
        visitation.append(verticeInicial);


        #Enquanto A busca largura estiver ativa
        while (len(visitation) != 0):
            #Desenfileira
            currentVertice = visitation[0]
            visitation.remove(visitation[0])
            #Enfileira todas arestas daquele Vertice
            for vertix, value in self.listaArestaAdjacente[currentVertice]:
                if statusVertix[vertix] == self.unvisited:
                    anterior[vertix] = currentVertice + self.offset #Para chegar em vertice[vertix] passa primeiro em vertice[currentVertice]
                    grau[vertix] = grau[currentVertice] + 1 #aumenta o grau do vertice
                    statusVertix[vertix] = self.visiting;
                    visitation.append(vertix);
            statusVertix[currentVertice] = self.visited;

        return [statusVertix,grau,anterior];

    def conexidade(self, verticeInicial):
        #Se necessário faz a lista transposta
        if(self.direcional == True and self.listaArestaAdjacenteTransposta == []):
            self.listaTransposta( self.listaArestaAdjacente)

        #Cria um vetor onde informara se o vertice foi visitado ou não
        statusVertix = []
        
        #Preparando terreno para evitar ciclos
        visitation = []
        for i in range(0,self.qtdVertice):
            statusVertix.append(self.unvisited);

        statusVertix[verticeInicial] = self.visiting;
        visitation.append(verticeInicial);

        #Faz A busca **** a partir do vertice inicial
        while (len(visitation) != 0):
            #Desenfileira
            currentVertice = visitation[0]
            visitation.remove(visitation[0])
            #Enfileira todas arestas daquele Vertice que não foram visitadas
            for vertix, value in self.listaArestaAdjacente[currentVertice]:
                if statusVertix[vertix] == self.unvisited:
                    statusVertix[vertix] = self.visiting;
                    visitation.append(vertix);
            statusVertix[currentVertice] = self.visited;
        
        #Caso o grafo não seja direcionado
        if(self.direcional == False):
            return (not self.unvisited in statusVertix)

        #Caso o grafo seja direcionado é preciso fazerr o mesmo processo no vertice transposto
        visitation.append(verticeInicial);
        #Faz A busca **** a partir do vertice inicial
        while (len(visitation) != 0):
            #Desenfileira
            currentVertice = visitation[0]
            visitation.remove(visitation[0])
            #Enfileira todas arestas daquele Vertice que não foram visitadas
            for vertix, value in self.listaArestaAdjacenteTransposta[currentVertice]:
                if statusVertix[vertix] == self.unvisited:
                    statusVertix[vertix] = self.visiting;
                    visitation.append(vertix);
            statusVertix[currentVertice] = self.visited;


        return (not self.unvisited in statusVertix)


    def connectivityBetween(grafo, v1, v2):
        #Cria um vetor onde informara se o vertice foi visitado ou não
        statusVertix = []
        visitation = []
        #Preparando para evitar ciclos
        for i in range(0,grafo.qtdVertice):
            statusVertix.append(grafo.unvisited);
        statusVertix[v1] = grafo.visiting;

        #Faz busca 
        visitation.append(v1);
        while (len(visitation) != 0):
            #Desempilha
            currentVertice = visitation.pop()
            if( currentVertice == v2):
                #V1 chega a V2
                return True
            #Empilha todas arestas daquele Vertice
            for vertix, value in grafo.listaArestaAdjacente[currentVertice]:
                if statusVertix[vertix] == grafo.unvisited:
                    statusVertix[vertix] = grafo.visiting;
                    visitation.append(vertix);
            statusVertix[currentVertice] = grafo.visited;
        #V1 não chega a V2
        return False;

    def Dijkstra(grafo, verticeOrigem):
        """        Caminho minimo partindo do verticeOrigem        """
        #Corrige indice
        verticeOrigem = verticeOrigem - grafo.offset
        def menorRelativo(vetor, numeroReferencia):
            """Verifica qual o proximo vertice a ser analisado"""
            def fMenor(valor):
                if(len(valor) > 0):
                    return valor[0][0]
                else:
                    return 999999999999

            #Cria uma copia para nao alterar os dados gerando uma inconsistencia
            listaAux = list(vetor)
            #Ordena o vetor
            listaAux.sort(key=lambda x : fMenor(x)) #Ordena a lista pelo primeiro indice da tupla porem se não tiver tupla o valor é 'infinito'
            #Pega o menor relativo
            celulaMenorRelativo = listaAux[numeroReferencia - 1][0]#( o 5º Passo pega o 5º Menor ou seja o 4º elemento em ordem crescente)
            return celulaMenorRelativo


        #Preparando a estrutura para dijkstra
        caminho = [] #É uma lista de tuplas sendo as tuplas compostas de (origem, custo, destino)  
        tabelaAux = [] #tabela aux é a simulação de uma matrix onde cada elemento é uma lista que pode estar vazia ou ter uma tupla sendo a tupla formado por (custo, origem) #Matrix tem as seguintes caracteristicas:(Linha = Numero do Passo    Coluna = Vertice de Destino)
        for i in range(grafo.qtdVertice + 1):
            tabelaAux.append([])
        for i in range(grafo.qtdVertice):
            tabelaAux[0].append([])

        #Iniciando Processamento Passo 0 ( Onde relata que o menor custo para chegar no vertice de origem é permanecer nele)
        tabelaAux[0][verticeOrigem] = [(0.0, verticeOrigem)] #Pois o menor custo para chegar no vertice de origem é permanecer nele
        caminho.append( (verticeOrigem, 0, verticeOrigem) ) #(Origem, Custo, Destino)  

        #Passo 1 adiante ( Onde relata qual o lugar mais barato que eu consigo chegar com 'n' passos)
        for nPasso in range(1, grafo.qtdVertice+1):
            #Ajusta Variaveis
            passoAnterior = nPasso - 1
            custoAtual = caminho[-1][1]# custoAtual é o custo até o ultimo vertice ja fechado/verificado
            verticeAtual = caminho[-1][2]# verticeAtual é o ultimo vertice fechado/verificado 
            tabelaAux[nPasso] = list(tabelaAux[passoAnterior])# Copia o passo Anterior

            #Calcula o custo de deslocamento de 1 unidade para cada vertice alcançavel partindo do ultimo vertice ja fechado
            for destino, custo in grafo.listaArestaAdjacente[verticeAtual]:
                menorCusto = custoAtual + custo
                if len(tabelaAux[nPasso][destino]) != 0: #Verifica se tem outra maneira de chegar ao vertice
                    if menorCusto < tabelaAux[nPasso][destino][0][0]: #Verifica se mesmo tendo outro caminho este é o menor
                        tabelaAux[nPasso][destino] = [(menorCusto, verticeAtual)]#Atualiza o menor custo
                    else:
                        #Se não tem outra maneira de chegar ao vertice Mantem o Custo
                        pass
                else:#Caso seja a primeira maneira encontrada para se alcançar o vertice
                    tabelaAux[nPasso][destino] = [(menorCusto, verticeAtual)]#atualiza o menor custo

            #Verifica qual o proximo vertice a ser analisado ( qual sera o proximo vertice de origem)
            celulaMenorRelativo = menorRelativo(tabelaAux[nPasso] , nPasso)
            origen = celulaMenorRelativo[1]
            custo = celulaMenorRelativo[0]
            destino = tabelaAux[nPasso].index([celulaMenorRelativo])

            #Fecha o vertice ou seja define que ele faz parte do menor caminho
            caminho.append( (origen, custo, destino) )

        #Corrigindo variavel de retorno
        retorno = []
        for origen, valor, destino in caminho[1:]:
            retorno.append( (origen + grafo.offset, float(valor), destino + grafo.offset) )
        return retorno

    def kruskal(self, preTree = None, minimum = True):
        """cria uma agm"""
        def listaAdjacenciaAGM(arestas):
            """Cria a representação do grafo por meio de uma lista de adjacencia"""
            agm = Grafo(self.offset)
            agm.direcional = self.direcional
            #por ser uma agm a quantidade de vertices é igual a quantidade de arestas +1
            agm.qtdAresta = len(arestas)
            agm.qtdVertice = self.qtdVertice
            #Cria uma lista com n Listas(Cria 'n' Vertices)
            for i in range(0,agm.qtdVertice):
                agm.listaArestaAdjacente.append(list())
            #Cria 'n' Arestas
            for origen, destino, valor in arestas:
                #Obrigatorio ter o offset pois usa a função inserir aresta
                agm.inserirAresta(agm.listaArestaAdjacente, origen, destino, valor)
                if(not agm.direcional):
                    agm.inserirAresta(agm.listaArestaAdjacente, destino, origen, valor)
            return agm
            
        def willHaveCycle(forest, edge):
            """Verifica se adicionar a aresta ocorrerá um cyclo"""
            #Ajusta Variaveis
            vertice1 = edge[0]
            vertice2 = edge[1]
            ciclo = False
            #Verifica se adicionas a aresta ocorrerá um ciclo
            for tree in forest:
                #Verifica se os 2 vertices ja estão em alguma arvore
                if( vertice1 in tree and vertice2 in tree):
                    ciclo = True
                    break
                else:
                    ciclo = False
            return ciclo

        def connectTrees(forest, edge):
            """Junta duas Arvores"""
            #Ajusta Variaveis
            vertice1 = edge[0]
            vertice2 = edge[1]
            foundV1 = foundV2 = False
            tree1 = tree2 = -1

            #Procura as duas arvores que serao mescladas
            for numberTree, tree in enumerate(forest):
                #Procura a arvore que possui vertice1
                if (not foundV1):
                    if(vertice1 in tree):
                        foundV1 = True
                        tree1 = numberTree
                #Procura a arvore que possui vertice2
                if (not foundV2):
                    if(vertice2 in tree):
                        foundV2 = True
                        tree2 = numberTree

            #Junta as duas arvores
            forest[tree1].extend(forest[tree2])
            forest.remove(forest[tree2])
            return forest

        # Ordena as arestas em ordem crescente
        arestaOut = []
        for origen, adjacentes in enumerate(self.listaArestaAdjacente):
            for destino, valor in adjacentes :
                arestaOut.append((origen + self.offset, destino + self.offset, valor))
        arestaOut.sort(key=lambda x: x[2]) # x[2] == Valor
        #inverte se necessário
        if(not minimum):
            arestaOut.reverse()

        #Cria uma floresta com 'n' arvores isoladas
        floresta = []
        for origen in range(0,self.qtdVertice):
            floresta.append( [origen + self.offset] )#Mais self.offset faz a correção do vertice começar no 0 ou no 1

        #Caso tenha uma arvore como base adiciona as 'n' arestas dela na nova arvore
        arestaInPreTree = []
        if(preTree != None):
            arestasPreTree = preTree.getArestas()
            #Adiciona N arestas do preGrafo na nova floresta 
            for aresta in arestasPreTree:#Perccore as n arestas 
                arestaInPreTree.append(aresta)
                #Atualiza a floresta pois houve a uniao de duas arvores
                floresta = connectTrees(floresta, aresta)
                
        #Adiciona N arestas na floresta até formar uma unica arvore
        arestaIn = []
        for aresta in arestaOut:#Perccore as n arestas 
            #Verifica se gera um ciclo 
            ciclo = willHaveCycle(floresta, aresta)
            #Se não gera um ciclo add a aresta e junta as arvores
            if(not ciclo):
                #Adiciona a aresta a AGM
                arestaIn.append(aresta)
                #Atualiza a floresta pois houve a uniao de duas arvores
                floresta = connectTrees(floresta, aresta)
        
        #Partes Conexas
        parteConexa = floresta
        
        #Mescla as arestas da preeTree junto com as da agm
        arestaIn.extend(arestaInPreTree)

        agm = listaAdjacenciaAGM(arestaIn)
        self.agm = agm
        return parteConexa

    def pathBetween(grafo, origen, destino):
        def __recursao(caminho, visitation, currentVertice, destino):
            #Evita ciclo
            visitation[currentVertice - grafo.offset] = grafo.visited
            
            #Cria uma  copia do dado para evitar inconsistencia
            caminho = list(caminho)
            caminho.append(currentVertice)

            #Caso base onde encontrou o Vertice de destino
            if currentVertice == destino:
                return caminho
                
            #Recursão one Não Encontrou o vertice de destino
            else:

                #Passa por todos os vizinhos
                for verticeAdjacente, valor in grafo.listaArestaAdjacente[currentVertice - grafo.offset]:
                    
                    #Olha vertices Adjacentes, caso o vertice não tenha sido verificado chama recursivamente
                    if(visitation[verticeAdjacente] == grafo.unvisited):

                        #chama recursivamente
                        caminho = __recursao(caminho, visitation, verticeAdjacente + grafo.offset, destino)
                        
                        #Verifica se o caminho chega até destino
                        if(caminho[-1] == destino):
                            
                            #Retorna caminho
                            return caminho

                return caminho[0:-1] #Caso não encontre remove o vertice

        #Preparando variaveis
        caminho = []
        visitation = []
        for vertice in range(grafo.qtdVertice):#Marca todos como não visitados
            visitation.append(grafo.unvisited)

        #Percorre recursivamente 
        caminho = __recursao(caminho, visitation, origen, destino)
        return caminho

    def pesoGrafo(grafo):
            valor = 0
            #Passa por todos os vertices
            for vertice in grafo.listaArestaAdjacente:
                for aresta in vertice:
                    valor = valor + aresta[1]
            #Se o grafo é não direcionado logo cada aresta aparece duas vezes 
            if(not grafo.direcional):
                return valor/2
            #Se é o grafo é direcionado logo cada aresta aparece uma vezes 
            else:
                return valor


def arredondar(x):
    #Caso base divisao por zero
    if(int(x) == 0):
        if( x > int(x)):
            return 1
        else:
            return 0

    #Arredonda para 'cima'
    x = x + (1 if x % int(x) else 0)
    return int(x)


#Entrada qtd de Cidades e carga da carroagem
cabecalho = input().split(" ")
qtdCidades = int(cabecalho[0])
cargaCarroagem = int(cabecalho[1])

#Entrada divida de cada cidade
dividas = input().split(" ")
for i in range(len(dividas)):
    dividas[i] = int(dividas[i])

#Entrada das vias
arestas = []
for i in range(len(dividas)-1):
    conexao = input().split(" ")
    origen = int(conexao[0])
    destino = int(conexao[1]) 
    custo = int(conexao[2])
    arestas.append( (origen, destino, custo) )

#Cria o Grafo com as arestas Adjacentes
direcional = False
grafo = Grafo(1)
grafo.listaAdjacencia(qtdCidades, arestas, direcional)

#define o grau de distancia das cidades até a capital
aux = grafo.grauDistancia(1)
statusVertix = aux[0] #Vertices visitados
grau = aux[1] #Grau de cada vertice
anterior = aux[2] #vertice anterior de cada vertice no caminho entre capital e vertice

#Ordena as cidades por grau de distancia
ordemGrau = []
for i in range(qtdCidades):
    ordemGrau.append( list() )
for i,g in enumerate(grau):
    ordemGrau[g].append( i + grafo.offset )

#Verifica o numero de passagens por cada cidade (começando pela mais distante da capital)
passagem = []
for i in range(qtdCidades):
    passagem.append(0) 
for grau in range(qtdCidades-1, -1, -1):

    #Verifica se existe cidade de grau i
    if(ordemGrau[grau] == list()):
        continue
    #Verifica se chegou a capital
    if(grau == 0):
        continue
    
    #Passa por Todas as cidades de Grau 'i'
    for cidade in ordemGrau[grau]:

        #Corrige o indice do vertice
        cidade = cidade - grafo.offset

        #Calcula o numero de viagens necessárias para transferir todo o dinheiro para cidade anterior
        passagem[cidade] = arredondar(dividas[cidade]/cargaCarroagem)

        #Transfere a divida da cidade para a cidade anterior
        dividas[anterior[cidade] - grafo.offset] = dividas[anterior[cidade] - grafo.offset] + dividas[cidade]
        dividas[cidade] = 0

#Calcula o custo total
custoTotal = 0
arestas = grafo.getArestas()
for origen, destino, valor in arestas:
    if(origen == anterior[destino - grafo.offset]):
        custoParcial = passagem[destino - grafo.offset] * valor * 2 # Vezes dois pois toda hroa que chega a um vertice tem que sair dele
        custoTotal = custoTotal + custoParcial
    

print(custoTotal)



