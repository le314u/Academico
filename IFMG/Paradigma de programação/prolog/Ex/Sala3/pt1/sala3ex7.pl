#!/usr/bin/swipl

semana(segunda).
semana(terca).
semana(quarta).
semana(quinta).
semana(sexta).
final(sabado).
final(domingo).

dia(X):-
    semana(X);
    final(X).
