#!/usr/bin/swipl

italiana(pizza).
italiana(calzone).
italiana(lazanha).
mineira(tutu).
mineira(feijoada).
gaucha(churrascada).
uruguaia(churrascada).
argentina(churrascada).
paraguaia(churrascada).

%a
brasileira(X):-
    mineira(X);
    gaucha(X).

%b
italiana(lazanha).
%c
brasileira(tutu).
%d
brasileira(X).
%e
brasileira(X),uruguaia(X).