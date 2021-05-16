#!/usr/bin/swipl

dup([],[]).
dup([H|T],Ret):-
    dup(T,RetAux),
    Ret = [H,H|RetAux].   