#include "tadLista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _AbaixoMedia(Aluno *aluno, int Media){
    if(aluno->media < Media){
        printf("\n%s, tem media %.2f",aluno->nome,aluno->media);
    }
}

int _NomeIgual(char* Nome1, char* Nome2){
    if(strcmp(Nome1, Nome2) == 0){
        return 1;
    }else
    {
        return 0;
    }   
}
Celula* _CriaCelula(Aluno* Instancia){
    //Cria uma Celula
    Celula *celula = malloc(sizeof(Celula));
    //Aponta para Null afi mde evitar lixo
    celula->proximo = NULL;
    //Seta o Elemento
    celula->elemento = Instancia;
    //Retorna uma Celula

    return celula;
}


//Cria lista – inicialização da lista;
void CriaLista(Lista* Instancia){
    //Aloca uma Lista Setando seus valores para 0
    Instancia->primeiro=NULL;
    Instancia->tamanho=0;
}

//Insere na lista – Insira em ordem crescente de número de matrícula
void InsereNaLista(Lista* Instancia,Aluno* Elemento){
    Celula *aux = NULL;
    Celula *celula = Instancia->primeiro;

    //verifica se a Lista esta Vazia
    if(celula == NULL){
        Instancia->primeiro=_CriaCelula(Elemento);
        Instancia->tamanho++;
        return;
    }    

    //Primeiro Elemento
    if( (celula->elemento->matricula) >= (Elemento->matricula) ){
        //Elemento é menor
        aux = _CriaCelula(Elemento);
        aux->proximo = celula;
        Instancia->primeiro = aux;
        Instancia->tamanho++;
        return;
    }else if( (celula->proximo) == NULL){
        //Não é menor porem elemento é o ultimo
        celula->proximo = _CriaCelula(Elemento);
        Instancia->tamanho++;
        return;
    }
    //Percorre até o momento de inserir o elemento na lista
    while(celula->proximo != NULL){
        //Antes do Elemento
        if( (celula->proximo->elemento->matricula) >= (Elemento->matricula) ){
            //Elemento Menor
            aux = _CriaCelula(Elemento);
            aux->proximo = celula->proximo;
            celula->proximo = aux;
            Instancia->tamanho++;
            return;
        }
        
        //Não inseriu e vai para o proximo
        celula=celula->proximo;
    }
    //Depois do Elemento
    if( (celula->proximo) == NULL){
        celula->proximo = _CriaCelula(Elemento);
        Instancia->tamanho++;
        return;
    }
}

//Retira da lista – Retira um aluno que é referenciado pelo seu nome.
void RetiraAluno(Lista* Instancia,char* Nome){   
    //Lista Vazia
    if(Instancia == NULL){
        return;
    }
    //Lista Vazia
    if(Instancia->tamanho == 0){
        return;
    }
    //Variaveis
    Celula *aux = NULL;
    Celula *celula = Instancia->primeiro;
    char* NomeCelula = celula->elemento->nome;

    //Primeiro
    if(_NomeIgual(NomeCelula, Nome)){
        Instancia->primeiro = Instancia->primeiro->proximo;
        free(celula);
        Instancia->tamanho--;
        return;
    }
    //Demais Elementos
    while(celula->proximo != NULL){
        NomeCelula = celula->proximo->elemento->nome;
        if(_NomeIgual(NomeCelula, Nome)){
            aux = celula->proximo;  
            celula->proximo = celula->proximo->proximo;
            free(aux);
            Instancia->tamanho--;
            return;
        }
        celula=celula->proximo;

    }
    if(celula->proximo == NULL){
        NomeCelula = celula->elemento->nome;
        if(_NomeIgual(NomeCelula, Nome)){
            aux = celula->proximo;  
            celula->proximo = celula->proximo->proximo;
            free(aux);
            Instancia->tamanho--;
            return;
        }
    }
    
}

//Consulta na lista – Consulta os alunos que possuem média abaixo de um valor específico.
void ConsultaMedia (Lista* Instancia, float Media){
    Celula* celula = Instancia->primeiro;

    //Primeiro
    _AbaixoMedia(celula->elemento, Media);
    celula = celula->proximo;

    //Demais
    while(celula != NULL){
        _AbaixoMedia(celula->elemento, Media);
        celula = celula->proximo;
    }
}

