class Fila:
    def __init__(self, string):
        self.dados = []
        for char in string:
            self.dados.append(char)

    def __str__(self):
        return str(self.dados)

    def insere(self, elemento):
        self.dados.append(elemento)

    def retira(self):
        return self.dados.pop(0)

    def vazia(self):
        return len(self.dados) == 0


class MaquinaPost:
    def __init__(self, pathFile, stringFila):
        self.fim = False
        self.estados = None
        self.alfabeto = None
        self.fila = Fila(stringFila)
        self.estado = None
        self.registrador = None
        self.comandos = None
        self.carregaFonte(pathFile)
        self.executar()

    def _edComando(self, tipo, origem, destino, argumento):
        """Cria uma estrutura que representa um programa"""
        return {
            "tipo": tipo,
            "origem": origem,
            "destino": destino,
            "argumento": argumento
        }
    # origem argumento destino
    def _criaComando(self, linha):
        """Dado uma linha do codigo fonte retorna uma estrutura que representa o comando"""
        # Comentario
        if linha[0] == "#":
            return None
        # Atribuição
        elif linha[1].lower() == 'atrib':
            return self._edComando('atribuicao', linha[0], linha[3], linha[2])
        # Verificação
        elif linha[1].lower() == 'if':
            return self._edComando('verificacao', linha[0], linha[3], linha[2])
        # Leitura
        elif linha[1].lower() == 'ler':
            return self._edComando('ler', linha[0], linha[2], '')
        # Aceita
        elif linha[1].lower() == 'aceita':
            return self._edComando('aceita', linha[0], '', '')
        # Rejeita
        elif linha[1].lower() == 'rejeita':
            return self._edComando('rejeita', linha[0], '', '')
        # Erro
        else:
            return None

    def carregaFonte(self, caminhoArquivo):
        """Dado um arquivo Fonte seta as configurações da Maquina"""
        self.estados = []
        self.alfabeto = []
        self.comandos = {}

        # Carrega o Arquivo
        arquivo = open(caminhoArquivo, "r")
        diagrama = []
        for i in arquivo:
            linha = i.split()
            diagrama.append(linha)

        # Percorre o arquivo fonte e extrai os comandos
        for numeroLinha in range(0, len(diagrama)):
            comando = self._criaComando(diagrama[numeroLinha])
            if (comando != None):
                if comando['origem'] not in self.estados:
                    self.comandos.update({comando['origem']: []})  # Cria a entrada para o estado na Hash
                    self.estados.append(comando['origem'])
                if comando['destino'] not in self.estados and (comando['tipo'] != 'aceita' and comando['tipo'] != 'rejeita'):
                    self.comandos.update({comando['destino']: []})  # Cria a entrada para o estado na Hash
                    self.estados.append(comando['destino'])
                if comando['argumento'] not in self.alfabeto and comando['argumento'] != '':
                    #self.comandos.update({comando['origem']: []})  # Cria a entrada para o estado na Hash
                    self.alfabeto.append(comando['argumento'])
                self.comandos[comando['origem']].append(comando)

    def aceita(self):
        self.fim = True
        print("Aceita")
        print(self.fila)

    def rejeita(self):
        self.fim = True
        print("Rejeita")
        print(self.fila)

    def verifica(self, comando):
        executado = False
        if (self.registrador == comando['argumento']):
            self.estado = comando['destino']
            executado = True
        return executado

    def le(self, comando):
        executado = False
        if (not self.fila.vazia()):
            self.registrador = self.fila.retira()
            self.estado = comando['destino']
            executado = True
        return executado

    def atribui(self, comando):
        executado = False
        self.fila.insere(comando['argumento'])
        self.estado = comando['destino']
        executado = True
        return executado

    def executar(self):
        # Variaveis de controle
        indiceUltimoComandoEstado = -1

        # Verifica se há estado 0 na maquina
        if not '0' in self.estados:
            print("Codigo Fonte Invalido")
            self.fim = True
        # Seta o estado inicial, a maquian sempre inicia pelo estado 0
        self.estado = '0'
        comandoAtual = self.comandos['0'][0]
        # Inicia o Loop para executar o codigo Fonte
        while (not self.fim):
            executado = False  # Define se a maquina esta funcionando
            # Executa a ação conforme o tipo de comando
            if (comandoAtual['tipo'] == 'atribuicao'):
                executado = self.atribui(comandoAtual)
            elif (comandoAtual['tipo'] == 'verificacao'):
                executado = self.verifica(comandoAtual)
            elif (comandoAtual['tipo'] == 'ler'):
                executado = self.le(comandoAtual)
            elif (comandoAtual['tipo'] == 'aceita'):
                executado = self.aceita()
            elif (comandoAtual['tipo'] == 'rejeita'):
                executado = self.rejeita()

            # Verifica qual o proximo Comando
            if (not executado):
                if ( indiceUltimoComandoEstado + 1 < len(self.comandos[self.estado]) ):
                    comandoAtual = self.comandos[self.estado][indiceUltimoComandoEstado + 1]
                    indiceUltimoComandoEstado = indiceUltimoComandoEstado + 1
                else:
                    self.fim = True
            else:
                comandoAtual = self.comandos[self.estado][0]
                indiceUltimoComandoEstado = 0

# Vazia ou numeros par de 1's
MaquinaPost("./ComparacaoTuringPost.py", "")
