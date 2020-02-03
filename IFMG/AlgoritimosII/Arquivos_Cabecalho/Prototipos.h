#ifndef _Prototipos_ 
	//Se não estiver definido entra no if
#define _Prototipos_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

#include "Registros.h"
	//Inclui arquivos de cabeçalho

//Funçoes
//void Apagar_Modificar(char Url[99], int Codigo,int Modificar,MODO Modo);
int MenuInicialFeedback();	
int MenuListagemFeedback();	
void Cria_Pasta(char Url[99]);	
int Opcao_Acoes();
int Main_All();
void Apagar_Modificar(char Url[99], int Codigo,int Modificar,MODO Modo,int Registro);
int Confirmacao();
int Intervalo_Vetor(int Vetor[],int Ultimo);
int Modo_Manipulacao();
void Quick_Sort(int vetor[], int inicio, int fim);
int Retorna_Linha_Codigo(char Url[99], int Codigo);
int Valida_Codigo(char Url[99],int Numero_De_Registros,int Modo_de_Abertura, int Tipo_DADO);
void Verificacao_Arquivo(char Url[99],int Modo_de_Abertura);
MODO Modo_Bin_ou_Txt(int Modo_de_Abertura);
int Converter_Decimal_Binario(int n0,int n1,int n2,int n3);
int Arquivo_Texto_Vazio(char Url[]);
int Arquivo_Binario_Vazio(char Url[]);	
void Verificacao_All();
int Ler_Configuracoes_Retorna_Modo_de_Abertura();
int Valida_Codigo_Produto(int Codigo, int Modo_de_Abertura);
void Recebe_Dados_Produtos(int Codigo[],int Quantidade[],int Pagamento[]);
//Hotel
int Retorna_Campo_Struct_Hotel(char Url[99], int Codigo);
void Apagar_Modificar_Hotel_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
void Criar_Modificar_Hotel(int Modo_de_Abertura,int Manter_Codigo);
void Gravar_Hotel_Bin(char Url[99],DADOS_HOTEL *Hotel);
void Gravar_Hotel_Txt(char Url[99],DADOS_HOTEL *Hotel);
void Ler_Hotel_Bin();
void Ler_Hotel_Memoria(DADOS_HOTEL Hotel);
void Ler_Hotel_Txt(char Url[99]);
void Main_Hotel(MODO Modo);
int Valida_Acomadacao_Hotel(int Codigo, int Modo_de_Abertura);
//Hospede
int Retorna_Campo_Struct_Hospede(char Url[99], int Codigo);
void Apagar_Modificar_Hospede_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
void Criar_Modificar_Hospede(int Modo_de_Abertura,int Manter_Codigo);
void Gravar_Hospede_Bin(char Url[99],DADOS_HOSPEDE *Hospede);
void Gravar_Hospede_Txt(char Url[99],DADOS_HOSPEDE *Hospede);
void Ler_Hospede_Bin();
void Ler_Hospede_Memoria(DADOS_HOSPEDE Hospede);
void Ler_Hospede_Txt(char Url[99]);
void Main_Hospede(MODO Modo);
void Nome_Hospede_Codigo(int Codigo, char Nome_Hospede[]);	
//Codigo_Categoria
int Retorna_Campo_Struct_Codigo_Categoria(char Url[99], int Codigo);
void Apagar_Modificar_Codigo_Categoria_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
void Criar_Modificar_Codigo_Categoria(int Modo_de_Abertura,int Manter_Codigo);
void Gravar_Codigo_Categoria_Bin(char Url[99],CODIGO_CATEGORIA *Codigo_Categoria);
void Gravar_Codigo_Categoria_Txt(char Url[99],CODIGO_CATEGORIA *Codigo_Categoria);
void Ler_Codigo_Categoria_Bin();
void Ler_Codigo_Categoria_Memoria(CODIGO_CATEGORIA Codigo_Categoria);
void Ler_Codigo_Categoria_Txt(char Url[99]);
void Main_Codigo_Categoria(MODO Modo);
int Valida_Acomadacao_Codigo_Categoria(int Codigo, int Modo_de_Abertura);
//Acomodacoes
int Valida_Codigo_Hotel(int Codigo, int Modo_de_Abertura);
int Retorna_Campo_Struct_Acomodacoes(char Url[99], int Codigo);
int Valida_Codigo_Categoria_Acomodacoes(int Codigo, int Modo_de_Abertura);
void Apagar_Modificar_Acomodacoes_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
void Criar_Modificar_Acomodacoes(int Modo_de_Abertura,int Manter_Codigo);
void Gravar_Acomodacoes_Bin(char Url[99],ACOMODACOES *Acomodacoes);
void Gravar_Acomodacoes_Txt(char Url[99],ACOMODACOES *Acomodacoes);
void Ler_Acomodacoes_Bin();
void Ler_Acomodacoes_Memoria(ACOMODACOES Acomodacoes);
void Ler_Acomodacoes_Txt(char Url[99]);
void Recebe_Dados_Acomodacoes(ACOMODACOES *Acomodacoes, int Modo_de_Abertura);
void Main_Acomodacoes(MODO Modo);
//Login
int Login(MODO Modo);
void Criptografar(char Senha[]);
void Descriptografar(char Senha[]);
//Funcionarios
void Ler_Funcionarios_Txt(char Url[99]);
void Ler_Funcionarios_Bin();
void Ler_Funcionarios_Memoria(FUNCIONARIOS Funcionarios);
void Gravar_Funcionarios_Txt(char Url[99],FUNCIONARIOS *Funcionarios);
void Gravar_Funcionarios_Bin(char Url[99],FUNCIONARIOS *Funcionarios);
void Criar_Modificar_Funcionarios(int Modo_de_Abertura,int Manter_Codigo);
int Retorna_Campo_Struct_Funcionarios(char Url[99], int Codigo);
void Apagar_Modificar_Funcionarios_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
//Fornecedores
int Retorna_Campo_Struct_Fornecedores(char Url[99], int Codigo);
void Apagar_Modificar_Fornecedores_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
void Criar_Modificar_Fornecedores(int Modo_de_Abertura,int Manter_Codigo);
void Gravar_Fornecedores_Bin(char Url[99],FORNECEDORES *Fornecedores);
void Gravar_Fornecedores_Txt(char Url[99],FORNECEDORES *Fornecedores);
void Ler_Fornecedores_Bin();
void Ler_Fornecedores_Memoria(FORNECEDORES Fornecedores);
void Ler_Fornecedores_Txt(char Url[99]);
void Main_Fornecedores(MODO Modo);
//Produtos
void Ler_Produtos_Txt(char Url[99]);
void Ler_Produtos_Bin();
void Ler_Produtos_Memoria(PRODUTOS Produtos);
void Gravar_Produtos_Txt(char Url[99],PRODUTOS *Produtos);
void Gravar_Produtos_Bin(char Url[99],PRODUTOS *Produtos);
void Criar_Modificar_Produtos(int Modo_de_Abertura,int Manter_Codigo);
int Retorna_Campo_Struct_Produtos(char Url[99], int Codigo);
void Apagar_Modificar_Produtos_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
int Valida_Codigo_Hotel_Produtos(int Codigo, int Modo_de_Abertura);
//Reserva
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
void Apagar_Fluxo(char Url[999], int Codigo);
int Retorna_Campo_Struct_Fluxo(char Url[99], int Codigo);
void Arquivo_Url_Fluxo(char Url[99], int Codigo,char Url_Fluxo[]);
int Retorna_Codigos_Reserva(int Codigos[]);	
//Pesquisa
void Main_Pesquisa();	
int Verifica_Fluxo(char Url[999], DATA Data_Entrada,DATA Data_Saida, int Acomodacao_Indisponiveis[]);
PESQUISA Tipo_Pesquisa();
DATA Pesquisa(PESQUISA Pesquisa,int *Indice_Disponiveis,int Vetor_Cod_Acomodacao_Disponivel[]);
int Retorna_Acomodacao_Disponiveis_Por_Periodo(int Acomodacao_Disponiveis[],PESQUISA Pesquisa_Entrada,PESQUISA Pesquisa_Saida);
void Pequisa_Quantidade(int Acomodacao_Invalida[],int Inicio_Vetor,int Quantidade);
void Pequisa_Facilidades(int Acomodacao_Invalida[],int Inicio_Vetor);
void Pequisa_Categoria_Acomodacao(int Acomodacao_Invalida[],int Inicio_Vetor);
int Valida_Codigo_Acomodacao(int Codigo, int Modo_de_Abertura);
void Recebe_Data(DATA *Data, int Auxiliar);
int Todas_Acomodacoes_TXT(char Url[99], int Acomodacoes_Disponiveis[],int Acomodacoes_Indisponiveis[], int Contador_Acomodacao_Indisponiveis);
void Mostra_Acomodacoes_TXT(int Contador_Acomodacoes, int Codigos[], char Url[]);
void Mostra_Acomodacoes_BIN(int Contador_Acomodacoes, int Codigos[], char Url[]);	
int Todas_Acomodacoes_BIN(char Url[99], int Acomodacoes_Disponiveis[],int Acomodacoes_Indisponiveis[], int Contador_Acomodacao_Indisponiveis);	
int Retorna_Acomodacoes_Indisponiveis_Com_Codigo_Categoria(int Codigo_Categoria, int Modo_Abertura, int Acomodacao_Indisponiveis[], int Contador_Acomodacao_Indisponiveis);	
int Retorna_Acomodacoes_Indisponiveis_Com_Quantidade_Pessoas(int Adultos, int Criancas,int Codigo_Acomodacao_Invalidas[], int Indice_Invalido);
int Retorna_Acomodacoes_Indisponiveis_Com_Facilidades(FACILIDADES Facilidade,int Codigo_Acomodacao_Invalidas[], int Indice_Invalido);
//Importar/Exportar XML
void Exportar();
IMPORTACAO_EXPORTACAO Set_On_Off();	
//FeedBack
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
void Filtro_Reserva_Data(int Modo_Feedback);
void Filtro_Reserva_Codigo_Acomodacao(int Modo_Feedback);
void Filtro_Reserva_Codigo_Hospede(int Modo_Feedback);
int Tipo_Listagem_Produtos();
void Filtro_Produtos_Codigos(int Modo_Feedback);
void Filtro_Produtos_Codigos_Em_Estoque_Minimo(int Modo_Feedback);
//Transacoes
void Main_Transacoes();
int Valida_Reserva(int Codigo, int Modo_de_Abertura);
float Valor_Total(int Codigo, int Modo_de_Abertura);
void Checkin();	
#endif