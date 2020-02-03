//////////////////////////////////////////////////////////////////////////////
//  LUCAS MATEUS FERNANDES 
//  RA 0035411
//
//	github : 1ldomal2
//  e-mail : lucasmfccom@gmail.com
//////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilha.h"

void printaLinhas(Pilha *linhas, int numeroLinhas);
void Tratamento(Pilha *linha, int indice, char caractere);
void FinalTexto(Pilha *linha, int indice);
void CancelarCaractere(Pilha *linha, int indice);
void ApagaLinha(Pilha *linha, int indice);
void PulaLinha(Pilha *linha, int indice);
Pilha *SeparaLinhas(int tamanhoTotal, int tamanhoLinha, char *texto);
char *PegaTexto();
void invertePilha(Pilha *linha);

#define DEBUG printf("LINHA:%d \n",__LINE__);

int main(int argc, char const *argv[])
{
      //Pega os dados inseridos pelo usuário
      char *entrada = PegaTexto();

     //Variaveis de controle
      int tamanhoEntrada = strlen(entrada);
      int tamanhoLinha = 60;
      int numeroLinhas = (int)ceil((float)tamanhoEntrada/(float)tamanhoLinha);
      //Desmembra a entrada em varias linhas/pilhas e faz o tratamento
      Pilha *linhas = SeparaLinhas(tamanhoEntrada, tamanhoLinha, entrada);
      
      //printa linhas
      printaLinhas(linhas,numeroLinhas);
}
void printaLinhas(Pilha *linhas, int numeroLinhas){
    printf("\nTexto Tratado:\n");
    for(int i = 0; i < numeroLinhas; i++){
                invertePilha(&(linhas[i]));
                int numeroElementosAlocadoPilha = (linhas[i].indice);
                for(int j = 0; j < numeroElementosAlocadoPilha; j++){
                    printf("%c",Desempilha(&(linhas[i])));
                }
            }
      
}
void invertePilha(Pilha *linha){
    //Cria pilha auxiliar
    Pilha auxiliar1,auxiliar2,auxiliar3;
    CriaPilha(&auxiliar1);
    CriaPilha(&auxiliar2);
    int indice = linha->indice;
    //auxiliar1 é inverso da original
    for(int i = 0; i < indice; i++){
        Empilha(&auxiliar1,Desempilha(linha));
    }
    //auxiliar2 é o inverso da auxilair1 ou seja é igual a original
    for(int i = 0; i < indice; i++){
        Empilha(&auxiliar2,Desempilha(&auxiliar1));
    }
    //original recebe o inverso da original
    for(int i = 0; i < indice; i++){
        Empilha(linha,Desempilha(&auxiliar2));
    }
}
void FinalTexto(Pilha *linha, int indice){
    //Não sei o que fazer;
    printf("\nSe Você está vendo esta mensagem ouve um erro semantico pois nao acabou a linha no '~'\n");
}
void CancelarCaractere(Pilha *linha, int indice){
    Desempilha(linha);//Apaga #
    Desempilha(linha);//Apagar o caractere

}
void ApagaLinha(Pilha *linha, int indice){
    for(int i = indice; i >= 0; i--){
        Desempilha(linha);
    }
    
}
 void PulaLinha(Pilha *linha, int indice){
    Desempilha(linha);
    Empilha(linha,'\n');
}
Pilha *SeparaLinhas(int tamanhoTotal, int tamanhoLinha, char *texto){
    //Variaveis
    int numeroLinhas = (int)ceil((float)tamanhoTotal/(float)tamanhoLinha);
    
    //Cria um array de pilha
    Pilha *linhas = malloc(numeroLinhas * sizeof(Pilha));
    //Instancia as pilhas
    CriaPilhas(linhas, numeroLinhas);

    //Cada pilha representa uma linha
    for(int i=0; i<tamanhoTotal; i++){
        //Percorre todo o vetor passando os dados para cada pilha
        int linhaAtual = (int)(i/tamanhoLinha);
        Empilha(&(linhas[linhaAtual]), texto[i]);
        int indice = linhas[linhaAtual].indice;//Aponta para um espaço vazio que sera preenchido
        Tratamento(&(linhas[linhaAtual]), indice, linhas[linhaAtual].vetor[indice-1]);
    }
    return linhas;
}
void Tratamento(Pilha *linha, int indice, char caractere){
    switch (caractere){
        case '#':
            CancelarCaractere(linha, indice);
            break;
        case '\\':
            ApagaLinha(linha, indice);
            break;
        case '*':
            PulaLinha(linha, indice);
            break;
        case '~':
            FinalTexto(linha, indice);
            break;
    }    
}
char *PegaTexto(){
    char *texto;
    //HELP
    printf("-------------------------------------\n");
    printf("#\t Apaga o ultimo caracter:\n");
    printf("\\\t Apaga a linha\n");
    printf("*\t Pula a linha ('\\n'):\n");
    printf("~\t Termina o tratamento\n");
    printf("-------------------------------------\n");

    printf("Digite o Texto :\n\n");
    scanf("%[^~,^\n]s",texto);
    //tem que colcoar ~ no final do vetor
    int tamanho = strlen(texto);
    char *textoInteiro = malloc((tamanho+1)*sizeof(char));
    return &(texto[0]);
}