#!/usr/bin/swipl

elem([H|T],Indice,Element):-
    elemIndice([H|T],Indice,0,Element).

elemIndice([H|T],Indice,IndiceRef,ELEM):-
    Indice =:= IndiceRef,
    ELEM = H;
    IndiceRef1 is IndiceRef + 1,
    elemIndice(T,Indice,IndiceRef1,ELEM).

main([],_,[]).
main([Hindice|Tpos],ListaElement,ListaRet):-
    elem(ListaElement,Hindice,Element),%Pega o elemento[i]
    main(Tpos,ListaElement,ListaAux),%Chama recursivamente até o caso Base
    %write(Element),write(Hindice),write(ListaAux),
    ListaRet = [Element|ListaAux].%Unifica as Listas
