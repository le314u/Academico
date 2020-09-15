; Aliases

$d = 0123456789 ;   [0-9]
$s = -+         ;   [+,-]
$e = ~          ;   [' '] porem como a fita não aceita espaço estarei representando por '~'
$f = =          ;   [=]


inicio sintatic-X 01      ; Faz analise Sintatica verificando se a entrada é valida
    01 skipSpace-X 02       ; Pula ' ' espaços
    02 number-X 03          ; Verifico se é um numero [0-9]+
    03 skipSpace-X 04       ; Pula ' ' espaços
    04 simbol-X 05          ; Verifico se é um simbolo [+,-]
    05 skipSpace-X 06       ; Pula ' ' espaços
    06 number-X 07          ; Verifico se é um numero [0-9]+
    07 skipSpace-X 08       ; Pula ' ' espaços
    08 end-X 09             ; Verifico se tem um = e é a ultima coisa
    09 retorne              ; OK
                            ; Se parar antes do Estado 10 está errado
    01 rejeite              ; Erro pois parou no meio do processo
    02 rejeite              ; Erro pois parou no meio do processo
    03 rejeite              ; Erro pois parou no meio do processo
    04 rejeite              ; Erro pois parou no meio do processo
    06 rejeite              ; Erro pois parou no meio do processo
    07 rejeite              ; Erro pois parou no meio do processo
    08 rejeite              ; Erro pois parou no meio do processo
                            ;
fim sintatic-X

inicio skipSpace-X 01         ; Verifico se é um ' '
    01 X $e i -- 01 X $e d      ; Se for um espaço eu avanço o cabeçote
    01 retorne                  ; OK
fim skipSpace-X


inicio number-X 01            ; Pula o numero [0-9]+
    01 X $d i -- 01 X $d d      ; Verifico Simbolo
    01 retorne                  ; Ok
fim number-X


inicio simbol-X 01            ; Verifico se é um [+,-]
    01 X $s i -- 02 X $s d      ; Verifico Simbolo
    02 retorne                  ; OK
    01 rejeite                  ; Erro pois parou no meio do processo
fim simbol-X


inicio end-X 01               ; Verifico se é um '='
    01 X $f i -- 02 X $f d      ; Verifico Simbolo
    02 X _ i -- 03 X _ i        ; Verifico Simbolo
    03 retorne                  ; OK
    01 rejeite                  ; Erro pois parou no meio do processo
    02 rejeite                  ; Erro pois parou no meio do processo
fim end-X


inicio brackelets-X 01       ; Reescreve a Fita X colocando os brackelets '<>'
    01 X _ i -- 02 X > e      ; Troco o primeiro espaço em branco a direita para '>'
    01 X * i -- 01 X * d      ; Vou para a direita até encontrar um espaço em branco '_'
    02 X _ i -- 03 X < i      ; Troco o primeiro espaço em branco a esquerda para '<'
    02 X * i -- 02 X * e      ; Vou para a direita até encontrar um espaço em branco '_'
    03 retorne                ; Fim do Processo
fim brackelets-X


inicio switch 01    ; POG para trocar o estado
        01 retorne      ; Retorna
fim switch


;Movimentação Fita X
    inicio moveE-X 01            ; Move para a esquerda
        01 X * i -- 02 X * e        ; Move para a esquerda
        02 retorne
    fim moveE-X

    inicio moveD-X 01            ; Move para a direita
        01 X * i -- 02 X * d        ; Move para a direita
        02 retorne
    fim moveD-X


;Movimentação Fita Y
    inicio moveE-Y 01            ; Move para a esquerda
        01 Y * i -- 02 Y * e        ; Move para a esquerda
        02 retorne
    fim moveE-Y

    inicio moveD-Y 01            ; Move para a direita
        01 Y * i -- 02 Y * d        ; Move para a direita
        02 retorne
    fim moveD-Y


;Movimentação Fita Z
    inicio moveE-Z 01            ; Move para a esquerda
        01 Z * i -- 02 Z * e        ; Move para a esquerda
        02 retorne
    fim moveE-Z

    inicio moveD-Z 01            ; Move para a direita
        01 Z * i -- 02 Z * d        ; Move para a direita
        02 retorne
    fim moveD-Z



inicio zero-Z 01        ; Verifico se o Digito está vazio
    01 moveE-Z 02           ; Move para a esquerda   
                            ; Verifico se é digito pois caso não seja significa que é zero
    02 Z $d i -- 03 Z $d d  ; Se for digito so volta o cabeçalho
    02 Z * d -- 03 Z 0 d    ; Se não for digito escrevo 0 e volto o cabeçalho
    03 retorne
fim zero-Z


inicio ignoreZero-X 01      ; Apaga os zeros inicias do numero
    01 skipSpace-X 02           ; Skipa os espaços
    02 X 0 i -- 02 X 0 d        ; Pula os 0 no inicio do digito
    02 retorne 
fim ignoreZero-X


inicio cpDigit-XZ 01      ; Transfere os digitos de X para Z
    01 skipSpace-X 02           ; Skipa os espaços
    02 X $d d -- 01 Z $d d    ; Transcreve os Digitos
    02 retorne 
fim cpDigit-XZ





inicio compile-XZ 01       ; Passa a Fita X para a Fita Z Tirando os 'espaços'

    ; Vai para o inicio da Fita X e transcreve '<'
        01 goInit-X 02 
        02 X < d -- 03 Z < d        ; Transcereve '<'

    ; Transcreve o Digito antes do simbolo
        03 ignoreZero-X 04             ; Ignora os Zeros inicias
        04 cpDigit-XZ 05               ; Transcreve os Digitos
        05 skipSpace-X 06              ; Skipa os espaços
        06 zero-Z 07                   ; Verifico se há um digito antes do simbolo caso contrario Traanscreve zero
    
    ; Transcreve o simbolo
        07 X $s d -- 08 Z $s d      ; Transcreve o simbolo

    ; Transcreve o Digito depois do simbolo
        08 ignoreZero-X 09            ; Ignora os Zeros inicias
        09 cpDigit-XZ 10              ; Transcreve os Digitos
        10 skipSpace-X 11             ; Skipa os espaços
        11 zero-Z 12                  ; Verifico se há um digito antes do simbolo caso contrario Traanscreve zero
        12 skipSpace-X 13             ; Skipa os espaços
    
    ; Transcreve o '='
        13 X $f d -- 14 Z $f d      ; Transcreve o =
    
    ; Coloca o token de fechamento na fita
        14 X > i -- 15 Z > i        ; Transcreve o >
    
    15 retorne                  ; Fim do Processo

    ; Se parar antes do Estado 11 está errado
        01 rejeite                  ; Erro pois parou no meio do processo
        02 rejeite                  ; Erro pois parou no meio do processo
        03 rejeite                  ; Erro pois parou no meio do processo
        04 rejeite                  ; Erro pois parou no meio do processo
        06 rejeite                  ; Erro pois parou no meio do processo
        07 rejeite                  ; Erro pois parou no meio do processo
        08 rejeite                  ; Erro pois parou no meio do processo
        09 rejeite                  ; Erro pois parou no meio do processo
        10 rejeite                  ; Erro pois parou no meio do processo
        11 rejeite                  ; Erro pois parou no meio do processo
        12 rejeite                  ; Erro pois parou no meio do processo
        13 rejeite                  ; Erro pois parou no meio do processo
        14 rejeite                  ; Erro pois parou no meio do processo
    
fim compile-XZ


inicio cpHalf-ZY 01            ; Copia a fita Z para Y 
    01 goInit-Z 02                 ; Vai para o inicio da Fita
    02 Z $s i -- 03 Y > i       ; Acabou de copiar
    02 Z * d -- 02 Y * d        ; Copia da esquerda para direita da fita Z para Y
    03 retorne           
fim cpHalf-ZY

inicio cp-ZY 01            ; Copia a fita Z para Y 
    01 goInit-Z 02               ; Vai para o inicio da Fita
    02 Z $s d -- 02 Y $s d       ; Acabou de copiar
    02 Z > i -- 03 Y > i         ; Acabou de copiar
    02 Z * d -- 02 Y * d         ; Copia da esquerda para direita da fita Z para Y
    03 retorne           
fim cp-ZY

; Função vai para o inicio da Fita
        inicio goInit-Z 01            ; Move a Fita para a esquerda
            01 Z < i -- 02 Z < i        ; Retorna pois chegou no token de inicio '<'
            01 Z * i -- 01 Z * e        ; Move a fita Z para esquerda
            02 retorne           
        fim goInit-Z

        inicio goInit-Y 01            ; Move a Fita para a esquerda
            01 Y < i -- 02 Y < i        ; Retorna pois chegou no token de inicio '<'
            01 Y * i -- 01 Y * e        ; Move a fita Y para esquerda
            02 retorne           
        fim goInit-Y

        inicio goInit-X 01            ; Move a Fita para a esquerda
            01 X < i -- 02 X < i        ; Retorna pois chegou no token de inicio '<'
            01 X * i -- 01 X * e        ; Move a fita X para esquerda
            02 retorne           
        fim goInit-X

; Função vai para o fim da Fita
        inicio goEnd-Z 01            ; Move a Fita para a direita
            01 Z > i -- 02 Z > i        ; Retorna pois chegou no token de termino '>'
            01 Z * i -- 01 Z * d        ; Move a fita Z para direita
            02 retorne           
        fim goEnd-Z

        inicio goEnd-Y 01            ; Move a Fita para a direita
            01 Y > i -- 02 Y > i        ; Retorna pois chegou no token de termino '>'
            01 Y * i -- 01 Y * d        ; Move a fita Y para direita
            02 retorne           
        fim goEnd-Y

        inicio goEnd-X 01            ; Move a Fita para a direita
            01 X > i -- 02 X > i        ; Retorna pois chegou no token de termino '>'
            01 X * i -- 01 X * d        ; Move a fita X para direita
            02 retorne           
        fim goEnd-X




inicio preaparaAmbiente 01   ; Prepara todo o ambiente para começar a fazer as contas
    01 brackelets-X 02          ; Reescreve a Fita X colocando <> 
    02 compile-XZ 03            ; Passa a Fita X para a Fita Z removendo os espaços e os 0 no inicio do inteiro
    03 cpHalf-ZY 04             ; Copia a Fita Z para Y
                                ; Verifica o tipo de operação
    04 retorne
fim preaparaAmbiente


    inicio posiciona-Z 01   ; Prepara todo o ambiente para começar a fazer as contas
        01 Z = i -- 02 Z = i 
        01 Z * i -- 01 Z * d 
        02 retorne
    fim posiciona-Z






; Verifico Qual A Operação
; Verifico Qual Digito É maior


inicio main 01
    ; Analisa se a entrada é valida
        01 sintatic-X 02            ; Verifico se a entrada é valida
    ; Prepara as fitas
        02 preaparaAmbiente 03      ; Prepara as Fitas
    ; Defini qual o tipo de operação
    ; Estado 1XXX Representa Soma  --   2XXX Representa Subtração
        03 Z + i -- 1000 Z + i      ; operação de SOMA
        1000 SOMA 04                ; Realiza a soma
        03 Z - i -- 2000 Z - i      ; operação de SUBTRAÇÂO
        2000 SUB 04                 ; Realiza a subtração
    ; Transcreve o resultado
        04 resultado-YZ 05               ; Fim
        05 aceite
