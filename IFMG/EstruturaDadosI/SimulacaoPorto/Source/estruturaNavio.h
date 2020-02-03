#ifndef estruturaNavio_h
#define estruturaNavio_h

// Defines
#define MaximoContainers 16
#define MinimoContainers 4
#define NumeroPilhasContainersNavio 4
#define NumeroMaximoContainersNaPilha 4

// Includes
#include "pilhaEstatica.h"

// Structs
typedef struct Navio_s
{
   int id;                 //Id
   Pilha *pilhaContainers; //Pilha com no maximo 16 elementos
   int tempoEntrada;       //Unidade de tempo que esperou
} Navio;

void GeraNavio(Navio *Instancia);
int NavioValido(Navio Instancia);
int NumeroContainersNavio(Navio *Instancia);
void DeletaNavio(Navio *navio);

#endif