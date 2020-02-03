//Autor		:Leandro Souza Pinheiro e Lucas Mateus Fernandes
//Ano		:2017
//Semestre	:2º Semestre
//
//Macros
int Bug;
char BUGS[999];
#define PAUSA 	scanf("%d",&Bug);
#define PAUSA_ 	scanf("%[qwertyuiopasdfghjklzxcvbnm]s",BUGS);
#define DEBUG(TEXTO) printf("\n%s%s \t Linha = %d \t %s%s\n","\33[1;31m",__FILE__, __LINE__,TEXTO,"\33[0;29m");//scanf("%d",&Bug)
#define DEBUGINT(TEXTO,INT) printf("\n%s%s \t Linha = %d \t %s%d%s\n","\33[1;32m",__FILE__,__LINE__,TEXTO,INT,"\33[0;29m");//scanf("%d",&Bug)
#define Vermelho(TEXTO)	printf("\33[1;31m%s\33[0;29m",TEXTO);
#define Vermelho_F(FLOAT)	printf("\33[1;31m%.2f\33[0;29m",FLOAT);
#define Verde(TEXTO)	printf("\33[1;32m%s\33[0;29m",TEXTO);
#define Amarelo(TEXTO)	printf("\33[1;33m%s\33[0;29m",TEXTO);
//Biblioteca Padrão
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
//Registros
#include "Arquivos_Cabecalho/Registros.h"
//Prototipos
#include "Arquivos_Cabecalho/Prototipos.h"
//Funções
#include "Arquivos_Cabecalho/Funcoes.h"
//Modulo_Registro
#include "Arquivos_Cabecalho/Modulo_Registro/Hotel.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Hospede.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Codigo_Categoria.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Acomodacoes.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Login.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Funcionarios.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Fornecedores.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Produtos.h"
//Modulo_Reserva
#include "Arquivos_Cabecalho/Modulo_Reserva/Reserva.h"
#include "Arquivos_Cabecalho/Modulo_Reserva/Pesquisa.h"
//Modulo Importacao/ExportacaoXML
#include "Arquivos_Cabecalho/Importacao_Exportacao/Importacao.h"
//Modulo FeedBack
#include "Arquivos_Cabecalho/Modulo_FeedBack/Feedback.h"
//Modulo Transacoes
#include "Arquivos_Cabecalho/Modulo_Transacao/Transacao.h"



//Macro

//Inicio


int main(int argc, char const *argv[])
{
	system("mkdir Arquivos");
	//comando do s.os
	Verificacao_All();
	//Cria todos os arquivos tanto bin quanto txt
	system("clear");
	//Limpa a tela

	while(1){
		int Enum_Manipulacao,Loop=1,Loop1 = 1;
		MODO Modo;

		Enum_Manipulacao=Configuracoes();//Retorna um inteiro referente ao modo de manipulação
		Modo=Modo_Bin_ou_Txt(Enum_Manipulacao);//Retorna uma struct com os modos txt ou bin
		int Permissao = Login(Modo);
		Modo.Nivel_De_Permissao = Permissao;
		//LOGIN retorna o tipo de permissao de 1 a 15
		while(Loop){
			Loop=1;
			Loop1=1;
			OrdenaValoresTxt();
			//Ordena os Txt em ordem crescente

			Enum_Manipulacao=Configuracoes();
			Modo=Modo_Bin_ou_Txt(Enum_Manipulacao);
			Modo.Nivel_De_Permissao = Permissao;
			//Verifica se o arquivo Configurações não foi apagado


			int Opcao_Registro;
			int Opcao_Inicial = Modulo();
			system("clear");
			switch(Opcao_Inicial){
				case Registro:
					while(Loop1){
						system("clear");
						Opcao_Registro=Main_All();//Retorna um numero inteiro referente ao case
							switch(Opcao_Registro){
								case Dados_Hotel:
									Main_Hotel(Modo);
								break;
								case Dados_Hospede:
									Main_Hospede(Modo); 	
								break;
				
								case Dados_Acomodacoes:
									Main_Acomodacoes(Modo);
								break;
				
								case Dados_Codigo_Categoria:
									Main_Codigo_Categoria(Modo);
								break;
				
								case Dados_Produtos:
									Main_Produtos(Modo);
								break;
				
								case Dados_Fornecedores:
									Main_Fornecedores(Modo);
								break;
				
								case Dados_Funcionarios:
									Main_Funcionarios(Modo);
								break;
				
								case 0:
									Loop1=0;
								break;

								default:
								break;	
							}
						}
				break;
				case Reserva:
					system("clear");
					Main_Reserva(Modo);
				break;
				case Pesquisa_Enum:
					Main_Pesquisa();
					system("clear");
				break;
				case Feedback:
					MainFeedback();	
					system("clear");
				break;
				case Importar_ExportarXml:
					Main_IE();
					system("clear");
				break;
				case Transacoes:
					Main_Transacoes();
					system("clear");
				break;
				case 0:
					system("clear");
					Loop=0;
				break;
				default:
					system("clear");
					Vermelho("Digite um Codigo Valido");
				break;
			}
			
		}
	}
	return 1;
}
