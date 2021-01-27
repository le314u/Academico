import Buffer;
import Token;
import Identifier;

class Scan:
    def __init__(self):
        self.linha = 1;
        self.identifier = Identifier.Identifier();
        #Carrega o arquivo em uma unicaString
        fluxo = self.loadFile('./teste');
        self.main(fluxo);
    
    def pushToken():
        """Empilha o token"""
        pass

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

    def main(self, fluxo):
        """Main"""
        
        #Preenche o Buffer passando do Arquivo para o Buffer
        tamanho=32
        buff = Buffer.Buffer(tamanho);
        statusFile = self.stream(buff, fluxo, 32)

        while(True):
            #Se o Buffer esta vazio é porque acabaram todos os tokens
            if(buff.empty()):
                break
            else:
                print(self.nextToken(buff, fluxo));

    def _renewBuff(self, buff, fluxo):
        """Renova parcialmente o buffer"""
        sizeLastToken = buff.renew()
        self.stream(buff, fluxo, sizeLastToken)

    def nextToken(self, buff, fluxo):
        """Retorna o proximo Token"""
        
        #Verifica se a String passa no Identifier
        VetAnt = []
        VetPos = self.identifier.vetor( buff.getString() );
        while(True):
            #Inicia um loop Para verificar qual Re será a correspondente
            lexema = buff.getString();

            #Verifica quais os possiveis tipos para a substring
            VetAnt = VetPos 
            VetPos = self.identifier.vetor( lexema );
            #Ignora espaços, tabulações e quebra de linha
            if(lexema == ' ' or lexema == '\t'):
                #Renova parcialmente o buffer
                self._renewBuff(buff,fluxo)
                
            elif(lexema == '\n'):
                #Renova parcialmente o buffer
                self._renewBuff(buff,fluxo)
                
                #Altera o meta dado relacionado ao posicionamento do token no arquivo
                self.linha = self.linha + 1;
            else:
                #Verifica se chegou no final do lexema ou no fim do buffer
                if( self.identifier.finishToken(VetAnt, VetPos) or buff.getCaracter() == ''):
                    buff.back() #Voltou o ponteiro
                    lexema = buff.getString() #Pega a string
                    types = self.identifier.types(lexema) #Vetor com todos os tipos possiveis para o token
                    if(lexema in self.identifier.reserved): #Verifica se o lexema é uma palavra reservada
                        typeLexema = "reserved"
                    else: #Caso o lexema não seja uma palavra reservada
                        if(len(types)==1):
                            typeLexema = types[0] #Caso não seja reservada há apenas uma RE que casa com a string
                    #Cria um token
                    token = Token.Token(lexema, typeLexema, self.linha);
                    #Renova parcialmente o buffer
                    self._renewBuff(buff, fluxo)
                    return token
                
                else:
                    buff.next()

Scan()