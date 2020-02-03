# -*- coding: utf-8 -*-

print("Feito por Lucas Mateus Fernandes Baseado em https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/B-trees.html")
print("https://www.youtube.com/watch?v=6uYM5eG0XOg  ajuda a entender o conceito de chave e valor")
print("http://www.ic.unicamp.br/~zanoni/mo637/aulas/arvoresB.pdf")

class Page(object):
    """Estrutura No/Pagina"""
    def __init__(self, order, leaf):

        #É folha?
        self.__leaf = leaf;

        #Qual a ordem?
        self.__order = order;
        self.__fatorPreenchimento = 0;

        #Conjunto de chaves
        self.__key = [];
        for i in range(self.__order):
            self.__key.append(None);

        #Conjunto de valores/ponteiros
        self.__son = []#cada nó contém no máximo ordem−1 chaves,
        for i in range(self.__order):
            self.__son.append(None);

    def __str__(self):
        string = ""+str(self.isFull())+" "
        for i in range(self.__order):
            string = string +"("+ str(self.__key[i])+","+str(self.__son[i])+") "
        return string

    def occupation(self):
        return (self.__fatorPreenchimento, self.__order)

    def getValue(self, key):
        """Retorna o valor da chave 'key'"""
        #Se a Pagina é uma folha logo ela tem valor
        if self.isLeaf():
            #So é possivel retornar o valor caso a chave esteja presente na pagina
            if self.holds(key):
                #Se o valor esta presente é importante saber em qual posição
                index = self.__key.index(key)
                #Apos sencontrar o valor ele é retornado
                return self.value[index]
        return None

    def getKey(self, index):
        """Retorna o valor da chave 'key'"""
        #Se a Pagina é uma folha logo ela tem valor
        return self.__key[index]

    def getPage(self, index):
        """Retorna o filho de indice 'index' """
        #Certificasse que o index é um valor valido
        if index < self.__fatorPreenchimento:
            #Se a Pagina não é uma folha logo ela tem filhos
            if not self.isLeaf():
                return self.__son[index]
        return None

    def isLeaf(self):
        """Esta página é uma folha?"""
        return self.__leaf;
    
    def isEmpty(self):
        """A pagina esta vazia?"""
        if self.__fatorPreenchimento == 0:
            return True
        else:
            return False

    def isFull(self):
        """A pagina esta cheia de chaves"""
        if self.__fatorPreenchimento == self.__order:
            return True
        else:
            return False

    def	holds(self, key):
        """A chave 'key' está nesta página?"""
        return key in self.__key;

    def keyPathPage(self, key):
        """O indice com a chave key"""
        #Procura o melhor caminho
        indice = 0;
        #Pagina esta vazia
        if(self.isEmpty()):
            indice = -1
        #Menor Elemento
        elif( (self.__key[0] != None) and ( key < self.__key[0]) ):#Caso seja Menor que a menor ja presente na pagina
            indice = -1
        #Maior Elemento
        elif(self.__key[self.__fatorPreenchimento - 1] <= key):#Caso seja maior que a maior ja presente na pagina
            indice = self.__fatorPreenchimento - 1
        #Entre o primeiro e Ultimo
        else:#caso seja no meio entre o primeiro e o ultimo
            for i in range(self.__fatorPreenchimento):
                if((self.__key[i] != None) and (self.__key[i+1] != None)):
                    if((self.__key[i] <= key) and (key < self.__key[i+1])) :
                        indice = i 
                        break;
        return indice


    def remove(self, index):
        """remove a chave e o valor da pagina """
        #So da para remover da pagina atual caso a pagina não esteja vazia
        if not self.isEmpty():
            #So da para remover da pagina atual algo que esta na pagina atual
            if(index < self.__fatorPreenchimento):
                #Fator de preenchimento é decrescido
                self.__fatorPreenchimento = self.__fatorPreenchimento - 1
                #Remove a Chave 
                self.__key.remove(self.__key[index])
                self.__key.append(None)
                #Remove o valor/Filho
                self.__son.remove(self.__son[index])
                self.__son.append(None)


    def insert(self, key, value):
        """insere a chave e o 'valor' nesta página (externa)"""
        #So da para adicionar na pagina atual caso a pagina não esteja cheia
        if not self.isFull():
            #Escolhe o melhor local para add
            index = self.keyPathPage(key) + 1
            #Adiciona a Chave 
            self.__key.insert(index, key)#Add chave
            self.__key.pop()#Apaga o ultimo elemento que no caso é None

            #Adiciona o valor/Filho
            self.__son.insert(index, value)#Add Filho
            self.__son.pop()#Apaga o ultimo elemento que no caso é None

            #Fator de preenchimento é aumentado
            self.__fatorPreenchimento = self.__fatorPreenchimento + 1
            

    def insertMidle(self, key, son):
        """Insere a chave no meio da Arvore"""
        #So da para adicionar na pagina atual caso a pagina não esteja cheia
        if not self.isFull():
            #Descobre onde deveria ser adicionado:
            index = self.keyPathPage(key) + 1
            self.__key.insert(index, key)#Add chave
            self.__key.pop()#Apaga o ultimo elemento que no caso é None
            self.__son.insert(index, son)#Add Filho
            self.__son.pop()#Apaga o ultimo elemento que no caso é None
            #Fator de preenchimento é aumentado
            self.__fatorPreenchimento = self.__fatorPreenchimento + 1

       
