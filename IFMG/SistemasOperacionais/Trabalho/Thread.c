/************************************************************************/
/*                                                                      */
/*  Bibliotecas Usadas                                        		    */
/*                                                                      */
/************************************************************************/
#ifndef THREAD
#define THREAD

	#include "Thread.h"

	/************************************************************************/
	/*                                                                      */
	/*  threads	          			                                        */
	/*                                                                      */
	/************************************************************************/

	 void *celula(void *argumento){//Thread e
	 
	 	DadosThread *parametros=(DadosThread*)argumento;//Converte o argumento recebido para o tipo Dadosthread;

	 	//Facilita a leitura
		int iLinha=parametros->iLinha;
		int iColuna=parametros->iColuna;
		int igualdade=parametros->igualdade;
	 	int nThread=parametros->matriz->ColunasM2*iLinha+iColuna;
		float CelulaM1;
		float CelulaM2;
		float *CelulaM3=&(parametros->matriz->m3[iLinha][iColuna]);//Facilita a leitura
		(*CelulaM3)=0.0;//Evita lixo de memoria
	 	//Codigo da thread
	    for(int i = 0; i < igualdade;i++){
	    	
	    	 CelulaM1=parametros->matriz->m1[iLinha][i];//Facilita a Leitura
	    	 CelulaM2=parametros->matriz->m2[i][iColuna];//Facilita a Leitura
	 		(*CelulaM3)+=CelulaM1*CelulaM2; //Salva a celula
	    } 	
		
	    //Sai thread
		 printf("%dº Thread - Encerrada \n",nThread+1 );
	 	 pthread_exit(0);
	 }

	 /************************************************************************/
	 /*                                                                      */
	 /*  Codigo			                                                    */
	 /*                                                                      */
	 /************************************************************************/
	 
	 int Threads(Matrix *m){ 	


	 	//Apos Ler do Arquivo
	 	int LinhasM1 = m->LinhasM1;
	 	int ColunasM1= m->ColunasM1;
		int LinhasM2 = m->LinhasM2;
	 	int ColunasM2= m->ColunasM2;
	 

	 	//Preparando as Threads
	 	int TotalThreads=LinhasM1*ColunasM2;//Numero de threads = 1 para cada celula da matriz resultante
		pthread_t thread[TotalThreads];//Cria N Threads uma para cada celula da matriz resultante
		DadosThread Argumentos[TotalThreads];//Cria uma struct para cada thread 

	 	//Chama as threads
		int indice=0;
	 	for (int i = 0; i < LinhasM1; i++){//Linhas m1	
	 		for (int j = 0; j < ColunasM2; j++){//Colunas m2
		 		indice=(i*ColunasM2)+(j);//mesma logica que aritimetica de ponteiro
		 		//Preenche as structs
		 			Argumentos[indice].matriz=m;//Aloca as mesmas matrizes para todas struct
		 			Argumentos[indice].iLinha=i;// linha(i) M1 
		 			Argumentos[indice].iColuna=j;// coluna(j) M2
		 			Argumentos[indice].igualdade=LinhasM2;// indice=x  M[][x] * M[x][]  
		 		printf("%dº Thread - Lançanda \n",indice+1 );
				pthread_create(&(thread[indice]), NULL, celula, (void *) &(Argumentos[indice]));//Cria a thread
				//pthread_join(thread[indice], NULL);//Cria a proxima thread so quando a primeira acabar
	 		}
	 	}
	 


	 	//Espera pelas Nthreads 
	 	for (int i = 0; i < TotalThreads; i++){
	 		pthread_join(thread[i], NULL);
	 	}

	 	//pthread_exit(0);
	 	return 1;
	 }

#endif