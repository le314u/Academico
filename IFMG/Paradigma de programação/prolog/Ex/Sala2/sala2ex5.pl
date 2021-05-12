#!/usr/bin/swipl

troca12(Lista1, Lista2):-
    [A,B|C]=Lista1,
    [B,A|D]=Lista2.

troca12([1,2,3,4,5],[2,1,3,4,5]).