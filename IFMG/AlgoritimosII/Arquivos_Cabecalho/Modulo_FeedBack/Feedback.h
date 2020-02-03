#ifndef _Feedback_
#define _Feedback_

/*
void MainFeedback();
int Tipo_Listagem_Hospede();
void Filtro_Hospede_Codigos(int Modo_Feedback);	
void Filtro_Hospede_Sexo(int Modo_Feedback);	
int Tipo_Listagem_Acomodacao();
void Filtro_Acomodacao_Codigos(int Modo_Feedback);	
void Gera_CSV_Acomodacoes_TXT(int Contador_Acomodacoes, int Codigos[], char Url[]);
void Gera_CSV_Acomodacoes_BIN(int Contador_Acomodacoes, int Codigos[], char Url[]);
void Filtro_Acomodacao_Data_Disponivel(int Modo_Feedback);
void Filtro_Acomodacao_CodCategoria(int Modo_Feedback);
int Tipo_Listagem_Reserva();
void Filtro_Reserva_Codigo_Acomodacao(int Modo_Feedback);
void Filtro_Reserva_Codigo_Hospede(int Modo_Feedback);
void Filtro_Produtos_Codigos(int Modo_Feedback);
void Filtro_Produtos_Codigos_Em_Estoque_Minimo(int Modo_Feedback);
int Tipo_Listagem_Produtos();
*/
void MainFeedback(){
	int Tipo_Listagem = MenuInicialFeedback();
	int Campo_Lista = MenuListagemFeedback();
	int Tipo_Hospede, Tipo_Acomodacoes, Tipo_Reservas, Tipo_Produtos; 
	if(Tipo_Listagem == Tela){
		switch(Campo_Lista){
			case Hospedes:
				Tipo_Hospede = Tipo_Listagem_Hospede();
				if(Tipo_Hospede == Codigo){
					Filtro_Hospede_Codigos(Tela);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;
				}else{
					Filtro_Hospede_Sexo(Tela);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;						
				}
			break;
			case Acomodacoes:
				Tipo_Acomodacoes = Tipo_Listagem_Acomodacao();
				if(Tipo_Acomodacoes == Codigo){
					Filtro_Acomodacao_Codigos(Tela);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;
				}else if(Tipo_Acomodacoes==Categoria){
					Filtro_Acomodacao_CodCategoria(Tela);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;	
				}else if(Tipo_Acomodacoes==Data_Disponivel){
					Filtro_Acomodacao_Data_Disponivel(Tela);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;	
				}
			break;
			case Reservas:
				Tipo_Reservas = Tipo_Listagem_Reserva();
				if(Tipo_Reservas == Cod_Acomodacao){
					Filtro_Reserva_Codigo_Acomodacao(Tela);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;
				}else if(Tipo_Reservas==Codigo_Hospede){
					Filtro_Reserva_Codigo_Hospede(Tela);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;	
				}else if(Tipo_Reservas==Data_Reservado){
					Filtro_Reserva_Data(Tela);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;	
				}
			break;
			case Produtos:
				Tipo_Produtos = Tipo_Listagem_Produtos();
				if(Tipo_Produtos == Consumo){
					Filtro_Produtos_Codigos(Tela);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;
				}else if(Tipo_Produtos==Estoque_Minimo){
					Filtro_Produtos_Codigos_Em_Estoque_Minimo(Tela);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;	
				}
			break;
		}
	}else if(Tipo_Listagem == Csv){
		switch(Campo_Lista){
			case Hospedes:
				Tipo_Hospede = Tipo_Listagem_Hospede();
				if(Tipo_Hospede == Codigo){
					Filtro_Hospede_Codigos(Csv);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;
				}else{
					Filtro_Hospede_Sexo(Csv);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;	
				}
			break;
			case Acomodacoes:
				Tipo_Acomodacoes = Tipo_Listagem_Acomodacao();
				if(Tipo_Acomodacoes == Codigo){
					Filtro_Acomodacao_Codigos(Csv);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;
				}else if(Tipo_Acomodacoes==Categoria){
					Filtro_Acomodacao_CodCategoria(Csv);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;	
				}else if(Tipo_Acomodacoes==Data_Disponivel){
					Filtro_Acomodacao_Data_Disponivel(Csv);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;	
				}
			break;
			case Reservas:
				Tipo_Reservas = Tipo_Listagem_Reserva();
				if(Tipo_Reservas == Cod_Acomodacao){
					Filtro_Reserva_Codigo_Acomodacao(Csv);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;
				}else if(Tipo_Reservas==Codigo_Hospede){
					Filtro_Reserva_Codigo_Hospede(Csv);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;	
				}else if(Tipo_Reservas==Data_Reservado){
					Filtro_Reserva_Data(Csv);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;	
				}
			break;
			case Produtos:
				Tipo_Produtos = Tipo_Listagem_Produtos();
				if(Tipo_Produtos == Consumo){
					Filtro_Produtos_Codigos(Csv);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;
				}else if(Tipo_Produtos==Estoque_Minimo){
					Filtro_Produtos_Codigos_Em_Estoque_Minimo(Csv);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;	
				}
			break;
		}
	}
}

int Tipo_Listagem_Reserva(){
	//Funcao para saber o filtro que o usuario deseja utilizar
	int Filtro;
	do{
		printf("Digite 1 para filtrar por codigo acomodacao e 2 para filtar por codigo hospede e 3 para filtrar por data reservado");
		scanf("%d",&Filtro);
		if(Filtro < 1 || Filtro > 3){
			Vermelho("Digite 1 opcao valida\n");
		}
	}while(Filtro < 1 || Filtro > 3);
	return Filtro;
	//Retorna o filtro
}

