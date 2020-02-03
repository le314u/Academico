#include "view.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturaPorto.h"
#include "estruturaNavio.h"
#include "estruturaTravessa.h"
#include "estruturaAreaAtracamento.h"
#include "filaDinamica.h"
#include "pilhaEstatica.h"

void _Cabecalho(){
    system("clear");
    printf("#########################################################################################################################################");
    printf("\n#                         SIMULADOR DE PORTO                                                                                              #");
    printf("\n# RA:0035411                                                                                                                              #");
    printf("\n# Nome:Lucas Mateus Fernandes                                                                                                             #");
    printf("\n#                                                                                                                                         #");
    printf("\n#########################################################################################################################################\n");
}
void _ChegadaNavios(int NumeroNavios){
    printf("\n");
    printf("Chegaram : %d Navios\n",NumeroNavios);
    printf("\n____________________________________________________________________________________________________________________________________________");
}
void _AreaAtracamento(AreaAtracamento *areaAtracamento){
    //Numero de Navios que chegaram7
    printf("\nArea Atracamento:\n");
    
    //Id Area Atracamento
    printf("\n");
    for(int i = 0; i < NumeroAreaAtracamento; i++)
    {
        printf("Id: %d\t\t\t",areaAtracamento[i].id);
    }
    
    //Tamanho Fila
    printf("\n");
    for(int i = 0; i < NumeroAreaAtracamento; i++)
    {
        printf("Em espera: %d\t\t",areaAtracamento[i].filaLocal.tamanho);
    }

    printf("\n");
    for(int i = 0; i < NumeroAreaAtracamento; i++)
    {
        printf("Total containers: %d\t",areaAtracamento[i].nContainersFila);
    }
    
    //Possui Barco Atracado  
    printf("\n");
    for(int i = 0; i < NumeroAreaAtracamento; i++)
    {
        printf("Atracamento: ");
        if(areaAtracamento[i].navio != NULL){
            printf("Operante");
        }else{
            printf("Ocioso");
        }
        printf("\t");
    }
    printf("\n____________________________________________________________________________________________________________________________________________");

}

void _Travessa(Travessa *travessa){
    printf("\nTravessa:\n");
    //Estado Travessa
    
    //Id Travessa
    printf("\n");
    for(int i = 0; i < NumeroTravessa; i++)
    {
        printf("Id: %d\t\t\t",travessa[i].id);
    }

    //Numero de itens empilhados
    printf("\n");
    for(int i = 0; i < NumeroTravessa; i++)
    {   
        printf("Containers: ");
        if(travessa[i].containers.topo != -1){
            printf("%d\t\t",travessa[i].containers.topo);
        }else{
            printf("trans.\t");
        }
    }

    //Disponibilidade
    printf("\n");
    for(int i = 0; i < NumeroTravessa; i++)
    {
        printf("Disponivel: ");
        if(TravessaDisponivel(&(travessa[i]))){
            printf("Sim");
        }
        else{
            printf("Não");
        }
        printf("\t\t");
    }
    printf("\n\n____________________________________________________________________________________________________________________________________________");

}
void _Navio(Navio **Despacho){
    printf("\nNavio:\n");
    //Estado Navio
    
    //Id Navio
    printf("\n");
    for(int i = 0; i < NumeroAreaAtracamento; i++)
    {
        if(Despacho[i]!= NULL){
            printf("Id: %d\t\t\t",Despacho[i]->id);
        }
    }

    //Tempos Espera
    printf("\n");
    for(int i = 0; i < NumeroAreaAtracamento; i++)
    {
        if(Despacho[i] != NULL){
            printf("Unidade Tempo: %d\t",Despacho[i]->tempoEntrada);
            DeletaNavio(Despacho[i]);
            free(Despacho[i]);
        }
    }

    printf("\n\n____________________________________________________________________________________________________________________________________________\n");

}


void Estado(Porto *porto){
    _Cabecalho();
    _ChegadaNavios(porto->quantidadeNaviosChegaram);
    _AreaAtracamento(porto->areaAtracamento);
    _Travessa(porto->travessa);
    _Navio(porto->filaDespacho);
}
