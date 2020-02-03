///////////////////////////////////////////////////////////////////////////
//Leandro Souza Pinheiro 	0015137	//						
//Lucas Mateus Fernandes 	0035411	//
//////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//inclui bibliotecas

#define DEBUG printf("\nLinha = %d Arquivo = %s\n",__LINE__,__FILE__);
//define constante para debugar codigo e encontrar possiveis erros
#define true 1//define valor para representar true e false
#define false 0
#define  ERRO  0.001//define erro para executar aproximacoes 

typedef int bool;//Cria um tipo para simular retornos do tipo Boolean
typedef struct arquivo{//struct para receber valores lido do arquivo
	double *x;
	double *y;
	int n;
	double a;
	double b;
	double i;
	double *p;
	double t;
}ARQUIVO;
typedef struct Matrizes{//Struct responsavel por representar as matrizes que serao criadas
	double **MatrizA;
	double *VetorB;
	double *VetorX;
}MATRIZ;

//Resolve uma função Polinomial de maneira mais eficiente
//Recebe Um vetor com os coeficiente o tamanho do vetor e o valor de X
//Retorna f(x) ou seja a imagem no ponto X
double Horner(double Coeficiente[],int Tamanho,double DominioX){
	double ImagemY=Coeficiente[0];
		for (int i = 1; i < Tamanho; ++i){
		ImagemY=ImagemY*DominioX+Coeficiente[i];
	}
	return ImagemY;//retorna a imagem do ponto passado
}
/*
Funcao responsavel por realizar a triangulacao da matriz ou seja ira zerar os valores a baixo da 
diagonal principal, vale ressaltar que ela realiza um pivotiamento dos valores caso seja necessario
*/
void Gauls(int Tamanho,double **MatrizA,double VetorB[]){
	//Cria Dois vetores para realizar trocas de linhas da matriz  
	double VetorSwapA[Tamanho];
	double VetorSwapB[Tamanho];
	double Aux = 0;
	//Inicializa os Vetores do Swap para evitar lixo de memoria
	for (int i = 0; i < Tamanho; ++i)
	{
		 VetorSwapA[i]=0;//zera vetor de troca
		 VetorSwapB[i]=0;//zera vetor de troca
	}
	//Vai da primeira até a penultima linha zerando-as
	for (int Pivo = 0; Pivo < (Tamanho-1); ++Pivo)
	{
		int IndiceMaior = Pivo;//indice maior inicialmente recebe o Pivo
		double Maior = MatrizA[Pivo][Pivo];//maior elemento recebe pivo

		//Faz as trocas da linha Pivo
		for (int SwapIndice = Pivo; SwapIndice < Tamanho; ++SwapIndice){
			if(SwapIndice != Pivo){
				if (fabs(Maior)<fabs(MatrizA[SwapIndice][Pivo]))
				{//verifica se é maior em modulo que o atual maior
					 IndiceMaior = SwapIndice;//recebe o indice do maior
					 Maior = MatrizA[SwapIndice][Pivo];//recebe o maior elemento
				}
			}
		}
		//Realiza a Troca
		for (int i = 0; i < Tamanho; ++i)
		{
			//Swap A da Matriz
			 VetorSwapA[i]=MatrizA[Pivo][i];
			 MatrizA[Pivo][i]=MatrizA[IndiceMaior][i];
			 MatrizA[IndiceMaior][i]=VetorSwapA[i];
		}
		//Swap B Vetor
		Aux=VetorB[Pivo];
		VetorB[Pivo]=VetorB[IndiceMaior];
		VetorB[IndiceMaior]=Aux;
		
		//Acha o Escalar que ira zerar as linhas
		double Escalar=1;
		double mult = 1;
		for (int LinhaTrabalha = (Pivo+1); LinhaTrabalha < Tamanho; ++LinhaTrabalha)
		{
			 Escalar=MatrizA[LinhaTrabalha][Pivo]/MatrizA[Pivo][Pivo];
			//Resolução Começa a Zerar
			for (int Coluna = 0; Coluna < Tamanho; ++Coluna)
			{
				MatrizA[LinhaTrabalha][Coluna]=MatrizA[LinhaTrabalha][Coluna]-(Escalar*MatrizA[Pivo][Coluna]);
				mult = Escalar * MatrizA[Pivo][Coluna];
				if(fabs(MatrizA[LinhaTrabalha][Coluna]) < ERRO){//Verifica se o valor é menor que o erro definido
					MatrizA[LinhaTrabalha][Coluna] = 0;//Ajuste devido a aproximacao de valores 
				}
			}
			 VetorB[LinhaTrabalha]=VetorB[LinhaTrabalha]-(Escalar*VetorB[Pivo]);//Multiplica o vetor b
		}
	}
	return;
}
/*
	Funcao responsavel por realizar a substitucao retroativa da matriz com o intuito de encontrar os valores de x 
*/
void SubsRetro(int Tamanho,double **MatrizA,double VetorB[],double VetorX[]){
	double Somatorio = 0;
	double AuxTruc = 0;
	double Aux = 0, Aux1 = 0;
	//..declara variaveis

	//Zera matriz para evitar erros
	for(int i = 0;i < Tamanho;i++)
	{
		VetorX[i] = 0;	
	}
	
	//Acha o primeiro x que é atípico
	VetorX[Tamanho-1] = VetorB[Tamanho-1] / MatrizA[Tamanho-1][Tamanho-1];
	
	//Acha os demais X
	for(int i = (Tamanho-2);i >= 0;i--)
	{
		Somatorio = 0;
		//Somatorio recebe 0
		for(int j = i;j < Tamanho;j++)
		{//For para percorrer a matriz e vetor e encontrar o valor do somatorio
			Somatorio = Somatorio + MatrizA[i][j] * VetorX[j];
		}
		Aux = 0;
		AuxTruc = 0;
		Aux1 = 0;
		//Zera valores para evitar erros
		VetorX[i] = (VetorB[i] - Somatorio) / MatrizA[i][i];//Vetor x recebe o valor
		AuxTruc = trunc(VetorX[i]);
		Aux = (VetorX[i]) - (AuxTruc);
		Aux1 = (double) (1 - fabs(Aux));
		//Responsavel por realizar truncamento e arredondamento dos valores
		if(fabs(Aux1) <= ERRO){
			if(Aux >= 0){//Caso menor ou igual a zero
				VetorX[i] = ceil(VetorX[i]);//Arredonda para cima
			}else{//se nao arredonda para baixo
				VetorX[i] = floor(VetorX[i]);
			}
		}//Realiza o mesmo arredondamento com base no outro auxiliar 
		if(fabs(Aux) <=ERRO){
			if(Aux < 0){
				VetorX[i] = ceil(VetorX[i]);
			}else{
				VetorX[i] = floor(VetorX[i]);
			}
		}
		if(VetorX[i] == (-0)){//Se por algum erro o valor estiver com -0
			VetorX[i] = 0;//recebe 0
		}
	}
}

