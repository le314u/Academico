#include "filaDinamica.h"
#include "estruturaNavio.h"
#include <stdlib.h>

void GeraFila(Fila *Instancia){
   Instancia->tamanho = 0;
   Instancia->primeiro = NULL;
   Instancia->ultimo = NULL;
}

Elemento GeraElemento(Navio *Dado){
   //Gera um elemento
   Elemento novaCelula;
   //Tira o lixo de memoria do ponteiro
   novaCelula.proximo = NULL;
   //Insere o dado no elemento
   novaCelula.elemento = Dado;
   //Retorna elemento
   return novaCelula;
}

void Enfileira(Fila *Instancia, Navio *Dado){ 
   
   //Gera uma celula com o Dado passado por parametro
   Elemento *celula = malloc(sizeof(Elemento));
   *celula = GeraElemento(Dado);
   //Caso a Fila  não esteja vazia
   if(Instancia->tamanho != 0){

      //Coloca o Dado na fila
      Instancia->ultimo->proximo = celula;
      
      
      //Muda o ponteiro ultimo7
      Instancia->ultimo = Instancia->ultimo->proximo;
      
      
      //Muda o tamanho
      Instancia->tamanho++;
   //Caso a Fila esteja Vazia
   }else{
      Instancia->ultimo = celula;
      Instancia->primeiro = celula;
      Instancia->tamanho++;
   //Caso a Fila Não Esteja Vazia
   }
   

}

Navio *Desenfileira(Fila *Instancia){
   //Se a Fila Estiver Vazia é impossivel Desenfileirar
   if(Instancia->tamanho == 0){
      return NULL;

   //Desenfileira
   }else{
      //Salva o elemento a ser retornado
      Navio *retorno = (Instancia->primeiro->elemento);

      //Exclui o elemento da fila atualizando o ponteiro 'primeiro'
      Elemento *elemento = Instancia->primeiro;
      Instancia->primeiro = Instancia->primeiro->proximo;
      free(elemento);

      //Diminui o tamanho da fila
      Instancia->tamanho--;

      //Retorna o elemento
      return retorno;
   }
}

void ResetFila(Fila *Instancia){
   while(Instancia->tamanho == 0){
      free(Desenfileira(Instancia));
   }
}

void Temporizador(Fila *Instancia){
   Elemento *aux = Instancia->primeiro;
   for (int i = 0; i < Instancia->tamanho; i++)
   {
      aux->elemento->tempoEntrada++;
      aux = aux->proximo;
   }
   
}
