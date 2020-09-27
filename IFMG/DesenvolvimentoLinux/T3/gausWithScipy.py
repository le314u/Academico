# Programa baseado em https://www.codesansar.com/numerical-methods/gauss-jordan-method-python-program-output.htm

# Imports necessários para o bom funcionamento do código
import numpy as np # NumPy para manipular matriz
import sys # Sys para manipular o So
from scipy import linalg # SciPy para fazer o trabalho arduo

# Variavel Global
var_Global = {}

#Inicia a estrutura para uma matriz com 'n' equações
def iniciaMatriz():
    # Le uma quantidade 'n' de equações
    var_Global['qtdEquacoes'] = int(input('Quantidade de entrada: '))
    n = var_Global['qtdEquacoes'] # Variavel Local para ser menos verboso

    # Cria uma matrix qtdEquacoes por qtdEquacoes e inicializa com zeros
    var_Global['matriz'] = np.zeros((n,n))
    
    # Cria uma matrix qtdEquacoes por 1 que representa o resultado das equações
    var_Global['matrizRes'] = np.zeros((n,1))

# Para cada linha que representa uma equação preenche tal linha ou seja a entrada é a propria equação
def preencheMatriz():
    n = var_Global['qtdEquacoes'] # Variavel Local para ser menos verboso

    # Le os coeficientes das 'n' equações
    print('Entre com os coeficientes da equação')
    for i in range(n):
        print('------------Equação nº '+str(i+1) +'------------')
        for j in range(n+1):
            if( j != n):
                msg = '(X'+ str(j)+')='
                var_Global['matriz'][i][j] = float(input(msg))
            else:
                msg = 'Resultado = '
                var_Global['matrizRes'][i][0] = float(input(msg))

        equacao(var_Global['matriz'][i], var_Global['matrizRes'][i][0])
    print('-----------------------------')
    
def Resultado():
    matrizEq = var_Global['matriz']
    matrizRes = var_Global['matrizRes']
    resultado = np.linalg.solve(matrizEq, matrizRes)

    for indice in range(len(resultado)):
        print('(X'+str(indice)+') = '+str(resultado[indice][0]))
    

# Exibe a entrada de forma mais 'legivel'
def equacao(equacao,res):
    # String que armazena o resultado
    stringEqu = '' 

    # Percorre a linha da matriz ou seja percorre uma equação
    for elemento in range(len(equacao)):
        if( elemento == 0): #Primeiro elemento
            stringEqu = stringEqu + '('+str(equacao[elemento])+'*'+'(x'+ str(elemento+1)+'))'
        else:#Elementos intermediarios
            stringEqu = stringEqu + ' + ('+str(equacao[elemento])+'*'+'(x'+ str(elemento+1)+'))'
    #Ultimo elemento
    stringEqu = stringEqu + ' = ' + str(res)
    #Mostra na tela
    print(stringEqu)

def main():
    iniciaMatriz()
    preencheMatriz()
    Resultado()

main()