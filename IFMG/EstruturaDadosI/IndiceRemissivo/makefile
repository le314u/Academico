
######################################################
##
##	Variaveis
##
######################################################
SRC=Source/
OBJ=Objects/
HEADER="\\n_______________________________________________________\\n"
FOOTER="\\n-------------------------------------------------------\\n"
FLAG=-c -g
nomeArquivoTreinamento = "Objects/README_Treinamento"
nomeArquivoTexto = "Objects/README_Texto"
###########################################################
##				INIT
###########################################################
init: gcc
			
standart:palavra lista listaHash openHash abb avl entrada clock main

gcc:standart
	@echo "${HEADER}GCC ${FOOTER}"
	gcc ${OBJ}main.o ${OBJ}Palavra.o ${OBJ}Lista.o ${OBJ}ListaHash.o ${OBJ}OpenHash.o ${OBJ}ABB.o ${OBJ}AVL.o ${OBJ}TratamentoString.o ${OBJ}AnaliseEntrada.o ${OBJ}Clock.o -o ${OBJ}main.exe 
	./${OBJ}main.exe ${nomeArquivoTreinamento} ${nomeArquivoTexto}
		
gdb:standart
	@echo "${HEADER}GDB  ${FOOTER}"
	gcc -g ${OBJ}main.o ${OBJ}Palavra.o ${OBJ}Lista.o ${OBJ}ListaHash.o ${OBJ}OpenHash.o ${OBJ}ABB.o ${OBJ}AVL.o ${OBJ}TratamentoString.o ${OBJ}AnaliseEntrada.o  ${OBJ}Clock.o -o ${OBJ}main.exe
	gdb ${OBJ}main.exe 
	


###########################################################
##				MODULOS
###########################################################
main:
	@echo "${HEADER}Main ${FOOTER}"
	gcc -o ${OBJ}main.o ${FLAG} ${SRC}main.c

palavra:
	@echo "${HEADER}Objeto Palavra ${FOOTER}"
	gcc -o ${OBJ}Palavra.o ${FLAG} ${SRC}Palavra.c 

lista:
	@echo "${HEADER}Objeto Lista ${FOOTER}"
	gcc -o ${OBJ}Lista.o ${FLAG} ${SRC}Lista.c 


openHash:palavra comparacao
	@echo "${HEADER}Estrutura OpenHash ${FOOTER}"
	gcc -o ${OBJ}OpenHash.o ${FLAG} ${SRC}OpenHash.c 

listaHash:palavra comparacao
	@echo "${HEADER}Estrutura ListaHash ${FOOTER}"
	gcc -o ${OBJ}ListaHash.o ${FLAG} ${SRC}ListaHash.c 

avl:palavra comparacao
	@echo "${HEADER}Estrutura AVL ${FOOTER}"
	gcc -o ${OBJ}AVL.o ${FLAG} ${SRC}AVL.c 

abb:palavra comparacao
	@echo "${HEADER}Estrutura ABB ${FOOTER}"
	gcc -o ${OBJ}ABB.o ${FLAG} ${SRC}ABB.c 

clock:
	@echo "${HEADER}Clock ${FOOTER}"
	gcc -o ${OBJ}Clock.o ${FLAG} ${SRC}Clock.c 

comparacao:
	@echo "${HEADER}Tratamento String${FOOTER}"
	gcc -o ${OBJ}TratamentoString.o ${FLAG} ${SRC}TratamentoString.c 

entrada: abb palavra 
	@echo "${HEADER}Entrada de Dados${FOOTER}"
	gcc -o ${OBJ}AnaliseEntrada.o ${FLAG} ${SRC}AnaliseEntrada.c 


###########################################################
##				DOCUMENTAÇÂO
###########################################################
documentacao: Documentacao.mk
	@echo "${HEADER}Gerando Documentacao markdown>>html apartir do pandoc${FOOTER}"
	@echo "${ArquivoDoc}"
	markdown-pdf Documentacao.mk
	
#"ValGrind"
