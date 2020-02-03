
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////1
//
//Nome:		Lucas Mateus Fernandes
//Nome:		Leandro Souza Pinheiro 
//Nome:		João Paulo de Souza
//
//2º Periodo	Matematica Discreta
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DEBUG(TEXTO) printf("\n%s%s \t Linha = %d \t %s%s\n","\33[1;31m",__FILE__, __LINE__,TEXTO,"\33[0;29m");//scanf("%d",&Bug)
#define DEBUGINT(TEXTO,INT) printf("\n%s%s \t Linha = %d \t %s%d%s\n","\33[1;32m",__FILE__,__LINE__,TEXTO,INT,"\33[0;29m");//scanf("%d",&Bug)
int Bug;
#define PAUSA 	scanf("%d",&Bug);
enum Boolean{true = 1, false =0};
typedef enum Boolean Bool; 

int Pega_Nos(FILE *Leitura){
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Função abre o arquivo verifica se a primeira letra é N e pega o numero de nós retornando-o 
//Caso Sintaxe  invalida retorna 0 que será considerado um valor inválido por definição
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	char Temporario;
	int Tamanho=0;
	//Cria variaveis para ler do arquivo
	fscanf(Leitura,"%c",&Temporario);
	//Le primeiro caractere
	if(Temporario != 'n' && Temporario !='N'){
		printf("O arquivo de entrada esta com a sintaxe incorreta\n");
		return 0;
		//Retorna 0 caso esteja com Sintaxe invalida
	}
	//IF para verificar se esta com sintaxe invalida no arquivo de entrada..
	getc(Leitura);
	//pula o espaço
	fscanf(Leitura,"%d",&Tamanho);
	//Captura o numero de nós
	return Tamanho;
	//Retorna Tamanho que sera criada a matriz(quantidade de nós informados)

}

int** Preenche_Matriz(int **Matriz, int Tamanho_Matriz, FILE *Leitura){
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Funcao para preencher Matriz com dados lido do Arquivo
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int Loop = 1, Contador = 0;
	int R1 = -1, R2 = -1;
	char Temporario[999];
	//Variaveis necessarias para o desenvolvimento da funcao
	
	Matriz=(int **)malloc(Tamanho_Matriz*sizeof(int*));
	for (int i = 0; i < Tamanho_Matriz; ++i)
	{
		Matriz[i]=(int *)malloc(Tamanho_Matriz*sizeof(int));
		for (int j = 0; j < Tamanho_Matriz; ++j)
		{
				Matriz[i][j] = 0;
				//Atribui valor a matriz
		}
	}
	//Aloca uma matriz
	do{

		fscanf(Leitura,"%[^r]s",Temporario);
		//Le ate encontrar a primeira letra R 
		if (feof(Leitura))//Verifica se chegou ao fim do arquivo
		{
			Loop = 0;
			return Matriz;
			//Sai do loop e desliga a FLAG
		}
		getc(Leitura);
		//pula o espaço
		fscanf(Leitura,"%d",&R1);
		//le o primeiro nó 
		getc(Leitura);
		//pula o espaco
		fscanf(Leitura,"%d",&R2);
		//le o segundo no
		
		Matriz[R1 - 1][R2 - 1] = 1;
		//Vetor em C vai de 0 ate n-1
		//setando como 1 onde existe uma relação
		fscanf(Leitura,"%[^\n]s",Temporario);
		//chega até ofinal da linha
		getc(Leitura);  
		//pula o \n
	}while(Loop == 1);
	
	return Matriz;
}
Bool Verifica_Reflexivo(int **Matriz, int Tamanho_Matriz, FILE *Leitura){
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//Função para a verificar se a relação possui o fecho reflexivo
	//Obs: Recebe por parametro, ponteiro da matriz, número de nos, e ponteiro do arquivo de leitura
	//
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//usamos um for para varrer a matriz, na sua diagonal principal e verificar se todos os campos dessa diagonal
	//os valores igual a 1
	for (int i = 0; i < Tamanho_Matriz; ++i)
	{	
		//se houver algum valor que seja diferente de 1, no caso especifico, valor 0, a função retorna o valor false
		if (Matriz[i][i] != 1)
		{	
			//retorna false
			return false;
		}
	}
	//caso esteja tudo de acordo com as regras do fecho reflexivo, retorna true
	return true;

}

