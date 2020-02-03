#ifndef _Funcionarios_ 
	//Se não estiver definido entra no if
#define _Funcionarios_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

	//Inclui arquivos de cabeçalho
/*
void Ler_Funcionarios_Txt(char Url[99]);
void Ler_Funcionarios_Bin();
void Ler_Funcionarios_Memoria(FUNCIONARIOS Funcionarios);
void Gravar_Funcionarios_Txt(char Url[99],FUNCIONARIOS *Funcionarios);
void Gravar_Funcionarios_Bin(char Url[99],FUNCIONARIOS *Funcionarios);
void Criar_Modificar_Funcionarios(int Modo_de_Abertura,int Manter_Codigo);
int Retorna_Campo_Struct_Funcionarios(char Url[99], int Codigo);
void Apagar_Modificar_Funcionarios_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
*/
void Main_Funcionarios(MODO Modo){
	FUNCIONARIOS Funcionarios;
	
	int Acao,Codigo=0;
	Verificacao_Arquivo("Arquivos/Funcionarios.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Funcionarios.txt",Arquivo_Texto);
	
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
						Ler_Funcionarios_Bin("Arquivos/Funcionarios.bin");
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						Ler_Funcionarios_Txt("Arquivos/Funcionarios.txt");
					}
				}else{
						Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;

			case Criar:
				if ((Modo.Nivel_De_Permissao >=4 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=12 && Modo.Nivel_De_Permissao <=15)){
						Criar_Modificar_Funcionarios(Modo.Modo_de_Abertura,0);	
				}else{
						Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;	

			case Editar:
				if ((Modo.Nivel_De_Permissao >=2 && Modo.Nivel_De_Permissao <=3)||(Modo.Nivel_De_Permissao >=6 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=10 && Modo.Nivel_De_Permissao <=11)||(Modo.Nivel_De_Permissao >=14 && Modo.Nivel_De_Permissao <=15)){

					if(Modo.Modo_de_Abertura == Arquivo_Binario){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar_Funcionarios_Bin("Arquivos/Funcionarios.bin",Codigo,1,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Funcionarios.txt",Codigo,1,Modo,Dados_Funcionarios);
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
						Apagar_Modificar_Funcionarios_Bin("Arquivos/Funcionarios.bin",Codigo,0,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Funcionarios.txt",Codigo,0,Modo,Dados_Funcionarios);
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
void Ler_Funcionarios_Txt(char Url[99]){
	FUNCIONARIOS Funcionarios;
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
			fscanf(Arquivo,"%d",&Funcionarios.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Funcionarios.Nome);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Funcionarios.Usuario);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Funcionarios.Senha);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%d",&Funcionarios.Permissao);
				//Expreção Regular
			getc(Arquivo);
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caracte (pula o \n)
			Ler_Funcionarios_Memoria(Funcionarios);
			
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

void Ler_Funcionarios_Memoria(FUNCIONARIOS Funcionarios){
	//Recebe por parametro Struct de Funcionarios
	printf("Codigo:\t\t%d\n",Funcionarios.Codigo);
	printf("Nome:\t\t%s\n",Funcionarios.Nome);
	printf("Usuario:\t%s\n",Funcionarios.Usuario);
	printf("Senha\t\t%s\n",Funcionarios.Senha);
	printf("Pemissao:\t%d\n",Funcionarios.Permissao);
	printf("____________________________________________________\n");
	//Mostra dados do Funcionarios cadastrado na memoria
}

void Ler_Funcionarios_Bin(char Url[99]){
	FILE *Arquivo;
	//Cria ponteiro de arquivo
	FUNCIONARIOS Funcionarios;
	Arquivo = fopen(Url,"rb");
	int Arquivo_Vazio=0;
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}else{
		while(!feof(Arquivo)){
			fread(&Funcionarios, sizeof(FUNCIONARIOS),1,Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Ler_Funcionarios_Memoria(Funcionarios);
			Arquivo_Vazio++;
			//Contador para verificar se o arquivo está em branco
		}
		fclose(Arquivo);
		if(Arquivo_Vazio==0){
			Vermelho("O Arquivo está vazio\n");
		}
	}
}

void Gravar_Funcionarios_Txt(char Url[99],FUNCIONARIOS *Funcionarios){
	//Colocar com parametro não " " mas sim ;
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	Arquivo=fopen(Url,"a+");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	fprintf(Arquivo,"%d;",Funcionarios->Codigo);
	fprintf(Arquivo,"%s;",Funcionarios->Nome);
	fprintf(Arquivo,"%s;",Funcionarios->Usuario);
	fprintf(Arquivo,"%s;",Funcionarios->Senha);
	fprintf(Arquivo,"%d;\n",Funcionarios->Permissao);
		//Salva um struct por Linha

	fclose(Arquivo);
		//Fecha o o arquivo para evitar erros
	

	printf("\nArquivo Salvo em : %s",Url);
}


void Gravar_Funcionarios_Bin(char Url[99],FUNCIONARIOS *Funcionarios){
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	
	Arquivo=fopen(Url,"ab");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	fwrite(Funcionarios, sizeof(FUNCIONARIOS), 1, Arquivo); 
   		//Primeiro argumento é um ponteiro .... como proceder

	fclose(Arquivo);
   		//Fecha o Arquivo Para evitar erro
	printf("\nArquivo Salvo 'Funcionarios.bin'");
   		//Mensagem de Confirmação
}
void Recebe_Dados_Funcionarios(FUNCIONARIOS *Funcionarios){
	printf("\nNome:");
	scanf("%s",Funcionarios->Nome);
	printf("Usuario:");
	scanf("%s",Funcionarios->Usuario);
	printf("Senha:");
	char Senha[999];
	scanf("%s",Senha);
	Criptografar(Senha);
	strcpy(Funcionarios->Senha,Senha);
	int Ler=2,Editar=2,Criar=2,Apagar=2;
	int Decimal = 0;

	while(((Ler>1||Ler<0)||(Criar>1||Criar<0) || (Editar>1 || Editar < 0) || (Apagar >1 || Apagar <0)) || Decimal == 0){
		printf("\nDigite 1 para permitir e 0 para negar");
		printf("\nPermissao para Ler:");
		scanf("%d",&Ler);
		printf("\nPermissao para Criar:");
		scanf("%d",&Criar);
		printf("\nPermissao para Editar:");
		scanf("%d",&Editar);
		printf("\nPermissao para Apagar:");
		scanf("%d",&Apagar);
		Decimal = Converter_Decimal_Binario(Apagar,Editar,Criar,Ler);
		system("clear");
		if (Decimal == 0)
		{
			printf("O usuario precisa ter pelo menos uma permissao\n");
		}else if((Ler>1||Ler<0)||(Criar>1||Criar<0) || (Editar>1 || Editar < 0) || (Apagar >1 || Apagar <0)){
			printf("Digite apenas 1 ou 0 para marcar a permissao\n");
		}
	}
	Funcionarios->Permissao = Decimal;

	switch (Decimal){
		case 1 :
			printf("\n Permissão nivel  1 - Apagar");
			break;
		case 2 :
			printf("\n Permissão nivel  2 - Editar");
			break;
		case 3 :
			printf("\n Permissão nivel  3 - Apagar e Editar");
			break;
		case 4 :
			printf("\n Permissão nivel  4 - Criar");
			break;
		case 5 :
			printf("\n Permissão nivel  5 - Criar e Apagar");
			break;
		case 6 :
			printf("\n Permissão nivel  6 - Criar e Editar");
			break;
		case 7 :
			printf("\n Permissão nivel  7 - Criar, Editar e Apagar");
			break;
		case 8 :
			printf("\n Permissão nivel  8 - Ler");
			break;
		case 9 :
			printf("\n Permissão nivel  9 - Ler e Apagar");
			break;
		case 10 :
			printf("\n Permissão nivel  10 - Ler e Editar");
			break;
		case 11 :
			printf("\n Permissão nivel  11 - Ler, Editar e Apagar");
			break;
		case 12 :
			printf("\n Permissão nivel  12 - Ler e Criar");
			break;
		case 13 :
			printf("\n Permissão nivel  13 - Ler, Criar e Apagar");
			break;
		case 14 :
			printf("\n Permissão nivel  14 - Ler, Criar e Editar");
			break;
		case 15 :
			printf("\n Permissão nivel  15 - Ler, Criar, Editar e Apagar");
			break;
	}
	//Le os outros dados
}

void Criar_Modificar_Funcionarios(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];
	FUNCIONARIOS Funcionarios;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela
	switch (Modo_de_Abertura){
		case Arquivo_Texto:
		strcpy(Url,"Arquivos/Funcionarios.txt");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Funcionarios.Codigo = Valida_Codigo(Url,15,Arquivo_Texto,Dados_Funcionarios);
		}else{
			Funcionarios.Codigo = Manter_Codigo;
		}
		break;

		case Arquivo_Binario:
		strcpy(Url,"Arquivos/Funcionarios.bin");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Funcionarios.Codigo = Valida_Codigo(Url,15,Arquivo_Binario,Dados_Funcionarios);
		}else{
			Funcionarios.Codigo = Manter_Codigo;
		}
		break;
		case Banco_De_Dados:
			//Não está implementado
		break;
		case Nuvem:
			//Não está implementado
		break;

	}
	Recebe_Dados_Funcionarios(&Funcionarios);
	//Mostra Dados de Funcionarios salvos na struct
	switch(Modo_de_Abertura){			
		case Arquivo_Texto:
			Gravar_Funcionarios_Txt(Url,&Funcionarios);
			//Grava em TXT
			break;

		case Arquivo_Binario:
			Gravar_Funcionarios_Bin(Url,&Funcionarios);
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


int Retorna_Campo_Struct_Funcionarios(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Bin_ou_Txt(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[9999];
	FUNCIONARIOS Funcionarios;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Funcionarios, sizeof(FUNCIONARIOS),1,Arquivo);
		Validador = Funcionarios.Codigo;
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

void Apagar_Modificar_Funcionarios_Bin(char Url[99], int Codigo,int Modificar,MODO Modo){
	if(Modo.Modo_de_Abertura == Arquivo_Binario){
		FUNCIONARIOS Funcionarios;
		//Cria uma Variavel do tipo Dados_Funcionarios
		FILE *Arquivo, *Arquivo_Temporario;
		//Cria 2ponteiros do tipo FILE
		Arquivo=fopen(Url,Modo.Leitura);
		//Abre o aqruivo principal em modo leitura
		Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
		//Abre o arquivo que sera apagado em modo de concatenacao
		int Campo_Struct = Retorna_Campo_Struct_Funcionarios(Url, Codigo);
		//Variavel Campo_Struct recebe quantas structs teve que pular para achar o codigo
		if(Campo_Struct == -1){//Se for retornado -1 mostra que nao foi encotrado o codigo digitado
			Vermelho("O codigo digitado não foi encontrado");
		}else{
			if(Confirmacao()){//Se a confirmacao retornar 1 
				for(int i=1;i<Campo_Struct;i++){
					//Vai ate o campo do codigo
					fread(&Funcionarios, sizeof(FUNCIONARIOS),1,Arquivo);
					fwrite(&Funcionarios, sizeof(FUNCIONARIOS),1,Arquivo_Temporario); 
					//Escreve no Arquivo temporario
				}

				fread(&Funcionarios, sizeof(FUNCIONARIOS),1,Arquivo); 
				//Le o arquivo Arquivo Binario e passa dados para struct
				if(Modificar==1){
					//Entra no modo Editar
					Criar_Modificar_Funcionarios(Arquivo_Binario, Codigo);
					//Chama a funcao para editar o arquivo
					Verde("\nEditado com Sucesso");
					system("clear");
					//Limpa tela
				}
				//Se nao entrar no if so apaga o dado
				while(!feof(Arquivo)){
					//Vai ate o Final do Arquivo
					fread(&Funcionarios, sizeof(FUNCIONARIOS),1,Arquivo);
					if(feof(Arquivo)){
						//Sai caso esteja no fim do arquivo;
						break;
					}
					fwrite(&Funcionarios, sizeof(FUNCIONARIOS),1,Arquivo_Temporario); 
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

