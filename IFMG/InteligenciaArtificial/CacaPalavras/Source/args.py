class argumentos():
    def __init__(self, iterativo=True):
        if(iterativo):
            self.arg()
        else:
            self.nomeArquivo = 'palavras'
            self.separador = ','
            self.numeroIndividuos = 100
            self.numeroGeracoes = 15
            self.idadeMaxima = 10
            self.nLinhas = 20
            self.nColunas = 20
            self.nCacaPalavras = 1

    def arg(self):
        self.nomeArquivo()
        self.separador()
        self.numeroIndividuos()
        self.numeroGeracoes()
        self.idadeMaxima()
        self.nLinhas()
        self.nColunas()
        self.nCacaPalavras()

    def nomeArquivo(self):
        self.nomeArquivo = input("Nome arquivo:")

    def separador(self):
        self.separador = input("Delimitador:")

    def numeroIndividuos(self):
        self.numeroIndividuos = int( input("Numero de individuos por geração:") )

    def numeroGeracoes(self):
        self.numeroGeracoes = int( input("Numero de gerações:") )

    def idadeMaxima(self):
        self.idadeMaxima = int( input("Idade máxima do gene:") )

    def nLinhas(self):
        self.nLinhas = int( input("Dimensão Linhas:") )

    def nColunas(self):
        self.nColunas = int( input("Dimensão Colunas:") )

    def nCacaPalavras(self):
        self.nCacaPalavras = int( input("Numero de CaçaPalavras:") )
    