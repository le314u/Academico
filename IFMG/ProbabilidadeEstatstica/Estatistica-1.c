#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NomeAplicacao argv[0] //String referente ao nome da aplicação concatenado a "./"
#define NomeArquivo argv[1] //String referente ao segundo parametro
#define CasasPrecisao argv[2] //String referente ao nome da aplicação concatenado a "./"
#define DEBUG printf("\nLinha[%d] OK\n",__LINE__);

void Quick_Sort(float vetor[], int inicio, int fim){//Algoritmo Auxiliar para a Ordenação de um Roll;
	float pivo, aux;
    int i, j, meio;
	i = inicio;
	j = fim;
	meio = (int) ((i + j) / 2);
	pivo = vetor[meio];
	do{
		while (vetor[i] < pivo) i = i + 1;
		while (vetor[j] > pivo) j = j - 1;
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	}while(j > i);
	if(inicio < j){
		Quick_Sort(vetor, inicio, j);
	}
	if(i < fim) {
		Quick_Sort(vetor, i, fim);  
	} 
}

float Arredondamento(float Valor,int Precisao){

    Valor *= (Precisao);
    Valor = ((Valor-((int)Valor))>=0.5)?ceil(Valor):floor(Valor);
    Valor /= Precisao;
    return Valor;
}


