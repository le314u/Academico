#!/usr/bin/swipl
%1
pai('Ivo','Eva').
pai('Rai','Noé').
pai('Gil','Rai').
pai('Gil','Clô').
pai('Gil','Ary').
pai('Ary','Gal').
mae('Ana','Eva').
mae('Eva','Noé').
mae('Lia','Gal').
mae('Bia','Rai').
mae('Bia','Clô').
mae('Bia','Ary').
%B
mulher('Ana').
mulher('Eva').
mulher('Clô').
mulher('Bia').
mulher('Lia').
mulher('Gal').
homem('Ivo').
homem('Noé').
homem('Rai').
homem('Gil').
homem('Ary').
%C
gerou(X,Y) :- 
    pai(X,Y); 
    mae(X,Y).
%D
filhx(Y,X) :-
    pai(X,Y);
    mae(X,Y).

filho(Y,X) :- 
    homem(Y),
    filhx(Y,X).

filha(Y,X) :-
    mulher(Y),
    filhx(Y,X).

vx(X,Y) :-
    gerou(X,Genitor),
    gerou(Genitor,Y).

vo(X,Y) :-
    homem(X),
    vx(X,Y).

voh(X,Y) :-
    mulher(X),
    vx(X,Y).

tix(X,Y) :-
    gerou(Ancestral,X),
    (  
        gerou(Ancestral,X),
        gerou(Ancestral,Genitor),
        gerou(Genitor,Y),
        X \== Genitor,
        !
    ).

tio(X,Y) :-
    homem(X),
    tix(X,Y).

tia(X,Y) :-
    mulher(X),
    tix(X,Y).

primx(X,Y) :-
    vx(Ancestral,X),
    vx(Ancestral,Y),
    X \== Y.

primo(X,Y) :-
    homem(X),
    primx(X,Y).

prima(X,Y) :-
    mulher(X),
    primx(X,Y).