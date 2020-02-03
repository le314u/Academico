#ifndef _Pesquisa_
#define _Pesquisa_
/*
PESQUISA Tipo_Pesquisa();
void Pesquisa(PESQUISA Pesquisa);
int Retorna_Acomodacao_Disponiveis_Por_Periodo(int Acomodacao_Disponiveis[],PESQUISA Pesquisa_Entrada,PESQUISA Pesquisa_Saida);
void Pequisa_Quantidade(int Acomodacao_Invalida[],int Inicio_Vetor,int Quantidade);
void Pequisa_Facilidades(int Acomodacao_Invalida[],int Inicio_Vetor);
void Pequisa_Categoria_Acomodacao(int Acomodacao_Invalida[],int Inicio_Vetor);
int Valida_Codigo_Acomodacao(int Codigo, int Modo_de_Abertura);
void Recebe_Data(DATA *Data);
int Pequisa_Periodo(int Acomodacao_Invalida[],int Inicio_Vetor,DATA Entrada,DATA Saida);
void Verifica_Fluxo(char Url[999], DATA Data_Entrada,DATA Data_Saida, int Acomodacao_Indisponiveis[]);
int Todas_Acomodacoes_TXT(char Url[99], int Acomodacoes_Disponiveis[],int Acomodacoes_Indisponiveis[], int Contador_Acomodacao_Indisponiveis);
void Mostra_Acomodacoes_BIN(int Contador_Acomodacoes, int Codigos[], char Url[]);
int Todas_Acomodacoes_BIN(char Url[99], int Acomodacoes_Disponiveis[],int Acomodacoes_Indisponiveis[], int Contador_Acomodacao_Indisponiveis);
*/
int Todas_Acomodacoes_TXT(char Url[99], int Acomodacoes_Disponiveis[],int Acomodacoes_Indisponiveis[], int Contador_Acomodacao_Indisponiveis){
	ACOMODACOES Acomodacoes;
		//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
		//Ponteiro para o arquivo
	
	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	int Contador=0;
	char Temporario[999];

	
	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
		do{

			fscanf(Arquivo,"%d",&Acomodacoes.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Acomodacoes_Disponiveis[Contador] = Acomodacoes.Codigo;
			Contador++;
			fscanf(Arquivo,"%[^\n]s",Temporario);
			getc(Arquivo);			
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		
	}
	fclose(Arquivo);
		//Fecha o Arquivo;
	for(int i = 0; i < Contador; i++){
		for(int j = 0; j < Contador_Acomodacao_Indisponiveis; j++){
			if(Acomodacoes_Disponiveis[i] == Acomodacoes_Indisponiveis[j]){
				Acomodacoes_Disponiveis[i] = 0;
			}
		}
	}
	return Contador;
}


int Todas_Acomodacoes_BIN(char Url[99], int Acomodacoes_Disponiveis[],int Acomodacoes_Indisponiveis[], int Contador_Acomodacao_Indisponiveis){
	ACOMODACOES Acomodacoes;
		//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
		//Ponteiro para o arquivo
	
	Arquivo=fopen(Url,"rb");
		//Abre o Arquivo
	int Contador=0;
	char Temporario[999];

	
	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
		do{
			fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);			
			//le struct de acomodacoes salva no binario
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Acomodacoes_Disponiveis[Contador] = Acomodacoes.Codigo;
			Contador++;		
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		
	}
	fclose(Arquivo);
		//Fecha o Arquivo;
	for(int i = 0; i < Contador; i++){
		for(int j = 0; j < Contador_Acomodacao_Indisponiveis; j++){
			if(Acomodacoes_Disponiveis[i] == Acomodacoes_Indisponiveis[j]){
				Acomodacoes_Disponiveis[i] = 0;
			}
		}
	}
	return Contador;
}

