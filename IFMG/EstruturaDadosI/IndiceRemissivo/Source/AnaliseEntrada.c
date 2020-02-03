//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AnaliseEntrada.h"
#include "TratamentoString.h"
#include "Palavra.h"
#include "Lista.h"
#include "OpenHash.h"
#include "ListaHash.h"
#include "ABB.h"
#include "AVL.h"
#include "Clock.h"

//Le um arquivo txt e verifica as linhas em que as palavras aparecem
TAD *leituraTexto(char *nomeArquivoTexto, TAD *tadEstrutura){
    printf("\n\nPROCESSAMENTO");
    //Abre Arquivo
    FILE *arquivo;
    arquivo = fopen(nomeArquivoTexto, "r");

    //Verifica se foi possivel abrir o arquivo
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo '%s' ",nomeArquivoTexto);
        return NULL;
    }
    
    //variavel de controle (linha em que a palavra aparece)
    int numeroLinha = 1;

    //Percorre Arquivo
    int fimArquivo = 0;
    do{
        //le uma palavra
        char *newPalavra = lerPalavra(arquivo);

        //Tira a pontuação do final da palavra
        newPalavra = tiraPontuacao(newPalavra);

        //Se a palavra for valida muda seus indices em todas as palavras
        if(palavraValida(newPalavra)){
        //printf("\nPalavra = %s",newPalavra);
            //ReCria a estrutura N vezes
            //Lista
            tadEstrutura = tadInserirLISTA(tadEstrutura, newPalavra, numeroLinha);
            //ABB
            tadEstrutura = tadInserirABB(tadEstrutura, newPalavra, numeroLinha);
            //AVL
            tadEstrutura = tadInserirAVL(tadEstrutura, newPalavra, numeroLinha);
            //Tabela Hash
            tadEstrutura = tadInserirHASH(tadEstrutura, newPalavra, numeroLinha);
            //Tabela Hash com Lista
            tadEstrutura = tadInserirHASH_LISTA(tadEstrutura, newPalavra, numeroLinha);
        }else{
            //printf("\nPalavraInvalida = %s",newPalavra);
        }

        //Verifica qual foi o criterio de parada para a leitura da palavra
        int criterio = criterioParada(arquivo);
        if(criterio == 0){}//Espaço
        else if(criterio == 1){numeroLinha++;}//\n
        else if(criterio == -1){ fimArquivo = 1;}//EOF
    }while(!fimArquivo);
    
    //Fecha o Arquivo
    fclose(arquivo);
    
    //Retorna struct com todas as estruturas e o tempo de processamento de cada uma
    return tadEstrutura;
}

//Leitura palavras Validas ( contrução das N estruturas)
TAD *leituraTreinamento(char *nomeArquivoPalavras){
    printf("\n\nTREINAMENTO");
    //Estruturas
    TAD *tadEstrutura = initEstrutura();

    //Abre Arquivo
    FILE *arquivo;
    arquivo = fopen(nomeArquivoPalavras, "r");

    //Verifica se foi possivel abrir o arquivo
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo '%s' ",nomeArquivoPalavras);
        return NULL;
    }
    
    //Percorre Arquivo
    int fimArquivo = 0;
    do{
        //le uma palavra
        char *newPalavra = lerPalavra(arquivo);

        //Tira a pontuação do final da palavra
        newPalavra = tiraPontuacao(newPalavra);

        //Se a palavra for valida a implementa em todas as estruturas
        if(palavraValida(newPalavra)){
    //printf("\nnewPalavra = %s",newPalavra);
            //ReCria a estrutura N vezes
            //Lista
            tadEstrutura = tadInserirLISTA(tadEstrutura, newPalavra, -1);
            //ABB
            tadEstrutura = tadInserirABB(tadEstrutura, newPalavra, -1);
            //AVL
            tadEstrutura = tadInserirAVL(tadEstrutura, newPalavra, -1);
            //Tabela Hash
            tadEstrutura = tadInserirHASH(tadEstrutura, newPalavra, -1);
            //Tabela Hash com Lista
            tadEstrutura = tadInserirHASH_LISTA(tadEstrutura, newPalavra, -1);
        }else{
            //printf("\nPalavraInvalida = %s",newPalavra);
        }

        //Verifica se chegou ao fim do arquivo
        if(criterioParada(arquivo)==-1){ fimArquivo = 1;}

    }while(!fimArquivo);
    
    //Fecha o Arquivo
    fclose(arquivo);
    
    //Retorna struct com todas as estruturas
    return tadEstrutura;

}

char *lerPalavra(FILE *arquivo){
    //Le uma palavra até espaço pula linha ou EOF
    int tamanho = 0;
    char *palavra = malloc(sizeof(char*));
    char letra;
    int flagContinuar;
    do{
        //reseta flag
        flagContinuar = 1;

        //Le um caractere
        letra = fgetc(arquivo);

        //Verifica se o caractere lido é um criterio de parada
        if(letra == ' ' || letra == '\n' || letra == EOF){
            flagContinuar = 0;
            palavra =  realloc(palavra, (tamanho+1) * sizeof(char*));
            palavra[tamanho] = '\0';
        }else{
            //Aumenta a quantidade de caracteres lidos
            tamanho++;

            //Ajusta o vetor para caber o novo caractere
            palavra =  realloc(palavra, tamanho * sizeof(char*));

            //Conseguiu alocar
            if(palavra != NULL){
                //Converte para letra minuscula
                palavra[tamanho-1] = tolower(letra);
            }else{//Não conseugiu alocar
                printf("\nImpossivel realocar mais espaço para a palavra a ser lida -Memoria FULL-\n");
            }
        }
    }while(flagContinuar);
    return palavra;
}

