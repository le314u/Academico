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

inicio positionTape 01      ; Posiciona as Fitas Y e Z 
    02 Y $s i -- 03 Y $s i      ; Retorna pois chegou no token de inicio '<'
    02 Y * i -- 02 Y * e        ; Retorna a Fita Y até o symbolo
    03 retorne
fim positionTape


inicio preaparaAmbiente 01   ; Prepara todo o ambiente para começar a fazer as contas
    01 brackelets-X 02          ; Reescreve a Fita X colocando <> 
    02 compile-XZ 03            ; Passa a Fita X para a Fita Z removendo os espaços e os 0 no inicio do inteiro
    03 cpHalf-ZY 04             ; Copia a Fita Z para Y de modo invertido
                                ; Verifica o tipo de operação
    04 positionTape 05          ; Reposiciona as Fitas Z e Y
fim preaparaAmbiente






; Verifico Qual A Operação
; Verifico Qual Digito É maior

inicio main 01
        01 sintatic-X 02        ; Verifico se a entrada é valida
        02 preaparaAmbiente 03
        03 aceite               ; Fim
fim main








inicio DEBUG-Y 01      ; Transfere os digitos de X para Z
    01 Y * i -- 02 Y X d      ; Transcreve os Digitos
    02 retorne
fim DEBUG-Y