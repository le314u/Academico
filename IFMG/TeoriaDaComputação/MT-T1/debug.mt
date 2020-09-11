............main : 01 sintatic 02
........sintatic : 01 skipSpace 02
.......skipSpace : 01 retorne
........sintatic : 02 number 03
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 retorne
........sintatic : 03 skipSpace 04
.......skipSpace : 01 retorne
........sintatic : 04 simbol 05
..........simbol : 01 X $s i -- 02 X $s d
..........simbol : 02 retorne
........sintatic : 05 skipSpace 06
.......skipSpace : 01 retorne
........sintatic : 06 number 07
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 retorne
........sintatic : 07 skipSpace 08
.......skipSpace : 01 retorne
........sintatic : 08 end 09
.............end : 01 X $f i -- 02 X $f d
.............end : 02 X _ i -- 03 X _ i
.............end : 03 retorne
........sintatic : 09 retorne
............main : 02 brackelets-X 03
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
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X * i -- 02 X * e
....brackelets-X : 02 X _ i -- 03 X < i
....brackelets-X : 03 retorne
............main : 03 rmSpace-XZ 04
......rmSpace-XZ : 01 X < d -- 02 Z < d
......rmSpace-XZ : 02 rmZero-XZ 03
.......rmZero-XZ : 01 skipSpace 02
.......skipSpace : 01 retorne
.......rmZero-XZ : 02 X 0 i -- 02 X 0 d
.......rmZero-XZ : 02 X 0 i -- 02 X 0 d
.......rmZero-XZ : 02 X 0 i -- 02 X 0 d
.......rmZero-XZ : 02 retorne
......rmSpace-XZ : 03 digit-XZ 04
........digit-XZ : 01 skipSpace 02
.......skipSpace : 01 retorne
........digit-XZ : 02 retorne
......rmSpace-XZ : 04 skipSpace 05
.......skipSpace : 01 retorne
......rmSpace-XZ : 05 zero-X 06
..........zero-X : 01 moveE 02
...........moveE : 01 X * i -- 02 X * e
...........moveE : 02 retorne
..........zero-X : 02 X * d -- 03 X 0 d
..........zero-X : 03 retorne
......rmSpace-XZ : 06 X $s d -- 07 Z $s d
......rmSpace-XZ : 07 rmZero-XZ 08
.......rmZero-XZ : 01 skipSpace 02
.......skipSpace : 01 retorne
.......rmZero-XZ : 02 X 0 i -- 02 X 0 d
.......rmZero-XZ : 02 retorne
......rmSpace-XZ : 08 digit-XZ 09
........digit-XZ : 01 skipSpace 02
.......skipSpace : 01 retorne
........digit-XZ : 02 retorne
......rmSpace-XZ : 09 skipSpace 10
.......skipSpace : 01 retorne
......rmSpace-XZ : 10 zero-X 11
..........zero-X : 01 moveE 02
...........moveE : 01 X * i -- 02 X * e
...........moveE : 02 retorne
..........zero-X : 02 X * d -- 03 X 0 d
..........zero-X : 03 retorne
......rmSpace-XZ : 11 skipSpace 12
.......skipSpace : 01 retorne
