#!/usr/bin/swipl

concatena([],Lista2,R):-
    R = Lista2.

concatena([H|T],Lista2,R):-
    concatena(T,Lista2,Raux),
    R = [H|Raux].

concatena(X,Y,[1,2,3,4,5]).