//#define Debug
/*
Falta fazer :
			
*/
#ifndef _Funcoes_ 
	//Se não estiver definido entra no if
#define _Funcoes_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Registros.h"
#include "Prototipos.h"
	//Inclui arquivos de cabeçalho

//Prototipos de Função
/*
int MenuInicialFeedback();	
int Opcao_Acoes();
int Main_All();
void Apagar_Modificar(char Url[99], int Codigo,int Modificar,MODO Modo,int Registro);
int Confirmacao();
int Intervalo_Vetor(int Vetor[],int Ultimo);
int Modo_Manipulacao();
void Quick_Sort(int vetor[], int inicio, int fim);
int Retorna_Linha_Codigo(char Url[99], int Codigo);
int Valida_Codigo(char Url[99],int Numero_De_Registros,int Modo_de_Abertura, int Tipo_DADO);
void Verificacao_Arquivo(char Url[99],int Modo_de_Abertura);
MODO Modo_Bin_ou_Txt(int Modo_de_Abertura);
int Converter_Decimal_Binario(int n0,int n1,int n2,int n3);
int Arquivo_Texto_Vazio(char Url[]);
void Verificacao_All();
int Ler_Configuracoes_Retorna_Modo_de_Abertura();
int Valida_Codigo_Produto(int Codigo, int Modo_de_Abertura);
void Recebe_Dados_Produtos(int Codigo[],int Quantidade[],int Pagamento[]);



*/
void Cria_Pasta(char Url[99]){
	char Pasta[100] = {"mkdir "};
	strcat(Pasta, Url);
	system(Pasta);
}
//Funçoes
void Verificacao_All(){
	//Texto
	Verificacao_Arquivo("Arquivos/Acomodacoes.txt",Arquivo_Texto);
	Verificacao_Arquivo("Arquivos/Codigo_Categoria.txt",Arquivo_Texto);
	Verificacao_Arquivo("Arquivos/Funcionarios.txt",Arquivo_Texto);
	Verificacao_Arquivo("Arquivos/Hospede.txt",Arquivo_Texto);
	Verificacao_Arquivo("Arquivos/Hotel.txt",Arquivo_Texto);
	Verificacao_Arquivo("Arquivos/Produtos.txt",Arquivo_Texto);
	//Binario
	Verificacao_Arquivo("Arquivos/Acomodacoes.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Codigo_Categoria.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Funcionarios.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Hospede.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Hotel.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Produtos.bin",Arquivo_Binario);

}
void OrdenaValoresTxt(){
	Verificacao_All();
	//Cria  os que nao existem para evitar mensagem de erro
	system("sort -n --output=Arquivos/Produtos.txt Arquivos/Produtos.txt");
	system("sort -n --output=Arquivos/Acomodacoes.txt Arquivos/Acomodacoes.txt");
	system("sort -n --output=Arquivos/Codigo_Categoria.txt Arquivos/Codigo_Categoria.txt ");
	system("sort -n --output=Arquivos/Funcionarios.txt Arquivos/Funcionarios.txt");
	system("sort -n --output=Arquivos/Hospede.txt Arquivos/Hospede.txt");
	system("sort -n --output=Arquivos/Hotel.txt Arquivos/Hotel.txt");
}

