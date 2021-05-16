#!/usr/bin/swipl

consec([],_,_).
consec([E1,E2|T],Ele1,Ele2):-
    E1 =:= Ele1,
    E2 =:= Ele2;
    consec([E2|T],Ele1,Ele2).

    