Bool Verifica_Simetrico(int **Matriz, int Tamanho_Matriz, FILE *Leitura){

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//Função para verificar se a relação possui o fecho simétrico
	//Obs: Recebe por parametro, ponteiro, número de nós, e ponteiro do arquivo que foi lido
	//
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//variaveis que serão necessárias para o uso do programa
	int conta_relacoes = 0;
	int controle = 0;
	//serão utilizados dois for's para verificar a ida da matriz e a volta, para as linhas e colunas
	for(int i = 0; i < Tamanho_Matriz; ++i){
		for(int j = 0; j < Tamanho_Matriz; ++j){
			//primeira verificação, se a matriz possui alguma relação
			if(Matriz[i][j] == 1){
				//se houver, o contador de relações sera acrescentado
				conta_relacoes++;
			}
			//verifica se os valores na matriz, possuem relações simetricas
			if(Matriz[i][j] != Matriz[j][i]){
				//se houver, aumenta o valor do controle
				controle++;
				return false;
			}
		}
	}
	//no fim da função, verifica se os valores de controle são um diferente de 0, e o outro igual a 0
	if(conta_relacoes != 0 && controle == 0){
		//retorna true
		return true;
	//senão 
	}else{
		//retorna false;
		return false;
	}
}

Bool Verifica_Transitivo(int **Matriz, int Tamanho_Matriz, FILE *Leitura){
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//Função para verificar se a relação possui o fecho transitivo
	//Obs: Recebe por parametro, ponteiro, número de nós, e ponteiro do arquivo que foi lido
	//
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//variaveis que serão necessárias para o uso do programa
	int conta_relacoes = 0;
	int controle = 0;
	//serão utilizados dois for's para verificar a ida da matriz e a volta, para as linhas e colunas
	for(int i = 0; i < Tamanho_Matriz; ++i){
		for(int j = 0; j < Tamanho_Matriz; ++j){
			if(Matriz[i][j] == 1){
				conta_relacoes++;
			}
			for(int k = 0; k < Tamanho_Matriz; ++k){
				if(Matriz[i][j] == 1 && Matriz[j][k] == 1 && Matriz[i][k] == 0){
					//se houver, aumenta o valor do controle
					controle++;
					return false;
					//Se matriz houver fecho de i pra j e de j pra k  e nao houver de i para k
					//indica que não possui a propriedade reflexiva
				}
			}
		}
	}
	//no fim da função, verifica se os valores de controle são um diferente de 0, e o outro igual a 0
	if(conta_relacoes != 0 && controle == 0){
		//retorna true
		return true;
	//senão 
	}else{
		//retorna false;
		return false;
	}
}
void Gera_Arquivo_Dot(int **Matriz, int Tamanho_Matriz, char Url[999]){
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//Função para Gerar arquivo Dot de todos os Fechos (Transitivo, Reflexivo, Simetrico)
	//Obs: Recebe por parametro, ponteiro, número de nós, e Url com o caminho que sera gerado o arquivo
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FILE *Arquivo;
	Arquivo = fopen(Url,"w");
	if(Arquivo == NULL){//Caso ocorra algum erro ao abrir o arquivo ponteiro volta como NULL
		printf("Erro ao abrir arquivo para criar Fecho");//Mostra que teve erro ao criar o arquivo com Fecho
	}else{//Se nao
		fprintf(Arquivo,"digraph fecho\n{\n");
		//printa cabeçalho do arquivo DOT
		for(int i = 0; i < Tamanho_Matriz; i++){
			fprintf(Arquivo,"\t%d;\n", i+1);
		}
		//Cria FOR ate tamanho da Matriz e printa no arquivo a quantidade de NOS que foi passada no arquivo
		for(int i = 0; i < Tamanho_Matriz; i++){
			for(int j = 0; j < Tamanho_Matriz; j++){
				//For para varrer a matriz em linhas colunas da matriz
				if(Matriz[i][j] == 1){
					//Caso ocorra ligacao entre nos na matriz
					fprintf(Arquivo,"\t%d -> %d;\n", i+1, j+1);
					//printa no arquivo de onde para onde esta a relacao
				}
			}
		}
		for(int i = 0; i < Tamanho_Matriz; i++){
			for(int j = 0; j < Tamanho_Matriz; j++){
				//FOR para varrer a matriz em linhas e colunas
				if(Matriz[i][j] == 2){
					//Caso tenha ligacao indicada com 2 na matriz indica que houve alteracao no arquivo criando o Fecho
					fprintf(Arquivo,"\t%d -> %d [color=red];\n", i+1, j+1);
					//Printa no arquivo com padrao que irá utilizar cor vermelha na ligacao
				}
			}
		}
		fprintf(Arquivo,"}");
		//Apos o terminar de printar todas as ligacoes, fecha a chave indicando que acabou o arquivo DOT
	}
}
void Calcula_Fecho_Reflexivo(int **Matriz, int Tamanho_Matriz, FILE *Leitura){
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//Função para calcular o fecho reflexivo
	//Obs: Recebe por parametro, ponteiro da matriz, número de nos, e ponteiro do arquivo de leitura
	//
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//usamos um for para varrer a matriz, na sua diagonal principal e verificar se todos os campos dessa diagonal
	//os valores igual a 1
	for (int i = 0; i < Tamanho_Matriz; ++i)
	{	
		//se houver algum valor que seja diferente de 1, no caso especifico, valor 0, a função retorna o valor false
		if (Matriz[i][i] != 1)
		{	
			Matriz[i][i] = 2;
		}
	}

}
	