int Configuracoes(){
	int Enum_Manipulacao = 0,Enum_Errado=0; 
	FILE *Arquivo;
	do{
		Enum_Errado=0;
		Arquivo = fopen("Arquivos/Configuracoes.txt","r");
		if(Arquivo == NULL){
		//Arquivo Vazio Cria o Arquivo e ja salva o modo de manipulação
			Enum_Manipulacao = Modo_Manipulacao();
			//Interação com o usuário para saber o modo de manipulação
			Arquivo = fopen("Arquivos/Configuracoes.txt","w");
			//Cria o Arquivo;	
			fprintf(Arquivo,"%d",Enum_Manipulacao);
			//Printa no arquivo
		}else{
			int Vazio=Arquivo_Texto_Vazio("Arquivos/Configuracoes.txt");
			//Verifica se o arquivo está vazio
			if(Vazio){//Caso esteja	fecha e abre como escrita e salva o modo de manipulação
				fclose(Arquivo);
				//Fecha		
				Arquivo = fopen("Arquivos/Configuracoes.txt","w");
				//Abre modo escrita
				Enum_Manipulacao = Modo_Manipulacao();
				//Interação com o usuário para saber o modo de manipulação
				fprintf(Arquivo,"%d",Enum_Manipulacao);
				//Printa no arquivo
			}else{//Caso não apenas le
				fscanf(Arquivo,"%d",&Enum_Manipulacao);
				//Le um inteiro do Arquivo para Enum_Manipulacao
				if(Enum_Manipulacao<1 || Enum_Manipulacao>4){
					remove("Arquivos/Configuracoes.txt");
					Enum_Errado=1;
					//Condigo Enum não está em um range aceitavel
				}
			}
		}
		fclose(Arquivo);
	}while(Enum_Errado==1);
	//Fecha o Arquivo evitando erros
	return Enum_Manipulacao;
	//retorna Enum Manipulação
}

int Arquivo_Texto_Vazio(char Url[]){
	FILE *Arquivo;
	int Posicao=0;
	char Temp;
	Arquivo=fopen(Url,"r");
	//Abre o Arquivo

	while(1){//Repete ate que chegue a um break
		Temp=getc(Arquivo);
		//Passa o char do Arquivo para Temp e automaticamente desloca o ponteiro uma posição

		if(feof(Arquivo)||Posicao>1){//Repete até chegar no final do arquivo ou até capturar 2 char ou seja  com 2 leituras da para saber se chagamos ou não ao final do arquivo
			break;
		}

		Posicao++;
		//Adiciona 1 A posição ou seja se 0 o arquivo chegou a Eof na primeira busca
	}

	fclose(Arquivo);
	//Fecha o arquivo para evitar erros

	if(Posicao==0){
		return 1;
		//Retorna um caso o arquivo esteja vazio
	}else{
		return 0;
		//Retorna 0 caso o arquivo não esteja vazio
	}

}
int Arquivo_Binario_Vazio(char Url[]){
	FILE *Arquivo;
	int Posicao=0;
	char Temp='0';
	Arquivo=fopen(Url,"rb");
	//Abre o Arquivo

	while(1){//Repete ate que chegue a um break
		fread(&Temp,sizeof(char),1,Arquivo);
		//Passa o char do Arquivo para Temp e automaticamente desloca o ponteiro uma posição

		if(feof(Arquivo)||Posicao>1){//Repete até chegar no final do arquivo ou até capturar 2 char ou seja  com 2 leituras da para saber se chagamos ou não ao final do arquivo
			break;
		}

		Posicao++;
		//Adiciona 1 A posição ou seja se 0 o arquivo chegou a Eof na primeira busca
	}
	fclose(Arquivo);
	//Fecha o arquivo para evitar erros

	if(Posicao==0){
		return 1;
		//Retorna um caso o arquivo esteja vazio
	}else{
		return 0;
		//Retorna 0 caso o arquivo não esteja vazio
	}

}



int Opcao_Acoes(){
	int Acao;
	
	printf("\nDigite:"
			"\n\t1\tPara Ler"
			"\n\t2\tPara Criar"
			"\n\t3\tPara Editar"
			"\n\t4\tPara Apagar"
			"\n\t?\tSair\n\t");
		scanf("%d",&Acao);

		system("clear");
		
	return Acao;
}

int Opcao_Acoes_Reserva(){
	int Acao;
	
	printf("\nDigite:"
			"\n\t1\tPara Ler Reservas Cadastradas"
			"\n\t2\tPara Criar Reserva"
			"\n\t3\tPara Cancelar Reserva"
			"\n\t?\tSair\n\t");
		scanf("%d",&Acao);
	if(Acao == 3){
		Acao = 4;//evitar fadiga
	}else if(Acao == 4){//evitar fadiga parte 2
		Acao = 5;
	}
		system("clear");
	return Acao;
}

