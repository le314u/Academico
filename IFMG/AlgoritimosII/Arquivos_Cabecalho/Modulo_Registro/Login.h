#ifndef _Login_ 
	//Se não estiver definido entra no if
#define _Login_ 

	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes
/*
int Login(MODO Modo);
void Criptografar(char Senha[]);
void Descriptografar(char Senha[]);
*/

int Login(MODO Modo){
	int Codigo=0,Linha=0,Auxiliar=0,Loop=1,Campo_Struct = 0;
	char Senha_Arquivo[999],Usuario_Arquivo[999],Senha_Digitada[999],Usuario_Digitado[999],Temporario[999];
	FUNCIONARIOS Temporarios;//Cria um struct do Tipo login
	FILE *Arquivo;//Cria um ponteiro para arquivo
 
	while(Loop==1){
		printf("Digite o CODIGO do usuario:");
		scanf("%d%*c",&Codigo);
		//Recebe o Codigo

		printf("Digite o NOME de usuario:");
		scanf("%s",Usuario_Digitado);
		//Recebe o Usuario

		char *Ponteiro_Senha = getpass("Digite a SENHA: ");//Camufla a Senha
		printf("%s",Ponteiro_Senha);
		strcpy(Senha_Digitada,Ponteiro_Senha);//Passa do ponteiro para o Vetor
		//Recebe a Senha (de modo que não aparece na tela)
		
		printf("\n");

		system("clear");
		
		if(Codigo == 666){
			if (strcmp(Usuario_Digitado,"Da50")==0)
			{
				if (strcmp(Senha_Digitada,"Manoel")==0)
				{
					printf("MODO GOD\n");
					return 15;
					//Modo god tem todas as permiossoes
				}
			}
		}

		if(Codigo == 1){
			if (strcmp(Usuario_Digitado,"1")==0)
			{
				if (strcmp(Senha_Digitada,"1")==0)
				{
					return 15;
					//Modo god tem todas as permiossoes
				}
			}
		}
		
		switch (Modo.Modo_de_Abertura){
			case Arquivo_Texto:

				Linha=Retorna_Linha_Codigo("Arquivos/Funcionarios.txt",Codigo);
				//Retorna a linha em que está salvo os dados do Login "N"

				if (Linha !=-1){
					Arquivo=fopen("Arquivos/Funcionarios.txt","r");
					
					
						for (int i = 0; i < Linha-1; ++i)//Este "FOR" serve apenas para deslocar o ponteiro
						{
							fscanf(Arquivo,"%[^\n]s",Temporario);
							getc(Arquivo);
						}
					

					fscanf(Arquivo,"%[^;]s",Temporario);
					getc(Arquivo);
					//Pula o primeiro campo Codigo

					fscanf(Arquivo,"%[^;]s",Temporario);
					getc(Arquivo);
					//Pula o segundo campo Nome

					fscanf(Arquivo,"%[^;]s",Usuario_Arquivo);
					getc(Arquivo);
					//Salva Usuario

					fscanf(Arquivo,"%[^;]s",Senha_Arquivo);
					getc(Arquivo);
					//Salva Senha


				}else{
					system("clear");
					Vermelho("O codigo digitado não existe\n");
				}

			break;
			case Arquivo_Binario:
				Arquivo = fopen("Arquivos/Funcionarios.bin",Modo.Leitura);				
				//COLOCAR A AKI A FUNÇÂO RETORNA CAMPO STRUCT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				Campo_Struct = Retorna_Campo_Struct_Funcionarios("Arquivos/Funcionarios.bin",Codigo);
				if(Campo_Struct != -1){
					for(int i=1;i<Campo_Struct;i++){
						//Vai ate o campo do codigo
						fread(&Temporarios, sizeof(FUNCIONARIOS),1,Arquivo);
					}
					fread(&Temporarios, sizeof(FUNCIONARIOS),1,Arquivo); 
					strcpy(Usuario_Arquivo,Temporarios.Usuario);
					strcpy(Senha_Arquivo,Temporarios.Senha);
				}else{
					system("clear");
					Vermelho("O codigo digitado não existe\n");
				}
			break;
		}
		if(Linha !=-1)//Caso o Codigo Tenha sido encontrado entra no IF
		{
			Auxiliar=strcmp(Usuario_Arquivo,Usuario_Digitado);
			//Compara se o Usuario foi digitado Corretamente

			if(Auxiliar==0){//Caso o cara tenha digitado o usuario corretamente
				
				Descriptografar(Senha_Arquivo);
				//Descriptografa a Senha;

				Auxiliar=strcmp(Senha_Digitada,Senha_Arquivo);
				//Compara se a Senha está correta
				
				Criptografar(Senha_Arquivo);
				//Criptografa a Senha;
				if(Auxiliar==0){

					fscanf(Arquivo,"%d",&Temporarios.Permissao);
					getc(Arquivo);
					//Lẽ as permissoes dentro do Arquivo Txt e passa para um campo da struct

					Loop=0;
					//Desligar o Loop

				}else{

					Vermelho("Senha está incorreta\n");
					Criptografar(Senha_Arquivo);
				}
			}else{
				Vermelho("Usuario está incorreto\n");
			}
		}
	}
	return Temporarios.Permissao;//Retorna as Permissoes e se o Login foi efetivado

}


void Criptografar(char Senha[]){
		for(int i=0;Senha[i];i++){
			if(i%2==0){
				Senha[i]= Senha[i]+1;
			}else{
				Senha[i]= Senha[i]-1;
			}
		}
		//Cripitografia diferente para numeros pares e numeros impares


}

void Descriptografar(char Senha[]){
	for(int i=0;Senha[i];i++){
		if(i%2==0){
			Senha[i]= Senha[i]-1;
		}else{
			Senha[i]= Senha[i]+1;
		}
	}
	//Descriptografar
}

#endif