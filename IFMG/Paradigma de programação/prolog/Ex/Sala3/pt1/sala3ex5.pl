#!/usr/bin/swipl

caminho(a,b).
caminho(a,d).
caminho(a,c).
caminho(c,e).
caminho(c,f).
caminho(f,g).
caminho(h,i).

%a
conectadas(X,Y):-
    caminho(X,Y);
    (
        caminho(X,Aux),
        conectadas(Aux,Y)
    ).
%b
ligada(X,Y):-
    (
        caminho(X,Aux),
        write(Aux),
        ligada(Aux,Y)
    ).
%c
conect(X,Y):-
    conectadas(X,Y);
    conectadas(Y,X).