int Modulo(){
	int Registro = 0;
	do{
		printf("\nDigite:"
		"\n\t1\tPara Registros"
		"\n\t2\tPara Reservas"
		"\n\t3\tPara Pesquisas"
		"\n\t4\tFeedBack"
		"\n\t5\tPara Importar/Exportar XML"
		"\n\t6\tPara Transações"
		"\n\t0\tSair\n\t");
		scanf("%d",&Registro);
		system("clear");
		if(Registro <0 || Registro > 6){
			Vermelho("Digite um valor valido");	
		}
	}while(Registro <0 || Registro > 6);
	return Registro;
}

int Main_All(){
	int Registro = 0;
	do{
		printf("\nDigite:"
			"\n\t1\tPara Hotel"
			"\n\t2\tPara Hospedes"
			"\n\t3\tPara Acomodações"
			"\n\t4\tPara Categoria"
			"\n\t5\tPara Produtos"
			"\n\t6\tPara Fornecedores"
			"\n\t7\tPara Funcionários"
			"\n\t0\tSair\n\t");
		scanf("%d",&Registro);
		if (Registro <0 || Registro > 7)
		{
			if (Registro == 666)
			{
				system("clear");
				printf(""
"             ____________________________________________________\n"
"            /                                                    \\\n"
"           |    _____________________________________________     |\n"
"           |   |                                             |    |\n"
"           |   |  C:\\>Mint < Ubunto                          |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                   #Da 50 Manuel             |    |\n"
"           |   |_____________________________________________|    |\n"
"           |                                                      |\n"
"            \\_____________________________________________________/\n"
"                   \\_______________________________________/\n"
"                _______________________________________________\n"
"             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n"
"          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n"
"       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n"
"    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n"
" _-'.-.-.-.-.-. .---.-. .-----------------------------. .-.---. .---.-.-.-.`-_\n"
":-----------------------------------------------------------------------------:\n"
"`---._.-----------------------------------------------------------------._.---'\n");

			}else{
				system("clear");
				Vermelho("Digite uma opção válida\n");
			}
		}
	}while(Registro <0 || Registro > 7);
	system("clear");
	return Registro;
}
void Apagar_Modificar(char Url[99], int Codigo,int Modificar,MODO Modo,int Registro){
	int Linha = Retorna_Linha_Codigo(Url,Codigo);
	int Auxiliar = 0;

		//Retorna qual linha deve ser apagada
	if(Linha == -1){
		//Caso o codigo nãp esteja presente dentro do arquivo
		Vermelho("Codigo inexistente");
	}else{
		if(Registro == Dados_Codigo_Categoria ){
			Auxiliar = Valida_Acomadacao_Codigo_Categoria(Codigo, Modo.Modo_de_Abertura);
			//Auxiliar igual a 1 caso exista codigo presente dentro de alguma acomodacao tornando impossivel apagar

		}else if(Registro == Dados_Hotel){
			Auxiliar = Valida_Acomadacao_Hotel(Codigo, Modo.Modo_de_Abertura);
			//Auxiliar igual a 1 caso exista codigo presente dentro de alguma acomodacao tornando impossivel apagar
		}
		if(Auxiliar == 0){
			if(Confirmacao()){
				char Temporario[9999];
						//Somente é declara para alocação do ponteiro dentro do arquivo		
				FILE *Arquivo, *Arquivo_Temporario;
						//Ponteiros para Arquivos
				Arquivo = fopen(Url,Modo.Leitura);
						//Abre em modo Leitura
				Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
						//Abre para Editar

				for(int i=1;i<Linha;i++){
						//Vai ate a linha do codigo
					fscanf(Arquivo,"%[^\n]s",Temporario);
					fprintf(Arquivo_Temporario,"%s\n",Temporario);
					getc(Arquivo);
				}

				fscanf(Arquivo,"%[^;]s",Temporario);
					//Pula a Linha do Codigo

				if(Modificar==1){
						//Se for 1 a função serve para modificar caso contraria apenas apaga
						//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!SWITCH GRANDAO
					switch(Registro){
						case Dados_Hotel:
							Criar_Modificar_Hotel(Arquivo_Texto, Codigo);
							Verde("\nEditado com Sucesso");
							system("clear");
						break;
						case Dados_Hospede:
							Criar_Modificar_Hospede(Arquivo_Texto, Codigo);
							Verde("\nEditado com Sucesso");
							system("clear");
						break;
						case Dados_Acomodacoes:
							Criar_Modificar_Acomodacoes(Arquivo_Texto, Codigo);
							Verde("\nEditado com Sucesso");
							system("clear");
						break;
						case Dados_Codigo_Categoria:
							Criar_Modificar_Codigo_Categoria(Arquivo_Texto, Codigo);
							Verde("\nEditado com Sucesso");
							system("clear");
						break;
						case Dados_Produtos:
							Criar_Modificar_Produtos(Arquivo_Texto, Codigo);
							Verde("\nEditado com Sucesso");
							system("clear");
						break;
						case Dados_Fornecedores:
							Criar_Modificar_Fornecedores(Arquivo_Texto, Codigo);
							Verde("\nEditado com Sucesso");
							system("clear");
						break;
						case Dados_Funcionarios:
							Criar_Modificar_Funcionarios(Arquivo_Texto, Codigo);
							Verde("\nEditado com Sucesso");
							system("clear");
						break;

					}
					
				}
				fscanf(Arquivo,"%[^\n]s",Temporario);
				getc(Arquivo);

				while(!feof(Arquivo)){
						//Vai ate o Final do Arquivo
					fscanf(Arquivo,"%[^\n]s",Temporario);
					if(feof(Arquivo)){
							//Sai caso esteja no fim do arquivo;
						break;
					}
					fprintf(Arquivo_Temporario,"%s\n",Temporario);
							//Printa no Arquivo Temporario
					getc(Arquivo);
							//Pula o \n
				}
				fclose(Arquivo_Temporario);
				fclose(Arquivo);
						//Fecha ambos os Arquivos
				remove(Url);
						//Remove o Arquivo Original
				rename("Arquivos/Temp",Url);
						//Renomeia o Arquivo
				if(Modificar==0){
					Verde("\nExcluído com Sucesso");
				}
			}
		}else{
			if(Registro == Dados_Codigo_Categoria ){
				printf("Querido senhor(a) infelizmente não poderemos estar apagar/modificar essa categoria, pois o codigo %d esta presente no cadastro de acomodacoes", Codigo);
			}else if(Registro == Dados_Hotel){
				printf("Querido senhor(a) infelizmente não poderemos estar apagar/modificar esse hotel, pois o codigo %d esta presente no cadastro de acomodacoes", Codigo);			
			}
		}
	}
}