void Main_Pesquisa(){
	int Indice_Disponiveis,Vetor_Cod_Acomodacao_Disponivel[Tamanho2];
	DATA Data;
	PESQUISA Pesquisar;
	Pesquisar = Tipo_Pesquisa();
	Data=Pesquisa(Pesquisar,&Indice_Disponiveis,Vetor_Cod_Acomodacao_Disponivel);
	
		
}
void Mostra_Acomodacoes_TXT(int Contador_Acomodacoes, int Codigos[], char Url[]){
	ACOMODACOES Acomodacoes;
	//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
	//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
	//Abre o Arquivo
	int Arquivo_Vazio=0;
	char Temporario[999];
	int Aux=0;

	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
			
		do{
			fscanf(Arquivo,"%d",&Acomodacoes.Codigo);
			Aux=-1;
			for(int i = 0; i < Contador_Acomodacoes; i++){
				if(Codigos[i] == 0){
					///SE FOR IGUAL A 0 Nao faz nada...
				}else if(Acomodacoes.Codigo == Codigos[i]){
					Aux=i;
					break;
				}
			}
			if(!(Aux == -1)){
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
				getc(Arquivo);
				if(Acomodacoes.Codigo = Codigos[Aux]){
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
					Verde("\nAcomodacao disponivel\n");
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Acomodacoes.Descricao);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Televisao);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Ar_Condicionado);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Frigobar);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Internet);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Banheira);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Cod_Categoria);
						//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%d",&Acomodacoes.Cod_Hotel);
					//Expreção Regular
					getc(Arquivo);
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caracte (pula o \n)
					Ler_Acomodacoes_Memoria(Acomodacoes);
					
					Arquivo_Vazio++;
				}
			}else{
				if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
				}
				fscanf(Arquivo,"%[^\n]s",Temporario);
				//Expreção Regular
				getc(Arquivo);
				Arquivo_Vazio++;
			}
		}while(!feof(Arquivo));
		//Entra no loop se não estiver apontando para o final do arquivo;
	if(Arquivo_Vazio==0){
		Vermelho("O Arquivo está vazio\n");
	}
}

fclose(Arquivo);
	//Fecha o Arquivo;
}

void Mostra_Acomodacoes_BIN(int Contador_Acomodacoes, int Codigos[], char Url[]){
	ACOMODACOES Acomodacoes;
	//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
	//Ponteiro para o arquivo

	Arquivo=fopen(Url,"rb");
	//Abre o Arquivo
	int Arquivo_Vazio=0;
	int Aux=0;

	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
			
		do{
			fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);		
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Aux=-1;
			for(int i = 0; i < Contador_Acomodacoes; i++){
				if(Codigos[i] == 0){
					///SE FOR IGUAL A 0 Nao faz nada...
				}else if(Acomodacoes.Codigo == Codigos[i]){
					Aux=i;
					break;
				}
			}
			if(!(Aux == -1)){
				if(Acomodacoes.Codigo = Codigos[Aux]){
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
					Verde("\nAcomodacao disponivel\n");
						//Pula o Ponteiro para o proximo caractere
					Ler_Acomodacoes_Memoria(Acomodacoes);
					
					Arquivo_Vazio++;
				}
			}else{
				Arquivo_Vazio++;
			}
		}while(!feof(Arquivo));
		//Entra no loop se não estiver apontando para o final do arquivo;
		if(Arquivo_Vazio==0){
			Vermelho("O Arquivo está vazio\n");
	}
}

fclose(Arquivo);
	//Fecha o Arquivo;
}

