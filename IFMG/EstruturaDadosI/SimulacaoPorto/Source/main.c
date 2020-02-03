#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estruturaPorto.h"
#include "estruturaNavio.h"
#include "estruturaTravessa.h"
#include "estruturaAreaAtracamento.h"
#include "filaDinamica.h"
#include "pilhaEstatica.h"
#include "log.h"
#include "view.h"

// Defines
#define MaximoChegadaNavios 3
#define MinimoChegadaNavios 0
// Prototipos função
void ControleChegada(Fila *Instancia, Porto *porto);
void ControleTravessa(Travessa *travessas);
void ControleAreasAtracamento(AreaAtracamento *areasAtracamento, Navio **FilaDespacho);
void ControleGruas(Porto *porto);
void ControlePorto(Porto *porto);
int _MelhorTravessa(Travessa *travessas);
void Log(FILE *Instancia, Porto *porto);
int _MelhorAreaAtracamento(AreaAtracamento *areasAtracamento);
void _EscalonaNavios(Fila *Instancia, AreaAtracamento *areasAtracamento);
void _Espera();
//Verifica se chegou um navio e o aloca
void ControleChegada(Fila *Instancia, Porto *porto)
{
    
    srand(time(NULL));
    int numeroNavios = rand() % ((MaximoChegadaNavios - MinimoChegadaNavios) + 1) + MinimoChegadaNavios;
    //Enfileira os Navios que chegaram
    porto->quantidadeNaviosChegaram = numeroNavios;
    for (int i = 0; i < numeroNavios; i++)
    {
        //Aloca um ponteiro para um Navio
        Navio *navio = malloc(sizeof(Navio));
        GeraNavio(navio);
        //Enfileira o Navio criado
        Enfileira(Instancia, navio);
    }
    _EscalonaNavios(Instancia, porto->areaAtracamento);
}

//Renova as travessas Disponiveis
void ControleTravessa(Travessa *travessas)
{
    
    //Tem um stradle car para cada area de atracamento
    int numeroStradleCar = NumeroAreaAtracamento;

    //Percorre todas as travessas
    for (int i = 0; (i < NumeroTravessa) && (numeroStradleCar >= 0); i++)
    {
        //Se tiver interagido com a travessa reduz o numero de carros disponiveis
        numeroStradleCar -= EmulaStradleCar(&(travessas[i]));
    }
}

//Controla a Alocação de Navios nas Areas de Atracamento
void ControleAreasAtracamento(AreaAtracamento *areasAtracamento, Navio **FilaDespacho)
{
    //
    //Passa por todas as Areas de Atracamento
    for (int indiceAreaAtracamento = 0; indiceAreaAtracamento < NumeroAreaAtracamento; indiceAreaAtracamento++)
    {   
        //Adiciona uma unidade de tempo a todos os navios presentes na fila
        Temporizador(&(areasAtracamento[indiceAreaAtracamento].filaLocal));
        //Tenta Despachar um Navio
        FilaDespacho[indiceAreaAtracamento] = DespachaNavioAreaAtracamento(&areasAtracamento[indiceAreaAtracamento]);
        //TentaAtracar um Navio
        AtracaNavio(&areasAtracamento[indiceAreaAtracamento]);
    }
}

void ControleGruas(Porto *porto)
{
    
    //Passa por todas as Areas de Atracamento OBS há uma Grua em cada Area
    for (int indiceGrua = 0; indiceGrua < NumeroAreaAtracamento; indiceGrua++)
    {
        //Tenta desempilhar um container do navio atracado
        int indiceMelhorTravessa = _MelhorTravessa((porto->travessa));
        if(indiceMelhorTravessa != -1){
            TransferenciaNavioParaTravessa(&(porto->areaAtracamento[indiceGrua]), &(porto->travessa[indiceMelhorTravessa]));
        }
    }
    
}

void _Espera(){
    int lento =  1000000000;
    int medio =  500000000;
    int rapido = 50000000;
    int ultra = 1;
    for(int i = 0; i < medio; i++){}
}

int _MelhorTravessa(Travessa *travessas)
{
    int indiceMelhorTravessa = -1;
    int quantidadeContainers = -2;
    //Percorre todas as travessas
    for (int indiceTravessa = 0; (indiceTravessa < NumeroTravessa); indiceTravessa++)
    {
        //Verifica se a travessa esta ativa
        if (TravessaDisponivel(&(travessas[indiceTravessa])))
        {
            //Verifica se a travessa é a melhor das ja analisadas
            if (travessas[indiceMelhorTravessa].containers.topo > quantidadeContainers)
            {
                indiceMelhorTravessa = indiceTravessa;
                quantidadeContainers = travessas[indiceMelhorTravessa].containers.topo;
            }
        }
    }
    return indiceMelhorTravessa;
}

void Log(FILE *Instancia, Porto *porto)
{
    //Cabeçalho
    EscreveArquivoDivisao(Instancia);

    JsonPorto(Instancia, porto); //Porto
    for (int i = 0; i < NumeroTravessa; i++)
    {
        JsonTravessa(Instancia, &(porto->travessa[i])); //Travessa
    }
    
    for (int i = 0; i < NumeroAreaAtracamento; i++)
    {
        JsonAreaAtracamento(Instancia, &(porto->areaAtracamento[i]));
    }
}

int _MelhorAreaAtracamento(AreaAtracamento *areasAtracamento)
{
    //Verifica qual a melhor fila para se alocar o barco
    int indiceMenorFila = 0;
    int valorMenorFila = areasAtracamento[0].nContainersFila;
    //Procura a Area de atracamento com Menor Fila
    for (int indiceArea = 0; indiceArea < NumeroAreaAtracamento; indiceArea++)
    {
        if (areasAtracamento[indiceArea].nContainersFila <= valorMenorFila)
        {
            valorMenorFila = areasAtracamento[indiceArea].nContainersFila;
            indiceMenorFila = indiceArea;
        }
    }
    return indiceMenorFila;
}

void _EscalonaNavios(Fila *Instancia, AreaAtracamento *areasAtracamento)
{

    //Escalona 'n' Navios
    for (int nNavios = 0; nNavios < Instancia->tamanho; nNavios++)
    {  
        //Verifica qual a melhor fila para se alocar o barco
        int indiceMenorFila = _MelhorAreaAtracamento(areasAtracamento);
        //Tira o Navio da fila de chegada e o direciona a uma fila de espera para desempilhamento
        Navio *navio = Desenfileira(Instancia);
                AddNavioAreaAtracamento(&(areasAtracamento[indiceMenorFila]), navio);
    }
}

int main()
{
    //Instancia Log
    FILE *log = CriaArquivo();

    //Gera um Porto
    Porto porto;
    GeraPorto(&porto);

    //Roda nUnidade de tempo;
    while(1){
        //Controla a chegada de Navios no Porto
        ControleChegada(&(porto.filaChegada), &porto);
        
        //Gerencia os stradle cars
        ControleTravessa(porto.travessa);
        
        //Controle da FilaLocal de cada Area
        ControleAreasAtracamento(porto.areaAtracamento, porto.filaDespacho);

        //Manipula as Gruas
        ControleGruas(&porto);
        
        //Printa eTapa;
        Estado(&porto);

        //Log
        Log(log, &porto);
        _Espera();
        
    }
    FechaArquivo(log);
}