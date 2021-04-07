
import 'package:lucas_projeto/modelo/bd/bd_fire.dart';
import 'package:lucas_projeto/modelo/beans/receita.dart';

class CReceita{

  Future<void> insert(g) async {
    await BdFire.instance.insert(g.toMap(),BdFire.tableReceita);
  }

  Future<void> deletar(String id) async {
    await BdFire.instance.delete(id,BdFire.tableReceita);
  }

  Future<List<Receita>> getAllList() async {
    var todasLinhas = await BdFire.instance.queryAllRows(BdFire.tableReceita);
    List<Receita> lg = [];
    todasLinhas.forEach((element) {
      var data = element.data;
      data['id'] = element.documentID;
      lg.add(
        Receita.fromMap(data)
      );
    });
    return lg;
  }

  Future get(String id) async {
    var obj =  await BdFire.instance.query(id, BdFire.tableReceita);
    return Receita.fromMap(obj.data);
  }
}
