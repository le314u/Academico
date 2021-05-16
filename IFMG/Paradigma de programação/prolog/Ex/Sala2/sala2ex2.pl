#!/usr/bin/swipl

tamanho([], 0).
tamanho(List,Tam):.
        [H|T]=List,
        tamanho(T,Tam1),
        Tam is Tam1+1.

tamanho_igual(L1,L2):-
    tamanho(L1,T1),
    tamanho(L2,T2),
    T1 == T2.

tamanho_igual([a,a,a],[b,b,b]).