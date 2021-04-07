import 'dart:io';
import 'package:lucas_projeto/modelo/bd/bd_configs.dart';
import 'package:path/path.dart';
import 'package:path_provider/path_provider.dart';
import 'package:sqflite/sqflite.dart';
import 'package:cloud_firestore/cloud_firestore.dart';


class BdFire {
  Firestore controlFireBase =  Firestore.instance ;
  static final tableGasto = 'gasto';
  static final tableTipoGasto = 'tipogasto';
  static final tableReceita = 'receita';
  static final tableTipoReceita = 'tiporeceita';
  static final tableUser = 'user';


  // torna esta classe singleton
  BdFire._privateConstructor();
  static final BdFire instance = BdFire._privateConstructor();



  // métodos Helper
  //----------------------------------------------------
  // Insere uma linha no banco de dados onde cada chave
  // no Map é um nome de coluna e o valor é o valor da coluna.
  // O valor de retorno é o id da linha inserida.
  Future<void> insert(Map<String, dynamic> row, String table) async {
    await controlFireBase.collection(table).add(row);
  }

  // Todas as linhas são retornadas como uma lista de mapas, onde cada mapa é
  // uma lista de valores-chave de colunas.
  Future<List<DocumentSnapshot>> queryAllRows(String table) async {
    var documents = await controlFireBase.collection(table).getDocuments();
    return documents.documents;
  }

  Future<DocumentSnapshot> query(String id,String table ) async {
    return await controlFireBase.collection(table).document(id).get();
  }

  // Exclui a linha especificada pelo id. O número de linhas afetadas é
  // retornada. Isso deve ser igual a 1, contanto que a linha exista.
  Future<void> delete(String id, String table) async {
    return await controlFireBase.collection(table).document(id).delete();
  }
}