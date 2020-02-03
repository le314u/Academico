#ifndef _Codigo_Categoria_ 
	//Se não estiver definido entra no if
#define _Codigo_Categoria_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

	//Inclui arquivos de cabeçalho
/*
void Ler_Codigo_Categoria_Txt(char Url[99]);
void Ler_Codigo_Categoria_Bin();
void Ler_Codigo_Categoria_Memoria(CODIGO_CATEGORIA Codigo_Categoria);
void Gravar_Codigo_Categoria_Txt(char Url[99],CODIGO_CATEGORIA *Codigo_Categoria);
void Gravar_Codigo_Categoria_Bin(char Url[99],CODIGO_CATEGORIA *Codigo_Categoria);
void Criar_Modificar_Codigo_Categoria(int Modo_de_Abertura,int Manter_Codigo);
int Retorna_Campo_Struct_Codigo_Categoria(char Url[99], int Codigo);
void Apagar_Modificar_Codigo_Categoria_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
int Valida_Acomadacao_Codigo_Categoria(int Codigo, int Modo_de_Abertura);
*/
void Main_Codigo_Categoria(MODO Modo){
	CODIGO_CATEGORIA Codigo_Categoria;
	int Acao,Codigo=0;

	Verificacao_Arquivo("Arquivos/Codigo_Categoria.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Codigo_Categoria.txt",Arquivo_Texto);
	
	while(1){
		OrdenaValoresTxt();
		Acao = Opcao_Acoes();
		//Retorna um inteiro referente a Ação (Case)
		//limpa a tela

		switch (Acao){

			case Ler:
				if(Modo.Nivel_De_Permissao>=8 && Modo.Nivel_De_Permissao <=15){

					if (Modo.Modo_de_Abertura == Arquivo_Binario)
					{
						Ler_Codigo_Categoria_Bin("Arquivos/Codigo_Categoria.bin");
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						Ler_Codigo_Categoria_Txt("Arquivos/Codigo_Categoria.txt");
					}
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}

				break;
			case Criar:
				if ((Modo.Nivel_De_Permissao >=4 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=12 && Modo.Nivel_De_Permissao <=15)){
						Criar_Modificar_Codigo_Categoria(Modo.Modo_de_Abertura,0);	
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;	
			
			case Editar:
				if ((Modo.Nivel_De_Permissao >=2 && Modo.Nivel_De_Permissao <=3)||(Modo.Nivel_De_Permissao >=6 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=10 && Modo.Nivel_De_Permissao <=11)||(Modo.Nivel_De_Permissao >=14 && Modo.Nivel_De_Permissao <=15)){

					if(Modo.Modo_de_Abertura == Arquivo_Binario){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar_Codigo_Categoria_Bin("Arquivos/Codigo_Categoria.bin",Codigo,1,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Codigo_Categoria.txt",Codigo,1,Modo,Dados_Codigo_Categoria);
					}
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
			break;

			case Apagar:
				if ((Modo.Nivel_De_Permissao%2)){//Se for impar retorna 1 e somente numeros impares tem a permissao de Apagar

					if(Modo.Modo_de_Abertura == Arquivo_Binario){
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar_Codigo_Categoria_Bin("Arquivos/Codigo_Categoria.bin",Codigo,0,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Codigo_Categoria.txt",Codigo,0,Modo,Dados_Codigo_Categoria);
					}
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
			break;

			default:
				return;
			break;

		}
	}
}
int Valida_Acomadacao_Codigo_Categoria(int Codigo, int Modo_de_Abertura){
	//Procura nas acomodacoes pelo codigo da categoria para que assim nao apague os que sao vinculados
	FILE *Arquivo;
	char Temporario[9999];
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Acomodacoes.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Acomodacoes cadastradas\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Acomodacoes.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Acomodacoes cadastradas\n");
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
		ACOMODACOES Tipo_Acomodacoes;
		ACOMODACOES Acomodacoes;
		Contador1=0;
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}

			Vetor_Codigos[Contador1] = Acomodacoes.Cod_Categoria;
			Contador1++;
			//Soma no contador de contador
		}
	}
	if(Contador1!=1){
		Quick_Sort(Vetor_Codigos,0,Contador1);
		//Ordena o Vetor;
	}
		for (int i = 0; i < Contador1; ++i)
		{
			if (Codigo == Vetor_Codigos[i])
			{
				return 1;
			}
		}
	return 0;
}
void Ler_Codigo_Categoria_Txt(char Url[99]){
	CODIGO_CATEGORIA Codigo_Categoria;
		//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
		//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	int Arquivo_Vazio=0;

	
	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
		do{

			fscanf(Arquivo,"%d",&Codigo_Categoria.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}

			fscanf(Arquivo,"%[^;]s",Codigo_Categoria.Descricao);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%f",&Codigo_Categoria.Valor_Diaria);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%d",&Codigo_Categoria.Capacidade_Adulto);
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%d",&Codigo_Categoria.Capacidade_Crianca);
				//Expreção Regular
			getc(Arquivo);
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caracte (pula o \n)
			Ler_Codigo_Categoria_Memoria(Codigo_Categoria);
			
			Arquivo_Vazio++;
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		if(Arquivo_Vazio==0){
			Vermelho("O Arquivo está vazio\n");
		}
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
}

void Ler_Codigo_Categoria_Memoria(CODIGO_CATEGORIA Codigo_Categoria){
	//Recebe por parametro Struct de Codigo_Categoria
	printf("Codigo:\t\t\t%d\n",Codigo_Categoria.Codigo);
	printf("Descricão:\t\t%s\n",Codigo_Categoria.Descricao);
	printf("Valor Diaria:\t\tR$%.2f\n",Codigo_Categoria.Valor_Diaria);
	printf("Capacidade de Adultos:\t%d\n",Codigo_Categoria.Capacidade_Adulto);
	printf("Capacidade de Crianças:\t%d\n",Codigo_Categoria.Capacidade_Crianca);
	printf("____________________________________________________\n");
	//Mostra dados do Codigo_Categoria cadastrado na memoria
}
void Ler_Codigo_Categoria_Bin(char Url[99]){
	FILE *Arquivo;
	//Cria ponteiro de arquivo
	CODIGO_CATEGORIA Codigo_Categoria;
	Arquivo = fopen(Url,"rb");
	int Arquivo_Vazio=0;
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}else{
		while(!feof(Arquivo)){
			fread(&Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Ler_Codigo_Categoria_Memoria(Codigo_Categoria);
			Arquivo_Vazio++;
			//Contador para verificar se o arquivo está em branco
		}
		fclose(Arquivo);
		if(Arquivo_Vazio==0){
			Vermelho("O Arquivo está vazio\n");
		}
	}
}

void Gravar_Codigo_Categoria_Txt(char Url[99],CODIGO_CATEGORIA *Codigo_Categoria){
	//Colocar com parametro não " " mas sim ;
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	Arquivo=fopen(Url,"a+");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	fprintf(Arquivo,"%d;",Codigo_Categoria->Codigo);
	fprintf(Arquivo,"%s;",Codigo_Categoria->Descricao);
	fprintf(Arquivo,"%.2f;",Codigo_Categoria->Valor_Diaria);
	fprintf(Arquivo,"%d;",Codigo_Categoria->Capacidade_Adulto);
	fprintf(Arquivo,"%d;\n",Codigo_Categoria->Capacidade_Crianca);
		//Salva um struct por Linha

	fclose(Arquivo);
		//Fecha o o arquivo para evitar erros
	

	printf("\nArquivo Salvo em : %s",Url);
}


void Gravar_Codigo_Categoria_Bin(char Url[99],CODIGO_CATEGORIA *Codigo_Categoria){
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	
	Arquivo=fopen(Url,"ab");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	fwrite(Codigo_Categoria, sizeof(CODIGO_CATEGORIA), 1, Arquivo); 
   		//Primeiro argumento é um ponteiro .... como proceder

	fclose(Arquivo);
   		//Fecha o Arquivo Para evitar erro
	printf("\nArquivo Salvo 'Codigo_Categoria.bin'");
   		//Mensagem de Confirmação
}
void Recebe_Dados_Codigo_Categoria(CODIGO_CATEGORIA *Codigo_Categoria){
	printf("\nDescrição:");
	scanf("%s",Codigo_Categoria->Descricao);
	printf("Valor Diaria:");
	scanf("%f",&Codigo_Categoria->Valor_Diaria);
	printf("Capacidade Adultos:");
	scanf("%d",&Codigo_Categoria->Capacidade_Adulto);
	printf("Capacidade Crianças:");
	scanf("%d",&Codigo_Categoria->Capacidade_Crianca);
	//Le os outros dados
}

void Criar_Modificar_Codigo_Categoria(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];
	CODIGO_CATEGORIA Codigo_Categoria;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela
	switch (Modo_de_Abertura){
		case Arquivo_Texto:
		strcpy(Url,"Arquivos/Codigo_Categoria.txt");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Codigo_Categoria.Codigo = Valida_Codigo(Url,15,Arquivo_Texto,Dados_Codigo_Categoria);
		}else{
			Codigo_Categoria.Codigo = Manter_Codigo;
		}
		break;

		case Arquivo_Binario:
		strcpy(Url,"Arquivos/Codigo_Categoria.bin");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Codigo_Categoria.Codigo = Valida_Codigo(Url,15,Arquivo_Binario,Dados_Codigo_Categoria);
		}else{
			Codigo_Categoria.Codigo = Manter_Codigo;
		}
		break;
		case Banco_De_Dados:
			//Não está implementado
		break;
		case Nuvem:
			//Não está implementado
		break;

	}
	Recebe_Dados_Codigo_Categoria(&Codigo_Categoria);
	//Mostra Dados de Codigo_Categoria salvos na struct
	switch(Modo_de_Abertura){			
		case Arquivo_Texto:
			Gravar_Codigo_Categoria_Txt(Url,&Codigo_Categoria);
			//Grava em TXT
			break;

		case Arquivo_Binario:
			Gravar_Codigo_Categoria_Bin(Url,&Codigo_Categoria);
			//Grava em BIN
			break;

		case Banco_De_Dados:
			Vermelho("Banco de Dados não foi implentado\n");
			break;
		case Nuvem:
			Vermelho("Nuvem não foi implementado\n");
			break;
	}
		//Para Grava o Buffer da String no Arquivo
}


