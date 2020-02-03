import math
from random import randint
from copy import copy
import gene
import individuo

#Monta uma Roleta com a porcentagem que cada individuo tem de ser Selecionado
def roleta(populacao):#Pagina 10 http://www.inf.ufpr.br/aurora/tutoriais/Ceapostila.pdf
    #Somatorio dos valores de aptidao
    roleta = []
    totalAptidao = 0
    for indi in populacao:
        totalAptidao = totalAptidao + indi.fitnes
    #Define a porcentagem de cada fatia
    for indice, indi in enumerate(populacao):
        roleta.append(float(indi.fitnes)/totalAptidao)
    #Retorna a roleta
    return [roleta,totalAptidao]

#Semelhante a busca binaria retornara o indice mais proximo levando em consideração que deva ser > ou = 
def numeroFatia(roleta,valor):
    vetor = roleta
    tamanho = len(vetor)
    inicio = 0
    fim = tamanho-1
    for i in range(0,tamanho):
        indice = inicio + math.ceil((fim-inicio)/2) 
        if(inicio == fim and vetor[indice] != valor):
            if(indice < tamanho-1):
                if((vetor[indice] < valor) and (vetor[indice+1]>valor)):
                    return (indice+1)
            return indice
        else:
            if(vetor[indice] == valor):
                return indice
            elif(vetor[indice] < valor):
                inicio = inicio + math.ceil((fim-inicio)/2)
            elif(vetor[indice] > valor):
                fim = fim - math.ceil((fim-inicio)/2)

#Seleciona 2 individuos da População
def selecaoPais(roleta, populacao, totalAptidao):#Pagina 10 http://www.inf.ufpr.br/aurora/tutoriais/Ceapostila.pdf
    totalAptidao = int(totalAptidao)
    #Gera um Pai
    valorAleatorio1 = randint(0,totalAptidao)
    fatiaPai = numeroFatia(roleta,valorAleatorio1)
    pai = populacao[fatiaPai]
    #Gera uma Mae != do pai
    while(True):
        valorAleatorio2 = randint(0,totalAptidao)
        fatiaMae = numeroFatia(roleta,valorAleatorio2)
        if(fatiaMae != fatiaPai):
            mae = populacao[fatiaMae]
            break
    return (pai, mae)


def mutacao(individuos):
    pass

def selecaoSobreviventes(populacao, numeroIndividuos, metodo):
    #Ordena a população pelo metodo selecionado
    #
    #0=idade
    #1=fitness
    #2=elitista
    if(metodo == "idade" or metodo == 0):
        #Indivíduo sobrevive apenas durante a sua geração (Colocar um limite de gerações que um individuo pode durar)
        ordenado = OrdenaIdade(populacao) 
    elif(metodo == "fitness" or metodo == 1):
        #Piores indivíduos são substituídos
        ordenado = OrdenaFitness(populacao)
    elif(metodo == "elitista" or metodo == 2):
        #indivíduo mais apto sobrevive entre gerações
        ordenado = OrdenaElitista(populacao)  
    else:
        #Default
        ordenado = OrdenaIdade(populacao);
    return Ordenado[0:numeroIndividuos]


def OrdenaIdade(populacao):
    #ordena o vetor populacao por idade
    populacao.sort(key=operator.attrgetter('idade'))
    return populacao

def OrdenaFitness(populacao):
    #ordena o vetor populacao pelo fitness
    populacao.sort(key=operator.attrgetter('fitness'))
    return populacao

#INCERTEZA DE COMO FUNCIONA
def OrdenaElitista(populacao):
    #Ordena por idade e dentro da faixa de idade Ordena por Fitnes
    populacao = OrdenaIdade(populacao)

def _QuebraFatiasIdade(populacao,indice):
    idade = pupulacao[indice].idade
    for i,individuo in enumerate(populacao):
        if(idade > individuo.idade):
            return i
        
def Crossover(pai, mae):#Pagina 6 http://www.decom.ufop.br/prof/marcone/Disciplinas/InteligenciaComputacional/CorteBidimensionalGuilhotinado.pdf
    #Order Crossover (OX)
    tamanho = len(pai.genes)
    #Escolhe 2 pontos para seccionar o indviduo
    pontos = _2pontos(pai)
    #vetor inicial com os genes de cada filho
    genesFilhoA = []
    genesFilhoB = []
    #Pega os elementos intermediarios ponto0 a ponto1 de um individuo x
    for i in range(pontos[0], pontos[1]+1):
        genesFilhoA.append(copy(pai.genes[i]))
        genesFilhoB.append(copy(mae.genes[i]))
    #Pega os demais elementos de um individuo diferente de modo que comece a contar apos o ponto1 e de uma volta até chegar no elemento
    flagA = False
    flagB = False
    contador = pontos[1]
    while(not (flagA and flagB) ):
        #Indice circular
        contador = (contador + 1) % tamanho
        #FilhoA
        if(not flagA):
            #Verifica se o gene ja esta alocado
            flagAux = False;
            for gen in genesFilhoA:
                if(gen.palavra == mae.genes[contador].palavra):
                    flagAux = True;
            #Se não estiver alocado o aloca
            if(not flagAux ):
                #Adiciona o novo gene 
                genesFilhoA.append(copy(mae.genes[contador]))
                #Verifica se o filhoA ja esta completo
                if(len(genesFilhoA) == tamanho):
                    flagA = True
        #FilhoB
        if(not flagB):
            #Verifica se o gene ja esta alocado
            flagAux = False;
            for gen in genesFilhoB:
                if(gen.palavra == pai.genes[contador].palavra):
                    flagAux = True;
            #Se não estiver alocado o aloca
            if(not flagAux):
                #Adiciona o novo gene 
                genesFilhoB.append(copy(pai.genes[contador]))
                if(len(genesFilhoB) == tamanho):
                    flagB = True
    #Aloca os n individuos
    filhoA = individuo.individuo(genesFilhoA)
    filhoA.reSet()
    filhoB = individuo.individuo(genesFilhoB)
    filhoB.reSet()
    return(filhoA, filhoB)

#Retorna 2 pontos de modo que divida o inviduo em 3 partes
def _2pontos(individuo):
    #Numero de palavras em um individuo
    tamanho = len(individuo.genes)
    #Escolhe 2 pontos de modo que divida o individuo em 3 partes
    ponto1 = randint(1,tamanho-2)
    while(True):
        ponto2 = randint(1,tamanho-2)
        if(ponto1 != ponto2):
            break
    pontos = ([ponto1, ponto2] if ponto1 <= ponto2 else [ponto2, ponto1])
    return pontos

def palavrasEntrada(nomeArquivoEntrada, separador):
    #Le um arquivo x
    arquivo = open(nomeArquivoEntrada, 'r')
    texto = arquivo.readlines()
    palavras = []
    for linha in texto :
        palavras.extend(linha.split(separador))
    arquivo.close()
    return palavras