import sys
Rec = 5000
sys.setrecursionlimit(Rec*3)
def Input():
    """Recebe os dados do Usuario"""
    # R é a quantidade de reações
    R = int(input())
    reacoes = []
    if(R != 0):
        for r in range(R):
            agentA, _, agentB, _, produto = input().split(' ')
            data = {
                'P':produto,
                'A':agentA,
                'B':agentB,
                'controle':None
            }
            reacoes.append( data )
    return R,reacoes

def isLeaf(pseudoArvore, chave):
    return not(chave in pseudoArvore)

def estruturaDados(reacoes):
    pseudoArvore = {}
    origem = []
    for reacao in reacoes:
        pseudoArvore[reacao['P']] = reacao
    return pseudoArvore

def Solve(): # O()
    while(True):
        R,reacoes = Input()
        if(R == 0):
            return
        pseudoArvore = estruturaDados(reacoes)
        produto = reacoes[len(reacoes)-1]
        defValor(pseudoArvore,produto['P'])
        print(pseudoArvore[ produto['P']]['P'],'requires',pseudoArvore[ produto['P']]['controle'],'containers')

def defValor(pseudoArvore,chave):
    A = None
    B = None
    no = pseudoArvore[chave]
    #Define Lado Esquerdo
    if(isLeaf(pseudoArvore,no['A'])):#Folha
        A = 0
    else:#Intermediario
        A = pseudoArvore[no['A']]['controle']
        if(A == None):#Caso a subArvore não tenha o custo definido
            defValor( pseudoArvore, no['A'] )
            A = pseudoArvore[no['A']]['controle']
            
    #Define Lado Esquerdo
    if(isLeaf(pseudoArvore, no['B'])):#Folha
        B = 0
    else:#Intermediario
        B = pseudoArvore[no['B']]['controle']
        if(B == None):#Caso a subArvore não tenha o custo definido
            defValor( pseudoArvore, no['B'] )
            B = pseudoArvore[no['B']]['controle']
    
    #Define o valor
    pseudoArvore[chave]['controle'] = max(max(A,B),min(A,B)+1)

Solve()