int Confirmacao(){
	int Confirmacao;
		//Declaração variavel

	printf("\nDigite '1' para confirmar: ");
	scanf("%d%*c",&Confirmacao);
	//system("clear");
	if(Confirmacao ==1){
		return 1;
	}else{	
		return 0;
	}
	return 0;
}

int Intervalo_Vetor(int Vetor[],int Ultimo){
	int Intervalo=0;
		//variavel que mostrará onde esta o intervalo 

	for (int i = 0; i < Ultimo; i++)																			
	{	//for que vai de 0 ate o ultimo numero do vetor
		
		if(Vetor[i+1]!=(Vetor[i]+1)){
			//Verifica se tem um intervalo entre o primeiro e a ultima posicao do vetor

			Intervalo=i;
			//Variavel intervalo recebe posicao do vetor que tem intervalo)
			
			return Intervalo;
			//Retorna o intervalo
		}
	}
	
	return -1;
	//Retorna -1 se nao tiver nenhum intervalo

}

int Modo_Manipulacao(){
	int Modo_de_Abertura;
		//Variavel usada para validar o switch

	system("clear");
		//limpa a tela 

	do{
		printf("\nDigite o modo de manipulação dos arquivos\n" );
		printf("\n1-Arquivo Texto"
			"\n2-Arquivo Binario"
			"\n3-Banco de Dados"
			"\n4-Nuvem"
			"\n");
			//Legenda

		scanf("%d",&Modo_de_Abertura);

		system("clear");
			//Limpa a tela

		//OBS Olhar Enum no arquivo de cabeçalho Registro.h

		switch(Modo_de_Abertura){
			case Arquivo_Texto:
			return Arquivo_Texto;

			case Arquivo_Binario:
			return Arquivo_Binario;

			case Banco_De_Dados:
			Vermelho("Banco de Dados não foi implentado\n");
			break;
			case Nuvem:
			Vermelho("Nuvem não foi implementado\n");
			break;
			default:
			Vermelho("Digite um codigo valido!\n");
			break;
		}

	}while(Modo_de_Abertura>=1 || Modo_de_Abertura<=4);
		//Validando o numero digitado

	system("clear");
			//Limpa a tela
}


