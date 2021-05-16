#!/usr/bin/swipl

sum([],0).
sum([H|T],Val):-
    sum(T,Val1),
    Val is Val1 + H.