............main : 01 sintatic 02
........sintatic : 01 skipSpace 02
.......skipSpace : 01 retorne
........sintatic : 02 number 03
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 retorne
........sintatic : 03 skipSpace 04
.......skipSpace : 01 X $e i -- 01 X $e d
.......skipSpace : 01 X $e i -- 01 X $e d
.......skipSpace : 01 retorne
........sintatic : 04 simbol 05
..........simbol : 01 X $s i -- 02 X $s d
..........simbol : 02 retorne
........sintatic : 05 skipSpace 06
.......skipSpace : 01 X $e i -- 01 X $e d
.......skipSpace : 01 X $e i -- 01 X $e d
.......skipSpace : 01 retorne
........sintatic : 06 number 07
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 X $d i -- 01 X $d d
..........number : 01 retorne
........sintatic : 07 skipSpace 08
.......skipSpace : 01 X $e i -- 01 X $e d
.......skipSpace : 01 retorne
........sintatic : 08 end 09
.............end : 01 X $f i -- 02 X $f d
.............end : 02 X _ i -- 03 X _ i
.............end : 03 retorne
........sintatic : 09 retorne
............main : 02 restruturaX 03
.....restruturaX : 01 X _ i -- 02 X > e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X * i -- 02 X * e
.....restruturaX : 02 X _ i -- 03 X < i
.....restruturaX : 03 retorne
............main : 03 X-Z-rmSpace 04
.....X-Z-rmSpace : 01 X < d -- 02 Z < d
.....X-Z-rmSpace : 02 skipSpace 03
.......skipSpace : 01 retorne
.....X-Z-rmSpace : 03 X $d d -- 03 Z $d d
.....X-Z-rmSpace : 03 X $d d -- 03 Z $d d
.....X-Z-rmSpace : 03 X $d d -- 03 Z $d d
.....X-Z-rmSpace : 03 X $d d -- 03 Z $d d
.....X-Z-rmSpace : 03 X $d d -- 03 Z $d d
.....X-Z-rmSpace : 03 switch 04
..........switch : 01 retorne
.....X-Z-rmSpace : 04 skipSpace 05
.......skipSpace : 01 X $e i -- 01 X $e d
.......skipSpace : 01 X $e i -- 01 X $e d
.......skipSpace : 01 retorne
.....X-Z-rmSpace : 05 X $s d -- 05 Z $s d
.....X-Z-rmSpace : 05 switch 06
..........switch : 01 retorne
.....X-Z-rmSpace : 06 skipSpace 07
.......skipSpace : 01 X $e i -- 01 X $e d
.......skipSpace : 01 X $e i -- 01 X $e d
.......skipSpace : 01 retorne
.....X-Z-rmSpace : 07 X $d d -- 07 Z $d d
.....X-Z-rmSpace : 07 X $d d -- 07 Z $d d
.....X-Z-rmSpace : 07 X $d d -- 07 Z $d d
.....X-Z-rmSpace : 07 X $d d -- 07 Z $d d
.....X-Z-rmSpace : 07 X $d d -- 07 Z $d d
.....X-Z-rmSpace : 07 switch 08
..........switch : 01 retorne
.....X-Z-rmSpace : 08 skipSpace 09
.......skipSpace : 01 X $e i -- 01 X $e d
.......skipSpace : 01 retorne
.....X-Z-rmSpace : 09 X $f d -- 10 Z $f d
.....X-Z-rmSpace : 10 X > i -- 11 Z > i
.....X-Z-rmSpace : 11 retorne
