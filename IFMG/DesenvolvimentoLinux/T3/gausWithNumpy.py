# Programa baseado em https://www.codesansar.com/numerical-methods/gauss-jordan-method-python-program-output.htm

# Imports necessários para o bom funcionamento do código
import numpy as np # NumPy para manipular matriz
import sys # Sys para manipular o So

# Variavel Global
var_Global = {}

#Inicia a estrutura para uma matriz com 'n' equações
def iniciaMatriz():
    # Le uma quantidade 'n' de equações
    var_Global['qtdEquacoes'] = int(input('Quantidade de entrada: '))
    n = var_Global['qtdEquacoes'] # Variavel Local para ser menos verboso

    # Cria uma matrix qtdEquacoes por qtdEquacoes+1 e inicializa com zeros
    var_Global['matriz'] = np.zeros((n,n+1))

    # Cria um array de tamanho igual a 'qtdEquacoes' inicializado com zeros  que representa o vetor solução
    var_Global['solucao'] = np.zeros(n)


# Para cada linha que representa uma equação preenche tal linha ou seja a entrada é a propria equação
def preencheMatriz():
    n = var_Global['qtdEquacoes'] # Variavel Local para ser menos verboso

    # Le os coeficientes das 'n' equações
    print('Entre com os coeficientes da equação')
    for i in range(n):
        print('------------------')
        print('Equação nº '+str(i+1))
        for j in range(n+1):
            if( j != n):
                msg = '(X'+ str(j)+')='
            else:
                msg = 'Igual a :'

            var_Global['matriz'][i][j] = float(input(msg))

        equacao(var_Global['matriz'][i])

def GaussJordan():
    # Variavel Local menos verbosa
    n = var_Global['qtdEquacoes']

    # Aplicando eliminação de  Gauss Jordan
    for i in range(n):

        # Detecta divisão por zero
        if var_Global['matriz'][i][i] == 0.0:
            sys.exit('Divisão por zero detectada!')

        # Pivoteamento
        for j in range(n):
            if i != j:
                ratio = var_Global['matriz'][j][i]/var_Global['matriz'][i][i]
                for k in range(n+1):
                    var_Global['matriz'][j][k] = var_Global['matriz'][j][k] - ratio * var_Global['matriz'][i][k]
    
    # Vetor solução
    for i in range(n):
        var_Global['solucao'][i] = var_Global['matriz'][i][n] / var_Global['matriz'][i][i]

def Resultado():
    # Mostra o vetor solução
    print('\nSolução: ')
    for i in range(n):
        print('X%d = %0.2f' %(i,x[i]), end = '\t')

# Exibe a entrada de forma mais 'legivel'
def equacao(linha):
    # String que armazena o resultado
    stringEqu = '' 

    # Percorre a linha da matriz ou seja percorre uma equação
    for elemento in range(len(linha)):
        if( elemento == 0): #Primeiro elemento
            stringEqu = stringEqu + '('+str(linha[elemento])+'*'+'(x'+ str(elemento+1)+'))'
        elif( elemento != len(linha)-1):#Elementos intermediarios
            stringEqu = stringEqu + ' + ('+str(linha[elemento])+'*'+'(x'+ str(elemento+1)+'))'
        else: #Ultimo elemento
            stringEqu = stringEqu + '=' + str(linha[elemento])
    #Mostra na tela
    print(stringEqu)

def main():
    iniciaMatriz()
    preencheMatriz()
    GaussJordan()
    Resultado()

main()