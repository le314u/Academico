#LUCAS MATEUS FERNANDES 0035411
#LUCAS GABRIEL
#RENAM




#############################################
#		Interpretacao Artigo
#############################################
#L=Comprimento
#W=Largura
#i=Indice da peça
#V=Valor
#Cada peça 1i' possui 3 atributos (l,w,v)
#R=Peça primária
#Quantidade de peças é  (0 <= QuantidadeMinima <= QuantidadePeças <= QuantidadeMaxima)
#P=Conjunto de peças a serem cortadas
#B=Conjunto de peças ja cortadas
#Representação da peça necessita apenas de dois pontos (um Mais superior a direita e um mais inferior a esquerda)
#L=Comprimento
#W=Largura
#i=Indice da peça
#V=Valor
#Cada peça 'i' possui 3 atributos (l,w,v)
#R=Peça primária
#Quantidade de peças é  (0 <= QuantidadeMinima <= QuantidadePeças <= QuantidadeMaxima)
#P=Conjunto de peças a serem cortadas
#B=Conjunto de peças ja cortadas
#Representação da peça necessita apenas de dois pontos (um Mais superior a direita e um mais inferior a esquerda)


###############################################
##
##				Estrutura de Dado
##
##############################################

#______________________________________________________________________________
#	'*' Significa que tem N
#	peca<-				c(comprimento,altura)
#	pecas<-				list(*peca)
#	valor<-				numeric(valor)
#	valores<-			c(*valor)
#	vetor4Pontos<-		c(x1,y1,x2,y2) sendo os 4 pontos a representação da Diagonal Secundaria de um bloco
#	vetor2Dimensoes<-	c(comprimento,altura)
#	vetorOrigem<-		c(x0,y0) Representação do ponto superior esquerdo do Bloco
#	pontos<-			list(vetor4Pontos)
#	estoque<-			list(*pontos)
#	lista<-				list(*list())

#Variaveis importantes

#Pecas representa o conjunto de todas peças que podem ser cortadas
#Estoque representa a solução pois são as peças que seram cortadas
#PercentualRemocao representa a % da area a ser removida do 'estoque/solução'

#Estrutura de vizinhança 

#A área preenchida é reduzida em 'n%' e para isso é retirada uma quantidade 'x' de peças de forma aleatoria
#Apos a remoção os elementos são deslocados para esquerda e para cima a fim de compacta-lo a uma extremidade da peça
#Apos a realocação são adicionados novos elementos nas extremidades da diagonal secundaria de cada peça


#Valor da Função Objetiva é a Area preenchida por todas as peças
#Valor da peça é a propria Area portanto ele prioriza peças maiores