int Tipo_Listagem_Produtos(){
	//Funcao para saber o filtro que o usuario deseja utilizar
	int Filtro;
	do{
		printf("Digite 1 para filtrar por produtos de consumo e 2 para filtar por produtos em estoque minimo");
		scanf("%d",&Filtro);
		if(Filtro < 1 || Filtro > 3){
			Vermelho("Digite 1 opcao valida\n");
		}
	}while(Filtro < 1 || Filtro > 3);
	return Filtro;
	//Retorna o filtro
}

int Tipo_Listagem_Acomodacao(){
	//Funcao para saber o filtro que o usuario deseja utilizar
	int Filtro;
	do{
		printf("Digite 1 para filtrar por codigos e 2 para filtar por categoria e 3 para filtrar por data disponivel");
		scanf("%d",&Filtro);
		if(Filtro < 1 || Filtro > 3){
			Vermelho("Digite 1 opcao valida\n");
		}
	}while(Filtro < 1 || Filtro > 3);
	return Filtro;
	//Retorna o filtro
}

int Tipo_Listagem_Hospede(){
	//Funcao para saber o filtro que o usuario deseja utilizar
	int Filtro;
	do{
		printf("Digite 1 para filtrar por codigos e 2 para filtar por sexo ");
		scanf("%d",&Filtro);
		if(Filtro < 1 || Filtro > 2){
			Vermelho("Digite 1 opcao valida\n");
		}
	}while(Filtro < 1 || Filtro > 2);
	return Filtro;
	//Retorna o filtro
}

void Filtro_Produtos_Codigos_Em_Estoque_Minimo(int Modo_Feedback){
	//Funcao para realizar filtro por codigos de hospede
	int Modo_Abertura = Configuracoes();
	int Codigo_Inicial = 0;
	int Codigo_Final = 0;
	//Variaveis para receber o codigo inicial e final e fazer o range entre eles
	Verde("Digite o range de codigos que sera printado:\n");
	do{
		Verde("Codigo Inicial = ");
		scanf("%d",&Codigo_Inicial);
		Verde("Codigo Final = ");
		scanf("%d",&Codigo_Final);
		if(Codigo_Inicial == 0 || Codigo_Final == 0 ){
			Vermelho("O codigo inicial e final não pode ser 0 digite um valido");
		}else if(Codigo_Final < Codigo_Inicial){
			Vermelho("O codigo final não pode ser menor que o inicial");
		}
		//Mostra mensagem de erros ao usuario
	}while(Codigo_Inicial == 0 || Codigo_Final == 0 || Codigo_Final < Codigo_Inicial);
	//Loop que repete ate usuario digitiar valores validos para o range de codigos 
	int Quantidade_Codigos = Codigo_Final - Codigo_Inicial + 1;
	int Codigos[Quantidade_Codigos];
	int Contador_Codigos = 0;
	int Indice_Iguais = 0;
	//Vetor de codigos com a quantidade exata do range de codigos que foi passado, e contador de condigos
	for(int i = Codigo_Inicial; i <= Codigo_Final; i++){
		Codigos[Contador_Codigos] = i;
		Contador_Codigos++;
	}
	if(Modo_Abertura == Arquivo_Texto){
	//Caso modo de abertura seja TXT
	char Url[Tamanho2],Temporario[Tamanho2];
	sprintf(Url,"Arquivos/Produtos.txt");
	//Declara Array com a url
	PRODUTOS Produtos;
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
			fscanf(Arquivo,"%d",&Produtos.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			//Pula o Ponteiro para o proximo caractere
			for(int i = 0;i < Quantidade_Codigos; i++){
				if(Codigos[i] == Produtos.Codigo){
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
					fscanf(Arquivo,"%u",&Produtos.Estoque);
						//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%u",&Produtos.Estoque_Minimo);
						//Expreção Regular
					getc(Arquivo);
					if(Produtos.Estoque_Minimo == Produtos.Estoque){
							//Pula o Ponteiro para o proximo caractere
						fscanf(Arquivo,"%[^;]s",Produtos.Descricao);
						//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
						//Expreção Regular
						getc(Arquivo);
							//Pula o Ponteiro para o proximo caractere
						fscanf(Arquivo,"%f",&Produtos.Preco_Custo);
							//Expreção Regular
						getc(Arquivo);
						fscanf(Arquivo,"%f",&Produtos.Preco_Venda);
							//Expreção Regular
						getc(Arquivo);
						fscanf(Arquivo,"%d",&Produtos.Cod_Hotel);
							//Expreção Regular
						getc(Arquivo);
						getc(Arquivo);
						//Pula o Ponteiro para o proximo caracte (pula o \n)
						if(Modo_Feedback == Tela){
							Ler_Produtos_Memoria(Produtos);
						}else if(Modo_Feedback == Csv){
							Gravar_Produtos_Txt("Arquivos/Produtos.csv",&Produtos);	
							//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
							system("clear");
							printf("\n");
						}
					}
				}else{
					fscanf(Arquivo,"%[^\n]s",Temporario);
					getc(Arquivo);
				}
			}
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
	}else{
		//Caso modo de abertura seja BIN
		FILE *Arquivo;
		//Cria ponteiro de arquivo
		PRODUTOS Produtos;
		char Url[Tamanho2];
		sprintf(Url,"Arquivos/Produtos.bin");
		Arquivo = fopen(Url,"rb");
		int Arquivo_Vazio=0;
		if(Arquivo == NULL){
			Vermelho("\nNao foi possivel abrir o arquivo!");
		}else{
			while(!feof(Arquivo)){
				fread(&Produtos, sizeof(PRODUTOS),1,Arquivo);
				if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
				}
				for(int i = 0;i < Quantidade_Codigos; i++){
					if(Codigos[i] == Produtos.Codigo){
						if(Produtos.Estoque_Minimo == Produtos.Estoque){
							if(Modo_Feedback == Tela){
								Ler_Produtos_Memoria(Produtos);
							}else if(Modo_Feedback == Csv){
								Gravar_Produtos_Txt("Arquivos/Produtos.csv",&Produtos);	
								system("clear");
								printf("\n");
							}
						}	
					}
				}
			}
			fclose(Arquivo);	
		}
	}
}

