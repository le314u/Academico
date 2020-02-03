#ifndef estruturaAreaAtracamento_h
#define estruturaAreaAtracamento_h
#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"
#include "estruturaTravessa.h"
#include "estruturaAreaAtracamento.h"

// Define
#define MaximoContainersTravessa 5

// Structs
typedef struct AreaAtracamento_s
{
   int id;       //
   Navio *navio; //Navio que esta na AreaAtracamento
   Fila filaLocal;
   int nContainersFila;
} AreaAtracamento;

// Prototipo
void GeraAreaAtracamento(AreaAtracamento *Instancia);
void AddNavioAreaAtracamento(AreaAtracamento *InstanciaAreaAtracamento, Navio *InstanciaNavio);
void AtracaNavio(AreaAtracamento *Instancia);
int TransferenciaNavioParaTravessa(AreaAtracamento *InstanciaAreaAtracamento, Travessa *InstanciaTravessa);
Navio *DespachaNavioAreaAtracamento(AreaAtracamento *Instancia);
int NavioAtracado(AreaAtracamento *Instancia);

#endif