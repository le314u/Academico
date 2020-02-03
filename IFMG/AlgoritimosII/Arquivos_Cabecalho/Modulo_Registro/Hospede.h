#ifndef _Hospede_ 
	//Se não estiver definido entra no if
#define _Hospede_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

	//Inclui arquivos de cabeçalho
/*
void Ler_Hospede_Txt(char Url[99]);
void Ler_Hospede_Bin();
void Ler_Hospede_Memoria(DADOS_HOSPEDE Hospede);
void Gravar_Hospede_Txt(char Url[99],DADOS_HOSPEDE *Hospede);
void Gravar_Hospede_Bin(char Url[99],DADOS_HOSPEDE *Hospede);
void Criar_Modificar_Hospede(int Modo_de_Abertura,int Manter_Codigo);
int Retorna_Campo_Struct_Hospede(char Url[99], int Codigo);
void Apagar_Modificar_Hospede_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
void Nome_Hospede_Codigo(int Codigo, char Nome_Hospede[]);
*/
void Main_Hospede(MODO Modo){
	OrdenaValoresTxt();
	DADOS_HOSPEDE Hospede;
	
	int Acao,Codigo=0;
	Verificacao_Arquivo("Arquivos/Hospede.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Hospede.txt",Arquivo_Texto);
	
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
						Ler_Hospede_Bin("Arquivos/Hospede.bin");
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						Ler_Hospede_Txt("Arquivos/Hospede.txt");
					}
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;

			case Criar:
				if ((Modo.Nivel_De_Permissao >=4 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=12 && Modo.Nivel_De_Permissao <=15)){
						Criar_Modificar_Hospede(Modo.Modo_de_Abertura,0);	
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;	

			case Editar:
				if ((Modo.Nivel_De_Permissao >=2 && Modo.Nivel_De_Permissao <=3)||(Modo.Nivel_De_Permissao >=6 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=10 && Modo.Nivel_De_Permissao <=11)||(Modo.Nivel_De_Permissao >=14 && Modo.Nivel_De_Permissao <=15)){

					if(Modo.Modo_de_Abertura == Arquivo_Binario){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar_Hospede_Bin("Arquivos/Hospede.bin",Codigo,1,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Hospede.txt",Codigo,1,Modo,Dados_Hospede);
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
						Apagar_Modificar_Hospede_Bin("Arquivos/Hospede.bin",Codigo,0,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Hospede.txt",Codigo,0,Modo,Dados_Hospede);
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

void Nome_Hospede_Codigo(int Codigo, char Nome_Hospede[]){
	FILE *Arquivo;
	int Loop = 1;
	DADOS_HOSPEDE Hospede;
	char Temporario[Tamanho2];
	if(Configuracoes() == Arquivo_Binario){
		Arquivo = fopen("Arquivos/Hospede.bin","rb");
		if(Arquivo == NULL){
			Vermelho("\nNao foi possivel abrir o arquivo!");
		}else{
			while(Loop){
				fread(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo);
				if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
				}
				if(Hospede.Codigo == Codigo){
					strcpy(Nome_Hospede,Hospede.Nome);
					Loop = 0;
				}
			}
			fclose(Arquivo);
		}	
	}else{
		Arquivo = fopen("Arquivos/Hospede.txt","r");
		if(Arquivo==NULL){
			Vermelho("O Arquivo não foi aberto corretamente\n");
		}else{
			do{
				fscanf(Arquivo,"%d",&Hospede.Codigo);
					//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
					//Expreção Regular
				getc(Arquivo);
				if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
				}
				if(Hospede.Codigo == Codigo){
					fscanf(Arquivo,"%[^;]s",Hospede.Nome);
					//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
					//Expreção Regular
					getc(Arquivo);
					//Pula o Ponteiro para o proximo caracte (pula o \n)
					strcpy(Nome_Hospede,Hospede.Nome);
					Loop = 0;
				}else{
					fscanf(Arquivo,"%[^\n]s",Temporario);
					getc(Arquivo);
				}getc(Arquivo);
					//Pula o Ponteiro para o proximo caractere
								
			}while(Loop);
		}
	}
}
void Ler_Hospede_Txt(char Url[99]){
	DADOS_HOSPEDE Hospede;
		//Cria uma variavel do tipo DADOS HOSPEDE;

	FILE *Arquivo;
		//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	int Arquivo_Vazio=0;

	
	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
		do{
			fscanf(Arquivo,"%d",&Hospede.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Nome);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Sexo);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Estado_Civil);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.CPF);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Logradouro);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Numero);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Bairro);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Cidade);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Telefone);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Email);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Data_Nascimento);
				//Expreção Regular
			getc(Arquivo);
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caracte (pula o \n)
			Ler_Hospede_Memoria(Hospede);
			
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