void Quick_Sort(int vetor[], int inicio, int fim){
   //Algoritmo Auxiliar para a Ordenação de um Roll;
	int pivo, aux, i, j, meio;

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


int Retorna_Linha_Codigo(char Url[99], int Codigo){
	//Funcao para procurar com base no codigo digitado pelo usuario
	FILE *Arquivo;
	//Ponteiro do tipo File
	char Temporario[9999];
	Arquivo = fopen(Url,"r");
	//Abre o arquivo em modo de leitura
	int Validador = -1, Contador = 1;
	
	//Armazena o codigo lido no arquivo TXT
	do{
		fscanf(Arquivo,"%d",&Validador);
		if(feof(Arquivo)){
			return -1;
			//Deu ruim
			break;
		}
		if(Validador == Codigo){
			//Verifica se o codigo é igual ao lido
			return Contador;
			//Retorna a linha que tem o codigo
			break;
			//Confirma se saiu do loop
		}
		Contador++;
		fscanf(Arquivo,"%[^\n]s",Temporario);
		//Le o arquivo ate a quebra de linha
		getc(Arquivo);
		//Pula a quebra de linha

	}while(!feof(Arquivo));
	//Le ate o fim do arquivo
	fclose(Arquivo);
	//Fecha o arquvio
	return -1;
	//Não encontrou o codigo
}


int Valida_Codigo(char Url[99],int Numero_De_Registros,int Modo_de_Abertura, int Tipo_DADO){
	char Temporario[9999];
	int Vetor_Codigos[9999],Codigo;
	DADOS_HOTEL Tipo_Hotel;
	DADOS_HOSPEDE Tipo_Hospedes;
	ACOMODACOES Tipo_Acomodacoes;
	CODIGO_CATEGORIA Tipo_Codigo_Categoria;
	PRODUTOS Tipo_Produtos;
	FORNECEDORES Tipo_Fornecedores;
	FUNCIONARIOS Tipo_Funcionarios;
	RESERVA Tipo_Reserva;
	//Declaraçao de variaveis
	FILE *Arquivo;
		//Ponteiro para o arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen(Url,"r");
		break;
		case Arquivo_Binario:
		Arquivo=fopen(Url,"rb");
		break;
		//Abre o Arquivo
	}

	int Contador1=0;
	
		//Evita lixo de memoria
	if (Modo_de_Abertura == Arquivo_Texto)
	{
		
		while(!feof(Arquivo)){


			fscanf(Arquivo,"%d",&Vetor_Codigos[Contador1]);
				//Lê o Codigo
			getc(Arquivo);
				//lê/pula ';'
			if(feof(Arquivo)){
				//Verifica se chegou a ao fim do arquivo
				
				break;


				//sai do while
			}
			fscanf(Arquivo,"%[^\n]s",Temporario);
			getc(Arquivo);
			//Move o ponteiro até o proximo codigo
			Contador1++;
			//Adicione 1 ao contador ou seja adicione um ao numero do indice
			
		}
		

		Quick_Sort(Vetor_Codigos,0,Contador1);
		//Ordena o Vetor;

		int Auxiliar = Intervalo_Vetor(Vetor_Codigos,Contador1);
		//Variavel Auxiliar recebe retorno da Funcao intervalor 
		
		if (Auxiliar != -1)
			//Se diferente de -1
		{
			
			Codigo = (Vetor_Codigos[Auxiliar])+1;
			//Codigo recebe o valor do Vetor Codigos na posicao Auxiliar somado 1

		}else{
			Codigo = Vetor_Codigos[Contador1]+1;
			//Se Nao Codigo recebe vetor na ultima posicao somado 1
			
		}
	}else if (Modo_de_Abertura == Arquivo_Binario)
	{
		Contador1=0;
		
		//Zera contador de Codigos
		while(!feof(Arquivo)){

			switch (Tipo_DADO){
				case Dados_Hotel:
					fread(&Tipo_Hotel, sizeof(DADOS_HOTEL),1,Arquivo);
				break;
				case Dados_Hospede:
					fread(&Tipo_Hospedes, sizeof(DADOS_HOSPEDE),1,Arquivo);
				break;
				case Dados_Acomodacoes:
					fread(&Tipo_Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
				break;
				case Dados_Codigo_Categoria:
					fread(&Tipo_Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo);
				break;
				case Dados_Produtos:
					fread(&Tipo_Produtos, sizeof(PRODUTOS),1,Arquivo);
				break;
				case Dados_Fornecedores:
					fread(&Tipo_Fornecedores, sizeof(FORNECEDORES),1,Arquivo);
				break;
				case Dados_Funcionarios:
					fread(&Tipo_Funcionarios, sizeof(FUNCIONARIOS),1,Arquivo);
				break;
				case Dados_Reserva:
					fread(&Tipo_Reserva, sizeof(RESERVA),1,Arquivo);
				break;	

			}
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}
			switch (Tipo_DADO){
				case Dados_Hotel:
					Vetor_Codigos[Contador1] = Tipo_Hotel.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Hospede:
					Vetor_Codigos[Contador1] = Tipo_Hospedes.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Acomodacoes:
					Vetor_Codigos[Contador1] = Tipo_Acomodacoes.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Codigo_Categoria:
					Vetor_Codigos[Contador1] = Tipo_Codigo_Categoria.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Produtos:
					Vetor_Codigos[Contador1] = Tipo_Produtos.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Fornecedores:
				Vetor_Codigos[Contador1] = Tipo_Fornecedores.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Funcionarios:
					Vetor_Codigos[Contador1] = Tipo_Funcionarios.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Reserva:
				Vetor_Codigos[Contador1] = Tipo_Reserva.Codigo;
			//Atribui o codigo no  vetor de codigos
			break;
			}
			
			Contador1++;
			//Soma no contador de contador
		}

		Quick_Sort(Vetor_Codigos,0,Contador1);
			//Ordenamento do Vetor;

		int Auxiliar = Intervalo_Vetor(Vetor_Codigos,Contador1);
		//Variavel Auxiliar recebe retorno da Funcao intervalor 

		if (Auxiliar != -1)
			//Se diferente de -1
		{
			Codigo = (Vetor_Codigos[Auxiliar])+1;
			//Codigo recebe o valor do Vetor Codigos na posicao Auxiliar somado 1

		}else{
			Codigo = Vetor_Codigos[Contador1]+1;
			//Se Nao Codigo recebe vetor na ultima posicao somado 1
			
		}	

	}



}

