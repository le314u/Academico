
import 'package:lucas_projeto/modelo/bd/bd_fire.dart';
import 'package:lucas_projeto/modelo/beans/gasto.dart';

class Control{
  var tipo,tabela;

  Control(tipo,tabela){
    this.tabela = tabela;
    this.tipo = tipo;
  }

  Future<void> insert(g) async {
    await BdFire.instance.insert(g.toMap(),this.tabela);
  }

  Future<void> deletar(String id) async {
    await BdFire.instance.delete(id,this.tabela);
  }

  Future getAllList() async {
    var todasLinhas = await BdFire.instance.queryAllRows(this.tabela);
    var lg = [];
    todasLinhas.forEach((element) {
      var data = element.data;
      data['id'] = element.documentID;
      lg.add(
        this.tipo.fromMap(data)
      );
    });
    return lg;
  }

  Future get(String id) async {
    var obj =  await BdFire.instance.query(id, this.tabela);
    return this.tipo.fromMap(obj.data);
  }
}
