//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019


#ifndef OpenHash_H
    #define OpenHash_H
    #include "Palavra.h"
    #define TAMANHO_VETOR 1009
    //14159
    //1009

    typedef struct tabelaHash{
        Palavra **tabela;
        int tamanho;
        int nInsercao;
    }TabelaHash;


int hash1(char *palavra);
TabelaHash *IniciaOpenHash();
void InserirPalavraOpenHash(TabelaHash *openHash, char *palavra, int linha);
void PrintaOpenHash(TabelaHash *tabelaHash);
#endif