int Verifica_Fluxo(char Url[999], DATA Data_Entrada,DATA Data_Saida, int Acomodacao_Indisponiveis[]){
	FLUXO Fluxo;
	FILE *Arquivo;
	int Tamanho_Vetor = Data_Saida.Dia - Data_Entrada.Dia + 1;
	int Contador_Acomodacao_Indisponiveis = 0;
	int Periodo[Tamanho_Vetor];
	for(int i = 0; i < Tamanho_Vetor; i++){
		Periodo[i] = Data_Entrada.Dia + i;
	}
	Arquivo=fopen(Url,"rb");
	while(!feof(Arquivo)){
		fread(&Fluxo, sizeof(FLUXO),1,Arquivo);		
		if(feof(Arquivo)){
			//Verifica se esta no fim do arquivo
			break;
			//Sai do loop
		}
		int Tamanho_Vetor_Fluxo_Lido_Binario = Fluxo.Data_Saida.Dia - Fluxo.Data_Entrada.Dia + 1;
		for(int i = 0; i <Tamanho_Vetor; i++){
			for(int j = 0; j <Tamanho_Vetor_Fluxo_Lido_Binario; j++){
				if(Periodo[i] == Fluxo.Vetor_Dias[j]){
					Acomodacao_Indisponiveis[Contador_Acomodacao_Indisponiveis] = Fluxo.Codigo_Acomodacao;
					Contador_Acomodacao_Indisponiveis++;
					i = Tamanho_Vetor + 1;
					// i recebe o tamanho do vetor somado 1 para sair do for superior
					break;
					//sai do for atual
				}
			}
		}
		//Contador para verificar se o arquivo está em branco
	}
	fclose(Arquivo);
	return Contador_Acomodacao_Indisponiveis;
}
PESQUISA Tipo_Pesquisa(){
	//Retorna em binario o tipo de pesquisa dentro da struct
	PESQUISA Pesquisa;
	int  Data,Categoria_Acomodacao,Quantidade_Pessoas,Facilidade;
	Verde("Digite '1' no campo  pelo qual deseja pesquisar:\n");
	do{
		do{
			 printf("\nData");
			 scanf("%d",&Pesquisa.Data);
			if(Pesquisa.Data!=0 && Pesquisa.Data!=1){
				printf("Porfavor digite apenas ");
				Vermelho("0 para desativado ");
				printf("ou ");
				Verde("1 para ativado");
			}
		}while(Pesquisa.Data != 1 && Pesquisa.Data !=0);
		//valida aceitando apenas 1 ou 0

		do{
			 printf("Categoria de Acomodação:");
			 scanf("%d",&Pesquisa.Categoria_Acomodacao);
			if(Pesquisa.Categoria_Acomodacao!=0 && Pesquisa.Categoria_Acomodacao!=1){
				printf("Porfavor digite apenas ");
				Vermelho("0 para desativado ");
				printf("ou ");
				Verde("1 para ativado");
			}
		}while(Pesquisa.Categoria_Acomodacao != 1 && Pesquisa.Categoria_Acomodacao !=0);
		//valida aceitando apenas 1 ou 0

		do{
			 printf("Quantidade de Pessoas:");
			 scanf("%d",&Pesquisa.Quantidade_Pessoas);
			if(Pesquisa.Quantidade_Pessoas != 1 && Pesquisa.Quantidade_Pessoas !=0){
				printf("Porfavor digite apenas ");
				Vermelho("0 para desativado ");
				printf("ou ");
				Verde("1 para ativado");
			}
		}while(Pesquisa.Quantidade_Pessoas != 1 && Pesquisa.Quantidade_Pessoas !=0);
		//valida aceitando apenas 1 ou 0

		do{
			 printf("Facilidades:");
			 scanf("%d",&Pesquisa.Facilidade);
			if(Pesquisa.Facilidade != 1 && Pesquisa.Facilidade !=0){
				printf("Porfavor digite apenas ");
				Vermelho("0 para desativado ");
				printf("ou ");
				Verde("1 para ativado");
			}
		}while(Pesquisa.Facilidade != 1 && Pesquisa.Facilidade !=0);
		//valida aceitando apenas 1 ou 0
		printf("\n");

	}while(Pesquisa.Data+Pesquisa.Categoria_Acomodacao+Pesquisa.Quantidade_Pessoas+Pesquisa.Facilidade==0);
	//Se for tudo 0


	return Pesquisa;
}

