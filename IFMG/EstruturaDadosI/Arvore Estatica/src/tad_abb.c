#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tad_abb.h"

void InicializaNo(No *Instancia, int *elemento);
void InsereElementoArvore(No *root, int *elemento);
No *Folha(No *no, int *elemento);
void InOrdem(No *no);
No *Pesquisa(No *no, int elemento);
int TamanhoArvore(No *root);
void _TransfereVetor(No *no, int *vetor, int *x);
void printaVetor(int **vetor, int tamanho);





//Inicializa um No
void InicializaNo(No *Instancia, int *elemento){
    Instancia->esquerda = NULL;
    Instancia->direita = NULL;
    Instancia->elemento = elemento;
}
//insere um Elemento na Arvore
void InsereElementoArvore(No *root, int *elemento){
    No *aux = Folha(root, elemento);
    //Verifica de retorno de Folha é valido
    if(aux != NULL){

        //Insere a Esquerda
        if(*elemento < *aux->elemento){
            aux->esquerda = malloc(sizeof(No*));
            InicializaNo(aux->esquerda, elemento);
            

        }else if(*elemento > *aux->elemento){
        //Insere a Direita
            aux->direita = malloc(sizeof(No*));
            InicializaNo(aux->direita, elemento);
        }
    }else{
        printf("\nFolha retornou um elemento NULL");
    }
}

//Vai ate uma folha e a retorna 
No *Folha(No *no, int *elemento){
    //Chegou no Fim
    if( (no->esquerda == NULL) && (no->direita == NULL) ){
        return no;
    }
    //Vai para Esquerda
    if(no->esquerda != NULL){
        if(*elemento < *no->elemento){
            return Folha(no->esquerda, elemento);
        }
    }
    //Vai para a Direita
    if(no->direita != NULL){
        if(*elemento > *no->elemento){
            return Folha(no->direita, elemento);
        }
    }
    //Possivel Folha Nunca chega
    if(*no->elemento != *elemento){
        return no;
    }else{
    //Erro Elemento ja esta na Arvore
        printf("\nElemento ja esta na ARVORE");
        return NULL;
    }
}

//Percorre a Arvore de forma "Crescente"
void InOrdem(No *no){
    //Chegou no Fim
    if( (no->esquerda == NULL) && (no->direita == NULL) ){
        return;
    }
    //Vai para Esquerda
    if(no->esquerda != NULL){
        InOrdem(no->esquerda);
    }
    //Faz Processamento


    //Vai para a Direita
    if(no->direita != NULL){
        InOrdem(no->direita);
    }
}


//Percorre a Arvore de forma "Crescente"
void ApagaElementos(No *no){
    ////Vai para Esquerda
    if(no->esquerda != NULL){
        InOrdem(no->esquerda);
    }

    //Vai para a Direita
    if(no->direita != NULL){
        InOrdem(no->direita);
    }
    free(no->elemento);
    free(no);
}

void _TransfereVetor(No *no, int *vetor, int *x){

    //Vai para Esquerda
    if(no->esquerda != NULL){
        _TransfereVetor(no->esquerda,vetor,x);
    }
    //Faz Processamento
    vetor[*x]=*(no->elemento);
    (*x)++;

    //Vai para a Direita
    if(no->direita != NULL){
        _TransfereVetor(no->direita,vetor,x);
    }
}

//Retorna o no que possui o elemento 'x'
No *Pesquisa(No *no, int elemento){
    //Vai para Esquerda
    if(no->esquerda != NULL){
        if(elemento < *no->elemento){
            return Pesquisa(no->esquerda, elemento);
        }
    }

    //Vai para a Direita
    if(no->direita != NULL){
        if(elemento > *no->elemento){
            return Pesquisa(no->direita, elemento);
        }
    }
    //Chegou no Fim
    if( (no->esquerda == NULL) && (no->direita == NULL) ){
        if(*no->elemento == elemento){
            return no;
        }else{
            return NULL;
        }
    }
}

void _tamanho(No *no, int *tamanho){

    //Vai para Esquerda
    if(no->esquerda != NULL){
        _tamanho(no->esquerda, tamanho);
    }
    
    //Faz Processamento
    (*tamanho)++;

    //Vai para a Direita
    if(no->direita != NULL){
        _tamanho(no->direita, tamanho);
    }
}