fim main


inicio resultado-YZ 00
    ; inicio do Digito
    00 Y $d i -- 01 Y $d i ; Inicio do numero
    00 moveE-Y 00

    ;Transcreve o numero
    01 Y $d e -- 01 Z $d d ; Inicio do numero
    01 Y > i -- 02 Z > i ; Inicio do numero

    02 retorne

fim resultado-YZ


inicio SUB 9999
    9999 initSUB 00
    00 Y A i -- 01 Y A d ; A-B
    00 Y B i -- 03 Y B d ; B-A
    00 Y C i -- 01 Y C d ; C tanto faz
    ; A-B
    01 direitaNumero-YZ 02 
    02 SUB_A-B 99
    ; B-A
    03 direitaNumero-YZ 04
    04 inverte-BA 05 
    05 SUB_A-B 99
    99 retorne

fim SUB

inicio SUB_A-B 9999
    9999 switch 0000
    ; Dado a leitura de um Digito vai para o estado que representa o digito 
        ; Representação do Estado WXYZ:
        ;   W Representa se esta lendo ou escrevendo [0] Lendo [1] Escrevendo
        ;   X Repsenta qual fita esta sendo operada [0] Primeira  [1]Segunda 
        ;   Y Representa se tem numero flutuando [1] Sim [0] Não
        ;   Z Representa o que foi lido ou escrito [0-9]
        ;   
        ;   Para representar a leitura da primeira fita Z=0 pois não houve leitura anterior
         

    ; Leitura Fita 0
        0000 Y 0 i -- 0100 Y 0 i    ; Scan 0
        0000 Y 1 i -- 0101 Y 1 i    ; Scan 1
        0000 Y 2 i -- 0102 Y 2 i    ; Scan 2
        0000 Y 3 i -- 0103 Y 3 i    ; Scan 3
        0000 Y 4 i -- 0104 Y 4 i    ; Scan 4
        0000 Y 5 i -- 0105 Y 5 i    ; Scan 5
        0000 Y 6 i -- 0106 Y 6 i    ; Scan 6
        0000 Y 7 i -- 0107 Y 7 i    ; Scan 7
        0000 Y 8 i -- 0108 Y 8 i    ; Scan 8
        0000 Y 9 i -- 0109 Y 9 i    ; Scan 9
        0000 Y * i -- 0100 Y * d    ; Scan [!digito] ou seja o digito acabou portanto conseidera 0
        0010 Y 0 i -- 0110 Y 0 i    ; Scan 0
        0010 Y 1 i -- 0100 Y 1 i    ; Scan 1
        0010 Y 2 i -- 0101 Y 2 i    ; Scan 2
        0010 Y 3 i -- 0102 Y 3 i    ; Scan 3
        0010 Y 4 i -- 0103 Y 4 i    ; Scan 4
        0010 Y 5 i -- 0104 Y 5 i    ; Scan 5
        0010 Y 6 i -- 0105 Y 6 i    ; Scan 6
        0010 Y 7 i -- 0106 Y 7 i    ; Scan 7
        0010 Y 8 i -- 0107 Y 8 i    ; Scan 8
        0010 Y 9 i -- 0108 Y 9 i    ; Scan 9
        0010 Y * i -- 0100 Y * i    ; Scan [!digito] ou seja o digito acabou portanto conseidera 0


    ; Leitura Fita 1 
        0100 Z 0 i -- 1000 Z 0 e 	;  0 - 0 - 0 = 0 Pega emprestado 0
        0100 Z 1 i -- 1019 Z 1 e 	;  0 - 0 - 1 = 9 Pega emprestado 1
        0100 Z 2 i -- 1018 Z 2 e 	;  0 - 0 - 2 = 8 Pega emprestado 1
        0100 Z 3 i -- 1017 Z 3 e 	;  0 - 0 - 3 = 7 Pega emprestado 1
        0100 Z 4 i -- 1016 Z 4 e 	;  0 - 0 - 4 = 6 Pega emprestado 1
        0100 Z 5 i -- 1015 Z 5 e 	;  0 - 0 - 5 = 5 Pega emprestado 1
        0100 Z 6 i -- 1014 Z 6 e 	;  0 - 0 - 6 = 4 Pega emprestado 1
        0100 Z 7 i -- 1013 Z 7 e 	;  0 - 0 - 7 = 3 Pega emprestado 1
        0100 Z 8 i -- 1012 Z 8 e 	;  0 - 0 - 8 = 2 Pega emprestado 1
        0100 Z 9 i -- 1011 Z 9 e 	;  0 - 0 - 9 = 1 Pega emprestado 1
        0100 Z $s i -- 1000 Z $s i 	;  0 - 0 - 0 = 0 Pega emprestado 1
        0100 Z < i -- 1000 Z < i 	;  0 - 0 - 0 = 0 Pega emprestado 1

        0110 Z 0 i -- 1019 Z 0 e 	;  0 - 1 - 0 = 9 Pega emprestado 1
        0110 Z 1 i -- 1018 Z 1 e 	;  0 - 1 - 1 = 8 Pega emprestado 1
        0110 Z 2 i -- 1017 Z 2 e 	;  0 - 1 - 2 = 7 Pega emprestado 1
        0110 Z 3 i -- 1016 Z 3 e 	;  0 - 1 - 3 = 6 Pega emprestado 1
        0110 Z 4 i -- 1015 Z 4 e 	;  0 - 1 - 4 = 5 Pega emprestado 1
        0110 Z 5 i -- 1014 Z 5 e 	;  0 - 1 - 5 = 4 Pega emprestado 1
        0110 Z 6 i -- 1013 Z 6 e 	;  0 - 1 - 6 = 3 Pega emprestado 1
        0110 Z 7 i -- 1012 Z 7 e 	;  0 - 1 - 7 = 2 Pega emprestado 1
        0110 Z 8 i -- 1011 Z 8 e 	;  0 - 1 - 8 = 1 Pega emprestado 1
        0110 Z 9 i -- 1010 Z 9 e 	;  0 - 1 - 9 = 0 Pega emprestado 1
        0110 Z $s i -- 1019 Z $s i 	;  0 - 1 - 0 = -1 Pega emprestado 1
        0110 Z < i -- 1019 Z < i 	;  0 - 1 - 0 = -1 Pega emprestado 1

        0101 Z 0 i -- 1001 Z 0 e 	;  1 - 0 - 0 = 1 Pega emprestado 0
        0101 Z 1 i -- 1000 Z 1 e 	;  1 - 0 - 1 = 0 Pega emprestado 0
        0101 Z 2 i -- 1019 Z 2 e 	;  1 - 0 - 2 = 9 Pega emprestado 1
        0101 Z 3 i -- 1018 Z 3 e 	;  1 - 0 - 3 = 8 Pega emprestado 1
        0101 Z 4 i -- 1017 Z 4 e 	;  1 - 0 - 4 = 7 Pega emprestado 1
        0101 Z 5 i -- 1016 Z 5 e 	;  1 - 0 - 5 = 6 Pega emprestado 1
        0101 Z 6 i -- 1015 Z 6 e 	;  1 - 0 - 6 = 5 Pega emprestado 1
        0101 Z 7 i -- 1014 Z 7 e 	;  1 - 0 - 7 = 4 Pega emprestado 1
        0101 Z 8 i -- 1013 Z 8 e 	;  1 - 0 - 8 = 3 Pega emprestado 1
        0101 Z 9 i -- 1012 Z 9 e 	;  1 - 0 - 9 = 2 Pega emprestado 1
        0101 Z $s i -- 1001 Z $s i 	;  1 - 0 - 0 = 1 Pega emprestado 1
        0101 Z < i -- 1001 Z < i 	;  1 - 0 - 0 = 1 Pega emprestado 1

        0111 Z 0 i -- 1000 Z 0 e 	;  1 - 1 - 0 = 0 Pega emprestado 0
        0111 Z 1 i -- 1019 Z 1 e 	;  1 - 1 - 1 = 9 Pega emprestado 1
        0111 Z 2 i -- 1018 Z 2 e 	;  1 - 1 - 2 = 8 Pega emprestado 1
        0111 Z 3 i -- 1017 Z 3 e 	;  1 - 1 - 3 = 7 Pega emprestado 1
        0111 Z 4 i -- 1016 Z 4 e 	;  1 - 1 - 4 = 6 Pega emprestado 1
        0111 Z 5 i -- 1015 Z 5 e 	;  1 - 1 - 5 = 5 Pega emprestado 1
        0111 Z 6 i -- 1014 Z 6 e 	;  1 - 1 - 6 = 4 Pega emprestado 1
        0111 Z 7 i -- 1013 Z 7 e 	;  1 - 1 - 7 = 3 Pega emprestado 1
        0111 Z 8 i -- 1012 Z 8 e 	;  1 - 1 - 8 = 2 Pega emprestado 1
        0111 Z 9 i -- 1011 Z 9 e 	;  1 - 1 - 9 = 1 Pega emprestado 1
        0111 Z $s i -- 1000 Z $s i 	;  1 - 1 - 0 = 0 Pega emprestado 1
        0111 Z < i -- 1000 Z < i 	;  1 - 1 - 0 = 0 Pega emprestado 1

        0102 Z 0 i -- 1002 Z 0 e 	;  2 - 0 - 0 = 2 Pega emprestado 0
        0102 Z 1 i -- 1001 Z 1 e 	;  2 - 0 - 1 = 1 Pega emprestado 0
        0102 Z 2 i -- 1000 Z 2 e 	;  2 - 0 - 2 = 0 Pega emprestado 0
        0102 Z 3 i -- 1019 Z 3 e 	;  2 - 0 - 3 = 9 Pega emprestado 1
        0102 Z 4 i -- 1018 Z 4 e 	;  2 - 0 - 4 = 8 Pega emprestado 1
        0102 Z 5 i -- 1017 Z 5 e 	;  2 - 0 - 5 = 7 Pega emprestado 1
        0102 Z 6 i -- 1016 Z 6 e 	;  2 - 0 - 6 = 6 Pega emprestado 1
        0102 Z 7 i -- 1015 Z 7 e 	;  2 - 0 - 7 = 5 Pega emprestado 1
        0102 Z 8 i -- 1014 Z 8 e 	;  2 - 0 - 8 = 4 Pega emprestado 1
        0102 Z 9 i -- 1013 Z 9 e 	;  2 - 0 - 9 = 3 Pega emprestado 1
        0102 Z $s i -- 1002 Z $s i 	;  2 - 0 - 0 = 2 Pega emprestado 1
        0102 Z < i -- 1002 Z < i 	;  2 - 0 - 0 = 2 Pega emprestado 1

        0112 Z 0 i -- 1001 Z 0 e 	;  2 - 1 - 0 = 1 Pega emprestado 0
        0112 Z 1 i -- 1000 Z 1 e 	;  2 - 1 - 1 = 0 Pega emprestado 0
        0112 Z 2 i -- 1019 Z 2 e 	;  2 - 1 - 2 = 9 Pega emprestado 1
        0112 Z 3 i -- 1018 Z 3 e 	;  2 - 1 - 3 = 8 Pega emprestado 1
        0112 Z 4 i -- 1017 Z 4 e 	;  2 - 1 - 4 = 7 Pega emprestado 1
        0112 Z 5 i -- 1016 Z 5 e 	;  2 - 1 - 5 = 6 Pega emprestado 1
        0112 Z 6 i -- 1015 Z 6 e 	;  2 - 1 - 6 = 5 Pega emprestado 1
        0112 Z 7 i -- 1014 Z 7 e 	;  2 - 1 - 7 = 4 Pega emprestado 1
        0112 Z 8 i -- 1013 Z 8 e 	;  2 - 1 - 8 = 3 Pega emprestado 1
        0112 Z 9 i -- 1012 Z 9 e 	;  2 - 1 - 9 = 2 Pega emprestado 1
        0112 Z $s i -- 1001 Z $s i 	;  2 - 1 - 0 = 1 Pega emprestado 1
        0112 Z < i -- 1001 Z < i 	;  2 - 1 - 0 = 1 Pega emprestado 1

        0103 Z 0 i -- 1003 Z 0 e 	;  3 - 0 - 0 = 3 Pega emprestado 0
        0103 Z 1 i -- 1002 Z 1 e 	;  3 - 0 - 1 = 2 Pega emprestado 0
        0103 Z 2 i -- 1001 Z 2 e 	;  3 - 0 - 2 = 1 Pega emprestado 0
        0103 Z 3 i -- 1000 Z 3 e 	;  3 - 0 - 3 = 0 Pega emprestado 0
        0103 Z 4 i -- 1019 Z 4 e 	;  3 - 0 - 4 = 9 Pega emprestado 1
        0103 Z 5 i -- 1018 Z 5 e 	;  3 - 0 - 5 = 8 Pega emprestado 1
        0103 Z 6 i -- 1017 Z 6 e 	;  3 - 0 - 6 = 7 Pega emprestado 1
        0103 Z 7 i -- 1016 Z 7 e 	;  3 - 0 - 7 = 6 Pega emprestado 1
        0103 Z 8 i -- 1015 Z 8 e 	;  3 - 0 - 8 = 5 Pega emprestado 1
        0103 Z 9 i -- 1014 Z 9 e 	;  3 - 0 - 9 = 4 Pega emprestado 1
        0103 Z $s i -- 1003 Z $s i 	;  3 - 0 - 0 = 3 Pega emprestado 1
        0103 Z < i -- 1003 Z < i 	;  3 - 0 - 0 = 3 Pega emprestado 1

        0113 Z 0 i -- 1002 Z 0 e 	;  3 - 1 - 0 = 2 Pega emprestado 0
        0113 Z 1 i -- 1001 Z 1 e 	;  3 - 1 - 1 = 1 Pega emprestado 0
        0113 Z 2 i -- 1000 Z 2 e 	;  3 - 1 - 2 = 0 Pega emprestado 0
        0113 Z 3 i -- 1019 Z 3 e 	;  3 - 1 - 3 = 9 Pega emprestado 1
        0113 Z 4 i -- 1018 Z 4 e 	;  3 - 1 - 4 = 8 Pega emprestado 1
        0113 Z 5 i -- 1017 Z 5 e 	;  3 - 1 - 5 = 7 Pega emprestado 1
        0113 Z 6 i -- 1016 Z 6 e 	;  3 - 1 - 6 = 6 Pega emprestado 1
        0113 Z 7 i -- 1015 Z 7 e 	;  3 - 1 - 7 = 5 Pega emprestado 1
        0113 Z 8 i -- 1014 Z 8 e 	;  3 - 1 - 8 = 4 Pega emprestado 1
        0113 Z 9 i -- 1013 Z 9 e 	;  3 - 1 - 9 = 3 Pega emprestado 1
        0113 Z $s i -- 1002 Z $s i 	;  3 - 1 - 0 = 2 Pega emprestado 1
        0113 Z < i -- 1002 Z < i 	;  3 - 1 - 0 = 2 Pega emprestado 1

        0104 Z 0 i -- 1004 Z 0 e 	;  4 - 0 - 0 = 4 Pega emprestado 0
        0104 Z 1 i -- 1003 Z 1 e 	;  4 - 0 - 1 = 3 Pega emprestado 0
        0104 Z 2 i -- 1002 Z 2 e 	;  4 - 0 - 2 = 2 Pega emprestado 0
        0104 Z 3 i -- 1001 Z 3 e 	;  4 - 0 - 3 = 1 Pega emprestado 0
        0104 Z 4 i -- 1000 Z 4 e 	;  4 - 0 - 4 = 0 Pega emprestado 0
        0104 Z 5 i -- 1019 Z 5 e 	;  4 - 0 - 5 = 9 Pega emprestado 1
        0104 Z 6 i -- 1018 Z 6 e 	;  4 - 0 - 6 = 8 Pega emprestado 1
        0104 Z 7 i -- 1017 Z 7 e 	;  4 - 0 - 7 = 7 Pega emprestado 1
        0104 Z 8 i -- 1016 Z 8 e 	;  4 - 0 - 8 = 6 Pega emprestado 1
        0104 Z 9 i -- 1015 Z 9 e 	;  4 - 0 - 9 = 5 Pega emprestado 1
        0104 Z $s i -- 1004 Z $s i 	;  4 - 0 - 0 = 4 Pega emprestado 1
        0104 Z < i -- 1004 Z < i 	;  4 - 0 - 0 = 4 Pega emprestado 1

        0114 Z 0 i -- 1003 Z 0 e 	;  4 - 1 - 0 = 3 Pega emprestado 0
        0114 Z 1 i -- 1002 Z 1 e 	;  4 - 1 - 1 = 2 Pega emprestado 0
        0114 Z 2 i -- 1001 Z 2 e 	;  4 - 1 - 2 = 1 Pega emprestado 0
        0114 Z 3 i -- 1000 Z 3 e 	;  4 - 1 - 3 = 0 Pega emprestado 0
        0114 Z 4 i -- 1019 Z 4 e 	;  4 - 1 - 4 = 9 Pega emprestado 1
        0114 Z 5 i -- 1018 Z 5 e 	;  4 - 1 - 5 = 8 Pega emprestado 1
        0114 Z 6 i -- 1017 Z 6 e 	;  4 - 1 - 6 = 7 Pega emprestado 1
        0114 Z 7 i -- 1016 Z 7 e 	;  4 - 1 - 7 = 6 Pega emprestado 1
        0114 Z 8 i -- 1015 Z 8 e 	;  4 - 1 - 8 = 5 Pega emprestado 1
        0114 Z 9 i -- 1014 Z 9 e 	;  4 - 1 - 9 = 4 Pega emprestado 1
        0114 Z $s i -- 1003 Z $s i 	;  4 - 1 - 0 = 3 Pega emprestado 1
        0114 Z < i -- 1003 Z < i 	;  4 - 1 - 0 = 3 Pega emprestado 1

        0105 Z 0 i -- 1005 Z 0 e 	;  5 - 0 - 0 = 5 Pega emprestado 0
        0105 Z 1 i -- 1004 Z 1 e 	;  5 - 0 - 1 = 4 Pega emprestado 0
        0105 Z 2 i -- 1003 Z 2 e 	;  5 - 0 - 2 = 3 Pega emprestado 0
        0105 Z 3 i -- 1002 Z 3 e 	;  5 - 0 - 3 = 2 Pega emprestado 0
        0105 Z 4 i -- 1001 Z 4 e 	;  5 - 0 - 4 = 1 Pega emprestado 0
        0105 Z 5 i -- 1000 Z 5 e 	;  5 - 0 - 5 = 0 Pega emprestado 0
        0105 Z 6 i -- 1019 Z 6 e 	;  5 - 0 - 6 = 9 Pega emprestado 1
        0105 Z 7 i -- 1018 Z 7 e 	;  5 - 0 - 7 = 8 Pega emprestado 1
        0105 Z 8 i -- 1017 Z 8 e 	;  5 - 0 - 8 = 7 Pega emprestado 1
        0105 Z 9 i -- 1016 Z 9 e 	;  5 - 0 - 9 = 6 Pega emprestado 1
        0105 Z $s i -- 1005 Z $s i 	;  5 - 0 - 0 = 5 Pega emprestado 1
        0105 Z < i -- 1005 Z < i 	;  5 - 0 - 0 = 5 Pega emprestado 1

        0115 Z 0 i -- 1004 Z 0 e 	;  5 - 1 - 0 = 4 Pega emprestado 0
        0115 Z 1 i -- 1003 Z 1 e 	;  5 - 1 - 1 = 3 Pega emprestado 0
        0115 Z 2 i -- 1002 Z 2 e 	;  5 - 1 - 2 = 2 Pega emprestado 0
        0115 Z 3 i -- 1001 Z 3 e 	;  5 - 1 - 3 = 1 Pega emprestado 0
        0115 Z 4 i -- 1000 Z 4 e 	;  5 - 1 - 4 = 0 Pega emprestado 0
        0115 Z 5 i -- 1019 Z 5 e 	;  5 - 1 - 5 = 9 Pega emprestado 1
        0115 Z 6 i -- 1018 Z 6 e 	;  5 - 1 - 6 = 8 Pega emprestado 1
        0115 Z 7 i -- 1017 Z 7 e 	;  5 - 1 - 7 = 7 Pega emprestado 1
        0115 Z 8 i -- 1016 Z 8 e 	;  5 - 1 - 8 = 6 Pega emprestado 1
        0115 Z 9 i -- 1015 Z 9 e 	;  5 - 1 - 9 = 5 Pega emprestado 1
        0115 Z $s i -- 1004 Z $s i 	;  5 - 1 - 0 = 4 Pega emprestado 1
        0115 Z < i -- 1004 Z < i 	;  5 - 1 - 0 = 4 Pega emprestado 1

        0106 Z 0 i -- 1006 Z 0 e 	;  6 - 0 - 0 = 6 Pega emprestado 0
        0106 Z 1 i -- 1005 Z 1 e 	;  6 - 0 - 1 = 5 Pega emprestado 0
        0106 Z 2 i -- 1004 Z 2 e 	;  6 - 0 - 2 = 4 Pega emprestado 0
        0106 Z 3 i -- 1003 Z 3 e 	;  6 - 0 - 3 = 3 Pega emprestado 0
        0106 Z 4 i -- 1002 Z 4 e 	;  6 - 0 - 4 = 2 Pega emprestado 0
        0106 Z 5 i -- 1001 Z 5 e 	;  6 - 0 - 5 = 1 Pega emprestado 0
        0106 Z 6 i -- 1000 Z 6 e 	;  6 - 0 - 6 = 0 Pega emprestado 0
        0106 Z 7 i -- 1019 Z 7 e 	;  6 - 0 - 7 = 9 Pega emprestado 1
        0106 Z 8 i -- 1018 Z 8 e 	;  6 - 0 - 8 = 8 Pega emprestado 1
        0106 Z 9 i -- 1017 Z 9 e 	;  6 - 0 - 9 = 7 Pega emprestado 1
        0106 Z $s i -- 1006 Z $s i 	;  6 - 0 - 0 = 6 Pega emprestado 1
        0106 Z < i -- 1006 Z < i 	;  6 - 0 - 0 = 6 Pega emprestado 1

        0116 Z 0 i -- 1005 Z 0 e 	;  6 - 1 - 0 = 5 Pega emprestado 0
        0116 Z 1 i -- 1004 Z 1 e 	;  6 - 1 - 1 = 4 Pega emprestado 0
        0116 Z 2 i -- 1003 Z 2 e 	;  6 - 1 - 2 = 3 Pega emprestado 0
        0116 Z 3 i -- 1002 Z 3 e 	;  6 - 1 - 3 = 2 Pega emprestado 0
        0116 Z 4 i -- 1001 Z 4 e 	;  6 - 1 - 4 = 1 Pega emprestado 0
        0116 Z 5 i -- 1000 Z 5 e 	;  6 - 1 - 5 = 0 Pega emprestado 0
        0116 Z 6 i -- 1019 Z 6 e 	;  6 - 1 - 6 = 9 Pega emprestado 1
        0116 Z 7 i -- 1018 Z 7 e 	;  6 - 1 - 7 = 8 Pega emprestado 1
        0116 Z 8 i -- 1017 Z 8 e 	;  6 - 1 - 8 = 7 Pega emprestado 1
        0116 Z 9 i -- 1016 Z 9 e 	;  6 - 1 - 9 = 6 Pega emprestado 1
        0116 Z $s i -- 1005 Z $s i 	;  6 - 1 - 0 = 5 Pega emprestado 1
        0116 Z < i -- 1005 Z < i 	;  6 - 1 - 0 = 5 Pega emprestado 1

        0107 Z 0 i -- 1007 Z 0 e 	;  7 - 0 - 0 = 7 Pega emprestado 0
        0107 Z 1 i -- 1006 Z 1 e 	;  7 - 0 - 1 = 6 Pega emprestado 0
        0107 Z 2 i -- 1005 Z 2 e 	;  7 - 0 - 2 = 5 Pega emprestado 0
        0107 Z 3 i -- 1004 Z 3 e 	;  7 - 0 - 3 = 4 Pega emprestado 0
        0107 Z 4 i -- 1003 Z 4 e 	;  7 - 0 - 4 = 3 Pega emprestado 0
        0107 Z 5 i -- 1002 Z 5 e 	;  7 - 0 - 5 = 2 Pega emprestado 0
        0107 Z 6 i -- 1001 Z 6 e 	;  7 - 0 - 6 = 1 Pega emprestado 0
        0107 Z 7 i -- 1000 Z 7 e 	;  7 - 0 - 7 = 0 Pega emprestado 0
        0107 Z 8 i -- 1019 Z 8 e 	;  7 - 0 - 8 = 9 Pega emprestado 1
        0107 Z 9 i -- 1018 Z 9 e 	;  7 - 0 - 9 = 8 Pega emprestado 1
        0107 Z $s i -- 1007 Z $s i 	;  7 - 0 - 0 = 7 Pega emprestado 1
        0107 Z < i -- 1007 Z < i 	;  7 - 0 - 0 = 7 Pega emprestado 1

        0117 Z 0 i -- 1006 Z 0 e 	;  7 - 1 - 0 = 6 Pega emprestado 0
        0117 Z 1 i -- 1005 Z 1 e 	;  7 - 1 - 1 = 5 Pega emprestado 0
        0117 Z 2 i -- 1004 Z 2 e 	;  7 - 1 - 2 = 4 Pega emprestado 0
        0117 Z 3 i -- 1003 Z 3 e 	;  7 - 1 - 3 = 3 Pega emprestado 0
        0117 Z 4 i -- 1002 Z 4 e 	;  7 - 1 - 4 = 2 Pega emprestado 0
        0117 Z 5 i -- 1001 Z 5 e 	;  7 - 1 - 5 = 1 Pega emprestado 0
        0117 Z 6 i -- 1000 Z 6 e 	;  7 - 1 - 6 = 0 Pega emprestado 0
        0117 Z 7 i -- 1019 Z 7 e 	;  7 - 1 - 7 = 9 Pega emprestado 1
        0117 Z 8 i -- 1018 Z 8 e 	;  7 - 1 - 8 = 8 Pega emprestado 1
        0117 Z 9 i -- 1017 Z 9 e 	;  7 - 1 - 9 = 7 Pega emprestado 1
        0117 Z $s i -- 1006 Z $s i 	;  7 - 1 - 0 = 6 Pega emprestado 1
        0117 Z < i -- 1006 Z < i 	;  7 - 1 - 0 = 6 Pega emprestado 1

        0108 Z 0 i -- 1008 Z 0 e 	;  8 - 0 - 0 = 8 Pega emprestado 0
        0108 Z 1 i -- 1007 Z 1 e 	;  8 - 0 - 1 = 7 Pega emprestado 0
        0108 Z 2 i -- 1006 Z 2 e 	;  8 - 0 - 2 = 6 Pega emprestado 0
        0108 Z 3 i -- 1005 Z 3 e 	;  8 - 0 - 3 = 5 Pega emprestado 0
        0108 Z 4 i -- 1004 Z 4 e 	;  8 - 0 - 4 = 4 Pega emprestado 0
        0108 Z 5 i -- 1003 Z 5 e 	;  8 - 0 - 5 = 3 Pega emprestado 0
        0108 Z 6 i -- 1002 Z 6 e 	;  8 - 0 - 6 = 2 Pega emprestado 0
        0108 Z 7 i -- 1001 Z 7 e 	;  8 - 0 - 7 = 1 Pega emprestado 0
        0108 Z 8 i -- 1000 Z 8 e 	;  8 - 0 - 8 = 0 Pega emprestado 0
        0108 Z 9 i -- 1019 Z 9 e 	;  8 - 0 - 9 = 9 Pega emprestado 1
        0108 Z $s i -- 1008 Z $s i 	;  8 - 0 - 0 = 8 Pega emprestado 1
        0108 Z < i -- 1008 Z < i 	;  8 - 0 - 0 = 8 Pega emprestado 1

        0118 Z 0 i -- 1007 Z 0 e 	;  8 - 1 - 0 = 7 Pega emprestado 0
        0118 Z 1 i -- 1006 Z 1 e 	;  8 - 1 - 1 = 6 Pega emprestado 0
        0118 Z 2 i -- 1005 Z 2 e 	;  8 - 1 - 2 = 5 Pega emprestado 0
        0118 Z 3 i -- 1004 Z 3 e 	;  8 - 1 - 3 = 4 Pega emprestado 0
        0118 Z 4 i -- 1003 Z 4 e 	;  8 - 1 - 4 = 3 Pega emprestado 0
        0118 Z 5 i -- 1002 Z 5 e 	;  8 - 1 - 5 = 2 Pega emprestado 0
        0118 Z 6 i -- 1001 Z 6 e 	;  8 - 1 - 6 = 1 Pega emprestado 0
        0118 Z 7 i -- 1000 Z 7 e 	;  8 - 1 - 7 = 0 Pega emprestado 0
        0118 Z 8 i -- 1019 Z 8 e 	;  8 - 1 - 8 = 9 Pega emprestado 1
        0118 Z 9 i -- 1018 Z 9 e 	;  8 - 1 - 9 = 8 Pega emprestado 1
        0118 Z $s i -- 1007 Z $s i 	;  8 - 1 - 0 = 7 Pega emprestado 1
        0118 Z < i -- 1007 Z < i 	;  8 - 1 - 0 = 7 Pega emprestado 1

        0109 Z 0 i -- 1009 Z 0 e 	;  9 - 0 - 0 = 9 Pega emprestado 0
        0109 Z 1 i -- 1008 Z 1 e 	;  9 - 0 - 1 = 8 Pega emprestado 0
        0109 Z 2 i -- 1007 Z 2 e 	;  9 - 0 - 2 = 7 Pega emprestado 0
        0109 Z 3 i -- 1006 Z 3 e 	;  9 - 0 - 3 = 6 Pega emprestado 0
        0109 Z 4 i -- 1005 Z 4 e 	;  9 - 0 - 4 = 5 Pega emprestado 0
        0109 Z 5 i -- 1004 Z 5 e 	;  9 - 0 - 5 = 4 Pega emprestado 0
        0109 Z 6 i -- 1003 Z 6 e 	;  9 - 0 - 6 = 3 Pega emprestado 0
        0109 Z 7 i -- 1002 Z 7 e 	;  9 - 0 - 7 = 2 Pega emprestado 0
        0109 Z 8 i -- 1001 Z 8 e 	;  9 - 0 - 8 = 1 Pega emprestado 0
        0109 Z 9 i -- 1000 Z 9 e 	;  9 - 0 - 9 = 0 Pega emprestado 0
        0109 Z $s i -- 1009 Z $s i 	;  9 - 0 - 0 = 9 Pega emprestado 0
        0109 Z < i -- 1009 Z < i 	;  9 - 0 - 0 = 9 Pega emprestado 0

        0119 Z 0 i -- 1008 Z 0 e 	;  9 - 1 - 0 = 8 Pega emprestado 0
        0119 Z 1 i -- 1007 Z 1 e 	;  9 - 1 - 1 = 7 Pega emprestado 0
        0119 Z 2 i -- 1006 Z 2 e 	;  9 - 1 - 2 = 6 Pega emprestado 0
        0119 Z 3 i -- 1005 Z 3 e 	;  9 - 1 - 3 = 5 Pega emprestado 0
        0119 Z 4 i -- 1004 Z 4 e 	;  9 - 1 - 4 = 4 Pega emprestado 0
        0119 Z 5 i -- 1003 Z 5 e 	;  9 - 1 - 5 = 3 Pega emprestado 0
        0119 Z 6 i -- 1002 Z 6 e 	;  9 - 1 - 6 = 2 Pega emprestado 0
        0119 Z 7 i -- 1001 Z 7 e 	;  9 - 1 - 7 = 1 Pega emprestado 0
        0119 Z 8 i -- 1000 Z 8 e 	;  9 - 1 - 8 = 0 Pega emprestado 0
        0119 Z 9 i -- 1019 Z 9 e 	;  9 - 1 - 9 = 9 Pega emprestado 1
        0119 Z $s i -- 1008 Z $s i 	;  9 - 1 - 0 = 8 Pega emprestado 1
        0119 Z < i -- 1008 Z < i 	;  9 - 1 - 0 = 8 Pega emprestado 1

    ; Apos uma operação escreve na fita
        1000 write[00]-Y 9000
        1001 write[01]-Y 9000
        1002 write[02]-Y 9000
        1003 write[03]-Y 9000
        1004 write[04]-Y 9000
        1005 write[05]-Y 9000
        1006 write[06]-Y 9000
        1007 write[07]-Y 9000
        1008 write[08]-Y 9000
        1009 write[09]-Y 9000
        1010 write[10]-Y 9010
        1011 write[11]-Y 9010
        1012 write[12]-Y 9010
        1013 write[13]-Y 9010
        1014 write[14]-Y 9010
        1015 write[15]-Y 9010
        1016 write[16]-Y 9010
        1017 write[17]-Y 9010
        1018 write[18]-Y 9010
        1019 write[19]-Y 9010

        ; Verifica se o processamento acabou
        9000 switch 9001
            9001 Y < i -- 9002 Y < i
            9001 switch 0000  ; Falhou então cancela
            9002 Z $s i -- 9003 Z $s i 
            9002 Z < i -- 9003 Z < i 
            9002 switch 0000 ; Falhou então cancela
            9003 gotR_-Y 9004
            9004 gotR>-Z 9005
            9005 retorne
        9010 switch 9011
            9011 Y < i -- 9012 Y < i
            9011 switch 0010  ; Falhou então cancela
            9012 Z $s i -- 9013 Z $s i
            9012 Z < i -- 9013 Z < i 
            9012 switch 0010  ; Falhou então cancela
            9013 write[01]-Y 9000
