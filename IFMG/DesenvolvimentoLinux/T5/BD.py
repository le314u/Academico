import sqlite3

class DB():
    def __init__(self):
        self.connect = sqlite3.connect('example.db')
        self.cursor = self.connect.cursor()

    def comand(self, string):
        return self.cursor.execute(string)


class pessoa():
    def __init__(self, db):
        self.db = db
    
    def creaTable(self):
        tabelaPessoa = """
            CREATE TABLE pessoa(
                id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
                Nome VARCHAR(100) NOT NULL,
                CPF VARCHAR(11) NOT NULL,
                Email VARCHAR(20) NOT NULL,
                UF VARCHAR(2) NOT NULL
            );
        """
        self.db.comand(tabelaPessoa)
    
    def insert(self, nome, cpf, email, uf):
        insertString = "INSERT INTO pessoa (Nome, CPF, Email, UF) VALUES('{}','{}','{}','{}');".format(nome, cpf, email, uf)
        self.db.comand(insertString)

    def select(self):
        selectString = "SELECT * FROM pessoa"
        return self.db.comand(selectString)

    def delete(self, id):
        deletString = "DELETE FROM pessoa WHERE id='{}';".format(id)
        self.db.comand(deletString)
        
    def update(self, id, nome, cpf, email, uf):
        updateString = "UPDATE table_name\
                        SET Nome={}, CPF={}, Email={}, UF={}\
                        WHERE id={};".format(nome, cpf, email, uf, id)
        self.db.comand(updateString)



    
db = DB()
p = pessoa(db)
p.creaTable()
p.insert(1,2,3,4)
p.insert(1,2,3,4)
p.insert(1,2,3,4)
p.insert(1,2,3,4)
p.insert(1,2,3,4)
for i in p.select():
    print(i)





















'''

        tabelaPessoa = """
        CREATE TABLE pessoa(
            id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
            Nome VARCHAR(100) NOT NULL,
            CPF VARCHAR(11) NOT NULL,
            Email VARCHAR(20) NOT NULL,
            UF VARCHAR(2) NOT NULL
            );"""

        tabelaFuncao = """
        CREATE TABLE funcao(
            id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
            Cargo VARCHAR(100) NOT NULL,
            Salario FLOAT(23) NOT NULL
            );"""
        tabelaRelacao = """
        CREATE TABLE relacao(
            pessoa_id int NOT NULL,
            funcao_id int NOT NULL,
            FOREIGN KEY (pessoa_id) REFERENCES pessoa(id),
            FOREIGN KEY (funcao_id) REFERENCES funcao(id)
        );"""
'''