	#ifndef _Importacao_
	#define _Importacao_
	
	//TEM QUE PEGAR A URL QUE QUER SALVAR E CRIAR A PASTA
	
	/*
	Arquivos/Hospede.bin 			Arquivos/Hospede.txt
	Arquivos/Hotel.bin 				Arquivos/Hotel.txt
	Arquivos/Acomodacoes.bin 		Arquivos/Acomodacoes.txt
	Arquivos/Codigo_Categoria.bin 	Arquivos/Codigo_Categoria.txt
	Arquivos/Fornecedores.bin 		Arquivos/Fornecedores.txt
	Arquivos/Funcionarios.bin 		Arquivos/Funcionarios.txt
	Arquivos/Produtos.bin 			Arquivos/Produtos.txt
	Arquivos/Reserva.bin 			Arquivos/Reserva.txt
	#######################Arquivos/Reserva#################
	Arquivos/Reserva/
	*/
/*
	void Main_IE();
	IMPORTACAO_EXPORTACAO Set_On_Off();
	void Exportar();
	void Importacao();
*/
	void Main_IE();
	IMPORTACAO_EXPORTACAO Set_On_Off();
	void Exportar();
	void Importacao();

	void Main_IE(){
		int Opcao=0;
		do{
			printf("\nDigite:\n");
			Amarelo("0");
			printf(" para ");
			Amarelo("voltar\n");
			Verde("1");
			printf(" para ");
			Verde("Importar\n")
			Vermelho("2");
			printf(" para ");
			Vermelho("Exportar\n");
			//Msgs
			scanf("%d",&Opcao);

			if(Opcao < 0 || Opcao > 2){
				system("clear");
				printf("Digite '0', '1' ou '2'\n");

			}
		}while(Opcao < 0 || Opcao > 2);

		
		switch (Opcao){

			case 0:
				return;
			break;

			case 1:
				Importacao();
			break;

			case 2:
				Exportar();
			break;

		}
		//Tomada de decisao
		
		return ;
	}

	IMPORTACAO_EXPORTACAO Set_On_Off(){
		IMPORTACAO_EXPORTACAO On_Off;
		int Modo_Abertura = Configuracoes();
		printf("Digite ");
		Verde("1 (ON) ");
		printf("ou ");
		Vermelho("0 (OFF)\n");
		//Tutorial
		do{
			printf("\nHotel:");
			scanf("%d%*c",&On_Off.Hotel);
			if(On_Off.Hotel == 1){
				if(Modo_Abertura == Arquivo_Texto){
					if(Arquivo_Texto_Vazio("Arquivos/Hotel.txt")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Hotel =0;
					}	
				}else{
					if(Arquivo_Binario_Vazio("Arquivos/Hotel.bin")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Hotel =0;
					}
				}	
			}
		}while(On_Off.Hotel!=0 && On_Off.Hotel!=1 );
		
	
		do{
			printf("\nHospede:");
			scanf("%d%*c",&On_Off.Hospede);
			if(On_Off.Hospede == 1){
				if(Modo_Abertura == Arquivo_Texto){
					if(Arquivo_Texto_Vazio("Arquivos/Hospede.txt")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Hospede =0;
					}	
				}else{
					if(Arquivo_Binario_Vazio("Arquivos/Hospede.bin")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Hospede =0;
					}
				}	
			}
		}while(On_Off.Hospede!=0 && On_Off.Hospede!=1 );
		
		do{
			printf("\nAcomodacoes:");
			scanf("%d%*c",&On_Off.Acomodacoes);
			if(On_Off.Acomodacoes == 1){
				if(Modo_Abertura == Arquivo_Texto){
					if(Arquivo_Texto_Vazio("Arquivos/Acomodacoes.txt")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Acomodacoes =0;
					}	
				}else{
					if(Arquivo_Binario_Vazio("Arquivos/Acomodacoes.bin")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Acomodacoes =0;
					}
				}	
			}
	
		}while(On_Off.Acomodacoes!=0 && On_Off.Acomodacoes!=1 );
	
		do{
			printf("\nCodigo_Categoria:");
			scanf("%d%*c",&On_Off.Codigo_Categoria);
			if(On_Off.Codigo_Categoria == 1){
				if(Modo_Abertura == Arquivo_Texto){
					if(Arquivo_Texto_Vazio("Arquivos/Codigo_Categoria.txt")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Codigo_Categoria =0;
					}	
				}else{
					if(Arquivo_Binario_Vazio("Arquivos/Codigo_Categoria.bin")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Codigo_Categoria =0;
					}
				}	
			}
	
		}while(On_Off.Codigo_Categoria!=0 && On_Off.Codigo_Categoria!=1 );
	
		do{
			printf("\nProdutos:");
			scanf("%d%*c",&On_Off.Produtos);
			if(On_Off.Produtos == 1){
				if(Modo_Abertura == Arquivo_Texto){
					if(Arquivo_Texto_Vazio("Arquivos/Produtos.txt")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Produtos =0;
					}	
				}else{
					if(Arquivo_Binario_Vazio("Arquivos/Produtos.bin")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Produtos =0;
					}
				}	
			}
	
		}while(On_Off.Produtos!=0 && On_Off.Produtos!=1 );
	
		do{
			printf("\nFornecedores:");
			scanf("%d%*c",&On_Off.Fornecedores);
			if(On_Off.Fornecedores == 1){
				if(Modo_Abertura == Arquivo_Texto){
					if(Arquivo_Texto_Vazio("Arquivos/Fornecedores.txt")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Fornecedores =0;
					}	
				}else{
					if(Arquivo_Binario_Vazio("Arquivos/Fornecedores.bin")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Fornecedores =0;
					}
				}	
			}
	
		}while(On_Off.Fornecedores!=0 && On_Off.Fornecedores!=1 );
	
		do{
			printf("\nFuncionarios:");
			scanf("%d%*c",&On_Off.Funcionarios);
			if(On_Off.Funcionarios == 1){
				if(Modo_Abertura == Arquivo_Texto){
					if(Arquivo_Texto_Vazio("Arquivos/Funcionarios.txt")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Funcionarios =0;
					}	
				}else{
					if(Arquivo_Binario_Vazio("Arquivos/Funcionarios.bin")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Funcionarios =0;
					}
				}	
			}
	
		}while(On_Off.Funcionarios!=0 && On_Off.Funcionarios!=1 );
	
		do{
			printf("\nReserva:");
			scanf("%d%*c",&On_Off.Reserva);
			if(On_Off.Reserva == 1){
				if(Modo_Abertura == Arquivo_Texto){
					if(Arquivo_Texto_Vazio("Arquivos/Reserva.txt")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Reserva =0;
					}	
				}else{
					if(Arquivo_Binario_Vazio("Arquivos/Reserva.bin")){
						Vermelho("Não é possivel exportar pois o arquivo esta vazio");
						On_Off.Reserva =0;
					}
				}	
			}
	
		}while(On_Off.Reserva!=0 && On_Off.Reserva!=1 );
	
		system("clear");
		return On_Off;
	}

	void Exportar(){
	
		//Variaveis
		int Loop=1,Indice[]={1,1,1,1,1,1,1,1,1};
		int Modo_Abertura=Configuracoes();
		IMPORTACAO_EXPORTACAO On_Off=Set_On_Off();
	
		FILE *Arquivo,*Exporta;
	
		DADOS_HOTEL *Hotel = malloc(sizeof(DADOS_HOTEL)); 
		DADOS_HOSPEDE *Hospede = malloc(sizeof(DADOS_HOSPEDE)); 
		ACOMODACOES *Acomodacoes=malloc(sizeof(ACOMODACOES));
		CODIGO_CATEGORIA *Codigo_Categoria = malloc(sizeof(CODIGO_CATEGORIA)); 
		PRODUTOS *Produtos = malloc(sizeof(PRODUTOS)); 
		FORNECEDORES *Fornecedores = malloc(sizeof(FORNECEDORES)); 
		FUNCIONARIOS *Funcionarios = malloc(sizeof(FUNCIONARIOS)); 
		RESERVA *Reserva = malloc(sizeof(RESERVA)); 
	
	
		//Cria um Arquivo
		char Url[Tamanho2];
		printf("Digite o Local para Exportar\n");
		scanf("%s",Url);
		strcat(Url,".xml");
		//Verificacao_Arquivo(Url,Arquivo_Texto);
		Exporta=fopen(Url,"w");
	
		//Le do Txt
	
		if(On_Off.Hotel==1){
			
			if(Modo_Abertura==Arquivo_Binario){//Bin
				Arquivo=fopen("Arquivos/Hotel.bin","rb");//Somente leitura
			}else{//Txt
				Arquivo=fopen("Arquivos/Hotel.txt","r");//Somente leitura
			}
			//Abre o Arquivo
			
			while(Loop){//Passa do Arquivo pra Memoria
				Hotel=realloc(Hotel,Indice[0]*sizeof(DADOS_HOTEL));//Realoca o ponteiro
				if(Modo_Abertura==Arquivo_Binario){//Bin
					fread(&Hotel[(Indice[0])-1], sizeof(DADOS_HOTEL),1,Arquivo);//Realoca o ponteiro
				}else{
					fscanf(Arquivo,"%d",&Hotel[(Indice[0])-1].Codigo);
					//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
					getc(Arquivo);
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Nome_Fantasia);					//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Razao_Social);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Inscricao_Estadual);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].CNPJ);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Endereco.Logradouro);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Endereco.Numero);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Endereco.Bairro);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Endereco.Cidade);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Telefone);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Email);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Dono_Gerente);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Telefone_Gerente);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Check_in);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%[^;]s",Hotel[(Indice[0])-1].Check_out);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%d",&Hotel[(Indice[0])-1].Lucro);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o \n)
				}
				
				if(feof(Arquivo)){
					break;//Sai do loop ao chegar no fim do arquivo
				}
				Indice[0]++;//Adiciona 1 ao Contador;
			}
			fclose(Arquivo);//Fecha o Arquivo
			//Pega dados 
	
			fprintf(Exporta, "<tabela=DADOS_HOTEL>\n");
			for (int i = 0; i < Indice[0]-1; ++i)//Salva em Txt
			{
				fprintf(Exporta, "\t<registro>\n");
					fprintf(Exporta, "\t\t<Codigo>%d</Codigo>\n",Hotel[i].Codigo);
					fprintf(Exporta, "\t\t<Nome_Fantasia>%s</Nome_Fantasia>\n",Hotel[i].Nome_Fantasia);
					fprintf(Exporta, "\t\t<Razao_Social>%s</Razao_Social>\n",Hotel[i].Razao_Social);
					fprintf(Exporta, "\t\t<Inscricao_Estadual>%s</Inscricao_Estadual>\n",Hotel[i].Inscricao_Estadual);
					fprintf(Exporta, "\t\t<CNPJ>%s</CNPJ>\n",Hotel[i].CNPJ);
					fprintf(Exporta, "\t\t<Logradouro>%s</Logradouro>\n",Hotel[i].Endereco.Logradouro);
					fprintf(Exporta, "\t\t<Numero>%s</Numero>\n",Hotel[i].Endereco.Numero);
					fprintf(Exporta, "\t\t<Bairro>%s</Bairro>\n",Hotel[i].Endereco.Bairro);
					fprintf(Exporta, "\t\t<Cidade>%s</Cidade>\n",Hotel[i].Endereco.Cidade);
					fprintf(Exporta, "\t\t<Telefone>%s</Telefone>\n",Hotel[i].Telefone);
					fprintf(Exporta, "\t\t<Email>%s</Email>\n",Hotel[i].Email);
					fprintf(Exporta, "\t\t<Dono_Gerente>%s</Dono_Gerente>\n",Hotel[i].Dono_Gerente);
					fprintf(Exporta, "\t\t<Telefone_Gerente>%s</Telefone_Gerente>\n",Hotel[i].Telefone_Gerente);
					fprintf(Exporta, "\t\t<Check_in>%s</Check_in>\n",Hotel[i].Check_in);
					fprintf(Exporta, "\t\t<Check_out>%s</Check_out>\n",Hotel[i].Check_out);
					fprintf(Exporta, "\t\t<Lucro>%d</Lucro>\n",Hotel[i].Lucro);
				fprintf(Exporta, "\t</registro>\n");
			}
			fprintf(Exporta, "</tabela>\n");
			//Salva em Xml
		}

		if(On_Off.Hospede==1){
			if(Modo_Abertura==Arquivo_Binario){//Bin
				Arquivo=fopen("Arquivos/Hospede.bin","rb");//Somente leitura
			}else{//Txt
				Arquivo=fopen("Arquivos/Hospede.txt","r");//Somente leitura
			}
			//Abre o Arquivo
			
			while(Loop){//Passa do Arquivo pra Memoria
				Hospede=realloc(Hospede,Indice[1]*sizeof(DADOS_HOSPEDE));//Realoca o ponteiro
				if(Modo_Abertura==Arquivo_Binario){//Bin
					fread(&Hospede[(Indice[1])-1], sizeof(DADOS_HOSPEDE),1,Arquivo);//Realoca o ponteiro
				}else{//Txt
					fscanf(Arquivo,"%d",&Hospede[(Indice[1])-1].Codigo);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";" Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede[(Indice[1])-1].Nome);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";" Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede[(Indice[1])-1].Sexo);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede[(Indice[1])-1].Estado_Civil);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede[(Indice[1])-1].CPF);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede[(Indice[1])-1].Endereco.Logradouro);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede[(Indice[1])-1].Endereco.Numero);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede[(Indice[1])-1].Endereco.Bairro);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede[(Indice[1])-1].Endereco.Cidade);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede[(Indice[1])-1].Telefone);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede[(Indice[1])-1].Email);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede[(Indice[1])-1].Data_Nascimento);//Expreção Regular
					getc(Arquivo);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o \n)
				}
				
				if(feof(Arquivo)){
					break;//Sai do loop ao chegar no fim do arquivo
				}
				Indice[1]++;//Adiciona 1 ao Contador;
			}
			fclose(Arquivo);//Fecha o Arquivo
			//Escrevendo em XML
			fprintf(Exporta, "<tabela=DADOS_HOSPEDE>\n");
			for (int i = 0; i < Indice[1]-1; ++i)//Salva em Txt
			{
				fprintf(Exporta, "\t<registro>\n");
					fprintf(Exporta, "\t\t<Codigo>%d</Codigo>\n",Hospede[i].Codigo);
					fprintf(Exporta, "\t\t<Nome>%s</Nome>\n",Hospede[i].Nome);
					fprintf(Exporta, "\t\t<CPF>%s</CPF>\n",Hospede[i].CPF);
					fprintf(Exporta, "\t\t<Logradouro>%s</Logradouro>\n",Hospede[i].Endereco.Logradouro);
					fprintf(Exporta, "\t\t<Numero>%s</Numero>\n",Hospede[i].Endereco.Numero);
					fprintf(Exporta, "\t\t<Bairro>%s</Bairro>\n",Hospede[i].Endereco.Bairro);
					fprintf(Exporta, "\t\t<Cidade>%s</Cidade>\n",Hospede[i].Endereco.Cidade);
					fprintf(Exporta, "\t\t<Telefone>%s</Telefone>\n",Hospede[i].Telefone);
					fprintf(Exporta, "\t\t<Email>%s</Email>\n",Hospede[i].Email);
					fprintf(Exporta, "\t\t<Sexo>%s</Sexo>\n",Hospede[i].Sexo);
					fprintf(Exporta, "\t\t<Estado_Civil>%s</Estado_Civil>\n",Hospede[i].Estado_Civil);
					fprintf(Exporta, "\t\t<Data_Nascimento>%s</Data_Nascimento>\n",Hospede[i].Data_Nascimento);
				fprintf(Exporta, "\t</registro>\n");
			}
			fprintf(Exporta, "</tabela>\n");
		}
	
		if(On_Off.Codigo_Categoria==1){
			if(Modo_Abertura==Arquivo_Binario){//Bin
				Arquivo=fopen("Arquivos/Codigo_Categoria.bin","rb");//Somente leitura
			}else{//Txt
				Arquivo=fopen("Arquivos/Codigo_Categoria.txt","r");//Somente leitura
			}
			//Abre o Arquivo
			
			while(Loop){//Passa do Arquivo pra Memoria
				Codigo_Categoria=realloc(Codigo_Categoria,Indice[2]*sizeof(CODIGO_CATEGORIA));//Realoca o ponteiro
				if(Modo_Abertura==Arquivo_Binario){//Bin
					fread(&Codigo_Categoria[(Indice[2])-1], sizeof(CODIGO_CATEGORIA),1,Arquivo);//
				}else{
					
					fscanf(Arquivo,"%d",&Codigo_Categoria[(Indice[2])-1].Codigo);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";" Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%[^;]s",Codigo_Categoria[(Indice[2])-1].Descricao);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%f",&Codigo_Categoria[(Indice[2])-1].Valor_Diaria);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Codigo_Categoria[(Indice[2])-1].Capacidade_Adulto);
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Codigo_Categoria[(Indice[2])-1].Capacidade_Crianca);//Expreção Regular
					getc(Arquivo);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o \n)
				}
	
				if(feof(Arquivo)){
					break;//Sai do loop ao chegar no fim do arquivo
				}
				Indice[2]++;//Adiciona 1 ao Contador;
			}
			fclose(Arquivo);
	
	
			fprintf(Exporta, "<tabela=CODIGO_CATEGORIA>\n");
			for (int i = 0; i < Indice[2]-1; ++i)//Salva em Txt
			{
				fprintf(Exporta, "\t<registro>\n");
					fprintf(Exporta, "\t\t<Codigo>%d</Codigo>\n",Codigo_Categoria[i].Codigo);
					fprintf(Exporta, "\t\t<Descricao>%s</Descricao>\n",Codigo_Categoria[i].Descricao);
					fprintf(Exporta, "\t\t<Valor_Diaria>%.2f</Valor_Diaria>\n",Codigo_Categoria[i].Valor_Diaria);
					fprintf(Exporta, "\t\t<Capacidade_Adulto>%i</Capacidade_Adulto>\n",Codigo_Categoria[i].Capacidade_Adulto);
					fprintf(Exporta, "\t\t<Capacidade_Crianca>%i</Capacidade_Crianca>\n",Codigo_Categoria[i].Capacidade_Crianca);
				fprintf(Exporta, "\t</registro>\n");
			}
			fprintf(Exporta, "</tabela>\n");
		}
	
		if(On_Off.Acomodacoes==1){
			if(Modo_Abertura==Arquivo_Binario){//Bin
				Arquivo=fopen("Arquivos/Acomodacoes.bin","rb");//Somente leitura
			}else{//Txt
				Arquivo=fopen("Arquivos/Acomodacoes.txt","r");//Somente leitura
			}
	
			//Abre o Arquivo
			while(Loop){//Passa do Arquivo pra Memoria
				Acomodacoes=realloc(Acomodacoes,Indice[3]*sizeof(ACOMODACOES));//Realoca o ponteiro
				if(Modo_Abertura==Arquivo_Binario){//Bin
					fread(&Acomodacoes[(Indice[3])-1], sizeof(ACOMODACOES),1,Arquivo);//
				}else{
					
					fscanf(Arquivo,"%d",&Acomodacoes[(Indice[3])-1].Codigo);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Acomodacoes[(Indice[3])-1].Descricao);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes[(Indice[3])-1].Facilidades.Televisao);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes[(Indice[3])-1].Facilidades.Ar_Condicionado);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes[(Indice[3])-1].Facilidades.Frigobar);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes[(Indice[3])-1].Facilidades.Internet);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes[(Indice[3])-1].Facilidades.Banheira);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes[(Indice[3])-1].Cod_Categoria);//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%d",&Acomodacoes[(Indice[3])-1].Cod_Hotel);//Expreção Regular
					getc(Arquivo);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o \n)
				}
				if(feof(Arquivo)){
					break;//Sai do loop ao chegar no fim do arquivo
				}
				Indice[3]++;//Adiciona 1 ao Contador;
			}
			fclose(Arquivo);//Fecha o Arquivo
			//Escrevendo em XML
			fprintf(Exporta, "<tabela=ACOMODACOES>\n");
			for (int i = 0; i < Indice[3]-1; ++i)//Salva em Txt
			{fprintf(Exporta, "\t<registro>\n");
					fprintf(Exporta, "\t\t<Codigo>%d</Codigo>\n",Acomodacoes[i].Codigo);
					fprintf(Exporta, "\t\t<Descricao>%s</Descricao>\n",Acomodacoes[i].Descricao);
					fprintf(Exporta, "\t\t<Televisao>%d</Televisao>\n",Acomodacoes[i].Facilidades.Televisao);
					fprintf(Exporta, "\t\t<Ar_Condicionado>%d</Ar_Condicionado>\n",Acomodacoes[i].Facilidades.Ar_Condicionado);
					fprintf(Exporta, "\t\t<Frigobar>%d</Frigobar>\n",Acomodacoes[i].Facilidades.Frigobar);
					fprintf(Exporta, "\t\t<Internet>%d</Internet>\n",Acomodacoes[i].Facilidades.Internet);
					fprintf(Exporta, "\t\t<Banheira>%d</Banheira>\n",Acomodacoes[i].Facilidades.Banheira);
					fprintf(Exporta, "\t\t<Cod_Categoria>%d</Cod_Categoria>\n",Acomodacoes[i].Cod_Categoria);
					fprintf(Exporta, "\t\t<Cod_Hotel>%d</Cod_Hotel>\n",Acomodacoes[i].Cod_Hotel);
				fprintf(Exporta, "\t</registro>\n");
			}
			fprintf(Exporta, "</tabela>\n");
		}
	
		if(On_Off.Fornecedores==1){
			if(Modo_Abertura==Arquivo_Binario){//Bin
				Arquivo=fopen("Arquivos/Fornecedores.bin","rb");//Somente leitura
			}else{//Txt
				Arquivo=fopen("Arquivos/Fornecedores.txt","r");//Somente leitura
			}
			//Abre o Arquivo
	
			while(Loop){//Passa do Arquivo pra Memoria
				Fornecedores=realloc(Fornecedores,Indice[4]*sizeof(FORNECEDORES));//Realoca o ponteiro
				if(Modo_Abertura==Arquivo_Binario){//Bin
					fread(&Fornecedores[(Indice[4])-1], sizeof(FORNECEDORES),1,Arquivo);//
				}else{
					fscanf(Arquivo,"%d",&Fornecedores[(Indice[4])-1].Codigo);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";" Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Fornecedores[(Indice[4])-1].Nome_Fantasia);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";" Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Fornecedores[(Indice[4])-1].Razao_Social);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Fornecedores[(Indice[4])-1].Inscricao_Estadual);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Fornecedores[(Indice[4])-1].CNPJ);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Fornecedores[(Indice[4])-1].Endereco.Logradouro);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Fornecedores[(Indice[4])-1].Endereco.Numero);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Fornecedores[(Indice[4])-1].Endereco.Bairro);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Fornecedores[(Indice[4])-1].Endereco.Cidade);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Fornecedores[(Indice[4])-1].Telefone);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Fornecedores[(Indice[4])-1].Email);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o \n)
				}
				if(feof(Arquivo)){
					break;//Sai do loop ao chegar no fim do arquivo
				}
				Indice[4]++;//Adiciona 1 ao Contador;
			}
			fclose(Arquivo);//Fecha o Arquivo
	
			//Escrevendo em XML
			fprintf(Exporta, "<tabela=FORNECEDORES>\n");
			for (int i = 0; i < Indice[4]-1; ++i)//Salva em Txt
			{
				fprintf(Exporta, "\t<registro>\n");
					fprintf(Exporta, "\t\t<Codigo>%d</Codigo>\n",Fornecedores[i].Codigo);
					fprintf(Exporta, "\t\t<Nome_Fantasia>%s</Nome_Fantasia>\n",Fornecedores[i].Nome_Fantasia);
					fprintf(Exporta, "\t\t<Razao_Social>%s</Razao_Social>\n",Fornecedores[i].Razao_Social);
					fprintf(Exporta, "\t\t<Inscricao_Estadual>%s</Inscricao_Estadual>\n",Fornecedores[i].Inscricao_Estadual);
					fprintf(Exporta, "\t\t<CNPJ>%s</CNPJ>\n",Fornecedores[i].CNPJ);
					fprintf(Exporta, "\t\t<Logradouro>%s</Logradouro>\n",Fornecedores[i].Endereco.Logradouro);
					fprintf(Exporta, "\t\t<Numero>%s</Numero>\n",Fornecedores[i].Endereco.Numero);
					fprintf(Exporta, "\t\t<Bairro>%s</Bairro>\n",Fornecedores[i].Endereco.Bairro);
					fprintf(Exporta, "\t\t<Cidade>%s</Cidade>\n",Fornecedores[i].Endereco.Cidade);
					fprintf(Exporta, "\t\t<Telefone>%s</Telefone>\n",Fornecedores[i].Telefone);
					fprintf(Exporta, "\t\t<Email>%s</Email>\n",Fornecedores[i].Email);
				fprintf(Exporta, "\t</registro>\n");
	
			}
			fprintf(Exporta, "</tabela>\n");
		}
	
		if(On_Off.Funcionarios==1){
			if(Modo_Abertura==Arquivo_Binario){//Bin
				Arquivo=fopen("Arquivos/Funcionarios.bin","rb");//Somente leitura
			}else{//Txt
				Arquivo=fopen("Arquivos/Funcionarios.txt","r");//Somente leitura
			}
			//Abre o Arquivo
	
			while(Loop){//Passa do Arquivo pra Memoria
				Funcionarios=realloc(Funcionarios,Indice[5]*sizeof(FUNCIONARIOS));//Realoca o ponteiro
				if(Modo_Abertura==Arquivo_Binario){//Bin
					fread(&Funcionarios[(Indice[5])-1], sizeof(FUNCIONARIOS),1,Arquivo);//
				}else{//TXT
					fscanf(Arquivo,"%d",&Funcionarios[(Indice[5])-1].Codigo);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Funcionarios[(Indice[5])-1].Nome);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Funcionarios[(Indice[5])-1].Usuario);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Funcionarios[(Indice[5])-1].Senha);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Funcionarios[(Indice[5])-1].Permissao);//Expreção Regular
					getc(Arquivo);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o \n)
				}
	
				if(feof(Arquivo)){
					break;//Sai do loop ao chegar no fim do arquivo
				}
				Indice[5]++;//Adiciona 1 ao Contador;
			}
			fclose(Arquivo);//Fecha o Arquivo
	
			//Escrevendo em XML
			fprintf(Exporta, "<tabela=FUNCIONARIOS>\n");
			for (int i = 0; i < Indice[5]-1; ++i)//Salva em Txt
			{
				fprintf(Exporta, "\t<registro>\n");
					fprintf(Exporta, "\t\t<Codigo>%d</Codigo>\n",Funcionarios[i].Codigo);
					fprintf(Exporta, "\t\t<Nome>%s</Nome>\n",Funcionarios[i].Nome);
					fprintf(Exporta, "\t\t<Usuario>%s</Usuario>\n",Funcionarios[i].Usuario);
					fprintf(Exporta, "\t\t<Senha>%s</Senha>\n",Funcionarios[i].Senha);//OLHAR SE ESTA CRIPITOGRAFADA
					fprintf(Exporta, "\t\t<Permissao>%d</Permissao>\n",Funcionarios[i].Permissao);
				fprintf(Exporta, "\t</registro>\n");
	
			}
			fprintf(Exporta, "</tabela>\n");
		}
	
		if(On_Off.Produtos==1){
			if(Modo_Abertura==Arquivo_Binario){//Bin
				Arquivo=fopen("Arquivos/Produtos.bin","rb");//Somente leitura
			}else{//Txt
				Arquivo=fopen("Arquivos/Produtos.txt","r");//Somente leitura
			}
			//Abre o Arquivo
	
	
			while(Loop){//Passa do Arquivo pra Memoria
				Produtos=realloc(Produtos,Indice[6]*sizeof(PRODUTOS));//Realoca o ponteiro
				if(Modo_Abertura==Arquivo_Binario){//Bin
					fread(&Produtos[(Indice[6])-1], sizeof(PRODUTOS),1,Arquivo);//
				}else{					
					fscanf(Arquivo,"%d",&Produtos[(Indice[6])-1].Codigo);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";" //Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%u",&Produtos[(Indice[6])-1].Estoque);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";" //Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%u",&Produtos[(Indice[6])-1].Estoque_Minimo);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Produtos[(Indice[6])-1].Descricao);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%f",&Produtos[(Indice[6])-1].Preco_Custo);//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%f",&Produtos[(Indice[6])-1].Preco_Venda);//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%d",&Produtos[(Indice[6])-1].Cod_Hotel);//Expreção Regular
					getc(Arquivo);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o \n)
				}
				if(feof(Arquivo)){
					break;//Sai do loop ao chegar no fim do arquivo
				}
				Indice[6]++;//Adiciona 1 ao Contador;
			}
			fclose(Arquivo);//Fecha o Arquivo
			//Escrevendo em XML
			fprintf(Exporta, "<tabela=PRODUTOS>\n");
			for (int i = 0; i < Indice[6]-1; ++i)//Salva em Txt
			{
				fprintf(Exporta, "\t<registro>\n");
					fprintf(Exporta, "\t\t<Codigo>%d</Codigo>\n",Produtos[i].Codigo);
					fprintf(Exporta, "\t\t<Estoque>%u</Estoque>\n",Produtos[i].Estoque);
					fprintf(Exporta, "\t\t<Estoque_Minimo>%u</Estoque_Minimo>\n",Produtos[i].Estoque_Minimo);
					fprintf(Exporta, "\t\t<Descricao>%s</Descricao>\n",Produtos[i].Descricao);
					fprintf(Exporta, "\t\t<Preco_Custo>%.2f</Preco_Custo>\n",Produtos[i].Preco_Custo);
					fprintf(Exporta, "\t\t<Preco_Venda>%.2f</Preco_Venda>\n",Produtos[i].Preco_Venda);
					fprintf(Exporta, "\t\t<Cod_Hotel>%d</Cod_Hotel>\n",Produtos[i].Cod_Hotel);
				fprintf(Exporta, "\t</registro>\n");
	
			}
			fprintf(Exporta, "</tabela>\n");
		}
	
		if(On_Off.Reserva==1){
			if(Modo_Abertura==Arquivo_Binario){//Bin
				Arquivo=fopen("Arquivos/Reserva.bin","rb");//Somente leitura
			}else{//Txt
				Arquivo=fopen("Arquivos/Reserva.txt","r");//Somente leitura
			}
			//Abre o Arquivo
	
			while(Loop){//Passa do Arquivo pra Memoria
				Reserva=realloc(Reserva,Indice[7]*sizeof(RESERVA));//Realoca o ponteiro
				
				if(Modo_Abertura==Arquivo_Binario){//Bin
					fread(&Reserva[(Indice[7])-1], sizeof(RESERVA),1,Arquivo);//
				}else{						
					fscanf(Arquivo,"%d",&Reserva[(Indice[7])-1].Codigo);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%[^;]s",Reserva[(Indice[7])-1].Nome_Hospede);//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"//Expreção Regular
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%d",&Reserva[(Indice[7])-1].Codigo_Hospede);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%d",&Reserva[(Indice[7])-1].Cod_Acomodacao);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%u",&Reserva[(Indice[7])-1].Data_Entrada.Dia);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
					fscanf(Arquivo,"%u",&Reserva[(Indice[7])-1].Data_Entrada.Mes);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
					fscanf(Arquivo,"%u",&Reserva[(Indice[7])-1].Data_Entrada.Ano);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%u",&Reserva[(Indice[7])-1].Data_Saida.Dia);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
					fscanf(Arquivo,"%u",&Reserva[(Indice[7])-1].Data_Saida.Mes);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
					fscanf(Arquivo,"%u",&Reserva[(Indice[7])-1].Data_Saida.Ano);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%u",&Reserva[(Indice[7])-1].Data_Vencimento_Fatura.Dia);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
					fscanf(Arquivo,"%u",&Reserva[(Indice[7])-1].Data_Vencimento_Fatura.Mes);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o /)
					fscanf(Arquivo,"%u",&Reserva[(Indice[7])-1].Data_Vencimento_Fatura.Ano);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%f",&Reserva[(Indice[7])-1].Valor_Fatura);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%d",&Reserva[(Indice[7])-1].Pago);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%f",&Reserva[(Indice[7])-1].Valor_Conta);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					fscanf(Arquivo,"%d",&Reserva[(Indice[7])-1].Modo_Pagamento);
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
					getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o \n)
				}
				if(feof(Arquivo)){
					break;//Sai do loop ao chegar no fim do arquivo
				}
				Indice[7]++;//Adiciona 1 ao Contador;
			}
			fclose(Arquivo);//Fecha o Arquivo
			
	
			//Escrevendo em XML
			fprintf(Exporta, "<tabela=RESERVA>\n");
			for (int i = 0; i < Indice[7]-1; ++i)//Salva em Txt
			{
				fprintf(Exporta, "\t<registro>\n");
					fprintf(Exporta, "\t\t<Codigo>%d</Codigo>\n",Reserva[i].Codigo);
					fprintf(Exporta, "\t\t<Nome_Hospede>%s</Nome_Hospede>\n",Reserva[i].Nome_Hospede);
					fprintf(Exporta, "\t\t<Codigo_Hospede>%d</Codigo_Hospede>\n",Reserva[i].Codigo_Hospede);
					fprintf(Exporta, "\t\t<Cod_Acomodacao>%d</Cod_Acomodacao>\n",Reserva[i].Cod_Acomodacao);
					fprintf(Exporta, "\t\t<Data_Entrada.Dia>%u</Data_Entrada.Dia>\n",Reserva[i].Data_Entrada.Dia);
					fprintf(Exporta, "\t\t<Data_Entrada.Mes>%u</Data_Entrada.Mes>\n",Reserva[i].Data_Entrada.Mes);
					fprintf(Exporta, "\t\t<Data_Entrada.Ano>%u</Data_Entrada.Ano>\n",Reserva[i].Data_Entrada.Ano);
					fprintf(Exporta, "\t\t<Data_Saida.Dia>%u</Data_Saida.Dia>\n",Reserva[i].Data_Saida.Dia);
					fprintf(Exporta, "\t\t<Data_Saida.Mes>%u</Data_Saida.Mes>\n",Reserva[i].Data_Saida.Mes);
					fprintf(Exporta, "\t\t<Data_Saida.Ano>%u</Data_Saida.Ano>\n",Reserva[i].Data_Saida.Ano);
					fprintf(Exporta, "\t\t<Data_Vencimento_Fatura.Dia>%u</Data_Vencimento_Fatura.Dia>\n",Reserva[i].Data_Vencimento_Fatura.Dia);
					fprintf(Exporta, "\t\t<Data_Vencimento_Fatura.Mes>%u</Data_Vencimento_Fatura.Mes>\n",Reserva[i].Data_Vencimento_Fatura.Mes);
					fprintf(Exporta, "\t\t<Data_Vencimento_Fatura.Ano>%u</Data_Vencimento_Fatura.Ano>\n",Reserva[i].Data_Vencimento_Fatura.Ano);
					fprintf(Exporta, "\t\t<Valor_Fatura>%.2f</Valor_Fatura>\n",Reserva[i].Valor_Fatura);
					fprintf(Exporta, "\t\t<Pago>%d</Pago>\n",Reserva[i].Pago);
					fprintf(Exporta, "\t\t<Valor_Conta>%.2f</Valor_Conta>\n",Reserva[i].Valor_Conta);
					fprintf(Exporta, "\t\t<Modo_Pagamento>%d</Modo_Pagamento>\n",Reserva[i].Modo_Pagamento);
					//VOLTAR E IMPLEMENTAR EXPORTACAO DE PRODUTO ASSIM QUE ACABAR FLUXO DE CAIXA
					//fprintf(Exporta, "\t\t<Codigo_Produto>%d</Codigo_Produto>\n",Reserva[i].Codigo_Produto);
					//fprintf(Exporta, "\t\t<Quantidade_De_Produtos>%d</Quantidade_De_Produtos>\n",Reserva[i].Quantidade_De_Produtos);
					//fprintf(Exporta, "\t\t<Prazo_Vista>%d</Prazo_Vista>\n",Reserva[i].Prazo_Vista);
				fprintf(Exporta, "\t</registro>\n");
	
			}
			fprintf(Exporta, "</tabela>\n");		
		}
	fclose(Exporta);
	}
	
	void Importacao(){
		int Loop=1,Indice[]={1,1,1,1,1,1,1,1,1};


		DADOS_HOTEL *Hotel = malloc(sizeof(DADOS_HOTEL)); 
		DADOS_HOSPEDE *Hospede = malloc(sizeof(DADOS_HOSPEDE)); 
		ACOMODACOES *Acomodacoes=malloc(sizeof(ACOMODACOES));
		CODIGO_CATEGORIA *Codigo_Categoria = malloc(sizeof(CODIGO_CATEGORIA)); 
		PRODUTOS *Produtos = malloc(sizeof(PRODUTOS)); 
		FORNECEDORES *Fornecedores = malloc(sizeof(FORNECEDORES)); 
		FUNCIONARIOS *Funcionarios = malloc(sizeof(FUNCIONARIOS)); 
		RESERVA *Reserva = malloc(sizeof(RESERVA)); 

		char Url[Tamanho2],Temp[Tamanho2];
		char Tag[Tamanho2];
		int Contador=0;
		FILE *Arquivo,*Salvar;
		int Modo_Abertura = Configuracoes();
		//{ Cria as Variaveis }//
		
		
		
		Verde("Caso o Arquivo esteja nesta pasta digite apenas o nome do arquivo caso contrario digite todo o caminho");
		printf("\nDigite o Local do Arquivo:");
		scanf("%s",Url);
		strcat(Url,".xml");
		//{ Pega url do arquivo }//
		
		
		
		Arquivo=fopen(Url,"r");
		if(Arquivo==NULL){
			system("clear");
			Vermelho(Url);
			printf(" não é um arquivo válido\n");
			Verde("\n\nDigite um numero  e pressione enter para Continuar");
			PAUSA
			return;
		}else{
		//{ Abre arquivo em modo txt }//
			do{
				fscanf(Arquivo,"%[^<]s",Temp);//Le a até o inicio da tag
				getc(Arquivo);//pula<
				fscanf(Arquivo,"%[^>]s",Tag);//pula até o >
				getc(Arquivo);//pula>
				getc(Arquivo);//pula\n
				//Le tag 
				
				if(strcmp(Tag,"tabela=DADOS_HOTEL")==0){ //Verifica se está na  tabela Hospede
					while(Loop){
						fscanf(Arquivo,"%[^<]s",Temp);//Le a até o inicio da tag
						getc(Arquivo);//pula<
						fscanf(Arquivo,"%[^>]s",Tag);//pula até o >
						getc(Arquivo);//pula>
						getc(Arquivo);//pula\n
						//Le tag
						
						if(strcmp (Tag,"/tabela")==0){
							Indice[0]--;//Corrige o Indice

							if (Modo_Abertura==Arquivo_Binario)
							{
								Salvar=fopen("Arquivos/Hotel.bin","wb");
								fclose(Salvar);
								//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
								for (int i = 0; i < Indice[0]; ++i)
								{
									Gravar_Hotel_Bin("Arquivos/Hotel.bin",&Hotel[i]);
									system("clear");
								}
								
							}else{
								Salvar=fopen("Arquivos/Hotel.txt","w");
								fclose(Salvar);
								//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
								for (int i = 0; i < Indice[0]; ++i)
								{
									Gravar_Hotel_Txt("Arquivos/Hotel.txt",&Hotel[i]);
									system("clear");
								}
							}
							break;//significa que chegou ao fim da tag
						}else{
							if(strcmp (Tag,"registro")==0){//Entramos em uma nova reserva

								Hotel=realloc(Hotel,Indice[0]*sizeof(DADOS_HOTEL));//Realoca o ponteiro

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%d",&Hotel[Indice[0]-1].Codigo);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Nome_Fantasia);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Razao_Social);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Inscricao_Estadual);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].CNPJ);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Endereco.Logradouro);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Endereco.Numero);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Endereco.Bairro);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Endereco.Cidade);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Telefone);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Email);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Dono_Gerente);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Telefone_Gerente);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Check_in);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Check_out);
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);

								fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
								getc(Arquivo);
								fscanf(Arquivo,"%d",&Hotel[Indice[0]-1].Lucro);				
								fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
								getc(Arquivo);
								
								
							}else{
								if(strcmp (Tag,"/registro")==0){
									Indice[0]++;//Adiciona um ao indice quando fechar a tag ou seja um reserva foi salva na memoria
								}
							}
						}
					}
				}else{
					if(strcmp(Tag,"tabela=DADOS_HOSPEDE")==0){ //Verifica se está na  tabela Hospede
						while(Loop){
							fscanf(Arquivo,"%[^<]s",Temp);//Le a até o inicio da tag
							getc(Arquivo);//pula<
							fscanf(Arquivo,"%[^>]s",Tag);//pula até o >
							getc(Arquivo);//pula>
							getc(Arquivo);//pula\n
							//Le tag
							
							if(strcmp (Tag,"/tabela")==0){
								Indice[1]--;//Corrige o Indice

								if (Modo_Abertura==Arquivo_Binario)
								{
									Salvar=fopen("Arquivos/Hospede.bin","wb");
									fclose(Salvar);
									//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
									for (int i = 0; i < Indice[1]; ++i)
									{
										Gravar_Hospede_Bin("Arquivos/Hospede.bin",&Hospede[i]);
										system("clear");
									}
									
								}else{
									Salvar=fopen("Arquivos/Hospede.txt","w");
									fclose(Salvar);
									//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
									for (int i = 0; i < Indice[1]; ++i)
									{
										Gravar_Hospede_Txt("Arquivos/Hospede.txt",&Hospede[i]);
										system("clear");
									}
								}
								break;//significa que chegou ao fim da tag
							}else{
								if(strcmp (Tag,"registro")==0){//Entramos em uma nova reserva

									Hospede=realloc(Hospede,Indice[1]*sizeof(DADOS_HOSPEDE));//Realoca o ponteiro

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%d",&Hospede[Indice[1]-1].Codigo);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%[^<]s",Hospede[Indice[1]-1].Nome);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%[^<]s",Hospede[Indice[1]-1].CPF);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%[^<]s",Hospede[Indice[1]-1].Endereco.Logradouro);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%[^<]s",Hospede[Indice[1]-1].Endereco.Numero);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%[^<]s",Hospede[Indice[1]-1].Endereco.Bairro);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%[^<]s",Hospede[Indice[1]-1].Endereco.Cidade);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%[^<]s",Hospede[Indice[1]-1].Telefone);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%[^<]s",Hospede[Indice[1]-1].Email);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%[^<]s",Hospede[Indice[1]-1].Sexo);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%[^<]s",Hospede[Indice[1]-1].Estado_Civil);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);

									fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
									getc(Arquivo);
									fscanf(Arquivo,"%[^<]s",Hospede[Indice[1]-1].Data_Nascimento);
									fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
									getc(Arquivo);							
									
								}else{
									if(strcmp (Tag,"/registro")==0){
										Indice[1]++;//Adiciona um ao indice quando fechar a tag ou seja um reserva foi salva na memoria
									}
								}
							}
						}
					}else{
						if(strcmp(Tag,"tabela=ACOMODACOES")==0){ //Verifica se está na  tabela Acomodacoes
								while(Loop){
									fscanf(Arquivo,"%[^<]s",Temp);//Le a até o inicio da tag
									getc(Arquivo);//pula<
									fscanf(Arquivo,"%[^>]s",Tag);//pula até o >
									getc(Arquivo);//pula>
									getc(Arquivo);//pula\n
									//Le tag
									
									if(strcmp (Tag,"/tabela")==0){
										Indice[3]--;//Corrige o Indice

										if (Modo_Abertura==Arquivo_Binario)
										{
											Salvar=fopen("Arquivos/Acomodacoes.bin","wb");
											fclose(Salvar);
											//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
											for (int i = 0; i < Indice[3]; ++i)
											{
												Gravar_Acomodacoes_Bin("Arquivos/Acomodacoes.bin",&Acomodacoes[i]);
												system("clear");
											}
											
										}else{
											Salvar=fopen("Arquivos/Acomodacoes.bin","w");
											fclose(Salvar);
											//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
											for (int i = 0; i < Indice[3]; ++i)
											{
												Gravar_Acomodacoes_Txt("Arquivos/Acomodacoes.txt",&Acomodacoes[i]);
												system("clear");
											}
										}
										break;//significa que chegou ao fim da tag
									}else{
										if(strcmp (Tag,"registro")==0){//Entramos em uma nova reserva

											Acomodacoes=realloc(Acomodacoes,Indice[3]*sizeof(ACOMODACOES));//Realoca o ponteiro

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%d",&Acomodacoes[Indice[3]-1].Codigo);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%[^<]s",Acomodacoes[Indice[3]-1].Descricao);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%d",&Acomodacoes[Indice[3]-1].Facilidades.Televisao);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%d",&Acomodacoes[Indice[3]-1].Facilidades.Ar_Condicionado);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%d",&Acomodacoes[Indice[3]-1].Facilidades.Frigobar);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%d",&Acomodacoes[Indice[3]-1].Facilidades.Internet);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%d",&Acomodacoes[Indice[3]-1].Facilidades.Banheira);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%d",&Acomodacoes[Indice[3]-1].Cod_Categoria);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%d",&Acomodacoes[Indice[3]-1].Cod_Hotel);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);
											
										}else{
											if(strcmp (Tag,"/registro")==0){
												Indice[3]++;//Adiciona um ao indice quando fechar a tag ou seja um reserva foi salva na memoria
											}
										}
									}
								}
						}else{
							if(strcmp(Tag,"tabela=CODIGO_CATEGORIA")==0){ //Verifica se está na  tabela Codigo_Categoria
								while(Loop){
									fscanf(Arquivo,"%[^<]s",Temp);//Le a até o inicio da tag
									getc(Arquivo);//pula<
									fscanf(Arquivo,"%[^>]s",Tag);//pula até o >
									getc(Arquivo);//pula>
									getc(Arquivo);//pula\n
									//Le tag
									
									if(strcmp (Tag,"/tabela")==0){
										Indice[2]--;//Corrige o Indice

										if (Modo_Abertura==Arquivo_Binario)
										{
											Salvar=fopen("Arquivos/Codigo_Categoria.bin","wb");
											fclose(Salvar);
											//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
											for (int i = 0; i < Indice[2]; ++i)
											{
												Gravar_Codigo_Categoria_Bin("Arquivos/Codigo_Categoria.bin",&Codigo_Categoria[i]);
												system("clear");
											}
											
										}else{
											Salvar=fopen("Arquivos/Codigo_Categoria.bin","w");
											fclose(Salvar);
											//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
											for (int i = 0; i < Indice[2]; ++i)
											{
												Gravar_Codigo_Categoria_Txt("Arquivos/Codigo_Categoria.txt",&Codigo_Categoria[i]);
												system("clear");
											}
										}
										break;//significa que chegou ao fim da tag
									}else{
										if(strcmp (Tag,"registro")==0){//Entramos em uma nova reserva

											Codigo_Categoria=realloc(Codigo_Categoria,Indice[2]*sizeof(CODIGO_CATEGORIA));//Realoca o ponteiro

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%d",&Codigo_Categoria[Indice[2]-1].Codigo);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);



											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%[^<]s",Codigo_Categoria[Indice[2]-1].Descricao);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%f",&Codigo_Categoria[Indice[2]-1].Valor_Diaria);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%d",&Codigo_Categoria[Indice[2]-1].Capacidade_Adulto);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);

											fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
											getc(Arquivo);
											fscanf(Arquivo,"%d",&Codigo_Categoria[Indice[2]-1].Capacidade_Crianca);
											fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
											getc(Arquivo);
										}else{
											if(strcmp (Tag,"/registro")==0){
												Indice[2]++;//Adiciona um ao indice quando fechar a tag ou seja um reserva foi salva na memoria
											}
										}
									}
								}
							}else{
								if(strcmp(Tag,"tabela=PRODUTOS")==0){ //Verifica se está na  tabela Produtos
									while(Loop){
										fscanf(Arquivo,"%[^<]s",Temp);//Le a até o inicio da tag
										getc(Arquivo);//pula<
										fscanf(Arquivo,"%[^>]s",Tag);//pula até o >
										getc(Arquivo);//pula>
										getc(Arquivo);//pula\n
										//Le tag
										
										if(strcmp (Tag,"/tabela")==0){
											Indice[4]--;//Corrige o Indice

											if (Modo_Abertura==Arquivo_Binario)
											{
												Salvar=fopen("Arquivos/Produtos.bin","wb");
												fclose(Salvar);
												//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
												for (int i = 0; i < Indice[4]; ++i)
												{
													Gravar_Produtos_Bin("Arquivos/Produtos.bin",&Produtos[i]);
													system("clear");
												}
												
											}else{
												Salvar=fopen("Arquivos/Produtos.bin","w");
												fclose(Salvar);
												//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
												for (int i = 0; i < Indice[4]; ++i)
												{
													Gravar_Produtos_Txt("Arquivos/Produtos.txt",&Produtos[i]);
													system("clear");
												}
											}
											break;//significa que chegou ao fim da tag
										}else{
											if(strcmp (Tag,"registro")==0){//Entramos em uma nova reserva

												Produtos=realloc(Produtos,Indice[4]*sizeof(PRODUTOS));//Realoca o ponteiro

												fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
												getc(Arquivo);
												fscanf(Arquivo,"%d",&Produtos[Indice[4]-1].Codigo);
												fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
												getc(Arquivo);

												fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
												getc(Arquivo);
												fscanf(Arquivo,"%u",&Produtos[Indice[4]-1].Estoque);
												fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
												getc(Arquivo);

												fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
												getc(Arquivo);
												fscanf(Arquivo,"%u",&Produtos[Indice[4]-1].Estoque_Minimo);
												fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
												getc(Arquivo);

												fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
												getc(Arquivo);
												fscanf(Arquivo,"%[^<]s",Produtos[Indice[4]-1].Descricao);
												fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
												getc(Arquivo);

												fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
												getc(Arquivo);
												fscanf(Arquivo,"%f",&Produtos[Indice[4]-1].Preco_Custo);
												fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
												getc(Arquivo);

												fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
												getc(Arquivo);
												fscanf(Arquivo,"%f",&Produtos[Indice[4]-1].Preco_Venda);
												fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
												getc(Arquivo);

												fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
												getc(Arquivo);
												fscanf(Arquivo,"%d",&Produtos[Indice[4]-1].Cod_Hotel);
												fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
												getc(Arquivo);
												
											}else{
												if(strcmp (Tag,"/registro")==0){
													Indice[4]++;//Adiciona um ao indice quando fechar a tag ou seja um reserva foi salva na memoria
												}
											}
										}
									}
								}else{
									if(strcmp(Tag,"tabela=FORNECEDORES")==0){ //Verifica se está na  tabela Produtos
										while(Loop){
											fscanf(Arquivo,"%[^<]s",Temp);//Le a até o inicio da tag
											getc(Arquivo);//pula<
											fscanf(Arquivo,"%[^>]s",Tag);//pula até o >
											getc(Arquivo);//pula>
											getc(Arquivo);//pula\n
											//Le tag
											
											if(strcmp (Tag,"/tabela")==0){
												Indice[5]--;//Corrige o Indice

												if (Modo_Abertura==Arquivo_Binario)
												{
													Salvar=fopen("Arquivos/Fornecedores.bin","wb");
													fclose(Salvar);
													//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
													for (int i = 0; i < Indice[5]; ++i)
													{
														Gravar_Fornecedores_Bin("Arquivos/Fornecedores.bin",&Fornecedores[i]);
														system("clear");
													}
													
												}else{
													Salvar=fopen("Arquivos/Fornecedores.bin","w");
													fclose(Salvar);
													//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
													for (int i = 0; i < Indice[5]; ++i)
													{
														Gravar_Fornecedores_Txt("Arquivos/Fornecedores.txt",&Fornecedores[i]);
														system("clear");
													}
												}
												break;//significa que chegou ao fim da tag
											}else{
												if(strcmp (Tag,"registro")==0){//Entramos em uma nova reserva

													Fornecedores=realloc(Fornecedores,Indice[5]*sizeof(FORNECEDORES));//Realoca o ponteiro

													fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
													getc(Arquivo);
													fscanf(Arquivo,"%d",&Fornecedores[Indice[5]-1].Codigo);
													fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
													getc(Arquivo);

													fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
													getc(Arquivo);
													fscanf(Arquivo,"%[^<]s",Fornecedores[Indice[5]-1].Nome_Fantasia);
													fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
													getc(Arquivo);

													fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
													getc(Arquivo);
													fscanf(Arquivo,"%[^<]s",Fornecedores[Indice[5]-1].Razao_Social);
													fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
													getc(Arquivo);

													fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
													getc(Arquivo);
													fscanf(Arquivo,"%[^<]s",Fornecedores[Indice[5]-1].Inscricao_Estadual);
													fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
													getc(Arquivo);

													fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
													getc(Arquivo);
													fscanf(Arquivo,"%[^<]s",Fornecedores[Indice[5]-1].CNPJ);
													fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
													getc(Arquivo);

													fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
													getc(Arquivo);
													fscanf(Arquivo,"%[^<]s",Fornecedores[Indice[5]-1].Endereco.Logradouro);
													fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
													getc(Arquivo);

													fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
													getc(Arquivo);
													fscanf(Arquivo,"%[^<]s",Fornecedores[Indice[5]-1].Endereco.Numero);
													fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
													getc(Arquivo);

													fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
													getc(Arquivo);
													fscanf(Arquivo,"%[^<]s",Fornecedores[Indice[5]-1].Endereco.Bairro);
													fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
													getc(Arquivo);

													fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
													getc(Arquivo);
													fscanf(Arquivo,"%[^<]s",Fornecedores[Indice[5]-1].Endereco.Cidade);
													fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
													getc(Arquivo);

													fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
													getc(Arquivo);
													fscanf(Arquivo,"%[^<]s",Fornecedores[Indice[5]-1].Telefone);
													fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
													getc(Arquivo);

													fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
													getc(Arquivo);
													fscanf(Arquivo,"%[^<]s",Fornecedores[Indice[5]-1].Email);
													fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
													getc(Arquivo);
													
												}else{
													if(strcmp (Tag,"/registro")==0){
														Indice[5]++;//Adiciona um ao indice quando fechar a tag ou seja um reserva foi salva na memoria
													}
												}
											}
										}
									}else{
										if(strcmp(Tag,"tabela=FUNCIONARIOS")==0){ //Verifica se está na  tabela Funcionarios
											while(Loop){
												fscanf(Arquivo,"%[^<]s",Temp);//Le a até o inicio da tag
												getc(Arquivo);//pula<
												fscanf(Arquivo,"%[^>]s",Tag);//pula até o >
												getc(Arquivo);//pula>
												getc(Arquivo);//pula\n
												//Le tag
												
												if(strcmp (Tag,"/tabela")==0){
													Indice[6]--;//Corrige o Indice

													if (Modo_Abertura==Arquivo_Binario)
													{
														Salvar=fopen("Arquivos/Funcionarios.bin","wb");
														fclose(Salvar);
														//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
														for (int i = 0; i < Indice[6]; ++i)
														{
															Gravar_Funcionarios_Bin("Arquivos/Funcionarios.bin",&Funcionarios[i]);
															system("clear");
														}
														
													}else{
														Salvar=fopen("Arquivos/Funcionarios.bin","w");
														fclose(Salvar);
														//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
														for (int i = 0; i < Indice[6]; ++i)
														{
															Gravar_Funcionarios_Txt("Arquivos/Funcionarios.txt",&Funcionarios[i]);
															system("clear");
														}
													}
													break;//significa que chegou ao fim da tag
												}else{
													if(strcmp (Tag,"registro")==0){//Entramos em uma nova Funcionarios

														Funcionarios=realloc(Funcionarios,Indice[6]*sizeof(FUNCIONARIOS));//Realoca o ponteiro

														fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
														getc(Arquivo);
														fscanf(Arquivo,"%d",&Funcionarios[Indice[6]-1].Codigo);
														fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
														getc(Arquivo);

														fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
														getc(Arquivo);
														fscanf(Arquivo,"%[^<]s",Funcionarios[Indice[6]-1].Nome);
														fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
														getc(Arquivo);

														fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
														getc(Arquivo);
														fscanf(Arquivo,"%[^<]s",Funcionarios[Indice[6]-1].Usuario);
														fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
														getc(Arquivo);

														fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
														getc(Arquivo);
														fscanf(Arquivo,"%[^<]s",Funcionarios[Indice[6]-1].Senha);
														fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
														getc(Arquivo);

														fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
														getc(Arquivo);
														fscanf(Arquivo,"%d",&Funcionarios[Indice[6]-1].Permissao);
														fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
														getc(Arquivo);

														
													}else{
														if(strcmp (Tag,"/registro")==0){
															Indice[6]++;//Adiciona um ao indice quando fechar a tag ou seja um reserva foi salva na memoria
														}
													}
												}
											}
										}else{
											if(strcmp(Tag,"tabela=RESERVA")==0){ //Verifica se está na  tabela Reserva
												while(Loop){
													fscanf(Arquivo,"%[^<]s",Temp);//Le a até o inicio da tag
													getc(Arquivo);//pula<
													fscanf(Arquivo,"%[^>]s",Tag);//pula até o >
													getc(Arquivo);//pula>
													getc(Arquivo);//pula\n
													//Le tag													
													if(strcmp (Tag,"/tabela")==0){
														Indice[7]--;//Corrige o Indice

														if (Modo_Abertura==Arquivo_Binario)
														{
															Salvar=fopen("Arquivos/Reserva.bin","wb");
															fclose(Salvar);
															//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
															for (int i = 0; i < Indice[7]; ++i)
															{
																Gravar_Reserva_Bin("Arquivos/Reserva.bin",&Reserva[i]);
																system("clear");
															}
															
														}else{
															Salvar=fopen("Arquivos/Reserva.bin","w");
															fclose(Salvar);
															//Apaga o arquivo antigo pois abre em modo escrita e logo em seguida fecha para evitar erros
															for (int i = 0; i < Indice[7]; ++i)
															{
																DEBUG("gravou um registro")
																Gravar_Reserva_Txt("Arquivos/Reserva.txt",&Reserva[i]);
																system("clear");
															}
														}
														break;//significa que chegou ao fim da tag
													}else{
														if(strcmp (Tag,"registro")==0){//Entramos em uma nova reserva

															Reserva=realloc(Reserva,Indice[7]*sizeof(RESERVA));//Realoca o ponteiro

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Codigo);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%[^<]s",Reserva[Indice[7]-1].Nome_Hospede);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Codigo_Hospede);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Cod_Acomodacao);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Data_Entrada.Dia);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Data_Entrada.Mes);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Data_Entrada.Ano);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Data_Saida.Dia);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Data_Saida.Mes);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Data_Saida.Ano);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);


															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Data_Vencimento_Fatura.Dia);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Data_Vencimento_Fatura.Mes);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Data_Vencimento_Fatura.Ano);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%f",&Reserva[Indice[7]-1].Valor_Fatura);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Pago);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%f",&Reserva[Indice[7]-1].Valor_Conta);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);

															fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
															getc(Arquivo);
															fscanf(Arquivo,"%d",&Reserva[Indice[7]-1].Modo_Pagamento);
															fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
															getc(Arquivo);
														}else{
															if(strcmp (Tag,"/registro")==0){
																Indice[7]++;//Adiciona um ao indice quando fechar a tag ou seja um reserva foi salva na memoria
															}
														}
													}
												}
											}
										}
										
									}
								}
							}
						}
					}

				}
				if(feof(Arquivo)){
					break;
				}
			}while(Loop);
		}
	}

#endif