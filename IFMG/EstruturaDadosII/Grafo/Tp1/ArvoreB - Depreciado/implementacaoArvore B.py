#-----------------------------------------------
#Nome:      Lucas Mateus
#E-mail:    lucasmfpiu@gmail.com
#Data:      xx/xx/2019
#-----------------------------------------------

import ArvoreB

tree = ArvoreB.ArvoreB(5)
elementos = 10

for i in range(elementos):
    print("\nInserir")
    tree.insert(i,i)
    print("Procurar")
    #print(tree.search(i)[0])
    print(tree)