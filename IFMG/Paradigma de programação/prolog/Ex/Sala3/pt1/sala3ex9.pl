#!/usr/bin/swipl

mapa(1,1).
mapa(1,2).
mapa(1,3).
mapa(1,4).
mapa(2,1).
mapa(2,2).
mapa(2,3).
mapa(2,4).
mapa(3,1).
mapa(3,2).
mapa(3,3).
mapa(3,4).
mapa(4,1).
mapa(4,2).
mapa(4,3).
mapa(4,4).

existe_acima(X,Y):-
    mapa(X,Y),
    Z is Y + 1,
    mapa(X,Z).

existe_abaixo(X,Y):-
    mapa(X,Y),
    Z is Y - 1,
    mapa(X,Z).

existe_direita(X,Y):-
    mapa(X,Y),
    Z is X + 1,
    mapa(Z,Y).

existe_esquerda(X,Y):-
    mapa(X,Y),
    Z is X - 1,
    mapa(Z,Y).