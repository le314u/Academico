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
.............SUB : 9999 posiciona-Z 9998
.....posiciona-Z : 01 Z * i -- 01 Z * d
.....posiciona-Z : 01 Z * i -- 01 Z * d
.....posiciona-Z : 01 Z * i -- 01 Z * d
.....posiciona-Z : 01 Z * i -- 01 Z * d
.....posiciona-Z : 01 Z = i -- 02 Z = i
.....posiciona-Z : 02 retorne
.............SUB : 9998 Y * i -- 9997 Y * e
.............SUB : 9997 Z * i -- 0000 Z * e
.............SUB : 0000 ordenFatores-Y 1111
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