void Calcula_Fecho_Simetrico(int **Matriz, int Tamanho_Matriz, FILE *Leitura){
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//Função para calcular o fecho simetrico
	//Obs: Recebe por parametro, ponteiro da matriz, número de nos, e ponteiro do arquivo de leitura
	//
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//usamos dois for para varrer a matriz
	for(int i = 0; i < Tamanho_Matriz; i++){
		for(int j = 0; j < Tamanho_Matriz; j++){
			//verifica se o valor da posição i e diferente da posição j e o contrario também
			if(Matriz[i][j] != Matriz[j][i]){
				//atribui valor 2 para os valores que são o fecho
				if(Matriz[i][j] == 0 && Matriz[j][i] == 1){
					Matriz[i][j] = 2;
				}
				else if(Matriz[i][j] == 1 && Matriz[j][i] == 0){
					Matriz[j][i] = 2;
				}
			}
		}
	}
}

void Calcula_Fecho_Transitivo(int **Matriz, int Tamanho_Matriz, FILE *Leitura){
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//Função para calcular o fecho transitivo
	//Obs: Recebe por parametro, ponteiro da matriz, número de nos, e ponteiro do arquivo de leitura
	//
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Bool Verifica;
	do{
	 	Verifica = true;
		for(int i = 0; i < Tamanho_Matriz; i++){
			for(int j = 0; j < Tamanho_Matriz; j++){
				for(int k = 0; k < Tamanho_Matriz; k++){
					//sao usado 3 for para as verificacoes do fecho transitivo
					if(Matriz[i][j] == 1 && Matriz[j][k] == 1 && Matriz[i][k] == 0){
						//Verifica se há relacao de i com j e j com k mas nao nao há i com k
						Matriz[i][k] = 2;
						//Atribui valor 2 que é valor do fecho
						Verifica = false;
						//Valor do verifica recebe falso indicando que loop tem que ser rodado novamente
					}else if(Matriz[i][j] == 2 && Matriz[j][k] == 2 && Matriz[i][k] ==0){
						//Verifica se há relacao de i com j e j com k mas nao nao há i com k
						Matriz[i][k] = 2;
						//Atribui valor 2 que é valor do fecho
						Verifica = false;
						//Valor do verifica recebe falso indicando que loop tem que ser rodado novamente
					}
					else if(Matriz[i][j] == 1 && Matriz[j][k] == 2 && Matriz[i][k] ==0){
						//Verifica se há relacao de i com j e j com k mas nao nao há i com k
						Matriz[i][k] = 2;
						//Atribui valor 2 que é valor do fecho
						Verifica = false;
						//Valor do verifica recebe falso indicando que loop tem que ser rodado novamente
					}
					else if(Matriz[i][j] == 2 && Matriz[j][k] == 1 && Matriz[i][k] ==0){
						//Verifica se há relacao de i com j e j com k mas nao nao há i com k
						Matriz[i][k] = 2;
						//Atribui valor 2 que é valor do fecho
						Verifica = false;
						//Valor do verifica recebe falso indicando que loop tem que ser rodado novamente
					}
				}	
			}
		}
	}while(Verifica == false);
	//Loop que repete enquanto valor do verifica continua com falso
}

