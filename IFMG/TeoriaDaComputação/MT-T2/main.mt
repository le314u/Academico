; Aliases

$d = 0123456789 ;   [0-9]
$s = -+         ;   [+,-]
$e = ~          ;   [' '] porem como a fita não aceita espaço estarei representando por '~'
$f = =          ;   [=]



inicio sintatic 01      ; Faz analise Sintatica verificando se a entrada é valida
    01 skipSpace 02         ;    Pula ' ' espaços
    02 number 03            ;    Verifico se é um numero [0-9]+
    03 skipSpace 04         ;    Pula ' ' espaços
    04 simbol 05            ;    Verifico se é um simbolo [+,-]
    05 skipSpace 06         ;    Pula ' ' espaços
    06  number 07           ;    Verifico se é um numero [0-9]+
    07 skipSpace 08         ;    Pula ' ' espaços
    08 end 09               ;    Verifico se tem um = e é a ultima coisa
    09 retorne              ;    OK
                            ;    Se parar antes do Estado 10 está errado
    01 rejeite              ;    Erro pois parou no meio do processo
    02 rejeite              ;    Erro pois parou no meio do processo
    03 rejeite              ;    Erro pois parou no meio do processo
    04 rejeite              ;    Erro pois parou no meio do processo
    06 rejeite              ;    Erro pois parou no meio do processo
    07 rejeite              ;    Erro pois parou no meio do processo
    08 rejeite              ;    Erro pois parou no meio do processo
                            ;
fim sintatic


inicio skipSpace 01         ; Verifico se é um ' '
    01 X $e i -- 01 X $e d      ; Verifico Simbolo
    01 retorne                  ; OK
fim skipSpace


inicio number 01            ; Pula o numero [0-9]+
    01 X $d i -- 01 X $d d      ; Verifico Simbolo
    01 retorne                  ; Ok
fim number


inicio simbol 01            ; Verifico se é um [+,-]
    01 X $s i -- 02 X $s d      ; Verifico Simbolo
    02 retorne                  ; OK
    01 rejeite                  ; Erro pois parou no meio do processo
fim simbol


inicio end 01               ; Verifico se é um '='
    01 X $f i -- 02 X $f d      ; Verifico Simbolo
    02 X _ i -- 03 X _ i        ; Verifico Simbolo
    03 retorne                  ; OK
    01 rejeite                  ; Erro pois parou no meio do processo
    02 rejeite                  ; Erro pois parou no meio do processo
fim end


inicio restruturaX 01       ; Reescreve a Fita X colocando os brackelets '<>'
    01 X _ i -- 02 X > e      ; Troco o primeiro espaço em branco a direita para '>'
    01 X * i -- 01 X * d      ; Vou para a direita até encontrar um espaço em branco '_'
    02 X _ i -- 03 X < i      ; Troco o primeiro espaço em branco a esquerda para '<'
    02 X * i -- 02 X * e      ; Vou para a direita até encontrar um espaço em branco '_'
    03 retorne                ; Fim do Processo
fim restruturaX


inicio switch 01    ; POG para trocar o estado
        01 retorne      ; Retorna
fim switch


inicio X-Z-rmSpace 01       ; Passa a Fita X para a Fita Z Tirando os 'espaços'
    01 X < d -- 02 Z < d        ; Transcereve '<'
    01 X * d -- 01 X * e        ; Vou para a esquerda até encontrar '<'
    02 skipSpace 03             ; Skipa os espaços
    03 X $d d -- 03 Z $d d      ; Transcreve os Digitos
    03 switch 04                 
    04 skipSpace 05             ; Skipa os espaços
    05 X $s d -- 05 Z $s d      ; Transcreve o simbolo
    05 switch 06 
    06 skipSpace 07             ; Skipa os espaços
    07 X $d d -- 07 Z $d d      ; Transcreve os Digitos
    07 switch 08 
    08 skipSpace 09             ; Skipa os espaços
    09 X $f d -- 10 Z $f d      ; Transcreve o =
    10 X > i -- 11 Z > i        ; Transcreve o >
    11 retorne                  ; Fim do Processo
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
fim X-Z-rmSpace







inicio main 01
        01 sintatic 02      ; Verifico se a entrada é valida
        02 restruturaX 03   ; Reescreve a Fita X colocando <>
        03 X-Z-rmSpace 04   ; Passa a Fita X para a Fita Z removendo os espaços
        03 aceite           ; Fim
fim main