#####################
##		Parametros
#####################
#iniciando Variaveis
	#Pecas<-c(largura,comprimento) 
	pecas<-list( c(4,5), c(16,11), c(19,2), c(20,1), c(10,2), c(5,16), c(14,2), c(11,16), c(16,1), c(11,19), c(10,10), c(10,3), c(13,9), c(7,2), c(6,19), c(4,20), c(11,8), c(16,9), c(17,1), c(15,3), c(17,15), c(9,16), c(19,6), c(6,9), c(5,16), c(3,3), c(18,18), c(5,18), c(4,1), c(17,14), c(14,1), c(14,8), c(4,18), c(16,20), c(16,7), c(8,3), c(4,6), c(6,2), c(1,12), c(5,17), c(18,9), c(17,6), c(18,12), c(3,10), c(20,2), c(19,12), c(17,8), c(6,8), c(14,6), c(1,10), c(16,18), c(12,3), c(11,8), c(1,13), c(6,14), c(19,3), c(7,6), c(15,17), c(1,6), c(17,19), c(16,11), c(16,17), c(10,6), c(15,5), c(9,17), c(6,2), c(13,3), c(20,14), c(8,14), c(10,15), c(4,12), c(6,14), c(11,13), c(17,13), c(12,20), c(13,4), c(11,15), c(7,4), c(16,10), c(14,11), c(20,3), c(20,12), c(19,10), c(20,10), c(13,15), c(2,3), c(17,20), c(13,10), c(2,5), c(4,12), c(10,13), c(1,14), c(2,7), c(19,18), c(1,19), c(17,5), c(14,13), c(1,5), c(13,3), c(20,8), c(15,11), c(14,19), c(17,13), c(10,13), c(9,1), c(20,18), c(4,10), c(2,13), c(11,15), c(12,7), c(8,7), c(10,4), c(17,9), c(8,3), c(15,6), c(20,8), c(9,12), c(9,7), c(4,3), c(9,8), c(6,13), c(6,12), c(2,8), c(18,8), c(19,15), c(5,20), c(11,9), c(2,18), c(7,12), c(4,16), c(4,4), c(7,12), c(3,11), c(10,15), c(6,9), c(5,17), c(3,6), c(10,9), c(1,15), c(6,14), c(1,14), c(7,12), c(6,11), c(8,19), c(18,3), c(17,10), c(1,16), c(16,8), c(3,6), c(5,11), c(14,17), c(8,1), c(7,13), c(17,17), c(2,18), c(7,17), c(3,19), c(2,12), c(13,7), c(7,4), c(12,5), c(10,7), c(19,10), c(9,5), c(16,10), c(19,11), c(3,19), c(5,17), c(12,20), c(11,11), c(12,2), c(14,4), c(9,9), c(6,16), c(17,19), c(1,20), c(16,4), c(8,18), c(17,13), c(12,19), c(17,12), c(16,9), c(6,5), c(6,14), c(4,17), c(2,15), c(20,14), c(11,3), c(19,1), c(20,1), c(19,18), c(3,1), c(1,7), c(20,16), c(20,3), c(8,8), c(6,4), c(6,20), c(15,16), c(15,1), c(2,8), c(19,15), c(4,20), c(8,17), c(6,13), c(8,16), c(14,5), c(11,19), c(1,7), c(18,6), c(1,10), c(1,16), c(15,7), c(9,18), c(5,5), c(20,2), c(3,4), c(18,12), c(17,1), c(12,8), c(2,9), c(5,12), c(20,11), c(9,18), c(9,19), c(6,3), c(8,11), c(13,19), c(15,19), c(2,5), c(19,16), c(20,12), c(9,4), c(12,14), c(20,18), c(1,9), c(6,9), c(12,18), c(9,15), c(19,3), c(7,20), c(17,6), c(20,14), c(7,14), c(20,1), c(18,6), c(11,10), c(2,4), c(1,7), c(14,14), c(19,1), c(19,1), c(13,12), c(14,15), c(16,19), c(4,15), c(19,17), c(11,13), c(3,11), c(3,6), c(19,19), c(5,7), c(8,2), c(15,13), c(17,8), c(18,4), c(19,20), c(15,5), c(8,8), c(11,15), c(15,13), c(7,14), c(1,2), c(13,9), c(13,7), c(10,11), c(16,8), c(13,6), c(1,5), c(12,16), c(16,19), c(10,10), c(15,2), c(13,15), c(15,20), c(1,2), c(16,12), c(14,7), c(14,16), c(16,1), c(1,13), c(15,4), c(1,7), c(12,11), c(1,9), c(3,11), c(13,10), c(14,5), c(18,10), c(8,9), c(14,1), c(16,4), c(3,6), c(3,16), c(13,4), c(7,9), c(4,17), c(4,8), c(2,15), c(4,15), c(3,2), c(14,20), c(16,19), c(12,15), c(13,19), c(14,4), c(4,9), c(9,1), c(11,2), c(4,6), c(9,20), c(1,12), c(19,7), c(5,12), c(16,7), c(12,16), c(13,7), c(16,19), c(20,12), c(6,4), c(13,19), c(9,5), c(12,1), c(2,17), c(19,10), c(2,5), c(9,4), c(4,15), c(7,12), c(17,8), c(11,3), c(13,2), c(11,6), c(9,2), c(4,11), c(15,9), c(16,17), c(19,13), c(8,20), c(5,16), c(13,10), c(3,8), c(13,8), c(7,4), c(15,11), c(16,10), c(1,1), c(10,13), c(16,6), c(17,19), c(7,20), c(2,10), c(9,10), c(2,17), c(14,6), c(2,4), c(18,2), c(8,11), c(17,5), c(6,4), c(11,17), c(12,6), c(19,8), c(8,19), c(20,18), c(3,7), c(4,1), c(18,11), c(7,14), c(18,5), c(5,5), c(14,4), c(17,9), c(10,18), c(9,19), c(14,7), c(10,7), c(9,6), c(17,5), c(13,15), c(19,14), c(15,18), c(12,8), c(7,4), c(7,7), c(7,4), c(19,10), c(15,3), c(3,7), c(15,18), c(12,2), c(4,12), c(13,2), c(20,16), c(4,15), c(17,6), c(2,10), c(2,20), c(14,14), c(7,20), c(9,9), c(7,2), c(20,2), c(11,14), c(1,20), c(14,6), c(13,15), c(10,16), c(6,12), c(6,17), c(2,13), c(7,16), c(1,5), c(1,16), c(11,5), c(17,19), c(12,1), c(8,13), c(15,20), c(18,18), c(16,12), c(5,18), c(11,4), c(17,15), c(14,9), c(8,19), c(3,16), c(7,16), c(16,7), c(7,20), c(14,11), c(15,5), c(20,17), c(9,7), c(12,7), c(15,10), c(17,1), c(9,9), c(3,16), c(4,14), c(6,2), c(14,13), c(1,14), c(1,5), c(8,7), c(5,9), c(17,3), c(3,15), c(8,13), c(6,3), c(15,12), c(4,9), c(18,8), c(2,8), c(2,2), c(10,20), c(4,8), c(6,6), c(9,20), c(19,1), c(18,9), c(20,1), c(2,8), c(15,7), c(9,19), c(15,6), c(9,15), c(3,18), c(15,19), c(5,10), c(5,1), c(17,1), c(9,9), c(12,10), c(18,19), c(3,12), c(19,19), c(18,8), c(19,12), c(6,11), c(16,13), c(4,13), c(7,8), c(13,14), c(12,1), c(12,1), c(12,19), c(9,17), c(3,11), c(16,4), c(20,9), c(12,1), c(14,7), c(4,7), c(19,2), c(11,15), c(1,12), c(7,12), c(12,13), c(19,18), c(20,7), c(12,6), c(9,1), c(9,6), c(11,6), c(6,3), c(8,17), c(12,13), c(14,19), c(8,2), c(16,1), c(19,12), c(10,18), c(10,7), c(11,15), c(18,16), c(15,15), c(2,19), c(18,13), c(9,8), c(12,16), c(12,14), c(7,16), c(4,7), c(8,1), c(2,11), c(17,16), c(7,14), c(15,14), c(18,16), c(1,8), c(8,5), c(16,9), c(2,8), c(1,14), c(19,11), c(12,14), c(9,19), c(1,15), c(18,18), c(13,2), c(16,11), c(13,7), c(8,11), c(2,11), c(2,18), c(12,20), c(1,2), c(1,19), c(18,8), c(11,10), c(8,19), c(6,3), c(5,13), c(18,9), c(11,8), c(1,2), c(8,4), c(3,13), c(15,4), c(16,14), c(20,5), c(17,11), c(17,13), c(1,3), c(2,18), c(20,4), c(12,4), c(20,12), c(13,7), c(12,19), c(14,3), c(18,5), c(12,11), c(4,3), c(4,18), c(4,20), c(13,7), c(6,18), c(6,4), c(5,8), c(6,11), c(18,20), c(14,8), c(9,8), c(7,9), c(9,8), c(3,1), c(10,20), c(7,15), c(17,7), c(17,7), c(6,12), c(6,10), c(5,6), c(7,19), c(6,19), c(7,8), c(6,6), c(16,4), c(4,3), c(13,19), c(16,20), c(1,4), c(2,9), c(20,17), c(4,10), c(12,12), c(16,1), c(15,16), c(3,5), c(20,1), c(14,6), c(11,16), c(13,13), c(11,10), c(4,2), c(12,17), c(18,18), c(4,7), c(11,20), c(7,9), c(7,15), c(10,15), c(14,1), c(16,15), c(11,7), c(13,8), c(15,18), c(5,20), c(17,18), c(3,16), c(5,11), c(6,11), c(15,18), c(1,17), c(15,9), c(5,5), c(17,15), c(4,1), c(4,9), c(16,12), c(4,20), c(7,7), c(20,17), c(15,14), c(13,16), c(11,14), c(16,10), c(3,12), c(9,17), c(2,4), c(13,8), c(6,17), c(17,2), c(2,17), c(8,2), c(6,4), c(12,7), c(14,8), c(17,9), c(17,2), c(2,16), c(5,9), c(11,19), c(16,20), c(16,15), c(10,20), c(9,5), c(1,12), c(13,15), c(2,16), c(2,10), c(3,15), c(13,6), c(19,4), c(5,13), c(2,11), c(2,4), c(17,10), c(13,7), c(16,10), c(6,5), c(9,10), c(15,1), c(14,8), c(4,9), c(3,20), c(10,18), c(18,3), c(7,7), c(17,7), c(1,12), c(6,8), c(6,4), c(13,16), c(15,4), c(1,5), c(16,3), c(1,1), c(2,13), c(7,4), c(19,5), c(2,4), c(9,19), c(7,17), c(18,7), c(9,13), c(11,5), c(3,12), c(15,1), c(17,12), c(11,4), c(20,19), c(17,15), c(7,17), c(3,20), c(2,19), c(1,1), c(3,17), c(5,17), c(3,6), c(11,18), c(20,17), c(10,17), c(7,18), c(18,10), c(9,4), c(14,3), c(13,14), c(15,11), c(18,17), c(11,4), c(17,20), c(17,2), c(8,17), c(16,3), c(18,17), c(15,1), c(1,2), c(15,20), c(3,6), c(10,18), c(18,15), c(12,5), c(7,20), c(5,6), c(20,17), c(18,8), c(20,10), c(19,3), c(6,16), c(9,11), c(11,14), c(7,9), c(16,20), c(16,4), c(10,16), c(9,9), c(19,7), c(3,17), c(17,12), c(19,5), c(14,6), c(7,19), c(5,14), c(3,12), c(9,9), c(13,17), c(2,4), c(5,14), c(19,1), c(4,19), c(16,2), c(13,18), c(14,19), c(12,17), c(18,12), c(16,7), c(14,10), c(18,2), c(19,17), c(18,18), c(18,17), c(1,13), c(15,18), c(16,8), c(11,5), c(2,16), c(7,8), c(1,13), c(16,6), c(1,18), c(7,11), c(17,13), c(6,15), c(17,15), c(15,11), c(10,1), c(8,11), c(18,3), c(9,19), c(13,20), c(12,3), c(19,9), c(3,15), c(11,6), c(2,2), c(15,16), c(4,10), c(13,4), c(11,12), c(4,15), c(11,14), c(14,8), c(15,13), c(16,15), c(12,9), c(19,10), c(16,16), c(19,20), c(16,4), c(2,1), c(12,6), c(16,10), c(17,7), c(5,9), c(2,12), c(20,15), c(12,2), c(4,5), c(9,17), c(6,12), c(12,8), c(14,3), c(8,6), c(14,8), c(18,6), c(12,19), c(19,6), c(6,4), c(10,13), c(19,10), c(5,7), c(2,8), c(12,5), c(3,7), c(1,11), c(8,10), c(9,11), c(13,10), c(12,7), c(12,11), c(14,6), c(11,16), c(11,12), c(10,10), c(11,1), c(16,1), c(9,20), c(15,18), c(19,5), c(3,14), c(6,12), c(7,10), c(12,14), c(8,12), c(15,16), c(7,19), c(12,18), c(18,15), c(1,1), c(15,8), c(7,7), c(15,2), c(15,20), c(1,11), c(15,7), c(5,7), c(16,2), c(5,17), c(17,1), c(12,3), c(11,4), c(14,12), c(6,14), c(7,2), c(14,15), c(8,16), c(14,3), c(18,10), c(4,19), c(20,15), c(3,4), c(18,13), c(7,17), c(18,11), c(15,15), c(14,19), c(17,15), c(9,18), c(10,4), c(7,20), c(13,1), c(15,11), c(11,12), c(13,4), c(10,2), c(20,18), c(10,7), c(1,16), c(17,14), c(3,6), c(9,18), c(6,6), c(13,14), c(17,10), c(7,6), c(4,15), c(13,10), c(9,12), c(16,5), c(13,1), c(5,2), c(12,15), c(20,8), c(2,10), c(1,8), c(11,16), c(8,5), c(20,12), c(16,17), c(11,10), c(17,9), c(3,20), c(14,14), c(20,6), c(12,15), c(8,4), c(7,7), c(2,11), c(15,5), c(14,18), c(11,6), c(4,13), c(19,4), c(17,7), c(7,6), c(20,15), c(17,6), c(10,6), c(12,18), c(14,18), c(13,17), c(13,15), c(20,4), c(9,12), c(8,3), c(15,12), c(11,17), c(10,10), c(19,3), c(10,10), c(7,2), c(4,9), c(6,14), c(15,14), c(9,16), c(1,2), c(3,18), c(4,18), c(17,18), c(10,3), c(2,1), c(14,7), c(12,11), c(12,13), c(14,7), c(1,10), c(1,9), c(6,12), c(8,9), c(19,8), c(2,10), c(16,20), c(14,19), c(20,8), c(17,20), c(5,8), c(11,5), c(17,2), c(11,5), c(8,19), c(5,18), c(6,9), c(6,12), c(14,5), c(2,2), c(20,3), c(3,18), c(13,7), c(14,2), c(7,3), c(16,8), c(12,20), c(20,3), c(11,13), c(9,11), c(3,8), c(17,5), c(19,13), c(10,11), c(9,7), c(13,10), c(6,10), c(17,15), c(19,17), c(2,19), c(3,14), c(1,5), c(15,16), c(2,16), c(3,3), c(13,18), c(9,7), c(1,2), c(18,13), c(20,13), c(2,20), c(11,5), c(16,1), c(8,10), c(18,11), c(17,19), c(11,8), c(16,20), c(14,11), c(10,16), c(16,12), c(9,13), c(2,13), c(19,20), c(2,10), c(10,2), c(18,19), c(18,2), c(2,17), c(17,15), c(2,13), c(8,20), c(5,15), c(7,5), c(12,10), c(1,9), c(10,16), c(3,6), c(14,14), c(18,18), c(14,20), c(12,10), c(19,12), c(6,3), c(13,16), c(18,13), c(11,9), c(18,9), c(13,8), c(13,19), c(11,2), c(20,4), c(7,4), c(2,6), c(6,18), c(6,3), c(9,11), c(11,3), c(11,15), c(12,20), c(18,6), c(13,15), c(8,3), c(8,2), c(15,4), c(10,10), c(5,2), c(6,16), c(3,5), c(3,13), c(14,20), c(20,10), c(6,9), c(11,11), c(5,10), c(19,13), c(12,7), c(14,5), c(7,11), c(7,14), c(4,19), c(2,14), c(2,2), c(13,8), c(16,6), c(13,9), c(16,17), c(11,4), c(20,8), c(12,11), c(1,4), c(2,8), c(9,20), c(4,7), c(11,20), c(4,12), c(10,9), c(15,15), c(18,17), c(11,15), c(16,9), c(16,13), c(16,1), c(14,19), c(17,19), c(2,7), c(2,8), c(8,8), c(5,3), c(19,15), c(12,3), c(16,4), c(15,4), c(14,17), c(3,5), c(3,20), c(1,15), c(9,4), c(1,10), c(8,18), c(13,10), c(5,5), c(2,12), c(17,11), c(12,1), c(6,9), c(12,14), c(19,13), c(3,5), c(9,12), c(4,14), c(14,6), c(13,19), c(8,4), c(2,9), c(15,6), c(6,17), c(9,17), c(19,3), c(20,4), c(14,14), c(18,20), c(4,14), c(13,7), c(3,7), c(3,15), c(16,19), c(10,10), c(14,20), c(18,9), c(4,2), c(8,17), c(3,6), c(13,20), c(15,17), c(20,1), c(9,2), c(3,7), c(8,5), c(17,3), c(4,14), c(2,11), c(12,3), c(7,19), c(15,10), c(3,18), c(14,13), c(9,12), c(3,7), c(19,16), c(11,19), c(8,15), c(13,14), c(7,16), c(2,12), c(3,18), c(14,6), c(6,13), c(11,9), c(14,19), c(3,18), c(7,1), c(8,2), c(17,17), c(5,7), c(5,17), c(15,17), c(3,11), c(17,6), c(4,2), c(11,8), c(6,15), c(8,19), c(14,8), c(1,12), c(2,6), c(1,6), c(10,16), c(5,15), c(3,2), c(17,11), c(16,5), c(8,11), c(7,11), c(4,12), c(8,1), c(1,11), c(20,15), c(11,4), c(3,10), c(1,5), c(15,13), c(14,13), c(1,19), c(17,1), c(5,19), c(12,14), c(19,3), c(5,4), c(2,6), c(11,6))
	estoque <- list()
	#Chapa Inicial Dimensao c(largura,comprimento)
	chapaInicial<-c(20,20)
	#Parametros Sa
	temperaturaInicial<-1000
	temperaturaFinal<-1 #Não pode ser 0 pois demora muito a convergir devido ao Temperatura*=Alpha
	maxIteracoes<-100
	taxaResfriamento<-0.01
	percentualRemocao<-0.25

