#!/usr/bin/swipl

elem([H|T],Indice):-
    elemIndice([H|T],Indice,0,ELEM).

elemIndice([H|T],Indice,IndiceRef,ELEM):-
    Indice =:= IndiceRef,
    ELEM = H;
    IndiceRef1 is IndiceRef + 1,
    elemIndice(T,Indice,IndiceRef1,ELEM).
    