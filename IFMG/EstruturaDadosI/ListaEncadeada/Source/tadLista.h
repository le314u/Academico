#ifndef lista_h
#define lista_h
#include "structAluno.h"



typedef struct tadCelula{
    struct tadCelula *proximo;
    Aluno *elemento;    
}Celula;

typedef struct tadLista
{
    struct tadCelula *primeiro;
    int tamanho;
}Lista;



void CriaLista(Lista* Instancia);
void InsereNaLista(Lista* Instancia,Aluno* Elemento);
void RetiraAluno(Lista* Instancia,char* Nome);
void ConsultaMedia (Lista* Instancia, float Media);


#endif