char *tiraPontuacao(char* string){
    //Verifica o tamanho da palavra
    int tamanho = strlen(string);

    //Cria flag para controle do while
    int flagMudanca;

    do{
        //Reseta flag
        flagMudanca = 0;

        // ! " # $ % & ' ( ) * + , - . /
        if((string[tamanho -1] >= 33) && (string[tamanho -1] <= 47)){
            string[tamanho -1] = '\0';
            flagMudanca++;
        }

        // : ; < = > ? @
        if((string[tamanho -1] >= 58) && (string[tamanho -1] <= 64)){
            string[tamanho -1] = '\0';
            flagMudanca++;
        }

        // [ \ ] ^ _ `
        if((string[tamanho -1] >= 91) && (string[tamanho -1] <= 96)){
            string[tamanho -1] = '\0';
            flagMudanca++;
        }

        // { | } ~
        if((string[tamanho -1] >= 123) && (string[tamanho -1] <= 126)){
            string[tamanho -1] = '\0';
            flagMudanca++;
        }

        //Verifica se teve alguma alteração
        if(flagMudanca == 0){
            break;
        }
    }while(flagMudanca);
    return string;
}

int criterioParada(FILE *arquivo){
    //LEGENDA
    // -1 == EOF
    // 0 == Nada em especifico 
    // 1 == \n

    //Verifica se chegou ao fim caso sim aborta a missao
    if(feof(arquivo)){
        return (-1);
    }
    //volta o ponteiro
    fseek(arquivo,-1,SEEK_CUR);

    //Le novamente a ultima caractere
    char caractere = fgetc(arquivo);
    //Verifica qual caractere interrompeu a leitura (" Muda Indice")
    if(caractere == '\n'){return 1;}
    else{return 0;}
}

TAD *initEstrutura(){
    //Lista de estruturas
    TAD *estrutura = NULL;
    estrutura = malloc(sizeof(TAD));

    //Estruturas
    estrutura->ABB = NULL;
    estrutura->AVL = NULL;
    estrutura->HASH = NULL;
    estrutura->LISTA = NULL;
    estrutura->HASH_LISTA = NULL;

    //Calcula TempoProcessamento
    estrutura->timePABB = 0;
    estrutura->timePAVL = 0;
    estrutura->timePHASH = 0;
    estrutura->timePHASH_LISTA = 0;
    estrutura->timePLISTA = 0;

    //Calcula TempoExibição
    estrutura->timeEABB = 0;
    estrutura->timeEAVL = 0;
    estrutura->timeEHASH = 0;
    estrutura->timeEHASH_LISTA = 0;
    estrutura->timeELISTA = 0;

    return estrutura;
}


TAD *tadInserirABB(TAD *estrutura, char *palavra, int pagina){
    //Começa a contar o tempo para processar a informação dentro da ABB
    float auxTimeI = start();
    //Inserir Palavra ou indice na ABB
    NoABB *ptrABB = InserirPalavraABB(estrutura->ABB, palavra, pagina);

    //Para de contar o tempo gasto na ABB
    float auxTimeF = stop();
    estrutura->timePABB += delta(auxTimeI, auxTimeF);
    
    //Cria a estrutura N vezes
    if(ptrABB != NULL){
        estrutura->ABB = ptrABB;
    }
    return estrutura;
}



TAD *tadInserirAVL(TAD *estrutura, char *palavra, int pagina){
    //Cria a estrutura N vezes
    float auxTimeI = start();
    NoAVL *ptrAVL = InserirPalavraAVL(estrutura->AVL, palavra, pagina);
    float auxTimeF = stop();
    estrutura->timePAVL += delta(auxTimeI, auxTimeF);
    if(ptrAVL != NULL){
        estrutura->AVL = ptrAVL;
    }
    return estrutura;
}


TAD *tadInserirLISTA(TAD *estrutura, char *palavra, int pagina){
    //Começa a contar o tempo para processar a informação dentro da LISTA
    float auxTimeI = start();
    //Inserir Palavra ou indice na LISTA
    estrutura->LISTA = InserirPalavraLista(estrutura->LISTA, palavra, pagina);
    //Para de contar o tempo gasto na LISTA
    float auxTimeF = stop();
    estrutura->timePLISTA += delta(auxTimeI, auxTimeF);
    return estrutura;
}

TAD *tadInserirHASH(TAD *estrutura, char *palavra, int pagina){
    //Se a tanela estiver Null aloca a
    if(estrutura->HASH == NULL){
        estrutura->HASH = IniciaOpenHash();
    }
    //Começa a contar o tempo para processar a informação dentro da HASH
    float auxTimeI = start();
    //Inserir Palavra ou indice na HASH
    InserirPalavraOpenHash(estrutura->HASH, palavra, pagina);
    //Para de contar o tempo gasto na HASH
    float auxTimeF = stop();
    estrutura->timePHASH += delta(auxTimeI, auxTimeF);
 
    return estrutura;
}


TAD *tadInserirHASH_LISTA(TAD *estrutura, char *palavra, int pagina){
    //Se a tabela estiver Null aloca a
    if(estrutura->HASH_LISTA == NULL){
        estrutura->HASH_LISTA = IniciaListaHash();
    }
    //Começa a contar o tempo para processar a informação dentro da HASH
    float auxTimeI = start();
    //Inserir Palavra ou indice na HASH
    InserirPalavraListaHash(estrutura->HASH_LISTA, palavra, pagina);
    //Para de contar o tempo gasto na HASH
    float auxTimeF = stop();
    estrutura->timePHASH_LISTA += delta(auxTimeI, auxTimeF);
    return estrutura;
}


    //######################################################################################
    //######################################################################################
    //######################################################################################     