#####################
##		VIEW
#####################

ChapaInView<-function(vetor4Pontos){
	x1=vetor4Pontos[1]
	y1=vetor4Pontos[2]
	x2=vetor4Pontos[3]
	y2=vetor4Pontos[4]
	cores<-rainbow(225)
	indice=round(runif(1,1, length(cores)))
	rect(x1,y1,x2,y2,col=cores[indice])

	#dispersaoLinha=round(runif(1,1,4))
	#orientacaoLinha=round(runif(1,1,4))
	#rect(x1,y1,x2,y2,dispersaoLinha,orientacaoLinha,col=cores[indice])
}

view<-function(solucao,chapaInicial){
	plot(0,0,xlim=c(0,chapaInicial[1]),ylim=c(0,chapaInicial[2]))
	#Coloca a Borda da Peça
	rect(0,0,chapaInicial[1],chapaInicial[2],border = "red")
	rect(0,0,chapaInicial[1],chapaInicial[2],border = "red")

	if(length(solucao)!=0){
		for(i in (1:length(solucao))){
			ChapaInView(solucao[[i]])
		}
	}
}

#####################
##		Mini
#####################

#Define Valor de uma peca
defineValor <- function(peca){
	return((peca[1]*peca[2]));
}


#Define Area de uma peca
defineArea <- function(peca){
	return(peca[1]*peca[2]);
}

