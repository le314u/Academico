class Tree:
    def __init__(self):
        self.RubroNegra = RubroNegra()
    
    def __getitem__(self, key):
        key = str(key)
        return self.RubroNegra.procuraKey(key)

    def __str__(self):
        #intera a arvore em in ordem
        tree = ""
        for no in self.inordem():
            try:
                tree = tree + str(no)+"\n"
            except:
                pass
        return tree[0:-1]

    def __setitem__(self, key, value):
        #Converte a entrada para string
        key = str(key)
        if value != None:
            try:#Atualiza o conteudo de um no
                self[key].dado = value
            except:#Adiciona um no na arvore
                self.insert(key, value)
        else:
            #remove um no da arvore
            self.remove(key)

    def __iter__(self):
        return self.inordem()

    def insert(self, key, value):
        self.RubroNegra.inserir(key, value)
    
    def remove(self, key):
        self.RubroNegra.remove_no(key)

    def preordem(self):
        return self.RubroNegra.preordem()

    def inordem(self):
        return self.RubroNegra.inordem()

    def posordem(self):
        return self.RubroNegra.posordem()


# DEFINE Tabela de COR
color = {
    "red": 1,
    "black": 0
}


# Strutura de dados que representa um nó dentro da arvore rubro negra
class No:
    def __init__(self, chave, dado):
        self.chave = chave  # Identificador do nó
        self.dado = dado  # Conteudo do nó
        self.pai = None  # Ponteiro para o nó pai
        self.esquerda = None  # Ponteiro para o nó da esquerda
        self.direita = None  # Ponteiro para o nó da direita
        self.cor = color['red']

    def __str__(self):
        return "{'chave':"+self.chave + ",\t'dado':"+self.dado+"}"

    def vo(self):
        return self.pai.pai


