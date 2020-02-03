#ifndef Transacao
#define Transacao

void Main_Transacoes(){
	int Opcao=0;
	do{
		printf("\n");
		printf("\nDigite um numero referente a açao:\n");
		Amarelo("1 - Check IN\n");
		Amarelo("2 - Check OUT\n");
		Amarelo("0 - Sair\n");
		scanf("%d",&Opcao);
		//Recebe a Opcao do usuario
	}while(Opcao<0 || Opcao>2);//Repete enquanto opcao invalida
	
	switch (Opcao)
	{
		case 1://Caso Check IN
			Checkin();
			Verde("\nDigite 1 e pressione enter para continuar");			
			PAUSA; 
		break;
		case 2://Caso Check OUT
		break;
		

	}
}


int Valida_Reserva(int Codigo, int Modo_de_Abertura){
	//Procura nas acomodacoes pelo codigo da categoria para que assim nao apague os que sao vinculados
	FILE *Arquivo;
	char Temporario[Tamanho2];
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Reserva.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Reserva cadastradas\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Reserva.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Reserva cadastradas\n");
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
		RESERVA Reserva;
		Contador1=0;
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Reserva, sizeof(RESERVA),1,Arquivo);
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}

			Vetor_Codigos[Contador1] = Reserva.Codigo;
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

float Valor_Total(int Codigo, int Modo_de_Abertura){
	RESERVA Reserva;
	int Codigo_Acomodacao = 0, Codigo_Categoria = 0;
	float Valor_Total = 0;
	int Quantidade_Dias = 0;
	FILE *Arquivo;
	char Temporario[999];
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Reserva.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Reserva cadastradas\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Reserva.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Reserva cadastradas\n");
			return 0;		
		}
		break;
	}
	if (Modo_de_Abertura == Arquivo_Texto)
	{
		while(!feof(Arquivo)){

			fscanf(Arquivo,"%d",&Reserva.Codigo);
				//Lê o Codigo
			getc(Arquivo);
				//lê/pula ';'
			if(feof(Arquivo)){
					//Verifica se chegou a ao fim do arquivo
					break;
					//sai do while
			}
			if(Reserva.Codigo == Codigo){
				fscanf(Arquivo,"%[^;]s",Reserva.Nome_Hospede);
					//Lê o Codigo
				getc(Arquivo);
					//lê/pula ';'
				fscanf(Arquivo,"%i",&Reserva.Codigo_Hospede);
					//Lê o Codigo
				getc(Arquivo);
					//lê/pula ';'
				fscanf(Arquivo,"%i",&Reserva.Cod_Acomodacao);
					//Lê o Codigo
				getc(Arquivo);
					//lê/pula ';'
				fscanf(Arquivo,"%i",&Reserva.Data_Entrada.Dia);
					//Lê o Codigo
				getc(Arquivo);
					//lê/pula ';'
				fscanf(Arquivo,"%i",&Reserva.Data_Entrada.Mes);
					//Lê o Codigo
				getc(Arquivo);
					//lê/pula ';'
				fscanf(Arquivo,"%i",&Reserva.Data_Entrada.Ano);
					//Lê o Codigo
				getc(Arquivo);
				fscanf(Arquivo,"%i",&Reserva.Data_Saida.Dia);
					//Lê o Codigo
				getc(Arquivo);
					//lê/pula ';'
				fscanf(Arquivo,"%i",&Reserva.Data_Saida.Mes);
					//Lê o Codigo
				getc(Arquivo);
					//lê/pula ';'
				fscanf(Arquivo,"%i",&Reserva.Data_Saida.Ano);
					//Lê o Codigo
				getc(Arquivo);
				Codigo_Acomodacao = Reserva.Cod_Acomodacao;
				Quantidade_Dias = Reserva.Data_Saida.Dia - Reserva.Data_Entrada.Dia;
			}else{
				if(feof(Arquivo)){
					//Verifica se chegou a ao fim do arquivo
					break;
					//sai do while
				}
				fscanf(Arquivo,"%[^\n]s",Temporario);
				getc(Arquivo);
			}	
		}
	}else if (Modo_de_Abertura == Arquivo_Binario)
	{
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Reserva, sizeof(RESERVA),1,Arquivo);
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}
			if(Reserva.Codigo == Codigo){
				Codigo_Acomodacao = Reserva.Cod_Acomodacao;
				Quantidade_Dias = Reserva.Data_Saida.Dia - Reserva.Data_Entrada.Dia;
			}
		}
	}
	ACOMODACOES Acomodacoes;
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Acomodacoes.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Acomodacao cadastradas\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Acomodacoes.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Acomodacao cadastradas\n");
			return 0;		
		}
		break;
	}
	if (Modo_de_Abertura == Arquivo_Texto)
	{
		while(!feof(Arquivo)){

			fscanf(Arquivo,"%d",&Acomodacoes.Codigo);
				//Lê o Codigo
			getc(Arquivo);
				//lê/pula ';'
			if(feof(Arquivo)){
					//Verifica se chegou a ao fim do arquivo
					break;
					//sai do while
			}
			if(Acomodacoes.Codigo == Codigo_Acomodacao){
				for(int i = 0;i < 6; i++){
					fscanf(Arquivo,"%[^;]s",Temporario);
					getc(Arquivo);
				}//Pula ate chegar no codigo de categoria

				fscanf(Arquivo,"%d",&Acomodacoes.Cod_Categoria);
					//Lê o Codigo
				getc(Arquivo);
				Codigo_Categoria = Acomodacoes.Cod_Categoria;
			}else{
				if(feof(Arquivo)){
					//Verifica se chegou a ao fim do arquivo
					break;
					//sai do while
				}
				fscanf(Arquivo,"%[^\n]s",Temporario);
				getc(Arquivo);
			}	
		}
	}else if (Modo_de_Abertura == Arquivo_Binario)
	{
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}
			if(Acomodacoes.Codigo == Codigo_Acomodacao){
				Codigo_Categoria = Acomodacoes.Cod_Categoria;
			}
		}
	}
	CODIGO_CATEGORIA Cod_Categoria;
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Codigo_Categoria.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Codigo_Categoria cadastradas\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Codigo_Categoria.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Codigo_Categoria cadastradas\n");
			return 0;		
		}
		break;
	}
	if (Modo_de_Abertura == Arquivo_Texto)
	{
		while(!feof(Arquivo)){

			fscanf(Arquivo,"%d",&Cod_Categoria.Codigo);
				//Lê o Codigo
			getc(Arquivo);
				//lê/pula ';'
			if(feof(Arquivo)){
					//Verifica se chegou a ao fim do arquivo
					break;
					//sai do while
			}
			if(Cod_Categoria.Codigo == Codigo_Categoria){
				for(int i = 0;i < 2; i++){
					fscanf(Arquivo,"%[^;]s",Temporario);
					getc(Arquivo);
				}//Pula ate chegar no codigo de categoria

				fscanf(Arquivo,"%f",&Cod_Categoria.Valor_Diaria);
					//Lê o Codigo
				getc(Arquivo);
				Valor_Total = Cod_Categoria.Valor_Diaria;
			}else{
				if(feof(Arquivo)){
					//Verifica se chegou a ao fim do arquivo
					break;
					//sai do while
				}
				fscanf(Arquivo,"%[^\n]s",Temporario);
				getc(Arquivo);
			}	
		}
	}else if (Modo_de_Abertura == Arquivo_Binario)
	{
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Cod_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo);
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}
			if(Cod_Categoria.Codigo == Codigo_Categoria){
				Valor_Total = Cod_Categoria.Valor_Diaria;
			}
		}
	}
	Valor_Total = Valor_Total * Quantidade_Dias;

	return Valor_Total;
}