#Calcula o Valor do cm^2 de uma peca
ValorCm2<-function(peca){
	valor=defineValor(peca)
	area=defineArea(peca)
	return(valor/area);
}


#Converte diagonal secundaria em um 'bloco' de duas dimensões (x,y)
ConvertePontosEmDimensao<-function(vetor4Pontos){
	x1 <- vetor4Pontos[1]
	y1 <- vetor4Pontos[2]
	x2 <- vetor4Pontos[3]
	y2 <- vetor4Pontos[4]
	x<-abs(x1-x2)
	y<-abs(y1-y2)
	vetor2Dimensoes<-c(x,y)
	return(vetor2Dimensoes)
}

#Converte (x,y) em uma diagonal secundaria a partir de um ponto de referencia'vetorOrigem'
ConverteDimensaoEmPontos <- function(vetor2Dimensoes,vetorOrigem){
	comprimento <- vetor2Dimensoes[1]
	altura <- vetor2Dimensoes[2]
	origemX <- vetorOrigem[1]
	origemY <- vetorOrigem[2]

	x1<-origemX+comprimento
	y1<-origemY

	x2<-origemX
	y2<-origemY-altura

	pontos<-list(c(x1,y1,x2,y2))
	
	return(pontos)
}
####################
##		Medio
####################

