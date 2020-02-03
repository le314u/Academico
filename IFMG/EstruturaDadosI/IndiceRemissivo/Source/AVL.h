//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019


#ifndef AVL_H
    #define AVL_H
    #include "Palavra.h"
    #define MENOR 1
    #define MAIOR 2
    #define IGUAL 0
    //Estrutura Arvore Avl
    typedef struct NoAVL {
        Palavra *elemento;
        int balanceamento;
        struct NoAVL *esquerda;
        struct NoAVL *direita;
    }NoAVL;
    NoAVL *InserirPalavraAVL(NoAVL *raiz, char *palavra, int linha);


#endif

