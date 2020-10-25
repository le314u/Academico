#Lucas Mateus Fernandes
#RA 0035411

import cv2
import numpy as np

#Pega um frame do video
def getFrame(movie):
    return movie.read()

# Abre a imagem
def videoRead(path):
    movie = cv2.VideoCapture(path)
    return movie

# Mostra a imagem na tela
def showImg(txt, img):
    cv2.imshow(txt, img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    return

movie = videoRead('video.mp4')
aux, newImg = getFrame(movie)
oldImg = None

while(True):
    try:
        oldImg = newImg
        ret, newImg = getFrame(movie)
        #showImg("Old", oldImg)
        #showImg("New", newImg)

        imgRGB = cv2.subtract(newImg, oldImg)
        #showImg("rgb", imgRGB)

        imgHSV = cv2.cvtColor(imgRGB, cv2.COLOR_BGR2HSV)
        #showImg("HSV", imgHSV)

        tomClaro = np.array([0, 120, 120])
        tomEscuro = np.array([180, 255, 255])
        imgSegmentada = cv2.inRange(imgHSV, tomClaro, tomEscuro)
        showImg("Segmentada", imgSegmentada)

    except:
        break