/*
	Funcao responsavel por calcular a integral da funcao
*/
double Funcao(ARQUIVO *Lido, MATRIZ *Interpolado){
	//Descobre o Tamanho da altura ( que é o mesmo tamanho para todos)
	double Range = Lido->b - Lido->a;
	double Altura=(double)Range/Lido->t;
	//Somatorio das areas do trapeziozio;
	double Ponto1=Lido->a;//F(Lido->a)
	double Ponto2=Lido->a + Altura;//F(Lido->a+Range)
	double AreaTotal = 0;//zera a area total para evitar erros
	double Area = 0;//zera a area do trapezio para evitar erros
	
	for (int i = 0; i < Lido->t; ++i){
		Area = (double) ((((Horner(Interpolado->VetorX,Lido->n, Ponto1) + Horner(Interpolado->VetorX,Lido->n, Ponto2)) * Altura) / 2 ));   // (B+b)*H/2
		Ponto1 += Altura;//recebe proximo ponto
		Ponto2 += Altura;//recebe proximo ponto
		AreaTotal += Area;//soma a area do trapezio encontrada a area total da funcao
	}
	return AreaTotal;//Retorna a area total
}
/*
	Funcao responsavel por preparar a matriz com base nos valores lidos do arquivo
*/
void Prepara_Matriz(ARQUIVO *Lida,MATRIZ *matriz){
	matriz->MatrizA = (double**)malloc(Lida->n * sizeof(double*));//aloca as linhas da matriz
	for(int i = 0;i < Lida->n;i++){//aloca as colunas da matriz
		matriz->MatrizA[i] = (double*)malloc(Lida->n * sizeof(double));
	}
	//preenche a MatrizA
	for(int i = 0;i < Lida->n;i++){//linha
		for(int j = (Lida->n - 1);j >= 0 ;j--){//coluna
			if(j == Lida->n - 1){
				matriz->MatrizA[i][j] = 1; // x⁰ = 1
			}else if(j == Lida->n - 2){
				matriz->MatrizA[i][j] = Lida->x[i];// x¹ = x
			}else{
				matriz->MatrizA[i][j] = matriz->MatrizA[i][j + 1] * matriz->MatrizA[i][Lida->n - 2]; 
				// x^n = x^(n-1) * x
				// Mais eficiente que POW 
			}
		}
	}
	// Preenche Vetor B
	matriz->VetorB = (double*)malloc(Lida->n * sizeof(double));//aloca vetor b
	for(int j = 0;j < Lida->n;j++){//coluna
		matriz->VetorB[j] = Lida->y[j];//preenche vetor b com os valores lidos do arquivo
	}
	matriz->VetorX = (double*)malloc(Lida->n * sizeof(double));//aloca vetor X
	for(int j = 0;j < Lida->n;j++){//coluna
		matriz->VetorX[j] = 0;//preenche o vetor x com 0 para evitar erros
	}
}

