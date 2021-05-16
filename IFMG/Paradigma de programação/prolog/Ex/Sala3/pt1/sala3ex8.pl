#!/usr/bin/swipl

homem(pedro).
homem(marcos).
homem(ze).
mulher(maria).
mulher(joana).
idade(ze,30).
idade(maria,40).
idade(marcos,20).
idade(pedro,25).
idade(joana,28).
gosta(ze,aventura).
gosta(maria,comedia).
gosta(joana,romance).
gosta(marcos,terror).
gosta(marcos,romance).
gosta(pedro,romance).
gosta(maria,romance).
opcao(ze,20,40).
opcao(pedro,25,55).
opcao(marcos,20,21).
opcao(maria,25,55).
opcao(joana,28,30).

%a
afinidade_filme(X,Y):-
    gosta(X,Z),
    gosta(Y,Z).

%b
casal(X,Y):-
    (
      homem(X),
      mulher(Y)  
    );
    (
        homem(Y),
        mulher(X)
    ).

%c
casal_afinidade_filme(X,Y):-
    casal(X,Y),
    afinidade_filme(X,Y).

%d
casal_afinidade_idade(X,Y):-
    casal(X,Y),
    (
        idade(Y,Ida2),
        idade(X,Ida1),
        opcao(X,IMin1,IMax1),
        opcao(Y,IMin2,IMax2),
        (
            Ida2 >= IMin1,
            Ida2 =< IMax1
        ),
        (
            Ida1 >= IMin2,
            Ida1 =< IMax2
        )
    ).

%e
casal_total(X,Y):-
    casal_afinidade_idade(X,Y),
    casal_afinidade_filme(X,Y).

%f
%afinidade_filme(X,Y).
%casal(X,Y).
%casal_afinidade_filme(X,Y).
%casal_afinidade_idade(X,Y).
%casal_total(X,Y).