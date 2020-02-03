#ifndef log_h
#define log_h

// Includes
#include "estruturaPorto.h"
#include "estruturaNavio.h"
#include "estruturaTravessa.h"
#include "estruturaAreaAtracamento.h"
#include "filaDinamica.h"
#include "pilhaEstatica.h"

// Defines
#define DiretorioArquivo ~home
#define NomeArquivo "Log.txt"

// Prototipos
FILE *CriaArquivo();
void FechaArquivo(FILE *arquivo);
void EscreveArquivoTexto(FILE *Instancia, char *texto);
void EscreveArquivoDivisao(FILE *Instancia);
void JsonPorto(FILE *Instancia, Porto *porto);
void JsonTravessa(FILE *Instancia, Travessa *travessa);
void JsonAreaAtracamento(FILE *Instancia, AreaAtracamento *areaAtracamento);
void JsonNavio(FILE *Instancia, Navio *navio);
void JsonFilaBarcos(FILE *Instancia, Fila *fila);
void JsonPilhaContainers(FILE *Instancia, Pilha *pilha);

#endif