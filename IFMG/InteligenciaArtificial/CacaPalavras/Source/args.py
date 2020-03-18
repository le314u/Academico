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
        self.nomeArquivo = input("Nome arquivo:")
        self.separador = input("Delimitador:")
        self.numeroIndividuos = int( input("Numero de individuos por geração:") )
        self.numeroGeracoes = int( input("Numero de gerações:") )
        self.idadeMaxima = int( input("Idade máxima do gene:") )
        self.nLinhas = int( input("Dimensão Linhas:") )
        self.nColunas = int( input("Dimensão Colunas:") )
        self.nCacaPalavras = int( input("Numero de CaçaPalavras:") )