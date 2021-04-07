# -*- coding: utf-8 -*-
def Input():
    """Pega a entrada de Dados"""
    linha1 = input();
    N,Q = linha1.split(' ');
    N = int(N);
    Q = int(Q);
    if(Q == 0 and N == 0):
        return N,Q,None,None
    linha2 = input();
    Sons = linha2.split(' ');
    linha3 = input();
    Consultas = linha3.split(' ');
    return N,Q,Sons,Consultas

def numberDigits(indice, base):
    """Dado um indice e o numero de elementos de uma base,
    retorna  o numero de Digitos que compoem o elemento presente no caracter de indice 'indice'
    da lista lexicografica"""
    return numberDigitsRec(indice, base, 0, 1);

def numberDigitsRec(indice, base, somaAnt, nDigits):
    """Calcula recursivamente quantos digitos são escritos
    até começar a escrever um elemento com 'n'digitos"""
    somaAnt=0
    nDigits=1
    while(True):
        #Calcula quantos elementos existem com nDigits
        qtdElementos = (base ** nDigits);
        #Calcula quantos caracteres foram escritos até chegar em um elemento de 'n' digitos
        initElement = somaAnt;
        #Calcula quantos caracteres são escritos até escrever todos os elementos de 'n'digitos
        endElement = initElement + ( qtdElementos * nDigits);
        #Verifica se o indice 'n' esa dentro de um elemento com 'n' caracteres
        if(endElement >= indice):#Esta dentro
            return (nDigits, initElement+1, endElement);
        else:#Esta fora
            #Verifico se o caracter procurado esta dentro de um elemento com 'nDigits+1'
            somaAnt = endElement
            nDigits = nDigits+1

def _numberDigitsRec(indice, base, somaAnt, nDigits):
    """Calcula recursivamente quantos digitos são escritos
    até começar a escrever um elemento com 'n'digitos"""

    #Calcula quantos elementos existem com nDigits
    qtdElementos = (base ** nDigits);
    #Calcula quantos caracteres foram escritos até chegar em um elemento de 'n' digitos
    initElement = somaAnt;
    #Calcula quantos caracteres são escritos até escrever todos os elementos de 'n'digitos
    endElement = initElement + ( qtdElementos * nDigits);
    #Verifica se o indice 'n' esa dentro de um elemento com 'n' caracteres
    if(endElement >= indice):#Esta dentro
        return (nDigits, initElement+1, endElement);
    else:#Esta fora
        #Verifico se o caracter procurado esta dentro de um elemento com 'nDigits+1'
        return numberDigitsRec(indice, base, endElement, nDigits+1);

def element(indice, base):
    """Dado um indice e o numero de elementos de uma base,
    retorna  Qual o elemento que contem o caracter de indice 'indice' presente na lista lexicografica"""
    nDigits, init, end = numberDigits(indice, base);
    elem =  elementInt(indice, base, init, nDigits);
    return nDigits, init, end, elem

def elementInt(indice, base , inicio, nDigits):
    """Calcula qual o elemento que contem o caracter de indice 'indice'
    a partir da informação de quantos caracteres compoem o elemento que possuim o caracter escolhido"""
    #Elemento procurado onde cada posição determina um caracter do elemento
    elemento = [];
    #Inicia a variavel que define qual o caracter da posição 'n'
    letra = 0
    #Define quantos caracteres foram escritos ante de começar os elementos com nDigits
    acumulativo = inicio - 1
    #Dada a posição 'iElement' de um elemento contando a posição da direita para a esquerda
    for iElement in range(nDigits,0,-1):
        #Define qual o Caracter da posição 'iElement'
        for i in range(1, base+1):
            #Se o elemento tiver a posição 'iElement' igual a letra 'i' quantos elementos podem ser escritos
            qtdElementos = (base ** (iElement - 1) )
            acumulativo = acumulativo + ( qtdElementos * nDigits)
            #Caso não tenha atingido ou passado o indice é necessário avançar para a proxima letra em 'iElement'
            if(acumulativo >= indice):
                letra = i
                acumulativo = acumulativo - ( qtdElementos * nDigits)
                break
        elemento.append(letra)
    return elemento
    #Letra ok vai para a proxima
    
def charElement(indice, base):
    """ Dado um indice de um vetor retorna o char de indice 'i' """
    #Tamanho da Base
    tBase = len(base)
    #Descobre em qual elemento está o caracter de indice 'indice'
    nDigits, init, end, elem = element(indice, tBase );
    #Sabendo qual o elemento aparece o indice descobre qual o caracter dentro do elemento
    ind = charElementInt(indice,tBase,elem,init-1)
    #Converte a representação por um valor da base
    char = convertIndice2String(indice,elem,ind,base)
    return char

def charElementInt(indice, base, elemento, partida):
    """Calcula qual o indice de um caracter em uma lista Lexicocrafica dado o elemento em que se encontra tal indice"""
    nDigits = len(elemento)
    aritimetica = 0
    for i in range(nDigits):
        #Aritimetica
        aritimetica = aritimetica + (elemento[i]-1)* base ** (nDigits-i-1)
    movimentos = aritimetica * nDigits
    indice = (partida + movimentos)
    return indice

def convertIndice2String(indice,elemento,indiceElement,base):
    deslocamento = indice-indiceElement
    indiceBase = elemento[deslocamento-1]
    return base[indiceBase-1]

# Entrada = []
# while(True):
#     N,Q,Sons,Consultas = Input()
#     if(Q != 0 and N != 0):
#         for i in Consultas:
#             print( charElement(int(i),Sons) )
#         print('\n')
#     else:
#         break

Entrada = []
while(True):
   N,Q,Sons,Consultas = Input()
   if(Q != 0 and N != 0):
       Entrada.append((N,Q,Sons,Consultas))
   else:
       break

for N,Q,Sons,Consultas in Entrada:
    for i in range(Q):
        indice = int(Consultas[i])
        print( charElement(int(indice),Sons) )
    print()