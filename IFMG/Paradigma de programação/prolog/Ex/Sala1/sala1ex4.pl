#!/usr/bin/swipl

row(1,ana,1000.90,[ary]).
row(2,bia,1200.00,[]).
row(3,ivo,903.50,[rai,eva]).
%a
dependentes(Name):-
    row(_,Name,_,Dep),
    write(Dep).
dependentes(ivo).
%b
dep(X,[X|_]).
dep(X,[_|T]):- dep(X,T).
ancestral(Name):-
    (
        row(_,Ances,_,Dep),
        dep(Name,Dep)
    ),
    write(Ances).
ancestral(ary).
%c
depInf(Val):-
    (
        row(_,_,Val,Dep),
        Val < 950.00,
        write(Dep)
    ).

depInf(X).
%d
notDep(Name):-
    (
        row(_,Name,_,Dep),
        Dep == []
    ),
    write(Name).
notDep(X).

