
class Buffer:
    """Classe para manipula o buffer"""
    def __init__(self, tamanho=32):
        self.indiceBuffer = 0; #Indice atual do buffer
        self.indiceMax = tamanho-1; #tamanho maximo do buffer
        self.bufferLeitura = [];
    
    def __str__(self):
        """Implementação do metodo toString para debug facilitado"""
        return "Indice:" + str(self.indiceBuffer) + "/" + str(self.indiceMax) + str(self.bufferLeitura);
    
    def getString(self):
        """Retorna uma string que corresponde a um subBuffer que vai do inicio até o '<indiceBuffer>' """
        pseudoBuffer = self.bufferLeitura[0:self.indiceBuffer+1]
        newString = "";
        for chunck in pseudoBuffer:
            newString = newString + str(chunck);
        return newString;

    def getCaracter(self):
        """Retorna um caracter que corresponde a onde o ponteiro esta sobre o buffer' """
        return self.bufferLeitura[self.indiceBuffer]
        
    def empty(self):
        """Verifica se o buffer esta vazio"""
        empty = self.bufferLeitura[0] == '';
        for item in self.bufferLeitura:
            empty = empty and (item == '');
        return empty

    def renew(self):
        """Esvazia o buffer parcialmente, do inicio até a posição atual do ponteiro"""
        self.bufferLeitura = self.bufferLeitura[self.indiceBuffer+1:self.indiceMax+1]
        sizeRenew = self.indiceBuffer + 1;
        self.indiceBuffer = 0;
        return sizeRenew;
    
    def add(self, item):
        """Adiciona um elemento ao buffer"""
        if( len(self.bufferLeitura) != self.indiceMax+1):
            self.bufferLeitura.append(item);
            return True;
        else:
            return False;
    
    def next(self):
        """Avança o ponteiro dentro do buffer"""
        if(self.indiceBuffer + 1 <= self.indiceMax):
            self.indiceBuffer = self.indiceBuffer + 1;
    
    def back(self):
        """Retrocede o ponteiro dentro do buffer"""
        if(self.indiceBuffer - 1 >= 0):
            self.indiceBuffer = self.indiceBuffer - 1;