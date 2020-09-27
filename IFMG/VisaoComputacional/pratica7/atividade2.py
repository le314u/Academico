from builtins import range

import cv2
import numpy as np

PATH_IMG = "img.jpg"
KERNEL = [ [-1, 0, 1], [-2, 0, 2], [-1, 0, 1] ]

#pega imagem convertendo para escala em cinza
def readImg(path):
    return cv2.imread( path )

def grayScale(img):
    return cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

def showImg(img):
    cv2.imshow("", img)
    cv2.waitKey(0)

def metaImg(img):
    #pega o numero de linhas e colunas
    qtdLinhas = len(img)
    qtdColunas = len(img[0])
    return {
        "linhas" : len(img),
        "colunas" : len(img[0])
    }


def sum(newFrame, size=3):
    sumAcc = 0
    for i in range(size):
        for j in range(size):
            sumAcc = sumAcc + newFrame[i][j]
    return float( sumAcc/(size*size) )

def newKernel(img, kernel, l, c):
    #Cria um quador do tamanho do kernel com zeros
    newFrame = np.zeros((3,3))

    newFrame[0][0] = float( img[l-1][c-1] * kernel[0][0])
    newFrame[0][1] = float( img[l-1][c] * kernel[0][1])
    newFrame[0][2] = float( img[l-1][c+1] * kernel[0][2])

    newFrame[1][0] = float( img[l][c-1] * kernel[1][0])
    newFrame[1][1] = float( img[l][c] * kernel[1][1])
    newFrame[1][2] = float( img[l][c+1] * kernel[1][2])
    
    newFrame[2][0] = float( img[l+1][c-1] * kernel[2][0])
    newFrame[2][1] = float( img[l+1][c] * kernel[2][1])
    newFrame[2][2] = float( img[l+1][c+1] * kernel[2][2])

    return newFrame
    
def applyKernel(img, kernel):
    newImg = img.copy()
    meta = metaImg(img)
    #percorre toda a imagem
    for l in range(meta['linhas']):
        for c in range(meta['colunas']):
            #se não for a primeira coluna ou linha de pixels nem as ultimas, faça(por causa da convolução pixel a pixel)
            if(l > 0 and l < (meta['linhas']-1) and c > 0 and c < (meta['colunas']-1) ):
                newFrame = newKernel(img, kernel, l, c)
                newPixel = sum(newFrame)
                newImg[l][c] = newPixel
    return newImg
        


img = readImg(PATH_IMG)
gImg = grayScale(img)
newImg = applyKernel(gImg, KERNEL)
showImg(newImg)