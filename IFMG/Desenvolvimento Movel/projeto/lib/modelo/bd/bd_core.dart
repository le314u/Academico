import 'dart:io';


import 'package:lucas_projeto/modelo/bd/bd_configs.dart';
import 'package:path/path.dart';
import 'package:path_provider/path_provider.dart';
import 'package:sqflite/sqflite.dart';

class BdCore {

  String _databaseName = Configs.databaseName;
  int _databaseVersion = Configs.databaseVersion;

  static final tableGasto = 'gasto';
  static final tableTipoGasto = 'tipogasto';
  static final tableReceita = 'receita';
  static final tableTipoReceita = 'tiporeceita';
  static final tableUser = 'user';


  // torna esta classe singleton
  BdCore._privateConstructor();
  static final BdCore instance = BdCore._privateConstructor();


  // tem somente uma referência ao banco de dados
  static Database _database;

  Future<Database> get database async {
    if (_database != null) return _database;
    // instancia o db na primeira vez que for acessado
    _database = await _initDatabase();
    return _database;
  }

  // abre o banco de dados e o cria se ele não existir
  _initDatabase() async {
    Directory documentsDirectory = await getApplicationDocumentsDirectory();
    String path = join(documentsDirectory.path, _databaseName);
    return await openDatabase(path,
        version: _databaseVersion,
        onCreate: _onCreate);
  }

  // Código SQL para criar o banco de dados e a tabela
  Future _onCreate(Database db, int version) async {
    //criando a tabela de configurações
    await db.execute('''
          CREATE TABLE $tableTipoGasto(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT ,
            descricao TEXT 
          )
          ''');
    await db.execute('''
          CREATE TABLE $tableGasto (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            tipo_gasto_id INTEGER,
            observacoes TEXT ,
            dataHora TIMESTAMP ,
            valor FLOAT 
          )
          ''');
    await db.execute('''
          CREATE TABLE $tableTipoReceita(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT ,
            descricao TEXT 
          )
          ''');
    await db.execute('''
          CREATE TABLE $tableReceita(
            id INTEGER PRIMARY KEY,
            tipo_receita_id INTEGER,
            observacoes TEXT,
            dataHora TIMESTAMP,
            valor FLOAT
          )
          ''');
     await db.execute('''
          CREATE TABLE $tableUser(
            id INTEGER PRIMARY KEY,
            user TEXT UNIQUE,
            senha TEXT
          )
          ''');
  }


  // métodos Helper
  //----------------------------------------------------
  // Insere uma linha no banco de dados onde cada chave
  // no Map é um nome de coluna e o valor é o valor da coluna.
  // O valor de retorno é o id da linha inserida.
  Future<int> insert(Map<String, dynamic> row, String table) async {
    Database db = await instance.database;
    return await db.insert(table, row);
  }

  // Todas as linhas são retornadas como uma lista de mapas, onde cada mapa é
  // uma lista de valores-chave de colunas.
  Future<List<Map<String, dynamic>>> queryAllRows(String table) async {
    Database db = await instance.database;
    return await db.query(table);
  }

  Future<List<Map<String, dynamic>>> querySQL(String sql) async {
    Database db = await instance.database;
    return await db.rawQuery(sql);
  }

  Future<void> executeSQL(String sql) async {
    Database db = await instance.database;
    return await db.execute(sql);
  }

  // Todos os métodos : inserir, consultar, atualizar e excluir, também podem ser feitos usando
  // comandos SQL brutos. Esse método usa uma consulta bruta para fornecer a contagem de linhas.
  Future<int> queryRowCount(String table) async {
    Database db = await instance.database;
    return Sqflite.firstIntValue(await db.rawQuery('SELECT COUNT(*) FROM $table'));
  }

  // Assumimos aqui que a coluna id no mapa está definida. Os outros
  // valores das colunas serão usados para atualizar a linha.
  Future<int> update(Map<String, dynamic> row, String table) async {
    Database db = await instance.database;
    int id = row["id"];
    return await db.update(table, row, where: 'id = ?', whereArgs: [id]);
  }

  // Exclui a linha especificada pelo id. O número de linhas afetadas é
  // retornada. Isso deve ser igual a 1, contanto que a linha exista.
  Future<int> delete(int id, String table) async {
    Database db = await instance.database;
    return await db.delete(table, where: 'id = ?', whereArgs: [id]);
  }
}