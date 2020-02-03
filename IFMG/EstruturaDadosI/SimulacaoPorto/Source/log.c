#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturaPorto.h"
#include "estruturaNavio.h"
#include "estruturaTravessa.h"
#include "estruturaAreaAtracamento.h"
#include "filaDinamica.h"
#include "pilhaEstatica.h"

// Defines
#define ERRO 0
#define OK 1

//FuncaoLocal;
char* _Recuo(int numeroRecuo);
void _MoreOne(FILE *Instancia);

//VariavelGlobal
int numeroRecuo = 0;

//Cria um arquivo
FILE* CriaArquivo(){
    //Cria um arquivo
    FILE *arquivo;
    //Seta o nome e o modo de opreção
    arquivo = fopen(NomeArquivo,"w+");
    //retorna o arquivo
    return arquivo;
}
//Fecha o arquivo
void FechaArquivo(FILE *arquivo){
    //Verifica se existe um arquivo
    if(arquivo != NULL){
        //fecha o arquivo
        fclose(arquivo);
    }
}
void EscreveArquivoTexto(FILE *Instancia, char *texto){
    //Escreve o texto no arquivo
    fprintf(Instancia,"%s",texto);
}
void EscreveArquivoDivisao(FILE *Instancia){
    //String de Divisao
    char *Divisao = "\n\n";
    //Escreve o texto no arquivo
    fprintf(Instancia,"\n%s\n",Divisao);
}

void JsonPorto(FILE *Instancia, Porto *porto){
/*
    Porto{
        id:"",
        numeroAreaAtracamento:"",
        numeroTravessas:"",
        filaChegada:""
    }
*/
    char *recuo = _Recuo(numeroRecuo);
    //Escreve Json no arquivo Log
    fprintf(Instancia,"\n%sPorto{", recuo);
        recuo = _Recuo(++numeroRecuo);
        //Id
        fprintf(Instancia, "\n%sid:\"%d\",", recuo, porto->id);
        //numero Area Atracamento
        fprintf(Instancia, "\n%snumeroAreaAtracamento:\"%d\",", recuo, NumeroAreaAtracamento);
        //numero Travessas
        fprintf(Instancia, "\n%snumeroTravessas:\"%d\",", recuo, NumeroTravessa);
        //Fila Chegada
        char *boolean = (porto->filaChegada.tamanho != 0 ? "True" : "False");
        fprintf(Instancia, "\n%sfilaChegada:\"%s\"", recuo, boolean);
        recuo = _Recuo(--numeroRecuo);
    fprintf(Instancia, "\n%s}", recuo);
    
}

void JsonTravessa(FILE *Instancia, Travessa *travessa){
/*
    Travessa{
        id:"",
        containers:""
    }
*/
    char *recuo = _Recuo(numeroRecuo);
    //Escreve Json no arquivo Log
    fprintf(Instancia,"\n%sTravessa{", recuo);
        recuo = _Recuo(++numeroRecuo);
        //Id
        fprintf(Instancia, "\n%sid:\"%d\",", recuo, travessa->id);
        //numero Area Atracamento
        fprintf(Instancia, "\n%scontainers:\"%d\"", recuo, travessa->containers.topo);
        recuo = _Recuo(--numeroRecuo);
    fprintf(Instancia, "\n%s}", recuo);
    
}

void JsonAreaAtracamento(FILE *Instancia, AreaAtracamento *areaAtracamento){
/*
    AreaAtracamento{
        id:"",
        navioAtracado:"",
        filaLocal:"",
        nContainersFila:""
    }
*/
    char *recuo = _Recuo(numeroRecuo);
    //Escreve Json no arquivo Log
    fprintf(Instancia,"\n%sAreaAtracamento{", recuo);
        recuo = _Recuo(++numeroRecuo);
        //Id
        fprintf(Instancia, "\n%sid:\"%d\",", recuo, areaAtracamento->id);
        //navio Atracado
        JsonNavio(Instancia, (areaAtracamento->navio));
        _MoreOne(Instancia);
        //filaLocal
        char *boolean = (areaAtracamento->filaLocal.tamanho != 0 ? "True" : "False");
        fprintf(Instancia, "\n%sfilaLocal:\"%s\",", recuo, boolean);
        //nContainersFila
        fprintf(Instancia, "\n%snContainersFila:\"%d\"", recuo, areaAtracamento->nContainersFila);
        recuo = _Recuo(--numeroRecuo);
    fprintf(Instancia, "\n%s}", recuo);
}