void Verificacao_Arquivo(char Url[999],int Modo_de_Abertura){
	FILE *Arquivo;
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen(Url,"r");
			//Abre o Arquivo em Modo Leitura

		if(Arquivo==NULL){
			//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Arquivo=fopen(Url,"w");
			//Abre no modo escrita e caso não exista ele vai criar o arquivo
		}
		break;
		case Arquivo_Binario:
		
		Arquivo=fopen(Url,"rb");
			//Abre o Arquivo em Modo Leitura
		
		if(Arquivo==NULL){
		//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Arquivo=fopen(Url,"wb");
			//Abre no modo escrita e caso não exista ele vai criar o arquivo
			
		}
		break;
	}
	
	fclose(Arquivo);
		//Fecha o Arquivo
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


MODO Modo_Bin_ou_Txt(int Modo_de_Abertura){
	MODO Modo;
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		strcpy(Modo.Leitura,"r");
			//Modo leitura Txt
		strcpy(Modo.Escrita,"w");
			//Modo escrita Txt
		strcpy(Modo.Concatenacao,"a");
			//Modo concatenação Txt
		Modo.Modo_de_Abertura = Arquivo_Texto;
			//Modo de Abertura
		break;
		
		case Arquivo_Binario:
		strcpy(Modo.Leitura,"rb");
			//Modo leitura Bin
		strcpy(Modo.Escrita,"wb");
			//Modo escrita Bin
		strcpy(Modo.Concatenacao,"ab");
			//Modo concatenação Bin
		Modo.Modo_de_Abertura = Arquivo_Binario;
		break;
	}
	return Modo;
	//Retorna a Struct
}
int Converter_Decimal_Binario(int n0,int n1,int n2,int n3){
	n0=n0*pow(2,0);
	n1=n1*pow(2,1);
	n2=n2*pow(2,2);
	n3=n3*pow(2,3);
	int Binario = n0+n1+n2+n3;
	return Binario;
}

