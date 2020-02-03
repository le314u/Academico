#Importa os arquivo
from random import randint,shuffle
import gene
import individuo

def matrixRandom():
    #Transforma um individuo em uma 'matriz'
    matriz = []
    for i in range (0,gene.NUMERO_LINHAS):
        matriz.append([])
        for j in range (0,gene.NUMERO_COLUNAS):
            #Gera um caracter Asc Maiusculo de A-Z
            letra = chr(randint(65,90))
            matriz[i].append(letra)
    return matriz

def individuoMatrix(matriz, individuo):
    #passa pelos n genes
    for i, gen in enumerate(individuo.genes):
        #So coloca as palavra utilizadas 
        if(individuo._auxGenesUtilizados[i] == True):
            if(gen.sentido == gene.HORIZONTAL):
                #Passa por todas as letras da palavra
                vetor = gen._vetor4Pontos()
                #Em qual linha vai ficar
                linha = randint(vetor[1],vetor[3])
                for i in range(len(gen.palavra)):
                    matriz[linha-1][gen.coluna+i-1] = gen.palavra[i]
            if(gen.sentido == gene.VERTICAL):
                #Passa por todas as letras da palavra
                vetor = gen._vetor4Pontos()
                #Em qual linha vai ficar
                coluna = randint(vetor[0],vetor[2])
                for i in range(len(gen.palavra)):
                    matriz[gen.linha+i-1][coluna-1] = gen.palavra[i]
            if(gen.sentido == gene.DIAGONAL):
                #Passa por todas as letras da palavra
                for i in range(len(gen.palavra)):
                    matriz[gen.linha+i-1][gen.coluna+i-1] = gen.palavra[i]    
    return matriz

def geraHtml(matriz, individuo):
    #Cria arquivo
    arquivo = open("Cacapalavras.html","w")
    arquivo.write("<html>\n")
    #Estilo Simples
    arquivo.write("<style>\n"+
        "\t\t.letra{\n"+
            "\t\t\ttext-align: center;\n"
            "\t\t}\n"+
        "</style>\n")
    arquivo.write("\t<body>\n")
    #Cria Tabela
    arquivo.write("\t\t<table border='1' width='90%'>\n")
    for i in range(gene.NUMERO_LINHAS):
    #repete igual o numero de Linhas
        arquivo.write("\t\t\t<tr>")
        for j in range(gene.NUMERO_COLUNAS):
            #Repete igualç o numero de Colunas
            arquivo.write("<td class='letra'>"+str(matriz[i][j])+"</td>\t")
        arquivo.write("</tr>\n")
    arquivo.write("\n\t\t</table>\n")
    for i, valido in enumerate(individuo._auxGenesUtilizados):
        if(valido):
            arquivo.write("\t<br>"+individuo.genes[i].palavra+"\n")
    arquivo.write("\n\t</body>\n</html>")
    arquivo.close()

def HTML(individuo):
    mRandom = matrixRandom()
    mFinal = individuoMatrix(mRandom, individuo)
    geraHtml(mFinal, individuo)