int TamanhoArvore(No *root){
    int tamanho = 0 ;
    _tamanho(root, &tamanho);
    return tamanho;
}

void printaVetor(int **vetor, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ",*vetor[i]);
    }
}

void printaListaNos(No **vetor, int tamanho){
    int nivel=0;
    for (int i = 0; i < tamanho; i++)
    {   
        if((i+1) >= pow(2,nivel)){
            nivel++;
            printf("\n");
        }
        printf("%d ",*(vetor[i]->elemento));
    }
}
////////////////////////////////////////
//METODOS EXTERNOS
////////////////////////////////////////



void IniciaABB(No *root){
    int *elemento = malloc(sizeof(int));
    *elemento=0;
    printf("\nDigite um numero para ser a raiz da arvore:");
    scanf("%d",elemento);
    InicializaNo(root, elemento);
    
}

void InsereABB(No *root){
    int *elemento = malloc(sizeof(int));
    *elemento=0;
    printf("\nDigite um numero para inserir na arvore:");
    scanf("%d",elemento);
    InsereElementoArvore(root, elemento);
    
}

void TamanhoABB(No *root){
    int tamanho = TamanhoArvore(root);
    printf("\nTamanho = %d\n", tamanho);
}

void PesquisaABB(No *root){
    int elemento=0;
    printf("\nDigite um numero para ser pesquisado na arvore:");
    scanf("%d",&elemento);
    No *aux = Pesquisa(root, elemento);
    if(aux != NULL){
        printf ("\n[%d] esta presente na Arvore",*aux->elemento);
    }else{
        printf ("\n[%d] NÃO esta presente na Arvore",elemento);
    }
}


void VaiPara(No *no, int **vetor, int min, int max){
    if(min==max){
        InsereElementoArvore(no ,(vetor[min]));
        return;
    }else{
        int ordinalArredondado = (int)ceil((((float)(max-min)+1)/2));
        int arredondado = (min + ordinalArredondado-1);
        int menor = arredondado-1;
        int maior = arredondado+1;
        //Coloca Arredondado
        InsereElementoArvore(no ,(vetor[arredondado]));
        //Espera um Enter
        //char A; scanf("%c",&A);
        if(!(menor<min)){
            VaiPara(no, vetor, min, menor);
        }
        if(!(maior>max)){
            VaiPara(no, vetor, maior, max);
        }
    }
}

No* BalanceiaABB(No *root){
    //Tamanho da Arvore
    int tamanho = TamanhoArvore(root);
    //Inicializa Vetor
    int *vetor = malloc(tamanho * sizeof(int));
    int *indice = malloc(sizeof(int));
    *indice=0;
    //Transfere da Arvore para um vetor
    _TransfereVetor(root, vetor, indice);
    //Tranfere do vetor de inteiro para um vetor de ponteiro para inteiro ( Necessário para persistirem os dados na Arvore)
    int **vetorPtr = malloc(sizeof(int *) * tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        vetorPtr[i]=malloc(sizeof(int));
        *(vetorPtr[i])=vetor[i];
    }
    //Deleta o vetor de Inteiro e fica apenas com vetor de vetor
    free(vetor);

    //Reseta
    ApagaElementos(root);
    root= malloc(sizeof(No));
    

    InicializaNo(root,vetorPtr[(int)ceil((tamanho-1)/2)]);
    VaiPara(root,vetorPtr,0,tamanho-1);
    return root;
}

void NiveisABB(No *root){
    //Descobre o tamanho da Arvore;
    int tamanho = TamanhoArvore(root);

    //Cria uma Lista
    No **niveis = malloc(sizeof(No *) * tamanho);
    int indice = 0;

    //Passa a raiz para a lista de Nós
    niveis[0] = root;

    //Passa os demais nos para a raiz
    int tamanhoRelativo = 1;
    for (int i = 0; i < tamanho; i++)
    {   
        if(niveis[i]->esquerda != NULL){
            niveis[tamanhoRelativo] = niveis[i]->esquerda;
            tamanhoRelativo++;
        }
        if(niveis[i]->direita != NULL){
            niveis[tamanhoRelativo] = niveis[i]->direita;
            tamanhoRelativo++;
        }
    }
    //Printa o vetor Por Lista
    printaListaNos(niveis,tamanho);
}


