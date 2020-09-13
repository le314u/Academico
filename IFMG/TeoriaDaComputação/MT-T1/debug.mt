............main : 01 sintatic-X 02
......sintatic-X : 01 skipSpace-X 02
.....skipSpace-X : 01 X $e i -- 01 X $e d
.....skipSpace-X : 01 retorne
......sintatic-X : 02 number-X 03
........number-X : 01 X $d i -- 01 X $d d
........number-X : 01 retorne
......sintatic-X : 03 skipSpace-X 04
.....skipSpace-X : 01 X $e i -- 01 X $e d
.....skipSpace-X : 01 retorne
......sintatic-X : 04 simbol-X 05
........simbol-X : 01 X $s i -- 02 X $s d
........simbol-X : 02 retorne
......sintatic-X : 05 skipSpace-X 06
.....skipSpace-X : 01 X $e i -- 01 X $e d
.....skipSpace-X : 01 retorne
......sintatic-X : 06 number-X 07
........number-X : 01 X $d i -- 01 X $d d
........number-X : 01 X $d i -- 01 X $d d
........number-X : 01 X $d i -- 01 X $d d
........number-X : 01 retorne
......sintatic-X : 07 skipSpace-X 08
.....skipSpace-X : 01 X $e i -- 01 X $e d
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
.....skipSpace-X : 01 X $e i -- 01 X $e d
.....skipSpace-X : 01 retorne
....ignoreZero-X : 02 retorne
......compile-XZ : 04 cpDigit-XZ 05
......cpDigit-XZ : 01 skipSpace-X 02
.....skipSpace-X : 01 retorne
......cpDigit-XZ : 02 X $d d -- 01 Z $d d
......cpDigit-XZ : 01 skipSpace-X 02
.....skipSpace-X : 01 X $e i -- 01 X $e d
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
.....skipSpace-X : 01 X $e i -- 01 X $e d
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
.....skipSpace-X : 01 X $e i -- 01 X $e d
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
........goInit-Z : 01 Z < i -- 02 Z < i
........goInit-Z : 02 retorne
.......cpHalf-ZY : 02 Z * d -- 02 Y * d
.......cpHalf-ZY : 02 Z * d -- 02 Y * d
.......cpHalf-ZY : 02 Z $s i -- 03 Y > i
.......cpHalf-ZY : 03 retorne
preaparaAmbiente : 04 retorne
............main : 03 Z + i -- 1000 Z + i
............main : 1000 SOMA 04
............SOMA : 9999 posiciona-Z 9998
.....posiciona-Z : 01 Z * i -- 01 Z * d
.....posiciona-Z : 01 Z * i -- 01 Z * d
.....posiciona-Z : 01 Z * i -- 01 Z * d
.....posiciona-Z : 01 Z * i -- 01 Z * d
.....posiciona-Z : 01 Z = i -- 02 Z = i
.....posiciona-Z : 02 retorne
............SOMA : 9998 Y * i -- 9997 Y * e
............SOMA : 9997 Z * i -- 0000 Z * e
............SOMA : 0000 Y 1 i -- 0101 Y 1 i
............SOMA : 0101 Z 9 i -- 1010 Z 9 e
............SOMA : 1010 write[10]-Y 9010
.....write[10]-Y : 01 prepareWrite-Y 02
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
.....write[10]-Y : 02 Y * i -- 03 Y 0 d
.....write[10]-Y : 03 prepareRead-Y 04
...prepareRead-Y : 01 gotL>-Y 02
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y * i -- 01 Y * e
.........gotL>-Y : 01 Y > i -- 02 Y > i
.........gotL>-Y : 02 retorne
...prepareRead-Y : 02 Y > i -- 03 Y > e
...prepareRead-Y : 03 Y X i -- 03 Y X e
...prepareRead-Y : 03 Y < i -- 04 Y < i
...prepareRead-Y : 04 retorne
.....write[10]-Y : 04 retorne
............SOMA : 9010 switch 9011
..........switch : 01 retorne
............SOMA : 9011 Y < i -- 9012 Y < i
............SOMA : 9012 switch 0010
..........switch : 01 retorne
............SOMA : 0010 Y * i -- 0101 Y * d
............SOMA : 0101 Z 9 i -- 1010 Z 9 e
............SOMA : 1010 write[10]-Y 9010
.....write[10]-Y : 01 prepareWrite-Y 02
..prepareWrite-Y : 01 Y X i -- 02 Y X i
..prepareWrite-Y : 02 gotR>-Y 03
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
...prepareRead-Y : 03 Y < i -- 04 Y < i
...prepareRead-Y : 04 retorne
.....write[10]-Y : 04 retorne
............SOMA : 9010 switch 9011
..........switch : 01 retorne
............SOMA : 9011 Y < i -- 9012 Y < i
............SOMA : 9012 switch 0010
..........switch : 01 retorne
............SOMA : 0010 Y * i -- 0101 Y * d
............SOMA : 0101 Z 9 i -- 1010 Z 9 e
............SOMA : 1010 write[10]-Y 9010
.....write[10]-Y : 01 prepareWrite-Y 02
..prepareWrite-Y : 01 Y X i -- 02 Y X i
..prepareWrite-Y : 02 gotR>-Y 03
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
...prepareRead-Y : 03 Y < i -- 04 Y < i
...prepareRead-Y : 04 retorne
.....write[10]-Y : 04 retorne
............SOMA : 9010 switch 9011
..........switch : 01 retorne
............SOMA : 9011 Y < i -- 9012 Y < i
............SOMA : 9012 Z $s i -- 9013 Z $s i
............SOMA : 9013 write[01]-Y 9000
.....write[01]-Y : 01 prepareWrite-Y 02
..prepareWrite-Y : 01 Y < i -- 02 Y < d
..prepareWrite-Y : 02 gotR>-Y 03
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
.....write[01]-Y : 02 Y * i -- 03 Y 1 d
.....write[01]-Y : 03 prepareRead-Y 04
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
...prepareRead-Y : 03 Y < i -- 04 Y < i
...prepareRead-Y : 04 retorne
.....write[01]-Y : 04 retorne
............SOMA : 9000 switch 9001
..........switch : 01 retorne
............SOMA : 9001 Y < i -- 9002 Y < i
............SOMA : 9002 Z $s i -- 9003 Z $s i
............SOMA : 9003 gotR_-Y 9004
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y * i -- 01 Y * d
.........gotR_-Y : 01 Y _ i -- 02 Y _ i
.........gotR_-Y : 02 retorne
............SOMA : 9004 gotR>-Z 9005
.........gotR>-Z : 01 Z * i -- 01 Z * d
.........gotR>-Z : 01 Z * i -- 01 Z * d
.........gotR>-Z : 01 Z * i -- 01 Z * d
.........gotR>-Z : 01 Z * i -- 01 Z * d
.........gotR>-Z : 01 Z * i -- 01 Z * d
.........gotR>-Z : 01 Z > i -- 02 Z > i
.........gotR>-Z : 02 retorne
............SOMA : 9005 retorne