#Verifica se a Diagonal Secundaria esta representada dentro do Range da ChapaInicial, 
Factbilidade<-function(vetor4Pontos,chapaInicial){
	#Legenda retorno
	#0 Não factivel
	#1 Factivel

	origemX <- vetor4Pontos[1]
	origemY <- vetor4Pontos[2]
	finalX <- vetor4Pontos[3]
	finalY <- vetor4Pontos[4]

	#Verifica do jeito que veio
	if( origemX >=0 && origemX<=chapaInicial[1]){
		if(origemY >=0 && origemY<=chapaInicial[2]){
			if(finalX >=0 && finalX<=chapaInicial[1]){
				if(finalY >=0 && finalY<=chapaInicial[2]){
					return(1)
				}
			}
		}
	}
	#Não factivel
	return(0);
}

#Verifica se Duas peças estão colidindo
VerificaColisaoEntre2Pecas<-function(Vetor4PontosA, Vetor4PontosB){
	#Legenda retorno
	#1=Colidiu
	#0=Não colidiu

	#Peça no estoque
	objetoA<-Vetor4PontosA
	A_x1<-objetoA[1]
	A_y1<-objetoA[2]
	A_x2<-objetoA[3]
	A_y2<-objetoA[4]

	#Peça a ser inserida
	objetoB<-Vetor4PontosB
	B_x1<-objetoB[1]
	B_y1<-objetoB[2]
	B_x2<-objetoB[3]
	B_y2<-objetoB[4]

	#A!=B A dentro de B
	if((A_x2<B_x1 && B_x1<A_x1)||(A_x2<B_x2 && B_x2<A_x1)){
		if((A_y2<B_y1 && B_y1<A_y1)||(A_y2<B_y2 && B_y2<A_y1)){
			return(1)
		}
	}
	#A!=B B dentro de A
	if((B_x2<A_x1 && A_x1<B_x1)||(B_x2<A_x2 && A_x2<B_x1)){
		if((B_y2<A_y1 && A_y1<B_y1)||(B_y2<A_y2 && A_y2<B_y1)){
			return(1)
		}
	}
	#A com mesmo comprimento de B
	if(B_x2==A_x2 && A_x1==B_x1){
		if((A_y2<B_y1 && B_y1<A_y1)|| (A_y2<B_y2 && B_y2<A_y1)|| (B_y2<A_y1 && A_y1<B_y1)|| (B_y2<A_y2 && A_y2<B_y1)){
				return(1)
		}
	}
	#A com mesma largura de B
	if(B_y2==A_y2 && A_y1==B_y1){
		if((A_x2<B_x1 && B_x1<A_x1)|| (A_x2<B_x2 && B_x2<A_x1)|| (B_x2<A_x1 && A_x1<B_x1)|| (B_x2<A_x2 && A_x2<B_x1) ){
			return(1)
		}
	}
	#A==B
	if(B_x2==A_x2 && A_x1==B_x1){
		if(B_y2==A_y2 && A_x1==B_x1){
			return(1)
		}
	}
	#A!=B eles cruzam mas sem a extremidade estar dentro do outro
	if((B_x2<A_x1 && A_x1<B_x1)||(B_x2<A_x2 && A_x2<B_x1)){
		if((A_y2<B_y1 && B_y1<A_y1)||(A_y2<B_y2 && B_y2<A_y1)){
			return(1)
		}
	}
	#A!=B eles cruzam mas sem a extremidade estar dentro do outro
	if((A_x2<B_x1 && B_x1<A_x1)||(A_x2<B_x2 && B_x2<A_x1)){
		if((B_y2<A_y1 && A_y1<B_y1)||(B_y2<A_y2 && A_y2<B_y1)){
			return(1)
		}
	}
	return(0)
}

