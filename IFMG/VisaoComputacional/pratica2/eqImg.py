import cv2
import numpy
import matplotlib
from matplotlib import pyplot as plt

print ('opencv'+cv2.__version__)#Confirma a versão
print ('numpy'+numpy.__version__)#Confirma a versão
print ('matplotlib'+matplotlib.__version__)#Confirma a versão


#############################
# Inicio Extra
#############################

# Converte a imagem em escala de cinza
def grayScale(img):
    return cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

# Imprime todos os valores dos pixels
def showMatrix(img):
    metaData = metaImagem(img)
    for l in range(metaData['linhas']):
        print('\n')
        for c in range(metaData['colunas']):
            print(img[l][c],end=' ')
    return   

# Exemplos de Filtros
def f1(n):
    return 255-n

def f2(n):
    return 0

def f3(n):
    return n*1.5 if n*1.5<=255 else 255

def showHistograma(histogram):
    #mostra histograma não equalizado, m
    plt.hist(img.ravel(),256,[0,256])
    plt.show()
    cv2.waitKey(0)
    cv2.destroyAllWindows()


#############################
# Fim Extra
#############################

#############################
# Inicio Core
#############################

# Abre a imagem
def imagemRead(path):
    img = cv2.imread(path)
    return img

# Separa a imagem em 3 Canais
def getCanais(img):
    B,G,R = cv2.split(img)
    return{
        'blue':B,
        'green':G,
        'red':R,
    }

# Junta a imagem em 3 Canais
def mergeCanais(jsonCanal):
    return cv2.merge(
        ( jsonCanal['blue'],
        jsonCanal['green'],
        jsonCanal['red'] )
    )

# Pega dimensoes da imagem
def metaImagem(img):
    qtdLinhas = len(img)
    qtdColunas = len(img[0])
    return {
        'linhas':qtdLinhas,
        'colunas':qtdColunas
    }

# Mostra a imagem na tela
def showImg(img):
    cv2.imshow('nomeImg',img)
    cv2.waitKey(0)
    return

# Altera todos os valores dos pixels
def filterCanal(canal,fx):
    linhas = canal.shape[0]
    colunas = canal.shape[1]
    for l in range(linhas):
        for c in range(colunas):
            canal[l][c] = fx(canal[l][c])
    return canal


# Cria um Histograma
def histograma(canal):
    return numpy.histogram(canal.flatten(),256,[0,256])

# Retorna um vetor com a probabilidade de ocorrência de um tom menor ou igual o tom analisado                       
def cdf(vetPmf):
    return vetPmf.cumsum()

# Retorna um vetor com probabilidade de ocorrência do tom X na imagem
def pmf(histogram,totalPixel):
    #Quantidade de pixels de tom 'x' dividido pela quantidade de pixel
    return histogram/totalPixel
    
# Normalizar o vetor ou seja coloca todos os valores do vetor em um range
def normalizacao(vetCdf):
    print(vetCdf)
    return (vetCdf - vetCdf.min())*255  /  (vetCdf.max()-vetCdf.min()) 

def equalizaCanal(canal):
    #Cria um histograma
    hist,bis = histograma(canal)
    #Pega Meta dados da imagem
    metaDados = metaImagem(canal)
    #Vetor de probabilidades
    vetPmf = pmf(hist, metaDados['linhas']*metaDados['colunas'])
    #Vetor de probabilidade acumulado
    vetCdf = cdf(vetPmf)
    #Normaliza o vetor
    vetNorm = normalizacao(vetCdf) 
    #Equalizando
    return equaliza(vetNorm)[canal]

def equaliza(vetCdf):
    # Cria um filtro
    cdf_f = numpy.ma.filled(vetCdf,0).astype('uint8')
    #Retorna uma matriz
    return cdf_f

#############################
# Fim Core
#############################

img = imagemRead('satelite.png')
canais = getCanais(img)
#Equalizando
red = equalizaCanal(canais['red'])
green = equalizaCanal(canais['green'])
blue = equalizaCanal(canais['blue'])
newImg = mergeCanais({
    'blue':blue,
    'green':green,
    'red':red
})

#Mostra as Img's antes e depois
showImg(img)#Normal
showImg(newImg)#Equalizado
showImg(grayScale(newImg))#
