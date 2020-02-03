#ifndef MATRIZ_H
#define MATRIZ_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include <pthread.h>
	#include "StructDados.h"

	void printaMatriz(int Linhas,int Colunas,float** m);
	int AlocaMatriz(int iLinha,int iColuna,float ***matriz,FILE *ptrArq);
	SValidacao ValidadeMultiplicacao(char* arg1,char* arg2,Matrix *StructMatriz);
	void fprintaMatriz(char* PATH,int Linhas,int Colunas,float** matriz);

#endif