int Retorna_Acomodacoes_Indisponiveis_Com_Codigo_Categoria(int Codigo_Categoria, int Modo_Abertura, int Acomodacao_Indisponiveis[], int Contador_Acomodacao_Indisponiveis){
	//Funcao para retornar todas as acomodacoes que possuem o codigo digitado pelo usuario
	FILE *Arquivo;
	//Ponteiro para o arquivo
	//Contador acomodacoes indisponiveiss
	ACOMODACOES Acomodacoes;
	//Cria uma variavel do tipo AcomodacaoL;
	if(Modo_Abertura == Arquivo_Texto){
		char Temporario[Tamanho2];
		//Temporario para pular dados nao correspondentes ao codigo

		Arquivo=fopen("Arquivos/Acomodacoes.txt","r");
			//Abre o Arquivo
		int Arquivo_Vazio=0;

	
		if(Arquivo==NULL){
			Vermelho("O Arquivo não foi aberto corretamente\n");
		}else{
			
			do{
				fscanf(Arquivo,"%d",&Acomodacoes.Codigo);
				getc(Arquivo);
				for(int i = 0; i < 6; i++){
					fscanf(Arquivo,"%[^;]s",Temporario);
					getc(Arquivo);
				}
				fscanf(Arquivo,"%d",&Acomodacoes.Cod_Categoria);
				getc(Arquivo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
					//Expreção Regular
				if(Acomodacoes.Cod_Categoria == Codigo_Categoria){
					fscanf(Arquivo,"%[^\n]s",Temporario);
					getc(Arquivo);
				}else{
					Acomodacao_Indisponiveis[Contador_Acomodacao_Indisponiveis] = Acomodacoes.Codigo;
					//Adiciona o codigo nao correspondente ao vetor
					Contador_Acomodacao_Indisponiveis++;
					fscanf(Arquivo,"%[^\n]s",Temporario);
					getc(Arquivo);
					//Expressao para pular o resto dos dados ate o fim do arquivo
				}
				
					
				if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
				}
					//Pula o Ponteiro para o proximo caractere
				
			}while(!feof(Arquivo));//Entra no loop se não estiver apontando para o final do arquivo;
			fclose(Arquivo);
			
		}		
	}else if(Modo_Abertura == Arquivo_Binario){
		
		Arquivo = fopen("Arquivos/Acomodacoes.bin","rb");
		int Arquivo_Vazio=0;
		if(Arquivo == NULL){
			Vermelho("\nNao foi possivel abrir o arquivo!");
		}else{
			while(!feof(Arquivo)){
				fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
				if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
				}
				if(Acomodacoes.Cod_Categoria != Codigo_Categoria){
					Acomodacao_Indisponiveis[Contador_Acomodacao_Indisponiveis] = Acomodacoes.Codigo;
					//Adiciona o codigo nao correspondente ao vetor
					Contador_Acomodacao_Indisponiveis++;
				}
				//Contador para verificar se o arquivo está em branco
			}
			fclose(Arquivo);
		}
	}
	return Contador_Acomodacao_Indisponiveis;
}
int Retorna_Acomodacoes_Indisponiveis_Com_Quantidade_Pessoas(int Adultos, int Criancas,int Codigo_Acomodacao_Invalidas[], int Indice_Invalido){
	FILE *Arquivo;
	CODIGO_CATEGORIA Codigo_Categoria;
	ACOMODACOES Acomodacoes;
	char Temporario[Tamanho2];
	int Codigo_Categoria_OK[Tamanho2],Indice_Codigo_Categoria=0;
	int Modo_Abertura=Configuracoes();
	int Auxiliar = 0;
	if(Modo_Abertura == Arquivo_Binario){
		Arquivo = fopen("Arquivos/Codigo_Categoria.bin","rb");
	}else if(Modo_Abertura == Arquivo_Texto){
		Arquivo = fopen("Arquivos/Codigo_Categoria.txt","r");
	}//Abre o arquivo

	while(!feof(Arquivo)){
		if(Modo_Abertura == Arquivo_Binario){
			fread(&Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo);	
		}
		else if(Modo_Abertura == Arquivo_Texto){
			fscanf(Arquivo,"%d",&Codigo_Categoria.Codigo);
			for(int i=0 ; i < 3;i++){
				fscanf(Arquivo,"%[^;]s",Temporario);
				getc(Arquivo);
			}
			fscanf(Arquivo,"%d",&Codigo_Categoria.Capacidade_Adulto);
			fscanf(Arquivo,"%d",&Codigo_Categoria.Capacidade_Crianca);
			fscanf(Arquivo,"%[^\n]s",Temporario);
			getc(Arquivo);
		}
		if(feof(Arquivo)){
			break;
		}
		if(Codigo_Categoria.Capacidade_Adulto >= Adultos){
			if(Codigo_Categoria.Capacidade_Crianca >= Criancas){
				Codigo_Categoria_OK[Indice_Codigo_Categoria] = Codigo_Categoria.Codigo;	
				Indice_Codigo_Categoria++;
			}
		}
	}//Preencher vetor com Codigo de acomodaçoes que se enquadrao na quantidade de pessoas 

	fclose(Arquivo);
	//Fecha o arquivo

	if(Modo_Abertura == Arquivo_Binario){
		Arquivo = fopen("Arquivos/Acomodacoes.bin","rb");
	}else if(Modo_Abertura == Arquivo_Texto){
		Arquivo = fopen("Arquivos/Acomodacoes.txt","r");
	}//Abre o arquivo

	while(!feof(Arquivo)){
		if(Modo_Abertura == Arquivo_Binario){
			fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);	
		}
		else if(Modo_Abertura == Arquivo_Texto){
			fscanf(Arquivo,"%d",&Acomodacoes.Codigo);
			getc(Arquivo);
			for(int i = 0 ; i < 6;	i++){
				fscanf(Arquivo,"%[^;]s",Temporario);
				getc(Arquivo);
			}
			fscanf(Arquivo,"%d",&Acomodacoes.Cod_Categoria);
			getc(Arquivo);
			fscanf(Arquivo,"%[^\n]s",Temporario);
			getc(Arquivo);
		}
		if(feof(Arquivo)){
			break;
		}
		for(int i=0 ; i <= Indice_Codigo_Categoria; i++){
			if(Acomodacoes.Cod_Categoria == Codigo_Categoria_OK[i]){
				Auxiliar++;
			}
		}
		if(Auxiliar == 0){
			Codigo_Acomodacao_Invalidas[Indice_Invalido] = Acomodacoes.Codigo;
			Indice_Invalido++;
		}
	}//Preencher vetor com Codigo de acomodaçoes que se enquadrao na quantidade de pessoas 

	fclose(Arquivo);
	//Fecha o arquivo
	return Indice_Invalido;
}

