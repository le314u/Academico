//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TratamentoString.h"

//Apenas os primeiros c1 caracteres devem ser retidos nas chaves | c1=32
const int c1 = 32;
const int tamanhoMinimo = 4;
//Verifica Qual palavra vem primeiro quando se trata de ordem alfabetica
int ordemAlfabetica(char *word1, char *word2){
    /*LEGENDA
    [0] plavra1 == palavra2
    [1] palavra1 < palavra2
    [2] palavra1 > palavra2
    */
   
    //Tamanho primeira palavra
    int tamanho1 = strlen(word1);
    //Tamanho segunda palavra
    int tamanho2 = strlen(word2);
    //numero de iterações é igual ao tamanho da menor palavra
    int numeroInteracoes = ((tamanho1 < tamanho2) ? tamanho1 : tamanho2);
    //Verifica Letra por Letra
    int aux = 0;

    //Verifica so as primeiras 'c1' caracteres
    numeroInteracoes = numeroInteracoes > c1 ? c1 : numeroInteracoes;

    for (int i = 0; i < numeroInteracoes; i++)
    {
        //Se primeira palavra antecede
        if(word1[i] < word2[i]){
            aux = 1;
            break;//sai do for porque achou
        //Se segunda palavra antecede
        }else if(word1[i] > word2[i]){
            aux = 2;
            break;//sai do for porque achou
        }
    }
    if(aux == 0){
        if(tamanho1 < tamanho2){
            aux = 1;
        }else if (tamanho1 > tamanho2){
            aux = 2;
        }else{
            aux = 0;
        }
    }
    return aux;    
}

int palavraValida(char *string){
    //Menos de 4 caracteres
    if(strlen(string)<tamanhoMinimo){
        
        return 0;
    }
    //Verifica se começa por letra não acentuada
    if(!(string[0]>=65 && string[0] <= 122)){
        return 0;
    }
    return 1;
}