#Verifica se o Bloco pode ser inserido no Estoque
PontosFactiveisNoEstoque<-function(pontos,estoque,chapaInicial){
	#-1 Extrapola o Range
	#0 Não colide
	#1 Colide

	#Factivel?
	pontos<-unlist(pontos)
	if((Factbilidade(pontos,chapaInicial)==0) || (Factbilidade(pontos,chapaInicial)==2)){
		#Extrapola as dimensoes
		return(-1);
	}

	#Colide?
	for(peca in estoque){	
		peca<-unlist(peca)
		if(VerificaColisaoEntre2Pecas(peca,pontos)){
			return(1)
		}
	}
	return(0)
}

#####################
##		Macro
#####################

#Calcula o valor de todas as pecas
CalculaValor<-function(pecas){
	valoresAux<-c()
	#Calcula Valor
	if(length(pecas)==0){
		for(i in 1:(length(pecas))){
			valoresAux[i]=defineValor(unlist(pecas[i][1]))
		}
		return(valoresAux)
	}else{
		return(c(0))
	}
}

#Calcula o valor do cm^2 de Todas as Pecas
PrecoPorCm2<-function(pecas){
	#Inicializa variaveis
	valores<-c()
	#Calcula melhor preço por 'cm^2' para todas as peças
	if(length(pecas)!=0){
		for(i in 1:length(pecas)){
			valores[i]<-ValorCm2(pecas[[i]]);
		}
	}
	return(valores)
}

#Ordena as pecas pelo valor do cm^2
OrdenaValoresDecrescenteCm2<-function(pecas){
	#Inicializa variaveis
	valores<-c()
	#Calcula melhor preço por 'cm^2' para todas as peças
	valores<-PrecoPorCm2(pecas)
	while(TRUE){
		#Ordena em Ordem Decrescente
		max <- length(pecas)
		if(max == 0){
			return(pecas);
		}
		flagTroca=0;
		for(i in 1:max){
			if(i!=max){
				#Realiza Troca
				if(valores[i]<valores[i+1]){
					#Troca Peça
					aux1<-pecas[i]
					pecas[i]=pecas[i+1]
					pecas[i+1]=aux1
					#Troca Valor
					aux2<-valores[i]
					valores[i]=valores[i+1]
					valores[i+1]=aux2
					#AtivaFlag
					flagTroca=flagTroca+1;
				}
			}
		}
		if(flagTroca == 0){
			break;
		}
	}
	return (pecas)
}

#####################
##		Complexas
#####################