int Retorna_Acomodacoes_Indisponiveis_Com_Facilidades(FACILIDADES Facilidade,int Codigo_Acomodacao_Invalidas[], int Indice_Invalido){
	FILE *Arquivo;
	ACOMODACOES Acomodacoes;
	char Temporario[Tamanho2];
	int Codigo_Acomodacao_OK[Tamanho2],Indice_Codigo_Acomodacao=0;
	int Modo_Abertura=Configuracoes();
	int Auxiliar = 0;
	//Declara variaveis necessarias
	if(Modo_Abertura == Arquivo_Binario){
		Arquivo = fopen("Arquivos/Acomodacoes.bin","rb");
	}else if(Modo_Abertura == Arquivo_Texto){
		Arquivo = fopen("Arquivos/Acomodacoes.txt","r");
	}//Abre o arquivo

	while(!feof(Arquivo)){
		if(Modo_Abertura == Arquivo_Binario){
			fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);	
		}
		else if(Modo_Abertura == Arquivo_Texto){
			fscanf(Arquivo,"%d",&Acomodacoes.Codigo);
			getc(Arquivo);
			fscanf(Arquivo,"%[^;]s",Temporario);
			getc(Arquivo);
			//PULA CAMPO DE DESCRICAO POIS NAO INTERESSA
			fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Televisao);
			getc(Arquivo);
			fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Ar_Condicionado);
			getc(Arquivo);
			fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Frigobar);
			getc(Arquivo);
			fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Internet);
			getc(Arquivo);
			fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Banheira);
			getc(Arquivo);
			fscanf(Arquivo,"%[^\n]s",Temporario);
			getc(Arquivo);
		}
		if(feof(Arquivo)){
			break;
		}

		/*
		BLOCO DE IF para verifica se o usuario quer a Facilidade = 1 e se o lido do arquivo nao possui
			Ou se o usuario nao quer a facilidade = 0 e o lido do arquivo possui tal facilidade
		*/
		if((Facilidade.Televisao == 0 && Acomodacoes.Facilidades.Televisao >= 1) || (Facilidade.Televisao == 1 && Acomodacoes.Facilidades.Televisao == 0)){
			Codigo_Acomodacao_Invalidas[Indice_Invalido] = Acomodacoes.Codigo;
			Indice_Invalido++;
		}else if((Facilidade.Ar_Condicionado == 0 && Acomodacoes.Facilidades.Ar_Condicionado >= 1) || (Facilidade.Ar_Condicionado == 1 && Acomodacoes.Facilidades.Ar_Condicionado == 0)){
			Codigo_Acomodacao_Invalidas[Indice_Invalido] = Acomodacoes.Codigo;
			Indice_Invalido++;
		}else if((Facilidade.Frigobar == 0 && Acomodacoes.Facilidades.Frigobar >= 1) || (Facilidade.Frigobar == 1 && Acomodacoes.Facilidades.Frigobar == 0)){
			Codigo_Acomodacao_Invalidas[Indice_Invalido] = Acomodacoes.Codigo;
			Indice_Invalido++;
		}else if((Facilidade.Internet == 0 && Acomodacoes.Facilidades.Internet >= 1) || (Facilidade.Internet == 1 && Acomodacoes.Facilidades.Internet == 0)){
			Codigo_Acomodacao_Invalidas[Indice_Invalido] = Acomodacoes.Codigo;
			Indice_Invalido++;
		}else if((Facilidade.Banheira == 0 && Acomodacoes.Facilidades.Banheira >= 1) || (Facilidade.Banheira == 1 && Acomodacoes.Facilidades.Banheira == 0)){
			Codigo_Acomodacao_Invalidas[Indice_Invalido] = Acomodacoes.Codigo;
			Indice_Invalido++;
		}
	}//Preencher vetor com Codigo de acomodaçoes que se enquadrao na quantidade de pessoas 
	fclose(Arquivo);
	//Fecha o arquivo
	return Indice_Invalido;
	//Retorna indice de facilidades invalidas
}