void Filtro_Produtos_Codigos(int Modo_Feedback){
	//Funcao para realizar filtro por codigos de hospede
	int Modo_Abertura = Configuracoes();
	int Codigo_Inicial = 0;
	int Codigo_Final = 0;
	//Variaveis para receber o codigo inicial e final e fazer o range entre eles
	Verde("Digite o range de codigos que sera printado:\n");
	do{
		Verde("Codigo Inicial = ");
		scanf("%d",&Codigo_Inicial);
		Verde("Codigo Final = ");
		scanf("%d",&Codigo_Final);
		if(Codigo_Inicial == 0 || Codigo_Final == 0 ){
			Vermelho("O codigo inicial e final não pode ser 0 digite um valido");
		}else if(Codigo_Final < Codigo_Inicial){
			Vermelho("O codigo final não pode ser menor que o inicial");
		}
		//Mostra mensagem de erros ao usuario
	}while(Codigo_Inicial == 0 || Codigo_Final == 0 || Codigo_Final < Codigo_Inicial);
	//Loop que repete ate usuario digitiar valores validos para o range de codigos 
	int Quantidade_Codigos = Codigo_Final - Codigo_Inicial + 1;
	int Codigos[Quantidade_Codigos];
	int Contador_Codigos = 0;
	int Indice_Iguais = 0;
	//Vetor de codigos com a quantidade exata do range de codigos que foi passado, e contador de condigos
	for(int i = Codigo_Inicial; i <= Codigo_Final; i++){
		Codigos[Contador_Codigos] = i;
		Contador_Codigos++;
	}
	if(Modo_Abertura == Arquivo_Texto){
	//Caso modo de abertura seja TXT
	char Url[Tamanho2],Temporario[Tamanho2];
	sprintf(Url,"Arquivos/Produtos.txt");
	//Declara Array com a url
	PRODUTOS Produtos;
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
			fscanf(Arquivo,"%d",&Produtos.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			//Pula o Ponteiro para o proximo caractere
			for(int i = 0;i < Quantidade_Codigos; i++){
				if(Codigos[i] == Produtos.Codigo){
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
					fscanf(Arquivo,"%u",&Produtos.Estoque);
						//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%u",&Produtos.Estoque_Minimo);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Produtos.Descricao);
					//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
					//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%f",&Produtos.Preco_Custo);
						//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%f",&Produtos.Preco_Venda);
						//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%d",&Produtos.Cod_Hotel);
						//Expreção Regular
					getc(Arquivo);
					getc(Arquivo);
					//Pula o Ponteiro para o proximo caracte (pula o \n)
					if(Modo_Feedback == Tela){
						Ler_Produtos_Memoria(Produtos);
					}else if(Modo_Feedback == Csv){
						Gravar_Produtos_Txt("Arquivos/Produtos.csv",&Produtos);	
						//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
						system("clear");
						printf("\n");

					}
					
				}else{
					fscanf(Arquivo,"%[^\n]s",Temporario);
					getc(Arquivo);
				}
			}
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
	}else{
		//Caso modo de abertura seja BIN
		FILE *Arquivo;
		//Cria ponteiro de arquivo
		PRODUTOS Produtos;
		char Url[Tamanho2];
		sprintf(Url,"Arquivos/Produtos.bin");
		Arquivo = fopen(Url,"rb");
		int Arquivo_Vazio=0;
		if(Arquivo == NULL){
			Vermelho("\nNao foi possivel abrir o arquivo!");
		}else{
			while(!feof(Arquivo)){
				fread(&Produtos, sizeof(PRODUTOS),1,Arquivo);
				if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
				}
				for(int i = 0;i < Quantidade_Codigos; i++){
					if(Codigos[i] == Produtos.Codigo){
						if(Modo_Feedback == Tela){
							Ler_Produtos_Memoria(Produtos);
						}else if(Modo_Feedback == Csv){
							
							Gravar_Produtos_Txt("Arquivos/Produtos.csv",&Produtos);	
							system("clear");
							printf("\n");
						}
					}
				}
			}
			fclose(Arquivo);	
		}
	}
}

