#Autor:Lucas Mateus Fernandes
#E-mail:lucasmfpiu@gmail.com
#Git:1ldomal2

#Tad Grafo por lista de Adjacencia
class Grafo():
    #Constantes
    __unvisited = 0#Não Visitado
    __visiting = 1#Vistando
    __visited = 2#Visitado

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
        for vertice, vertices in enum(listaArestaAdjacente):
            for aresta in vertices:
                valorAresta = aresta[1]
                verticeOrigem = aresta[0]
                verticeDestino = vertice
                listaArestaAdjacenteTransposta[verticeOrigem].append([verticeDestino,valorAresta])
        return listaTransposta

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
            visitation.append(self.__unvisited);
        visitation[verticeInicial] = self.__visiting;
        filo = [verticeInicial];

        #Enquanto A busca estiver ativa
        while (len(filo) != 0):
            #Desempilha
            currentVertice = filo.pop()
            #Empilha todas arestas daquele Vertice
            for vertix, value in self.listaArestaAdjacente[currentVertice]:
                if(visitation[vertix] == self.__unvisited):#Se nunca foi visitado coloca na pilha de visitação
                    visitation[vertix] = self.__visiting;#Seta como visitando
                    filo.append(vertix);#Adiciona a pilha
            #Seta o vertice como visitado
            visitation[currentVertice] = self.__visited;
        return visitation;
    #Cria uma Agm

    def buscaLargura(self, verticeInicial):
        #Cria um vetor onde informara se o vertice foi visitado ou não
        statusVertix = []
        #Preparando terreno para evitar ciclos
        for i in range(0,self.qtdVertice):
            statusVertix.append(__unvisited);
        statusVertix[verticeInicial] = __visiting;
        visitation.append(verticeInicial);

        #Enquanto A busca estiver ativa
        while (len(visitation) != 0):
            #Desenfileira
            currentVertice = visitation[0]
            visitation.remove(visitation[0])
            #Enfileira todas arestas daquele Vertice
            for vertix, value in self.listaArestaAdjacente[currentVertice]:
                if statusVertix[vertix] == __unvisited:
                    statusVertix[vertix] = __visiting;
                    visitation.append(vertix);
            statusVertix[currentVertice] = __visited;
        return statusVertix;

        def connectivityBetween(grafo, v1, v2):
            #Cria um vetor onde informara se o vertice foi visitado ou não
            statusVertix = []

            #Preparando para evitar ciclos
            for i in range(0,grafo.qtdVertice):
                statusVertix.append(__unvisited);
            statusVertix[v1] = __visiting;

            #Faz busca estiver ativa
            visitation.append(v1);
            while (len(visitation) != 0):
                #Desempilha
                currentVertice = visitation.pop()
                if( currentVertice == v2):
                    #V1 chega a V2
                    return True
                #Empilha todas arestas daquele Vertice
                for vertix, value in grafo.listaArestaAdjacente[currentVertice]:
                    if statusVertix[vertix] == __unvisited:
                        statusVertix[vertix] = __visiting;
                        visitation.append(vertix);
                statusVertix[currentVertice] = __visited;
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
            visitation[currentVertice - grafo.offset] = grafo.__visited
            
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
                    if(visitation[verticeAdjacente] == grafo.__unvisited):

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
            visitation.append(grafo.__unvisited)

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





while(True):
    #Entrada
    direcional = False
    cabecalho = input().split(' ')
    C = int(cabecalho[0]) #Cidades
    E = int(cabecalho[1]) #Estradas
    #Condição de parada
    if(C==0 and E==0):
        break
    arestas = []
    for i in range(E):
        aresta = input().split(' ')
        c1 = int(aresta[0]) #cidade de origem
        c2 = int(aresta[1]) #idade de destino
        t = int(aresta[2]) #tempo medio
        arestas.append( (c1,c2,t) )
    D = int(input()) #Cidade de origem onde o individuo está


    #Monta o Grafo
    grafo = Grafo(1)
    grafo.listaAdjacencia(C, arestas, direcional)

    #Aplcia Dijkstra para calcular o menor caminho
    menorPercurso = grafo.Dijkstra(D)
    tempoGasto = 0
    cidades = []
    arestas = []
    for origen, valor, destino in menorPercurso:
        arestas.append((origen,destino,valor))
        if(destino == 1):
            tempoGasto = int(valor)
            cidades.append(destino)
            break
    #Cria um grafo apenas com o menor caminho
    g = Grafo(1)
    g.listaAdjacencia(C, arestas, direcional)
    cidades = g.pathBetween(D,1)
    string = ""
    for c in cidades :
        string = string + str(c) + " "

    if(not tempoGasto > 120):
        print("Will not be late. Travel time -",tempoGasto,"- best way -", string[:-1])
    else:
        print("It will be",tempoGasto-120,"minutes late. Travel time -",tempoGasto,"- best way -",string[:-1])