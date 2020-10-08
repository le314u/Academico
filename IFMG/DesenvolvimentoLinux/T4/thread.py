import threading # Biblioteca para gerenciar o uso de threads
import random # Biblioca para gerar numeros pseudo-aleatorios
import time # Biblioteca para controlar o atraso entre as threads
import queue # Biblioteca que representa a estrutura de dados FIFO



class Produtor(threading.Thread):
    """Classe que representa uma thread Produtora"""

    def __init__(self, id_produtor):
        """Construtor da classe"""
        threading.Thread.__init__(self) # Instancia como uma thread
        self.id_produtor = id_produtor # Nomeia a thread

    def run(self):
        """Execução da Thread"""
        #Variaveis de referência Global
        global produto
        global fila
        #Loop Infinito pois a Thread 'nunca' para
        while 1:            
            # Verifica a trava do Estoque
            if not fila.full():
                try:
                    pair = (self.id_produtor, produto)
                    fila.put(pair)
                    print("Produtor\t", self.id_produtor, "\tarmazena \t", pair)
                finally:
                    produto += 1
                    time.sleep(random.randrange(1, 3))
            else:
                pass

class Consumidor(threading.Thread):
    """Classe que representa uma thread Consumidora"""

    def __init__(self, id_consumidor):
        """Construtor da classe"""
        threading.Thread.__init__(self) # Instancia como uma thread
        self.id_consumidor = id_consumidor # Nomeia a thread

    def run(self):
        """Execução da Thread"""
        #Variaveis de referência Global
        global fila
        #Loop Infinito pois a Thread 'nunca' para
        while 1:            
            # Verifica a trava do Estoque
            if not fila.empty():
                try:
                    produto = fila.get()
                    print("Consumidor\t", self.id_consumidor, "\tconsome \t", produto)
                finally:
                    time.sleep(random.randrange(1, 3))
            else:
                pass

class Estoque():
    """Classe que representa a zona critica (dados operados por uma mesma thread)"""

    def  __init__(self,):
        """Construtor da classe"""
        self.size = 10
        self.fila = queue.Queue(self.size) #Cria uma Fila de tamanho 'n'
    
    def get(self):
        """Retorna o primeiro produto da fila"""
        return self.fila.get()

    def put(self, obj):
        """Coloca um produto no final da fila"""
        self.fila.put(obj)
    
    def empty(self):
        """Verifica se a fila esta vazia"""
        return self.fila.empty()
    
    def full(self):
        """Verifica se a fila esta cheia"""
        return self.fila.full()

    def size(self):
        """Indica quantos produtos há na fila"""
        return self.fila.qsize()


def main():
    #Declara que os seguintes nomes estaram se referindo a variaveis globais
    global fila 
    global produto

    #Instancia as variaveis Globais
    produto = 0 # Id sequencial do produto
    fila = Estoque() # zona critica entre as threads

    #instancia 3 Thread's Consumidoras e 3 Produtoras
    for i in range(3):
        Produtor(i+1).start()
        Consumidor(i+1).start()

main()