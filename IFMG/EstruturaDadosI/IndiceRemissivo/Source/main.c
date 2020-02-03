//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019
#include <stdio.h>
#include <stdlib.h>
#include "TratamentoString.h"
#include "AnaliseEntrada.h"
#include "ABB.h"
#include "Clock.h"

void InOrdenABB(NoABB *aux);
void InOrdenAVL(NoAVL *aux);
void PercorreLISTA(ListaP *lista);

int main(int argc, char const *argv[])
{

    //Pega o Arquivo de palavras validas
    char *nomeArquivoTreinamento = (char*)argv[1];

    //Pega o Arquivo com o texto
    char *nomeArquivoTexto = (char*)argv[2];

    TAD *estrutura = NULL;

    //Arquivo Treinamento
    estrutura = leituraTreinamento(nomeArquivoTreinamento);

    //Arquivo Texto
    estrutura = leituraTexto(nomeArquivoTexto, estrutura);

    //Printa As Estruturas;
    printf("\n\n\nLISTA\n\n");
    float auxTimeILISTA = start();
    PercorreLISTA(estrutura->LISTA);
    float auxTimeFLISTA = stop();
    estrutura->timeELISTA += delta(auxTimeILISTA, auxTimeFLISTA);

    printf("\n\n\nABB\n\n");
    float auxTimeIABB = start();
    InOrdenABB(estrutura->ABB);
    float auxTimeFABB = stop();
    estrutura->timeEABB += delta(auxTimeIABB, auxTimeFABB);

    printf("\n\n\nAVL\n\n");
    float auxTimeIAVL = start();
    InOrdenAVL(estrutura->AVL);
    float auxTimeFAVL = stop();
    estrutura->timeEAVL += delta(auxTimeIAVL, auxTimeFAVL);

    printf("\n\n\nHASH_OPEN\n\n");
    float auxTimeIHASH = start();
    PrintaOpenHash(estrutura->HASH);
    float auxTimeFHASH = stop();
    estrutura->timeEHASH += delta(auxTimeIHASH, auxTimeFHASH);

    printf("\n\n\nHASH_LISTA\n\n");
    float auxTimeIHASH_LISTA = start();
    PrintaListaHash(estrutura->HASH_LISTA);
    float auxTimeFHASH_LISTA = stop();
    estrutura->timeEHASH_LISTA += delta(auxTimeIHASH_LISTA, auxTimeFHASH_LISTA);


    printf("\n\n\nRelatorio\n\n");
    printf("\n\nTime Processamento LISTA %.15f",estrutura->timePLISTA);
    printf("\nTime Exibição LISTA %.15f",estrutura->timeELISTA);
    printf("\n\nTime Processamento ABB %.15f",estrutura->timePABB);
    printf("\nTime Exibição ABB %.15f",estrutura->timeEABB);
    printf("\n\nTime Processamento AVL %.15f",estrutura->timePAVL);
    printf("\nTime Exibição AVL %.15f",estrutura->timeEAVL);
    printf("\n\nTime Processamento HASH_OPEN %.15f",estrutura->timePHASH);
    printf("\nTime Exibição HASH_OPEN %.15f",estrutura->timeEHASH);
    printf("\n\nTime Processamento HASH_LISTA %.15f",estrutura->timePHASH_LISTA);
    printf("\nTime Exibição HASH_LISTA %.15f",estrutura->timeEHASH_LISTA);
    printf("\n");

    return 0;
}


















//Metodos Internos para Exebição da Estrutura adequada
void InOrdenABB(NoABB *aux){
    //Esquerda
    if(aux->esquerda != NULL)
        InOrdenABB(aux->esquerda);

    printf("\n%s",aux->elemento->palavra);
    percorreLista(*(aux->elemento));
    //Direita
    if(aux->direita != NULL)
        InOrdenABB(aux->direita);
}

void InOrdenAVL(NoAVL *aux){
    //Esquerda
    if(aux->esquerda != NULL)
        InOrdenAVL(aux->esquerda);
    
    printf("\n%s",aux->elemento->palavra);
    percorreLista(*(aux->elemento));
    //Direita
    if(aux->direita != NULL)
        InOrdenAVL(aux->direita);
}

void PercorreLISTA(ListaP *lista){
    CelulaP *aux = lista->inicio;
    while(aux != NULL){
        printf("\n%s",aux->elemento->palavra);
        percorreLista(*(aux->elemento));
        aux = aux->proxima;
    }
}
