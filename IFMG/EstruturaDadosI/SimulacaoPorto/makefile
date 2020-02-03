
######################################################
##
##	Variaveis
##
######################################################
SRC=Source/
OBJ=Objects/
HEADER="\\n_____________________________________\\n"
FOOTER="\\n-------------------------------------"
ArquivoDoc=Documentacao.html
ArquivoLog=Log.txt

init: compilar executar posProcessamento
all:debugar

debugar: estrutura
	@echo "$(HEADER)Debug <Main>$(FOOTER)"
	gcc -g -o $(OBJ)debug.exe $(OBJ)view.o $(OBJ)main.o $(OBJ)log.o $(OBJ)pilhaEstatica.o $(OBJ)estruturaNavio.o $(OBJ)estruturaAreaAtracamento.o $(OBJ)estruturaTravessa.o $(OBJ)filaDinamica.o $(OBJ)estruturaPorto.o
	gdb $(OBJ)debug.exe

compilar: estrutura
	@echo "$(HEADER)Fluxo Geral <Main>$(FOOTER)"
	gcc -o $(OBJ)main.exe $(OBJ)view.o $(OBJ)main.o $(OBJ)log.o $(OBJ)pilhaEstatica.o $(OBJ)estruturaNavio.o $(OBJ)estruturaAreaAtracamento.o $(OBJ)estruturaTravessa.o $(OBJ)filaDinamica.o $(OBJ)estruturaPorto.o

executar: $(OBJ)main.exe
	@echo $(HEADER)Executando aplicação$(FOOTER)
	./$(OBJ)main.exe

apagar:
	@echo "$(HEADER)Apagando Arquivos Compilados$(FOOTER)"
	rm $(OBJ)

posProcessamento:
	@echo "$(HEADER)Mostrando Resultado Log Execução$(FOOTER)"
	cat $(ArquivoLog)


#Ordem de compilaçao
estrutura: pilha navio areaAtracamento travessa fila porto view log main

#Main
main: $(SRC)main.c
	gcc -o $(OBJ)main.o -c $(SRC)main.c


######################################################
##
##	Modulos
##
######################################################
documentacao: Documentacao.mk
	@echo "$(HEADER)Gerando Documentacao markdown>>html apartir do pandoc$(FOOTER)"
	@echo "$(ArquivoDoc)"
	pandoc Documentacao.mk>$(ArquivoDoc)

log: pilha navio areaAtracamento travessa fila porto
	@echo "$(HEADER)Arquivo Log Instancias >> Json$(FOOTER)"
	gcc -o $(OBJ)log.o -c $(SRC)log.c 


######################################################
##
##	Estruturas
##
######################################################

pilha:
	@echo "$(HEADER)Pilha Estatica$(FOOTER)"
	gcc -o $(OBJ)pilhaEstatica.o -c $(SRC)pilhaEstatica.c 

navio:	pilha
	@echo "$(HEADER)Estrutura Navio$(FOOTER)"
	gcc -o $(OBJ)estruturaNavio.o -c $(SRC)estruturaNavio.c 

areaAtracamento:
	@echo "$(HEADER)Estrutura Area de Atracamento$(FOOTER)"
	gcc -o $(OBJ)estruturaAreaAtracamento.o -c $(SRC)estruturaAreaAtracamento.c 
	
travessa:	pilha
	@echo "$(HEADER)Estrutura Travessa$(FOOTER)"
	gcc -o $(OBJ)estruturaTravessa.o -c $(SRC)estruturaTravessa.c 

fila:	navio
	@echo "$(HEADER)Fila Dinamica sendo os elementos  <Estruturas Navio>$(FOOTER)"
	gcc -o $(OBJ)filaDinamica.o -c $(SRC)filaDinamica.c 

porto:	travessa 	areaAtracamento	fila
	@echo "$(HEADER)Estrutura Porto porem sem processamento$(FOOTER)"
	gcc -o $(OBJ)estruturaPorto.o -c $(SRC)estruturaPorto.c 

view: porto
	@echo "$(HEADER)View para Analise Dados$(FOOTER)"
	gcc -o $(OBJ)view.o -c $(SRC)view.c 
