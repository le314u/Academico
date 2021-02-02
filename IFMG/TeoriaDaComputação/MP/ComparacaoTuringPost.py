class Fila(object):
    def __init__(self):
        self.dados = []

    def insere(self, elemento):
        self.dados.append(elemento)

    def retira(self):
        return self.dados.pop(0)

    def vazia(self):
        return len(self.dados) == 0


def iniciaFila(filaMP):
    while not filaMP.vazia():
        filaMP.retira()

    filaMP.insere(5)
    filaMP.insere(6)
    filaMP.insere(7)
    filaMP.insere(8)
    filaMP.insere(9)
    filaMP.insere("#")
    filaMP.insere(1)
    filaMP.insere(2)
    filaMP.insere(3)
    filaMP.insere(4)

    return filaMP


def moveDireita(filaMP):
    filaMP.insere(filaMP.retira())
    return filaMP.dados


def moveEsquerda(filaMP):

    return filaMP.dados

def printaMT(fita, cabecote):
    return fita[0:cabecote], "->", fita[cabecote], "<-", fita[cabecote + 1: len(fita)]


fitaMT = [1, 2, 3, 4, 5, 6, 7, 8, 9]
cabecote = 4

filaMP = Fila()
filaMP = iniciaFila(filaMP)

print("Fita da MT:", printaMT(fitaMT, cabecote))
print("Fila da MP:", filaMP.dados, "\n")

print("Se a MT escrever I e mover para a direita:")
print("Fita da MT:", printaMT(fitaMT, cabecote + 1))
print("Fila da MP:", moveDireita(filaMP), "\n")

filaMP = iniciaFila(filaMP)

print("Se a MT escrever I e mover para a esquerda:")
print("Fita da MT:", printaMT(fitaMT, cabecote - 1))
print("Fila da MP:", moveEsquerda(filaMP), "\n")



"""
inicial 5 6 7 8 9 # 1 2 3 4
final   4 5 6 7 8 9 # 1 2 3

teste
5 6 7 8 9 # 1 2 3 4
5 6 7 8 9 # 1 2 3 4 #
6 7 8 9 # 1 2 3 4 # 5
7 8 9 # 1 2 3 4 # 5 6
8 9 # 1 2 3 4 # 5 6 7
9 # 1 2 3 4 # 5 6 7 8
# 1 2 3 4 # 5 6 7 8 9
1 2 3 4 # 5 6 7 8 9 #
2 3 4 # 5 6 7 8 9 # 1
3 4 # 5 6 7 8 9 # 1 2
4 # 5 6 7 8 9 # 1 2 3
# 5 6 7 8 9 # 1 2 3 4


[5, 6, 7, 8, 9, '#', 1, 2, 3, 4]
[5, 6, 7, 8, 9, '#', 1, 2, 3, 4, !0]
[1, 2, 3, 4, !0, 5, 6, 7, 8, 9, '#']
[!0, 5, 6, 7, 8, 9, '#',1, 2, 3, 4]




"""