int MenuInicialFeedback(){
	int Tipo_Listagem = 0;
	do{
		printf("Digite 1 para listagem na tela ou 2 para gerar csv");
		scanf("%d",&Tipo_Listagem);
		if(Tipo_Listagem > 2 || Tipo_Listagem < 1){
			Vermelho("Digite um valor válido");
		}
	}while(Tipo_Listagem > 2 || Tipo_Listagem < 1);
	return Tipo_Listagem;
}
int MenuListagemFeedback(){
	int Tipo_Listagem = 0;
	do{
		Verde("Escolha qual dado deseja listar\n");
		printf("1 - Hospedes\n"
		"2 - Acomodações\n"
		"3 - Reservas\n"
		"4 - Produtos\n");
		
		scanf("%d",&Tipo_Listagem);
		if(Tipo_Listagem > 4 || Tipo_Listagem < 1){
			Vermelho("Digite um valor válido");
		}
	}while(Tipo_Listagem > 4 || Tipo_Listagem < 1);
	return Tipo_Listagem;
}

int Ler_Configuracoes_Retorna_Modo_de_Abertura(){
	FILE *Arquivo;
	int Modo_Abertura = 0;
	//cria as variaveis para o bom funcionamento da função 

	Arquivo = fopen("Arquivos/Configuracoes.txt", "r");
	//Abre o Arquivo para ver o modo de manipulaçao que está salvo
	
	fscanf(Arquivo,"%d",&Modo_Abertura);
	//Le do Arquivo

	fclose(Arquivo);
	//Fecha para evitar erros

	return Modo_Abertura;
}


int Valida_Codigo_Produto(int Codigo, int Modo_de_Abertura){
	FILE *Arquivo;
	char Temporario[9999];
		//Ponteiro para Arquivo

	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Produtos.txt","r");

			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Produtos\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Produtos.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Produtos\n");
			return 0;		
		}
		break;
	}		

	int Contador1=0, Vetor_Codigos[9999];
		//Evita lixo de memoria
	if (Modo_de_Abertura == Arquivo_Texto)
	{
		while(!feof(Arquivo)){

			fscanf(Arquivo,"%d",&Vetor_Codigos[Contador1]);
				//Lê o Codigo
			getc(Arquivo);
				//lê/pula ';'
			if(feof(Arquivo)){
				//Verifica se chegou a ao fim do arquivo
				break;
				//sai do while
			}
			fscanf(Arquivo,"%[^\n]s",Temporario);
			getc(Arquivo);
			//Move o ponteiro até o proximo codigo
			Contador1++;
			//Adicione 1 ao contador ou seja adicione um ao numero do indice
			
		}

	}else if (Modo_de_Abertura == Arquivo_Binario)
	{
		PRODUTOS Produtos;
		Contador1=0;
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Produtos, sizeof(PRODUTOS),1,Arquivo);
			//Le arquivo e passac para a struct
			Vetor_Codigos[Contador1] = Produtos.Codigo;
			Contador1++;
			//Soma no contador de contador
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}

			
		}
	}
	if(Contador1!=1){
		Quick_Sort(Vetor_Codigos,0,Contador1-1);
		//COntador -1 para poder ler o vetor inteiro e não perder ultimo valor 
		//Ordena o Vetor;
	}	
		for (int i = 0; i < Contador1; ++i)
		{

			if (Codigo == Vetor_Codigos[i])
			{
				return 1;//Se achar o codigo no vetor ordenado retorna 1 indicando TRUE
			}
		}
return 0;//Caso contrario retorna FALSE 0 
}

#endif