fim SUB_A-B

inicio inverte-BA 00
    ; Apaga a fita Y
    00 goEnd-Y 01
    01 Y _ i -- 02 Y _ i ; Fita foi apagada
    01 Y * i -- 01 Y _ e ; Apaga cracter por caracter
    
    ; Vou até o simbolo
    02 Z $s i -- 03 Z $s i ; Vai até o simbolo
    02 Z * i -- 02 Z * e ; Movimenta o cabeçote

    ; Copio o elemento B para a fita Y
    03 Z $s d -- 04 Y < d;
    04 Z $d d -- 04 Y $d d 
    04 Z = d -- 05 Y > i 
    05 Z > i -- 06 Z - d
    06 Z _ i -- 07 Z > i 

    ; Aponta o cabeçote para o inicio do numero
    07 Y > i -- 08 Y > e
    08 goInit-Z 09
    09 Z $s i -- 10 Z $s e
    09 Z * i -- 09 Z * d  
    
    10 retorne
fim inverte-BA

inicio initSUB 00
    ; Inicio os ponteiros na posição mais a direita de cada numero 
    00 direitaNumero-Y 01
    01 direitaNumero-Z 02
    ; A=A-B ou B=B-A ?  C=A-B | B-A
    02 ordenFatores-Y  03
    03 retorne
