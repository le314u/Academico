#!/usr/bin/swipl

come(urso,peixe).
come(peixe,peixinho).
come(peixinho,alga).
come(peixe,alga).
come(urso,raposa).
come(veado,grama).
come(peixe,minhoca).
come(urso,guaxinim).
come(raposa,coelho).
come(urso,veado).
come(lince,veado).
come(planta_carnívora,mosca).
come(veado,planta_carnívora).
animal(urso).
animal(peixe).
animal(raposa).
animal(veado).
animal(minhoca).
animal(lince).
animal(coelho).
animal(guaxinim).
animal(mosca).
animal(peixinho).
planta(grama).
planta(alga).
planta(planta_carnívora).

%a
c_peixe(X):- %Urso e Peixe
    come(X,peixe);
    come(X,peixinho).
    
%b
animal(X).% urso peixe raposa veado minhoca lince coelho guaxinim mosca peixinho

%c
come(X,Y). % urso peixe | peixe peixinho | peixinho alga | peixe alga | urso raposa | veado grama | peixe minhoca | urso guaxinim | raposa coelho | urso veado | lince veado | planta_carnívora mosca | veado planta_carnívora |

%d
carnivoro(X):-
    come(X,Y),
    animal(Y).

herbivoro(X):-
    come(X,Y),
    planta(Y).
    
predador(X):-
    carnivoro(X),
    animal(X).

presa(Y):-
    animal(Y),
    come(X,Y).

cacado(X):-
    presa(X).

%Não funciona
pertence_a_cadeia(X,Y):-
    come(Y,X);
    (
        come(Y,Aux),
        pertence_a_cadeia(Aux,X)
    ),!.