
import 'package:lucas_projeto/modelo/bd/bd_fire.dart';
import 'package:lucas_projeto/modelo/beans/tipoReceita.dart';

class CTipoReceita{

  Future<void> insert(g) async {
    await BdFire.instance.insert(g.toMap(),BdFire.tableTipoReceita);
  }

  Future<void> deletar(String id) async {
    await BdFire.instance.delete(id,BdFire.tableTipoReceita);
  }

  Future<List<TipoReceita>> getAllList() async {
    var todasLinhas = await BdFire.instance.queryAllRows(BdFire.tableTipoReceita);
    List<TipoReceita> lg = [];
    todasLinhas.forEach((element) {
      var data = element.data;
      data['id'] = element.documentID;
      lg.add(
        TipoReceita.fromMap(data)
      );
    });
    return lg;
  }

  Future get(String id) async {
    var obj =  await BdFire.instance.query(id, BdFire.tableTipoReceita);
    return TipoReceita.fromMap(obj.data);
  }
}
