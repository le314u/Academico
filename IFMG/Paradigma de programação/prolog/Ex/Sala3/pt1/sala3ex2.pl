#!/usr/bin/swipl

nota_freq(alberto, logica, 9.0, 60.0).
nota_freq(juca, logica, 7.0, 95.0).
nota_freq(maria, logica, 4.0, 75.0).

%a
nome_nota(Nome,Nota):-
    nota_freq(Nome,_,Nota,_).
%b
aprovado(X, Y, Z, W):-
    nota_freq(X, Y, Z, W),
    Z>=7,W>=75.
%c
aprovado(X, Y, _, _). %Não sei porque mas depois do retorna informa Y=logica
%d
aprovado(X, logica, _, _).
%e
reprovados(X,Y):-
    nota_freq(X, Y, Z, W),
    (
        Z<7;W<75
    ).
%f
reprovados(X,Y).
   