void Filtro_Reserva_Codigo_Acomodacao(int Modo_Feedback){
	//Funcao para realizar filtro por codigos de hospede
	int Modo_Abertura = Configuracoes();
	int Codigo_Acomodacao = 0;
	FILE *Arquivo;
	//Variaveis para receber o codigo inicial e final e fazer o range entre eles
	do{
		Verde("Codigo Acomodação = ");
		scanf("%d",&Codigo_Acomodacao);
		if(Codigo_Acomodacao <= 0){
			Vermelho("O codigo da acomodação não pode ser menor ou igual a 0");
		}
		//Mostra mensagem de erros ao usuario
	}while(Codigo_Acomodacao <= 0);
	//Loop que repete ate usuario digitiar valores validos para o range de codigos 
	if(Modo_Abertura == Arquivo_Texto){
		//Caso modo de abertura seja TXT
		char Url[Tamanho2],Temporario[Tamanho2];
		sprintf(Url,"Arquivos/Reserva.txt");
		//Declara Array com a url
		RESERVA Reserva;
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
				fscanf(Arquivo,"%d",&Reserva.Codigo);
					//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
					//Expreção Regular
				getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
				fscanf(Arquivo,"%[^;]s",Reserva.Nome_Hospede);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
				//Expreção Regular
				getc(Arquivo);
					//Pula o Ponteiro para o proximo caractere
				fscanf(Arquivo,"%d",&Reserva.Codigo_Hospede);
					//Expreção Regular
				getc(Arquivo);
					//Pula o Ponteiro para o proximo caractere
				fscanf(Arquivo,"%d",&Reserva.Cod_Acomodacao);
					//Expreção Regular
				getc(Arquivo);
				if(Codigo_Acomodacao== Reserva.Cod_Acomodacao){
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Entrada.Dia);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Entrada.Mes);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Entrada.Ano);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Saida.Dia);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Saida.Mes);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Saida.Ano);
						//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%f",&Reserva.Valor_Fatura);
						//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%d",&Reserva.Pago);
					//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%f",&Reserva.Valor_Conta);
					//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%d",&Reserva.Modo_Pagamento);
					getc(Arquivo);
					getc(Arquivo);
					//Pula o Ponteiro para o proximo caracte (pula o \n)
					if(Modo_Feedback == Tela){
						Ler_Reserva_Memoria(Reserva);
					}else if(Modo_Feedback == Csv){
						Gravar_Reserva_Txt("Arquivos/Reserva.csv",&Reserva);	
						//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
							system("clear");
							printf("\n");
					}
				}else{
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
					fscanf(Arquivo,"%[^\n]s",Temporario);
					getc(Arquivo);
				}
			}while(!feof(Arquivo));
				//Entra no loop se não estiver apontando para o final do arquivo;
			fclose(Arquivo);
		}
	}else if(Modo_Abertura == Arquivo_Binario){
		RESERVA Reserva;
		char Url[Tamanho2],Temporario[Tamanho2];
		sprintf(Url,"Arquivos/Reserva.bin");
		Arquivo=fopen(Url,"rb");
		do{
			fread(&Reserva, sizeof(RESERVA),1,Arquivo);
			if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
			}
			if(Codigo_Acomodacao == Reserva.Cod_Acomodacao){	
				if(Modo_Feedback == Tela){
					Ler_Reserva_Memoria(Reserva);
				}else if(Modo_Feedback == Csv){
					Gravar_Reserva_Txt("Arquivos/Reserva.csv",&Reserva);	
					//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
						system("clear");
							printf("\n");
				}
			}
			
		}while(!feof(Arquivo));
		fclose(Arquivo);
	}
}

void Filtro_Reserva_Codigo_Hospede(int Modo_Feedback){
	//Funcao para realizar filtro por codigos de hospede
	int Modo_Abertura = Configuracoes();
	int Codigo_Hospede = 0;
	FILE *Arquivo;
	//Variaveis para receber o codigo inicial e final e fazer o range entre eles
	do{
		Verde("Codigo Hospede = ");
		scanf("%d",&Codigo_Hospede);
		if(Codigo_Hospede <= 0){
			Vermelho("O codigo do Hospede não pode ser menor ou igual a 0");
		}
		//Mostra mensagem de erros ao usuario
	}while(Codigo_Hospede <= 0);
	//Loop que repete ate usuario digitiar valores validos para o range de codigos 
	if(Modo_Abertura == Arquivo_Texto){
		//Caso modo de abertura seja TXT
		char Url[Tamanho2],Temporario[Tamanho2];
		sprintf(Url,"Arquivos/Reserva.txt");
		//Declara Array com a url
		RESERVA Reserva;
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
				fscanf(Arquivo,"%d",&Reserva.Codigo);
					//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
					//Expreção Regular
				getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
				fscanf(Arquivo,"%[^;]s",Reserva.Nome_Hospede);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
				//Expreção Regular
				getc(Arquivo);
					//Pula o Ponteiro para o proximo caractere
				fscanf(Arquivo,"%d",&Reserva.Codigo_Hospede);
					//Expreção Regular
				getc(Arquivo);
					//Pula o Ponteiro para o proximo caractere
				if(Codigo_Hospede== Reserva.Codigo_Hospede){
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
					fscanf(Arquivo,"%d",&Reserva.Cod_Acomodacao);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Entrada.Dia);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Entrada.Mes);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Entrada.Ano);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Saida.Dia);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Saida.Mes);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Reserva.Data_Saida.Ano);
						//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%f",&Reserva.Valor_Fatura);
						//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%d",&Reserva.Pago);
					//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%f",&Reserva.Valor_Conta);
					//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%d",&Reserva.Modo_Pagamento);
					getc(Arquivo);
					getc(Arquivo);
					//Pula o Ponteiro para o proximo caracte (pula o \n)
					if(Modo_Feedback == Tela){
						Ler_Reserva_Memoria(Reserva);
					}else if(Modo_Feedback == Csv){
						Gravar_Reserva_Txt("Arquivos/Reserva.csv",&Reserva);	
						//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
							system("clear");
							printf("\n");
					}
				}else{
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
					fscanf(Arquivo,"%[^\n]s",Temporario);
					getc(Arquivo);
				}
			}while(!feof(Arquivo));
				//Entra no loop se não estiver apontando para o final do arquivo;
			fclose(Arquivo);
		}
	}else if(Modo_Abertura == Arquivo_Binario){
		RESERVA Reserva;
		char Url[Tamanho2],Temporario[Tamanho2];
		sprintf(Url,"Arquivos/Reserva.bin");
		Arquivo=fopen(Url,"rb");
		do{
			fread(&Reserva, sizeof(RESERVA),1,Arquivo);
			if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
			}
			if(Codigo_Hospede == Reserva.Codigo_Hospede){	
				if(Modo_Feedback == Tela){
					Ler_Reserva_Memoria(Reserva);
				}else if(Modo_Feedback == Csv){
					Gravar_Reserva_Txt("Arquivos/Reserva.csv",&Reserva);	
					//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
						system("clear");
							printf("\n");
				}
			}
			
		}while(!feof(Arquivo));
		fclose(Arquivo);
	}
}