int main(int argc, char const *argv[])
{
	FILE *Arquivo_Leitura,*Arquivo_Escrita;
	//Criando ponteiro para arquivo
	int Tamanho_Matriz=0;


	if(argc == 3){//Verifica a quantidade de argumentos passados 
		Arquivo_Leitura = fopen(argv[1],"r");
		//Abre o arquivo
		if(Arquivo_Leitura == NULL){
			printf("\n%s não é um arquivo/caminho válido\n",argv[1]);
			return 0;
		}//Caso o Arquivo não exista
		Tamanho_Matriz = Pega_Nos(Arquivo_Leitura);
		//Chama funcao para pegar tamanho da matriz
		//verifica se a quantidade de nos é maior que 0, se for realiza o processo, senão mostra mensagem de erro
		if(Tamanho_Matriz > 0){
				int **Matriz;
				//Cria ponteiro para ponteiro(Matriz)
				Matriz = (int**)Preenche_Matriz(Matriz,Tamanho_Matriz,Arquivo_Leitura);
				//primeiro verifica se a função para verificar o fecho reflexivo retornou true
				if(Verifica_Reflexivo(Matriz,Tamanho_Matriz,Arquivo_Leitura) == true)
				{	
					//se retornou true, mostra mensagem na tela
					printf("\nO arquivo de entrada possui a propriedade reflexiva!\n");
				}
				else{
					int **Matriz_Reflexiva;
					char URL[999];
					strcpy(URL,argv[2]);
					strcat(URL, "_Reflexiva.dot");
					//Cria ponteiro para ponteiro(Matriz)
					Matriz_Reflexiva = (int**)Preenche_Matriz(Matriz_Reflexiva,Tamanho_Matriz,Arquivo_Leitura);
					for(int i = 0; i < Tamanho_Matriz; i++){
						for(int j = 0; j < Tamanho_Matriz; j++){
							Matriz_Reflexiva[i][j] = Matriz[i][j];
						}
					}
					//primeiro verifica se a função para verificar o fecho reflexivo retornou tr
					Calcula_Fecho_Reflexivo(Matriz_Reflexiva, Tamanho_Matriz, Arquivo_Leitura);
					//Chama funcao para gerar fecho reflexivo na matriz reflexiva
					Gera_Arquivo_Dot(Matriz_Reflexiva, Tamanho_Matriz, URL);
					//Gera o arquivo concatenado com seu respectivo fecho
				}
				//verifica a simetria da relação
				if(Verifica_Simetrico(Matriz,Tamanho_Matriz,Arquivo_Leitura) == true){
					printf("\nO arquivo de entrada possui a propriedade simétrica!\n");
				}
				else{
					int **Matriz_Simetrica;
					char URL[999];
					strcpy(URL,argv[2]);
					strcat(URL, "_Simetrica.dot");
					//Cria ponteiro para ponteiro(Matriz)
					Matriz_Simetrica = (int**)Preenche_Matriz(Matriz_Simetrica,Tamanho_Matriz,Arquivo_Leitura);
					for(int i = 0; i < Tamanho_Matriz; i++){
						for(int j = 0; j < Tamanho_Matriz; j++){
							Matriz_Simetrica[i][j] = Matriz[i][j];
						}
					}
					//calcula o fecho
					//primeiro verifica se a função para verificar o fecho reflexivo retornou tr
					Calcula_Fecho_Simetrico(Matriz_Simetrica, Tamanho_Matriz, Arquivo_Leitura);
					//Chama funcao para gerar fecho reflexivo na matriz reflexiva
					Gera_Arquivo_Dot(Matriz_Simetrica, Tamanho_Matriz, URL);
					//Gera o arquivo concatenado com seu respectivo fecho

				}
				//verifica a simetria da relação
				if(Verifica_Transitivo(Matriz,Tamanho_Matriz,Arquivo_Leitura) == true){
					printf("\nO arquivo de entrada possui a propriedade transitiva!\n");
				}
				else{
					int **Matriz_Transitiva;
					char URL[999];
					strcpy(URL,argv[2]);
					strcat(URL, "_Transitiva.dot");
					//Cria ponteiro para ponteiro(Matriz)
					Matriz_Transitiva = (int**)Preenche_Matriz(Matriz_Transitiva,Tamanho_Matriz,Arquivo_Leitura);
					for(int i = 0; i < Tamanho_Matriz; i++){
						for(int j = 0; j < Tamanho_Matriz; j++){
							Matriz_Transitiva[i][j] = Matriz[i][j];
						}
					}
					//calcula o fecho
					//primeiro verifica se a função para verificar o fecho reflexivo retornou tr
					Calcula_Fecho_Transitivo(Matriz_Transitiva, Tamanho_Matriz, Arquivo_Leitura);
					//Chama funcao para gerar fecho reflexivo na matriz reflexiva
					Gera_Arquivo_Dot(Matriz_Transitiva, Tamanho_Matriz, URL);
					//Gera o arquivo concatenado com seu respectivo fecho
				}
			}else{
				printf("\nQuantidade de nós inválida!\n");
				return 0;
				//Passou mais argumentos que o necessário
			}
		}else{
			printf("\nFoi passado uma quantidade diferente da esperada de argumentos, porfavor abra novamente a aplicação\n");
			return 0;
			
		}
		
	return 1;
}