void Seta_Valores_Structs_Verifica_0(ARQUIVO *Verifica){
//Funcao responsavel por setar todos os valores como False indicando que ainda nao foram lidos corretamente 
	Verifica->x=(double*)malloc(sizeof(double));
	Verifica->y=(double*)malloc(sizeof(double));
	Verifica->p=(double*)malloc(sizeof(double));
	//aloca os ponteiros na memoria
	Verifica->x[0] = false;
	Verifica->y[0] = false;
	Verifica->n = false;
	Verifica->a = false;
	Verifica->b = false;
	Verifica->i = false;
	Verifica->p[0] = false;
	Verifica->t = false;
	//seta valores como false 
}
bool Verifica_Arquivo_Valido(ARQUIVO Verifica){
	//Verifica se todos campos da struct esta como true indicando que arquivo tem parametros corretos
	if(Verifica.x[0] == true){
		if(Verifica.y[0] == true){
			if(Verifica.n == true){
				if(Verifica.a == true){
					if(Verifica.b == true){
						if(Verifica.i == true){
							if(Verifica.p[0] == true){
								if(Verifica.t == true){
									return true;//retorna true indicando que foi corretamente
								}
							}
						}
					}
				}
			}
		}
	}
	return false;//retorna false indicando que nao foi corretamente
}