void Ler_Hospede_Memoria(DADOS_HOSPEDE Hospede){
	//Recebe por parametro Struct de Hospede
	printf("Codigo:\t\t\t\t%d\n",Hospede.Codigo);
	printf("Nome :\t\t\t\t%s\n",Hospede.Nome);
	printf("Sexo:\t\t\t\t%s\n",Hospede.Sexo);
	printf("Estado Civil:\t\t\t%s\n",Hospede.Estado_Civil);
	printf("CPF:\t\t\t\t%s\n",Hospede.CPF);
	printf("Logradouro:\t\t\t%s\n",Hospede.Endereco.Logradouro);
	printf("Numero:\t\t\t\t%s\n",Hospede.Endereco.Numero);
	printf("Bairro:\t\t\t\t%s\n",Hospede.Endereco.Bairro);
	printf("Cidade:\t\t\t\t%s\n",Hospede.Endereco.Cidade);
	printf("Telefone:\t\t\t%s\n",Hospede.Telefone);
	printf("Email:\t\t\t\t%s\n",Hospede.Email);
	printf("Data Nascimento gerente:\t%s\n",Hospede.Data_Nascimento);
	printf("____________________________________________________\n");
	//Mostra dados do Hospede cadastrado na memoria
}

void Ler_Hospede_Bin(char Url[99]){
	FILE *Arquivo;
	//Cria ponteiro de arquivo
	DADOS_HOSPEDE Hospede;
	Arquivo = fopen(Url,"rb");
	int Arquivo_Vazio=0;
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}else{
		while(!feof(Arquivo)){
			fread(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Ler_Hospede_Memoria(Hospede);
			Arquivo_Vazio++;
			//Contador para verificar se o arquivo está em branco
		}
		fclose(Arquivo);
		if(Arquivo_Vazio==0){
			Vermelho("O Arquivo está vazio\n");
		}
	}
}

void Gravar_Hospede_Txt(char Url[99],DADOS_HOSPEDE *Hospede){
	//Colocar com parametro não " " mas sim ;
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	Arquivo=fopen(Url,"a+");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	fprintf(Arquivo,"%d;",Hospede->Codigo);
	fprintf(Arquivo,"%s;",Hospede->Nome);
	fprintf(Arquivo,"%s;",Hospede->Sexo);
	fprintf(Arquivo,"%s;",Hospede->Estado_Civil);
	fprintf(Arquivo,"%s;",Hospede->CPF);
	fprintf(Arquivo,"%s;",Hospede->Endereco.Logradouro);
	fprintf(Arquivo,"%s;",Hospede->Endereco.Numero);
	fprintf(Arquivo,"%s;",Hospede->Endereco.Bairro);
	fprintf(Arquivo,"%s;",Hospede->Endereco.Cidade);
	fprintf(Arquivo,"%s;",Hospede->Telefone);
	fprintf(Arquivo,"%s;",Hospede->Email);
	fprintf(Arquivo,"%s;\n",Hospede->Data_Nascimento);
		//Salva um struct por Linha

	fclose(Arquivo);
		//Fecha o o arquivo para evitar erros
	

	printf("\nArquivo Salvo em : %s",Url);
}


