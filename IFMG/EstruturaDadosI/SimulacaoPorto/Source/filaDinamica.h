#ifndef filaDinamica_h
#define filaDinamica_h

// Includes
#include "estruturaNavio.h"

// Structs
typedef struct ElementoEncadeado{
   struct ElementoEncadeado *proximo;
   Navio *elemento;
}Elemento;

typedef struct FilaEncadeada{
   struct ElementoEncadeado *primeiro;
   struct ElementoEncadeado *ultimo;
   int tamanho;
}Fila;


// Prototipos
void GeraFila(Fila *Instancia);
Elemento GeraElemento(Navio *Dado);
void Enfileira(Fila *Instancia, Navio *Dado);
Navio *Desenfileira(Fila *Instancia);
void ResetFila(Fila *Instancia);
void Temporizador(Fila *Instancia);
#endif