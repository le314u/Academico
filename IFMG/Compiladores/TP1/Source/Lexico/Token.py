class Token:
    """Cria uma estrutura que representa um token"""

    def __init__(self, lexema, tipo, linha):
        """Construtor"""
        self.lexema = lexema;
        self.tipo = tipo;
        self.linha = linha;

    def __str__(self):
        return str(self.toJson());
        
    def toJson(self):
        """Transforma o Token em um Json"""
        return {
            "lexema" : self.lexema,
            "tipo" : self.tipo,
            "linha" : self.linha
        };