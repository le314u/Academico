//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Palavra.h"

//Adiciona um indice a palavra
Lista *addIndice(Lista *header, int pagina){
    //Se não tem lista, cria uma lista de indices
    if(header->primeiro == NULL){
        //Cria uma celula (seta primeiro e ultimo)
        header->primeiro = initCelula(pagina);
        header->ultimo = header->primeiro;
        header->tamanho++;
    //Se ja possui a Lista Adiciona um Indice
    }else{
        //Verifica se a pagina ja foi inserida na Lista
        if(header->ultimo->pagina >= pagina){
            //OBS:Neste trabalho os indices sempre virão na ordem crescente
            return header;
        }else{
            //Adiciona a Pagina a lista
            header->ultimo->proximo = initCelula(pagina);
            header->ultimo = header->ultimo->proximo;
            header->tamanho++;
        }
    }
    //retorna o ponteiro para a Lista
    return header;
}

//Inicia uma celula
Celula *initCelula(int pagina){
    //Aloca espaço para uma celula
    Celula *aux = malloc(sizeof(Celula));
    //Reseta proximo elemento
    aux->proximo = NULL;
    //Adiciona o numero da Pagina a lista
    aux->pagina = pagina;
    return aux; 
}

//Inicializa um objeto Palavra;
Palavra *initPalavra(char *palavra){
    //Aloca espaço para uma palavra
    Palavra *aux = malloc(sizeof(Palavra));
    //Seta a palavra
    aux->palavra = palavra;
    //Cria uma lista com as paginas que a palavra aparece
    aux->paginas = malloc(sizeof(Lista));
    //Como a palavra foi criada agora ela não aparece em nenhuma pagina
    aux->paginas->primeiro = NULL;
    aux->paginas->ultimo = NULL;
    aux->paginas->tamanho = 0;
    return aux;
}

//Printa uma Lista de inteiro
void percorreLista(Palavra instancia){
    Celula *temp = instancia.paginas->primeiro;
    int indice = 0;
    //Passa por toda a 
    while(temp != NULL){
        //Printa o valor
        printf("\t %d",temp->pagina);
        //passa para o proximo valor
        temp = temp->proximo;
    }
}