int main(int argc, char const *argv[]){
    int Precisao;
    int NCasasPrecisao;
    if(argc == 3){
        NCasasPrecisao = atoi(CasasPrecisao);
        Precisao = pow(10,atoi(CasasPrecisao));
        printf("Precisao é de %d casa(s) apos a virgula\n",NCasasPrecisao);
    }else{
        Precisao = 100;
        NCasasPrecisao = 2;
        printf("A precisao padrao é de 2 casas decimais caso queira trocar passa o numeros de casa como argumento apos o nome do arquivo\n");
    }
    if(argc==1){//Verifica Se passou os parametros corretos
         printf("Nenhum arquivo foi passado por parametro.\nPor favor, ao chamar o arquivo digite <%s \"Nome do arquivo\">\n",NomeAplicacao);
         return 1;
    }
    FILE *Arquivo;//Cria um ponteiro para arquivo
    Arquivo=fopen(NomeArquivo,"rt");//Abre o arquivo em modo leitura de texto
    if(Arquivo==NULL){//Não foi possivel abrir o arquivo
            printf("%s não foi encontrado.\n"
                "Por favor, verifique o nome do arquivo e se ele está na pasta corrente.\n"
                "Digite ls e tecle enter e procure pelo nome do arquivo para se certificar que está no diretorio correto."
                "\nCaso o nome do arquivo tenha ' '[espaço] coloque o espaço precedido de \\ [back slash] ou coloque todo o nome do arquivo detro de aspas ['Nome do Arquivo' ou \"Nome do Arquivo\"]\n",NomeArquivo);
       return 1;
    }
    printf("Abrindo o arquivo <%s>...\n",NomeArquivo);
    float *vet;//Vetor dinamico
    vet = malloc(sizeof(float));//Aloca um vetor dinamico
    int TElementos = 1;//Representa o numero de celulas do vetor
    float temp = 0;

    
    while(1){//Le todo o arquivo
        vet = (float *)realloc(vet,TElementos*sizeof(float));//Realloca o vetor
        if(vet == NULL){
            printf("Erro na alocação de memória.\n");
            return 1;
        }
        fscanf(Arquivo,"%f",&temp);//Le um dado do Arquivo e salva em uma variavel temporaria e depois joga no vetor
        vet[TElementos - 1] = temp;//Passa de Temp para o vetor
        fgetc(Arquivo);//Pula o 'separador' seja ele qual for desde que seja do tamanho de 1 caractere
        if(feof(Arquivo) == 1){
            if(TElementos > 1){//Caso TElementos seja = 1 e tenha chegado no final do arquivo significa que não chegou a ler nenhuma elemento do arquivo pois este está vazio
                printf("O arquivo <%s> foi lido com sucesso.\n",NomeArquivo);
            }else{
                printf("O arquivo <%s> está vazio.\n",NomeArquivo);
            }
            break;
        }
        TElementos++;//Aumenta o total de posições no vetor
    }
    fclose(Arquivo);//Fecha o arquivo para evitar erro
    printf("\n\n");

    Quick_Sort(vet,0,TElementos);//Ordena o Vetor


    for(int i=1;i<TElementos+1;i++){//Printa o mais proximo de uma matriz quadrada
        printf("[%d]%.4f\t",i,vet[i]);
        if((i) % abs(sqrt(TElementos))==0){
            printf("\n");
        }
    }

    Arquivo=fopen("Analise.html","w");//Abre o arquivo em modo leitura de texto
    if(Arquivo==NULL){//Não foi possivel abrir o arquivo
         printf("Erro ao criar o arquivo Analise.html\n");
         return 1;
    }
    

    //Analise dos dados
    float NClasses = 1 + (3.32 * log10(TElementos));//Fórmula de Sturges
    NClasses = (NClasses>25)?floor(NClasses):ceil(NClasses);//Operador Ternário para arredondar para cima ou para baixo
    printf("Numero de Classes = %f\n",NClasses);
    float AmplitudeClasse = (vet[TElementos] - vet[1])/NClasses;//Amplitude de cada classe

    Arredondamento(AmplitudeClasse,Precisao);
    printf("Amplitude de classe é %f\n",AmplitudeClasse);

    float **RangeClasse = (float **)calloc(NClasses , sizeof(float *));//Aloca um vetor de vetor ou seja uma futura matrix
    for(int i=0; i<NClasses; i++){
         RangeClasse[i] = (float *)calloc(7 , sizeof(float ));//Aloca 7 Colunas para cada linha fazendo o vetor virar uma matriz
    }

    //Preencher Range da Classe
    RangeClasse[0][0] = vet[1];
    RangeClasse[0][1] = vet[1] + AmplitudeClasse;
    for(int i=1; i<NClasses; i++){
        RangeClasse[i][0] = RangeClasse[i-1][0] + (AmplitudeClasse);
        RangeClasse[i][1] = RangeClasse[i-1][1] + (AmplitudeClasse);
    }
    
    //ponto médio
    for(int i=0; i<NClasses; i++){
        RangeClasse[i][2] = RangeClasse[i][0] + (AmplitudeClasse / 2);// RangeClasse[i][0] + ((RangeClasse[i][1] - RangeClasse[i][0]) / 2);
    }
   
    //Preenche a frequencia
    for(int i=1; i<=TElementos; i++){
        for(int j=0; j<NClasses; j++){
            if ((vet[i] >= RangeClasse[j][0] && vet[i] < RangeClasse[j][1])||(i == TElementos+1 && vet[i] == RangeClasse[(int)(NClasses-1)][1])){//Verifica em qual classe o Arquivo se encontra
                RangeClasse[j][3]+=1;
                break;
            }
        }
    }


    //Preenche a Porcentagem
    for(int i=0; i<NClasses; i++){
        RangeClasse[i][4] =  RangeClasse[i][3] / TElementos;
        RangeClasse[i][4] = Arredondamento(RangeClasse[i][4],Precisao);
        
    }

    //Preenche a frequencia acumulada
    RangeClasse[0][5] = RangeClasse[0][3];

    for(int i=1; i<NClasses; i++){
        RangeClasse[i][5] = RangeClasse[i-1][5] + RangeClasse[i][3];
        printf("%f %f ",RangeClasse[i][5],RangeClasse[i][3]);
    }

    //Preenche a Porcentagem acumulada
    RangeClasse[0][6] = RangeClasse[0][4];
    for(int i=1; i<NClasses; i++){
        RangeClasse[i][6] = RangeClasse[i-1][6] + RangeClasse[i][4];
    }

    //Printa A tabela
    printf("\n\n");
    for(int i=0; i<NClasses; i++){
        printf("%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",RangeClasse[i][0],RangeClasse[i][1],RangeClasse[i][2],RangeClasse[i][3],RangeClasse[i][4],RangeClasse[i][5],RangeClasse[i][6]);
    }
    
    fprintf(Arquivo,"<!DOCTYPE html>\n"//Abertura do Html
            "<html>\n"
            "\t<head>\n"
            "\t\t<title>%s</title>\n"
            "\t\t<meta charset=\"UTF-8\">\n"
            "\t</head>\n"
            "\t<body>\n"
            "\t\t<table border=\"1px\" bordercolor=\"#000\">\n",NomeArquivo);
    fprintf(Arquivo,"\t\t\t<tr>\n");
    fprintf(Arquivo,"\t\t\t\t<td>Intervalo Aberto</td><td>Intervalo Fechado</td><td>Ponto médio</td><td>Frequencia</td><td>Frequencia relativa</td><td>Frequencia acumulada</td><td>Frequencia relativa acumulada</td>\n");
    fprintf(Arquivo,"\t\t\t</tr>\n");
    for(int i=0; i<NClasses; i++){
        fprintf(Arquivo,"\t\t\t<tr>\n");
        for(int j=0; j<7; j++){
            fprintf(Arquivo,"\t\t\t\t<td>%f</td>\n",RangeClasse[i][j]);
        }
        fprintf(Arquivo,"\t\t\t</tr>\n");
    }  
    fprintf(Arquivo,"\t\t</table>\n");//Fecha a Tabela
    fprintf(Arquivo,"\t</body>\n"//Encerramento do Html
            "<html>");
    fclose(Arquivo);//Fecha o arquivo para evitar erro
    return 0;
}
