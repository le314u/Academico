import cv2
import numpy as np

# Teste para verificação se o opencv é versão 3 ou superiro
assert float(cv2.__version__.rsplit('.', 1)[0]) >= 3, 'OpenCV version 3 or newer required.'
# Criação do KERNEL DE TRANSFORMAÇÃO QUE FAZ a retirada do olho de peixe
K = np.array([[  689.21,     0.  ,  1295.56],
              [    0.  ,   690.48,   942.17],
              [    0.  ,     0.  ,     1.  ]])

#coeficientes de distorção zero funcionam bem para esta imagem
D = np.array([0., 0., 0., 0.])

# Copia o kernel e multiplica por um fator de 0.4
Knew = K.copy()
Knew[(0,1), (0,1)] = 0.4 * Knew[(0,1), (0,1)]#redimensionando a imagem


# Carrega a imagem na variavel IMG
img = cv2.imread('olho_peixe.jpg')

# Filtro para tirar olho de peixe
img_undistorted = cv2.fisheye.undistortImage(img, K, D=D, Knew=Knew)
# Escreve a imagem
cv2.imwrite('fisheye_distorcido.jpg', img_undistorted)
# Mostra a imagem Antes dos filtros
cv2.imshow('original', img)
cv2.waitKey()
# Mostra a imagem Apos os filtros
cv2.imshow('nao_distorcido', img_undistorted)
cv2.waitKey()