void Gravar_Hospede_Bin(char Url[99],DADOS_HOSPEDE *Hospede){
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	
	Arquivo=fopen(Url,"ab");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	fwrite(Hospede, sizeof(DADOS_HOSPEDE), 1, Arquivo); 
   		//Primeiro argumento é um ponteiro .... como proceder

	fclose(Arquivo);
   		//Fecha o Arquivo Para evitar erro
	printf("\nArquivo Salvo 'Hospede.bin'");
   		//Mensagem de Confirmação
}
void Recebe_Dados_Hospede(DADOS_HOSPEDE *Hospede){
	printf("\nNome:");
	scanf("%s",Hospede->Nome);
	printf("Sexo:");
	scanf("%s",Hospede->Sexo);
	printf("Estado Civil:");
	scanf("%s",Hospede->Estado_Civil);
	printf("CPF:");
	scanf("%s",Hospede->CPF);
	printf("Logradouro:");
	scanf("%s",Hospede->Endereco.Logradouro);
	printf("Numero:");
	scanf("%s",Hospede->Endereco.Numero);
	printf("Bairro:");
	scanf("%s",Hospede->Endereco.Bairro);
	printf("Cidade:");
	scanf("%s",Hospede->Endereco.Cidade);
	printf("Telefone:");
	scanf("%s",Hospede->Telefone);
	printf("e-mail:");
	scanf("%s",Hospede->Email);
	printf("Data Nascimento:");
	scanf("%s",Hospede->Data_Nascimento);
	
	//Le os outros dados
}

void Criar_Modificar_Hospede(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];
	DADOS_HOSPEDE Hospede;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela
	switch (Modo_de_Abertura){
		case Arquivo_Texto:
		strcpy(Url,"Arquivos/Hospede.txt");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Hospede.Codigo = Valida_Codigo(Url,15,Arquivo_Texto,Dados_Hospede);
		}else{
			Hospede.Codigo = Manter_Codigo;
		}
		break;

		case Arquivo_Binario:
		strcpy(Url,"Arquivos/Hospede.bin");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Hospede.Codigo = Valida_Codigo(Url,15,Arquivo_Binario,Dados_Hospede);
		}else{
			Hospede.Codigo = Manter_Codigo;
		}
		break;
		case Banco_De_Dados:
			//Não está implementado
		break;
		case Nuvem:
			//Não está implementado
		break;

	}
	Recebe_Dados_Hospede(&Hospede);
	//Mostra Dados de Hospede salvos na struct
	switch(Modo_de_Abertura){			
		case Arquivo_Texto:
			Gravar_Hospede_Txt(Url,&Hospede);
			//Grava em TXT
			break;

		case Arquivo_Binario:
			Gravar_Hospede_Bin(Url,&Hospede);
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


int Retorna_Campo_Struct_Hospede(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Bin_ou_Txt(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[9999];
	DADOS_HOSPEDE Hospede;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo);
		Validador = Hospede.Codigo;
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

void Apagar_Modificar_Hospede_Bin(char Url[99], int Codigo,int Modificar,MODO Modo){
	if(Modo.Modo_de_Abertura == Arquivo_Binario){
		DADOS_HOSPEDE Hospede;
		//Cria uma Variavel do tipo Dados_Hospede
		FILE *Arquivo, *Arquivo_Temporario;
		//Cria 2ponteiros do tipo FILE
		Arquivo=fopen(Url,Modo.Leitura);
		//Abre o aqruivo principal em modo leitura
		Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
		//Abre o arquivo que sera apagado em modo de concatenacao
		int Campo_Struct = Retorna_Campo_Struct_Hospede(Url, Codigo);
		//Variavel Campo_Struct recebe quantas structs teve que pular para achar o codigo
		if(Campo_Struct == -1){//Se for retornado -1 mostra que nao foi encotrado o codigo digitado
			Vermelho("O codigo digitado não foi encontrado");
		}else{
			if(Confirmacao()){//Se a confirmacao retornar 1 
				for(int i=1;i<Campo_Struct;i++){
					//Vai ate o campo do codigo
					fread(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo);
					fwrite(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo_Temporario); 
					//Escreve no Arquivo temporario
				}

				fread(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo); 
				//Le o arquivo Arquivo Binario e passa dados para struct
				if(Modificar==1){
					//Entra no modo Editar
					Criar_Modificar_Hospede(Arquivo_Binario, Codigo);
					//Chama a funcao para editar o arquivo
					Verde("\nEditado com Sucesso");
					system("clear");
					//Limpa tela
				}
				//Se nao entrar no if so apaga o dado
				while(!feof(Arquivo)){
					//Vai ate o Final do Arquivo
					fread(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo);
					if(feof(Arquivo)){
						//Sai caso esteja no fim do arquivo;
						break;
					}
					fwrite(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo_Temporario); 
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

