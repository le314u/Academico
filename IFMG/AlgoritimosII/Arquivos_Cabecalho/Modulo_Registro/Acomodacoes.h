#ifndef _Acomodacoes_ 
	//Se não estiver definido entra no if
#define _Acomodacoes_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

	//Inclui arquivos de cabeçalho
/*
void Ler_Acomodacoes_Txt(char Url[99]);
void Ler_Acomodacoes_Bin();
void Ler_Acomodacoes_Memoria(ACOMODACOES Acomodacoes);
void Recebe_Dados_Acomodacoes(ACOMODACOES *Acomodacoes, int Modo_de_Abertura)
void Gravar_Acomodacoes_Txt(char Url[99],ACOMODACOES *Acomodacoes);
void Gravar_Acomodacoes_Bin(char Url[99],ACOMODACOES *Acomodacoes);
void Criar_Modificar_Acomodacoes(int Modo_de_Abertura,int Manter_Codigo);
int Retorna_Campo_Struct_Acomodacoes(char Url[99], int Codigo);
void Apagar_Modificar_Acomodacoes_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
*/

void Main_Acomodacoes(MODO Modo){
	ACOMODACOES Acomodacoes;
	int Acao,Codigo=0,Vazio_Hotel=0,Vazio_Categoria=0;
	//Variaveis e struct
	switch (Modo.Modo_de_Abertura){
		case Arquivo_Binario:
			Vazio_Categoria=Arquivo_Binario_Vazio("Arquivos/Codigo_Categoria.bin");
			Vazio_Hotel=Arquivo_Binario_Vazio("Arquivos/Hotel.bin");
			//Caso binario verifica se arquivos estao criados e se estao vazios
		break;
		case Arquivo_Texto:
			Vazio_Categoria=Arquivo_Texto_Vazio("Arquivos/Codigo_Categoria.txt");
			Vazio_Hotel=Arquivo_Binario_Vazio("Arquivos/Hotel.txt");
			//Caso TXT verifica se arquivos estao criados e se estao vazios
		break;
	}
	//Caso algum esteja vazio indica que nao é possivel manipular dados hotel
	if(Vazio_Hotel == 1){
		Vermelho("Não é possivel Manipular as Acomodaçoes pois não há hotéis cadastradas \n");
		Verde("\nDigite 1 e aperte algo para continuar");
		PAUSA
	}else if (Vazio_Categoria == 1)
	{
		Vermelho("Não é possivel Manipular as Acomodaçoes pois não há categorias cadastradas \n");
		Verde("\nDigite 1 e aperte algo para continuar");
		PAUSA
	}else{
		while(1){
			OrdenaValoresTxt();
			Acao = Opcao_Acoes();
			//Retorna um inteiro referente a Ação (Case)
			switch (Acao){
				case Ler:
				//Caso ler
				if(Modo.Nivel_De_Permissao>=8 && Modo.Nivel_De_Permissao <=15){
					//Verifica permissao BINARIOS
					if (Modo.Modo_de_Abertura == Arquivo_Binario)//MOdo de abertura binario
					{
						Ler_Acomodacoes_Bin("Arquivos/Acomodacoes.bin");//Chama funcao para ler acomodacoes
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						Ler_Acomodacoes_Txt("Arquivos/Acomodacoes.txt");//Caso txt chama funcao para ler em txt
					}
				}else{//Caso o usuario nao tenha permissao para ler
						Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
					}
					break;

				case Criar://Caso criar
					if ((Modo.Nivel_De_Permissao >=4 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=12 && Modo.Nivel_De_Permissao <=15)){
						//Verifica se usuario tem permissao para criar dados
							Criar_Modificar_Acomodacoes(Modo.Modo_de_Abertura,0);//chama funcao para criar ou modificar acomodacoes
					}else{
						Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
					}//Mostra que usuario nao tem a permissao para a a acao
					break;	

				case Editar:
				//Caso editar
				if ((Modo.Nivel_De_Permissao >=2 && Modo.Nivel_De_Permissao <=3)||(Modo.Nivel_De_Permissao >=6 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=10 && Modo.Nivel_De_Permissao <=11)||(Modo.Nivel_De_Permissao >=14 && Modo.Nivel_De_Permissao <=15)){
					//Verifica se o usuario tem permissao para a tarefa
					if(Modo.Modo_de_Abertura == Arquivo_Binario){//Caso modo binario
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						//Recebe codigo a ser editado
						Apagar_Modificar_Acomodacoes_Bin("Arquivos/Acomodacoes.bin",Codigo,1,Modo);
						//Chama funcao para apagar modificar passando por parametro codigo 1 indicando edicao
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						//Caso txt, recebe codigo a ser editado
						Apagar_Modificar("Arquivos/Acomodacoes.txt",Codigo,1,Modo,Dados_Acomodacoes);
						//Chama funcao para apagar modificar passando por parametro codigo 1 indicando edicao
					}
				}else{//Mostra que usuario nao tem permissao para editar
						Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
					}
					break;
				case Apagar:
				//Caso apagar
					if ((Modo.Nivel_De_Permissao%2)){//Se for impar retorna 1 e somente numeros impares tem a permissao de Apagar
						//Veriifica a permissao para apagar
						if(Modo.Modo_de_Abertura == Arquivo_Binario){
							printf("Digite o codigo a ser apagado: ");
							scanf("%d",&Codigo);
							//Caso modo binario recebe codigo a ser apagado
							Apagar_Modificar_Acomodacoes_Bin("Arquivos/Acomodacoes.bin",Codigo,0,Modo);
							//Chama funcao de apagar modificar passando 0 por parametro indicando deleçao
						}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
							printf("Digite o codigo a ser apagado: ");
							scanf("%d",&Codigo);
							//Caso modo txt recebe codigo
							Apagar_Modificar("Arquivos/Acomodacoes.txt",Codigo,0,Modo,Dados_Acomodacoes);
							//Chama funcao de apagar modificar passando 0 por parametro indicando deleçao
						}
						
					}else{//Caso usuario nao tenha permissao mostra isso
							Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
						}
					break;
				default:
					return;
				break;
			}
		}
	}
}
void Ler_Acomodacoes_Txt(char Url[99]){
	ACOMODACOES Acomodacoes;
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

			fscanf(Arquivo,"%d",&Acomodacoes.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
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
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		if(Arquivo_Vazio==0){
			Vermelho("O Arquivo está vazio\n");
		}
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
}

void Ler_Acomodacoes_Memoria(ACOMODACOES Acomodacoes){
	//Recebe por parametro Struct de Acomodacoes
	printf("Codigo:\t\t\t%d\n",Acomodacoes.Codigo);
	printf("Descricao:\t\t%s\n",Acomodacoes.Descricao);
	printf("Televisao \t\t%d\n",Acomodacoes.Facilidades.Televisao);
	printf("Ar Condicionado 	%d\n",Acomodacoes.Facilidades.Ar_Condicionado);
	printf("Frigobar\t\t%d\n",Acomodacoes.Facilidades.Frigobar);
	printf("Banheira\t\t%d\n",Acomodacoes.Facilidades.Banheira);
	printf("Internet\t\t");
	if(Acomodacoes.Facilidades.Internet>0){
		Verde("Sim");
	}else{
		Vermelho("Não");
	}
	printf("\nCodigo da Categoria:\t%d\n",Acomodacoes.Cod_Categoria);
	printf("Codigo do Hotel:\t%d\n",Acomodacoes.Cod_Hotel);
	
	printf("____________________________________________________\n");
	//Mostra dados do Acomodacoes cadastrado na memoria
}

void Ler_Acomodacoes_Bin(char Url[99]){
	FILE *Arquivo;
	//Cria ponteiro de arquivo
	ACOMODACOES Acomodacoes;
	Arquivo = fopen(Url,"rb");
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
			Ler_Acomodacoes_Memoria(Acomodacoes);
			Arquivo_Vazio++;
			//Contador para verificar se o arquivo está em branco
		}
		fclose(Arquivo);
		if(Arquivo_Vazio==0){//Caso arquivo vazio
			Vermelho("O Arquivo está vazio\n");
		}
	}
}