void JsonNavio(FILE *Instancia, Navio *navio){
/*
    Navio{
        id:"",
        pilhaContainers:"",
        unidadeTempo:""
    }
*/  
    char *recuo = _Recuo(numeroRecuo);
    //Escreve Json no arquivo Log
    fprintf(Instancia,"\n%sNavio{", recuo);

    if((navio != NULL) && (NavioValido(*navio)) ){
        recuo = _Recuo(++numeroRecuo);
            //Id
            fprintf(Instancia, "\n%sid:\"%d\",", recuo, navio->id);
            //pilhaContainers
            for(int i = 0; i < NumeroPilhasContainersNavio; i++)
            {
                JsonPilhaContainers(Instancia, &(navio->pilhaContainers[i]));
            }   
            //unidadeTempo
            fprintf(Instancia, "\n%sunidadeTempo:\"%d\"", recuo, navio->tempoEntrada);
        recuo = _Recuo(--numeroRecuo);
        fprintf(Instancia, "\n%s}", recuo);
    }else{
        fprintf(Instancia, "}");
    }
}
void JsonFilaBarcos(FILE *Instancia, Fila *fila){
/*
    FilaBarcos{
        tamanho:""
        barcos:[]
    }
*/
    Elemento *celula;
    char *recuo = _Recuo(numeroRecuo);
    //Escreve Json no arquivo Log
    fprintf(Instancia,"\n%sFila{", recuo);
    //So Printa a fila se tiver fila
    if(fila->tamanho != 0){
        recuo = _Recuo(++numeroRecuo);
        //Tamanho
        fprintf(Instancia, "\n%stamanho:\"%d\",", recuo, fila->tamanho);
        //Todos os Navios da fila
        celula = fila->primeiro;
        for(int i = 0; i < fila->tamanho; i++)
        {
            JsonNavio(Instancia,(celula->elemento));
            if( i != (fila->tamanho-1)){
                celula = celula->proximo;
                _MoreOne(Instancia);
            }
        }
    }else{//Caso contrario apenas fecha a fila
        fprintf(Instancia, "}");
    }
}


void JsonPilhaContainers(FILE *Instancia, Pilha *pilha){
/*
    PilhaContainers{
        tamanho:""
    }
*/
    char *recuo = _Recuo(numeroRecuo);
    //Escreve Json no arquivo Log
    fprintf(Instancia,"\n%sPilha{", recuo);
    recuo = _Recuo(++numeroRecuo);
        //Tamanho Pilha
        fprintf(Instancia, "\n%stamanho:\"%d\",", recuo, pilha->tamanho);
        //Quantidade Containers
        fprintf(Instancia, "\n%scontainers:\"%d\"", recuo, pilha->topo);
    recuo = _Recuo(--numeroRecuo);
    fprintf(Instancia, "\n%s}", recuo);
}


char* _Recuo(int numeroRecuo){
    char *recuo = "\t";
    char *stringRetorno = NULL;

    //Pega o tamanho da string recuo
    int tamanho = strlen(recuo) * numeroRecuo;
    //realloca a string para ter o tamanho adequado;
    stringRetorno = realloc(stringRetorno,sizeof(char) * tamanho);

    //Concatena o recuo 'n' Vezes
    for(int nRecuo = 0; nRecuo < numeroRecuo; nRecuo++)
    {
        strcat (stringRetorno, recuo);
    }    
    return stringRetorno;
}

void _MoreOne(FILE *Instancia){
    fprintf(Instancia, ",");
}