DATA Pesquisa(PESQUISA Pesquisa,int *Indice_Disponiveis,int Vetor_Cod_Acomodacao_Disponivel[]){
	int Modo_Abertura=Configuracoes();
	int Ok=0;
	int Contador=0;
	int Vetor_Acomodacoes_Invalidas[Tamanho2];
	int Tamanho_Acomodacoes_disponiveis = 0;
	int Acomodacao_Disponiveis[999], Acomodacao_Indisponiveis[9999];
	char Arquivo_Fluxo[999];
	int Contador_Acomodacao_Indisponiveis = 0;
	int Acomodacao_Existentes[999]={0};
	DATA Data;
	//Variaveis

	if(Pesquisa.Data==1){
		do{
			Verde("\nDigite a data referente a Entrada");
			Recebe_Data(&Pesquisa.Data_Entrada,1);
			Verde("\nDigite a data referente a Saida");
			Pesquisa.Data_Saida.Ano = Pesquisa.Data_Entrada.Ano;
			Pesquisa.Data_Saida.Mes = Pesquisa.Data_Entrada.Mes;		
			Recebe_Data(&Pesquisa.Data_Saida,2);
			Data.Dia = Pesquisa.Data_Entrada.Dia;
			Data.Mes = Pesquisa.Data_Entrada.Mes;
			Data.Ano = Pesquisa.Data_Entrada.Ano;
			Data.Dia_Saida = Pesquisa.Data_Saida.Dia;
			if(Data.Dia_Saida < Pesquisa.Data_Entrada.Dia){
				Vermelho("O dia de entrada não pode ser anterior ao dia de saida");
			}
		}while(Data.Dia_Saida < Pesquisa.Data_Entrada.Dia);
		//Equanto a data de entrada for menor que a data de saida repete o loop
		//Recebe dados da Data
					
		sprintf(Arquivo_Fluxo,"Arquivos/Reserva/");
		Cria_Pasta(Arquivo_Fluxo);
		sprintf(Arquivo_Fluxo,"Arquivos/Reserva/%u",Pesquisa.Data_Entrada.Ano);
		Cria_Pasta(Arquivo_Fluxo);
		system("clear");
		//Cria pasta caso nao exista para evitar erro de caminho invalido
		sprintf(Arquivo_Fluxo,"Arquivos/Reserva/%u/%u",Pesquisa.Data_Entrada.Ano,Pesquisa.Data_Entrada.Mes);
		Verificacao_Arquivo(Arquivo_Fluxo,Arquivo_Binario);
		Contador_Acomodacao_Indisponiveis = Verifica_Fluxo(Arquivo_Fluxo, Pesquisa.Data_Entrada,Pesquisa.Data_Saida, Acomodacao_Indisponiveis);
		//quando chamo a função verifica fluxo eu retorno o contador e o vetor com os codigos das acomodações indisponiveis
	}//Pesquisa por data

	if(Pesquisa.Categoria_Acomodacao==1){
		Verde("Confira a lista com as categorias cadastradas \n");
		if(Modo_Abertura == Arquivo_Texto){
			Ler_Codigo_Categoria_Txt("Arquivos/Codigo_Categoria.txt");
		}else if(Modo_Abertura == Arquivo_Binario){
			Ler_Codigo_Categoria_Bin("Arquivos/Codigo_Categoria.bin");
		}
		do{
			printf("Digite o codigo da categoria da Acomodação");
			scanf("%d",&Pesquisa.Codigo_Categoria);
			Ok = Valida_Codigo_Acomodacao(Pesquisa.Codigo_Categoria,Modo_Abertura);
			if(Ok==0){
				Vermelho("O codigo não está cadastrado \n");
			}
		}while(Ok==0);
		//Validar acomodação;
		//Olhar no arquivo se está cadastrado
		Contador_Acomodacao_Indisponiveis += Retorna_Acomodacoes_Indisponiveis_Com_Codigo_Categoria(Pesquisa.Codigo_Categoria, Modo_Abertura, Acomodacao_Indisponiveis,Contador_Acomodacao_Indisponiveis);	
			
	}//Pesquisa por Categoria de Acomodação

	if(Pesquisa.Quantidade_Pessoas==1){
		do{
			printf("Digite a Quantidade de Adultos:");
			scanf("%d",&Pesquisa.Quantidade_Adultos);
			if(Pesquisa.Quantidade_Adultos <= 0){
				Vermelho("\nDigite um numero maior que zero\n");
			}
		}while(Pesquisa.Quantidade_Adultos<=0);
		//Valida para não colocar um numero negativo
		do{
			printf("Digite a Quantidade de Crianças ");
			scanf("%d",&Pesquisa.Quantidade_Criancas);
			if(Pesquisa.Quantidade_Criancas < 0){
				Vermelho("\nDigite um numero maior ou igual a zero\n");
			}
		}while(Pesquisa.Quantidade_Criancas<0);
		//Valida para não colocar um numero negativo
		Contador_Acomodacao_Indisponiveis += Retorna_Acomodacoes_Indisponiveis_Com_Quantidade_Pessoas(Pesquisa.Quantidade_Adultos, Pesquisa.Quantidade_Criancas,Acomodacao_Indisponiveis,Contador_Acomodacao_Indisponiveis);
		Contador_Acomodacao_Indisponiveis++;
	}//Pesquisa por Quantidade de crianças
	if(Pesquisa.Facilidade==1){
		do{
			printf("Digite 1 para acomodacao com Televisoes ou 0 para sem:");
			scanf("%d",&Pesquisa.Facilidades.Televisao);
			if(Pesquisa.Facilidades.Televisao<0){
				Vermelho("Digite apenas 1 para sim e 0 para nao");
			}
		}while(Pesquisa.Facilidades.Televisao < 0 || Pesquisa.Facilidades.Televisao > 1);
		
		do{
			printf("Digite 1 para acomodacao com Ar Condicionado ou 0 para sem:");
			scanf("%d",&Pesquisa.Facilidades.Ar_Condicionado);
			if(Pesquisa.Facilidades.Ar_Condicionado<0){
				Vermelho("Digite apenas 1 para sim e 0 para nao");
			}
			}while(Pesquisa.Facilidades.Televisao < 0 || Pesquisa.Facilidades.Televisao > 1);
		
		do{
			printf("Digite 1 para acomodacao com Frigobar ou 0 para sem:");
			scanf("%d",&Pesquisa.Facilidades.Frigobar);
			if(Pesquisa.Facilidades.Frigobar<0){
				Vermelho("Digite apenas 1 para sim e 0 para nao");
			}
			}while(Pesquisa.Facilidades.Televisao < 0 || Pesquisa.Facilidades.Televisao > 1);
		
		do{
			printf("Digite 1 para acomodacao com Internet ou 0 para sem: ");
			scanf("%d",&Pesquisa.Facilidades.Internet);
			if(Pesquisa.Facilidades.Internet<0){
				Vermelho("Digite apenas 1 para sim e 0 para nao");
			}
			}while(Pesquisa.Facilidades.Televisao < 0 || Pesquisa.Facilidades.Televisao > 1);
		
		do{
			printf("Digite 1 para acomodacao com Banheiras ou 0 para sem:");
			scanf("%d",&Pesquisa.Facilidades.Banheira);
			if(Pesquisa.Facilidades.Banheira<0){
				Vermelho("Digite apenas 1 para sim e 0 para nao");
			}
		}while(Pesquisa.Facilidades.Televisao < 0 || Pesquisa.Facilidades.Televisao > 1);
		Contador_Acomodacao_Indisponiveis += Retorna_Acomodacoes_Indisponiveis_Com_Facilidades(Pesquisa.Facilidades,Acomodacao_Indisponiveis,Contador_Acomodacao_Indisponiveis);
		//Ve qual Cod Categoria que tem a quantidade minima //Pegar da ultima função salva
	}
	//pega dados sobre as Facilidades(coisas que a acomodaçao possui)
	if(Modo_Abertura == Arquivo_Texto){
		Tamanho_Acomodacoes_disponiveis = Todas_Acomodacoes_TXT("Arquivos/Acomodacoes.txt",Acomodacao_Disponiveis,Acomodacao_Indisponiveis,Contador_Acomodacao_Indisponiveis);
		Verde("Acomodações Dispniveis\n");
	   	Mostra_Acomodacoes_TXT(Tamanho_Acomodacoes_disponiveis, Acomodacao_Disponiveis, "Arquivos/Acomodacoes.txt");
	}else if(Modo_Abertura == Arquivo_Binario){
		Tamanho_Acomodacoes_disponiveis = Todas_Acomodacoes_BIN("Arquivos/Acomodacoes.bin",Acomodacao_Disponiveis,Acomodacao_Indisponiveis,Contador_Acomodacao_Indisponiveis);
		Verde("Acomodações Dispniveis\n");
	   	Mostra_Acomodacoes_BIN(Tamanho_Acomodacoes_disponiveis, Acomodacao_Disponiveis, "Arquivos/Acomodacoes.bin");
	}
	Verde("\n Digite 1 e pressione ENTER para continuar");
	PAUSA;
	if(Vetor_Cod_Acomodacao_Disponivel != NULL && Indice_Disponiveis != NULL){
		*Indice_Disponiveis == Tamanho_Acomodacoes_disponiveis;
		for(int i = 0; i < Tamanho_Acomodacoes_disponiveis; i++){
			Vetor_Cod_Acomodacao_Disponivel[i] = Acomodacao_Disponiveis[i];
		}
	}
return Data;

}



