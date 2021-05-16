#!/usr/bin/swipl

tamanho([],0).
tamanho(Lista,Tamanho):-
    [H|T]=Lista,
    tamanho(T,Tamanho1),
    Tamanho is Tamanho1 +1.

eq(L1,L2):-
    tamanho(L1,T1),
    tamanho(L2,T2),
    T1 == T2.