$d = '0123456789'
inicio main 01
        01 X 0 i -- 01 X 0 i
        01 X 1 i -- 01 X $d i
        01 X 2 i -- 01 X $d i
        01 X 7 i -- 01 X $d i
        01 X $d i -- 03 X $d i
        01 X ∗ i -- 05 X ∗ i
        01 copiaX 05
        01 aceite
        01 retorne
        01 aceite
        01 pare
fim main
inicio copiaX 1234
        01 X $d i -- 5 Y $d d
        01 retorne
        01 aceite
        01 rejeite
fim copiaX