void Checkin(){
	int Reserva=0,Loop=1,Check=0;
	int Configuracao=Configuracoes();
	float Valor_Total_Diarias = 0;
	//Declara Variaveis
	while(Loop){//Loop que repete equanto loop for igual 1
		printf("Digite o codigo da reserva para efetuar o Check In:\n");
		scanf("%d",&Reserva);
		//Recebe codigo da reserva
		Loop = Valida_Reserva(Reserva, Configuracao);
		//Valida codigo(recebe 1 se encontrar e 0 se nao encontrar)
		if(Loop == 1){
			Loop = 0;//Caso encontre zera o loop para sair do while
		}else{//see nao
			Vermelho("Código digitado é invalido\n");
			printf("Deseja sair sem validar o codigo da reseva(1 - Sim 2 - Nao)");
			scanf("%d",&Loop);
			//Pergunta se usuario deseja sair sem validar
			if(Loop == 1){
				return;//Sai da funcao
			}else{
				Loop = 1;//Loop recebe 1 para repetir while
			}
		}
	}
	do{	
		printf("\nSe quer pagar na Entrada ou Saida digite o respecitivo codigo:\n");
		Verde("1")
		printf(" para ");
		Verde("Entrada\n")
		Vermelho("2")
		printf(" para ");
		Vermelho("Saida\n")
		//Recebe se usuario deseja pagar na entrada ou na saida
		scanf("%d",&Check);
	}while(Check<1 || Check>2);//Repete equanto nao digitar opcao valida

	if(Check == 1){//Caso deseja efetuar o pagamento na entrada
		Valor_Total_Diarias = Valor_Total(Reserva, Configuracao);
		//Chama Funcao para calcular o valor a ser pago
		Vermelho("O valor a ser pago é R$");
		Vermelho_F(Valor_Total_Diarias);
		//Mostra na tela o valor da diaria
	}
}

#endif