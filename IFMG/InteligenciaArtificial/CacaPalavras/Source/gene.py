import math

NUMERO_LINHAS = 20
NUMERO_COLUNAS = 20

HORIZONTAL = 1
VERTICAL = 2
DIAGONAL = 3

class gene():
    def __init__(self, linha, coluna, palavra, sentido):
        #linha que inicia a palavra
        self.linha = linha
        #coluna que inicia a palavra
        self.coluna = coluna
        #string 'palavra'
        self.palavra = palavra
        #label V H D
        self.sentido = sentido
    def colisao(self, gene):
        if(not (self.factibilidade()) ):
            return True
        #x1,y1 ponto superior direito
        #x2,y2 ponto inferior esquerdo
        geneA = self._vetor4Pontos()
        geneB = gene._vetor4Pontos()
        #A
        x1_A = geneA[0]
        x2_A = geneA[2]
        y1_A = geneA[1]
        y2_A = geneA[3]
        #B
        x1_B = geneB[0] 
        x2_B = geneB[2] 
        y1_B = geneB[1]
        y2_B = geneB[3]
        #Invalido/Fora do range
        if(x1_A <= 0 or x2_A <= 0 or y1_A <= 0 or y2_A <= 0 or x1_B <= 0 or x2_B <= 0 or y1_B <= 0 or y2_B <= 0):
            return False
        #A!=B A parcialmente dentro de B 
        if((x1_A < x1_B and x1_B < x2_A) or (x1_A < x2_B and x2_B < x2_A)):
            if((y1_A < y1_B and y1_B < y2_A) or (y1_A < y2_B and y2_B < y2_A) or (y1_B < y1_A and y2_B > y2_A) ):
                return True
        #A!=B B parcialmente dentro de A
        if((x1_B < x1_A and x1_A < x2_B) or (x1_B < x2_A and x2_A < x2_B)):
            if((y1_B < y1_A and y1_A < y2_B) or (y1_B < y2_A and y2_A < y2_B) or (y1_A < y1_B and y2_A > y2_B) ):
                return True

        #Pontos iguais comprimento
        if((x1_A == x1_B) or (x2_A == x2_B) or (x1_A == x2_B) or (x2_A == x1_B)):
            if((y1_A < y1_B and y1_B < y2_A) or (y1_B < y1_A and y1_A < y2_B) or (y1_A == y2_B)or (y2_A == y1_B)or (y1_A == y1_B)or (y2_A == y2_B)):
                return True
        #Pontos iguais comprimento largura
        if((y1_A == y1_B) or (y2_A==y2_B) or (y1_B == y2_A) or (y1_A==y2_B)):
            if((x1_A < x1_B and x1_B < x2_A) or (x1_B < x1_A and x1_A < x2_B) or (x1_A == x2_B)or (x2_A == x1_B)or (x1_A == x1_B)or (x2_A == x2_B)):
                return True
        #Caso não tiver colisão
        return False    
    #tamanho da Palavra
    def tamanhoPalavra(self):
        return (len(self.palavra))
    #Conjunto de Genes Verificar factibilidade
    def factibilidade(self):
        #Verifica se a palavra estrapola as linhas
        if(self.estouraMatriz(NUMERO_LINHAS, NUMERO_COLUNAS, self.sentido, self.tamanhoPalavra())):
            return False
        return True
    #Verifica se a palavra estourou a Matriz
    def estouraMatriz(self, linhas, colunas, sentido, tamanho):     
        pontos = self._vetor4Pontos()
        if(pontos[2] > colunas or pontos[3] > linhas):
            return True
        return False
    def vetor4PontosDiagonal(self):
        return self._vetor4Pontos()
    ################################
    #   Metodos interno
    ################################
    def _vetor4Pontos(self):
        #p1 ponto superior direito
        #p2 ponto inferior esquerdo        
        tamanho = self.tamanhoPalavra()
        x1 = self.coluna
        y1 = self.linha
        if(self.sentido == VERTICAL):
            x2 = math.ceil(self.coluna + ((tamanho-1)/2))
            y2 = self.linha + tamanho-1
        if(self.sentido == HORIZONTAL):
            x2 = self.coluna + tamanho-1
            y2 = math.ceil(self.linha + ((tamanho-1)/2))
        if(self.sentido == DIAGONAL):
            x2 = self.coluna + tamanho-1
            y2 = self.linha + tamanho-1
        return list([x1, y1, x2, y2])