#!/usr/bin/swipl
%país(Nome, Área, População)
pais(brasil, 9, 130).
pais(china, 12, 1800).
pais(eua, 9, 230).
pais(índia, 3, 450).

%a
densidade(Pais,Dens):-
    pais(Pais,Area,Pop),
    Dens is Pop/Area.

densidade(brasil,Dens).
%b
dif(Pais1,Pais2,PopTotal):-
    pais(Pais1, _, Pop1),
    pais(Pais2, _, Pop2),
    PopTotal is Pop2 - Pop1.

dif(china,india,T).

%c
areaEq(Pais1,Pais2):-
    pais(Pais1, X, _),
    pais(Pais2, Y, _),!,
    X==Y.
areaEq(brasil,eua).
