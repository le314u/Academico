#!/usr/bin/swipl

new([H|T],Ele,Ret):-
Ret = [Ele,H|T].