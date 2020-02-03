//////////////////////////////////////////////////////////////////////////////
//  LUCAS MATEUS FERNANDES 
//  RA 0035411
//
//	github : 1ldomal2
//  e-mail : lucasmfccom@gmail.com
//////////////////////////////////////////////////////////////////////////////

#include "pilha.h"
void CriaPilha(Pilha *instancia){
    instancia->tamanho=60;
    instancia->indice=0;
    instancia->vetor=malloc(61*sizeof(char));
}

int Empilha(Pilha *pilha, char caractere){
    if( (pilha->indice) < (pilha->tamanho) ){
        pilha->vetor[pilha->indice] = caractere;
        pilha->indice++;
        return 1;
        //Adicionou ok
    }
    return 0;
    //0 codigo de Erro
}

char Desempilha(Pilha *pilha){
    if(pilha->indice > 0){
        pilha->indice--;
        return pilha->vetor[pilha->indice];
    }
    //Codigo de Erro
}

void CriaPilhas(Pilha *listaPilha, int numeroPilhas){
    for(int i = 0; i < numeroPilhas; i++)
    {
        CriaPilha(&(listaPilha[i]));
    }
}