............main : 01 sintatic-X 02
......sintatic-X : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
......sintatic-X : 02 number-X 03
........number-X : 01 X $d i -- 01 X $d d
........number-X : 01 X $d i -- 01 X $d d
........number-X : 01 X $d i -- 01 X $d d
........number-X : 01 X $d i -- 01 X $d d
........number-X : 01 retorne
......sintatic-X : 03 skipSpace-X 04
.....skipSpace-X : 01 retorne
......sintatic-X : 04 simbol-X 05
........simbol-X : 01 X $s i -- 02 X $s d
........simbol-X : 02 retorne
......sintatic-X : 05 skipSpace-X 06
.....skipSpace-X : 01 retorne
......sintatic-X : 06 number-X 07
........number-X : 01 X $d i -- 01 X $d d
........number-X : 01 X $d i -- 01 X $d d
........number-X : 01 X $d i -- 01 X $d d
........number-X : 01 retorne
......sintatic-X : 07 skipSpace-X 08
.....skipSpace-X : 01 retorne
......sintatic-X : 08 end-X 09
...........end-X : 01 X $f i -- 02 X $f d
...........end-X : 02 X _ i -- 03 X _ i
...........end-X : 03 retorne
......sintatic-X : 09 retorne
............main : 02 preaparaAmbiente 03
preaparaAmbiente : 01 brackelets-X 02
....brackelets-X : 01 X _ i -- 02 X > e
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X _ i -- 03 X < i
....brackelets-X : 03 retorne
preaparaAmbiente : 02 compile-XZ 03
......compile-XZ : 01 goInit-X 02
........goInit-X : 01 X < i -- 02 X < i
........goInit-X : 02 retorne
......compile-XZ : 02 X < d -- 03 Z < d
......compile-XZ : 03 ignoreZero-X 04
....ignoreZero-X : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
....ignoreZero-X : 02 retorne
......compile-XZ : 04 cpDigit-XZ 05
......cpDigit-XZ : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
......cpDigit-XZ : 02 X $d d -- 01 Z $d d
......cpDigit-XZ : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
......cpDigit-XZ : 02 X $d d -- 01 Z $d d
......cpDigit-XZ : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
......cpDigit-XZ : 02 X $d d -- 01 Z $d d
......cpDigit-XZ : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
......cpDigit-XZ : 02 X $d d -- 01 Z $d d
......cpDigit-XZ : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
......cpDigit-XZ : 02 retorne
......compile-XZ : 05 skipSpace-X 06
.....skipSpace-X : 01 retorne
......compile-XZ : 06 zero-Z 07
..........zero-Z : 01 moveE-Z 02
.........moveE-Z : 01 Z * i -- 02 Z * e
.........moveE-Z : 02 retorne
..........zero-Z : 02 Z $d i -- 03 Z $d d
..........zero-Z : 03 retorne
......compile-XZ : 07 X $s d -- 08 Z $s d
......compile-XZ : 08 ignoreZero-X 09
....ignoreZero-X : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
....ignoreZero-X : 02 retorne
......compile-XZ : 09 cpDigit-XZ 10
......cpDigit-XZ : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
......cpDigit-XZ : 02 X $d d -- 01 Z $d d
......cpDigit-XZ : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
......cpDigit-XZ : 02 X $d d -- 01 Z $d d
......cpDigit-XZ : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
......cpDigit-XZ : 02 X $d d -- 01 Z $d d
......cpDigit-XZ : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
......cpDigit-XZ : 02 retorne
......compile-XZ : 10 skipSpace-X 11
.....skipSpace-X : 01 retorne
......compile-XZ : 11 zero-Z 12
..........zero-Z : 01 moveE-Z 02
.........moveE-Z : 01 Z * i -- 02 Z * e
.........moveE-Z : 02 retorne
..........zero-Z : 02 Z $d i -- 03 Z $d d
..........zero-Z : 03 retorne
......compile-XZ : 12 skipSpace-X 13
.....skipSpace-X : 01 retorne
......compile-XZ : 13 X $f d -- 14 Z $f d
......compile-XZ : 14 X > i -- 15 Z > i
......compile-XZ : 15 retorne
preaparaAmbiente : 03 cpHalf-ZY 04
.......cpHalf-ZY : 01 goInit-Z 02
........goInit-Z : 01 Z * i -- 01 Z * e
........goInit-Z : 01 Z * i -- 01 Z * e
........goInit-Z : 01 Z * i -- 01 Z * e
........goInit-Z : 01 Z * i -- 01 Z * e
........goInit-Z : 01 Z * i -- 01 Z * e
........goInit-Z : 01 Z * i -- 01 Z * e
........goInit-Z : 01 Z * i -- 01 Z * e
........goInit-Z : 01 Z * i -- 01 Z * e
........goInit-Z : 01 Z * i -- 01 Z * e
........goInit-Z : 01 Z * i -- 01 Z * e
........goInit-Z : 01 Z < i -- 02 Z < i
........goInit-Z : 02 retorne
.......cpHalf-ZY : 02 Z * d -- 02 Y * d
.......cpHalf-ZY : 02 Z * d -- 02 Y * d
.......cpHalf-ZY : 02 Z * d -- 02 Y * d
.......cpHalf-ZY : 02 Z * d -- 02 Y * d
.......cpHalf-ZY : 02 Z * d -- 02 Y * d
.......cpHalf-ZY : 02 Z $s i -- 03 Y > i
.......cpHalf-ZY : 03 retorne
preaparaAmbiente : 04 retorne
............main : 03 Z - i -- 2000 Z - i
............main : 2000 SUB 04
.............SUB : 9999 initSUB 00
.........initSUB : 00 direitaNumero-Y 01
.direitaNumero-Y : 00 goEnd-Y 01
.........goEnd-Y : 01 Y > i -- 02 Y > i
.........goEnd-Y : 02 retorne
.direitaNumero-Y : 01 moveE-Y 01
.........moveE-Y : 01 Y * i -- 02 Y * e
.........moveE-Y : 02 retorne
.direitaNumero-Y : 01 Y $d i -- 02 Y $d i
.direitaNumero-Y : 02 retorne
.........initSUB : 01 direitaNumero-Z 02
.direitaNumero-Z : 00 goEnd-Z 01
.........goEnd-Z : 01 Z * i -- 01 Z * d
.........goEnd-Z : 01 Z * i -- 01 Z * d
.........goEnd-Z : 01 Z * i -- 01 Z * d
.........goEnd-Z : 01 Z * i -- 01 Z * d
.........goEnd-Z : 01 Z * i -- 01 Z * d
.........goEnd-Z : 01 Z > i -- 02 Z > i
.........goEnd-Z : 02 retorne
.direitaNumero-Z : 01 moveE-Z 01
.........moveE-Z : 01 Z * i -- 02 Z * e
.........moveE-Z : 02 retorne
.direitaNumero-Z : 01 moveE-Z 01
.........moveE-Z : 01 Z * i -- 02 Z * e
.........moveE-Z : 02 retorne
.direitaNumero-Z : 01 Z $d i -- 02 Z $d i
.direitaNumero-Z : 02 retorne
.........initSUB : 02 ordenFatores-Y 03
..ordenFatores-Y : 99 Y $d i -- 19 Y $d e
..ordenFatores-Y : 19 Z $d i -- 11 Z $d e
..ordenFatores-Y : 11 switch 99
..........switch : 01 retorne
..ordenFatores-Y : 99 Y $d i -- 19 Y $d e
..ordenFatores-Y : 19 Z $d i -- 11 Z $d e
..ordenFatores-Y : 11 switch 99
..........switch : 01 retorne
..ordenFatores-Y : 99 Y $d i -- 19 Y $d e
..ordenFatores-Y : 19 Z $d i -- 11 Z $d e
..ordenFatores-Y : 11 switch 99
..........switch : 01 retorne
..ordenFatores-Y : 99 Y $d i -- 19 Y $d e
..ordenFatores-Y : 19 switch 10
..........switch : 01 retorne
..ordenFatores-Y : 10 maiorA 9999
..........maiorA : 00 goInit-Y 01
........goInit-Y : 01 Y < i -- 02 Y < i
........goInit-Y : 02 retorne
..........maiorA : 01 Y < i -- 02 Y < e
..........maiorA : 02 Y _ i -- 03 Y A i
..........maiorA : 03 retorne
..ordenFatores-Y : 9999 retorne
.........initSUB : 03 retorne
.............SUB : 00 Y A i -- 01 Y A d
.............SUB : 01 SUB_A-B 03
.........SUB_A-B : 9999 direitaNumero-YZ 0000
direitaNumero-YZ : 00 direitaNumero-Y 01
.direitaNumero-Y : 00 goEnd-Y 01
.........goEnd-Y : 01 Y * i -- 01 Y * d
.........goEnd-Y : 01 Y * i -- 01 Y * d
.........goEnd-Y : 01 Y * i -- 01 Y * d
.........goEnd-Y : 01 Y * i -- 01 Y * d
.........goEnd-Y : 01 Y * i -- 01 Y * d
.........goEnd-Y : 01 Y > i -- 02 Y > i
.........goEnd-Y : 02 retorne
.direitaNumero-Y : 01 moveE-Y 01
.........moveE-Y : 01 Y * i -- 02 Y * e
.........moveE-Y : 02 retorne
.direitaNumero-Y : 01 Y $d i -- 02 Y $d i
.direitaNumero-Y : 02 retorne
direitaNumero-YZ : 01 direitaNumero-Z 02
.direitaNumero-Z : 00 goEnd-Z 01
.........goEnd-Z : 01 Z * i -- 01 Z * d
.........goEnd-Z : 01 Z * i -- 01 Z * d
.........goEnd-Z : 01 Z * i -- 01 Z * d
.........goEnd-Z : 01 Z * i -- 01 Z * d
.........goEnd-Z : 01 Z * i -- 01 Z * d
.........goEnd-Z : 01 Z > i -- 02 Z > i
.........goEnd-Z : 02 retorne
.direitaNumero-Z : 01 moveE-Z 01
.........moveE-Z : 01 Z * i -- 02 Z * e
.........moveE-Z : 02 retorne
.direitaNumero-Z : 01 moveE-Z 01
.........moveE-Z : 01 Z * i -- 02 Z * e
.........moveE-Z : 02 retorne
.direitaNumero-Z : 01 Z $d i -- 02 Z $d i
.direitaNumero-Z : 02 retorne
direitaNumero-YZ : 02 retorne
.........SUB_A-B : 0000 Y 0 i -- 0100 Y 0 i
.........SUB_A-B : 0100 Z 9 i -- 1011 Z 9 e
.........SUB_A-B : 1011 write[11]-Y 9010
.....write[11]-Y : 01 prepareWrite-Y 02
..prepareWrite-Y : 01 Y $d i -- 02 Y X i
..prepareWrite-Y : 02 gotR>-Y 03
.........gotR>-Y : 01 Y * i -- 01 Y * d
.........gotR>-Y : 01 Y > i -- 02 Y > i
.........gotR>-Y : 02 retorne
..prepareWrite-Y : 03 gotR_-Y 04
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y _ i -- 02 Y _ i
.........gotR_-Y : 02 retorne
..prepareWrite-Y : 04 retorne
.....write[11]-Y : 02 Y * i -- 03 Y 1 d
.....write[11]-Y : 03 prepareRead-Y 04
...prepareRead-Y : 01 gotL>-Y 02
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y > i -- 02 Y > i
.........gotL>-Y : 02 retorne
...prepareRead-Y : 02 Y > i -- 03 Y > e
...prepareRead-Y : 03 Y X i -- 03 Y X e
...prepareRead-Y : 03 Y $d i -- 04 Y $d i
...prepareRead-Y : 04 retorne
.....write[11]-Y : 04 retorne
.........SUB_A-B : 9010 switch 9011
..........switch : 01 retorne
.........SUB_A-B : 9011 switch 0010
..........switch : 01 retorne
.........SUB_A-B : 0010 Y 0 i -- 0110 Y 0 i
.........SUB_A-B : 0110 Z 9 i -- 1010 Z 9 e
.........SUB_A-B : 1010 write[10]-Y 9010
.....write[10]-Y : 01 prepareWrite-Y 02
..prepareWrite-Y : 01 Y $d i -- 02 Y X i
..prepareWrite-Y : 02 gotR>-Y 03
.........gotR>-Y : 01 Y * i -- 01 Y * d
.........gotR>-Y : 01 Y * i -- 01 Y * d
.........gotR>-Y : 01 Y > i -- 02 Y > i
.........gotR>-Y : 02 retorne
..prepareWrite-Y : 03 gotR_-Y 04
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y _ i -- 02 Y _ i
.........gotR_-Y : 02 retorne
..prepareWrite-Y : 04 retorne
.....write[10]-Y : 02 Y * i -- 03 Y 0 d
.....write[10]-Y : 03 prepareRead-Y 04
...prepareRead-Y : 01 gotL>-Y 02
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y > i -- 02 Y > i
.........gotL>-Y : 02 retorne
...prepareRead-Y : 02 Y > i -- 03 Y > e
...prepareRead-Y : 03 Y X i -- 03 Y X e
...prepareRead-Y : 03 Y X i -- 03 Y X e
...prepareRead-Y : 03 Y $d i -- 04 Y $d i
...prepareRead-Y : 04 retorne
.....write[10]-Y : 04 retorne
.........SUB_A-B : 9010 switch 9011
..........switch : 01 retorne
.........SUB_A-B : 9011 switch 0010
..........switch : 01 retorne
.........SUB_A-B : 0010 Y 0 i -- 0110 Y 0 i
.........SUB_A-B : 0110 Z 9 i -- 1010 Z 9 e
.........SUB_A-B : 1010 write[10]-Y 9010
.....write[10]-Y : 01 prepareWrite-Y 02
..prepareWrite-Y : 01 Y $d i -- 02 Y X i
..prepareWrite-Y : 02 gotR>-Y 03
.........gotR>-Y : 01 Y * i -- 01 Y * d
.........gotR>-Y : 01 Y * i -- 01 Y * d
.........gotR>-Y : 01 Y * i -- 01 Y * d
.........gotR>-Y : 01 Y > i -- 02 Y > i
.........gotR>-Y : 02 retorne
..prepareWrite-Y : 03 gotR_-Y 04
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y _ i -- 02 Y _ i
.........gotR_-Y : 02 retorne
..prepareWrite-Y : 04 retorne
.....write[10]-Y : 02 Y * i -- 03 Y 0 d
.....write[10]-Y : 03 prepareRead-Y 04
...prepareRead-Y : 01 gotL>-Y 02
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y > i -- 02 Y > i
.........gotL>-Y : 02 retorne
...prepareRead-Y : 02 Y > i -- 03 Y > e
...prepareRead-Y : 03 Y X i -- 03 Y X e
...prepareRead-Y : 03 Y X i -- 03 Y X e
...prepareRead-Y : 03 Y X i -- 03 Y X e
...prepareRead-Y : 03 Y $d i -- 04 Y $d i
...prepareRead-Y : 04 retorne
.....write[10]-Y : 04 retorne
.........SUB_A-B : 9010 switch 9011
..........switch : 01 retorne
.........SUB_A-B : 9011 switch 0010
..........switch : 01 retorne
.........SUB_A-B : 0010 Y 1 i -- 0100 Y 1 i
.........SUB_A-B : 0100 Z $s i -- 1000 Z $s i
.........SUB_A-B : 1000 write[00]-Y 9000
.....write[00]-Y : 01 prepareWrite-Y 02
..prepareWrite-Y : 01 Y $d i -- 02 Y X i
..prepareWrite-Y : 02 gotR>-Y 03
.........gotR>-Y : 01 Y * i -- 01 Y * d
.........gotR>-Y : 01 Y * i -- 01 Y * d
.........gotR>-Y : 01 Y * i -- 01 Y * d
.........gotR>-Y : 01 Y * i -- 01 Y * d
.........gotR>-Y : 01 Y > i -- 02 Y > i
.........gotR>-Y : 02 retorne
..prepareWrite-Y : 03 gotR_-Y 04
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y _ i -- 02 Y _ i
.........gotR_-Y : 02 retorne
..prepareWrite-Y : 04 retorne
.....write[00]-Y : 02 Y * i -- 03 Y 0 d
.....write[00]-Y : 03 prepareRead-Y 04
...prepareRead-Y : 01 gotL>-Y 02
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y > i -- 02 Y > i
.........gotL>-Y : 02 retorne
...prepareRead-Y : 02 Y > i -- 03 Y > e
...prepareRead-Y : 03 Y X i -- 03 Y X e
...prepareRead-Y : 03 Y X i -- 03 Y X e
...prepareRead-Y : 03 Y X i -- 03 Y X e
...prepareRead-Y : 03 Y X i -- 03 Y X e
...prepareRead-Y : 03 Y < i -- 04 Y < i
...prepareRead-Y : 04 retorne
.....write[00]-Y : 04 retorne
.........SUB_A-B : 9000 switch 9001
..........switch : 01 retorne
.........SUB_A-B : 9001 Y < i -- 9002 Y < i
.........SUB_A-B : 9002 Z $s i -- 9003 Z $s i
.........SUB_A-B : 9003 gotR_-Y 9004
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y _ i -- 02 Y _ i
.........gotR_-Y : 02 retorne
.........SUB_A-B : 9004 gotR>-Z 9005
.........gotR>-Z : 01 Z * i -- 01 Z * d
.........gotR>-Z : 01 Z * i -- 01 Z * d
.........gotR>-Z : 01 Z * i -- 01 Z * d
.........gotR>-Z : 01 Z * i -- 01 Z * d
.........gotR>-Z : 01 Z * i -- 01 Z * d
.........gotR>-Z : 01 Z > i -- 02 Z > i
.........gotR>-Z : 02 retorne
.........SUB_A-B : 9005 retorne
.............SUB : 03 retorne
