//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019

#ifndef ABB_H
    #define ABB_H
    #include "Palavra.h"

    

    //No Palavra
    typedef struct ElementoArvore{
        Palavra *elemento;
        struct ElementoArvore *esquerda;
        struct ElementoArvore *direita;
    }NoABB;

    NoABB *IniciaNoABB(char *palavra);
    NoABB *InserirPalavra(NoABB *aux, char *palavra, int linha);

    //Insere uma PalavraNaABB
    NoABB *IniciaNoABB(char *palavra);
    NoABB *InserirPalavraABB(NoABB *raiz, char *palavra, int linha);// Se Indice >= 1 salva os indices que a palavra apareceu





#endif