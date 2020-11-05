import cv2

# Qtd pixels brancos
def qtdPixelWhite(img, area):
    x = 0
    for l in range(area[3]):
        for c in range(area[2]):
            if img[l][c] > 127:
                x += 1
    return x

# Processar área baseado na imagem estática
def process(img, area):
    #Pre processamento com a area de interesse
    zona = img[area[1]:area[1] + area[3], area[0]:area[0] + area[2]]
    zona = cv2.medianBlur(zona, 9, dst=None)
    zona = cv2.medianBlur(zona, 9, dst=None)
    zona = cv2.cvtColor(zona, cv2.COLOR_BGR2GRAY)
    #retorna a zona processada
    return zona


# define os locais e tamanhos da zona de interesse (para imagem estática e frames)
area_interesse = ( (500, 190, 80, 50), (450, 240, 110, 50), (400, 290, 150, 50) )
#Carrega o video e a imagem estática
captura = cv2.VideoCapture("trafego.mp4")
imgAuxiliar = cv2.imread("vazio.png")
# recorta as zonas de interesse da imagem estática
zonaEstaticaA = process(imgAuxiliar, area_interesse[0])
zonaEstaticaB = process(imgAuxiliar, area_interesse[1])
zonaEstaticaC = process(imgAuxiliar, area_interesse[2])
# loop no vídeo(pode ser uzado na captura de imagens ao vivo também)
while True:
    # Frame atual
    ret, frame = captura.read()
    # recorta as areas de interesses no frame atual
    area_A = cv2.threshold(cv2.absdiff(process(frame, area_interesse[0]), zonaEstaticaA), 45, 255, cv2.THRESH_BINARY)[1]
    area_B = cv2.threshold(cv2.absdiff(process(frame, area_interesse[1]), zonaEstaticaB), 45, 255, cv2.THRESH_BINARY)[1]
    area_C = cv2.threshold(cv2.absdiff(process(frame, area_interesse[2]), zonaEstaticaC), 45, 255, cv2.THRESH_BINARY)[1]
    # mostra ROIs
    cv2.imshow("Area A", area_A)
    cv2.imshow("Area B", area_B)
    cv2.imshow("Area C", area_C)
    # mostra as zonas de interesse em cima do frame atual
    cv2.rectangle(frame, (area_interesse[0][0], area_interesse[0][1]), (area_interesse[0][0] + area_interesse[0][2], area_interesse[0][1] + area_interesse[0][3]), (0, 128, 0), 2)
    cv2.rectangle(frame, (area_interesse[1][0], area_interesse[1][1]), (area_interesse[1][0] + area_interesse[1][2], area_interesse[1][1] + area_interesse[1][3]), (24, 88, 226), 2)
    cv2.rectangle(frame, (area_interesse[2][0], area_interesse[2][1]), (area_interesse[2][0] + area_interesse[2][2], area_interesse[2][1] + area_interesse[2][3]), (0, 0, 255), 2)
    # Verde
    if (qtdPixelWhite(area_A, area_interesse[0]) > 200 and qtdPixelWhite(area_B, area_interesse[1]) < 150 and qtdPixelWhite(area_C, area_interesse[2]) < 150):
        cv2.putText(frame, "Atencao.", (int(260), int(300)), cv2.QT_FONT_NORMAL, 1, (255, 255, 255), 2)
    # Amarelo
    elif (qtdPixelWhite(area_B, area_interesse[1]) > 200 and qtdPixelWhite(area_C, area_interesse[2]) < 150):
        cv2.putText(frame, "Reduza.", (int(260), int(300)), cv2.QT_FONT_NORMAL, 1, (255, 255, 255), 2)
    # Vermelha
    elif qtdPixelWhite(area_C, area_interesse[2]) > 200:
        cv2.putText(frame, "Pare!!!", (int(260), int(300)), cv2.QT_FONT_NORMAL, 1, (255, 255, 255), 2)
    # Mostra frame com as areas de atencao
    cv2.imshow("Processamento", frame)
    # Caso pressiona Q sai do loop e para
    if cv2.waitKey(30) & 0xFF == ord('q'):
        break
captura.release()
cv2.destroyAllWindows()