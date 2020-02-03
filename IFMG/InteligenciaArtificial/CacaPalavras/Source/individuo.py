import gene

#Variavel que tenta balancear a proporção de palavras Horizontais, Verticais e Diagonais
kBalanceamentoFitness = 0.25
kTamanhoPalavra = 0
class individuo:
    def __init__(self, genes):
        #Lista de Genes
        self.genes = genes
        #Numero de gerações que o individuo Durou
        self.idade = 0
        #Verifica quais as palavras serão usadas e os pontos de cada
        self._auxGenesUtilizados = []
        self.reSet()
        #Fitiness do individuo
        self.fitnes = self.fitness();
        
    #Simula que o individuo esta passando de uma geração para outra
    def envelhecimento(self):
        self.idade = self.idade + 1;
    
    #Calcula o quao bom é um individuo
    def fitness(self):
        return self._porcentagemFitness() * self._parcialFitnes()
    #Quanto maior a palavra melhor, Quanto mais palavras melhor
    def _parcialFitnes(self):
        fitnessParcial = 0
        totalPalavras = len(self.genes)
        numeroPalavrasFactiveis = 0
        #Passa por todas as palavras
        for indice, gene in enumerate(self.genes):
            #So contabiliza as palavras Inseridas
            if(self._auxGenesUtilizados[indice] == True):
                fitnessParcial = fitnessParcial + (len(gene.palavra) * 0.1)
                numeroPalavrasFactiveis = numeroPalavrasFactiveis + 1
        fitnessParcial = fitnessParcial + numeroPalavrasFactiveis
        return fitnessParcial
    #Define o quao bem distribuido a palavras estão em questao de 'sentido'
    def _porcentagemFitness(self):
        horizontal = 0
        vertical = 0
        diagonal = 0
        total = 0
        for i,genee in enumerate(self.genes):
            if(self._auxGenesUtilizados[i]):
                total = total + 1
                if(genee.sentido == gene.HORIZONTAL):
                    horizontal = horizontal + 1
                if(genee.sentido == gene.VERTICAL):
                    vertical = vertical + 1
                if(genee.sentido == gene.DIAGONAL):
                    diagonal = diagonal + 1
        perHorizontal = horizontal/total
        perVertical = vertical/total
        perDiagonal = diagonal/total
        porcentagemFitness = 1;
        # 'apartir de 3 palavras' começa a balancear a proporção de palavras em cada sentido
        if(total > 3):
            #Calcula a diferença entre as palavras
            perDH=abs(perDiagonal - perHorizontal)
            perDV=abs(perDiagonal - perVertical) 
            perHV=abs(perHorizontal - perVertical)
            #Se a diferença de proporção entre as palavras for maior que 'k' (kBalanceamentoFitness) significa que esta disbalanceado
            if( (perDH > kBalanceamentoFitness) or (perDV > kBalanceamentoFitness) or (perHV > kBalanceamentoFitness) ):
                maior = max(perDH,perDV,perHV)
                complemento = 1-maior
                porcentagemFitness = complemento
                #Quanto mais tendencioso a um tipo de sentido ('pior o individuo')
        return porcentagemFitness
    
    #Realoca Todos os Elementos e gera um vetor Aux informado quais genes 'seram usados'
    def reSet(self):
        #Reseta o vetor que informa quais genes estão 'alocados'
        self._auxGenesUtilizados = []
        #Passa por todos os elementos tentando realoca-los
        for indice, gen in enumerate(self.genes):
            #Passa por todos os elementos a fim de escolher os pontos para cada palavra
            if(indice != 0):
                #Verifica em qual ponto a palavra ira ficar (Diagonal Principal)
                for i in range(0, indice):
                    #So tenta verificar em diagonais de palavras que seram utilizadas
                    if(self._auxGenesUtilizados[i]):
                        #Tenta inserir em p1(x2,y1)
                        pontos = self.genes[i].vetor4PontosDiagonal()
                        self.genes[indice].linha = pontos[1]
                        self.genes[indice].coluna = pontos[2]+1
                        #Verifica se tem colisao até o ultimo elemento ja verificado
                        if(not(self.colisaoRange(indice-1, self.genes[indice]))):
                            self._auxGenesUtilizados.append(True)
                            self.genes[indice] = gene.gene(self.genes[indice].linha, self.genes[indice].coluna, self.genes[indice].palavra, self.genes[indice].sentido)
                            break
                        #Tenta inserir em p2(x1,y2)
                        self.genes[indice].linha =  pontos[3]+1
                        self.genes[indice].coluna =  pontos[0]
                        #Verifica se tem colisao
                        if(not(self.colisaoRange(indice-1, self.genes[indice]))):
                            self._auxGenesUtilizados.append(True)
                            break                       
                    #Verifica se Chegou no final e não conseguiu inserir a palavra
                    if(i == indice-1):
                        self.genes[indice].linha =  -1
                        self.genes[indice].coluna =  -1
                        self._auxGenesUtilizados.append(False)
                        break;
            else:
                #Seta Todos como -1 exceto o primeiro que é 1
                self._auxGenesUtilizados = []
                for i in self.genes:
                    i.linha = -1
                    i.coluna = -1
                self.genes[0].linha = 1
                self.genes[0].coluna = 1
                if(self.genes[0].factibilidade):
                    self.genes[0].linha = 1
                    self.genes[0].coluna = 1
                    self._auxGenesUtilizados.append(True)
                else:
                    self.genes[0].linha = -1
                    self.genes[0].coluna = -1
                    self._auxGenesUtilizados.append(False)
        #return vetorAux
    def colisaoRange(self, ultimoIndice, gene):
        if(ultimoIndice == 0 or ultimoIndice == -1):
            #So verifica a colisão caso o gene esteja sendo utilizado
            if( self._auxGenesUtilizados[0] == True):
                if(gene.colisao(self.genes[0])):
                    return True
        else:
            #Vai do primeiro até o enésimo gene verificando colisao
            for indice in range(0,ultimoIndice+1):
                #So verifica a colisão caso o gene esteja sendo utilizado
                if( self._auxGenesUtilizados[indice] == True):
                    if(gene.colisao(self.genes[indice])):
                        return True
                else:
                    #So verifica a colisão caso o gene esteja sendo utilizado
                    #Portanto retorna negativo Caso o Gene não esteja sendo utilizado
                    pass
        return False
    def posicaoGenes(self):
        for gene in self.genes:
            print(gene.palavra,"   \t",gene.linha,"x",gene.coluna,"    \t",self.sentido(gene.sentido),"")
    def sentido(self,sentido):
        if(sentido == 1):
            return "Horizontal"
        if(sentido == 2):
            return "Vertical"
        if(sentido == 3):
            return "Diagonal"
