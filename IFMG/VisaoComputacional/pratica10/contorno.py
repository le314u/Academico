import	cv2


# Separa a imagem em 3 Canais
def getCanais(img):
    B,G,R = cv2.split(img)
    return{
        'blue':B,
        'green':G,
        'red':R,
    }

# recupera video
video = cv2.VideoCapture("video.mp4")
ret, frame = video.read()

while True:
    # Frame a Frame
    ret, novoFrame = video.read()
    if ret == False:
        break

    # Camada Vermelho
    c = getCanais(novoFrame)

    # Gray Scale
    imgGray = img = cv2.cvtColor(novoFrame, cv2.COLOR_BGR2GRAY)
    
    # Binarização invertida
    metodo = cv2.THRESH_BINARY_INV
    ret, imgBinarizada = cv2.threshold(imgGray,110, 255, metodo)
    
    cv2.imshow("Camada", c['blue'])
    cv2.imshow("Binari", imgBinarizada)

    # Pego contornos da área branca
    contours, hier = cv2.findContours(imgBinarizada, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

    #desenho os contornos(pegos na linha acima) baseado na mascara
    for cnt in contours:
        if cv2.contourArea(cnt) :
            cv2.drawContours(novoFrame, [cnt], -1, (0, 0, 255), 1)

    #imprimo os frame
    cv2.imshow("Final", novoFrame)
    cv2.waitKey()

    if cv2.waitKey(30) & 0xFF == ord('q'):
        break
    
    # Atualiza o frame atual
    frame = novoFrame
    
video.release()
cv2.destroyAllWindows()