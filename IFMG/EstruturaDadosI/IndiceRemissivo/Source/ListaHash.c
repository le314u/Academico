//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Palavra.h"
#include "TratamentoString.h"
#include "ListaHash.h"
#include "Lista.h"
#define INVALIDO -1
int _indiceMenorPalavra(CelulaP **nCelulasP);

//Função Hash em cima da string
int hash2(char *palavra){
    //Pega o tamanho da palavra
    int tamanho = strlen(palavra);
    int valor = 0;
    //Gera um Hash
    for(int i = 0 ; i < tamanho; i++){
        valor += (int) palavra[i]-'0';
    }
    //Padroniza para caber no vetor original
    int valorHash = valor +(valor << 1);
    //1010 1010 1010 1010
    int mascara1 = valorHash & 43690;
    //1001 1001 1001 1001
    int mascara2 = valorHash & 39321;
    //0101 0101 0101 0101
    int mascara3 = valorHash & 1365;
    //0110 0110 0110 0110
    int mascara4 = valorHash & 26214;
    //1000 1000 1000 1000
    int mascara5 = valorHash & 34952;
    //0001 0001 0001 0001
    int mascara6 = valorHash & 4369;
    int hash = (mascara1 - mascara2 + (mascara5 - (mascara3 + mascara4)) + mascara6);
    return abs(hash % TAMANHO_VETOR_LISTA);
}

TabelaListaHash *IniciaListaHash(){
    //Cria uma tabela com 'n' listas Hash
    TabelaListaHash *listaHash = malloc(sizeof(TabelaListaHash));
    listaHash->tabela = malloc(TAMANHO_VETOR_LISTA * sizeof(ListaP*));
    //Inicia Todas as N Listas
    for(int i=0 ; i<TAMANHO_VETOR_LISTA; i++){
        listaHash->tabela[i] = NULL;      
    }
    return listaHash;
}

void InserirPalavraListaHash(TabelaListaHash *listaHash, char *palavra, int linha){
    //Faz o Hash do elemento
    int indice = hash2(palavra);
    //Todo o tratamento de linha < 1 e linhas >=1 ja foi implementado na TAD lista
    listaHash->tabela[indice] = InserirPalavraLista(listaHash->tabela[indice], palavra, linha); 
}

int TotalPalavrasListaHash(TabelaListaHash *tabelaHash){
    int totalPalavras = 0;
    for(int i=0; i<TAMANHO_VETOR_LISTA; i++){
        if(tabelaHash->tabela[i] != NULL){
            totalPalavras += tabelaHash->tabela[i]->tamanho;
        }
    }
    return totalPalavras;
}

void PrintaListaHash(TabelaListaHash *tabelaHash){
    //Numero de Palavras alocadas
    int totalPalavras = 0;
    totalPalavras = TotalPalavrasListaHash(tabelaHash);
    //Cria um vetor auxiliar que contem os elementos em ordem
    Palavra **newTabela = malloc(totalPalavras * sizeof(Palavra*));
    //possui menor celula não transferida para 'newTabela' de cada lista;
    CelulaP **nTabelas = malloc(TAMANHO_VETOR_LISTA * sizeof(CelulaP*));
    //instancia nTabelas com a celula inicial de cada ListaP
    for(int i=0; i<TAMANHO_VETOR_LISTA; i++){
        if(tabelaHash->tabela[i] != NULL){
            nTabelas[i] = tabelaHash->tabela[i]->inicio;
        }else{
            nTabelas[i] = NULL;
        }
    }
    //Transfere de nTabelas para newTabela
    for(int i=0; i<totalPalavras; i++){
        //Descobre a menor Palavra valida
        int indiceMenor = _indiceMenorPalavra(nTabelas);
        if(indiceMenor != INVALIDO){
            //Salva a nova Palavra
            newTabela[i] = nTabelas[indiceMenor]->elemento;
            //Muda para a proxima;
            nTabelas[indiceMenor] = nTabelas[indiceMenor]->proxima;
        }
    }
    //Printa em ordem
    for (int i = 0; i < totalPalavras; i++){
        if(newTabela[i] != NULL)
        {
            //Printa Palavra
            printf("\n%s",newTabela[i]->palavra);
            //Printa os indice
            percorreLista(*newTabela[i]);
        }
    }
    free(nTabelas);
    free(newTabela);
}

int _indiceMenorPalavra(CelulaP **nCelulasP){
    int indice = INVALIDO;
    for(int i=0; i<TAMANHO_VETOR_LISTA; i++){
        //Verifica se é possivel fazer o calculo
        if(nCelulasP[i] != NULL){
            //Verifica se ja pegou alguma palavra como base
            if(indice != INVALIDO){
                //Faz o calculo e salva o indice da menor Palavra
                int flagMenor = ordemAlfabetica(nCelulasP[i]->elemento->palavra, nCelulasP[indice]->elemento->palavra);
                if(flagMenor == MENOR){
                    indice = i;
                }
            }else{
                indice = i;
            }
        }
    }
    return indice;
}