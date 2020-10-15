import sqlite3

class DB():
    def __init__(self):
        """Cria uma conexão com sqlite3 """
        self.name = "example.db"
        self.connect = sqlite3.connect(self.name)
        self.cursor = self.connect.cursor()
    
    def commit(self):
        """Faz com que as Alteraçoes no BD persistam no arquivo"""
        self.connect.commit()

    def comand(self, string):
        """Faz com que o comando dentro de "string" seja execdo no BD"""
        return self.cursor.execute(string)


class Pessoa():
    def __init__(self, db):
        """CRUD para tabela Pessoa"""
        self.db = db
        self.creaTable()
    
    def creaTable(self):
        """Cria uma tabela caso não exista"""
        tabelaPessoa = """
            CREATE TABLE IF NOT EXISTS pessoa(
                id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
                Nome VARCHAR(100) NOT NULL,
                CPF VARCHAR(11) NOT NULL UNIQUE,
                Email VARCHAR(20) NOT NULL,
                UF VARCHAR(2) NOT NULL
            );
        """
        self.db.comand(tabelaPessoa)
    
    def insert(self, nome, cpf, email, uf):
        """Insere Dados no BD"""
        try:
            insertString = "INSERT INTO pessoa (Nome, CPF, Email, UF) VALUES('{}','{}','{}','{}');".format(nome, cpf, email, uf)
            self.db.comand(insertString)
            self.db.commit()
            return True
        except:
            return False

    def select(self, cpf):
        """Seleciona a Pessoa conforme o CPF informado"""
        selectString = "SELECT * FROM pessoa WHERE CPF='{}';".format(cpf)
        return self.db.comand(selectString)

    def delete(self, id):
        """Deleta uma Pessoa conforme o ID"""
        deletString = "DELETE FROM pessoa WHERE id='{}';".format(id)
        self.db.comand(deletString)
        self.db.commit()

    def update(self, id, nome, cpf, email, uf):
        """Atualiza os dados de uma Pessoa com base no id"""
        updateString = "UPDATE table_name\
                        SET Nome={}, CPF={}, Email={}, UF={}\
                        WHERE id={};".format(nome, cpf, email, uf, id)
        self.db.comand(updateString)
        self.db.commit()


class Servico():
    def __init__(self, db):
        """CRUD para tabela Pessoa"""
        self.db = db
        self.creaTable()

    def creaTable(self):
        """Cria uma tabela caso não exista"""
        tabelaFuncao = """
        CREATE TABLE IF NOT EXISTS funcao(
            id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
            Cargo VARCHAR(100) NOT NULL,
            Salario FLOAT(23) NOT NULL
            );"""
        self.db.comand(tabelaFuncao)
    
    def insert(self, cargo, salario):
        """Insere Dados no BD"""
        insertString = "INSERT INTO funcao (Cargo, Salario) VALUES('{}','{}');".format(cargo, salario)
        self.db.comand(insertString)
        self.db.commit()

    def select(self, cargo):
        """Seleciona a Servico conforme o Cargo informado"""
        selectString = "SELECT * FROM funcao WHERE Cargo='{}';".format(cargo)
        return self.db.comand(selectString)

    def delete(self, id):
        """Deleta uma Serviço conforme o ID"""
        deletString = "DELETE FROM funcao WHERE id='{}';".format(id)
        self.db.comand(deletString)
        self.db.commit()

    def update(self, id, cargo, salario):
        """Atualiza os dados de uma Servico com base no id"""
        updateString = "UPDATE table_name\
                        SET Cargo={}, Salario={}\
                        WHERE id={};".format(cargo, salario, id)
        self.db.comand(updateString)
        self.db.commit()


class Relacao():
    def __init__(self, db):
        """CRUD para tabela de Relacao entre Pessoa e Cargo"""
        self.db = db
        self.creaTable()

    def creaTable(self):
        """Cria uma tabela caso não exista"""
        tabelaRelacao = """
        CREATE TABLE IF NOT EXISTS relacao(
            pessoa_id int NOT NULL,
            funcao_id int NOT NULL,
            FOREIGN KEY (pessoa_id) REFERENCES pessoa(id),
            FOREIGN KEY (funcao_id) REFERENCES funcao(id)
        );"""
        self.db.comand(tabelaRelacao)
    
    def insert(self, pessoa_id, funcao_id):
        """Insere Dados no BD"""
        insertString = "INSERT INTO relacao (pessoa_id, funcao_id) VALUES('{}','{}');".format(pessoa_id, funcao_id)
        self.db.comand(insertString)
        self.db.commit()

    def select(self, pessoa_id, funcao_id):
        """Seleciona a relação conforme o os id (Verifica se há a relação)"""
        selectString = "SELECT * FROM relacao WHERE pessoa_id='{}' AND funcao_id='{}' ;".format(pessoa_id, funcao_id)
        return self.db.comand(selectString)

    def delete(self, pessoa_id, funcao_id):
        """Deleta uma relação"""
        deletString = "DELETE FROM relacao WHERE pessoa_id='{}' AND funcao_id='{}' ;".format(pessoa_id, funcao_id)
        self.db.comand(deletString)
        self.db.commit()


# Prepara o ambiente
db = DB()
p = Pessoa(db)
s = Servico(db)
r = Relacao(db)

#Cria 2 Pessoas
p.insert("Lucas G",0,"lucas@Gmail","MG")
p.insert("Lucas M",1,"lucas@Mmail","MG")
#Mostra todas as pessoas
for cpf in range(2):
    for pessoa in p.select(cpf):
        print(pessoa)

#Cria 2 cargos
s.insert("Chefe",1000)
s.insert("Subordinado",1)
#Mostra dados sobre o cargo "Chefe"
s.select("Chefe")

#Cria uma relação de Pessoa-> Cargo
r.insert(1,1)
r.insert(2,2)
r.select(1,1)
#Mostra a relação
for k in range(3):
    for j in range(3):
        for i in r.select(j,k):
            print(i)