void Filtro_Reserva_Data(int Modo_Feedback){
	//Funcao para filtro de reserva com base em determinada data
	int Modo_Abertura = Configuracoes();
	PESQUISA Pesquisa;
	DATA Data;
	RESERVA Reserva;
	int Tamanho_Acomodacoes_disponiveis = 0, loop = 1;
	int Acomodacao_Disponiveis[999], Acomodacao_Indisponiveis[9999];
	char Arquivo_Fluxo[999];
	int Contador_Acomodacao_Indisponiveis = 0;
	//Declara variaveis para bom funcionamento da funcao
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
	//Loop que repete equanto o não for digitado uma data valida
	FILE *Arquivo;
	if(Modo_Abertura == Arquivo_Binario){
		Arquivo = fopen("Arquivos/Reserva.bin", "rb");
		while(loop){
			fread(&Reserva, sizeof(RESERVA),1,Arquivo);
			//Le struct do binario
			if(feof(Arquivo)){
				loop = 0;
				break;
				//Se chega no fim do arquivo sai do loop
			}else{
				//Se nao executa funcao
				if(Reserva.Data_Entrada.Ano == Pesquisa.Data_Entrada.Ano && Reserva.Data_Entrada.Mes == Pesquisa.Data_Entrada.Mes){
					if(Reserva.Data_Saida.Dia >= Pesquisa.Data_Entrada.Dia && Reserva.Data_Saida.Dia <= Pesquisa.Data_Saida.Dia){
						//Verifica se ano e mes sao iguais ao passado e se a data esta entre a a lida do arquivo
						if(Modo_Feedback == Tela){
							//Caso modo de printar na tela
								Ler_Reserva_Memoria(Reserva);
								//Chama funcao para ler da memoria e mostrar na tela
						}else{
								Gravar_Reserva_Txt("Arquivos/Reserva.csv",&Reserva);
								system("clear");	
						}
					}else if(Reserva.Data_Entrada.Dia >= Pesquisa.Data_Entrada.Dia && Reserva.Data_Entrada.Dia <= Pesquisa.Data_Saida.Dia){
						if(Modo_Feedback == Tela){
							Ler_Reserva_Memoria(Reserva);
						}else{
							Gravar_Reserva_Txt("Arquivos/Reserva.csv",&Reserva);	
							system("clear");
						}
					}else if(Reserva.Data_Entrada.Dia <= Pesquisa.Data_Entrada.Dia && Reserva.Data_Saida.Dia >= Pesquisa.Data_Saida.Dia){
						if(Modo_Feedback == Tela){
							Ler_Reserva_Memoria(Reserva);
						}else{
							Gravar_Reserva_Txt("Arquivos/Reserva.csv",&Reserva);	
							system("clear");
						}
					}
					//Faz o mesmo que no primeiro if
				}
			}
		}
	}else{
		//Caso arquivo TXT 
		Arquivo = fopen("Arquivos/Reserva.txt", "r");
		//Abre arquivo TXT de Reserva
		while(loop){
			fscanf(Arquivo,"%d",&Reserva.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			fscanf(Arquivo,"%[^;]s",Reserva.Nome_Hospede);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
				//Expreção Regular
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%d",&Reserva.Codigo_Hospede);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%d",&Reserva.Cod_Acomodacao);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%u",&Reserva.Data_Entrada.Dia);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
			fscanf(Arquivo,"%u",&Reserva.Data_Entrada.Mes);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
			fscanf(Arquivo,"%u",&Reserva.Data_Entrada.Ano);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%u",&Reserva.Data_Saida.Dia);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
			fscanf(Arquivo,"%u",&Reserva.Data_Saida.Mes);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
			fscanf(Arquivo,"%u",&Reserva.Data_Saida.Ano);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%u",&Reserva.Data_Vencimento_Fatura.Dia);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
			fscanf(Arquivo,"%u",&Reserva.Data_Vencimento_Fatura.Mes);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
			fscanf(Arquivo,"%u",&Reserva.Data_Vencimento_Fatura.Ano);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%f",&Reserva.Valor_Fatura);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%d",&Reserva.Pago);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%f",&Reserva.Valor_Conta);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%d",&Reserva.Modo_Pagamento);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			//FAZER METODO PARA LER MATRIZ NO TXT
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o \n)
			if(feof(Arquivo)){
				loop = 0;
				break;
				//Se chega no fim do arquivo sai do loop
			}else{
				//Se nao executa funcao
				if(Reserva.Data_Entrada.Ano == Pesquisa.Data_Entrada.Ano && Reserva.Data_Entrada.Mes == Pesquisa.Data_Entrada.Mes){
					if(Reserva.Data_Saida.Dia >= Pesquisa.Data_Entrada.Dia && Reserva.Data_Saida.Dia <= Pesquisa.Data_Saida.Dia){
						//Verifica se ano e mes sao iguais ao passado e se a data esta entre a a lida do arquivo
						if(Modo_Feedback == Tela){
							//Caso modo de printar na tela
								Ler_Reserva_Memoria(Reserva);
								//Chama funcao para ler da memoria e mostrar na tela
						}else{
								
								Gravar_Reserva_Txt("Arquivos/Reserva.csv",&Reserva);
								system("clear");	
						}
					}else if(Reserva.Data_Entrada.Dia >= Pesquisa.Data_Entrada.Dia && Reserva.Data_Entrada.Dia <= Pesquisa.Data_Saida.Dia){
						if(Modo_Feedback == Tela){
							Ler_Reserva_Memoria(Reserva);
						}else{
							
							Gravar_Reserva_Txt("Arquivos/Reserva.csv",&Reserva);	
							system("clear");
						}
					}else if(Reserva.Data_Entrada.Dia <= Pesquisa.Data_Entrada.Dia && Reserva.Data_Saida.Dia >= Pesquisa.Data_Saida.Dia){
						if(Modo_Feedback == Tela){
							Ler_Reserva_Memoria(Reserva);
						}else{
							
							Gravar_Reserva_Txt("Arquivos/Reserva.csv",&Reserva);	
							system("clear");
						}
					}
					//Faz o mesmo que no primeiro if
				}
			}
		}
	}
}

