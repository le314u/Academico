#ifndef _Fornecedores_ 
	//Se não estiver definido entra no if
#define _Fornecedores_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

	//Inclui arquivos de cabeçalho
/*
int Retorna_Campo_Struct_Fornecedores(char Url[99], int Codigo);
void Apagar_Modificar_Fornecedores_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
void Criar_Modificar_Fornecedores(int Modo_de_Abertura,int Manter_Codigo);
void Gravar_Fornecedores_Bin(char Url[99],FORNECEDORES *Fornecedores);
void Gravar_Fornecedores_Txt(char Url[99],FORNECEDORES *Fornecedores);
void Ler_Fornecedores_Bin();
void Ler_Fornecedores_Memoria(FORNECEDORES Fornecedores);
void Ler_Fornecedores_Txt(char Url[99]);
void Main_Fornecedores(MODO Modo);
*/
void Main_Fornecedores(MODO Modo){
	FORNECEDORES Fornecedores;
	int Acao,Codigo=0;

	Verificacao_Arquivo("Arquivos/Fornecedores.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Fornecedores.txt",Arquivo_Texto);
	//Verifica se ja existe os arquivos

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
						Ler_Fornecedores_Bin("Arquivos/Fornecedores.bin");
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						Ler_Fornecedores_Txt("Arquivos/Fornecedores.txt");
					}
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;
			case Criar:
				if ((Modo.Nivel_De_Permissao >=4 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=12 && Modo.Nivel_De_Permissao <=15)){
						Criar_Modificar_Fornecedores(Modo.Modo_de_Abertura,0);	
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;	

			case Editar:
				if ((Modo.Nivel_De_Permissao >=2 && Modo.Nivel_De_Permissao <=3)||(Modo.Nivel_De_Permissao >=6 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=10 && Modo.Nivel_De_Permissao <=11)||(Modo.Nivel_De_Permissao >=14 && Modo.Nivel_De_Permissao <=15)){
					if(Modo.Modo_de_Abertura == Arquivo_Binario){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar_Fornecedores_Bin("Arquivos/Fornecedores.bin",Codigo,1,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Fornecedores.txt",Codigo,1,Modo,Dados_Fornecedores);
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
						Apagar_Modificar_Fornecedores_Bin("Arquivos/Fornecedores.bin",Codigo,0,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Fornecedores.txt",Codigo,0,Modo,Dados_Fornecedores);
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
void Ler_Fornecedores_Txt(char Url[99]){
	FORNECEDORES Fornecedores;
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
			fscanf(Arquivo,"%d",&Fornecedores.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Fornecedores.Nome_Fantasia);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Fornecedores.Razao_Social);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Fornecedores.Inscricao_Estadual);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Fornecedores.CNPJ);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Fornecedores.Endereco.Logradouro);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Fornecedores.Endereco.Numero);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Fornecedores.Endereco.Bairro);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Fornecedores.Endereco.Cidade);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Fornecedores.Telefone);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Fornecedores.Email);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caracte (pula o \n)
			Ler_Fornecedores_Memoria(Fornecedores);
			
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

void Ler_Fornecedores_Memoria(FORNECEDORES Fornecedores){
	//Recebe por parametro Struct de Fornecedores
	printf("Codigo:\t\t\t%d\n",Fornecedores.Codigo);
	printf("Nome fantasia:\t\t%s\n",Fornecedores.Nome_Fantasia);
	printf("Razao social:\t\t%s\n",Fornecedores.Razao_Social);
	printf("Inscricao Estadual\t%s\n",Fornecedores.Inscricao_Estadual);
	printf("CNPJ:\t\t\t%s\n",Fornecedores.CNPJ);
	printf("Logradouro:\t\t%s\n",Fornecedores.Endereco.Logradouro);
	printf("Numero:\t\t\t%s\n",Fornecedores.Endereco.Numero);
	printf("Bairro:\t\t\t%s\n",Fornecedores.Endereco.Bairro);
	printf("Cidade:\t\t\t%s\n",Fornecedores.Endereco.Cidade);
	printf("Telefone:\t\t%s\n",Fornecedores.Telefone);
	printf("Email:\t\t\t%s\n",Fornecedores.Email);
	printf("____________________________________________________\n");
	//Mostra dados do Fornecedores cadastrado na memoria
}

