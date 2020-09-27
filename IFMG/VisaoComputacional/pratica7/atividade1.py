import cv2
import numpy as np

# Constantes
PATH_IMAGEM = "img.png"
KERNEL = 3

def readImage():
    return cv2.imread(PATH_IMAGEM)

def grayScale(img):
    return cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

def subImg(img):
    return img[::2, ::2]

def closeWindows():
    cv2.destroyAllWindows()

def spinImg(img, arg):
    # Rotacionar Verticalmente
    if (arg == 0):
        return cv2.flip(img, 0)
    # Rotacionar Horizontalmente
    elif (arg == 1):
        return cv2.flip(img, 1)

    return None

def showImg(img):
    # Mostra as imagens na tela
    cv2.imshow("", img)
    cv2.waitKey(0)
    closeWindows()

def media():
    img = readImage()
    img = grayScale(img)
    img = subImg(img)

    # Calculo com KERNEL de 3x3
    media = cv2.blur(img, (KERNEL, KERNEL))

    # Junta as imagens
    imgs = np.vstack([
        np.hstack([img, media])
    ])

    return imgs

def gauss():
    img = readImage()
    img = grayScale(img)
    img = subImg(img)

    gaussiana = cv2.GaussianBlur(img, (KERNEL, KERNEL), 0)

    # Junta as imagens
    imgs = np.vstack([
        np.hstack([img, gaussiana])
    ])

    return imgs

def vertical():
    img = readImage()
    img = subImg(img)

    vertical = spinImg(img, 0)

    # Junta as imagens
    imgs = np.vstack([
        np.hstack([img, vertical])
    ])

    return imgs

def horizontal():
    img = readImage()
    img = subImg(img)

    horizontal = spinImg(img, 1)

    # Junta as imagens
    imgs = np.vstack([
        np.hstack([img, horizontal])
    ])

    return imgs

def laplaciano():
    img = readImage()
    img = grayScale(img)
    img = subImg(img)

    lap = cv2.Laplacian(img, cv2.CV_64F)
    lap = np.uint8(np.absolute(lap))

    # Junta as imagens
    imgs = np.vstack([
        np.hstack([img, lap])
    ])

    return imgs

def menu():

    print('[1] Média')
    print('[2] Gauss')
    print('[3] Vertical')
    print('[4] Horizontal')
    print('[5] Laplaciano')
    print('[6] Sair')
    print('-----------------')
    while(True):
        arg = int(input('Opção desejada: '))
        if arg == 1:
            showImg( media() )
        elif arg == 2:
            showImg( gauss() )
        elif arg == 3:
            showImg( vertical() )
        elif arg == 4:
            showImg( horizontal() )
        elif arg == 5:
            showImg( laplaciano() )
        elif arg == 6:
            exit(0)
        else:
            print('Essa opção não existe! digite um numero entre 1 e 6')

menu()