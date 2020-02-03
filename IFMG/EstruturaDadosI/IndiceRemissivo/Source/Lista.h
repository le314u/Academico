//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019

#ifndef Lista_H
    #define Lista_H
    #include "Palavra.h"

    //Celula Palavra
    typedef struct CelulaP{
        Palavra *elemento;
        struct CelulaP *proxima;
        struct CelulaP *anterior;
    }CelulaP;

    //Lista de  Palavras
    typedef struct ListaP{
        int tamanho;
        CelulaP *inicio;
    }ListaP;
        
    CelulaP *IniciaCelulaP(char *palavra);
    ListaP *IniciaListaP();
    ListaP *InserirPalavraLista(ListaP *lista, char *palavra, int linha);
#endif