/*
	funcao responsavel por ler os valores do arquivo
*/
int Interpolacao(char Url[],ARQUIVO *File){
	FILE *Arquivo; //ponteiro para abrir arquivo
	ARQUIVO Verifica;
	Seta_Valores_Structs_Verifica_0(&Verifica);//seta valores como 0
	Arquivo=fopen(Url,"r");//abre arquivo em modo de leitura
	char Buff;//char para ler primeiro caractere do arquivo
	double valor;//valor para receber numero lido do arquivo
	char String[9999];//string para pular linha do arquivo
	//Verifica se o arquivo existe
	if(Arquivo == NULL ){
		printf("O arquivo não foi aberto\n");
		return -1;//retorna -1 indicando que o arquivo nao existe
	}
	//Le o Arquivo ate encontrar o final
	while(!feof(Arquivo)){
		fscanf(Arquivo,"%c",&Buff);
		if(feof(Arquivo)){//Caso chegue no fim do arquivo sai do LOOP
			break;
		}
		//Verifica se a linha é um comentario
		if(Buff == '#'){
			fscanf(Arquivo,"%[^\n]s",String);
			//Pula o /n
			getc(Arquivo);
			continue;
		}
		switch (Buff){//Switch que verifica qual caractere foi lido do arquivo
			case 'n'://Caso seja o caractere N 
				Verifica.n = true;
				fscanf(Arquivo,"%c",&Buff);//Pula o espaço
				fscanf(Arquivo,"%d",&File->n);//Le o Tamanho
				fscanf(Arquivo,"%c",&Buff);//Pula o \n
				break;
			case 'x'://Caso caractere X
				fscanf(Arquivo,"%c",&Buff);//Pula o espaço
				File->x=(double*)malloc(sizeof(double));// Aloca o ponteiro na memoria
					for(int i = 1;i <= File->n;i++){
						fscanf(Arquivo,"%lf",&valor);//le o valor
						getc(Arquivo);//Pula
						File->x=(double*)realloc(File->x,i * sizeof(double));//realoca o vetor
						File->x[i-1] = valor;//coloca o valor lido no vetor
						if(i == File->n ){//caso todo o vetor tenha sido preenchido
							Verifica.x[0] = true;//coloca como verdadeiro na struct de verificador indicando que o vetor contendo os valores de x foi preenchido corretamente
						}
					}
				break;
			case 'y'://caso Y
				fscanf(Arquivo,"%c",&Buff);//Pula o espaço
					File->y=(double*)malloc(sizeof(double));//Aloca o vetor y na memoria
					for(int i = 1;i <= File->n;i++){
						fscanf(Arquivo,"%lf",&valor);//le o valor do arquivo
						if(valor == '-'){//caso leia o - multiplica o valor por -1 para pegar o negativo
							getc(Arquivo);
							fscanf(Arquivo,"%lf",&valor);
							valor = valor * -1;
						}
						getc(Arquivo);	
						File->y=(double*)realloc(File->y,i * sizeof(double));//realoca o ponteiro
						File->y[i-1] = valor;//coloca o valor lido do arquivo no vetor de Y
						if(i == File->n ){
							Verifica.y[0] = true;//verificador como true indicando que foi lido corretamente do vetor
						}
					}
				break;
			case 'a'://caso caractere a 
				fscanf(Arquivo,"%c",&Buff);//Pula o espaço
				fscanf(Arquivo,"%lf",&valor);
				File->a = valor;
				fscanf(Arquivo,"%c",&Buff);//Pula o \n
				Verifica.a = true;//verificador recebe true indicando que o valor foi lido
				break;
			case 'b'://Caso caratere b
				fscanf(Arquivo,"%c",&Buff);//Pula o espaço
				fscanf(Arquivo,"%lf",&valor);
				File->b = valor;
				fscanf(Arquivo,"%c",&Buff);//Pula o \n
				Verifica.b = true;//verificador recebe true indicando que o valor foi lido
				break;
			case 'i'://Caso caractere i
				fscanf(Arquivo,"%c",&Buff);//Pula o espaço
				fscanf(Arquivo,"%lf",&valor);
				File->i = valor;
				fscanf(Arquivo,"%c",&Buff);//Pula o \n
				Verifica.i = true;//verificador recebe true indicando que o valor foi lido
				break;
			case 'p'://caso caractere p
				File->p=(double*)malloc(sizeof(double));//aloca o vetor na memoria
				fscanf(Arquivo,"%c",&Buff);//Pula o espaço
					for(int i = 1;i <= File->i;i++){
						fscanf(Arquivo,"%lf",&valor);
						getc(Arquivo); 	
						File->p=(double*)realloc(File->p,i * sizeof(double));//realoca o vetor
						File->p[i-1] = valor;//insere o valor lido dentro do vetor
						if(i == File->i ){
							Verifica.p[0] = true;//verificador recebe true indicando que o valor foi lido
						}
					}
				break;
			case 't':
				fscanf(Arquivo,"%c",&Buff);//Pula o espaço
				fscanf(Arquivo,"%lf",&valor);
				getc(Arquivo); 	
				File->t = valor;//recebe o valor
				fscanf(Arquivo,"%c",&Buff);//Pula o \n
				Verifica.t = true;//verificador recebe true indicando que o valor foi lido
				break;
			case '\n'://caso caractere \n 
				break;
			case ' '://caso encontre algum espaco
				break;
			default://se ler algum caractere diferente do esperado 
				printf("Erro ao ler, arquivo invalido\n");//mostra erro
				return -2;//sai funcao
				break;
		}
	}
	fclose(Arquivo);//fecha arquivo para eviar erros
	if(Verifica_Arquivo_Valido(Verifica) == false){//se passou pelo arquivo todo e o verificador se manteve em falso indica que o arquivo esta incompleto
		printf("Erro ao ler arquivo incompleto\n");//mostra na tela
		return -3;//sai da funcao com retorno de erro referente ao arquivo incompleto
	}
	
	return 0;//sai da funcao com retorno padrao
}
/*
	Funcao responsavel por gerar arquivo de saida
*/
int OutPut(ARQUIVO File,char ArqOut[], MATRIZ Matriz_Interpolacao){
	FILE *Arquivo = fopen(ArqOut,"w");//abre arquivo em modo de escrita
	if(Arquivo == NULL){//caso nao consiga abrir o arquivo
		printf("Erro ao abrir o arquivo");//mostra mensagem de eroo
		return -5;//sai da funcao retornando numero de erro
	}
	fprintf(Arquivo,"######################################################################\n");
	fprintf(Arquivo,"# Script automatico gerado por ‘trapezium', software de interpolação \n");
	fprintf(Arquivo,"# e integracao numerica\n");
	fprintf(Arquivo,"######################################################################\n\n");
	//printa cabeçalho do arquivo
	fprintf(Arquivo,"# Nome da figura\n\n");

	fprintf(Arquivo,"nome <- '%s.png'\n",ArqOut);//nome do arquivo de saida

	fprintf(Arquivo,"# Dados tabelados\n\n");

	fprintf(Arquivo,"x.tab <- c(");
	fprintf(Arquivo, "%lf",File.x[0]);//printa coeficientes X lidos do arquivo

	for (int i = 1; i < File.n; ++i)
	{
		fprintf(Arquivo, ", %lf",File.x[i]);//printa coeficientes X lidos do arquivo
	}

	fprintf(Arquivo,");\n\n");

	fprintf(Arquivo,"y.tab <- c(");
	fprintf(Arquivo, "%lf",File.y[0]);//printa coeficientes Y lidos do arquivo
	for (int i = 1; i < File.n; ++i)
	{
		fprintf(Arquivo, ", %lf",File.y[i]);///printa coeficientes y lidos do arquivo
	}
	fprintf(Arquivo,");\n\n");
	fprintf(Arquivo,"# Pontos interpolados, calculados pelo ‘trapezium'\n\n");

	fprintf(Arquivo,"x.int <- c(");
	
	fprintf(Arquivo, "%lf",File.p[0]);
	for (int i = 1; i < File.i; ++i)
	{
		fprintf(Arquivo, ", %lf",File.p[i]);//printa coeficientes a serem interpolados
	}
	fprintf(Arquivo,");\n\n");


	fprintf(Arquivo,"y.int <- c(");
	fprintf(Arquivo, "%lf",Horner(Matriz_Interpolacao.VetorX,File.n,File.p[0]));//HORNER NO PONTO X que foi passado
	for (int i = 1; i < File.i; ++i)
	{
		fprintf(Arquivo, ", %lf",Horner(Matriz_Interpolacao.VetorX,File.n,File.p[i]));//HORNER NO PONTO X que foi passado
	}
	fprintf(Arquivo,");\n\n");


	fprintf(Arquivo,"# Coeficientes do polinomio interpolador\n\n");

	fprintf(Arquivo,"coef <- c(");//N

	for (int i = (File.n - 1); i >= 0; --i){
		//if(Matriz_Interpolacao.VetorX[i] != 0){
			if(i != 0){//caso nao seja o ultimo a printar insere virgula
				fprintf(Arquivo, "%lf, ",Matriz_Interpolacao.VetorX[i]);
			}else{//caso seja o ultimo valor nao insere virgula
				fprintf(Arquivo, "%lf",Matriz_Interpolacao.VetorX[i]);
			}
		//}
	}
	fprintf(Arquivo,");\n\n");

	fprintf(Arquivo,"# Numero de pontos da tabela\n\n");

	fprintf(Arquivo,"n.tab <- ");
	fprintf(Arquivo,"%d",File.n);//tamanho da matriz
	fprintf(Arquivo,";\n\n");


	fprintf(Arquivo,"# Numero de pontos a interpolar\n\n");

	fprintf(Arquivo,"n.int <- ");
	fprintf(Arquivo,"%d",(int)File.i);//tamanho de pontos a interpolar
	fprintf(Arquivo,";\n\n");

	fprintf(Arquivo,"# Numero de trapezios\n");

	fprintf(Arquivo,"n.tpz <- ");
	fprintf(Arquivo,"%d",(int)File.t);//numero de trapezios

	fprintf(Arquivo,";\n# Titulo\n");

	fprintf(Arquivo,"titulo <- \"P(x) = ");//Vetor X sera o titulo da figura

	fprintf(Arquivo,"((%f)*X^%d )",Matriz_Interpolacao.VetorX[0],((File.n)-1));
	for (int i = 1; i < File.n; ++i)
	{
		if((i % 3)==0){//a cada 3 printados quebra linha
			fprintf(Arquivo,"\n");
		}
		fprintf(Arquivo,"+ ((%f)*X^%d )",Matriz_Interpolacao.VetorX[i],((File.n - i)-1));
	}
	fprintf(Arquivo, "\";\n");

	//Parte Estática do arquivo, literalmente copiada e colada aqui...
	fprintf(Arquivo,"#\n\
	# Esta parte do script deve funcionar desde que os parametros\n\
	# acima estejam devidamente preenchidos. E' a parte estatica\n\
	# do script. Copiar exatamente desta forma no arquivo de saida.\n\
	#\n\
	# Calcula o valor interpolado para o pto x\n\
	polinomio <- function(x, coef, n)\n\
	{\n\
		\tresultado <- 0;\n\
		\tfor(i in 1:n)\n\
		\t{\n\
			\t\tresultado <- resultado + coef[i]*(x^(i-1));\n\
		\t}\n\
		\treturn(resultado);\n\
	}\n\
	#\n\
	# Aqui comecam os comandos para plotar os resultados\n\
	#\n\
	# Cria o arquivo .png\n\
	png(nome);\n\
	# Gerando figura com 100 pontos\n\
	gap <- (max(x.tab) - min(x.tab)) / 100;\n\
	x <- seq(min(x.tab), max(x.tab), gap);\n\
	y <- polinomio(x, coef, n.tab);\n\
	plot(x,y,type='l', main=titulo);\n\
	# Plota os trapezios\n\
	h <- (max(x.tab) - min(x.tab)) / n.tpz;\n\
	xp <- seq(min(x.tab), max(x.tab), h);\n\
	yp <- polinomio(xp, coef, n.tab);\n\
	for(i in 1:(n.tpz))\n\
	{\n\
	polygon(c(xp[i], xp[i], xp[i+1], xp[i+1], xp[i]),\n\
	c(0, yp[i], yp[i+1], 0, 0),\n\
	col='yellow', border='black', lty=2, lwd=1.3);\n\
	\n\
	}\n\
	# Pontos da tabela\n\
	for(i in 1:n.tab)\n\
	{\n\
		\tpoints(x.tab[i], y.tab[i], col='red', pch=19);\n\
	}\n\
	# Pontos interpolados\n\
	\n\
	for(i in 1:n.tab)\n\
	{\n\
		\tpoints(x.int[i], y.int[i], col='blue', pch=19);\n\
	}\n\
	# Encerra a criacao do arquivo .png\n\
	dev.off();\n\
	");
	fclose(Arquivo);//fecha arquivo para evitar erros
}