int Retorna_Campo_Struct_Codigo_Categoria(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Bin_ou_Txt(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[9999];
	CODIGO_CATEGORIA Codigo_Categoria;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo);
		Validador = Codigo_Categoria.Codigo;
		if(feof(Arquivo)){
			return -1;
			break;
		}
		if(Validador == Codigo){
			//Verifica se o codigo é igual ao lido
			return Numero_Structs;
			//Retorna a linha que tem o codigo
			break;
			//Confirma se saiu do loop
		}
		Numero_Structs++;
		//Soma no contac
	}while(!feof(Arquivo));
	//Le ate o fim do arquivo
	fclose(Arquivo);
	//Fecha o arquvio
	return -1;
}

void Apagar_Modificar_Codigo_Categoria_Bin(char Url[99], int Codigo,int Modificar,MODO Modo){
	if(Modo.Modo_de_Abertura == Arquivo_Binario){
		CODIGO_CATEGORIA Codigo_Categoria;
		//Cria uma Variavel do tipo Dados_Codigo_Categoria
		FILE *Arquivo, *Arquivo_Temporario;
		//Cria 2ponteiros do tipo FILE
		Arquivo=fopen(Url,Modo.Leitura);
		//Abre o aqruivo principal em modo leitura
		Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
		//Abre o arquivo que sera apagado em modo de concatenacao
		int Campo_Struct = Retorna_Campo_Struct_Codigo_Categoria(Url, Codigo);
		//Variavel Campo_Struct recebe quantas structs teve que pular para achar o codigo
		if(Campo_Struct == -1){//Se for retornado -1 mostra que nao foi encotrado o codigo digitado
			Vermelho("O codigo digitado não foi encontrado");
		}else{
			if(Confirmacao()){//Se a confirmacao retornar 1 
				for(int i=1;i<Campo_Struct;i++){
					//Vai ate o campo do codigo
					fread(&Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo);
					fwrite(&Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo_Temporario); 
					//Escreve no Arquivo temporario
				}

				fread(&Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo); 
				//Le o arquivo Arquivo Binario e passa dados para struct
				if(Modificar==1){
					//Entra no modo Editar
					Criar_Modificar_Codigo_Categoria(Arquivo_Binario, Codigo);
					//Chama a funcao para editar o arquivo
					Verde("\nEditado com Sucesso");
					system("clear");
					//Limpa tela
				}
				//Se nao entrar no if so apaga o dado
				while(!feof(Arquivo)){
					//Vai ate o Final do Arquivo
					fread(&Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo);
					if(feof(Arquivo)){
						//Sai caso esteja no fim do arquivo;
						break;
					}
					fwrite(&Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo_Temporario); 
						//Printa no Arquivo Temporario
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
					//Mostra que foi apagado com sucesso
				}
			}
		}
	}
}

/*
#ifdef Debug
printf("");
#endif
*/

#endif

