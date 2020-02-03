#ifndef TabelaHash_H
    #define TabelaHash_H
    typedef struct conjunto{
        int *conjunto;
        int tamanho;
    }Conjunto;

    int hash(int valor, int tamanho);
    Conjunto addEConjunto(Conjunto structConjunto, int valor);
    Conjunto interscecao(Conjunto structConjunto1,Conjunto structConjunto2);
    Conjunto uniao(Conjunto structConjunto1,Conjunto structConjunto2);
    int pertinenciaConjunto(Conjunto structConjunto, int valor);
    Conjunto criarConjunto(int *valores, int numeroValores);
    Conjunto rmEConjunto(Conjunto structConjunto, int valor);
#endif