void Ler_Fornecedores_Bin(char Url[99]){
	FILE *Arquivo;
	//Cria ponteiro de arquivo
	FORNECEDORES Fornecedores;
	Arquivo = fopen(Url,"rb");
	int Arquivo_Vazio=0;
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}else{
		while(!feof(Arquivo)){
			fread(&Fornecedores, sizeof(FORNECEDORES),1,Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Ler_Fornecedores_Memoria(Fornecedores);
			Arquivo_Vazio++;
			//Contador para verificar se o arquivo está em branco
		}
		fclose(Arquivo);
		if(Arquivo_Vazio==0){
			Vermelho("O Arquivo está vazio\n");
		}
	}
}

void Gravar_Fornecedores_Txt(char Url[99],FORNECEDORES *Fornecedores){
	//Colocar com parametro não " " mas sim ;
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	Arquivo=fopen(Url,"a+");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	fprintf(Arquivo,"%d;",Fornecedores->Codigo);
	fprintf(Arquivo,"%s;",Fornecedores->Nome_Fantasia);
	fprintf(Arquivo,"%s;",Fornecedores->Razao_Social);
	fprintf(Arquivo,"%s;",Fornecedores->Inscricao_Estadual);
	fprintf(Arquivo,"%s;",Fornecedores->CNPJ);
	fprintf(Arquivo,"%s;",Fornecedores->Endereco.Logradouro);
	fprintf(Arquivo,"%s;",Fornecedores->Endereco.Numero);
	fprintf(Arquivo,"%s;",Fornecedores->Endereco.Bairro);
	fprintf(Arquivo,"%s;",Fornecedores->Endereco.Cidade);
	fprintf(Arquivo,"%s;",Fornecedores->Telefone);
	fprintf(Arquivo,"%s;\n",Fornecedores->Email);
		//Salva um struct por Linha

	fclose(Arquivo);
		//Fecha o o arquivo para evitar erros
	

	printf("\nArquivo Salvo em : %s",Url);
}


void Gravar_Fornecedores_Bin(char Url[99],FORNECEDORES *Fornecedores){
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	
	Arquivo=fopen(Url,"ab");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	fwrite(Fornecedores, sizeof(FORNECEDORES), 1, Arquivo); 
   		//Primeiro argumento é um ponteiro .... como proceder

	fclose(Arquivo);
   		//Fecha o Arquivo Para evitar erro
	printf("\nArquivo Salvo 'Fornecedores.bin'");
   		//Mensagem de Confirmação
}
void Recebe_Dados_Fornecedores(FORNECEDORES *Fornecedores){
	printf("\nNome Fantasia:");
	scanf("%s",Fornecedores->Nome_Fantasia);
	printf("Razão Social:");
	scanf("%s",Fornecedores->Razao_Social);
	printf("Inscrição Estadual:");
	scanf("%s",Fornecedores->Inscricao_Estadual);
	printf("CNPJ:");
	scanf("%s",Fornecedores->CNPJ);
	printf("Logradouro:");
	scanf("%s",Fornecedores->Endereco.Logradouro);
	printf("Numero:");
	scanf("%s",Fornecedores->Endereco.Numero);
	printf("Bairro:");
	scanf("%s",Fornecedores->Endereco.Bairro);
	printf("Cidade:");
	scanf("%s",Fornecedores->Endereco.Cidade);
	printf("Telefone:");
	scanf("%s",Fornecedores->Telefone);
	printf("e-mail:");
	scanf("%s",Fornecedores->Email);
	//Le os outros dados
}