fim initSUB

inicio ordenFatores-Y 99   ; Verifica qual o maior NUMERO
    ; Representação dos estado YZ
    ;   Y = Na fita Y [1] é um digito [0] não é um digito
    ;   Z = Na fita Z [1] é um digito [0] não é um digito
    ;   Para ambos [9] significa uma incognita pois ainda não ouve a leitura
        ;Leitura Primeira Fita
            99 Y $d i -- 19 Y $d e  ; Y tem um digito
            99 switch 09 ;          ; Y não tem um digito

        ;Leitura Segunda Fita
            09 Z $d i -- 01 Z $d e  ; Z tem um digito  e Y não tem logo Z>Y
            09 switch 00            ; Ambos não tem um digito
            19 Z $d i -- 11 Z $d e  ; Z tem um digito  e Y tbm 
            19 switch 10            ; Z não tem um digito  e Y tem logo Y>Z
            
            10 maiorA 9999
            01 maiorB 9999
            11 switch 99 ; Olha o proximo pois ambos são digitos
        
        ; Olha qual o maior Digito
        00 moveD-YZ 0000    

        ; Representação dos estado WXYZ
        ;   W = Se fita Y ja foi lida
        ;   X = Se fita Z ja foi lida
        ;   Y = Valor do digito na fita Y
        ;   Z = Valor do digito na fita Z

            ;Valores Iguais
            0000 Y > i -- 9900 Y > i
            9900 Z = i -- 9800 Z = i
            9800 igualC 9999

            0000 Y 0 i -- 0100 Y 0 i
            0000 Y 1 i -- 0101 Y 1 i
            0000 Y 2 i -- 0102 Y 2 i
            0000 Y 3 i -- 0103 Y 3 i
            0000 Y 4 i -- 0104 Y 4 i
            0000 Y 5 i -- 0105 Y 5 i
            0000 Y 6 i -- 0106 Y 6 i
            0000 Y 7 i -- 0107 Y 7 i
            0000 Y 8 i -- 0108 Y 8 i
            0000 Y 9 i -- 0109 Y 9 i
            0100 Z 0 i -- 1100 Z 0 i
            0101 Z 0 i -- 1101 Z 0 i
            0102 Z 0 i -- 1102 Z 0 i
            0103 Z 0 i -- 1103 Z 0 i
            0104 Z 0 i -- 1104 Z 0 i
            0105 Z 0 i -- 1105 Z 0 i
            0106 Z 0 i -- 1106 Z 0 i
            0107 Z 0 i -- 1107 Z 0 i
            0108 Z 0 i -- 1108 Z 0 i
            0109 Z 0 i -- 1109 Z 0 i
            0100 Z 1 i -- 1110 Z 1 i
            0101 Z 1 i -- 1111 Z 1 i
            0102 Z 1 i -- 1112 Z 1 i
            0103 Z 1 i -- 1113 Z 1 i
            0104 Z 1 i -- 1114 Z 1 i
            0105 Z 1 i -- 1115 Z 1 i
            0106 Z 1 i -- 1116 Z 1 i
            0107 Z 1 i -- 1117 Z 1 i
            0108 Z 1 i -- 1118 Z 1 i
            0109 Z 1 i -- 1119 Z 1 i
            0100 Z 2 i -- 1120 Z 2 i
            0101 Z 2 i -- 1121 Z 2 i
            0102 Z 2 i -- 1122 Z 2 i
            0103 Z 2 i -- 1123 Z 2 i
            0104 Z 2 i -- 1124 Z 2 i
            0105 Z 2 i -- 1125 Z 2 i
            0106 Z 2 i -- 1126 Z 2 i
            0107 Z 2 i -- 1127 Z 2 i
            0108 Z 2 i -- 1128 Z 2 i
            0109 Z 2 i -- 1129 Z 2 i
            0100 Z 3 i -- 1130 Z 3 i
            0101 Z 3 i -- 1131 Z 3 i
            0102 Z 3 i -- 1132 Z 3 i
            0103 Z 3 i -- 1133 Z 3 i
            0104 Z 3 i -- 1134 Z 3 i
            0105 Z 3 i -- 1135 Z 3 i
            0106 Z 3 i -- 1136 Z 3 i
            0107 Z 3 i -- 1137 Z 3 i
            0108 Z 3 i -- 1138 Z 3 i
            0109 Z 3 i -- 1139 Z 3 i
            0100 Z 4 i -- 1140 Z 4 i
            0101 Z 4 i -- 1141 Z 4 i
            0102 Z 4 i -- 1142 Z 4 i
            0103 Z 4 i -- 1143 Z 4 i
            0104 Z 4 i -- 1144 Z 4 i
            0105 Z 4 i -- 1145 Z 4 i
            0106 Z 4 i -- 1146 Z 4 i
            0107 Z 4 i -- 1147 Z 4 i
            0108 Z 4 i -- 1148 Z 4 i
            0109 Z 4 i -- 1149 Z 4 i
            0100 Z 5 i -- 1150 Z 5 i
            0101 Z 5 i -- 1151 Z 5 i
            0102 Z 5 i -- 1152 Z 5 i
            0103 Z 5 i -- 1153 Z 5 i
            0104 Z 5 i -- 1154 Z 5 i
            0105 Z 5 i -- 1155 Z 5 i
            0106 Z 5 i -- 1156 Z 5 i
            0107 Z 5 i -- 1157 Z 5 i
            0108 Z 5 i -- 1158 Z 5 i
            0109 Z 5 i -- 1159 Z 5 i
            0100 Z 6 i -- 1160 Z 6 i
            0101 Z 6 i -- 1161 Z 6 i
            0102 Z 6 i -- 1162 Z 6 i
            0103 Z 6 i -- 1163 Z 6 i
            0104 Z 6 i -- 1164 Z 6 i
            0105 Z 6 i -- 1165 Z 6 i
            0106 Z 6 i -- 1166 Z 6 i
            0107 Z 6 i -- 1167 Z 6 i
            0108 Z 6 i -- 1168 Z 6 i
            0109 Z 6 i -- 1169 Z 6 i
            0100 Z 7 i -- 1170 Z 7 i
            0101 Z 7 i -- 1171 Z 7 i
            0102 Z 7 i -- 1172 Z 7 i
            0103 Z 7 i -- 1173 Z 7 i
            0104 Z 7 i -- 1174 Z 7 i
            0105 Z 7 i -- 1175 Z 7 i
            0106 Z 7 i -- 1176 Z 7 i
            0107 Z 7 i -- 1177 Z 7 i
            0108 Z 7 i -- 1178 Z 7 i
            0109 Z 7 i -- 1179 Z 7 i
            0100 Z 8 i -- 1180 Z 8 i
            0101 Z 8 i -- 1181 Z 8 i
            0102 Z 8 i -- 1182 Z 8 i
            0103 Z 8 i -- 1183 Z 8 i
            0104 Z 8 i -- 1184 Z 8 i
            0105 Z 8 i -- 1185 Z 8 i
            0106 Z 8 i -- 1186 Z 8 i
            0107 Z 8 i -- 1187 Z 8 i
            0108 Z 8 i -- 1188 Z 8 i
            0109 Z 8 i -- 1189 Z 8 i
            0100 Z 9 i -- 1190 Z 9 i
            0101 Z 9 i -- 1191 Z 9 i
            0102 Z 9 i -- 1192 Z 9 i
            0103 Z 9 i -- 1193 Z 9 i
            0104 Z 9 i -- 1194 Z 9 i
            0105 Z 9 i -- 1195 Z 9 i
            0106 Z 9 i -- 1196 Z 9 i
            0107 Z 9 i -- 1197 Z 9 i
            0108 Z 9 i -- 1198 Z 9 i
            0109 Z 9 i -- 1199 Z 9 i

            ;Escreve na Fita qual o maior Numero
            1100 switch 00
            1101 maiorA 9999
            1102 maiorA 9999
            1103 maiorA 9999
            1104 maiorA 9999
            1105 maiorA 9999
            1106 maiorA 9999
            1107 maiorA 9999
            1108 maiorA 9999
            1109 maiorA 9999
            1110 maiorB 9999
            1111 switch 00
            1112 maiorA 9999
            1113 maiorA 9999
            1114 maiorA 9999
            1115 maiorA 9999
            1116 maiorA 9999
            1117 maiorA 9999
            1118 maiorA 9999
            1119 maiorA 9999
            1120 maiorB 9999
            1121 maiorB 9999
            1122 switch 00
            1123 maiorA 9999
            1124 maiorA 9999
            1125 maiorA 9999
            1126 maiorA 9999
            1127 maiorA 9999
            1128 maiorA 9999
            1129 maiorA 9999
            1130 maiorB 9999
            1131 maiorB 9999
            1132 maiorB 9999
            1133 switch 00
            1134 maiorA 9999
            1135 maiorA 9999
            1136 maiorA 9999
            1137 maiorA 9999
            1138 maiorA 9999
            1139 maiorA 9999
            1140 maiorB 9999
            1141 maiorB 9999
            1142 maiorB 9999
            1143 maiorB 9999
            1144 switch 00
            1145 maiorA 9999
            1146 maiorA 9999
            1147 maiorA 9999
            1148 maiorA 9999
            1149 maiorA 9999
            1150 maiorB 9999
            1151 maiorB 9999
            1152 maiorB 9999
            1153 maiorB 9999
            1154 maiorB 9999
            1155 switch 00
            1156 maiorA 9999
            1157 maiorA 9999
            1158 maiorA 9999
            1159 maiorA 9999
            1160 maiorB 9999
            1161 maiorB 9999
            1162 maiorB 9999
            1163 maiorB 9999
            1164 maiorB 9999
            1165 maiorB 9999
            1166 switch 00
            1167 maiorA 9999
            1168 maiorA 9999
            1169 maiorA 9999
            1170 maiorB 9999
            1171 maiorB 9999
            1172 maiorB 9999
            1173 maiorB 9999
            1174 maiorB 9999
            1175 maiorB 9999
            1176 maiorB 9999
            1177 switch 00
            1178 maiorA 9999
            1179 maiorA 9999
            1180 maiorB 9999
            1181 maiorB 9999
            1182 maiorB 9999
            1183 maiorB 9999
            1184 maiorB 9999
            1185 maiorB 9999
            1186 maiorB 9999
            1187 maiorB 9999
            1188 switch 00
            1189 maiorA 9999
            1190 maiorB 9999
            1191 maiorB 9999
            1192 maiorB 9999
            1193 maiorB 9999
            1194 maiorB 9999
            1195 maiorB 9999
            1196 maiorB 9999
            1197 maiorB 9999
            1198 maiorB 9999
            1199 switch 00

            9999 retorne
