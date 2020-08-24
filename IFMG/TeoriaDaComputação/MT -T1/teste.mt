$d = '0123456789'

inicio main 01
        01 nomeMuitoGrandeMesmoComMaisDe16Letras 03
        03 moveE 02             ; Vai para o inicio
        02 X 0 d -- 02 Y 1 d    ; Escreve 1 em Y para cada 0 em X
        02 X 1 d -- 02 Y 0 d    ; Escreve 0 em Y para cada 1 em X
        02 moveD 04             ; Vai para direita
        04 aceite               ; Fim
        01 retorne
        01 aceite
        05 pare
fim main

inicio moveE 01
        01 X 0 i -- 01 X 0 e
        01 X 1 i -- 01 X 1 e
        01 X _ i -- 02 X _ d
        02 retorne
fim moveE

inicio moveD 01
        01 aceite
        01 X 0 i -- 01 X 0 d
        01 X 1 i -- 01 X 1 d
        01 X _ i -- 02 X _ e
        02 retorne
fim moveD

inicio nomeMuitoGrandeMesmoComMaisDe16Letras 01
        01 retorne
fim nomeMuitoGrandeMesmoComMaisDe16Letras