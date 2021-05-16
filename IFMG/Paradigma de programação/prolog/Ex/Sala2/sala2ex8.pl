#!/usr/bin/swipl

train(eins,um).
train(zwei,dois).
train(drei,tres).
train(vier,quatro).
train(fuenf,cinco).
train(sechs,seis).
train(sieben,sete).
train(acht,oito).
train(neun,nove).

listatrain([],[]). %Caso Base
listatrain([Ha|Ta],Lp):-
    listatrain(Ta,P),%Chama rec até caso Base
    train(Ha,Hp),%Converte A->P
    Lp = [Hp|P].%Preenche a variavel LP Com a conversão e o que foi mandado para Recursão
    