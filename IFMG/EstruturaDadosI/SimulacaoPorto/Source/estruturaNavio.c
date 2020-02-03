#include "estruturaNavio.h"
#include <time.h>
#include <stdlib.h>

#define ERRO 0
#define OK 1

// Variavel Global
int idNavio = 0;

//Instancia um navio respeitando a regra de Negocio pre estabelecida
void GeraNavio(Navio *Instancia)
{
    //Seta o Id do Navio atraves de uma variavel Globals
    Instancia->id = ++idNavio;

    //Gera numero de containers que o navio terá
    int numeroContainers = MinimoContainers + (rand() % (MaximoContainers - MinimoContainers) + 1);

    //Gera as Pilhas de containers 'Vetor de Pilhas'
    Instancia->pilhaContainers = malloc(NumeroPilhasContainersNavio * sizeof(Pilha));
    for (int i = 0; i < NumeroPilhasContainersNavio; i++)
    {
        GeraPilha(&(Instancia->pilhaContainers[i]), NumeroMaximoContainersNaPilha);
    }

    //Distribui os containers nas pilhas de Containers de forma uniforme
    for (int i = 1; i <= numeroContainers; i++)
    {
        Empilha(&(Instancia->pilhaContainers[i % NumeroPilhasContainersNavio]), 1);
    }


    //Seta as unidades de tempo de cada barco
    Instancia->tempoEntrada = -1;
}
void DeletaNavio(Navio *navio){
    int quantidadeContainers = 0;
    for(int i = 0; i < NumeroPilhasContainersNavio; i++)
    {
        quantidadeContainers += navio->pilhaContainers[i].tamanho;
    }
    
    if(!quantidadeContainers){
        free(navio->pilhaContainers);
        free(navio);
    }
}

int NavioValido(Navio Instancia)
{
    if (Instancia.id == 0)
    {
        return ERRO;
    }
    else
    {
        return OK;
    }
}

int NumeroContainersNavio(Navio *Instancia)
{
    int numeroContainers = 0;
    //Se não há barco não da pra analisa-lo
    if (Instancia == NULL)
    {
        return ERRO;
    }
    //Se Há Barco mas não a pilhas há um erro
    if (Instancia->pilhaContainers == NULL)
    {
        return ERRO;
    }
    //Verifica Quantidade de ContainersNavio;
    
    for (int indice = 0; indice < NumeroPilhasContainersNavio; indice++)
    {
        numeroContainers += Instancia->pilhaContainers[indice].topo;
    }
    //retorna Quantidade Containers Navio
    return numeroContainers;
}