void Gravar_Acomodacoes_Txt(char Url[99],ACOMODACOES *Acomodacoes){
	//Colocar com parametro não " " mas sim ;
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	Arquivo=fopen(Url,"a+");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	if(Acomodacoes->Cod_Categoria == 0 || Acomodacoes->Cod_Hotel == 0){
		if(Acomodacoes->Cod_Categoria == 0 ){
			Vermelho("Erro com Codigo da cateogira");
		}
		if( Acomodacoes->Cod_Hotel == 0 ){
			Vermelho("Erro com Codigo do Hotel");
		}
	}else{
		fprintf(Arquivo,"%d;",Acomodacoes->Codigo);
		fprintf(Arquivo,"%s;",Acomodacoes->Descricao);
		fprintf(Arquivo,"%d;",Acomodacoes->Facilidades.Televisao);
		fprintf(Arquivo,"%d;",Acomodacoes->Facilidades.Ar_Condicionado);
		fprintf(Arquivo,"%d;",Acomodacoes->Facilidades.Frigobar);
		fprintf(Arquivo,"%d;",Acomodacoes->Facilidades.Internet);
		fprintf(Arquivo,"%d;",Acomodacoes->Facilidades.Banheira);
		fprintf(Arquivo,"%d;",Acomodacoes->Cod_Categoria);
		fprintf(Arquivo,"%d;\n",Acomodacoes->Cod_Hotel);
			//Salva um struct por Linha

		fclose(Arquivo);
			//Fecha o o arquivo para evitar erros
		printf("\nArquivo Salvo em : %s",Url);
	}
}


