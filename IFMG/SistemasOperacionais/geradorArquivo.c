#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Cria um Par de Arquivos de Matrizes que podem ser multiplicadas
void main(int argc, char const *argv[]){
    if(argc == 2 && argv[1] != NULL){
        char caminho[100]; 
    	int linhas=0;//Evita lixo
    	int iguais=0;//Evita Lixoint linhas 0;//Evita lixo
    	int colunas=0;//Evita Lixo
        srand(time(NULL));//Pseudo aleatorio
        float valor;
        FILE *arquivo;

        //Caminho passado +"-a"
        strcpy(caminho,argv[1]);
        strcat(caminho, "-a");
        arquivo = fopen(caminho,"w");

    	//printf("Digite o numero de linhas:\n");//Nlinhas
    	//scanf("%d",&linhas);
    	//printf("Digite o numero de colunas:\n");//NColunas
    	//scanf("%d",&colunas);


    	linhas  =(int)(rand() % 15);
    	iguais  =(int)(rand() % 15);
    	colunas =(int)(rand() % 15);


    	
        if(arquivo != NULL){ //Se criou o arquivo corretamente
            fprintf(arquivo,"%i\n",linhas);
            fprintf(arquivo,"%i\n",iguais);
            for(int i = 0; i < linhas; i++){
                for(int j = 0; j < iguais; j++){
                    valor = (float)(rand() % 100 + 1) / (rand() % 10 + 1);
                    fprintf(arquivo,"%.2f ",valor);
                }
                fprintf(arquivo,"\n");
            }
            fclose(arquivo);//Fecha o arquivo evitando erro
        }

        //Caminho passado +"-b"
        strcpy(caminho,argv[1]);
        strcat(caminho, "-b");
        arquivo = fopen(caminho,"w");

        arquivo = fopen(caminho,"w");
        if(arquivo != NULL){ //Se criou o arquivo corretamente
            fprintf(arquivo,"%i\n",iguais);
            fprintf(arquivo,"%i\n",colunas);
            for(int i = 0; i < iguais; i++){
                for(int j = 0; j < colunas; j++){
                    valor = (float)(rand() % 100 + 1) / (rand() % 10 + 1);
                    fprintf(arquivo,"%.2f ",valor);
                }
                fprintf(arquivo,"\n");
            }
            fclose(arquivo);//Fecha o arquivo evitando erro
        }

    }else{
        printf("É necessário passar o caminho/nome do arquivo de matriz!\n");
    }
}