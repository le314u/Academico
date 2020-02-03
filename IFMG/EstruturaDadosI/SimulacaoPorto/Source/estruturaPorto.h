#ifndef estruturaPorto_h
#define estruturaPorto_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Includes
#include "filaDinamica.h"
#include "estruturaTravessa.h"
#include "estruturaAreaAtracamento.h"

// Defines
#define MaximoChegadaNavios 3
#define MinimoChegadaNavios 0
#define NumeroAreaAtracamento 4
#define NumeroTravessa 5

// Structs
typedef struct Porto_s
{
   int id;
   AreaAtracamento *areaAtracamento;
   Travessa *travessa;
   Fila filaChegada;
   Navio **filaDespacho;
   int quantidadeNaviosChegaram;
} Porto;

// Prototipos
void GeraPorto(Porto *Instancia);

#endif