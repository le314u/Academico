#sudo apt-get install python3-pip
#sudo pip3 install opencv-python
#sudo pip3 install numpy
#sudo pip3 install matplotlib

import cv2
import numpy

print ('opencv'+cv2.__version__)#Confirma a versão
print ('numpy'+numpy.__version__)#Confirma a versão


#############################
# Inicio Extra
#############################

# Converte a imagem em escala de cinza
def grayScale(img):
    return cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

# Converte a imagem em escala de cinza Na unha  
def myGrayScale(img):
    linhas = img.shape[0]
    colunas = img.shape[1]
    for l in range(linhas):
        for c in range(colunas):
            newPixel = img[l][c][0] + img[l][c][1] + img[l][c][2]
            img[l][c][0] = newPixel
            img[l][c][1] = newPixel
            img[l][c][2] = newPixel
    return img

# Imprime todos os valores dos pixels
def showMatrix(img):
    metaData = metaImagem(img)
    for l in range(metaData['linhas']):
        print('\n')
        for c in range(metaData['colunas']):
            print(img[l][c],end=' ')
    return   

def showHistograma(img):
    plt.hist(img.flatten(), 256, [0,256], color='b')
    plt.xlim([0,256])
    plt.show()

def show2Histograma(img1, img2):
    plt.subplot(2,1,1)
    plt.plot(img1,color='r')
    plt.hist(img1.flatten(), 256, [0,256], color='r')
    plt.xlim([0,256])

    plt.subplot(2,1,2)
    plt.plot(img2,color='b')
    plt.hist(img2.flatten(), 256, [0,256], color='b')
    plt.xlim([0,256])

    plt.show()


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

def filterCanais(image,fx):
    linhas = image.shape[0]
    colunas = image.shape[1]
    for l in range(linhas):
        for c in range(colunas):
            newPixel = fx(image[l][c])
            image[l][c][0] = newPixel
            image[l][c][1] = newPixel
            image[l][c][2] = newPixel
    return image


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
# Exemplos de Filtros

    

original = imagemRead('original.jpeg')
img = imagemRead('original.jpeg')
# Pega apenas o que o matiz azul for maior que as outra em no minimo 5%
def fx(pixel):
    #B=0 G=1 R=2
    if(pixel[1] == 0 or pixel[2] == 0):
        if ( ( pixel[0] > pixel[1] ) and ( pixel[0] > pixel[2]) ):
            return 0
        return 255
    if ( (pixel[0]/pixel[1] > 1.05) and ( pixel[0]/pixel[2] > 1.05) ):
        return 0
    return 255

# Se verde >100 o pixel vira branco
newImg = filterCanais(img,fx) 
#Mostra as 2 Img's
showImg(original)
showImg(newImg)