int main(int argc, char const *argv[])
{
	ARQUIVO File;//declara struct do arquivo
	MATRIZ Matriz_Interpolacao;//struct que contem dados da matriz interpolada
	double Integral = 0;//valor da integral da funcao é iniciado em zero
	char Url[999];//declara url para receber entrada e saida do arquivo
	if(argc < 3){//caso argumentos menor que 3
		if(argc == 1){//caso tenha passado apenas um argumento
			printf("Não foi passado o arquivo contendo os dados de entrada\n");//Mostra erro
			return 1;//sai do Main
		}
		printf("Foram passados poucos argumentos\n");//mostra alerta
	}
	strcpy(Url,argv[1]);//copia arquivo de entrada para a URL
	//copia o arquivo de entrada para a url
	Interpolacao(Url,&File);//chama funcao para ler do arquivo
	Prepara_Matriz(&File,&Matriz_Interpolacao);//prepara a matriz
	Gauls(File.n,Matriz_Interpolacao.MatrizA,Matriz_Interpolacao.VetorB);//realiza o Gaus
	SubsRetro(File.n, Matriz_Interpolacao.MatrizA, Matriz_Interpolacao.VetorB,
	Matriz_Interpolacao.VetorX);
	//realiza a substituicao para receber os valores de x
	//Mostra o relatorio no console
	printf("Trapezium: Interpolador/Integrador Numerico\n");//Começo do relatorio no terminal
	printf("Polinomio Interpolador:\n");
	printf("\nP(x) = ");//Mostra a funcao que foi interpolada
	for(int i = (File.n - 1);i >= 0;i--){
		if(i != 0){
			printf(" %lf*(X^%d) +",Matriz_Interpolacao.VetorX[i],((File.n - i)-1));
			//mostra o elemento => (constante) *  x ^(expoente)
		}else{
			printf(" %lf*(X^%d)",Matriz_Interpolacao.VetorX[i],((File.n - i)-1));
		}
	}
	printf("\n\n");//Volta ponteiro de escrita 2 vezes e printa espacos em branco
	for(int i = 0;i<File.i;i++){//chama o horner para mostrar a imagem do valor passado
		printf("P(%lf) = %lf\n",File.p[i],Horner(Matriz_Interpolacao.VetorX,File.n,File.p[i]));
	}
	Integral = Funcao(&File, &Matriz_Interpolacao);//Chama funcao responsavel por realizar 
	//o calculo da integral da funcao que foi interpolada utilizando regra do trapezio
	printf("Integral em [%lf,%lf] = %f\n", File.a,File.b,Integral);
	//printa o valor da integral no intervalo passado
	if(argc < 3){//caso nao tenha passado o argumento para o nome de saida
		strcpy(Url,"Saida.R");//coloca um nome padrao para evitar erros
	}else{
		strcpy(Url,argv[2]);//caso tenha passado o nome do arquivo de de saida utiliza o nome que o usuario passou
	}
	OutPut(File,Url,Matriz_Interpolacao);
	//chama funcao responsavel por gerar arquivo de saida
	return 0;//finaliza programa
}
