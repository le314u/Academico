//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019
#include <stdio.h>
#include <stdlib.h>
#include "Palavra.h"
#include "TratamentoString.h"
#include "ABB.h"

void _InserirPalavraABB(NoABB *aux, char *palavra, int linha);

NoABB *IniciaNoABB(char *palavra){
    //Aloca um NoAbb 'Raiz'
    NoABB *Instancia = malloc(sizeof(NoABB));
    //Seta Filhos como NULL ou seja é uma folha
    Instancia->esquerda = NULL;
    Instancia->direita = NULL;
    //Aloca a Palavra
    Instancia->elemento = NULL;
    Instancia->elemento = initPalavra(palavra);
    return Instancia;
}

//Insere uma PalavraNaABB
NoABB *InserirPalavraABB(NoABB *raiz, char *palavra, int linha){
    //Caso a Raiz ja tenha sido alocada
    if(raiz != NULL){
        _InserirPalavraABB(raiz, palavra, linha);
        return NULL;
    }else{
    //Caso a raiz não tenha sido alocada
        raiz = IniciaNoABB(palavra);
        return raiz;
    }    
}

void _InserirPalavraABB(NoABB *aux, char *palavra, int linha){

    //Verifica a precedencia das palavras
    int indiceLado = ordemAlfabetica(palavra,aux->elemento->palavra);

    //São Iguais logo a palavra ja esta inserida
    if(indiceLado == IGUAL){

        //Verifica se a linha é valida 
        if(linha >= 1){
            aux->elemento->paginas = addIndice(aux->elemento->paginas, linha);
        }else{
            //Palavra ja foi adicionada
        }
    }

    //Esquerda
    if(indiceLado == MENOR){
        if(aux->esquerda != NULL){
            //vai para esquerda
            _InserirPalavraABB(aux->esquerda, palavra, linha);
        }else{
            if(linha < 1){
                //Cria um novo no
                aux->esquerda = IniciaNoABB(palavra);
            }
        }
    }

    //Direita
    if(indiceLado == MAIOR){
        if(aux->direita != NULL){
            //vai para direita
            _InserirPalavraABB(aux->direita, palavra, linha);
        }else{
            //Cria um novo No
            if(linha < 1){
                aux->direita = IniciaNoABB(palavra);
            }
        }
    }
}