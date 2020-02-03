#Importa os arquivo
import sys
from random import randint,shuffle
from copy import copy
import algoritimoGenetico
import gene
import individuo
import saida

numeroIndividuos = 100
numeroGeracoes = 60
idadeMaxima = 5

def melhorIndividuo(populacao):
    #Salva o Melhor individuo
    melhorIndice=0
    melhor = populacao[0]
    for indice,individuo in enumerate(populacao):
        if(populacao[melhorIndice].fitnes < individuo.fitnes):
            melhorIndice = indice
            melhor = individuo
    return melhor

def populacaoInicial(numeroIndividuos, listaPalavras):
    populacao = []
    sentido = [1,2,3]   #HORIZONTAL = 1 VERTICAL = 2    DIAGONAL = 3
    #Cria 'n' individuos aleatorios
    for x in range(numeroIndividuos):
        #Preparando Genes
        listaGenes = []
        for palavra in listaPalavras:
            indice = randint(0,2)
            auxGene = gene.gene(1, 1, palavra, sentido[indice])
            listaGenes.append(auxGene)
        #Embaralha os genes
        shuffle(listaGenes)
        ind = individuo.individuo(listaGenes)
        populacao.append(ind)
    return populacao



#Prepara as Palavras
nomeArquivo = sys.argv[1] #Nome do arquivo
separador = sys.argv[2] #separador
listaPalavras = algoritimoGenetico.palavrasEntrada(nomeArquivo, separador)

#Cria população inicial;
populacao = populacaoInicial(numeroIndividuos, listaPalavras)
melhor = melhorIndividuo(populacao)

#Começa os Cruzamentos
for i in range(numeroGeracoes):
    print("Geração :",i," população",len(populacao))
    #Envelhece os individuos e deleta os individuos velhos
    listaIndicesApagar=[]
    for j,ind in enumerate(populacao):
        ind.envelhecimento()
        if(ind.idade > idadeMaxima):
            listaIndicesApagar.append(j)
    listaIndicesApagar.sort()
    listaIndicesApagar.reverse()
    for j in listaIndicesApagar:
        del populacao[-j]
    #Cria a roleta
    retorno = algoritimoGenetico.roleta(populacao)
    roleta = retorno[0]
    totalAptidao = retorno[1]
    #Cria N individuos
    #selecao dos pais
    for i in range(int(numeroIndividuos/2)):
        pais = algoritimoGenetico.selecaoPais(roleta, populacao, totalAptidao)
        filhos = algoritimoGenetico.Crossover(pais[0], pais[1])
        populacao.append(copy(filhos[0]))
        populacao.append(copy(filhos[1]))
    #Salva o melhor
    populacao.append(copy(melhor))
    melhor = melhorIndividuo(populacao)

print("\n---------------------------------------\n")
melhor = melhorIndividuo(populacao)
melhor.posicaoGenes()
print("\n")
print("Fitness",melhor.fitnes)
saida.HTML(melhor)

