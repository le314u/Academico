#ifndef MATRIZ
#define MATRIZ
	#include "Matriz.h"

	void fprintaMatriz(char* PATH,int Linhas,int Colunas,float** matriz){
		//Abre o Arquivo
		FILE *arq;
		arq = fopen(PATH,"w");

		//Salva Matriz no arquivo
		fprintf(arq,"%d\n",Linhas);//Linha
		fprintf(arq,"%d\n",Colunas);//Colunas
		for (int i = 0; i < Linhas; i++){
			for (int j = 0; j < Colunas;j++){
				fprintf(arq,"%f\t",matriz[i][j]);
			}
			fprintf(arq,"\n");
		}
		return ;
	}


	void printaMatriz(int Linhas,int Colunas,float** matriz){
		printf("\n");
		printf("%d\n",Linhas);//Linha
		printf("%d\n",Colunas);//Colunas
		for (int i = 0; i < Linhas; i++){
			for (int j = 0; j < Colunas;j++){
				printf("%f\t",matriz[i][j]);
			}
			printf("\n");
		}
		return ;
	}
	
	int AlocaMatriz(int iLinha,int iColuna,float ***matriz,FILE *ptrArq){
		//Se retorno 0 ptr veio nulo
		//Se retorno 1 ptr veio para arquivo e foi fechado

		//Aloca Matriz;
		*matriz =(float **) malloc(iLinha * sizeof(float*));//alocando as linhas da matriz
		for (int i = 0; i < iLinha; i++){
			(*matriz)[i] = malloc(iColuna * sizeof(float));//alocando as colunas em cada linha
		}
	

		//Preenchendo Matriz
		if(ptrArq==NULL){
			for (int i = 0; i < iLinha; i++){
				for (int j = 0; j < iColuna; j++){
					(*matriz)[i][j]=0;//Evita lixo de memoria
				}
			}
			return 0;
		}else{
			for (int i = 0; i < iLinha; i++){
				for (int j = 0; j < iColuna; j++){
					fscanf(ptrArq,"%f",&((*matriz)[i][j]));//escaneando cada número até o fim do arquivo
				}
			}
			fclose (ptrArq);
			return 1;
		}

	}

	SValidacao ValidadeMultiplicacao(char* arg1,char* arg2,Matrix *StructMatriz){
		SValidacao Sretorno;//Cria a strutura com nome de "Sretorno" pois essa struct sera retornada
		
		//Inicializa Variaveis
		StructMatriz->LinhasM1=0;
		StructMatriz->LinhasM2=0;
		StructMatriz->ColunasM1=0;
		StructMatriz->ColunasM2=0;
		Sretorno.arq1= fopen(arg1,"r");//abrindo arquivo
		fscanf(Sretorno.arq1,"%d",&(StructMatriz->LinhasM1));//Le Quantidade de Linhas M1
		fscanf(Sretorno.arq1,"%d",&(StructMatriz->ColunasM1));//Le Quantidade de Colunas M1

		Sretorno.arq2= fopen(arg2,"r");//abrindo arquivo
		fscanf(Sretorno.arq2,"%d",&(StructMatriz->LinhasM2));//Le Quantidade de Linhas M2
		fscanf(Sretorno.arq2,"%d",&(StructMatriz->ColunasM2));//Le Quantidade de Colunas M2

		if(StructMatriz->ColunasM1!=StructMatriz->LinhasM2){//Verifica se é possivel fazer o calculo
			printf("Não é possivel Fazer a Multiplicação das Matrizes");
		}
		Sretorno.iLinha1=StructMatriz->LinhasM1;
		Sretorno.iLinha2=StructMatriz->LinhasM2;
		Sretorno.iColuna1=StructMatriz->ColunasM1;
		Sretorno.iColuna2=StructMatriz->ColunasM2;
		return Sretorno;
	}
#endif