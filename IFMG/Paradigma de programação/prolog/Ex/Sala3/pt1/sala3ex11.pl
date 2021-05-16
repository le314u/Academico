#!/usr/bin/swipl

presidente(sarney, 1985, 1990).
presidente( collor , 1990, 1992).
presidente(itamar, 1992, 1995).
presidente(fhc, 1995, 2003).
presidente( lula , 2003, 2011).
presidente(dilma,2012,2018).

presidente_em(Ano,Presidente):-
    presidente(Presidente,Ini,Fim),
    Ano >= Ini,
    Ano =< Fim.
