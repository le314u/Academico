#Importa os arquivo
import sys
from random import randint,shuffle
from copy import copy
import algoritimoGenetico
import gene
import individuo
import html
import args

verboso = False

#argumentos
argumentos = args.argumentos(iterativo = True)

#Prepara as Palavras
listaPalavras = algoritimoGenetico.palavrasEntrada(argumentos.nomeArquivo, argumentos.separador)

#instanciação classe
output = html.html(argumentos.nLinhas, argumentos.nColunas)

for i in range(argumentos.nCacaPalavras):
    #Cria população inicial;
    populacao = algoritimoGenetico.populacaoInicial(argumentos.numeroIndividuos, listaPalavras)
    melhor = algoritimoGenetico.melhorIndividuo(populacao)

    #Começa os Cruzamentos
    for i in range(argumentos.numeroGeracoes):

        if(verboso):
            print("Geração :",i," população",len(populacao))

        #Envelhece os individuos
        listaIndicesApagar=[]
        for j,ind in enumerate(populacao):
            ind.envelhecimento()
            if(ind.idade > argumentos.idadeMaxima):
                listaIndicesApagar.append(j)
        listaIndicesApagar.sort()
        listaIndicesApagar.reverse()
        
        #Deleta os individuos velhos
        for j in listaIndicesApagar:
            del populacao[-j]

        #Cria a roleta
        retorno = algoritimoGenetico.roleta(populacao)
        roleta = retorno[0]
        totalAptidao = retorno[1]

        #Cria 'n' individuos e seleciona os pais
        for i in range(int(argumentos.numeroIndividuos/2)):
            pais = algoritimoGenetico.selecaoPais(roleta, populacao, totalAptidao)
            filhos = algoritimoGenetico.Crossover(pais[0], pais[1])
            populacao.append(copy(filhos[0]))
            populacao.append(copy(filhos[1]))

        #Salva o melhor
        populacao.append(copy(melhor))
        melhor = algoritimoGenetico.melhorIndividuo(populacao)

    melhor = algoritimoGenetico.melhorIndividuo(populacao)
    melhor.posicaoGenes()

    if(verboso):
        print("\n---------------------------------------\n")
        print("\n")
        print("Fitness",melhor.fitnes)

    output.persistencia(melhor,'CacaPalavras'+str(i)+'.html')