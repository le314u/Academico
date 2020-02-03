#include "pilhaEstatica.h"
#include "estruturaTravessa.h"
#include <stdlib.h>

#define ERRO 0
#define OK 1

// Variavel Gloval
int idTravessa = 0;

//  Instancia Structs
void GeraTravessa(Travessa *Instancia)
{
   //seta idendificados Travessa
   Instancia->id = ++idTravessa;
   //Inicializa a Pilha de containers
   GeraPilha(&(Instancia->containers), MaximoContainersTravessa);
}
// Empihla um item na travessa
void EmpilhaTravessa(Travessa *Instancia, int Data)
{
   Empilha(&(Instancia->containers), Data);
}

//Switch Estado Travessa
//Emula um StradleCars transportando as travessas
int EmulaStradleCar(Travessa *Instancia)
{
   //É preferivel que um carro disponibilize novas travessas do que retire as cheias
   //Se tiver indisponivel ela volta a ser disponivel
   if (Instancia->containers.topo == -1)
   {
      ResetaPilha(&(Instancia->containers));
      return OK;
   }

   //Se travessa estiver Cheia fica indisponivel
   if (Instancia->containers.topo == Instancia->containers.tamanho)
   {
      Instancia->containers.topo = -1;
      return OK;
   }

   //Caso nao tenha interagido com a travessa
   return ERRO;
}

int TravessaDisponivel(Travessa *Instancia)
{

   //Travessa setada como Indisponivel
   if (Instancia->containers.topo == -1)
   {
      return ERRO;
   }

   //Se travessa estiver Cheia ela esta indisponivel
   if (Instancia->containers.topo == Instancia->containers.tamanho)
   {
      return ERRO;
   }

   //Caso travessa esteja disponivel
   return OK;
}