#Tenta Incluir Uma Peca no Estoque
TentaIncluirPeca <- function(vetor2Dimensoes,estoque,chapaInicial){
	if(length(estoque)==0){
		origem=c(0,chapaInicial[2]);
		pontos<-ConverteDimensaoEmPontos(vetor2Dimensoes,origem)
		#Inclui no Estoque
		tamanhoEstoque <- length(estoque)
		estoque[tamanhoEstoque+1]=pontos
		return(estoque)
	}else{
		#Percorre Todo o Estoque
		#Tenta inserir a peça perto da parte superior da diagonal secundaria
		flagErro<-FALSE
		for (i in length(estoque)){
			peca<-unlist(estoque[i])
			origem=c(peca[1],peca[2])
			pontos<-ConverteDimensaoEmPontos(vetor2Dimensoes,origem)
			#Verifica colisão
			colide <- PontosFactiveisNoEstoque(pontos,estoque,chapaInicial)
			if(colide != 0){#Caso Colida ou extrapole
				flagErro<-TRUE
				break;
			}
		}
		#Ponto inferior esquerdo da Diagonal secundaria
		if(flagErro){
			flagErro<-FALSE
			for (i in length(estoque)){
				peca<-unlist(estoque[i])
				origem=c(peca[3],peca[4])
				pontos<-ConverteDimensaoEmPontos(vetor2Dimensoes,origem)
				#Verifica colisão
				colide <- PontosFactiveisNoEstoque(pontos,estoque,chapaInicial)
				if(colide != 0){
					flagErro<-TRUE
					break;
				}
			}
		}

		#RODA A PEÇA
		vetor2Dimensoes<-c(vetor2Dimensoes[2],vetor2Dimensoes[1])

		#Tenta inserir a peça perto da parte superior da diagonal secundaria
		flagErro<-FALSE
		for (i in length(estoque)){
			peca<-unlist(estoque[i])
			origem=c(peca[1],peca[2])
			pontos<-ConverteDimensaoEmPontos(vetor2Dimensoes,origem)
			#Verifica colisão
			colide <- PontosFactiveisNoEstoque(pontos,estoque,chapaInicial)
			if(colide != 0){#Caso Colida ou extrapole
				flagErro<-TRUE
				break;
			}
		}
		#Ponto inferior esquerdo da Diagonal secundaria
		if(flagErro){
			flagErro<-FALSE
			for (i in length(estoque)){
				peca<-unlist(estoque[i])
				origem=c(peca[3],peca[4])
				pontos<-ConverteDimensaoEmPontos(vetor2Dimensoes,origem)
				#Verifica colisão
				colide <- PontosFactiveisNoEstoque(pontos,estoque,chapaInicial)
				if(colide != 0){
					flagErro<-TRUE
					break;
				}
			}
		}
		if(!flagErro){
			#Inclui no Estoque
			tamanhoEstoque <- length(estoque)
			estoque[tamanhoEstoque+1]=pontos
			return(estoque)
		}
	}
	return(estoque)
}

#Cria uma Primeira Solução
CriaSolucao<-function(estoque,pecas,chapaInicial){
	#Retorno
	#list(pecas,estoque)

	#Adiciona peça ao estoque
	#("ate encher a capacidade do Estoque")
	indiceExcluir=c();
	if(length(pecas)!=0){
		for(indice in 1:length(pecas)){
			antes <-length(estoque)
			#Inclui 'N' peças 
			estoque<-TentaIncluirPeca(pecas[[indice]],estoque,chapaInicial)
			depois <-length(estoque)
			if(antes!=depois){
				#Add indices de pecas a serem excluidos pois ja fora implantados no estoque
				indiceExcluir[length(indiceExcluir)+1]<-indice
			}
		}
		#Exclui Peça da coleção de 'pecas'
		if(length(indiceExcluir)!=0){
			for(indice in length(indiceExcluir):1){
				pecas=pecas[-(indiceExcluir[indice])];
			}
		}
	}
	indicesExcluir=c();
	valores <- CalculaValor(pecas);
	pecas<-OrdenaValoresDecrescenteCm2(pecas)
	retorno<-list(pecas,estoque)
	return(retorno)
}

VerificaAreaPreenchida<-function(estoque){

	Area=0;
	for(peca in estoque){
		dimensaoPeca=ConvertePontosEmDimensao((peca))
		Area=Area+defineArea(dimensaoPeca)
	}
	return(Area)
}

DeslocaEsquerda<-function(vetor4Pontos){
	vetor4Pontos[1]=vetor4Pontos[1]-1
	vetor4Pontos[3]=vetor4Pontos[3]-1
	return (list(vetor4Pontos))
}

DeslocaCima<-function(vetor4Pontos){
	vetor4Pontos[2]=vetor4Pontos[2]+1
	vetor4Pontos[4]=vetor4Pontos[4]+1
	return (list(vetor4Pontos))
}

