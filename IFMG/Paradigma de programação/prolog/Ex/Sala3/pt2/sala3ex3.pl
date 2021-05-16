#!/usr/bin/swipl

last([],[]]).
last(Lista,Ele):-
    [H|T]=Lista,
    last(T,Ele1),
    Ele1 == []],
    Ele is H.
