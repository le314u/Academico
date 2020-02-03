#-------------------------------------------------------------
#
#    Classe para tratar Automatos Finitos
#
#    Esqueleto para o trabalho pratico de 2019-sem2
#
#    2a versao:
#      - corrigidos pequenos bugs
#      - acrescentada prototipagem nos metodos da classe
#        .... funciona como se fosse comentario apenas
#      - corrigidos metodos: addTransition, isAFD
#      - acrescentados e renomeados metodos
#
#-------------------------------------------------------------

class Automata(object):
    pass

class Automata(object):
    def copy(self):
        newAf = Automata()
        newAf.__alfabeto = list(self.__alfabeto)
        newAf.__estados = dict(self.__estados)
        newAf.__finais = list(self.__finais)
        newAf.__iniciais = list(self.__iniciais)
        newAf.__fTransicao = dict(self.__fTransicao)
        newAf.__numEstados = self.__numEstados
        return newAf
    
    def UnionAlphabet(afd1: Automata, afd2: Automata)-> Automata:
        #Faz uma copia de newAfd
        newAfd = afd1.copy()

        #Faz a união dos alfabetos de afd1 e afd2
        for char in afd2.getAlphabet():
            newAfd.addAlphabet(char)

        return newAfd

    def list2State(self, listState):
        #Retira os itens Duplicados
        listState = set(listState)
        #Coloca em ordem Crescente
        listState = list(listState)
        listState.sort()
        #Converte em um nome valido
        strState = str(listState).strip("[]")
        return strState

    def state2List(self, strState):
        listState = []
        strState = str(strState)
        strState = strState.split(',')

        for s in strState:
            listState.append(int(s))
        return listState

    def multiplica(afd1: Automata, afd2: Automata) -> Automata:
        '''
        Monta automato com o produto de Estados do Afd1 com Afd2
        Simula a execução em paralelo
        '''

        #Cria uma copia dos Afd
        afd1 = afd1.copy()
        afd2 = afd2.copy()

        #Cria um novo AFD
        newAfd = Automata()
        
        #Faz a união dos alfabetos de afd1 e afd2
        newAfd = newAfd.UnionAlphabet(afd1)
        newAfd = newAfd.UnionAlphabet(afd2)
        
        #Adiciona Todos os caracteres à copia do afd's a fim de evitar erro durante a manipulação em paralelo
        for char in newAfd.getAlphabet():
            afd1.addAlphabet(char)
            afd2.addAlphabet(char)

        #Completa os afd's com estados de erro
        afd1 = afd1.completeErrorState()
        afd2 = afd2.completeErrorState()
        
        #Faz o produto dos estados de (afd1,afd2)
        estadoAfd1 = afd1.getStates()
        estadoAfd2 = afd2.getStates()
        for eAfd1 in estadoAfd1:
            for eAfd2 in estadoAfd2:
                newAfd.addState(str(eAfd1)+','+str(eAfd2))

        #Cria as Transições
        #Percorre Todas os estados
        for state in newAfd.getNameStates():
            tmp = state.split(',')
            eAfd1 = int(tmp[0])
            eAfd2 = int(tmp[1])
            #Percorre Todas as letras do Alfabeto
            for char in newAfd.getAlphabet():
                #Executa como se estivesse em paralelo
                eAfd1Next = str(afd1.moveAFD(eAfd1, char))
                eAfd2Next = str(afd2.moveAFD(eAfd2, char))
                #Adiciona uma transição
                source = newAfd.getStateByName(state)
                nameTarget = str(eAfd1Next) + "," + str(eAfd2Next)
                target = newAfd.getStateByName(nameTarget)
                newAfd.addTransition( source, char, target )
        return newAfd


    def stateEquivalent(afd: Automata) -> list:
        '''        Cria uma lista de estados equivalentes        '''
        def printaMatrix(matrix):
            '''            Debugar matrix            '''
            for linha in matrix:
                print(linha)
            print("\n\n")
            
        def debugMiniTransicao(s1, s2):
            '''            Debugar mini transição na matrix            '''
            #Cabecalho
            chars = list(afd.getAlphabet())
            chars.insert(0," ")

            #Cria o vetor
            v1 = []
            v2 = []
            for i in chars:
                v1.append(" ")
                v2.append(" ")
            v1[0] = str(s1)
            v2[0] = str(s2)

            #Preenche o vetor referente ao estado s1
            transition = afd.getTransitionsFrom(s1)
            for t in transition:
                indiceChar = chars.index(t[0])
                v1[indiceChar] = str(t[1][0])

            #Preenche o vetor referente ao estado s2
            transition = afd.getTransitionsFrom(s2)
            for t in transition:
                indiceChar = chars.index(t[0])
                v2[indiceChar] = str(t[1][0])
                
            #Printa
            print(chars)
            print(v1)
            print(v2)
            print("\n")
            pass

        def correctIndex(i, j):
            '''            Como é so meia matrix [i][j] == [j][i] portanto será analisado so quando i>j ,ou seja, apenas a parte inferior da matrix            '''
            if(i<j):
                return j,i
            return i,j

        def __matrixEquivalencia2List(matrix) -> list:
            '''            Transforma a matrix em uma  lista de conjuntos onde cada conjunto tem todos os estado equivalentes            '''
            listaEquivalencia = []
            estado1 = 0
            for i in matrix:
                estado1 = estado1 + 1
                estado2 = 0
                for j in i:
                    estado2 = estado2 + 1
                    if j != False:
                        addConjunto = True;
                        for conjunto in listaEquivalencia:
                            if(estado1 in conjunto):
                                conjunto.add(estado2);
                                addConjunto = False
                            if(estado2 in conjunto):
                                conjunto.add(estado1);
                                addConjunto = False
                        if addConjunto:
                            c = set()
                            c.add(estado1)
                            c.add(estado2)
                            listaEquivalencia.append(c)
            retorno = []
            for item in listaEquivalencia:
                retorno.append(list(item))
            return retorno

        def __reanaliseMatrix(matrix, stateI, stateJ):
            '''            Recursao para definir os estados codependentes como não Equivalentes            '''
            #Marca o estado como Falso e Todos os seus links codependentes
            indexI = stateI - 1 #Indice linha matrix 
            indexJ = stateJ - 1 #Indice coluna matrix
            #Index == (Estado -1)    Estado == (Index + 1)
            if matrix[indexI][indexJ] == False:
                #Caso Base
                pass
            else:
                estadosCodependentes = list(matrix[indexI][indexJ])
                matrix[indexI][indexJ] = False;
                for sI,sJ in estadosCodependentes:
                    #Nega todos os estados 'linkados'
                    __reanaliseMatrix(matrix, sI, sJ);
                    
        #Completa o afd com estado de Erro
        afd = afd.completeErrorState()

        #Pega todos os estados
        estados = afd.getStates()

        #Cria uma matriz ou seja uma lista de lista [Apenas Meia Matriz] para verificar a equivalencia
        """
        Configuração MAtrix
        2   []
        3   [] []
        4   [] []  []
        5   [] []  []  []
            1   2   3   4   
        """
        matrix = []
        for i in range( len( estados ) ):#Linhas
            matrix.append( [] );
            for j in range( i ):#colunas
                matrix[i].append( [] );

        #Diferencia Estados Finais de Não Finais
        estadosFinais = afd.getFinals()
        for indexI, stateI in enumerate(estados):
            for indexJ in range(indexI):
                stateJ = indexJ + 1
                #Sempre Um estado sera equivalente a ele mesmo (Tratamento diagonal principal)
                if stateI == stateJ:
                    continue 
                if (((not stateI in estadosFinais) and (stateJ in estadosFinais) ) or (( stateI in estadosFinais) and (not stateJ in estadosFinais) ) ):
                    matrix[indexI][indexJ] = False;         

        #Percorre So metade da Matriz
        #Percorre as Linhas
        for indexI in range(len(estados)):
            stateI = indexI + 1
            #Percorre as Colunas
            for indexJ in range(indexI):
                stateJ = indexJ + 1
    
                #Verifica se o estado ja foi marcado como não equivalente
                if matrix[indexI][indexJ] == False :
                    pass
                #Caso o estado ainda esteja impreciso
                else:
                    #Caso não tenha sido marcado verifica a equivalencia
                    #Para cada letra de transição verifica se os 2 novos estados são equivalentes
                    for char in afd.getAlphabet():
                        #Para cada letra do alfabeto verifica para onde o estado te leva
                        moveStateI = afd.moveAFD(stateI, char)
                        moveStateJ = afd.moveAFD(stateJ, char)
                        moveStateI, moveStateJ = correctIndex(moveStateI, moveStateJ)
                        #Um estado sempre é equivalente a ele mesmo
                        if(moveStateI == moveStateJ):
                            pass
                        else:
                            #Se os 2 novos estados ja estao marcados como não equivalente logo o estado que esta sendo analisado não é equivalente
                            if matrix[moveStateI-1][moveStateJ-1] == False:
                                __reanaliseMatrix(matrix, stateI, stateJ)
                                matrix[indexI][indexJ] = False
                                break;
                            #O par de estadosDestino recebe um link informando que se ele for Falso os link tbm devem ser marcados como falso
                            else:
                                matrix[moveStateI-1][moveStateJ-1].append((stateI, stateJ))
        return  __matrixEquivalencia2List(matrix)

    def completeErrorState(af :Automata) -> Automata:
        #Se ja estiver completo não faz nada
        if(af.isAFNComplete()):
            return af
        #Cria uma copia do Af
        af = af.copy()

        states = af.getStates()
        alphabet = af.getAlphabet()

        #Cria estado de erro
        erro = af.addState(name="erro")
        for c in alphabet:
            af.addTransition(erro, c, erro)

        #Verifica se Todos estados tem todas transiçoes
        for e in states:
            transicao = af.getTransitionsFrom(e)
            for char in alphabet:
                charInTransitions = False
                for c,s in transicao:
                    if c == char:
                        charInTransitions = True
                        break
                #Caso necessário adiciona transição para o estado de erro
                if not charInTransitions:
                    af.addTransition(e, char, erro)
        return af

    def minimize(afd: Automata) -> Automata:
        '''
        Retorna um Afd minimizado
        '''
        #Cria uma copia do afd
        afd = afd.copy()

        #Lista de equivalencias
        listaEquivalencia = afd.stateEquivalent()
        
        initials = afd.getInitials()
        finals = afd.getFinals()

        #Cria uma lista com todos os estados que tem equivalencia (conversao listaEquivalencia em um unico vetor)
        listaAux = []
        for states in listaEquivalencia:
            for state in states:
                listaAux.append(state)
        
        #Cria um novo afd para ser retornado
        newAfd = Automata()

        #Para cada conjunto de estado Equivalente adiciona um novo estado
        for sEquivalent in listaEquivalencia:
            newName = newAfd.list2State(sEquivalent)
            newAfd.addState(name=newName, initial=(sEquivalent[0] in initials), final=(sEquivalent[0] in finals))

        #Adiciona os estados que não são equivalentes
        states = afd.getStates()
        for state in states:
            #Não sera adicionado mais de um estado equivalente
            if state in listaAux:
                continue;
            #Adiciona o estado desde que ele não seja um estado equivalente
            else:
                newAfd.addState(name=state, initial=(state in initials), final=(state in finals))
        
        #Adiciona as Transições
        oldStatesPersistem = newAfd.getNameStates() #Nome de todos os novos estados equivalentes
        for nameState in oldStatesPersistem:
            newOrigin = newAfd.getStateByName(nameState)#numero do novo estado equivalente
            oldOrigin = afd.state2List(nameState)[0]#pega o numero de algum dos estados equivalentes (ambos levam para o mesmo lugar)
            transitions = afd.getTransitionsFrom(oldOrigin)#de todas as transições  que o antigo estado faz, este novo tbm fará
            #Percorre todas as transicoes do estado antigo
            for t in transitions:
                caracter = t[0]
                oldDestiny = t[1][0]
                newDestiny = newAfd.getStateByPartName(oldDestiny)
                newDestiny = newDestiny[0]
                #Cria a nova Transição
                newAfd.addTransition(newOrigin, caracter, newDestiny)
        
        #Seta quais estados são iniciais
        iniciais = newAfd.getStateByPartName(initials[0])
        inicial = iniciais[0]
        newAfd.setInitial(inicial)

        #Pega so a parte conexa do Af
        newAfdConexo = newAfd.parteConexa()
        return newAfdConexo

    def parteConexa(afd: Automata) -> Automata:
        newAfd = Automata()
        
        #Copia o Alfabeto de afd para newAfd
        alphabet = afd.getAlphabet()
        for char in alphabet:
            newAfd.addAlphabet(char)

        fifo = [newAfd.list2State(afd.getInitials())]
        checked = []
        newAfd.addState(name=str(fifo[0]), initial=True)
        #Partindo do ponto inicial verifica todos os estados alcançaveis e suas arestas
        while (len(fifo) != 0):

            current = int(fifo[0])
            #Evita Loop e garante a execução de todos os estados
            if current in checked:
                fifo = fifo[1:]
                continue

            #Saindo do estado atual verifica quais os estados atingiveis em um movimento
            transicoes = afd.getTransitionsFrom(current)
            for char,s in transicoes:
                state = str(s[0])
                fifo.append(state)#Adiciona o estado na fila para ser analisado

                #Cria o Estado caso não exista
                if not state in newAfd.getNameStates():
                    newAfd.addState(name=state)

                # Adiciona a Transição
                source = newAfd.getStateByName(str(current))
                target = newAfd.getStateByName(str(state))
                newAfd.addTransition(int(source), char, int(target))

            checked.append(current)
            #Garante que na proxima iteração analise um no Diferente
            fifo = fifo[1:]

        #Adiciona Estados Finais
        for nameState in newAfd.getNameStates():
           
            state = int(nameState)#Procura o Estado pelo nome ( pois o nome é estado que ele representava)
            #Verifica se o estado é um estado Final
            if state in afd.getFinals():
                newAfd.setFinal(nameState, final=True)
        return newAfd

    def union(afd1: Automata, afd2: Automata) -> Automata:
        #Inicial
        InicialAfd1 = afd1.getInitials()
        InicialAfd2 = afd2.getInitials()
        #Final
        FinalAfd1 = afd1.getFinals()
        FinalAfd2 = afd2.getFinals()
        #Afd a ser retornado
        newAfd = Automata.multiplica(afd1, afd2)
        states = newAfd.getNameStates()
        #Passa por todos os Estados
        for state in states:
            if(state == 'error'):
                continue
            tmp = state.split(',')
            stateAfd1 = int(tmp[0])
            stateAfd2 = int(tmp[1])
            #Verifica se é inicial
            if (stateAfd1 in InicialAfd1) and (stateAfd2 in InicialAfd2):
                newAfd.setInitial(state)
            #Verifica se é final
            if (stateAfd1 in FinalAfd1) or (stateAfd2 in FinalAfd2):
                newAfd.setFinal(state)
        return newAfd

    def intercession(afd1: Automata, afd2: Automata) -> Automata:
        #Inicial
        InicialAfd1 = afd1.getInitials()
        InicialAfd2 = afd2.getInitials()
        #Final
        FinalAfd1 = afd1.getFinals()
        FinalAfd2 = afd2.getFinals()
        #Afd a ser retornado
        newAfd = Automata.multiplica(afd1, afd2)
        states = newAfd.getNameStates()
        #Passa por todos os Estados
        for state in states:
            if(state == 'error'):
                continue
            tmp = state.split(',')
            stateAfd1 = int(tmp[0])
            stateAfd2 = int(tmp[1])
            #Verifica se é inicial
            if (stateAfd1 in InicialAfd1) and (stateAfd2 in InicialAfd2):
                newAfd.setInitial(state)
            #Verifica se é final
            if (stateAfd1 in FinalAfd1) and (stateAfd2 in FinalAfd2):
                newAfd.setFinal(state)
        return newAfd

    def diference(afd1: Automata, afd2: Automata) -> Automata:
        #Estados Iniciais
        InicialAfd1 = afd1.getInitials()
        InicialAfd2 = afd2.getInitials()

        #Estados Finais
        FinalAfd1 = afd1.getFinals()
        FinalAfd2 = afd2.getFinals()

        #Afd a ser retornado
        newAfd = Automata.multiplica(afd1, afd2)
        states = newAfd.getNameStates()

        #newAfd.parteConexa()

        #Passa por todos os Estados
        for state in states:
            if(state == 'error'):
                continue
            tmp = state.split(',')
            stateAfd1 = int(tmp[0])
            stateAfd2 = int(tmp[1])

            #Verifica se é inicial
            if (stateAfd1 in InicialAfd1) and (stateAfd2 in InicialAfd2):
                newAfd.setInitial(state)

            #Verifica se é final
            if (stateAfd1 in FinalAfd1) and (not (stateAfd2 in FinalAfd2)):
                newAfd.setFinal(state)
        return newAfd

    def inverter(afd1: Automata) -> Automata:
        
        #Afd a ser retornado
        newAfd = afd1.copy()
        states = newAfd.getNameStates()

        #Estados Finais
        FinalAfd1 = afd1.getFinals()

        #Passa por todos os Estados
        for indexState in range(1, len(states)+1):
            #Inverte a condição de estado final
            if (indexState in FinalAfd1):
                newAfd.setFinalIndex(indexState, final=False)
            else:
                newAfd.setFinalIndex(indexState, final=True)

        return newAfd

    def equivalence(afd1: Automata, afd2: Automata) -> Automata:
        '''
        Verifica se afd1 é equivalente a afd2
        '''
        def __copyTransition(newAfd:Automata ,afd:Automata ,prefixo)->Automata:
            '''
            Adiciona todas as transicoes do afd para newAfd
            '''
            #Cria uma copia do newAfd
            newAfd = newAfd.copy()
            
            #Adiciona as transicoes de afd para o newAfd
            for index,s in enumerate(afd.getNameStates()):#Percorre todos os estados de afd
                indexOrigenAfd = index+1#index de 's' dentro de afd
                for t in afd.getTransitionsFrom(indexOrigenAfd):#Percorre todas as transições a partir do estado 's'
                    nomeOrigenNewAfd = str(prefixo) + str(indexOrigenAfd)#Descobre o nome de 's' dentro de newAfd
                    indexOrigenNewAfd = newAfd.getStateByName(nomeOrigenNewAfd)#Descobre o index de 's' dentro de newAfd
                    indexDestinoNewAfd = newAfd.getStateByName( str(prefixo) + str(t[1][0]) )#Descobre o index do estado alvo (parada apos a transição)
                    newAfd.addTransition(indexOrigenNewAfd,t[0],indexDestinoNewAfd) #Adiciona a Transição a newAfd

            return newAfd

        def __copyStates(newAfd:Automata, afd:Automata, prefixo) -> Automata:
            '''
            Adiciona todos os estados de afd para newAfd
            '''
            #Cria uma copia de newAfd
            newAfd = newAfd.copy()

            #Passa por todos os estados de afd e adiciona a newAfd
            states = afd.getNameStates()#Conjunto com o nome dos estados de afd
            finishStates = afd.getFinals()#Conjunto com index dos estados finais em afd
            inicialOriginal = afd.getInitials()[0]#Como é afd é garantido que exista apenas 1 estado inicial caso contrário seria Afn

            #Passa por todos os estados de afd
            for state in range( len(states) ):
                final = ( (state + 1) in finishStates )#Verifica se o estado que esta sendo avaliado é um estado final
                nome = str(prefixo) + str(state + 1)#Seta o nome do novo estado de acordo com o prefixo e o index do estado em afd        (o +1 é necessário pois a contagem começa em 0 e os estados em 1)
                newAfd.addState( nome ,final=final)#Adiciona o novo estado mantendo a condição de ser final ou não
            
            #Adiciona uma transicao para o estado inicial do newAfd para o inicial de afd "dentro do newAfd"
            inicialAfd = str(prefixo) + str( inicialOriginal )#Nome do estado Incial de Afd2 dentro de newAfd
            destino = newAfd.getStateByName(inicialAfd)#Numero do estado Incial de Afd2 dentro de newAfd
            char = str(prefixo.split(',')[0]) #Caracter de controle "Ou seja o Afd não pode ter no alfabeto 1 e 2"
            newAfd.addTransition(inicialNewAfd, char , destino)

            return newAfd

        #Cria um novo Afd e adiciona o Estado inicial
        newAfd = Automata()
        inicialNewAfd = newAfd.addState(name="0" , initial=True)

        #Completa Afd1 e Afd2 com estados de erro e com o alfabeto
        afd1 = afd1.UnionAlphabet(afd2)#Completa Alfabeto afd1
        afd1 = afd1.completeErrorState()#Completa transicoes afd1
        afd2 = afd2.UnionAlphabet(afd1)#Completa Alfabeto afd2
        afd2 = afd2.completeErrorState()#Completa transicoes afd2

        #NewAfd tem o mesmo alphabeto que afd1 e afd2
        newAfd = newAfd.UnionAlphabet(afd1)
        newAfd = newAfd.UnionAlphabet(afd2)

        #Adiciona a NewAfd todos os estados de Afd1 e Afd2
        newAfd = __copyStates(newAfd, afd1, "1,")
        newAfd = __copyStates(newAfd, afd2, "2,")

        #Adiciona a NewAfd as transições de Afd1 e Afd2
        newAfd = __copyTransition(newAfd, afd1 ,"1,")
        newAfd = __copyTransition(newAfd, afd2 ,"2,")
       
        #Completa new afd com estado de erro
        newAfd = newAfd.completeErrorState()

        #Verifica se os estados Inicias de Afd1 e Afd2 são equivalentes pois se forem dali para frente , tudo é equivalente     
        statesEquivalentes = newAfd.stateEquivalent()#Pega Todos os Estados equivalentes em New Afd
        inicialNewAfd = newAfd.getInitials()[0]#New afd tem apenas um estado inicial caso contrario não seria afd
        transicoes = newAfd.getTransitionsFrom(inicialNewAfd)#O estado inicial de New Afd joga para os estados iniciais de afd1 e afd2
        inicial1 = transicoes[0][1][0]#indice do estado final de afd1 em newAfd
        inicial2 = transicoes[1][1][0]#indice do estado final de afd2 em newAfd

        #Verifica se os estados Inicias de Afd1 e Afd2 estão no mesmo conjunto de equivalencia   
        for listStates in statesEquivalentes:
            if(inicial1 in listStates and inicial2 in listStates):
                return True
        return False

    def convAFN2AFD(afn: Automata) -> Automata:
        afn = afn.completeErrorState()
        newAfd = Automata()#Automato que sera retornado
        fifo = list()#Estrutura de Dados que garante o funcionamento correto
        checked = []#Estrutura de Dados que evita repetição de Estados

        #Conjunto de Estados iniciais equivalente a um unico estado inicial
        initial = afn.getInitials() 
        strInitial = str(initial).strip("[]")
        newAfd.addState(name=strInitial, initial=True)

        #Add o primeiro estato a ser verificado (estado inicial)
        fifo.append(initial)
        #Passa por todos os Estados partindo do inicial
        while len(fifo) != 0:

            #Evita Loop e garante a execução de todos os estados
            states = fifo[0]
            if newAfd.list2State(states) in checked:
                fifo = fifo[1:]
                continue

            #Simula a transição com todos os caracteres apartir de "states"
            for char in afn.getAlphabet():
                listNextState = list()
                #Verifica todos os estados de destino saindo de "states" com "char"
                for current in states:
                    transicoes = afn.getTransitionsFrom(current)
                    for c,s in transicoes:
                        if c == char:
                            listNextState.extend(s)

                #Tratamento do nome dos estados equivalentes
                strNextState = newAfd.list2State(listNextState)
                listNextState = newAfd.state2List(strNextState)

                #Cria o Estado caso não exista
                if not strNextState in newAfd.getNameStates():
                    newAfd.addState(name=strNextState)

                #Adiciona a Transição com o caracter (char)
                source = newAfd.list2State(fifo[0])
                source = newAfd.getStateByName(source)
                target = newAfd.getStateByName(strNextState)
                newAfd.addTransition(source,char,target)

                #Adiciona um novo Estado na fila
                fifo.append(listNextState)
                checked.append(newAfd.list2State(fifo[0]))

            #Garante que na proxima iteração analise um no Diferente
            fifo = fifo[1:]
        #Adiciona Estados Finais
        finals = afn.getFinals()
        names = newAfd.getNameStates()
        #Passa por todos os estados
        for name in names:
            state = name.split(",")#Verifica se o estado tem algun estado Final
            for s in state:
                s = int(s)
                if s in  finals:
                    newAfd.setFinal(name)
                    break

        #retorna o novo Afd
        return newAfd            

    def convAFLambda2AFN(aflambda: Automata) -> Automata:
        #Cria um novo Af com os mesmo estados que o aflambda
        newAfN = Automata()
        nomes = aflambda.getNameStates()
        for nome in nomes:
            #Cria 'N' estados ou seja faz uma copia dos Estados de aflambda para newAfN
            newAfN.addState(name=nome)
        #Percorre Todos os estados
        for index, nome in enumerate(nomes):
            #Verifica todas as transicoes de cada Estado
            estado = index+1
            transicoes = aflambda.getTransitionsFrom(estado)
            for char, estados in transicoes:
                #Ignroa as transições Lambdas
                if(char == ''):
                    pass
                #Add as transiçoes indo para todos os estados gastando apenas 1 'char'
                else:
                    for s in estados:
                        semGastar = list(aflambda.getFechoLambda(s))
                        for destino in semGastar:
                            newAfN.addTransition(estado, char, destino)
        
        #Copia estados Inicias
        #Copia estados Finais
        newAfN.__finais = list(aflambda.__finais)
        newAfN.__iniciais = list(aflambda.__iniciais)

        return newAfN

    def convAFextended2AFN(afestendido: Automata) -> Automata:
        newAf = Automata()

        #Adiciona N Estados
        nomes = afestendido.getNameStates()
        for i in range(len(nomes)):
            newAf.addState()
        
        #Copia os Estados Iniciais
        initials = afestendido.getInitials()
        for s in initials:
            newAf.setInitialIndex(s)
        
        #Copia os Estados Finais
        finals = afestendido.getFinals()
        for s in finals:
            newAf.setFinalIndex(s)

        #Passa por todos os estados 
        for origen in range(1,len(nomes)+1):
            transitions = afestendido.getTransitionsFrom(origen)

            #Passa por todas as transiçoes de cada estado
            for t in transitions:
                destino = t[1]
                string = t[0]
                #TransiçãoVazia
                if(string == ''):
                    for d in destino:
                        newAf.addTransition(origen,str(string),d)
                #Sem Transição Vazia
                else:
                    #passa por todos caracteres da transicao
                    ultimoEstado = origen
                    for i,c in enumerate(string):

                        #Verifica se é o ultimo caracter da string
                        if(i+1 == len(string)):
                            for d in destino:
                                newAf.addTransition(ultimoEstado,c,d)
                                
                        #Caso não seja o ultimo caracter da string
                        else:
                            proximoEstado = newAf.addState()
                            newAf.addTransition(ultimoEstado,c,proximoEstado)
                            ultimoEstado = proximoEstado

        return newAf

    def convER2AFN(expressao: str) -> Automata:
        pass

    def convAFD2ER(afd: Automata) -> str:

        def prettyER(ER):
            return ER.replace("()","")


        def joinListER(lista, loop=False):
            '''
            Cria a Er com todas as palavras da lista
            '''
            if(lista == []):
                return ''

            #String
            newStr = "("
            for palavra in lista:
                aux = str(palavra)
                newStr = newStr + aux + "|"
            newStr = newStr[:-1]
            newStr = newStr + ")"

            #loop
            if loop:
                newStr = newStr + "*"
                    
            return newStr

        def retiraVertice(afd, vertice):
            '''
            Retira um vertice e cria as 'ER' que dependem daquele vertice
            '''
            #Verifica quem chega até o vertice
            antecessores = afd.antecessores(vertice)

            #Verifica para onde o vertice vai
            sucessores = afd.getTransitionsFrom(vertice)
 
            #Cria as 'ER' que dependem do vertice removido
            
            #Identifica Loops
            loops = []
            for palavra, destino in sucessores:#Passa por todas transiçoes
                for d in destino:#Passa por todos os vertice de destido de cada transição
                    if ( d == vertice):# verifica se sucessor == antecessor logo tem loop
                        loops.append(palavra)
            loop = joinListER(loops , loop=True)

            for origen in antecessores:
                if(vertice == origen): #Tratamento do loop
                    continue
                Er = ""

                #Prefixo
                auxString = afd.StringEdge(origen, vertice)
                prefixo = joinListER(auxString, loop=False)
                Er = Er + prefixo
                
                #Loop
                Er = Er + loop
                
                #Sufixo
                for palavra, destinos in sucessores:
                    #Sufixo
                    for destino in destinos:#Passa por todos os vertices de destino
                        auxString = afd.StringEdge(vertice,destino)
                        sufixo = joinListER(auxString, loop=False)
                        ErFinal = prettyER(Er + sufixo)
                        if(vertice == destino): #Tratamento do loop
                            continue
                        
                        #Add Transição
                        afd.addTransition(origen, ErFinal, destino)

            #remove as transições que envolvem 'vertice'
            for palavra, destino in sucessores:#Que saem de vertice
                afd.__fTransicao.pop( (vertice, palavra) )
            for v in antecessores: #Que chegam em vertice
                transicoes = afd.getTransitionsFrom(v)
                for palavra, destino in transicoes:
                    if(vertice in destino):
                        afd.__fTransicao.pop( (v, palavra) )

            #remove o vertice
            afd.__estados.pop(vertice)

            return afd


        #Cria uma copia de segurança do afd
        newAfd = afd.copy()

        #Cria uma copia dos estados iniciais e Finals
        initial = list( newAfd.getInitials() )
        finals = list( newAfd.getFinals() )
        totalState = newAfd.__numEstados

        #Reseta os estados iniciais e Finais do newAfd
        newAfd.__iniciais = []
        newAfd.__finais = []


        #Cria novo Estados Iniciais
        newInitial = newAfd.addState(name="Init",initial=True)
        for i in initial:
            newAfd.addTransition(newInitial,'',i)

        #Cria novo Estados Finais
        newFinal = newAfd.addState(name="Finish",final=True)
        for f in finals:
            newAfd.addTransition(f,'',newFinal)

        #Passa por todos os estados
        for state in range(1,totalState+1):
            newAfd = retiraVertice(newAfd, state)
        
        #pega a ER
        lista = []
        transicoes = newAfd.getTransitionsFrom(newInitial)
        for palavra, destinos in transicoes:
            if(newFinal in destinos):
                lista.append(palavra)
        ER = joinListER(lista, False)
        ER = prettyER(ER)
        return ER

        
 

    #--------------------------
    #   classe
    #--------------------------

    def __init__(self):
        self.__numEstados = 0

        # --- elementos da quintupla
        self.__estados = dict()     # { E : A*, ... }
        self.__alfabeto = list()    # [ A, ... ]
        self.__fTransicao = dict()  # { (E, A*) : E+, ... }
        self.__iniciais = list()    # [ E, ... ]
        self.__finais = list()      # [ E, ... ]

    def __getNew(self):
        self.__numEstados = self.__numEstados + 1
        return self.__numEstados

    def addState(self, name='', initial=False, final=False):
        name = str(name)
        novo = self.__getNew()
        self.__estados[novo] = name
        if initial:
            self.__iniciais.append(novo)
        if final:
            self.__finais.append(novo)
        return novo

    def addTransition(self, origem, palavra, destino):
        if not origem in self.__estados or not destino in self.__estados:
            self.__erro('addTransition')
        for c in palavra:
            if not c in self.__alfabeto:
                self.__alfabeto.append(c)
        if (origem, palavra) in self.__fTransicao:
            aux = self.__fTransicao[(origem, palavra)]
        else:
            aux = [ ]
        if not destino in aux:
            self.__fTransicao[(origem, palavra)] = aux + [destino]

    def getInitials(self):
        return self.__iniciais

    def getFinals(self):
        return self.__finais

    def getStates(self):
        return self.__estados.keys()
    
    def setFinal(self, state, final = True):
        #State = Name State
        index = self.getNameStates().index(state)
        #Verifica se o estado é valido
        if index != -1:
            chaves = list(self.getStates())
            state = int(chaves[index])
            #Add
            if final:
                if not state in self.__finais:
                    self.__finais.append(state)
                    self.__finais.sort()
            #Remove
            else:
                if state in self.__finais:
                    self.__finais.remove(state)

    def setFinalIndex(self, index, final = True):
        #Verifica se o index é valido
        if(index >= 1 and index <= self.__numEstados):
            state = index
            #Add
            if final:
                if not state in self.__finais:
                    self.__finais.append(state)
                    self.__finais.sort()
            #Remove
            else:
                if state in self.__finais:
                    self.__finais.remove(state)

    def setInitial(self, state, initial = True):
        index = self.getStateByName(state)
        #Verifica se o estado é valido
        if index != 0:
            chaves = list(self.getStates())
            state = index
            #Add
            if initial:
                if not state in self.__iniciais:
                    self.__iniciais.append(state)
                    self.__iniciais.sort()
            #Remove
            else:
                if state in self.__iniciais:
                    self.__iniciais.remove(state)

    def setInitialIndex(self, index, initial = True):
        #Verifica se o index é valido
        if(index >= 1 and index <= self.__numEstados):
            chaves = list(self.getStates())
            state = index
            #Add
            if initial:
                if not state in self.__iniciais:
                    self.__iniciais.append(state)
                    self.__iniciais.sort()
            #Remove
            else:
                if state in self.__iniciais:
                    self.__iniciais.remove(state)

    def getNameState(self, state):
        return self.__estados[state]
    
    def getNameStates(self):
        return list(self.__estados.values())

    def getStateByName(self, name):
        states = self.getNameStates()
        try:
            return states.index(name) + 1
        except:
            return 0

    def getStateByPartName(self, name):
        states = self.getNameStates()
        listMatch = []
        #Converte a string em uma lista
        for index, state in enumerate(states):
            listState = self.state2List(state)
            for s in listState:
                if int(s) == int(name):
                    listMatch.append(index + 1)
                    break
        return listMatch

    def getAlphabet(self):
        return self.__alfabeto
    
    def addAlphabet(self, char):
        if char not in self.__alfabeto:
            self.__alfabeto.append(char)

    def getTransitionsFrom(self, estado):
        resp = list()
        for (e,s) in self.__fTransicao:
            if e == estado:
                resp.append((s, self.__fTransicao[(e, s)]))
        return resp

    def __erro(self, msg):
        print('ERRO: %s' % msg)
        quit()

       # estado;
    # ------------------------------------------

    def StringEdge(afd, origen, destino):
        '''
        Retorna uma lista com as string's das transiçoes (origen,destino)
        '''
        origen = int(origen)
        destino = int(destino)
        listString = []
        for palavra, d in afd.getTransitionsFrom(origen):
            if destino in d:
                listString.append(palavra)
        return listString

    def antecessores(self,state):
        antecessores = []
        #Passa por todos os estados
        for stateOrigen in range(1,self.__numEstados+1):
            transitions = self.getTransitionsFrom(stateOrigen)
            for string,destino in transitions:
                if state in destino:
                    antecessores.append(stateOrigen)
        return antecessores


    def getFechoLambda(self, estado, verificados = None) -> set:
        '''
        Retorna um conjunto com fecho de todos os estados que se pode parar ao andar lambda
        '''
        #Arrumando parametros
        if(verificados == None):
            verificados = set()

        #sempre é possivel permanecer no mesmo estado sem gastar nada
        transicaoLambda = set()
        transicaoLambda.add(estado)
        verificados.add(estado)
        #Verifica se no afd 'self' tem transicao 'lambda'
        conjuntoEstados = [] 
        try:
            #Tem transição lambda
            conjuntoEstados = list(self.__fTransicao[(estado, '')])
        except:
            pass

        #Para cada estado que se pode ir sem gastar nada verifica recursivamente para onde pode ir sem gastar nada
        for e in conjuntoEstados:
            #Evitar loop infinito
            if(not e in verificados):
                transicaoLambda = transicaoLambda.union( self.getFechoLambda(e,verificados) )
                
        #Retorna o conjunto
        return set(transicaoLambda);

    def moveAFD(self, estado, palavra):
        '''
        Verifica em qual estado irá parar apos processar uma palavra a partir do 'estado'
        '''
        if not self.isAFD():
            self.__erro('moveAFD')
        e = estado
        for a in palavra:
            if not (e, a) in self.__fTransicao:
                return None
            lista = self.__fTransicao[(e, a)]
            e = lista[0]
        return e

    def accept(self, palavra):
        '''
        Verifica se a palavra é aceita pelo AF
        '''
        if not self.isAFD():
            self.__erro('accept')
        e = self.moveAFD(self.__iniciais[0], palavra)
        if e is None:
            return False
        else:
            return e in self.__finais

    def isAFD(self):
        '''
        Verifica se é um AFD ou seja:
        Tem apenas um estado inicial
        A partir de um estado de origem ao ler um caractere pode ir apenas para um estado de destino
        '''
        if len(self.__iniciais) > 1:
            return False
        for e in self.getStates():
            for (s, destino) in self.getTransitionsFrom(e):
                if len(s) != 1 or len(destino) != 1:
                    return False
        return True

    def hasLambda(self):
        '''
        Verifica se algum estado tem transição lambda ou seja é um AFN-Lambda
        '''
        for (e,s) in self.__fTransicao:
            if s == '':
                return True
        return False

    def isAFDComplete(self):
        '''
        Verifica se é um AFD completo ou seja tem todos os estados de erro
        '''
        if not self.isAFD():
            return False
        for e in self.getStates():
            for s in self.getAlphabet():
                if not (e,s) in self.__fTransicao:
                    return False
        return True

    def isAFNComplete(self):
        '''
        Verifica se é um AFN completo ou seja tem todos os estados de erro
        '''
        for e in self.getStates():
            for s in self.getAlphabet():
                if not (e,s) in self.__fTransicao:
                    return False
        return True


    def __str__(self):
        '''
        Para printar
        '''
        msg = '(E, A, ft, I, F) onde:\n' +\
              '  E  = {0}\n' +\
              '  A  = {1}\n' +\
              '  I  = {3}\n' +\
              '  F  = {4}\n' +\
              '  ft = {2}'
        ft = '{\n'
        for (e,a) in self.__fTransicao:
            t = self.__fTransicao[(e, a)]
            ft = '{0}    ({1}, {2}): {3},\n'.format(ft, e, a, t)
        ft = ft + '  }'
        return msg.format(self.__estados, \
                          self.__alfabeto, ft, \
                          self.__iniciais, self.__finais)