void Gravar_Acomodacoes_Bin(char Url[99],ACOMODACOES *Acomodacoes){
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	
	Arquivo=fopen(Url,"ab");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	if(Acomodacoes->Cod_Categoria == 0 || Acomodacoes->Cod_Hotel == 0){
		if(Acomodacoes->Cod_Hotel == 0 ){
			Vermelho("Erro com Codigo do hotel");
		}
		if( Acomodacoes->Cod_Categoria == 0 ){
			Vermelho("Erro com Codigo da categoria");
		}
	}else{
		fwrite(Acomodacoes, sizeof(ACOMODACOES), 1, Arquivo); 
		//Primeiro argumento é um ponteiro .... como proceder
		printf("\nArquivo Salvo 'Acomodacoes.bin'");
	}

	fclose(Arquivo);
   		//Fecha o Arquivo Para evitar erro
   		//Mensagem de Confirmação
}
void Recebe_Dados_Acomodacoes(ACOMODACOES *Acomodacoes, int Modo_de_Abertura){
	//Funcao para receber dados passando recebe por parametro struct e modo de abertura
	printf("Descrição:");
	scanf("%s",Acomodacoes->Descricao);
	printf("Televisao:");
	scanf("%d",&Acomodacoes->Facilidades.Televisao);
	printf("Ar Condicionado:");
	scanf("%d",&Acomodacoes->Facilidades.Ar_Condicionado);
	printf("Frigobar:");
	scanf("%d",&Acomodacoes->Facilidades.Frigobar);
	printf("Internet:");
	scanf("%d",&Acomodacoes->Facilidades.Internet);
	printf("Banheira:");
	scanf("%d",&Acomodacoes->Facilidades.Banheira);
	//Recebe dados do usuario
	int Codigo_Categoria_A_Ser_Validado,Codigo_Hotel_A_Ser_Validado,Auxiliar=0,Sair_Da_Validacao = 0;
	//Codigos a serem validados
	while(Auxiliar == 0){//Repete loop enquanto auxiliar se mantem no 0
		printf("Codigo da Categoria:");
		scanf("%d",&Codigo_Categoria_A_Ser_Validado);
		//Recebe codida categoria
		if (Valida_Codigo_Categoria_Acomodacoes(Codigo_Categoria_A_Ser_Validado,Modo_de_Abertura))
		{
			//Chama funcao para validar e ja verifica se retornou verdadeiro 1
			Acomodacoes->Cod_Categoria = Codigo_Categoria_A_Ser_Validado;
			Auxiliar = 1;			
			//Coloca codigo da categoria na struct e auxiliar recebe 1 para sair do loop sem erros
		}else{
			Vermelho("\nCodigo não cadastrado\n");//Mostra que o codigo nao esta cadastrado
			printf("Deseja sair sem efetuar o cadastro?(1 - Sim | 2 - Não)");
			scanf("%d",&Sair_Da_Validacao);
			//Recebe valor para sair do loop sem efetuar cadastro
			if(Sair_Da_Validacao == 1){
				break;//sai do loop com auxiliar 0 indicando que nao efetuara o cadastro
			}
		}
	}
	if(Auxiliar==1){//Se auxiliar sair como 1 indica que validou
		Auxiliar = 0;//zera auxiliar
		while(Auxiliar == 0){//Loop enquanto auxiliar for 0
			printf("Codigo do Hotel:");
			scanf("%d",&Codigo_Hotel_A_Ser_Validado);
			//Recebe codigo do hotel a ser validado
			if (Valida_Codigo_Hotel(Codigo_Hotel_A_Ser_Validado,Modo_de_Abertura))
			{
				//Chamafuncao para validar codigo hotel e ja verifica retorno verdadeiro
				Acomodacoes->Cod_Hotel = Codigo_Hotel_A_Ser_Validado;	
				Auxiliar = 1;		
				//Joga codigo para struct e auxiliar recebe 1 indicando que validou com sucesso
			}else{
				Vermelho("\nCodigo não cadastrado\n\n");
				printf("Deseja sair sem efetuar o cadastro?(1 - Sim | 2 - Não)");
				scanf("%d",&Sair_Da_Validacao);
				//Caso contrario pergunta se deseja sair sem efetuar cadastro
				if(Sair_Da_Validacao == 1){
					break;//Se verdadeiro sai sem validar auxiliar
				}	
			}
		}
	}
}
int Valida_Codigo_Hotel(int Codigo, int Modo_de_Abertura){
		FILE *Arquivo;
		char Temporario[9999];
			//Ponteiro para Arquivo
		switch(Modo_de_Abertura){
			case Arquivo_Texto:
			Arquivo=fopen("Arquivos/Hotel.txt","r");
				//Abre o Arquivo em Modo Leitura
			if(Arquivo==NULL){
					//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
				Vermelho("Não há Hoteis\n");
				return -1;//retorna valor invalido
			}
			break;
			case Arquivo_Binario:
			Arquivo=fopen("Arquivos/Hotel.bin","rb");
				//Abre o Arquivo em Modo Leitura
			if(Arquivo==NULL){
					//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
				Vermelho("Não há Hoteis\n");
				return -1;		
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
			DADOS_HOTEL Hotel;
			Contador1=0;
			//Zera contador de Codigos
			while(!feof(Arquivo)){
				fread(&Hotel, sizeof(DADOS_HOTEL),1,Arquivo);
				//Le arquivo e passac para a struct
				if(feof(Arquivo)){
					break;
					//Se estiver no fim do arquivo sai do loop
				}
	
				Vetor_Codigos[Contador1] = Hotel.Codigo;
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
					//verifica se achou codigo e retonar 1 como verdadeiro
				}
			}
	return 0;
}

int Valida_Codigo_Categoria_Acomodacoes(int Codigo, int Modo_de_Abertura){
	FILE *Arquivo;
	char Temporario[9999];
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Codigo_Categoria.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há categorias cadastradas\n");
			return -1;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Codigo_Categoria.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há categorias cadastradas\n");
			return -1;		
		}
		break;
	}		

	int Contador1=0, Vetor_Codigos[9999];
		//Evita lixo de memoria
	if (Modo_de_Abertura == Arquivo_Texto)
	{
		while(!feof(Arquivo)){
			//equanto nao for fim do arquivo
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
		for (int i = 0; i < Contador1; ++i)
		{
			if (Codigo == Vetor_Codigos[i])
			{
				return 1;//Retorna true ao achar codigo
			}
		}
		return 0;
}

void Criar_Modificar_Acomodacoes(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];

	ACOMODACOES Acomodacoes;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela

	switch (Modo_de_Abertura){

		case Arquivo_Texto:

			strcpy(Url,"Arquivos/Acomodacoes.txt");
			 //Coloca o caminho na URL

			if (Manter_Codigo == 0)
			{
				Acomodacoes.Codigo = Valida_Codigo(Url,15,Arquivo_Texto,Dados_Acomodacoes);
				//Caso mantem codigo falso indica que vai criar nova acomodacao
			}else{
				Acomodacoes.Codigo = Manter_Codigo;
				//Indica que esta sendo editado
			}
			break;

		case Arquivo_Binario:

			strcpy(Url,"Arquivos/Acomodacoes.bin");
			 //Coloca o caminho na URL

			if (Manter_Codigo == 0)
			{
				Acomodacoes.Codigo = Valida_Codigo(Url,15,Arquivo_Binario,Dados_Acomodacoes);
				//Caso mantem codigo falso indica que vai criar nova acomodacao
			}else{
				Acomodacoes.Codigo = Manter_Codigo;
				//Indica que esta sendo editado
			}
			break;

		case Banco_De_Dados:
			//Não está implementado
			break;

		case Nuvem:
			//Não está implementado
			break;

	}
	Recebe_Dados_Acomodacoes(&Acomodacoes,Modo_de_Abertura);

	switch(Modo_de_Abertura){			
		case Arquivo_Texto:
			Gravar_Acomodacoes_Txt(Url,&Acomodacoes);
			//Grava em TXT
			break;

		case Arquivo_Binario:
			Gravar_Acomodacoes_Bin(Url,&Acomodacoes);
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


int Retorna_Campo_Struct_Acomodacoes(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Bin_ou_Txt(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[9999];
 	ACOMODACOES Acomodacoes;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
		Validador = Acomodacoes.Codigo;
		//Recebe dados de acomodacao salvos no binario
		if(feof(Arquivo)){
			return -1;
			break;
			//sai do loop retornando valor falso
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

void Apagar_Modificar_Acomodacoes_Bin(char Url[99], int Codigo,int Modificar,MODO Modo){
	if(Modo.Modo_de_Abertura == Arquivo_Binario){
		ACOMODACOES Acomodacoes;
		//Cria uma Variavel do tipo Dados_Acomodacoes
		FILE *Arquivo, *Arquivo_Temporario;
		//Cria 2ponteiros do tipo FILE
		Arquivo=fopen(Url,Modo.Leitura);
		//Abre o aqruivo principal em modo leitura
		Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
		//Abre o arquivo que sera apagado em modo de concatenacao
		int Campo_Struct = Retorna_Campo_Struct_Acomodacoes(Url, Codigo);
		//Variavel Campo_Struct recebe quantas structs teve que pular para achar o codigo
		if(Campo_Struct == -1){//Se for retornado -1 mostra que nao foi encotrado o codigo digitado
			Vermelho("O codigo digitado não foi encontrado");
		}else{
			if(Confirmacao()){//Se a confirmacao retornar 1 
				for(int i=1;i<Campo_Struct;i++){
					//Vai ate o campo do codigo
					fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
					fwrite(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo_Temporario); 
					//Escreve no Arquivo temporario
				}

				fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo); 
				//Le o arquivo Arquivo Binario e passa dados para struct
				if(Modificar==1){
					//Entra no modo Editar
					Criar_Modificar_Acomodacoes(Arquivo_Binario, Codigo);
					//Chama a funcao para editar o arquivo
					Verde("\nEditado com Sucesso");
					system("clear");
					//Limpa tela
				}
				//Se nao entrar no if so apaga o dado
				while(!feof(Arquivo)){
					//Vai ate o Final do Arquivo
					fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
					if(feof(Arquivo)){
						//Sai caso esteja no fim do arquivo;
						break;
					}
					fwrite(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo_Temporario); 
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

