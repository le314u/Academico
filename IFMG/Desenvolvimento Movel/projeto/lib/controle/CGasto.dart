
import 'package:lucas_projeto/modelo/bd/bd_fire.dart';
import 'package:lucas_projeto/modelo/beans/gasto.dart';

class CGasto{

  Future<void> insert(g) async {
    await BdFire.instance.insert(g.toMap(),BdFire.tableGasto);
  }

  Future<void> deletar(String id) async {
    await BdFire.instance.delete(id,BdFire.tableGasto);
  }

  Future<List<Gasto>> getAllList() async {
    var todasLinhas = await BdFire.instance.queryAllRows(BdFire.tableGasto);
    List<Gasto> lg = [];
    todasLinhas.forEach((element) {
      var data = element.data;
      data['id'] = element.documentID;
      lg.add(
        Gasto.fromMap(data)
      );
    });
    return lg;
  }

  Future get(String id) async {
    var obj =  await BdFire.instance.query(id, BdFire.tableGasto);
    return Gasto.fromMap(obj.data);
  }
}