void Pequisa_Quantidade(int Acomodacao_Invalida[],int Inicio_Vetor,int Quantidade){
	
	
	}
	
void Pequisa_Facilidades(int Acomodacao_Invalida[],int Inicio_Vetor){
	
	
	}
	
void Pequisa_Categoria_Acomodacao(int Acomodacao_Invalida[],int Inicio_Vetor){
	
	
	}


int Valida_Codigo_Acomodacao(int Codigo, int Modo_de_Abertura){
	//Procura nas acomodacoes pelo codigo da acomodacao
	FILE *Arquivo;
	char Temporario[9999];
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Codigo_Categoria.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Categoria cadastradas\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Codigo_Categoria.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Categoria cadastradas\n");
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
		CODIGO_CATEGORIA Codigo_Categoria;
		Contador1=0;
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo);
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}

			Vetor_Codigos[Contador1] = Codigo_Categoria.Codigo;
			Contador1++;
			//Soma no contador de contador
		}
	}
	if(Contador1!=1){
		Quick_Sort(Vetor_Codigos,0,Contador1);
		//Ordena o Vetor;
	}
	for (int i = 0; i <= Contador1; ++i){
		if (Codigo == Vetor_Codigos[i])
		{
			return 1;
		}
	}
	return 0;
}

void Recebe_Data(DATA *Data, int Auxiliar){
	if(Auxiliar == 1){
		do{
			printf("\nDigite o Ano ");
			scanf("%u",&Data->Ano);
			if(Data->Ano<2017){
				Vermelho("\nAno invalido");
			}
		}while(Data->Ano<2017);
		do{
			printf("\nDigite o numero referente ao Mes ");
			scanf("%u",&Data->Mes);
			if(Data->Mes<1 || Data->Mes>12){
				Vermelho("\nMes invalido");
			}
		}while(Data->Mes<1 || Data->Mes>12);
	
		switch (Data->Mes){
			
			case Janeiro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Fevereiro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>28 || Data->Dia<1);
			break;
	
	
			case Marco:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Abril:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>30 || Data->Dia<1);
			break;
	
	
			case Maio:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Junho:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>30 || Data->Dia<1);
			break;
	
	
			case Julho:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Agosto:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Setembro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>30 || Data->Dia<1);
			break;
	
	
			case Outubro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Novembro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>30 || Data->Dia<1);
			break;
	
			case Dezembro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
			//Valida dia do mes
		}
	}else{
		switch (Data->Mes){
			
			case Janeiro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Fevereiro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>28 || Data->Dia<1);
			break;
	
	
			case Marco:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Abril:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>30 || Data->Dia<1);
			break;
	
	
			case Maio:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Junho:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>30 || Data->Dia<1);
			break;
	
	
			case Julho:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Agosto:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Setembro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>30 || Data->Dia<1);
			break;
	
	
			case Outubro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
	
	
			case Novembro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>30 || Data->Dia<1);
			break;
	
			case Dezembro:
				do{
					printf("\nDigite o Dia ");
					scanf("%u",&Data->Dia);
				}while(Data->Dia>31 || Data->Dia<1);
			break;
			//Valida dia do mes
		}
	}
	
		
}



#endif