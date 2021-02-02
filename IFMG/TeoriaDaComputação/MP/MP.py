class Fila(object):
    def __init__(self):
        self.dados = []

    def __str__(self):
        return self.dados

    def insere(self, elemento):
        self.dados.append(elemento)

    def retira(self):
        return self.dados.pop(0)

    def vazia(self):
        return len(self.dados) == 0

class MaquinaPost():
    def __init__(self, pathFile, pathFila):
        self.fim = False
        self.estados = None
        self.alfabeto = None
        self.fila = None
        self.estado = None
        self.rergistrador = None
        self.comandos = None

        self.carregaFonte(pathFile)
            
    def _edComando(tipo, origem, destino, argumento):
        """Cria uma estrutura que representa um programa"""
        return {
            "tipo":tipo,
            "origem":origem,
            "destino":destino,
            "argumento":argumento
        }

    def _criaComando(self, linha):
        """Dado uma linha do codigo fonte retorna uma estrutura que representa o comando""" 
        # Comentario
        if linha[0] == "#":
            return None
        # Atribuição
        elif linha[1].lower() == 'atrib':
            return self._edComando('atribuicao', linha[0], linha[3], linha[2])
        # Leitura
        elif linha[1].lower() == 'ler':
            return self._edComando('atribuicao', linha[0], linha[3], '')
        # Aceita
        elif linha[1].lower() == 'aceita':
            return self._edComando('aceita', linha[0], '', '')
        # Rejeita
        elif linha[1].lower() == 'rejeita':
            return self._edComando('rejeita', linha[0], '', '')
        #Erro
        else:
            return None

    def carregaFonte(self, caminhoArquivo):
        """Dado um arquivo Fonte seta as configurações da Maquina"""
        self.estados = []
        self.alfabeto = []

        #Carrega o Arquivo 
        arquivo = open(caminhoArquivo, "r")
        diagrama = []
        for i in arq:
            linha = i.split()
            diagrama.append(linha)

        #Percorre o arquivo fonte e extrai os comandos
        for numeroLinha in range(0, len(diagrama)):
            comando = self._criaComando(diagrama[numeroLinha])
            if(comando != None):
                self.comandos.append(comando)
                if comando['origen'] not in self.estados:
                    self.estados.append(comando['origen'])
                if comando['destino'] not in self.estados:
                    self.estados.append(comando['destino'])
                if comando['argumento'] not in self.alfabeto:
                    self.alfabeto.append(comando['argumento'])

    def aceita():
        self.fim = True
        print("Aceita")
        print(self.fila)

    def rejeita():
        self.fim = True
        print("Rejeita")
        print(self.fila)

    def verifica(comando):
        executado = False
        if( self.rergistrador == comando['arg'] ):
            self.estado = comando['destino']
            executado = True
        return executado

    def le(comando):
        executado = False
        if( not self.fila.vazio() ):
            self.registrador = self.fila.retira()
            self.estado = comando['destino']
            executado = True
        return executado

    def atribui(comando):
        executado = False
        self.fila.insere(comando['argumento'])
        self.estado = comando['destino']
        executado = True
        return executado