#!/usr/bin/swipl

segundo(X,Lista):-
    [A,X|T]=Lista.

segundo(2,[1,2,3]).