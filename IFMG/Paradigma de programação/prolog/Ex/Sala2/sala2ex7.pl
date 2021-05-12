#!/usr/bin/swipl

% Crie dois fatos para definir respectivamente linhas verticais e horizontais. Você pode definir fatos com nível inferior chamados "linha" e dentro de linhas outro chamado "ponto" criando assim um termo complexo.

dentro(irina,natasha).
dentro(natasha,olga).
dentro(olga,katarina).

in(Me,Ma):-
    dentro(Me,Ma);
    (
        Me \== Ma,
        inAux(Me,Ma)
    ).

inAux(Me,Ma):-
    Me \== Ma,
    (
        (
            dentro(Me,Aux),
            Aux == Ma,
            !
        );
        (
            Me \== Ma,
            inAux(Aux,Ma)  
        )
    ).

% Não consigo parar no caso de False