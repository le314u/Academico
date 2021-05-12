#!/usr/bin/swipl
joga(ana,volei).
joga(bia,tenis).
joga(ivo,basquete).
joga(eva,volei).
joga(leo,tenis).

parceiro(Name):-
    joga(Name,Sport),
    joga(Parceiro,Sport),
    Name \== Parceiro,
    write(Parceiro).
parceiro(leo).