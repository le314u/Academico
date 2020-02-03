//Lucas Mateus Fernandes
//Joao Pedro Mendonça

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include "StructDados.h"
#include "Matriz.h"
#include "Thread.h"



int main(int argc, char** argv){
	//Retorno 0 ==Multiplicação não é possivel
	//Retorno -1 ==Erro na Sintaxi dos arquivos
	//Retorno 1 ==Multiplicação feita e arquivo gerado/Sobrescrito
	

	//Inicializa as variaveis
	Matrix	matrizes;
	SValidacao validacao;


	//Ve se é possivel fazer a modificação
	validacao = ValidadeMultiplicacao(argv[1],argv[2],&matrizes);//OBS dentro desta função tem arquivos abertos que serao fechados no "AlocaMatriz"



	




	if(validacao.iColuna1!=validacao.iLinha2){
		printf("Não é possivel multiplicar as matrizes\n");
		return 0;
	}

	//Aloca as matrizes
		//M1
		if(AlocaMatriz(validacao.iLinha1,validacao.iColuna1,&matrizes.m1,validacao.arq1)){
			printf("Matriz 1 - Ok \n");
			matrizes.LinhasM1=validacao.iLinha1;
			matrizes.ColunasM1=validacao.iColuna1;
		}else{
			printf("%s Incoreto\n",argv[1]);
			fclose(validacao.arq1);
			return -1;
		}
		//M2
		if(AlocaMatriz(validacao.iLinha2,validacao.iColuna2,&matrizes.m2,validacao.arq2)){
			printf("Matriz 2 - Ok\n");
			matrizes.LinhasM2=validacao.iLinha2;
			matrizes.ColunasM2=validacao.iColuna2;
		}else{
			printf("%s Incoreto\n",argv[2]);
			fclose(validacao.arq2);
			return -1;
		}
		//M3
		if(!AlocaMatriz(validacao.iLinha1,validacao.iColuna2,&matrizes.m3,NULL)){
			printf("Matriz 3 - Alocada\n");
	}

	


	//Chama as threads
	Threads(&matrizes);
	//So retorna quando todas threads acabarem
	printf("Matriz 3 - Ok\n\n");

	printf("\n\nresultado.txt:\n");
	//Printa a matriz na tela
	printaMatriz(matrizes.LinhasM1,matrizes.ColunasM2,matrizes.m3);

	//Printa a matriz no arquivo
	fprintaMatriz( "resultado.txt",matrizes.LinhasM1,matrizes.ColunasM2,matrizes.m3);
	pthread_exit(0);
	return 1;

}