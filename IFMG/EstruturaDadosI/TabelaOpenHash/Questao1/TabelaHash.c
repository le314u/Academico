//Tamanho do conjunto foi passado de 1000 para 1009 pois assim da um numero primo
//Por não usar ponteiro para ponteiro Obrigatoriamente tem um valor no conjunto
//Portanto o numero 0 não podera fazer parte do Conjunto ou seja
//a posição  que o valor for zero esta simulando NULL
#define TAMANHO 1009
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "TabelaHash.h"

int hash(int valor, int tamanho){
    //1010 1010 1010 1010
    int mascara1 = valor & 43690;
    
    //1001 1001 1001 1001
    int mascara2 = valor & 39321;

    //0101 0101 0101 0101
    int mascara3 = valor & 1365;

    //0110 0110 0110 0110
    int mascara4 = valor & 26214;

    //1000 1000 1000 1000
    int mascara5 = valor & 34952;

    //0001 0001 0001 0001
    int mascara6 = valor & 4369;

    int hash = (mascara1 - mascara2 + (mascara5 - (mascara3 + mascara4)) + mascara6);

    return (abs(hash) % tamanho );
}

Conjunto addEConjunto(Conjunto structConjunto, int valor){
    int *conjunto = structConjunto.conjunto;
    int tamanhoConjunto = structConjunto.tamanho;

    int indice = hash(valor, tamanhoConjunto);
    int indiceInicial = indice;
    int numeroColisao=0;
    do{
        //Tenta inserir na posição 'indice'
        if(conjunto[indice]==0){
            //esta Vazia ou seja da para preencher
            conjunto[indice] = valor;
            break;
        }
        //Não esta vazia mas verifica se o numero ja foi inserido ali
        if(conjunto[indice]==valor){
            //numero ja esta no conjunto
            break;    
        }
        //Indica que Houve Colisao
        numeroColisao++;
        //Passa para o proximoElemento
        indice = (indice + 1) % tamanhoConjunto;

    //ja Deu uma volta
    }while((indice % tamanhoConjunto) != indiceInicial);

    //retorna o conjunto
    return structConjunto;
}

Conjunto interscecao(Conjunto structConjunto1, Conjunto structConjunto2){
    int *conjunto1 = structConjunto1.conjunto;
    int tamanho1 = structConjunto1.tamanho;

    int *conjunto2 = structConjunto2.conjunto;
    int tamanho2 = structConjunto2.tamanho;

    Conjunto conjuntoIntersecao;
    int *valores = malloc(sizeof(int));
    int tamanho=0;

    for (int i = 0; i < tamanho1; i++)
    {
        //Verifica se o valor esta presente nos dois conjuntos
        if(pertinenciaConjunto(structConjunto2, conjunto1[i])){
            tamanho++;
            valores = (int*)realloc(valores, tamanho * sizeof(int) );
            valores[tamanho-1]=conjunto1[i];
        }
    }
    //Cria o esqueleto do conjunto
    conjuntoIntersecao.conjunto = malloc( tamanho * sizeof(int));
    conjuntoIntersecao.tamanho = tamanho;
    conjuntoIntersecao.conjunto = (int*) memset(conjuntoIntersecao.conjunto, 0, conjuntoIntersecao.tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        conjuntoIntersecao = addEConjunto(conjuntoIntersecao, valores[i]);  
    }
    //Apaga o ponteiro;
    free(valores);
    return conjuntoIntersecao;
}

Conjunto uniao(Conjunto structConjunto1, Conjunto structConjunto2){
    int *conjunto1 = structConjunto1.conjunto;
    int tamanho1 = structConjunto1.tamanho;

    int *conjunto2 = structConjunto2.conjunto;
    int tamanho2 = structConjunto2.tamanho;

    Conjunto conjuntoIntersecao;
    int *valores;
    int tamanho=0;
    //Mesmo que a especificação fala que o tamanho maximo do conjunto seja 1000 2 conjuntos de 1000 podem gerar um conjunto de 1000 até 2000 elementos
    //Cria o esqueleto do conjunto como nao sei o tamanho certo irei colocar que o tamanho sera a soma dos 2 conjuntos (isso nao garante o tamanho certo mas garante o tamanho maximo)
    conjuntoIntersecao.conjunto = malloc( (tamanho1+tamanho2) * sizeof(int));
    conjuntoIntersecao.tamanho = tamanho1+tamanho2;
    conjuntoIntersecao.conjunto = (int*) memset(conjuntoIntersecao.conjunto, 0, conjuntoIntersecao.tamanho * sizeof(int));

    for (int i = 0; i < tamanho1; i++)
    {
        conjuntoIntersecao = addEConjunto(conjuntoIntersecao, conjunto1[i]);  
    }
    for (int i = 0; i < tamanho2; i++)
    {
        conjuntoIntersecao = addEConjunto(conjuntoIntersecao, conjunto2[i]);  
    }
    //Apaga o ponteiro;
    return conjuntoIntersecao;
}


int pertinenciaConjunto(Conjunto structConjunto, int valor){
    int *conjunto=structConjunto.conjunto;
    int tamanhoConjunto=structConjunto.tamanho;

    int indice = hash(valor, tamanhoConjunto);
    int indiceInicial = indice;
    int pertence=0;
    do{
        //Verifica se esta na posição 'indice'
        if(conjunto[indice]==valor){
            //numero ja esta no conjunto
            pertence = 1;
            break;    
        }
        //Passa para o proximoElemento
        indice = (indice + 1) % tamanhoConjunto;

    //ja Deu uma volta
    }while((indice % tamanhoConjunto) != indiceInicial);

    //retorna o conjunto
    return pertence;
}

Conjunto criarConjunto(int *valores, int numeroValores){
    if(numeroValores > TAMANHO){
        printf("\nValores Extrapola %d elementos",TAMANHO);
        numeroValores = TAMANHO;
    }

    //Cria Esqueleto do Conjunto
    Conjunto structConjunto;
    structConjunto.conjunto = malloc(numeroValores * sizeof(int));
    structConjunto.conjunto = (int*) memset(structConjunto.conjunto, 0, numeroValores * sizeof(int));
    structConjunto.tamanho = numeroValores;

    //Preenche o conjunto
    for(int i=0; i<numeroValores ; i++){
        structConjunto = addEConjunto(structConjunto, valores[i]);
    }
    return structConjunto;
}

Conjunto rmEConjunto(Conjunto structConjunto, int valor){
    int *conjunto = structConjunto.conjunto;
    int tamanhoConjunto = structConjunto.tamanho;

    int indice = hash(valor, tamanhoConjunto);
    int indiceInicial = indice;
    int numeroVerificacao=0;
    do{
        //Não esta vazia mas verifica se aquele é o numero
        if(conjunto[indice]==valor){
            //Apaga o valor
            conjunto[indice]=0;
            break;    
        }
        //Indica que Houve Colisao
        numeroVerificacao++;
        //Passa para o proximoElemento
        indice = (indice + 1) % tamanhoConjunto;

    //ja Deu uma volta
    }while((indice % tamanhoConjunto) != indiceInicial);

    //retorna o conjunto
    return structConjunto;
}