DeslocaPecas<-function(estoque,chapaInicial){
	while(TRUE){
		deslocamento=FALSE
		#q<-scan()
		#view(estoque,chapaInicial)
		if(!length(estoque)==0){
			for(indice in 1:length(estoque)){
				#Desloca Esquerda
					#Salva estado atual da peça caso tenha que dar rollBack
					pontosOld<-estoque[indice]
					#Desloca a peça a esquerda
					pontosNew<-DeslocaEsquerda(pontosOld[[1]])
					pontos<-pontosNew
					#Remove a Peca do estoque
					estoque[indice]<-list(c(0,0,0,0));
					#Verifica se vai entrar em conflito com as demais peças
					if(PontosFactiveisNoEstoque(pontos,estoque,chapaInicial)!=0){
						#volta a peca para o estoque
						estoque[indice]<-pontosOld
					}else{
						estoque[indice]<-pontosNew
						deslocamento=TRUE
					}

				#Desloca Cima
					#Salva estado atual da peça caso tenha que dar rollBack
					pontosOld<-estoque[indice]
					#Desloca a peça a esquerda
					pontosNew<-DeslocaCima(unlist(pontosOld))
					pontos<-unlist(pontosNew)
					#Remove a Peca do estoque
					estoque[indice]<-list(c(0,0,0,0));
					#Verifica se vai entrar em conflito com as demais peças
					if(PontosFactiveisNoEstoque(pontos,estoque,chapaInicial)!=0){
						#volta a peca para o estoque
						estoque[indice]<-pontosOld
					}else{
						estoque[indice]<-pontosNew
						deslocamento=TRUE
					}

			}
		}
		if(deslocamento==FALSE){
			return(estoque)
		}
	}

}
FObjetiva<-VerificaAreaPreenchida

Troca<-function(solucao,pecas,percentualRemocao,chapaInicial){
	#retorno[1]=Pecas
	#retorno[2]=Solucao

	#Remover γ da área de R;
	areaInicial=VerificaAreaPreenchida(solucao)
	areaAtual=VerificaAreaPreenchida(solucao)
	while(!((areaAtual/areaInicial)<=(1-percentualRemocao))){
		#Sortea uma peça aleatoria dentro de Estoque
		indice=round(runif(1,1, length(solucao)))
		#Passa a peca a ser removida para o vetor de pecas
		pecas[(length(pecas)+1)][[1]]=ConvertePontosEmDimensao(solucao[[indice]])
		#Remove  a peça Alterada
		solucao=solucao[-indice]
		#Verifica a Area preenchida(Somatorio da Area das peças presente no 'estoque')
		areaAtual=VerificaAreaPreenchida(solucao)
	}
	solucao<-DeslocaPecas(solucao,chapaInicial)
	lista<-CriaSolucao(solucao,pecas,chapaInicial);
	return(lista);
}



SA<-function(pecas,temperaturaInicial,temperaturaFinal,maxIteracoes,taxaResfriamento,percentualRemocao,chapaInicial)
{
	#Ordena o Vetor de Pecas a serem Inseridos
	#Atual
	solucaoAtual=c()
	pecasAtual=OrdenaValoresDecrescenteCm2(pecas)
	#Nova
	solucaoNova=c()
	pecasNova=c()
	#Melhor
	solucaoMelhor=c()
	pecasMelhor=c()
	#Prepara a Solução atual
	lista=CriaSolucao(solucaoAtual,pecasAtual,chapaInicial)
	pecasAtual=lista[[1]]
	solucaoAtual=lista[[2]]
	#Seta os primeiros valores como melhores
	solucaoMelhor = solucaoAtual;
	pecasMelhor = pecasAtual;
	#Seta a temperatura
	temperatura = temperaturaInicial;
	#Seta o numero de Iterações
	iteracaoT = 0;

	while(temperatura>temperaturaFinal){
		while(iteracaoT<maxIteracoes){
			#Incrementa +1 iteracao
			iteracaoT<-iteracaoT+1
			#Gera um Vizinho
			lista<-Troca(solucaoAtual,pecasAtual,percentualRemocao,chapaInicial)
			pecasNova<-lista[[1]]
			solucaoNova<-lista[[2]]
			#Verifica a qualidade da soluçaoNova
			delta<-FObjetiva(solucaoAtual)-FObjetiva(solucaoNova)
			cat("\nAtual= ",FObjetiva(solucaoAtual),"|Melhor= ",FObjetiva(solucaoMelhor))
			view(solucaoAtual,chapaInicial)
			if(delta<0){
				solucaoAtual<-solucaoNova
				if(FObjetiva(solucaoNova)>FObjetiva(solucaoMelhor)){
					#Seta the new Best
					solucaoMelhor<-solucaoAtual
					pecsaMelhor<-pecasAtual
				}
			}else{
				#Se a nova solução não foi tão boa Verifica a possibilidade de aceita-la mesmo assim
				random <- runif(1, 0,1)
				if(random<exp(-delta/temperatura)){
					solucaoAtual<-solucaoNova
					pecasAtual<-pecasNova
				}
			}
		}
		view(solucaoNova,chapaInicial)
		temperatura=temperatura*taxaResfriamento;
		Iteracao=0;
	}
	return(solucaoMelhor)
}


	
#Inicia Script
	#Ordena o Vetor de Pecas a serem Inseridos
	pecas<-OrdenaValoresDecrescenteCm2(pecas)
	valores<-CalculaValor(pecas);
	lista<-CriaSolucao(estoque,pecas,chapaInicial)
	atualPecas=lista[[1]]
	atualEstoque=lista[[2]]
	solucao<-SA(pecas,temperaturaInicial,temperaturaFinal,maxIteracoes,taxaResfriamento,percentualRemocao,chapaInicial)
	view(solucao,chapaInicial)