fim ordenFatores-Y

inicio moveD-YZ 00
    00 moveD-Z 01
    01 moveD-Y 02
    02 retorne
fim moveD-YZ

inicio maiorA 00
    00 goInit-Y 01
    01 Y < i -- 02 Y < e
    02 Y _ i -- 03 Y A i
    02 rejeite
    03 retorne
fim maiorA

inicio maiorB 00
    00 goInit-Y 01
    01 Y < i -- 02 Y < e
    02 Y _ i -- 03 Y B i
    03 retorne
fim maiorB

inicio igualC 00
    00 goInit-Y 01
    01 Y < i -- 02 Y < e
    02 Y _ i -- 03 Y C i
    03 retorne
fim igualC

inicio esquerdaNumero-Y 0000
    0000 goInit-Y 0001               ; Vai apra o inicio da fita
    0001 Y $d i -- 0002 Y $d i       ; Chegou no digito
    0001 moveD-Y 0001
    0002 retorne
fim esquerdaNumero-Y

inicio esquerdaNumero-Z 0000
    0000 goEnd-Z 0001                ; Vai para o final da fita
    0001 Z $s i -- 0002 Z $s d       ; Chegou no Simbolo
    0001 moveE-Z 0001                ; Move para esquerda até chegar no digito
    0002 retorne
