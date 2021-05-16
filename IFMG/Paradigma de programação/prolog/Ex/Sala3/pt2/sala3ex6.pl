#!/usr/bin/swipl

tamanho([],0).
tamanho([H|T],Tam):-
    tamanho(T,Tam1),
    Tam is Tam1 + 1.