void Criar_Modificar_Fornecedores(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];
	FORNECEDORES Fornecedores;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela
	switch (Modo_de_Abertura){
		case Arquivo_Texto:
		strcpy(Url,"Arquivos/Fornecedores.txt");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Fornecedores.Codigo = Valida_Codigo(Url,15,Arquivo_Texto,Dados_Fornecedores);
		}else{
			Fornecedores.Codigo = Manter_Codigo;
		}
		break;

		case Arquivo_Binario:
		strcpy(Url,"Arquivos/Fornecedores.bin");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Fornecedores.Codigo = Valida_Codigo(Url,15,Arquivo_Binario,Dados_Fornecedores);
		}else{
			Fornecedores.Codigo = Manter_Codigo;
		}
		break;
		case Banco_De_Dados:
			//Não está implementado
		break;
		case Nuvem:
			//Não está implementado
		break;

	}
	Recebe_Dados_Fornecedores(&Fornecedores);
	//Mostra Dados de Fornecedores salvos na struct
	switch(Modo_de_Abertura){			
		case Arquivo_Texto:
			Gravar_Fornecedores_Txt(Url,&Fornecedores);
			//Grava em TXT
			break;

		case Arquivo_Binario:
			Gravar_Fornecedores_Bin(Url,&Fornecedores);
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


int Retorna_Campo_Struct_Fornecedores(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Bin_ou_Txt(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[9999];
	FORNECEDORES Fornecedores;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Fornecedores, sizeof(FORNECEDORES),1,Arquivo);
		Validador = Fornecedores.Codigo;
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
		//Soma no contador
	}while(!feof(Arquivo));
	//Le ate o fim do arquivo
	fclose(Arquivo);
	//Fecha o arquvio
	return -1;
}

void Apagar_Modificar_Fornecedores_Bin(char Url[99], int Codigo,int Modificar,MODO Modo){
	if(Modo.Modo_de_Abertura == Arquivo_Binario){
		FORNECEDORES Fornecedores;
		//Cria uma Variavel do tipo Dados_Fornecedores
		FILE *Arquivo, *Arquivo_Temporario;
		//Cria 2ponteiros do tipo FILE
		Arquivo=fopen(Url,Modo.Leitura);
		//Abre o aqruivo principal em modo leitura
		Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
		//Abre o arquivo que sera apagado em modo de concatenacao
		int Campo_Struct = Retorna_Campo_Struct_Fornecedores(Url, Codigo);
		//Variavel Campo_Struct recebe quantas structs teve que pular para achar o codigo
		if(Campo_Struct == -1){//Se for retornado -1 mostra que nao foi encotrado o codigo digitado
			Vermelho("O codigo digitado não foi encontrado");
		}else{
			if(Confirmacao()){//Se a confirmacao retornar 1 
				for(int i=1;i<Campo_Struct;i++){
					//Vai ate o campo do codigo
					fread(&Fornecedores, sizeof(FORNECEDORES),1,Arquivo);
					fwrite(&Fornecedores, sizeof(FORNECEDORES),1,Arquivo_Temporario); 
					//Escreve no Arquivo temporario
				}

				fread(&Fornecedores, sizeof(FORNECEDORES),1,Arquivo); 
				//Le o arquivo Arquivo Binario e passa dados para struct
				if(Modificar==1){
					//Entra no modo Editar
					Criar_Modificar_Fornecedores(Arquivo_Binario, Codigo);
					//Chama a funcao para editar o arquivo
					Verde("\nEditado com Sucesso");
					system("clear");
					//Limpa tela
				}
				//Se nao entrar no if so apaga o dado
				while(!feof(Arquivo)){
					//Vai ate o Final do Arquivo
					fread(&Fornecedores, sizeof(FORNECEDORES),1,Arquivo);
					if(feof(Arquivo)){
						//Sai caso esteja no fim do arquivo;
						break;
					}
					fwrite(&Fornecedores, sizeof(FORNECEDORES),1,Arquivo_Temporario); 
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