fim esquerdaNumero-Z

inicio direitaNumero-YZ 00
    00 direitaNumero-Y 01
    01 direitaNumero-Z 02
    02 retorne
fim direitaNumero-YZ

inicio direitaNumero-Y 00
    00 goEnd-Y 01               ; Vai apra o Fim da fita
    01 Y $d i -- 02 Y $d i      ; Chegou no digito
    01 moveE-Y 01               ; Move para esquerda até chegar no digito
    02 retorne
fim direitaNumero-Y

inicio direitaNumero-Z 00
    00 goEnd-Z 01               ; Vai apra o Fim da fita
    01 Z $d i -- 02 Z $d i      ; Chegou no digito
    01 moveE-Z 01               ; Move para esquerda até chegar no digito
    02 retorne
fim direitaNumero-Z

    inicio SOMA 9999   ; Prepara todo o ambiente para começar a fazer as contas
        ; Inicio os ponteiros na posição mais a direita de cada numero 
        9999 direitaNumero-YZ 0000
        
        ; Dado a leitura de um Digito vai para o estado que representa o digito 
        ; Representação do Estado WXYZ:
        ;   W Representa se esta lendo ou escrevendo [0] Lendo [1] Escrevendo
        ;   X Repsenta qual fita esta sendo operada [0] Primeira  [1]Segunda 
        ;   Y Representa se tem numero flutuando [1] Sim [0] Não
        ;   Z Representa o que foi lido ou escrito [0-9]
        ;   
        ;   Para representar a leitura da primeira fita Z=0 pois não houve leitura anterior
         
        
        ; Leitura Fita 0
        0000 Y 0 i -- 0100 Y 0 i    ; Scan 0
        0000 Y 1 i -- 0101 Y 1 i    ; Scan 1
        0000 Y 2 i -- 0102 Y 2 i    ; Scan 2
        0000 Y 3 i -- 0103 Y 3 i    ; Scan 3
        0000 Y 4 i -- 0104 Y 4 i    ; Scan 4
        0000 Y 5 i -- 0105 Y 5 i    ; Scan 5
        0000 Y 6 i -- 0106 Y 6 i    ; Scan 6
        0000 Y 7 i -- 0107 Y 7 i    ; Scan 7
        0000 Y 8 i -- 0108 Y 8 i    ; Scan 8
        0000 Y 9 i -- 0109 Y 9 i    ; Scan 9
        0000 Y * i -- 0100 Y * d    ; Scan [!digito] ou seja o digito acabou portanto conseidera 0
        0010 Y 0 i -- 0101 Y 0 i    ; Scan 0
        0010 Y 1 i -- 0102 Y 1 i    ; Scan 1
        0010 Y 2 i -- 0103 Y 2 i    ; Scan 2
        0010 Y 3 i -- 0104 Y 3 i    ; Scan 3
        0010 Y 4 i -- 0105 Y 4 i    ; Scan 4
        0010 Y 5 i -- 0106 Y 5 i    ; Scan 5
        0010 Y 6 i -- 0107 Y 6 i    ; Scan 6
        0010 Y 7 i -- 0108 Y 7 i    ; Scan 7
        0010 Y 8 i -- 0109 Y 8 i    ; Scan 8
        0010 Y 9 i -- 0110 Y 9 i    ; Scan 9
        0010 Y * i -- 0101 Y * d    ; Scan [!digito] ou seja o digito acabou portanto conseidera 0
        
        ;Leitura Fita 1
        0100 Z 0 i -- 1000 Z 0 e 	;  0 + 0 + 0 = 0
        0100 Z 1 i -- 1001 Z 1 e 	;  0 + 0 + 1 = 1
        0100 Z 2 i -- 1002 Z 2 e 	;  0 + 0 + 2 = 2
        0100 Z 3 i -- 1003 Z 3 e 	;  0 + 0 + 3 = 3
        0100 Z 4 i -- 1004 Z 4 e 	;  0 + 0 + 4 = 4
        0100 Z 5 i -- 1005 Z 5 e 	;  0 + 0 + 5 = 5
        0100 Z 6 i -- 1006 Z 6 e 	;  0 + 0 + 6 = 6
        0100 Z 7 i -- 1007 Z 7 e 	;  0 + 0 + 7 = 7
        0100 Z 8 i -- 1008 Z 8 e 	;  0 + 0 + 8 = 8
        0100 Z 9 i -- 1009 Z 9 e 	;  0 + 0 + 9 = 9
        0110 Z 0 i -- 1001 Z 0 e 	;  0 + 1 + 0 = 1
        0110 Z 1 i -- 1002 Z 1 e 	;  0 + 1 + 1 = 2
        0110 Z 2 i -- 1003 Z 2 e 	;  0 + 1 + 2 = 3
        0110 Z 3 i -- 1004 Z 3 e 	;  0 + 1 + 3 = 4
        0110 Z 4 i -- 1005 Z 4 e 	;  0 + 1 + 4 = 5
        0110 Z 5 i -- 1006 Z 5 e 	;  0 + 1 + 5 = 6
        0110 Z 6 i -- 1007 Z 6 e 	;  0 + 1 + 6 = 7
        0110 Z 7 i -- 1008 Z 7 e 	;  0 + 1 + 7 = 8
        0110 Z 8 i -- 1009 Z 8 e 	;  0 + 1 + 8 = 9
        0110 Z 9 i -- 1010 Z 9 e 	;  0 + 1 + 9 = 10
        0100 Z $s i -- 1000 Z $s i 	;  Fita Z Vazia
        0110 Z $s i -- 1010 Z $s i 	;  Fita Z Vazia

        0101 Z 0 i -- 1001 Z 0 e 	;  1 + 0 + 0 = 1
        0101 Z 1 i -- 1002 Z 1 e 	;  1 + 0 + 1 = 2
        0101 Z 2 i -- 1003 Z 2 e 	;  1 + 0 + 2 = 3
        0101 Z 3 i -- 1004 Z 3 e 	;  1 + 0 + 3 = 4
        0101 Z 4 i -- 1005 Z 4 e 	;  1 + 0 + 4 = 5
        0101 Z 5 i -- 1006 Z 5 e 	;  1 + 0 + 5 = 6
        0101 Z 6 i -- 1007 Z 6 e 	;  1 + 0 + 6 = 7
        0101 Z 7 i -- 1008 Z 7 e 	;  1 + 0 + 7 = 8
        0101 Z 8 i -- 1009 Z 8 e 	;  1 + 0 + 8 = 9
        0101 Z 9 i -- 1010 Z 9 e 	;  1 + 0 + 9 = 10
        0111 Z 0 i -- 1002 Z 0 e 	;  1 + 1 + 0 = 2
        0111 Z 1 i -- 1003 Z 1 e 	;  1 + 1 + 1 = 3
        0111 Z 2 i -- 1004 Z 2 e 	;  1 + 1 + 2 = 4
        0111 Z 3 i -- 1005 Z 3 e 	;  1 + 1 + 3 = 5
        0111 Z 4 i -- 1006 Z 4 e 	;  1 + 1 + 4 = 6
        0111 Z 5 i -- 1007 Z 5 e 	;  1 + 1 + 5 = 7
        0111 Z 6 i -- 1008 Z 6 e 	;  1 + 1 + 6 = 8
        0111 Z 7 i -- 1009 Z 7 e 	;  1 + 1 + 7 = 9
        0111 Z 8 i -- 1010 Z 8 e 	;  1 + 1 + 8 = 10
        0111 Z 9 i -- 1011 Z 9 e 	;  1 + 1 + 9 = 11
        0101 Z $s i -- 1001 Z $s i 	;  Fita Z Vazia
        0111 Z $s i -- 1011 Z $s i 	;  Fita Z Vazia
        
        0102 Z 0 i -- 1002 Z 0 e 	;  2 + 0 + 0 = 2
        0102 Z 1 i -- 1003 Z 1 e 	;  2 + 0 + 1 = 3
        0102 Z 2 i -- 1004 Z 2 e 	;  2 + 0 + 2 = 4
        0102 Z 3 i -- 1005 Z 3 e 	;  2 + 0 + 3 = 5
        0102 Z 4 i -- 1006 Z 4 e 	;  2 + 0 + 4 = 6
        0102 Z 5 i -- 1007 Z 5 e 	;  2 + 0 + 5 = 7
        0102 Z 6 i -- 1008 Z 6 e 	;  2 + 0 + 6 = 8
        0102 Z 7 i -- 1009 Z 7 e 	;  2 + 0 + 7 = 9
        0102 Z 8 i -- 1010 Z 8 e 	;  2 + 0 + 8 = 10
        0102 Z 9 i -- 1011 Z 9 e 	;  2 + 0 + 9 = 11
        0112 Z 0 i -- 1003 Z 0 e 	;  2 + 1 + 0 = 3
        0112 Z 1 i -- 1004 Z 1 e 	;  2 + 1 + 1 = 4
        0112 Z 2 i -- 1005 Z 2 e 	;  2 + 1 + 2 = 5
        0112 Z 3 i -- 1006 Z 3 e 	;  2 + 1 + 3 = 6
        0112 Z 4 i -- 1007 Z 4 e 	;  2 + 1 + 4 = 7
        0112 Z 5 i -- 1008 Z 5 e 	;  2 + 1 + 5 = 8
        0112 Z 6 i -- 1009 Z 6 e 	;  2 + 1 + 6 = 9
        0112 Z 7 i -- 1010 Z 7 e 	;  2 + 1 + 7 = 10
        0112 Z 8 i -- 1011 Z 8 e 	;  2 + 1 + 8 = 11
        0112 Z 9 i -- 1012 Z 9 e 	;  2 + 1 + 9 = 12
        0102 Z $s i -- 1002 Z $s i 	;  Fita Z Vazia
        0112 Z $s i -- 1012 Z $s i 	;  Fita Z Vazia

        0103 Z 0 i -- 1003 Z 0 e 	;  3 + 0 + 0 = 3
        0103 Z 1 i -- 1004 Z 1 e 	;  3 + 0 + 1 = 4
        0103 Z 2 i -- 1005 Z 2 e 	;  3 + 0 + 2 = 5
        0103 Z 3 i -- 1006 Z 3 e 	;  3 + 0 + 3 = 6
        0103 Z 4 i -- 1007 Z 4 e 	;  3 + 0 + 4 = 7
        0103 Z 5 i -- 1008 Z 5 e 	;  3 + 0 + 5 = 8
        0103 Z 6 i -- 1009 Z 6 e 	;  3 + 0 + 6 = 9
        0103 Z 7 i -- 1010 Z 7 e 	;  3 + 0 + 7 = 10
        0103 Z 8 i -- 1011 Z 8 e 	;  3 + 0 + 8 = 11
        0103 Z 9 i -- 1012 Z 9 e 	;  3 + 0 + 9 = 12
        0113 Z 0 i -- 1004 Z 0 e 	;  3 + 1 + 0 = 4
        0113 Z 1 i -- 1005 Z 1 e 	;  3 + 1 + 1 = 5
        0113 Z 2 i -- 1006 Z 2 e 	;  3 + 1 + 2 = 6
        0113 Z 3 i -- 1007 Z 3 e 	;  3 + 1 + 3 = 7
        0113 Z 4 i -- 1008 Z 4 e 	;  3 + 1 + 4 = 8
        0113 Z 5 i -- 1009 Z 5 e 	;  3 + 1 + 5 = 9
        0113 Z 6 i -- 1010 Z 6 e 	;  3 + 1 + 6 = 10
        0113 Z 7 i -- 1011 Z 7 e 	;  3 + 1 + 7 = 11
        0113 Z 8 i -- 1012 Z 8 e 	;  3 + 1 + 8 = 12
        0113 Z 9 i -- 1013 Z 9 e 	;  3 + 1 + 9 = 13
        0103 Z $s i -- 1003 Z $s i 	;  Fita Z Vazia
        0113 Z $s i -- 1013 Z $s i 	;  Fita Z Vazia

        0104 Z 0 i -- 1004 Z 0 e 	;  4 + 0 + 0 = 4
        0104 Z 1 i -- 1005 Z 1 e 	;  4 + 0 + 1 = 5
        0104 Z 2 i -- 1006 Z 2 e 	;  4 + 0 + 2 = 6
        0104 Z 3 i -- 1007 Z 3 e 	;  4 + 0 + 3 = 7
        0104 Z 4 i -- 1008 Z 4 e 	;  4 + 0 + 4 = 8
        0104 Z 5 i -- 1009 Z 5 e 	;  4 + 0 + 5 = 9
        0104 Z 6 i -- 1010 Z 6 e 	;  4 + 0 + 6 = 10
        0104 Z 7 i -- 1011 Z 7 e 	;  4 + 0 + 7 = 11
        0104 Z 8 i -- 1012 Z 8 e 	;  4 + 0 + 8 = 12
        0104 Z 9 i -- 1013 Z 9 e 	;  4 + 0 + 9 = 13
        0114 Z 0 i -- 1005 Z 0 e 	;  4 + 1 + 0 = 5
        0114 Z 1 i -- 1006 Z 1 e 	;  4 + 1 + 1 = 6
        0114 Z 2 i -- 1007 Z 2 e 	;  4 + 1 + 2 = 7
        0114 Z 3 i -- 1008 Z 3 e 	;  4 + 1 + 3 = 8
        0114 Z 4 i -- 1009 Z 4 e 	;  4 + 1 + 4 = 9
        0114 Z 5 i -- 1010 Z 5 e 	;  4 + 1 + 5 = 10
        0114 Z 6 i -- 1011 Z 6 e 	;  4 + 1 + 6 = 11
        0114 Z 7 i -- 1012 Z 7 e 	;  4 + 1 + 7 = 12
        0114 Z 8 i -- 1013 Z 8 e 	;  4 + 1 + 8 = 13
        0114 Z 9 i -- 1014 Z 9 e 	;  4 + 1 + 9 = 14
        0104 Z $s i -- 1004 Z $s i 	;  Fita Z Vazia
        0114 Z $s i -- 1014 Z $s i 	;  Fita Z Vazia

        0105 Z 0 i -- 1005 Z 0 e 	;  5 + 0 + 0 = 5
        0105 Z 1 i -- 1006 Z 1 e 	;  5 + 0 + 1 = 6
        0105 Z 2 i -- 1007 Z 2 e 	;  5 + 0 + 2 = 7
        0105 Z 3 i -- 1008 Z 3 e 	;  5 + 0 + 3 = 8
        0105 Z 4 i -- 1009 Z 4 e 	;  5 + 0 + 4 = 9
        0105 Z 5 i -- 1010 Z 5 e 	;  5 + 0 + 5 = 10
        0105 Z 6 i -- 1011 Z 6 e 	;  5 + 0 + 6 = 11
        0105 Z 7 i -- 1012 Z 7 e 	;  5 + 0 + 7 = 12
        0105 Z 8 i -- 1013 Z 8 e 	;  5 + 0 + 8 = 13
        0105 Z 9 i -- 1014 Z 9 e 	;  5 + 0 + 9 = 14
        0115 Z 0 i -- 1006 Z 0 e 	;  5 + 1 + 0 = 6
        0115 Z 1 i -- 1007 Z 1 e 	;  5 + 1 + 1 = 7
        0115 Z 2 i -- 1008 Z 2 e 	;  5 + 1 + 2 = 8
        0115 Z 3 i -- 1009 Z 3 e 	;  5 + 1 + 3 = 9
        0115 Z 4 i -- 1010 Z 4 e 	;  5 + 1 + 4 = 10
        0115 Z 5 i -- 1011 Z 5 e 	;  5 + 1 + 5 = 11
        0115 Z 6 i -- 1012 Z 6 e 	;  5 + 1 + 6 = 12
        0115 Z 7 i -- 1013 Z 7 e 	;  5 + 1 + 7 = 13
        0115 Z 8 i -- 1014 Z 8 e 	;  5 + 1 + 8 = 14
        0115 Z 9 i -- 1015 Z 9 e 	;  5 + 1 + 9 = 15
        0105 Z $s i -- 1005 Z $s i 	;  Fita Z Vazia
        0115 Z $s i -- 1015 Z $s i 	;  Fita Z Vazia

        0106 Z 0 i -- 1006 Z 0 e 	;  6 + 0 + 0 = 6
        0106 Z 1 i -- 1007 Z 1 e 	;  6 + 0 + 1 = 7
        0106 Z 2 i -- 1008 Z 2 e 	;  6 + 0 + 2 = 8
        0106 Z 3 i -- 1009 Z 3 e 	;  6 + 0 + 3 = 9
        0106 Z 4 i -- 1010 Z 4 e 	;  6 + 0 + 4 = 10
        0106 Z 5 i -- 1011 Z 5 e 	;  6 + 0 + 5 = 11
        0106 Z 6 i -- 1012 Z 6 e 	;  6 + 0 + 6 = 12
        0106 Z 7 i -- 1013 Z 7 e 	;  6 + 0 + 7 = 13
        0106 Z 8 i -- 1014 Z 8 e 	;  6 + 0 + 8 = 14
        0106 Z 9 i -- 1015 Z 9 e 	;  6 + 0 + 9 = 15
        0116 Z 0 i -- 1007 Z 0 e 	;  6 + 1 + 0 = 7
        0116 Z 1 i -- 1008 Z 1 e 	;  6 + 1 + 1 = 8
        0116 Z 2 i -- 1009 Z 2 e 	;  6 + 1 + 2 = 9
        0116 Z 3 i -- 1010 Z 3 e 	;  6 + 1 + 3 = 10
        0116 Z 4 i -- 1011 Z 4 e 	;  6 + 1 + 4 = 11
        0116 Z 5 i -- 1012 Z 5 e 	;  6 + 1 + 5 = 12
        0116 Z 6 i -- 1013 Z 6 e 	;  6 + 1 + 6 = 13
        0116 Z 7 i -- 1014 Z 7 e 	;  6 + 1 + 7 = 14
        0116 Z 8 i -- 1015 Z 8 e 	;  6 + 1 + 8 = 15
        0116 Z 9 i -- 1016 Z 9 e 	;  6 + 1 + 9 = 16
        0106 Z $s i -- 1006 Z $s i 	;  Fita Z Vazia
        0116 Z $s i -- 1016 Z $s i 	;  Fita Z Vazia

        0107 Z 0 i -- 1007 Z 0 e 	;  7 + 0 + 0 = 7
        0107 Z 1 i -- 1008 Z 1 e 	;  7 + 0 + 1 = 8
        0107 Z 2 i -- 1009 Z 2 e 	;  7 + 0 + 2 = 9
        0107 Z 3 i -- 1010 Z 3 e 	;  7 + 0 + 3 = 10
        0107 Z 4 i -- 1011 Z 4 e 	;  7 + 0 + 4 = 11
        0107 Z 5 i -- 1012 Z 5 e 	;  7 + 0 + 5 = 12
        0107 Z 6 i -- 1013 Z 6 e 	;  7 + 0 + 6 = 13
        0107 Z 7 i -- 1014 Z 7 e 	;  7 + 0 + 7 = 14
        0107 Z 8 i -- 1015 Z 8 e 	;  7 + 0 + 8 = 15
        0107 Z 9 i -- 1016 Z 9 e 	;  7 + 0 + 9 = 16
        0117 Z 0 i -- 1008 Z 0 e 	;  7 + 1 + 0 = 8
        0117 Z 1 i -- 1009 Z 1 e 	;  7 + 1 + 1 = 9
        0117 Z 2 i -- 1010 Z 2 e 	;  7 + 1 + 2 = 10
        0117 Z 3 i -- 1011 Z 3 e 	;  7 + 1 + 3 = 11
        0117 Z 4 i -- 1012 Z 4 e 	;  7 + 1 + 4 = 12
        0117 Z 5 i -- 1013 Z 5 e 	;  7 + 1 + 5 = 13
        0117 Z 6 i -- 1014 Z 6 e 	;  7 + 1 + 6 = 14
        0117 Z 7 i -- 1015 Z 7 e 	;  7 + 1 + 7 = 15
        0117 Z 8 i -- 1016 Z 8 e 	;  7 + 1 + 8 = 16
        0117 Z 9 i -- 1017 Z 9 e 	;  7 + 1 + 9 = 17
        0107 Z $s i -- 1007 Z $s i 	;  Fita Z Vazia
        0117 Z $s i -- 1017 Z $s i 	;  Fita Z Vazia

        0108 Z 0 i -- 1008 Z 0 e 	;  8 + 0 + 0 = 8
        0108 Z 1 i -- 1009 Z 1 e 	;  8 + 0 + 1 = 9
        0108 Z 2 i -- 1010 Z 2 e 	;  8 + 0 + 2 = 10
        0108 Z 3 i -- 1011 Z 3 e 	;  8 + 0 + 3 = 11
        0108 Z 4 i -- 1012 Z 4 e 	;  8 + 0 + 4 = 12
        0108 Z 5 i -- 1013 Z 5 e 	;  8 + 0 + 5 = 13
        0108 Z 6 i -- 1014 Z 6 e 	;  8 + 0 + 6 = 14
        0108 Z 7 i -- 1015 Z 7 e 	;  8 + 0 + 7 = 15
        0108 Z 8 i -- 1016 Z 8 e 	;  8 + 0 + 8 = 16
        0108 Z 9 i -- 1017 Z 9 e 	;  8 + 0 + 9 = 17
        0118 Z 0 i -- 1009 Z 0 e 	;  8 + 1 + 0 = 9
        0118 Z 1 i -- 1010 Z 1 e 	;  8 + 1 + 1 = 10
        0118 Z 2 i -- 1011 Z 2 e 	;  8 + 1 + 2 = 11
        0118 Z 3 i -- 1012 Z 3 e 	;  8 + 1 + 3 = 12
        0118 Z 4 i -- 1013 Z 4 e 	;  8 + 1 + 4 = 13
        0118 Z 5 i -- 1014 Z 5 e 	;  8 + 1 + 5 = 14
        0118 Z 6 i -- 1015 Z 6 e 	;  8 + 1 + 6 = 15
        0118 Z 7 i -- 1016 Z 7 e 	;  8 + 1 + 7 = 16
        0118 Z 8 i -- 1017 Z 8 e 	;  8 + 1 + 8 = 17
        0118 Z 9 i -- 1018 Z 9 e 	;  8 + 1 + 9 = 18
        0108 Z $s i -- 1008 Z $s i 	;  Fita Z Vazia
        0118 Z $s i -- 1018 Z $s i 	;  Fita Z Vazia

        0109 Z 0 i -- 1009 Z 0 e 	;  9 + 0 + 0 = 9
        0109 Z 1 i -- 1010 Z 1 e 	;  9 + 0 + 1 = 10
        0109 Z 2 i -- 1011 Z 2 e 	;  9 + 0 + 2 = 11
        0109 Z 3 i -- 1012 Z 3 e 	;  9 + 0 + 3 = 12
        0109 Z 4 i -- 1013 Z 4 e 	;  9 + 0 + 4 = 13
        0109 Z 5 i -- 1014 Z 5 e 	;  9 + 0 + 5 = 14
        0109 Z 6 i -- 1015 Z 6 e 	;  9 + 0 + 6 = 15
        0109 Z 7 i -- 1016 Z 7 e 	;  9 + 0 + 7 = 16
        0109 Z 8 i -- 1017 Z 8 e 	;  9 + 0 + 8 = 17
        0109 Z 9 i -- 1018 Z 9 e 	;  9 + 0 + 9 = 18
        0119 Z 0 i -- 1010 Z 0 e 	;  9 + 1 + 0 = 10   ; ACHO QUE ISSO É impossivel
        0119 Z 1 i -- 1011 Z 1 e 	;  9 + 1 + 1 = 11   ; ACHO QUE ISSO É impossivel
        0119 Z 2 i -- 1012 Z 2 e 	;  9 + 1 + 2 = 12   ; ACHO QUE ISSO É impossivel
        0119 Z 3 i -- 1013 Z 3 e 	;  9 + 1 + 3 = 13   ; ACHO QUE ISSO É impossivel
        0119 Z 4 i -- 1014 Z 4 e 	;  9 + 1 + 4 = 14   ; ACHO QUE ISSO É impossivel
        0119 Z 5 i -- 1015 Z 5 e 	;  9 + 1 + 5 = 15   ; ACHO QUE ISSO É impossivel
        0119 Z 6 i -- 1016 Z 6 e 	;  9 + 1 + 6 = 16   ; ACHO QUE ISSO É impossivel
        0119 Z 7 i -- 1017 Z 7 e 	;  9 + 1 + 7 = 17   ; ACHO QUE ISSO É impossivel
        0119 Z 8 i -- 1018 Z 8 e 	;  9 + 1 + 8 = 18   ; ACHO QUE ISSO É impossivel
        0119 Z 9 i -- 1019 Z 9 e 	;  9 + 1 + 9 = 19   ; ACHO QUE ISSO É impossivel
        0109 Z $s i -- 1009 Z $s i 	;  Fita Z Vazia
        0119 Z $s i -- 1019 Z $s i 	;  Fita Z Vazia     ; ACHO QUE ISSO É impossivel
    
        1000 write[00]-Y 9000
        1001 write[01]-Y 9000
        1002 write[02]-Y 9000
        1003 write[03]-Y 9000
        1004 write[04]-Y 9000
        1005 write[05]-Y 9000
        1006 write[06]-Y 9000
        1007 write[07]-Y 9000
        1008 write[08]-Y 9000
        1009 write[09]-Y 9000
        1010 write[10]-Y 9010
        1011 write[11]-Y 9010
        1012 write[12]-Y 9010
        1013 write[13]-Y 9010
        1014 write[14]-Y 9010
        1015 write[15]-Y 9010
        1016 write[16]-Y 9010
        1017 write[17]-Y 9010
        1018 write[18]-Y 9010
        1019 write[19]-Y 9010

        ; Verifica se o processamento acabou
        9000 switch 9001
            9001 Y < i -- 9002 Y < i
            9001 switch 0000  ; Falhou então cancela
            9002 Z $s i -- 9003 Z $s i 
            9002 switch 0000 ; Falhou então cancela
            9003 gotR_-Y 9004
            9004 gotR>-Z 9005
            9005 retorne
        9010 switch 9011
            9011 Y < i -- 9012 Y < i
            9011 switch 0010  ; Falhou então cancela
            9012 Z $s i -- 9013 Z $s i 
            9012 switch 0010  ; Falhou então cancela
            9013 write[01]-Y 9000
            
    fim SOMA



        inicio write[00]-Y   01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 0 d  
            03 prepareRead-Y 04
            04 retorne
        fim write[00]-Y 

        inicio write[01]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 1 d  
            03 prepareRead-Y 04
            04 retorne 
        fim write[01]-Y

        inicio write[02]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 2 d  
            03 prepareRead-Y 04
            04 retorne  
        fim write[02]-Y

        inicio write[03]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 3 d  
            03 prepareRead-Y 04
            04 retorne  
        fim write[03]-Y

        inicio write[04]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 4 d  
            03 prepareRead-Y 04
            04 retorne
        fim write[04]-Y

        inicio write[05]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 5 d  
            03 prepareRead-Y 04
            04 retorne 
        fim write[05]-Y

        inicio write[06]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 6 d  
            03 prepareRead-Y 04
            04 retorne  
        fim write[06]-Y

        inicio write[07]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 7 d  
            03 prepareRead-Y 04
            04 retorne 
        fim write[07]-Y

        inicio write[08]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 8 d  
            0 retorne  
        fim write[08]-Y

        inicio write[09]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 9 d  
            03 prepareRead-Y 04
            04 retorne 
        fim write[09]-Y

        inicio write[10]-Y   01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 0 d  
            03 prepareRead-Y 04
            04 retorne
        fim write[10]-Y 

        inicio write[11]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 1 d  
            03 prepareRead-Y 04
            04 retorne 
        fim write[11]-Y

        inicio write[12]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 2 d  
            03 prepareRead-Y 04
            04 retorne  
        fim write[12]-Y

        inicio write[13]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 3 d  
            03 prepareRead-Y 04
            04 retorne  
        fim write[13]-Y

        inicio write[14]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 4 d  
            03 prepareRead-Y 04
            04 retorne  
        fim write[14]-Y

        inicio write[15]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 5 d  
            03 prepareRead-Y 04
            04 retorne 
        fim write[15]-Y

        inicio write[16]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 6 d  
            03 prepareRead-Y 04
            04 retorne  
        fim write[16]-Y

        inicio write[17]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 7 d  
            03 prepareRead-Y 04
            04 retorne 
        fim write[17]-Y

        inicio write[18]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 8 d  
            03 prepareRead-Y 04
            04 retorne  
        fim write[18]-Y

        inicio write[19]-Y 01    
            01 prepareWrite-Y 02
            02 Y * i -- 03 Y 9 d  
            03 prepareRead-Y 04
            04 retorne 
        fim write[19]-Y

                inicio prepareWrite-Y 01       ; Transfere os digitos de X para Z
                    01 Y $d i -- 02 Y X i           ; Apaga o digito inicial
                    01 Y X i -- 02 Y X i            ; Apaga o digito inicial
                    01 Y < i -- 02 Y < d            ; Apaga o digito inicial
                    02 gotR>-Y 03
                    03 gotR_-Y 04
                    04 retorne
                fim prepareWrite-Y

                inicio prepareRead-Y 01    ; Transfere os digitos de X para Z
                    01 gotL>-Y 02             ; Chegou até o simbolo que delimtia entrada da saida
                    02 Y > i -- 03 Y > e      ; Anda para esquerda para sair do '>' e entrar no numero
                    03 Y X i -- 03 Y X e      ; Parte Ja Tratada
                    03 Y $d i -- 04 Y $d i    ; Chegou no Numbero
                    03 Y < i -- 04 Y < i      ; O digito acabou
                    04 retorne
                fim prepareRead-Y

                inicio gotR>-Z 01           ; Transfere os digitos de X para Z
                    01 Z > i -- 02 Z > i      ; Chegou no simbolo
                    01 Z * i -- 01 Z * d      ; Vai até o simbolo
                    02 retorne                  
                fim gotR>-Z

                inicio gotR>-Y 01           ; Transfere os digitos de X para Z
                    01 Y > i -- 02 Y > i      ; Chegou no simbolo
                    01 Y * i -- 01 Y * d      ; Vai até o simbolo
                    02 retorne                  
                fim gotR>-Y

                inicio gotR_-Y 01           ; Transfere os digitos de X para Z
                    01 Y _ i -- 02 Y _ i      ; Chegou no simbolo
                    01 Y * i -- 01 Y * d      ; Vai até o simbolo
                    02 retorne                  
                fim gotR_-Y

                inicio gotL$d-Y 01           ; Transfere os digitos de X para Z
                    01 Y $d i -- 02 Y $d i      ; Chegou no simbolo
                    01 Y * i -- 01 Y * e      ; Vai até o simbolo
                    02 retorne                  
                fim gotL$d-Y

                inicio gotL>-Y 01           ; Transfere os digitos de X para Z
                    01 Y > i -- 02 Y > i      ; Chegou no simbolo
                    01 Y * i -- 01 Y * e      ; Vai até o simbolo
                    02 retorne                  
                fim gotL>-Y

inicio DEBUG-Y 01      ; Transfere os digitos de X para Z
    01 Y * i -- 02 Y X d      ; Transcreve os Digitos
    02 retorne
fim DEBUG-Y