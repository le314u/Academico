#!/usr/bin/swipl

%Escreva uma regra com o predicado duasVezes(Entrada, Saida) onde o argumento da esquerda é uma lista, e o argumento da direita é outra contendo todos os elementos da esquerda duas vezes. Por exemplo, para a consulta: duasVezes([a,4,teste],X). deve-se retornar X = [a,a,4,4,teste,teste]).

duasVezes([],[]).
duasVezes(Entrada, Saida):-
    [He|Te]=Entrada,
    duasVezes(Te,NewSaida),
    Saida=[He,He|NewSaida].

duasVezes([1,2,3],A).