//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019


#ifndef Palavra_H
    #define Palavra_H

    //Celula Lista
    typedef struct celula{
        int pagina;
        struct celula *proximo;
    }Celula;

    //Header Lista
    typedef struct lista{
        int tamanho;
        Celula *primeiro;
        Celula *ultimo;
    }Lista;

    //Palavra
    typedef struct palavra{
        char *palavra;//Palavra
        Lista *paginas;//Vetor que guarda a lista com as linhas em que a palavra aparece
    }Palavra;


    //Palavra
    Palavra *initPalavra(char *palavra);

    //Lista de Indices
    void percorreLista(Palavra instancia);
    Celula *initCelula(int pagina);
    Lista *addIndice(Lista *header, int pagina);

#endif