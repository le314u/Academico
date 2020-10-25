# -*- coding:utf-8 -*-

import math
import numpy as np
import cv2


def lim(x):
    if (x > 253):
        return 253
    else:
        return x


def abs(x):
    if (x < 0):
        return x * -1
    else:
        return x


def primeiraDerivadaGaussUni(x, desvio):
    fator = float(1.0 / float(desvio * math.sqrt(2.0 * math.pi)))
    return fator * math.exp(float(float(-1.0 * x ** 2) / float(2.0 * desvio ** 2)))


def primeiraDerivadaGaussBi(x, desvio):
    fator = float(1.0 / float(desvio * math.sqrt(2.0 * math.pi)))
    return fator * math.exp(float(float(-1.0 * x ** 2) / float(2.0 * desvio ** 2)))


def getMaiorIntensidade(l, c, imgX):
    li = l - 1
    ci = c - 1
    maiorIntensidade = 0
    while (li < l + 1):
        while (ci < c + 1):
            if (maiorIntensidade < imgX[li][ci]):
                maiorIntensidade = imgX[li][ci]
            ci += 1
        li += 1
    return maiorIntensidade


# pega a captura da webcam
captura = cv2.VideoCapture("video.mp4")

# loop infinito para ficar recebendo frame a frame 
while True:
    # momento em que pega frame a frame para posteriormente exibi-lo
    ret, img = captura.read()
    img = cv2.GaussianBlur(img, (3, 3), 0)

    # sobel horizontal , vertical, diagonal
    img1 = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    img2 = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    imgde = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # imagem crua para fazer a convolução
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    ####################################
    # aplicação dos gradientes de sobel
    mh = [[-1, -2, -1], [0, 0, 0], [1, 2, 1]]  # horizontal
    mv = [[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]]  # vertical
    mde = [[-2, -1, 0], [-1, 0, 1], [0, 1, 2]]  # diagonal esquerda

    # pega o numero de linhas e colunas
    qtdLinhas = len(img)
    qtdColunas = len(img[0])

    # percorre toda a imagem
    for l in range(qtdLinhas):
        for c in range(qtdColunas):
            # se não for a primeira coluna ou linha de pixels nem as ultimas, faça(por causa da convolução pixel a pixel)
            if (l >= 1 and l <= qtdLinhas - 2 and c >= 1 and c <= qtdColunas - 2):
                lm = 0
                somaH = 0.0
                somaV = 0.0
                somaDE = 0.0
                for lf in range(l - 1, l + 2):
                    cm = 0
                    for cf in range(c - 1, c + 2):
                        somaH += float(img[lf][cf] * mh[lm][cm])
                        somaV += float(img[lf][cf] * mv[lm][cm])
                        somaDE += float(img[lf][cf] * mde[lm][cm])
                        cm += 1
                    lm += 1

                somaH = lim(abs(somaH))
                somaV = lim(abs(somaV))
                somaDE = lim(abs(somaDE))

                img1[l][c] = float(somaH)
                img2[l][c] = float(somaV)
                imgde[l][c] = float(somaDE)

    # adiciona o horzontal ao vertical
    img3 = cv2.absdiff(img2, img1)
    img3 = cv2.absdiff(img3, imgde)
    img4 = cv2.absdiff(img2, img1)
    img4 = cv2.absdiff(img4, imgde)
    res = np.hstack((img1, img2, imgde, img3))

    # Supressão de não máximos
    # percorre toda a imagem
    for l in range(qtdLinhas):
        for c in range(qtdColunas):
            # se não for a primeira coluna ou linha de pixels nem as ultimas, faça(por causa da convolução pixel a pixel)
            if (l >= 1 and l <= qtdLinhas - 2 and c >= 1 and c <= qtdColunas - 2):

                # verifica a intensidade máxima
                maiorIntensidade1 = getMaiorIntensidade(l, c, img1)
                maiorIntensidade2 = getMaiorIntensidade(l, c, img2)
                maiorIntensidadeDE = getMaiorIntensidade(l, c, imgde)
                print(maiorIntensidade1, maiorIntensidade2, maiorIntensidadeDE)

                # suprime os não maximos da primeira imagem
                li = l - 1
                ci = c - 1
                while (li < l + 1):
                    while (ci < c + 1):
                        if (maiorIntensidade1 > img1[li][ci]):
                            img1[li][ci] = 0
                        ci += 1
                    li += 1

                # suprime os não máximos da segunda imagem
                li = l - 1
                ci = c - 1
                while (li < l + 1):
                    while (ci < c + 1):
                        if (maiorIntensidade2 > img2[li][ci]):
                            img2[li][ci] = 0
                        ci += 1
                    li += 1

                # suprime os não maximos da imagem em diagonal esquerda
                li = l - 1
                ci = c - 1
                while (li < l + 1):
                    while (ci < c + 1):
                        if (maiorIntensidade1 > imgde[li][ci]):
                            imgde[li][ci] = 0
                        ci += 1
                    li += 1

    img3 = cv2.absdiff(img2, img1)
    img3 = cv2.absdiff(img3, imgde)
    res = np.hstack((img1, img2, imgde, img3))
    grausLiberdade = 30  # (alterar para menos observando pixels não limitados)
    intensidade = 240

    for l in range(qtdLinhas):
        for c in range(qtdColunas):
            if (img3[l][c] < intensidade - grausLiberdade or img3[l][c] > intensidade + grausLiberdade):
                img4[l][c] = 0
            else:
                img4[l][c] = 255

    cv2.imshow("Saida", img4)

    # criterio de parada do laco de repeticao
    if cv2.waitKey(30) & 0xFF == ord('q'):
        break

captura.release()
cv2.destroyAllWindows()