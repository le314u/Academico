$d = 0123456789
$c = abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ

inicio main 01
        01 moveE 02             ; Vai para o inicios
        02 X ! i -- 03 * * i    ;
        02 X 0 d -- 02 Y 1 d    ; Escreve 1 em Y para cada 0 em X
        02 X 1 d -- 02 Y 0 d    ; Escreve 0 em Y para cada 1 em X
        03 erase 02             ; Apaga Tudo
        02 X $c d -- 02 Z $c d  ! ;
        02 moveD 05             ; Vai para direita
        05 aceite               ; Fim
        06 retorne
        07 pare
fim main

inicio moveE 01
        01 X _ i -- 02 X _ d ; Volta cabeçote
        01 X * i -- 01 X * e ; Move para esquerda
        02 retorne           ; Sai do bloco
fim moveE

inicio moveD 01
        01 X 0 i -- 01 X 0 d ; Move para direita
        01 X 1 i -- 01 X 1 d ; Move para direita
        01 X _ i -- 02 X _ e ; Volta cabeçote
        02 retorne           ; Sai do bloco
fim moveD

inicio erase 01
        01 X * i -- 02 X _ d ; Apaga $c move pra direita
        02 retorne
fim erase