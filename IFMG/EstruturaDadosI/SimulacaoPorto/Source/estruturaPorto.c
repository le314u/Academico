#include <stdlib.h>

#include "filaDinamica.h"
#include "estruturaAreaAtracamento.h"
#include "estruturaTravessa.h"
#include "estruturaPorto.h"
#include "estruturaNavio.h"

#define ERRO 0
#define Ok 1

// Variavel Global
int idPorto = 0;

// Prototipos Funçoes Locais
void _InstanciaNAreaAtracamento(Porto *Instancia, int numeroAreaAtracamento);
void _InstanciaNTravessa(Porto *Instancia, int numeroTravessa);

//  Instancia Structs
void GeraPorto(Porto *Instancia)
{
    //Seta id
    Instancia->id = ++idPorto;
    //Gera a quantidade de AreaAtracamento necessária
    _InstanciaNAreaAtracamento(Instancia, NumeroAreaAtracamento);
    //Gera a quantidade de Travessas necessária
    _InstanciaNTravessa(Instancia, NumeroTravessa);
    //Instancia Fila de Escalonamento (onde os barcos chegam primeiro antes de ir para cada Area de Atracamento)
    GeraFila(&(Instancia->filaChegada));
    //Instancia Fila de Despacho Utilizada apenas para printar na tela
    Instancia->filaDespacho = malloc(NumeroAreaAtracamento * sizeof(Navio *));
    for (int i = 0; i < NumeroAreaAtracamento; i++)
    {
        Instancia->filaDespacho[i] = NULL;
    }
    
    //Evita Lixo de memoria na chegada de Navios
    Instancia->quantidadeNaviosChegaram = 0;
}

//  Metodos Internos
void _InstanciaNAreaAtracamento(Porto *Instancia, int numeroAreaAtracamento)
{
    Instancia->areaAtracamento = malloc(numeroAreaAtracamento * sizeof(AreaAtracamento));
    for (int indiceAreaAtracamento = 0; indiceAreaAtracamento < numeroAreaAtracamento; indiceAreaAtracamento++)
    {
        GeraAreaAtracamento(&(Instancia->areaAtracamento[indiceAreaAtracamento]));
    }
}

void _InstanciaNTravessa(Porto *Instancia, int numeroTravessa)
{
    Instancia->travessa = malloc(numeroTravessa * sizeof(Travessa));
    for (int indiceTravessa = 0; indiceTravessa < numeroTravessa; indiceTravessa++)
    {
        GeraTravessa(&(Instancia->travessa[indiceTravessa]));
    }
}