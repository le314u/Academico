#!/usr/bin/swipl

rec([Head|List],Tam):-
    (
        Head \== [],
        Tam = 1,
        !
    );
    (
        rec(List,Tam1), 
        Tam is Tam1+1
    ).

tamanho(List1,List2):-
    rec(List1,Tam1),
    rec(List2,Tam2),
    Tam1 == Tam2.

tamanho([a,a,a],[b,b,b]).