void Filtro_Acomodacao_Codigos(int Modo_Feedback){
	//Funcao para realizar filtro por codigos de hospede
	int Modo_Abertura = Configuracoes();
	int Codigo_Inicial = 0;
	int Codigo_Final = 0;
	//Variaveis para receber o codigo inicial e final e fazer o range entre eles
	Verde("Digite o range de codigos que sera printado:\n");
	do{
		Verde("Codigo Inicial = ");
		scanf("%d",&Codigo_Inicial);
		Verde("Codigo Final = ");
		scanf("%d",&Codigo_Final);
		if(Codigo_Inicial == 0 || Codigo_Final == 0 ){
			Vermelho("O codigo inicial e final não pode ser 0 digite um valido");
		}else if(Codigo_Final < Codigo_Inicial){
			Vermelho("O codigo final não pode ser menor que o inicial");
		}
		//Mostra mensagem de erros ao usuario
	}while(Codigo_Inicial == 0 || Codigo_Final == 0 || Codigo_Final < Codigo_Inicial);
	//Loop que repete ate usuario digitiar valores validos para o range de codigos 
	int Quantidade_Codigos = Codigo_Final - Codigo_Inicial + 1;
	int Codigos[Quantidade_Codigos];
	int Contador_Codigos = 0;
	int Indice_Iguais = 0;
	//Vetor de codigos com a quantidade exata do range de codigos que foi passado, e contador de condigos
	for(int i = Codigo_Inicial; i <= Codigo_Final; i++){
		Codigos[Contador_Codigos] = i;
		Contador_Codigos++;
	}
	if(Modo_Abertura == Arquivo_Texto){
	//Caso modo de abertura seja TXT
	char Url[Tamanho2],Temporario[Tamanho2];
	sprintf(Url,"Arquivos/Acomodacoes.txt");
	//Declara Array com a url
	ACOMODACOES Acomodacoes;
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
			fscanf(Arquivo,"%d",&Acomodacoes.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			//Pula o Ponteiro para o proximo caractere
			for(int i = 0;i < Quantidade_Codigos; i++){
				if(Codigos[i] == Acomodacoes.Codigo){
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
					fscanf(Arquivo,"%[^;]s",Acomodacoes.Descricao);
					//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
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
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Cod_Hotel);
						//Expreção Regular
					getc(Arquivo);
					getc(Arquivo);
					//Pula o Ponteiro para o proximo caracte (pula o \n)
					if(Modo_Feedback == Tela){
						Ler_Acomodacoes_Memoria(Acomodacoes);
					}else if(Modo_Feedback == Csv){
						
						Gravar_Acomodacoes_Txt("Arquivos/Acomodacoes.csv",&Acomodacoes);	
						//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
							system("clear");
							printf("\n");
					}
					
				}else{
					fscanf(Arquivo,"%[^\n]s",Temporario);
					getc(Arquivo);
				}
			}
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
	}else{
		//Caso modo de abertura seja BIN
		FILE *Arquivo;
		//Cria ponteiro de arquivo
		ACOMODACOES Acomodacoes;
		char Url[Tamanho2];
		sprintf(Url,"Arquivos/Acomodacoes.bin");
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
				for(int i = 0;i < Quantidade_Codigos; i++){
					if(Codigos[i] == Acomodacoes.Codigo){
						if(Modo_Feedback == Tela){
							Ler_Acomodacoes_Memoria(Acomodacoes);
						}else if(Modo_Feedback == Csv){
							
							Gravar_Acomodacoes_Txt("Arquivos/Acomodacoes.csv",&Acomodacoes);	
							system("clear");
							printf("\n");
						}
					}
				}
			}
			fclose(Arquivo);	
		}
	}
}

void Gera_CSV_Acomodacoes_TXT(int Contador_Acomodacoes, int Codigos[], char Url[]){
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
					
					Gravar_Acomodacoes_Txt("Arquivos/Acomodacoes.csv",&Acomodacoes);	
					system("clear");
					printf("\n");
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
	}
	fclose(Arquivo);
	//Fecha o Arquivo;
}
void Gera_CSV_Acomodacoes_BIN(int Contador_Acomodacoes, int Codigos[], char Url[]){
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
					
					Gravar_Acomodacoes_Txt("Arquivos/Acomodacoes.csv",&Acomodacoes);	
					system("clear");
					printf("\n");
				}
			}
		}while(!feof(Arquivo));
		//Entra no loop se não estiver apontando para o final do arquivo;
	}

	fclose(Arquivo);
	//Fecha o Arquivo;
}


void Filtro_Acomodacao_Data_Disponivel(int Modo_Feedback){
	int Modo_Abertura=Configuracoes();
	PESQUISA Pesquisa;
	DATA Data;
	int Tamanho_Acomodacoes_disponiveis = 0;
	int Acomodacao_Disponiveis[999], Acomodacao_Indisponiveis[9999];
	char Arquivo_Fluxo[999];
	int Contador_Acomodacao_Indisponiveis = 0;
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
	if(Modo_Feedback == Tela){//Caso modo de feedback seja na tela
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
	}else{//Caso seja no csv
		if(Modo_Abertura == Arquivo_Texto){
			Tamanho_Acomodacoes_disponiveis = Todas_Acomodacoes_TXT("Arquivos/Acomodacoes.txt",Acomodacao_Disponiveis,Acomodacao_Indisponiveis,Contador_Acomodacao_Indisponiveis);
			Gera_CSV_Acomodacoes_TXT(Tamanho_Acomodacoes_disponiveis, Acomodacao_Disponiveis, "Arquivos/Acomodacoes.txt");
		}else if(Modo_Abertura == Arquivo_Binario){
			Tamanho_Acomodacoes_disponiveis = Todas_Acomodacoes_BIN("Arquivos/Acomodacoes.bin",Acomodacao_Disponiveis,Acomodacao_Indisponiveis,Contador_Acomodacao_Indisponiveis);
			Gera_CSV_Acomodacoes_BIN(Tamanho_Acomodacoes_disponiveis, Acomodacao_Disponiveis, "Arquivos/Acomodacoes.bin");
		}
	}
}

