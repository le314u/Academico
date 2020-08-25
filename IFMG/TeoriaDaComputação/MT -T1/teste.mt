$d = 0123456789
$c = abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ

inicio main 01
        01 moveE 02             ; Vai para o inicio
        02 X 0 d -- 02 Y 1 d    ; Escreve 1 em Y para cada 0 em X
        02 X 1 d -- 02 Y 0 d    ; Escreve 0 em Y para cada 1 em X
        03 erase 02             ; Apaga letras
        02 X $c i -- 03 X $c i  ;
        02 moveD 04             ; Vai para direita
        04 aceite               ; Fim
        01 retorne
        02 pare
fim main

inicio moveE 01
        01 X 0 i -- 01 X 0 e ; Move para esquerda
        01 X 1 i -- 01 X 1 e ; Move para esquerda
        01 X _ i -- 02 X _ d ; Volta cabeçote
        02 retorne           ; Sai do bloco
fim moveE

inicio moveD 01
        01 X 0 i -- 01 X 0 d ; Move para direita
        01 X 1 i -- 01 X 1 d ; Move para direita
        01 X _ i -- 02 X _ e ; Volta cabeçote
        02 retorne           ; Sai do bloco
fim moveD

inicio erase 01
        01 X $c i -- 01 X _ d ; Apaga $c move pra direita
        01 retorne
fim erase