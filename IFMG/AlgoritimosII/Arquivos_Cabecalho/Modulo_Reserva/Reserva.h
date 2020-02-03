#ifndef _Reserva_ 
	//Se não estiver definido entra no if
#define _Reserva_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

	//Inclui arquivos de cabeçalho
/*
int Retorna_Campo_Struct_Reserva(char Url[99], int Codigo);
void Apagar_Modificar_Reserva_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
void Criar_Modificar_Reserva(int Modo_de_Abertura,int Manter_Codigo);
void Gravar_Reserva_Bin(char Url[99],RESERVA *Reserva);
void Gravar_Reserva_Txt(char Url[99],RESERVA *Reserva);
void Ler_Reserva_Bin();
void Ler_Reserva_Memoria(RESERVA Reserva);
void Ler_Reserva_Txt(char Url[99]);
void Main_Reserva(MODO Modo);
int Valida_Acomadacao_Reserva(int Codigo, int Modo_de_Abertura);
void Mostra_Se_Conta_Paga(int Pago);
void Modo_De_Pagamento(int Modo);
int Valida_Hospede_Reserva(int Codigo, int Modo_de_Abertura);
void DebugFluxo(char Url[99], FLUXO *Fluxo);
*/
void DebugFluxo(char Url[99], FLUXO *Fluxo){
	FILE *Arquivo;
	Arquivo = fopen(Url,"rb");
	Vermelho("\nMostrar Fluxo\n");
	printf("%s",Url);
	Verificacao_Arquivo(Url,Arquivo_Binario);
	while(!feof(Arquivo)){
		DEBUG("WHILE");
		fread(Fluxo, sizeof(FLUXO),1,Arquivo);	
		if(feof(Arquivo)){
			//Verifica se esta no fim do arquivo
			break;
			//Sai do loop
		}
		printf("Fluxo->Codigo_Reserva = %d\n", Fluxo->Codigo_Reserva);
		printf("Fluxo->Codigo_Acomodacao = %d\n", Fluxo->Codigo_Acomodacao);	
		printf("DataEntrada Dia = %d\n", Fluxo->Data_Entrada.Dia);	
		printf("Fluxo->DataEntrada Mes = %d\n", Fluxo->Data_Entrada.Mes);		
		printf("Fluxo->Data_Entrada Ano = %d\n", Fluxo->Data_Entrada.Ano);	
		printf("Fluxo->Data_Saida Dia = %d\n", Fluxo->Data_Saida.Dia);	
		printf("Fluxo->Data_Saida Mes = %d\n", Fluxo->Data_Saida.Mes);	
		printf("Fluxo->Data_Saida Ano = %d\n", Fluxo->Data_Saida.Ano);
		int Tamanho_Vetor = Fluxo->Data_Saida.Dia-Fluxo->Data_Entrada.Dia+1;
		for(int i=0;i<Tamanho_Vetor;i++){
			printf("%d\t",Fluxo->Vetor_Dias[i]);
		}
	
	}
	fclose(Arquivo);
}
void Ler_Reserva_Memoria(RESERVA Reserva){
	//Recebe por parametro Struct de Reserva
	printf("Codigo:\t\t\t\t%d\n",Reserva.Codigo);
	printf("Nome Hospede:\t\t\t%s\n",Reserva.Nome_Hospede);
	printf("Codigo Hospede:\t\t\t%d\n",Reserva.Codigo_Hospede);
	printf("Codigo Acomodacao\t\t%d\n",Reserva.Cod_Acomodacao);
	printf("Data de entrada:\t\t%u/%u/%u\n",Reserva.Data_Entrada.Dia,Reserva.Data_Entrada.Mes,Reserva.Data_Entrada.Ano);
	printf("Data de saida:\t\t\t%u/%u/%u\n",Reserva.Data_Saida.Dia,Reserva.Data_Saida.Mes,Reserva.Data_Saida.Ano);
	printf("Data de vencimento da fatura:\t%u/%u/%u\n",Reserva.Data_Vencimento_Fatura.Dia,Reserva.Data_Vencimento_Fatura.Mes,Reserva.Data_Vencimento_Fatura.Ano);
	printf("Valor Fatura:\t\t\tR$%.2f\n",Reserva.Valor_Fatura);
	printf("Pagamento:\t\t\t");
	Mostra_Se_Conta_Paga(Reserva.Pago);
	printf("Valor Conta:\t\t\tR$%.2f\n",Reserva.Valor_Conta);
	printf("Modo de Pagamento:\t\t");
	Modo_De_Pagamento(Reserva.Modo_Pagamento);
	//Fazer Funcao Para Pegar produtos consumidos
	printf("____________________________________________________\n");
	//Mostra dados do Reserva cadastrado na memoria
}
void Mostra_Se_Conta_Paga(int Pago){
	//Funcao para mostrar se a conta esta paga
	if(Pago == 0){//Se 0 esta pendente
		Vermelho("Pendente\n");//Mostra na tela colorindo de vermelho
	}else{//Se nao pago
		Verde("Pago\n");//Mostra na tela colorindo de verde
	}
}
void Modo_De_Pagamento(int Modo){
	//Funcao para Mostrar o modo de pagamento
	switch(Modo){//Switch para verificar cada caso
		case Especie:
			printf("Dinheiro\n");
		break;
		case Debito:
			printf("Debito\n");
		break;
		case Credito:
			printf("Credito\n");
		break;
		case Cheque:
			printf("Cheque\n");	
		break;
		default:
			Vermelho("INVALIDO\n");
		//Verifica o Caso definido no enum de registro e mostra o modo para o usuario
	}
}
void Gravar_Reserva_Txt(char Url[99],RESERVA *Reserva){
	//Colocar com parametro não " " mas sim ;
	FLUXO Fluxo;
	FILE *Arquivo;
	FILE *Arquivo_Fluxo_Ponteiro;
	char Arquivo_Fluxo[Tamanho2];
	char Temporario;
	int Auxiliar, Digito_Dia[2],Digito_Mes[2],Digito_Ano[4];
		
	Arquivo=fopen(Url,"a+");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	if(Reserva->Codigo_Hospede == 0){//Se codigo do hotel voltar como 0 indica que o codigo do hotel nao foi validado
		Vermelho("Erro com Codigo do Hospede");//Mostra mensagem de erro e nao deixa salvar no arquivo de TXT
	}else if(Reserva->Cod_Acomodacao == 0){
		Vermelho("Erro com Codigo de acomodacao");//Mostra mensagem de erro e nao deixa salvar no arquivo de TXT
	}else if(Reserva->Codigo == 0){
		//Codigo da Reserva vem com erro usuario digitou codigo de produto invalido
		Vermelho("Erro com Codigo de produtos");//Mostra mensagem de erro e nao deixa salvar no arquivo de BIN
}	else{
		fprintf(Arquivo,"%d;",Reserva->Codigo);
		fprintf(Arquivo,"%s;",Reserva->Nome_Hospede);
		fprintf(Arquivo,"%d;",Reserva->Codigo_Hospede);
		fprintf(Arquivo,"%d;",Reserva->Cod_Acomodacao);
		fprintf(Arquivo,"%u/",Reserva->Data_Entrada.Dia);
		fprintf(Arquivo,"%u/",Reserva->Data_Entrada.Mes);
		fprintf(Arquivo,"%u;",Reserva->Data_Entrada.Ano);		
		fprintf(Arquivo,"%u/",Reserva->Data_Saida.Dia);
		fprintf(Arquivo,"%u/",Reserva->Data_Saida.Mes);
		fprintf(Arquivo,"%u;",Reserva->Data_Saida.Ano);
		fprintf(Arquivo,"%u/",Reserva->Data_Vencimento_Fatura.Dia);
		fprintf(Arquivo,"%u/",Reserva->Data_Vencimento_Fatura.Mes);
		fprintf(Arquivo,"%u;",Reserva->Data_Vencimento_Fatura.Ano);
		fprintf(Arquivo,"%.2f;",Reserva->Valor_Fatura);
		fprintf(Arquivo,"%d;",Reserva->Pago);
		fprintf(Arquivo,"%.2f;",Reserva->Valor_Conta);
		fprintf(Arquivo,"%d;\n",Reserva->Modo_Pagamento);
		//CONFERIR DAQUI PARA BAIXO È A URL DE FLUXO printa no arquivo
		system("pwd");
		sprintf(Arquivo_Fluxo,"mkdir Arquivos/Reserva/%u",Reserva->Data_Entrada.Ano);
		system(Arquivo_Fluxo);//Cria primeira pasta Reserva
		system("clear");
		sprintf(Arquivo_Fluxo,"Arquivos/Reserva/%u/%u",Reserva->Data_Entrada.Ano,Reserva->Data_Entrada.Mes);		
		Verificacao_Arquivo(Arquivo_Fluxo,Arquivo_Binario);	
		//Verifica / cria os arquivos
		Arquivo_Fluxo_Ponteiro = fopen(Arquivo_Fluxo,"ab");//sempre abre em binario 
		Fluxo.Codigo_Reserva = Reserva->Codigo;	
		Fluxo.Codigo_Acomodacao = Reserva->Cod_Acomodacao;			//boolean
		Fluxo.Data_Entrada.Dia = Reserva->Data_Entrada.Dia;
		Fluxo.Data_Entrada.Mes = Reserva->Data_Entrada.Mes;
		Fluxo.Data_Entrada.Ano = Reserva->Data_Entrada.Ano;
		Fluxo.Data_Saida.Dia = Reserva->Data_Saida.Dia;
		Fluxo.Data_Saida.Mes = Reserva->Data_Entrada.Mes;
		Fluxo.Data_Saida.Ano = Reserva->Data_Entrada.Ano;		
		
		for(int i = 0; i < Fluxo.Data_Saida.Dia-Fluxo.Data_Entrada.Dia + 1; i++){
			Fluxo.Vetor_Dias[i] = Fluxo.Data_Entrada.Dia + i;
		}
		
		fwrite(&Fluxo, sizeof(FLUXO), 1, Arquivo_Fluxo_Ponteiro); 
		//Salva
		fclose(Arquivo_Fluxo_Ponteiro);
		//Fecha o arquivo

		Verde("\nArquivo Salvo em :");
		Verde(Url);
		Verde("\nArquivo Salvo em :");
		Verde(Arquivo_Fluxo);
		
	}
	//
	//
	//
	//Fazer funcao para salvar produtos no TXT
		//Salva um struct por Linha
	fclose(Arquivo);
		//Fecha o o arquivo para evitar erros	
}
void Ler_Reserva_Txt(char Url[99]){
	RESERVA Reserva;
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
				
			Ler_Reserva_Memoria(Reserva);
			
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

void Recebe_Dados_Reserva(RESERVA *Reserva){
	int Modo_de_Abertura=0;
	int Acomodacao_Indisponiveis[Tamanho2];
	int Acomodacao_Disponiveis[Tamanho2];
	int Contador_Acomodacao_Indisponiveis, Contador_Acomodacao_Disponiveis;
	DATA Data;
	char Arquivo_Fluxo[Tamanho2];
	Modo_de_Abertura=Configuracoes();
	PESQUISA Pesquisar;
	int Codigo_Hospede_A_Ser_Validado,Codigo_Acomodacao_A_Ser_Validado,Auxiliar=0,Sair_Da_Validacao = 0;
	//Codigos a serem validados
	while(Auxiliar == 0){//Repete loop enquanto auxiliar se mantem no 0
		printf("Codigo do Hospede:");
		scanf("%d",&Codigo_Hospede_A_Ser_Validado);
		//Recebe codida categoria
		if (Valida_Hospede_Reserva(Codigo_Hospede_A_Ser_Validado,Modo_de_Abertura))
		{
			//Chama funcao para validar e ja verifica se retornou verdadeiro 1
			Reserva->Codigo_Hospede = Codigo_Hospede_A_Ser_Validado;
			Auxiliar = 1;			
			//Coloca codigo da categoria na struct e auxiliar recebe 1 para sair do loop sem erros
		}else{
			Vermelho("\nCodigo não cadastrado\n");//Mostra que o codigo nao esta cadastrado
			printf("Deseja sair sem efetuar o cadastro?(1 - Sim | 2 - Não)");
			scanf("%d",&Sair_Da_Validacao);
			//Recebe valor para sair do loop sem efetuar cadastro
			if(Sair_Da_Validacao == 1){
				Auxiliar=0;
				break;//sai do loop com auxiliar 0 indicando que nao efetuara o cadastro
			}
		}
	}
	if(Auxiliar == 1){
		Nome_Hospede_Codigo(Reserva->Codigo_Hospede, Reserva->Nome_Hospede);
		printf("Codigo da Acomodacao:");
		scanf("%d",&Codigo_Acomodacao_A_Ser_Validado);	
		Reserva->Cod_Acomodacao = Codigo_Acomodacao_A_Ser_Validado;	

		do{
			Verde("\nDigite a data referente a Entrada");
			Recebe_Data(&Reserva->Data_Entrada,1);
			Verde("\nDigite a data referente a Saida");
			Reserva->Data_Saida.Ano = Reserva->Data_Entrada.Ano;
			Reserva->Data_Saida.Mes = Reserva->Data_Entrada.Mes;		
			Recebe_Data(&Reserva->Data_Saida,2);
			if(Reserva->Data_Saida.Dia < Reserva->Data_Entrada.Dia){
				Vermelho("O dia de entrada não pode ser anterior ao dia de saida");
			}
		}while(Reserva->Data_Saida.Dia < Reserva->Data_Entrada.Dia);
		//Recebe data que sera efetuada a reserva

		sprintf(Arquivo_Fluxo,"Arquivos/Reserva/");
		Cria_Pasta(Arquivo_Fluxo);
		sprintf(Arquivo_Fluxo,"Arquivos/Reserva/%u",Reserva->Data_Entrada.Ano);
		Cria_Pasta(Arquivo_Fluxo);
		system("clear");
		//Cria pasta caso nao exista para evitar erro de caminho invalido
		sprintf(Arquivo_Fluxo,"Arquivos/Reserva/%u/%u",Reserva->Data_Entrada.Ano,Reserva->Data_Entrada.Mes);

		Verificacao_Arquivo(Arquivo_Fluxo,Arquivo_Binario);
		Contador_Acomodacao_Indisponiveis = Verifica_Fluxo(Arquivo_Fluxo, Reserva->Data_Entrada,Reserva->Data_Saida, Acomodacao_Indisponiveis);
		if(Modo_de_Abertura == Arquivo_Texto){
			Contador_Acomodacao_Disponiveis = Todas_Acomodacoes_TXT("Arquivos/Acomodacoes.txt",Acomodacao_Disponiveis,Acomodacao_Indisponiveis,Contador_Acomodacao_Indisponiveis);
		}else if(Modo_de_Abertura == Arquivo_Binario){
			Contador_Acomodacao_Disponiveis = Todas_Acomodacoes_BIN("Arquivos/Acomodacoes.bin",Acomodacao_Disponiveis,Acomodacao_Indisponiveis,Contador_Acomodacao_Indisponiveis);
		}
		//Retorna os Codigos de acomodaacoes Disponiveis para cadastro e a quantidade
		Auxiliar = 0;
		//Zera auxiliar para poder validar a Acomodacao
		for(int i = 0; i < Contador_Acomodacao_Disponiveis; i++){
			if(Reserva->Cod_Acomodacao == Acomodacao_Disponiveis[i]){
				Auxiliar = 1;
				break;
			}
		}
		if(Auxiliar != 1){
			Vermelho("\nAcomodacao já esta reservada para a data\n");
			 printf("%u/%u/%u a  %u/%u/%u", Reserva->Data_Entrada.Dia,Reserva->Data_Entrada.Mes,Reserva->Data_Entrada.Ano,Reserva->Data_Saida.Dia,Reserva->Data_Saida.Mes,Reserva->Data_Saida.Ano);
			 Reserva->Cod_Acomodacao = 0;
		}else{
			Verde("A reserva será efetuada no periodo de:");
			printf("%u/%u/%u a %u/%u/%u\n", Reserva->Data_Entrada.Dia,Reserva->Data_Entrada.Mes,Reserva->Data_Entrada.Ano,Reserva->Data_Saida.Dia,Reserva->Data_Saida.Mes,Reserva->Data_Saida.Ano);
			printf("Digite o dia de Vencimento da Fatura");
			scanf("%u",&Reserva->Data_Vencimento_Fatura.Dia);
			printf("Digite o mes de Vencimento da Fatura");
			scanf("%u",&Reserva->Data_Vencimento_Fatura.Mes);
			printf("Digite o ano de Vencimento da Fatura");
			scanf("%u",&Reserva->Data_Vencimento_Fatura.Ano);
			printf("Valor da Fatura:");
			scanf("%f",&Reserva->Valor_Fatura);
			printf("Digite");
			Verde("\t1 para valor pago");
			Vermelho("\t0 para pendente");
			scanf("%d",&Reserva->Pago);
			do{
				printf("1- Pagamento Dinheiro\n"
						"2- Pagamento Debito\n"
						"3- Pagamento Credito\n"
						"4- Pagamento Cheque\n");
				scanf("%d",&Reserva->Modo_Pagamento);
				if(Reserva->Modo_Pagamento<1 || Reserva->Modo_Pagamento>4){
					Vermelho("\nDigite um opção Valida\n");
				}
			}while(Reserva->Modo_Pagamento<1 || Reserva->Modo_Pagamento>4);

			int Loop=1,Indice=0;
			while(Loop){
				int Codigo_Produto_A_Ser_Validado,Sair_Da_Validacao = 0;
				
				Auxiliar=0;
				//Adapta A variavel de acordo com o modo de abertura
				while(Auxiliar == 0){
					printf("Codigo do Produto:");
					scanf("%d",&Codigo_Produto_A_Ser_Validado);
					//Recebe o codigo de Hotel OBS O Codigo do hotel é importante para vincular o produto ao hotel alem de automatizar o preço de venda de acordo com a porcentagem de lucro cadastrada no hotel
					if (Valida_Codigo_Produto(Codigo_Produto_A_Ser_Validado, Modo_de_Abertura))
					{//Verifica se o codigo do hotel está cadastro 
						Reserva->Codigo_Produto[Indice] = Codigo_Produto_A_Ser_Validado;
						//Atribui o codigo digitado a struct	
						Auxiliar = 1;		
						//Variavel para sair do loop
					}else{
						Vermelho("\nCodigo não cadastrado\n\n");
						printf("Deseja sair SEM efetuar o cadastro?(1 - Sim | 2 - Não)");
						scanf("%d",&Sair_Da_Validacao);
						if(Sair_Da_Validacao == 1){
							Reserva->Codigo = 0;
							//zera codigo de reserva indicando que nao fara o cadastro
							Loop=0;
							break;
							//Sai do loop
						}	
					}
				}
				if(Auxiliar != 1){
					Reserva->Codigo = 0;
					//zera codigo de reserva indicando que nao fara o cadastro

				}
				if(Auxiliar==1){
					do{
						printf("Digite o Quantidade do produto");
						scanf("%d",&Reserva->Quantidade_De_Produtos[Indice]);
					}while(Reserva->Quantidade_De_Produtos[Indice]<=0);
					do{
						printf("Digite o Pagamento do produto");
						Vermelho(" 0 - Prazo");
						Verde(" 1 - A vista");
						scanf("%d",&Reserva->Prazo_Vista[Indice]);	
					}while(Reserva->Prazo_Vista[Indice]!=Prazo && Reserva->Prazo_Vista[Indice]!=Vista);
					Indice++;
					printf("Deseja implementar outro Produto à lista ");
					Verde("1 - Sim ");
					Vermelho("0 - Não");
					scanf("%d",&Loop);		
				}				
			}
		}
	}
	//RECEBER DADOS PRODUTOS
	//os outros dados
	
}

void Arquivo_Url_Fluxo(char Url[99], int Codigo,char Url_Fluxo[]){
	RESERVA Reserva;
		//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
		//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	char Temporario[Tamanho2];
	int Arquivo_Vazio=0;

	
	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
		do{
			fscanf(Arquivo,"%d",&Reserva.Codigo);
			getc(Arquivo);
			if(Reserva.Codigo == Codigo){
						//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
					//Expreção Regular

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
				sprintf(Url_Fluxo,"Arquivos/Reserva/%u/%u",Reserva.Data_Entrada.Ano,Reserva.Data_Entrada.Mes);		
				break;
				//sai do loop
			}else{
				fscanf(Arquivo,"%[^\n]s",Temporario);
			}
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
}


void Main_Reserva(MODO Modo){
	RESERVA Reserva;
	int Acao,Codigo=0;

	Verificacao_Arquivo("Arquivos/Reserva.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Reserva.txt",Arquivo_Texto);
	//Verifica se ja existe os arquivos

	while(1){
		OrdenaValoresTxt();
		Acao = Opcao_Acoes_Reserva();
		//Retorna um inteiro referente a Ação (Case)
		//limpa a tela
		switch (Acao){
			case Ler:
				if(Modo.Nivel_De_Permissao>=8 && Modo.Nivel_De_Permissao <=15){
					if (Modo.Modo_de_Abertura == Arquivo_Binario)
					{
						Ler_Reserva_Bin("Arquivos/Reserva.bin");
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						Ler_Reserva_Txt("Arquivos/Reserva.txt");
					}
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;
			case Criar:
				if ((Modo.Nivel_De_Permissao >=4 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=12 && Modo.Nivel_De_Permissao <=15)){
						Criar_Modificar_Reserva(Modo.Modo_de_Abertura,0);	
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;	
			case Apagar:
				if ((Modo.Nivel_De_Permissao%2)){//Se for impar retorna 1 e somente numeros impares tem a permissao de Apagar
					if(Modo.Modo_de_Abertura == Arquivo_Binario){
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar_Reserva_Bin("Arquivos/Reserva.bin",Codigo,0,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						char Arquivo_Fluxo[Tamanho2]={'\0'};
						int Indice = 0, Codigos[Tamanho2];
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Indice = Retorna_Codigos_Reserva(Codigos);
						int Auxiliar = 0;
						for(int i = 0; i < Indice; i++){
							if(Codigo == Codigos[i]){								
								Arquivo_Url_Fluxo("Arquivos/Reserva.txt",Codigo,Arquivo_Fluxo);
								Apagar_Fluxo(Arquivo_Fluxo,Codigo);
								Apagar_Modificar("Arquivos/Reserva.txt",Codigo,0,Modo,Dados_Reserva);
								Auxiliar = 1;
							}
						}
						if(Auxiliar == 0){
							Vermelho("O código que foi digitado é inexistente, por favor digite um código válido!!");
						}
						
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

int Retorna_Codigos_Reserva(int Codigos[]){
	FILE *Arquivo;
	int Indice = 0;
	char Temporario[Tamanho2];
	Arquivo = fopen("Arquivos/Reserva.txt","r");
	if(Arquivo != NULL && Arquivo_Texto_Vazio("Arquivos/Reserva.txt") != 1){
		do{
			fscanf(Arquivo,"%d", &Codigos[Indice]);
			if(feof(Arquivo)){
				break;
			}
			fscanf(Arquivo,"%[^\n]s", Temporario);
			Indice++;
		}while(!feof(Arquivo));
	}
	return Indice;
}

void Ler_Reserva_Bin(char Url[99]){
	FILE *Arquivo;
	//Cria ponteiro de arquivo
	RESERVA Reserva;
	Arquivo = fopen(Url,"rb");
	int Arquivo_Vazio=0;
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}else{
		while(!feof(Arquivo)){
			fread(&Reserva, sizeof(RESERVA),1,Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Ler_Reserva_Memoria(Reserva);
			Arquivo_Vazio++;
			//Contador para verificar se o arquivo está em branco
		}
		fclose(Arquivo);
		if(Arquivo_Vazio==0){
			Vermelho("O Arquivo está vazio\n");
		}
	}
}



void Gravar_Reserva_Bin(char Url[99],RESERVA *Reserva){
	FILE *Arquivo;
	FILE *Arquivo_Fluxo_Ponteiro;
	FLUXO Fluxo;
	char Arquivo_Fluxo[Tamanho2];
	
		//Um ponteiro que aponta para um arquivo
	Arquivo=fopen(Url,"ab");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	
	if(Reserva->Codigo_Hospede == 0){//Se codigo do hotel voltar como 0 indica que o codigo do hotel nao foi validado
		Vermelho("Erro com Codigo do Hospede");//Mostra mensagem de erro e nao deixa salvar no arquivo de BIN
	}else if(Reserva->Cod_Acomodacao == 0){
		Vermelho("Erro com Codigo de acomodacao");//Mostra mensagem de erro e nao deixa salvar no arquivo de BIN
	}else if(Reserva->Codigo == 0){
			//Codigo da Reserva vem com erro usuario digitou codigo de produto invalido
		Vermelho("Erro com Codigo de produtos");//Mostra mensagem de erro e nao deixa salvar no arquivo de BIN
	}else{
		fwrite(Reserva, sizeof(RESERVA), 1, Arquivo); 
			//Primeiro argumento é um ponteiro .... como proceder
			
			sprintf(Arquivo_Fluxo,"Arquivos/Reserva/%u/%u",Reserva->Data_Entrada.Ano,Reserva->Data_Entrada.Mes);
			Verificacao_Arquivo(Arquivo_Fluxo,Arquivo_Binario);	
			Arquivo_Fluxo_Ponteiro = fopen(Arquivo_Fluxo,"ab");//sempre abre em binario 
			Fluxo.Codigo_Reserva = Reserva->Codigo;	
			Fluxo.Codigo_Acomodacao = Reserva->Cod_Acomodacao;			//boolean
			Fluxo.Data_Entrada.Dia = Reserva->Data_Entrada.Dia;
			Fluxo.Data_Entrada.Mes = Reserva->Data_Entrada.Mes;
			Fluxo.Data_Entrada.Ano = Reserva->Data_Entrada.Ano;
			Fluxo.Data_Saida.Dia = Reserva->Data_Saida.Dia;
			Fluxo.Data_Saida.Mes = Reserva->Data_Saida.Mes;
			Fluxo.Data_Saida.Ano = Reserva->Data_Saida.Ano;		
			for(int i = 0; i <= Fluxo.Data_Saida.Dia-Fluxo.Data_Entrada.Dia + 1; i++){
				Fluxo.Vetor_Dias[i] = Fluxo.Data_Entrada.Dia + i;
			}
			fwrite(&Fluxo, sizeof(FLUXO), 1, Arquivo_Fluxo_Ponteiro); 
			
			//Abre arquivo 
	
			fclose(Arquivo_Fluxo_Ponteiro);
			
		fclose(Arquivo);
			//Fecha o Arquivo Para evitar erro
		Verde("\nArquivo Salvo 'Reserva.bin'");
		   //Mensagem de Confirmação
	}
}

int Valida_Acomadacao_Reserva(int Codigo, int Modo_de_Abertura){
	//Procura nas acomodacoes pelo codigo da categoria para que assim nao apague os que sao vinculados
	FILE *Arquivo;
	char Temporario[Tamanho2];
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

	int Contador1=0, Vetor_Codigos[Tamanho2];
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

			Vetor_Codigos[Contador1] = Acomodacoes.Codigo;
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
int Valida_Hospede_Reserva(int Codigo, int Modo_de_Abertura){
	//Procura nas acomodacoes pelo codigo da categoria para que assim nao apague os que sao vinculados
	FILE *Arquivo;
	char Temporario[Tamanho2];
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Hospede.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Hospedes cadastradas\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Hospede.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Hospedes cadastradas\n");
			return 0;		
		}
		break;
	}		

	int Contador1=0, Vetor_Codigos[Tamanho2];
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
		DADOS_HOSPEDE Hospede;
		Contador1=0;
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo);
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}

			Vetor_Codigos[Contador1] = Hospede.Codigo;
			Contador1++;
			//Soma no contador de contador
		}
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
void Criar_Modificar_Reserva(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];
	RESERVA Reserva;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela
	switch (Modo_de_Abertura){
		case Arquivo_Texto:
		strcpy(Url,"Arquivos/Reserva.txt");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Reserva.Codigo = Valida_Codigo(Url,15,Arquivo_Texto,Dados_Reserva);
		}else{
			Reserva.Codigo = Manter_Codigo;
		}
		break;

		case Arquivo_Binario:
		strcpy(Url,"Arquivos/Reserva.bin");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Reserva.Codigo = Valida_Codigo(Url,15,Arquivo_Binario,Dados_Reserva);
		}else{
			Reserva.Codigo = Manter_Codigo;
		}
		break;
		case Banco_De_Dados:
			//Não está implementado
		break;
		case Nuvem:
			//Não está implementado
		break;

	}
	Recebe_Dados_Reserva(&Reserva);
	//Mostra Dados de Reserva salvos na struct
	switch(Modo_de_Abertura){			
		case Arquivo_Texto:
			Gravar_Reserva_Txt(Url,&Reserva);
			//Grava em TXT
			break;

		case Arquivo_Binario:
		
			Gravar_Reserva_Bin(Url,&Reserva);
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


int Retorna_Campo_Struct_Reserva(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Bin_ou_Txt(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[Tamanho2];
	RESERVA Reserva;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Reserva, sizeof(RESERVA),1,Arquivo);
		Validador = Reserva.Codigo;
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

void Apagar_Modificar_Reserva_Bin(char Url[99], int Codigo,int Modificar,MODO Modo){
	if(Modo.Modo_de_Abertura == Arquivo_Binario){
		char Arquivo_Fluxo[Tamanho2];
		RESERVA Reserva;
		//Cria uma Variavel do tipo Dados_Reserva
		FILE *Arquivo, *Arquivo_Temporario;
		//Cria 2ponteiros do tipo FILE
		Arquivo=fopen(Url,Modo.Leitura);
		//Abre o aqruivo principal em modo leitura
		Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
		//Abre o arquivo que sera apagado em modo de concatenacao
		int Campo_Struct = Retorna_Campo_Struct_Reserva(Url, Codigo);
		//Variavel Campo_Struct recebe quantas structs teve que pular para achar o codigo
		if(Campo_Struct == -1){//Se for retornado -1 mostra que nao foi encotrado o codigo digitado
			Vermelho("O codigo digitado não foi encontrado");
		}else{
			if(Confirmacao()){//Se a confirmacao retornar 1 
				for(int i=1;i<Campo_Struct;i++){
					//Vai ate o campo do codigo
					fread(&Reserva, sizeof(RESERVA),1,Arquivo);
					fwrite(&Reserva, sizeof(RESERVA),1,Arquivo_Temporario); 
					//Escreve no Arquivo temporario
				}
				fread(&Reserva, sizeof(RESERVA),1,Arquivo); 
				sprintf(Arquivo_Fluxo,"Arquivos/Reserva/%u/%u",Reserva.Data_Entrada.Ano,Reserva.Data_Entrada.Mes);		
				Verificacao_Arquivo(Arquivo_Fluxo,Arquivo_Binario);	
				Apagar_Fluxo(Arquivo_Fluxo, Reserva.Codigo);
				//Le o arquivo Arquivo Binario e passa dados para struct
				//Apaga o dado
				while(!feof(Arquivo)){
					//Vai ate o Final do Arquivo
					fread(&Reserva, sizeof(RESERVA),1,Arquivo);
					if(feof(Arquivo)){
						//Sai caso esteja no fim do arquivo;
						break;
					}
					fwrite(&Reserva, sizeof(RESERVA),1,Arquivo_Temporario); 
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

int Retorna_Campo_Struct_Fluxo(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Bin_ou_Txt(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[Tamanho2];
	FLUXO Fluxo;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Fluxo, sizeof(FLUXO),1,Arquivo);
		Validador = Fluxo.Codigo_Reserva;
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

void Apagar_Fluxo(char Url[999], int Codigo){
	char Url_Temporaria[999];
	FLUXO Fluxo;
	//Cria uma Variavel do tipo Dados_Reserva
	strcpy(Url_Temporaria,Url);		
	strcat(Url_Temporaria,".tmp");
	FILE *Arquivo, *Arquivo_Temporario;
	//Cria 2ponteiros do tipo FILE
	Arquivo=fopen(Url,"rb");
	//Abre o aqruivo principal em modo leitura
	Arquivo_Temporario = fopen(Url_Temporaria,"ab+");
	//Abre o arquivo que sera apagado em modo de concatenacao
	int Campo_Struct = Retorna_Campo_Struct_Fluxo(Url, Codigo);
	//Variavel Campo_Struct recebe quantas structs teve que pular para achar o codigo
	if(Campo_Struct != -1){//Se for retornado -1 mostra que nao foi encotrado o codigo digitado
		if(1){//Se a confirmacao retornar 1 
			for(int i=1;i<Campo_Struct;i++){
				//Vai ate o campo do codigo
				fread(&Fluxo, sizeof(FLUXO),1,Arquivo);
				fwrite(&Fluxo, sizeof(FLUXO),1,Arquivo_Temporario); 
				//Escreve no Arquivo temporario
			}

			fread(&Fluxo, sizeof(FLUXO),1,Arquivo); 
			//Le o arquivo Arquivo Binario e passa dados para struct
			//Apaga o dado
			while(!feof(Arquivo)){
				//Vai ate o Final do Arquivo
				fread(&Fluxo, sizeof(FLUXO),1,Arquivo);
				if(feof(Arquivo)){
					//Sai caso esteja no fim do arquivo;
					break;
				}
				fwrite(&Fluxo, sizeof(FLUXO),1,Arquivo_Temporario); 
					//Printa no Arquivo Temporario
			}
			fclose(Arquivo_Temporario);
			fclose(Arquivo);
				//Fecha ambos os Arquivos
			remove(Url);
				//Remove o Arquivo Original
			rename(Url_Temporaria,Url);
				//Renomeia o Arquivo
		}
	}
}

/*
#ifdef Debug
printf("");
#endif
*/

#endif

