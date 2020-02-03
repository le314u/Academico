#ifndef STRUCCTDADOS_H
#define STRUCCTDADOS_H
	#define DEBUG printf("\n Linha- %d -%s\n",__LINE__,__FILE__);
	//#define DEBUG 1==1;

	typedef struct {//Comum a todas as threads
			float **m1;
			float **m2;
			float **m3;
			int LinhasM1;
			int ColunasM1; 
			int LinhasM2; 
			int ColunasM2;
	}Matrix;

	typedef struct{//Uma para cada thread		 
		int   iLinha;//Linha que vai multiplicar              
		int   iColuna;//Coluna que vai multiplicas  
		int	  igualdade;//numero de colunas de m1 e de linhas de m2     
		//float retorno;//Salvar o valor da celula[iLinha][iColuna]         
		Matrix   *matriz;    
	}DadosThread;

	typedef struct{
		FILE *arq1;
		FILE *arq2;
		int	iLinha1;
		int	iColuna1;
		int	iLinha2;
		int	iColuna2;
	}SValidacao;
#endif