void Filtro_Acomodacao_CodCategoria(int Modo_Feedback){
	//Funcao para realizar filtro por codigos de hospede
	int Modo_Abertura = Configuracoes();
	int Codigo_Categoria = 0;
	do{
		Verde("Digite o codigo da categoria que deseja gerar o feedback\n");
		scanf("%d",&Codigo_Categoria);
		if(Codigo_Categoria < 1 ){
			Vermelho("Codigo de categoria não pode ser menor que 1");
		}
		//Mostra mensagem de erros ao usuario
	}while(Codigo_Categoria < 1);
	//Loop que repete ate usuario digitiar valores validos para o range de codigos 
	int Quantidade_Codigos = Tamanho2;
	int Codigos[Quantidade_Codigos];
	int Contador_Codigos = 0;
	int Indice_Iguais = 0;
	int Auxiliar = 0;
	//Vetor de codigos com a quantidade exata do range de codigos que foi passado, e contador de condigos
	
	if(Modo_Abertura == Arquivo_Texto){
	//Caso modo de abertura seja TXT
	char Url[Tamanho2],Temporario[Tamanho2];
	sprintf(Url,"Arquivos/Acomodacoes.txt");
	//Declara Array com a url
	ACOMODACOES Acomodacoes;
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
			fscanf(Arquivo,"%d",&Acomodacoes.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
			//Expreção Regular
			getc(Arquivo);
			fscanf(Arquivo,"%[^;]s",Acomodacoes.Descricao);
			//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
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
				//Pula o Ponteiro para o proximo caractere
			Auxiliar = 0;
			//Zera auxiliar para ter certeza que não vai ter problemas
			if(Acomodacoes.Cod_Categoria == Codigo_Categoria){
				Auxiliar = 1;
			}
			//Se codigo da categoria lido for igual ao codigo da categoria passado auxiliar recebe 1 indicando que ira mostrar a acomodacao
				
			//Bloco de IFs para comparar qual sexo foi selecionado no inicio e verificar se no arquivo tem o sexo desejado, caso tenha habilita auxiliar com 1
			if(Auxiliar == 1){//Se auxiliar 1 le restante dos dados e chama funcao para gerar CSV ou printar na Tela
				fscanf(Arquivo,"%d",&Acomodacoes.Cod_Hotel);
				//Expreção Regular
				getc(Arquivo);
				getc(Arquivo);
				if(Modo_Feedback == Tela){
					Ler_Acomodacoes_Memoria(Acomodacoes);
				}else if(Modo_Feedback == Csv){
					
					Gravar_Acomodacoes_Txt("Arquivos/Acomodacoes.csv",&Acomodacoes);	
					system("clear");
					printf("\n");
					//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
				}
			}else{
				Auxiliar = 0;
				fscanf(Arquivo,"%[^\n]s",Temporario);
				getc(Arquivo);
				//Pula resto dos campos pois nao interessa
			}
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		
	}
	fclose(Arquivo);
		//Fecha o Arquivo;
	}else{
		//Caso modo de abertura seja BIN
		FILE *Arquivo;
		//Cria ponteiro de arquivo
		ACOMODACOES Acomodacoes;
		char Url[Tamanho2];
		sprintf(Url,"Arquivos/Acomodacoes.bin");
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
				Auxiliar = 0;
				//Zera auxiliar para ter certeza que não vai ter problemas
				if(Acomodacoes.Cod_Categoria == Codigo_Categoria){
					Auxiliar = 1;
				}
				if(Auxiliar == 1){
					if(Modo_Feedback == Tela){
						Ler_Acomodacoes_Memoria(Acomodacoes);
					}else if(Modo_Feedback == Csv){
						Gravar_Acomodacoes_Txt("Arquivos/Acomodacoes.csv",&Acomodacoes);	
						system("clear");
						printf("\n");
					}
				}	
			}
			fclose(Arquivo);
		}
	}
}

