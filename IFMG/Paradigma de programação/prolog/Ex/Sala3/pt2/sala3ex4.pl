#!/usr/bin/swipl

exist([],0).
exist([H|T],Ele):-
    Ele =:= H;
    exist(T,Ele).
    