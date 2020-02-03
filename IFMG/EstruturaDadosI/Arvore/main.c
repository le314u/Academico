#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoArvore{
    int *elemento;
    struct ElementoArvore *esquerda;
    struct ElementoArvore *direita;
}No;

void InicializaNo(No *Instancia, int *Elemento){
    Instancia->esquerda = NULL;
    Instancia->direita = NULL;
    Instancia->elemento = Elemento;
}

void Insere(No *root, int *Elemento){
    No *aux = root ;
    //Chega ate um nó superior a folha
    while(aux->esquerda != NULL || aux->direita != NULL){
        //Achou
        if(*Elemento == *(aux->elemento)){
            return;
        }
        //Esquerda
        if(aux->esquerda != NULL){
            if(*Elemento < *(aux->elemento)){
                //vai para esquerda
                aux = aux->esquerda;
                continue;
            }
        }
        if(aux->direita != NULL){
            if(*Elemento > *(aux->elemento)){
                //vai para a direita
                aux = aux->direita;
                continue;
            }
        }
        break;
    }
    if(*Elemento < *(aux->elemento)){
        //vai para esquerda
        aux->esquerda = malloc(sizeof(No));
        InicializaNo(aux->esquerda, Elemento);
        return;
    }
    if(*Elemento > *(aux->elemento)){
        //vai para a direita
        aux->direita = malloc(sizeof(No));
        InicializaNo(aux->direita,  Elemento);
        return;
    }
}


int Pesquisa(No *root, int Elemento){
    No *aux = root ;
    if(Elemento == *(aux->elemento)){
        return 1;
    }
    //Chega ate um nó superior a folha
    while(aux->esquerda != NULL || aux->direita != NULL){
        //Encontrou
        if(Elemento == *(aux->elemento)){
            return 1;
        }

        //Verifica a Esquerda
        if(aux->esquerda != NULL){
            if(Elemento < *(aux->elemento)){
                //vai para esquerda
                aux = aux->esquerda;
                continue;
            }
        }

        //Verifica a Direitas
        if(aux->direita != NULL){
            if(Elemento > *(aux->elemento)){
                //vai para a direita
                aux = aux->direita;
                continue;
            }
        }
    }
    if(Elemento == *(aux->elemento)){
       return 1;
    }
    return 0;
}

int main(){
    printf("\nInicializou");
    //Inicializa Arvore
    int numeroElementos = 10;
    int vetorDados[10] = {5,9,8,7,4,15,3,14,13,1};
    No *root = malloc(sizeof(No));
    InicializaNo(root, &(vetorDados[0]));
    printf("\nVai inserir");
    //Insere Todos os elementos na Arvore
    for (int i = 1; i < numeroElementos; i++)
    {   
        printf("\nInserindo elemento [%d]",i);
        Insere(root, &(vetorDados[i]));
    }
    printf("\nInseriu todos");
    //Pesquisa o Elemento 'n'
    if(Pesquisa(root,4)){
        printf("\nEncontrou");
    }
    else{
        printf("\nFalhou");
    }
    return 0;
}
