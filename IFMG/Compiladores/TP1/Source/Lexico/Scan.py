import Buffer;
import Token;
import Identifier;

class Scan:
    def __init__(self, pathFile,tamanhoBuffer=1024):
        #Meta dados
        self.linha = 1;
        self.identifier = Identifier.Identifier();
        #Carrega o arquivo em uma unicaString
        arquivo = self.loadFile( pathFile );
        self.tokens = self.main(arquivo,tamanhoBuffer);
    
    def pushToken(self, token):
        """Empilha o token"""
        #Salva o token na memoria
        if(not (token is None)):
            self.tokens.append(str(token))

    def loadFile(self, nomeArquivo):
        """Abre um arquivo"""
        fileStream = open(nomeArquivo, 'r')
        return fileStream

    def stream(self, buffer, fileSource, num):
        """Transfere <num> caracteres do arquivo para o buffer"""
        EOF = False
        for chunck in range(num):
            try:
                caracter = fileSource.read(1)
                buffer.add(caracter);
                if(caracter == ''):
                    EOF = True
                    break;
            except:
                pass
        status = not EOF
        return status

    def main(self, fluxo , tamanho):
        """Main"""
        #Preenche o Buffer passando do Arquivo para o Buffer
        buff = Buffer.Buffer(tamanho);
        statusFile = self.stream(buff, fluxo, tamanho)

        while(True):
            #Se o Buffer esta vazio é porque acabaram todos os tokens
            if(buff.empty()):
                break
            else:
                #Salva o token na memoria
                self.pushToken( self.nextToken(buff, fluxo) )
        return self.tokens



    def _renewBuff(self, buff, fluxo):
        """Renova parcialmente o buffer"""
        sizeLastToken = buff.renew()
        self.stream(buff, fluxo, sizeLastToken)

    def nextToken(self, buff, fluxo):
        """Retorna o proximo Token"""
        
        #Ignora Espaço tabulção e quebra de linha
        lexema = buff.getString();

        #Ignora Identação
        while( lexema == ' ' or lexema == '\t' or lexema == '\n' ):
            #Contabiliza uma linha
            if(lexema == '\n'):
                #Altera o meta dado relacionado ao posicionamento do token no arquivo
                self.linha = self.linha + 1;
                
            #Renova parcialmente o buffer
            self._renewBuff(buff,fluxo)
            lexema = buff.getString();

            #Fita acabou | Trim acabou
            if(buff.empty() or  (lexema != ' ' and lexema != '\t' and lexema != '\n')):
                return

        #Ignora Comentario
        while( lexema == "#"): #Vai de '#'
            while(buff.getCaracter() != '\n'): #Até '\n'
                self._renewBuff(buff,fluxo)
                lexema = buff.getString();
                #Fita acabou
                if(buff.empty()):
                    return
            self.linha = self.linha + 1;
            self._renewBuff(buff,fluxo)
            lexema = buff.getString();
            return

        #Inicializa as verificações de validade
        VetAnt = []
        VetPos = self.identifier.vetor( lexema );
        
        #Caracter Invalido
        if(self.identifier.erroToken(VetAnt,VetPos)):
            token = Token.Token(lexema, 'erro', self.linha);
            #Renova parcialmente o buffer
            self._renewBuff(buff, fluxo)
            return token
        
        #Caracter Valido
        while(True):
            #Inicia um loop Para verificar qual Re será a correspondente
            lexema = buff.getString();

            #Verifica quais os possiveis tipos para a substring
            VetAnt = VetPos 
            VetPos = self.identifier.vetor( lexema );

            #Token interrompido
            now = lexema[-1]
            if( now == '\n' or now == ' ' or now == '\t'):
                #Elimina o ultimo caracter que causou o erro
                lexema = lexema[:-1]

                #Verifica se a linha foi alterada
                linha = self.linha
                if(now == '\n'):
                    self.linha = self.linha + 1;

                #Verifica se o lexema é uma palavra reservada
                if(lexema in self.identifier.reserved): 
                    typeLexema = "reserved"
                else: #Caso o lexema não seja uma palavra reservada
                    #Retorna o possivel tipo do token
                    types = self.identifier.types(lexema)#Vetor com todos os tipos possiveis para o token
                
                    typeLexema = types[0] #Caso não seja reservada há apenas uma RE que casa com a string
                #Cria um token
                token = Token.Token(lexema, typeLexema, linha);
                #Renova parcialmente o buffer
                self._renewBuff(buff, fluxo)
                return token

            #Verifica se chegou no final do lexema
            if( self.identifier.finishToken(VetAnt, VetPos)):
                buff.back() #Voltou o ponteiro
                lexema = buff.getString() #Pega a string
                if(lexema in self.identifier.reserved): 
                    typeLexema = "reserved"
                else: #Caso o lexema não seja uma palavra reservada
                    types = self.identifier.types(lexema) #Vetor com todos os tipos possiveis para o token
                    typeLexema = types[0] #Caso não seja reservada há apenas uma RE que casa com a string
                #Cria um token
                token = Token.Token(lexema, typeLexema, self.linha);
                #Renova parcialmente o buffer
                self._renewBuff(buff, fluxo)
                return token

            #Caso o buffer tenha chegado no limite
            elif(buff.getCaracter() == '' or buff.indiceBuffer == buff.indiceMax):
                lexema = buff.getString() #Pega a string
                if(lexema in self.identifier.reserved): #Verifica se o lexema é uma palavra reservada
                    typeLexema = "reserved"
                else: #Caso o lexema não seja uma palavra reservada
                    types = self.identifier.types(lexema) #Vetor com todos os tipos possiveis para o token
                    typeLexema = types[0]           
                #Cria um token
                token = Token.Token(lexema, typeLexema, self.linha);
                #Renova parcialmente o buffer
                self._renewBuff(buff, fluxo)
                return token
            else:
                buff.next()