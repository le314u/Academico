//////////////////////////////////////////////////////////////////////////////
//  LUCAS MATEUS FERNANDES 
//  RA 0035411
//
//	github : 1ldomal2
//  e-mail : lucasmfccom@gmail.com
//////////////////////////////////////////////////////////////////////////////
#ifndef PILHA_H
    #define PILHA_H
    #include <stdio.h>
    #include <stdlib.h>
    typedef struct{
        int tamanho;
        int indice;
        char *vetor;
        //[0~59] é dado e tem 60 posiçoes
        //[60] é a 61 posição e tem \0
    }Pilha;
    void CriaPilhas(Pilha *listaPilha, int numeroPilhas);
    void CriaPilha(Pilha *instancia);
    int Empilha(Pilha *pilha, char caractere);
    char Desempilha(Pilha *pilha);
#endif


