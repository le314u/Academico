$d = '0123456789'

inicio main 01
        01 copiaX 02
        02 X 0 i -- 01 X 0 i
        02 X 1 i -- 01 X $d i
        02 X 2 i -- 01 X $d i
        02 X 7 i -- 01 X $d i
        02 X $d i -- 03 X $d i
        02 X ∗ i -- 05 X ∗ i
        01 aceite
        01 retorne
        01 aceite
        05 pare
fim main

inicio copiaX 01
        01 copiaY 02
        01 X $d i -- 5 Y $d d
        02 retorne
        01 aceite
        01 rejeite
fim copiaX

inicio copiaY 01
        01 retorne
        01 X $d i -- 5 Y $d d
        01 retorne
        01 aceite
        01 rejeite
fim copiaY