class ArvoreB(object):
    """Definiçõs das características da Arvore"""
    def __init__(self, order = 4):
        self.__order = order;
        self.__root = Page(order, True)#Sempre a raiz começa sendo uma folha

    def __str__(self):
        return str(self.__root);

        #Variaveis para análise simulando que RAM disponível é 32 Mbytes e que cada bloco (página) contém 4 kbytes.

    def search(self, key, page = None):
        """Retorna a primeira pagina que contem a chave 'key' e o indice da chave dentro da pagina"""
        if page == None:
            page = self.__root

        index = 0
        fatorPreenchimento = page.occupation()[0]
        print("Ocupação =",fatorPreenchimento)
        #Encontra a primeira chave maior que a chave que esta sendo pesquisada
        while( (index < fatorPreenchimento) and (key > page.getKey(index)) ):
            index = index + 1
        #Verifica se a chave esta na pagina atual
        if (index <= fatorPreenchimento and key == page.getKey(index)):
            return (page, index)
        #Se chegou na folha e não encontrou é porque a chave não esta na arvore
        if page.isLeaf():
            return None
        #Caso não tenha chegado na folha aplica recursao
        else:
            return self.search_Original(key, page.getSon(index))
    
    def split(self, nodeHalf, index, nodeFull):
        """ OBS: nodeFull é filho direto de nodeHalf logo nodeFull não pode ser Leaf"""
        print("Quebrando SPLIT")
        #Cria um no auxiliar com as mesmas propriedades de nodeFull  
        newNode = Page(order = self.__order, leaf=nodeFull.isLeaf())

        #Transfere metade dos elementos de nodeFull para newNode
        for j in range(index, self.__order - 1):
            newNode.insert(nodeFull.getKey(j), nodeFull.getPage(j)) # Copia elemento de nodeFull para newNode
        for j in range(index, self.__order - 1):    
            nodeFull.remove(j)#Apaga de newNode o Elemento que foi copiado para nodeFull
        nodeHalf.insertMidle(newNode.getKey(index) , newNode)
        #Apaga os elementos que foram transferidos

    def insert(self, key, value, full = False , node = None):
        """Insere a chave e o valor na arvore"""
        if node == None:
            node = self.__root
            full = node.isFull()
        if full :
            print("FULL")
            root = self.__root
            if root.occupation()[0] == self.__order - 1:
                #Cria um Pai
                nodeFather = Page(order = self.__order, leaf=False)
                #o pai agora se torna a nova raiz
                self.__root = nodeFather
                nodeFather.insert(root.getKey(0), root)
                print("BREAK")
                self.split(nodeFather, int(self.__order/2 +1) , root)
                self.insert(nodeFather, key, value)
        else:
            print("Not FULL")
            if node.isLeaf():
               node.insert(key, value);
            else:
                index = node.keyPathPage()
                if node.isFull():
                    self.split(node, index, node.getSon(index))
                    if key > node.getKey(index):
                        index = index + 1
                    self.insert(key, value, full, node = node.getPage(index))

    def remove(self, chave):
        pass