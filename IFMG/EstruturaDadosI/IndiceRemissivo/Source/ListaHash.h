//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019


#ifndef ListaHash_H
    #define ListaHash_H
    #include "Lista.h"
    #include "Palavra.h"
    #define TAMANHO_VETOR_LISTA 14159
    //1009

    typedef struct tabelaListaHash{
        ListaP **tabela;
    }TabelaListaHash;

    int hash2(char *palavra);
    TabelaListaHash *IniciaListaHash();
    void InserirPalavraListaHash(TabelaListaHash *listaHash, char *palavra, int linha);
    int TotalPalavrasListaHash(TabelaListaHash *tabelaHash);
    void PrintaListaHash(TabelaListaHash *tabelaHash);


#endif