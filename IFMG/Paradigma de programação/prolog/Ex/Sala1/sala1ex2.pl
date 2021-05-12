#!/usr/bin/swipl

start() :- consult(['sala1ex1.pl']).
start().

%a
feliz(X):-
    gerou(X,Y).
%b
casal(X,Y):-
    gerou(X,Filhx),
    gerou(Y,Filhx).

