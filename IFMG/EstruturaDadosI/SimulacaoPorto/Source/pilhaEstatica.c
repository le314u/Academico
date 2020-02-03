#include <stdlib.h>
#include "pilhaEstatica.h"

#define ERRO 0
#define OK 1

void GeraPilha(Pilha *Instancia, int Tamanho){
   //Gera a instancia de Um pilha
   Instancia->tamanho = Tamanho;
   Instancia->topo = 0;
   Instancia->elemento = malloc( sizeof(int) * Tamanho);
}

int Empilha(Pilha *Instancia, int Elemento){
   //Se a pilha não existe não há como empilhar
   if (Instancia == NULL) {
      printf("Não tem pilha");
      return ERRO;
   }
   //Se a pilha esta indisponivel não há como empilhar
   if(Instancia->topo == -1){
      printf("Pilha Indisponivel");
      return ERRO;
   }
   //Se a Pilha Estiver Cheia é impossivel Empilhar
   if(Instancia->topo >= Instancia->tamanho){
      printf("Pilha Cheia");
      return ERRO;
   }

   //Empilha
   Instancia->elemento[Instancia->topo] = Elemento;
   Instancia->topo++;
   return OK;
}

int Desempilha(Pilha *Instancia){
   //Se a pilha não existe não há como desempilhar
   if (Instancia == NULL) {
      return ERRO;
   }
   //Se a pilha esta indisponivel não há como desempihlar
   if(Instancia->topo == -1){
      return ERRO;
   }
   //Se a Pilha Estiver Vazia é impossivel Desempilhar
   if(Instancia->topo <= 0){
      return ERRO;
   }

   //Desempilha
   int elemento = Instancia->elemento[(Instancia->topo)-1];
   Instancia->elemento[(Instancia->topo)-1] = 0 ;
   Instancia->topo--;
   return elemento;
}

int ResetaPilha(Pilha *Instancia){
   Instancia->topo = 0;
   for(int i = 0; i < Instancia->tamanho; i++)
   {
      Instancia->elemento[i] = 0;
   }
   
}