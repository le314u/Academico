#!/usr/bin/swipl

start():-
    consult('sala3ex9.pl').
start().

pos_acima(X1,Y1,X2,Y2):-
    (existe_acima(X1,Y1),
    Y2 is Y1 + 1,
    X2 is X1,!);
    (X2 is X1,
    Y2 is Y1,!).

pos_abaixo(X1,Y1,X2,Y2):-
    (existe_abaixo(X1,Y1),
    Y2 is Y1 - 1,
    X2 is X1);
    (X2 is X1,
    Y2 is Y1).

pos_direita(X1,Y1,X2,Y2):-
    (existe_direita(X1,Y1),
    X2 is X1 + 1,
    Y2 is Y1);
    (X2 is X1,
    Y2 is Y1).

pos_esquerda(X1,Y1,X2,Y2):-
    (existe_esquerda(X1,Y1),
    X2 is X1 - 1,
    Y2 is Y1);
    (X2 is X1,
    Y2 is Y1).

start().