# class RedBlackTree implements the operations in Red Black Tree
class RubroNegra:
    def __init__(self):
        self.arvoreVazia = No("0", None)
        self.arvoreVazia.cor = color['black']
        self.arvoreVazia.esquerda = None
        self.arvoreVazia.direita = None
        self.raiz = self.arvoreVazia
        
    def inserir_novoNo(self, chave, dado):
        # Inserção Binaria Simples
        no = No(chave, dado)
        no.pai = None
        # Começa com self.arvoreVazia pois facilida ao percorrer a arvore
        no.esquerda = self.arvoreVazia
        no.direita = self.arvoreVazia
        # novos nós são sempre vermelhos
        no.cor = color['red']
        return no

    def goToInsert_inserir(self, no):
        # Caminha até o local de inserção
        vo = None
        pai = self.raiz
        while pai != self.arvoreVazia:
            vo = pai
            if no.chave < pai.chave:
                pai = pai.esquerda
            else:
                pai = pai.direita
        return [pai, vo]

    def append_inserir(self, no, pai, vo):
        # Linka o no ná arvore
        no.pai = vo
        if vo == None:
            self.raiz = no
        elif no.chave < vo.chave:
            vo.esquerda = no
        else:
            vo.direita = no
        return [no, pai, vo]

    # Insere a chave em sua posição apropriada e faz os devidos ajustes
    def inserir(self, chave, dado):
        # Cria um no a ser inserido
        no = self.inserir_novoNo(chave, dado)

        # Caminha até o local de inserção
        pai, vo = self.goToInsert_inserir(no)

        # Linka o no ná arvore
        no, pai, vo = self.append_inserir(no, pai, vo)

        # Caso base 1 (Primeiro no da arvore)
        if no.pai == None:
            no.cor = color['black']
            return

        # Caso base 2 (No na segundo nível da arvore)
        if no.pai.pai == None:
            return

        # Rotaciona se necessário
        self.__fix_insert(no)

    # fix the red-black tree
    def __fix_insert(self, no):
        # Trocando a cor
        while no.pai.cor == color['red']:
            # Define o tio
            if no.pai == no.pai.pai.direita:
                tio = no.pai.pai.esquerda
                # Colore
                if tio.cor == color['red']:
                    tio.cor = color['black']
                    no.pai.cor = color['black']
                    no.pai.pai.cor = color['red']
                    no = no.pai.pai
                else:  # Colore e rotaciona
                    if no == no.pai.esquerda:
                        no = no.pai
                        self.rotaciona_direita(no)
                    no.pai.cor = color['black']
                    no.pai.pai.cor = color['red']
                    self.rotaciona_esquerda(no.pai.pai)
            else:  # Define o tio
                tio = no.pai.pai.direita
                # Colore
                if tio.cor == color['red']:
                    tio.cor = color['black']
                    no.pai.cor = color['black']
                    no.pai.pai.cor = color['red']
                    no = no.pai.pai
                else:  # Colore e rotaciona
                    if no == no.pai.direita:
                        no = no.pai
                        self.rotaciona_esquerda(no)
                    no.pai.cor = color['black']
                    no.pai.pai.cor = color['red']
                    self.rotaciona_direita(no.pai.pai)
            if no == self.raiz:
                break
        self.raiz.cor = color['black']

    # rotate esquerda at no x
    def rotaciona_esquerda(self, x):
        y = x.direita
        x.direita = y.esquerda
        if y.esquerda != self.raiz:
            y.esquerda.pai = x
        y.pai = x.pai
        if x.pai == None:
            self.raiz = y
        elif x == x.pai.esquerda:
            x.pai.esquerda = y
        else:
            x.pai.direita = y
        y.esquerda = x
        x.pai = y

    # rotate direita at no x
    def rotaciona_direita(self, x):
        y = x.esquerda
        x.esquerda = y.direita
        if y.direita != self.raiz:
            y.direita.pai = x
        y.pai = x.pai
        if x.pai == None:
            self.raiz = y
        elif x == x.pai.direita:
            x.pai.direita = y
        else:
            x.pai.esquerda = y
        y.direita = x
        x.pai = y

    # remove um no da arvore
    def remove_no(self, chave):
        self.__remove_no_helper(self.raiz, chave)

    def __remove_no_helper(self, no, key):
        #Percorre a arvore até encontrar o no com a chave  
        z = self.arvoreVazia #Representa o no a ser removido
        while no != self.arvoreVazia:
            if no.chave == key:
                z = no
            if no.chave <= key:
                no = no.direita
            else:
                no = no.esquerda

        #Caso o nó não esteja presente na arvore apenas encerra a função
        if z == self.arvoreVazia:
            return
        
        y = z
        y_original_cor = y.cor #Guarda a cor do no
        # Caso não haja no menor a partir de no
        if z.esquerda == self.arvoreVazia: 
            x = z.direita
            self.__rb_transplant(z, z.direita)
        # Caso não haja no maior a partir de no
        elif (z.direita == self.arvoreVazia):
            x = z.esquerda
            self.__rb_transplant(z, z.esquerda)
        # Caso haja no maior e menor
        else:
            y = self.minimum(z.direita)#Verifica qual o menor no que seja maior que o no especificado
            y_original_cor = y.cor # salva a cor do no
            x = y.direita # recebe o filho da direita (um no com a chave maior)
            if y.pai == z: #Verifica se numero maior mais proximo do "no" esta um nivel abaixo
                x.pai = y 
            else:
                #Reajusta "y" da arvore
                self.__rb_transplant(y, y.direita)
                y.direita = z.direita
                y.direita.pai = y
            #Reajusta "z" na arvore
            self.__rb_transplant(z, y)
            y.esquerda = z.esquerda
            y.esquerda.pai = y
            #Recolore 
            y.cor = z.cor
        if y_original_cor == color['black']:
            self.__fix_delete(x)

    #Remove um no da arvore e reajusta
    def __rb_transplant(self, no, filho):
        #Verifica se o no especificado não possui um pai
        if no.pai == None:
            self.raiz = filho
        #Verifica se no é menor ou maior que o pai
        elif no == no.pai.esquerda:# Caso seja menor
            no.pai.esquerda = filho# Elimino o no da arvore
        else:# Caso seja maior
            no.pai.direita = filho# Elimino o no da arvore
        #Link o filho ao seu novo pai
        filho.pai = no.pai

    # Corrige a arvore
    def __fix_delete(self, x):
        while x != self.raiz and x.cor == color['black']:
            if x == x.pai.esquerda:
                s = x.pai.direita
                if s.cor == color['red']:
                    # case 3.1
                    s.cor = color['black']
                    x.pai.cor = color['red']
                    self.rotaciona_esquerda(x.pai)
                    s = x.pai.direita

                if s.esquerda.cor == color['black'] and s.direita.cor == color['black']:
                    # case 3.2
                    s.cor = color['red']
                    x = x.pai
                else:
                    if s.direita.cor == color['black']:
                        # case 3.3
                        s.esquerda.cor = color['black']
                        s.cor = color['red']
                        self.rotaciona_direita(s)
                        s = x.pai.direita

                    # case 3.4
                    s.cor = x.pai.cor
                    x.pai.cor = color['black']
                    s.direita.cor = color['black']
                    self.rotaciona_esquerda(x.pai)
                    x = self.raiz
            else:
                s = x.pai.esquerda
                if s.cor == color['red']:
                    # case 3.1
                    s.cor = color['black']
                    x.pai.cor = color['red']
                    self.rotaciona_direita(x.pai)
                    s = x.pai.esquerda

                if s.esquerda.cor == color['black'] and s.direita.cor == color['black']:
                    # case 3.2
                    s.cor = color['red']
                    x = x.pai
                else:
                    if s.esquerda.cor == color['black']:
                        # case 3.3
                        s.direita.cor = color['black']
                        s.cor = color['red']
                        self.rotaciona_esquerda(s)
                        s = x.pai.esquerda

                        # case 3.4
                    s.cor = x.pai.cor
                    x.pai.cor = color['black']
                    s.esquerda.cor = color['black']
                    self.rotaciona_direita(x.pai)
                    x = self.raiz
        x.cor = color['black']

    # Procura o no com a menor chave a partir do no
    def minimum(self, no):
        while no.esquerda != self.arvoreVazia:
            no = no.esquerda
        return no

    def preordem(self):
        return self.preordem_rec(self.raiz)

    def preordem_rec(self, no):
        if (no != self.arvoreVazia):
            yield no
            yield from (self.preordem_rec(no.esquerda))
            yield from (self.preordem_rec(no.direita))

    def inordem(self):
        return self.inordem_rec(self.raiz)

    def inordem_rec(self, no):
        if (no != self.arvoreVazia):
            yield from (self.inordem_rec(no.esquerda))
            yield no
            yield from (self.inordem_rec(no.direita))

    def posordem(self):
        return self.posordem_rec(self.raiz)

    def posordem_rec(self, no):
        if (no != self.arvoreVazia):
            yield from (self.posordem_rec(no.esquerda))
            yield from (self.posordem_rec(no.direita))
            yield no

    def procuraKey(self, key):
        no = self.raiz
        while no != self.arvoreVazia:
            if key < no.chave:
                no = no.esquerda
            elif key > no.chave:
                no = no.direita
            elif key == no.chave:
                return no
        return None



if __name__ == "__main__":
    bst = Tree()
    print("Inserindo Dados")
    bst.insert("b8", "1")#Insert por função
    bst.insert("h80", "2")#Insert por função
    bst["e18"]="3"#Insert por chave
    bst["a5"]="4"#Insert por chave
    bst["c15"]="5"#Insert por chave
    bst["d17"]="6"#Insert por chave
    bst["f25"]="7"#Insert por chave
    bst["g40"]="8"#Insert por chave

    #Printa a arvore inOrden
    print(str(bst) + "\n")

    print("Removendo Dados")
    bst["c15"]=None#Remove por chave
    bst.remove("c17")#Remove por chave
    
    #Printa a arvore inOrden
    print(str(bst) + "\n")

    #Percorre a arvore em preOrden
    print("Percorre a arvore em preOrden")
    for no in bst.preordem():
        print(no)
    print("\n")

    #Percorre a arvore em inOrden
    print("Percorre a arvore em inOrden")
    for no in bst.inordem():
        print(no)
    print("\n")

    #Percorre a arvore em posOrden
    print("Percorre a arvore em posOrden")
    for no in bst.posordem():
        print(no)
    print("\n")