void Filtro_Hospede_Codigos(int Modo_Feedback){
	//Funcao para realizar filtro por codigos de hospede
	int Modo_Abertura = Configuracoes();
	int Codigo_Inicial = 0;
	int Codigo_Final = 0;
	//Variaveis para receber o codigo inicial e final e fazer o range entre eles
	Verde("Digite o range de codigos que sera printado:\n");
	do{
		Verde("Codigo Inicial = ");
		scanf("%d",&Codigo_Inicial);
		Verde("Codigo Final = ");
		scanf("%d",&Codigo_Final);
		if(Codigo_Inicial == 0 || Codigo_Final == 0 ){
			Vermelho("O codigo inicial e final não pode ser 0 digite um valido");
		}else if(Codigo_Final < Codigo_Inicial){
			Vermelho("O codigo final não pode ser menor que o inicial");
		}
		//Mostra mensagem de erros ao usuario
	}while(Codigo_Inicial == 0 || Codigo_Final == 0 || Codigo_Final < Codigo_Inicial);
	//Loop que repete ate usuario digitiar valores validos para o range de codigos 
	int Quantidade_Codigos = Codigo_Final - Codigo_Inicial + 1;
	int Codigos[Quantidade_Codigos];
	int Contador_Codigos = 0;
	int Indice_Iguais = 0;
	//Vetor de codigos com a quantidade exata do range de codigos que foi passado, e contador de condigos
	for(int i = Codigo_Inicial; i <= Codigo_Final; i++){
		Codigos[Contador_Codigos] = i;
		Contador_Codigos++;
	}
	if(Modo_Abertura == Arquivo_Texto){
	//Caso modo de abertura seja TXT
	char Url[Tamanho2],Temporario[Tamanho2];
	sprintf(Url,"Arquivos/Hospede.txt");
	//Declara Array com a url
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
			//Pula o Ponteiro para o proximo caractere
			for(int i = 0;i < Quantidade_Codigos; i++){
				if(Codigos[i] == Hospede.Codigo){
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
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
					if(Modo_Feedback == Tela){
						Ler_Hospede_Memoria(Hospede);
					}else if(Modo_Feedback == Csv){
						
						Gravar_Hospede_Txt("Arquivos/Hospedes.csv",&Hospede);	
						system("clear");
						printf("\n");
						//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
					}
					
				}else{
					fscanf(Arquivo,"%[^\n]s",Temporario);
					getc(Arquivo);
				}
			}
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
	}else{
		//Caso modo de abertura seja BIN
		FILE *Arquivo;
		//Cria ponteiro de arquivo
		DADOS_HOSPEDE Hospede;
		char Url[Tamanho2];
		sprintf(Url,"Arquivos/Hospede.bin");
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
				for(int i = 0;i < Quantidade_Codigos; i++){
					if(Codigos[i] == Hospede.Codigo){
						if(Modo_Feedback == Tela){
							Ler_Hospede_Memoria(Hospede);
						}else if(Modo_Feedback == Csv){
						
							Gravar_Hospede_Txt("Arquivos/Hospedes.csv",&Hospede);	
							system("clear");
							printf("\n");
						}
					}
				}
			}
			fclose(Arquivo);	
		}
	}
}
void Filtro_Hospede_Sexo(int Modo_Feedback){
	//Funcao para realizar filtro por codigos de hospede
	int Modo_Abertura = Configuracoes();
	int Sexo = 0;
	do{
		Verde("Digite 1 - Masculino\n2 - Feminino\n3 - Outro:\n");
		scanf("%d",&Sexo);
		if(Sexo < 1 || Sexo > 3){
			Vermelho("Digite um valor valido para sexo");
		}
		//Mostra mensagem de erros ao usuario
	}while(Sexo < 1 || Sexo > 3);
	//Loop que repete ate usuario digitiar valores validos para o range de codigos 
	int Quantidade_Codigos = Tamanho2;
	int Codigos[Quantidade_Codigos];
	int Contador_Codigos = 0;
	int Indice_Iguais = 0;
	int Auxiliar = 0;
	//Vetor de codigos com a quantidade exata do range de codigos que foi passado, e contador de condigos
	
	if(Modo_Abertura == Arquivo_Texto){
	//Caso modo de abertura seja TXT
	char Url[Tamanho2],Temporario[Tamanho2];
	sprintf(Url,"Arquivos/Hospede.txt");
	//Declara Array com a url
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
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			getc(Arquivo);
			//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Nome);
			//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
			//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hospede.Sexo);
				//Expreção Regular
			getc(Arquivo);
			Auxiliar = 0;
			if(Sexo == 1){
				if(strcmp(Hospede.Sexo, "Masculino") == 0 || strcmp(Hospede.Sexo, "masculino") == 0){
					Auxiliar = 1;
				}
			}else if(Sexo == 2){
				if(strcmp(Hospede.Sexo, "Feminino") == 0 || strcmp(Hospede.Sexo, "feminino") == 0){
					Auxiliar = 1;
				}
			}else if(Sexo == 3){
				if(Hospede.Sexo[0] != 'F' && Hospede.Sexo[0] != 'f' && Hospede.Sexo[0] != 'M' && Hospede.Sexo[0] != 'm'){
					Auxiliar = 1;
				}
			}
			//Bloco de IFs para comparar qual sexo foi selecionado no inicio e verificar se no arquivo tem o sexo desejado, caso tenha habilita auxiliar com 1
			if(Auxiliar == 1){//Se auxiliar 1 le restante dos dados e chama funcao para gerar CSV ou printar na Tela
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
				if(Modo_Feedback == Tela){
					Ler_Hospede_Memoria(Hospede);
				}else if(Modo_Feedback == Csv){
				
					Gravar_Hospede_Txt("Arquivos/Hospedes.csv",&Hospede);	
					system("clear");
					printf("\n");
					//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
				}
			}else{
				Auxiliar = 0;
				fscanf(Arquivo,"%[^\n]s",Temporario);
				getc(Arquivo);
				//Pula resto dos campos pois nao interessa
			}
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		
	}
	fclose(Arquivo);
		//Fecha o Arquivo;
	}else{
		//Caso modo de abertura seja BIN
		FILE *Arquivo;
		//Cria ponteiro de arquivo
		DADOS_HOSPEDE Hospede;
		char Url[Tamanho2];
		sprintf(Url,"Arquivos/Hospede.bin");
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
				if(Sexo == 1){
					if(Hospede.Sexo[0] == 'M' || Hospede.Sexo[0] == 'm'){
						Auxiliar = 1;
					}
				}else if(Sexo == 2){
					if(Hospede.Sexo[0] == 'F' || Hospede.Sexo[0] == 'f'){
						Auxiliar = 1;
					}
				}else if(Sexo == 3){
					if(Hospede.Sexo[0] != 'F' && Hospede.Sexo[0] != 'f' && Hospede.Sexo[0] != 'M' && Hospede.Sexo[0] != 'm'){
						Auxiliar = 1;
					}
				}
				if(Auxiliar == 1){
					if(Modo_Feedback == Tela){
						Ler_Hospede_Memoria(Hospede);
					}else if(Modo_Feedback == Csv){
						
						Gravar_Hospede_Txt("Arquivos/Hospedes.csv",&Hospede);	
						system("clear");
						printf("\n");
					}
				}	
			}
			fclose(Arquivo);	
		}
	}
}
#endif