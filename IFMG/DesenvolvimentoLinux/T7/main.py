class Tree:
    def __init__(self):
        self.RubroNegra = RubroNegra()
    
    def __getitem__(self, key):
        key = str(key)
        return self.RubroNegra.procuraKey(key)

    def __setitem__(self, key, value):
        key = str(key)
        if value != None:
            try:
                self[key].dado = value
            except:
                self.insert(key, value)
        else:
            pass

    def __iter__(self):
        return self.inordem()

    def insert(self, key, value):
        self.RubroNegra.inserir(key, value)
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
        return self.chave + "--->"+self.dado

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
    bst.insert("8", "")
    bst.insert("18", "")
    bst.insert("5", "")
    bst.insert("15", "")
    bst.insert("17", "")
    bst.insert("25", "")
    bst.insert("40", "")
    bst.insert("80", "Alguma Coisa")

    print(bst["80"])
    print(bst[80])
    print(bst["80"].dado)
    bst["80"]= "teste"
    print(bst["80"].dado)
    bst["800"]= "teste"
    for i in bst:
        print(i)

    #for i in bst.preordem():
    #    print(i.chave)

    #for i in bst.inordem():
    #    print(i.chave)

    #for i in bst.posordem():
    #    print(i.chave)

    #for i in bst:
    #    print(i.chave)

    # bst.delete_no(25)