
import 'package:lucas_projeto/modelo/bd/bd_fire.dart';
import 'package:lucas_projeto/modelo/beans/tipoGasto.dart';

class CTipoGasto{

  Future<void> insert(g) async {
    await BdFire.instance.insert(g.toMap(),BdFire.tableTipoGasto);
  }

  Future<void> deletar(String id) async {
    await BdFire.instance.delete(id,BdFire.tableTipoGasto);
  }

  Future<List<TipoGasto>> getAllList() async {
    var todasLinhas = await BdFire.instance.queryAllRows(BdFire.tableTipoGasto);
    List<TipoGasto> lg = [];
    todasLinhas.forEach((element) {
      var data = element.data;
      data['id'] = element.documentID;
      lg.add(
        TipoGasto.fromMap(data)
      );
    });
    return lg;
  }

  Future<TipoGasto> get(String id) async {
    print("GET----->");
    print(id);
    var obj =  await BdFire.instance.query(id, BdFire.tableTipoGasto);
    print(obj.data);
    return TipoGasto.fromMap(obj.data);
  }
}
