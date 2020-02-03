//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019


#ifndef AnaliseEntrada_H
    #define AnaliseEntrada_H
    #include "Palavra.h"
    #include "Lista.h"
    #include "ABB.h"
    #include "AVL.h"
    #include "OpenHash.h"
    #include "ListaHash.h"

    typedef struct tad{
        //Estrutura
        ListaP *LISTA;
        NoABB *ABB;
        NoAVL *AVL;
        TabelaHash *HASH;
        TabelaListaHash *HASH_LISTA;

        //Tempo processamento
        float timePABB;
        float timePAVL;
        float timePHASH;
        float timePHASH_LISTA;
        float timePLISTA;

        //Tempo exibição
        float timeEABB;
        float timeEAVL;
        float timeEHASH;
        float timeEHASH_LISTA;
        float timeELISTA;
    }TAD;
    
    TAD *leituraTexto(char *nomeArquivoTexto, TAD *tadEstrutura);
    TAD *leituraTreinamento(char *nomeArquivoPalavras);
    TAD *initEstrutura();
    TAD *tadInserirAVL(TAD *estrutura, char *palavra, int pagina);
    TAD *tadInserirABB(TAD *estrutura, char *palavra, int pagina);
    TAD *tadInserirLISTA(TAD *estrutura, char *palavra, int pagina);
    TAD *tadInserirHASH(TAD *estrutura, char *palavra, int pagina);
    TAD *tadInserirHASH_LISTA(TAD *estrutura, char *palavra, int pagina);
    
    void entrada(char *nomeArquivo);
    char *lerPalavra(FILE *arquivo);
    char *tiraPontuacao(char* string);
    int criterioParada(FILE *arquivo);


#endif