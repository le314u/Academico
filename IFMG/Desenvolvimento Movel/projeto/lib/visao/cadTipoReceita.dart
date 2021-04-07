import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:lucas_projeto/controle/CTipoReceita.dart';
import 'package:lucas_projeto/modelo/beans/tipoReceita.dart';

class CadTipoReceita extends StatefulWidget {
  @override
  _CadTipoReceitaState createState() => _CadTipoReceitaState();
}

class _CadTipoReceitaState extends State<CadTipoReceita> {
  var instanciaControle = CTipoReceita();
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Tipo de Receita"),
        backgroundColor: Colors.blueGrey,
      ),
      backgroundColor: Colors.white,
      body: Column(
        children: <Widget>[
          Row(
            children: <Widget>[
              Expanded(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: <Widget>[
                    Card(
                      child: Padding(
                        padding: EdgeInsets.all(5),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          mainAxisAlignment: MainAxisAlignment.start,
                          children: <Widget>[
                            Text("Nome:",style: TextStyle(fontSize: 10)),
                            TextField(
                              controller: _tecNome,
                            ),
                          ],
                        ),
                      ),
                    ),
                    Card(
                      child: Padding(
                        padding: EdgeInsets.all(5),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          mainAxisAlignment: MainAxisAlignment.start,
                          children: <Widget>[
                            Text("Descrição:",style: TextStyle(fontSize: 10)),
                            TextField(
                              maxLines: 2,
                              controller: _tecDescricao,
                            )
                          ],
                        ),
                      ),
                    ),
                  ],
                ),
              ),
              Container(
                width: 60,
                height: 165,
                child: ButtonTheme(
                  height: 60.0,
                  child: RaisedButton(
                    onPressed: () {
                      _insereTipoReceita();
                    },
                    shape: new RoundedRectangleBorder(
                        borderRadius: new BorderRadius.circular(12.0)),
                    child: Icon(
                      Icons.add,
                      color: Colors.white,
                    ),
                    color: Colors.blue,
                  ),
                ),
              )
            ],
          ),
          Divider(
            height: 10,
          ),
          Text("::Dados::"),
          Expanded(
            child: ListView(children: _listViewTipoReceita),
          )
        ],
      ),
    );
  }

  //controllers dos texts fields
  TextEditingController _tecNome = TextEditingController();
  TextEditingController _tecDescricao = TextEditingController();

  //lista de tipo de gastos
  List<TipoReceita> _tiposReceita = List();

  //listView de tipos de gastos
  List<Widget> _listViewTipoReceita = List<Widget>();

  /**
   * Método responsável por construir o listview
   */
  _setListView() async {
    //busca lista de objetos Gasto do BD
    _tiposReceita = await instanciaControle.getAllList();

    //monta listView já na treade de visualização de forma dinâmica
    setState(() {
      try {
        _listViewTipoReceita = _tiposReceita
            .map(
              (_data) => Card(elevation: 3,child: Container(
                height: 60,
                child: Row(
                  children: <Widget>[
                    Expanded(
                      child: Padding(padding: EdgeInsets.all(10),child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        mainAxisAlignment: MainAxisAlignment.start,
                        children: <Widget>[
                          Text(
                            _data.nome.toString(),
                            style: TextStyle(
                                fontSize: 14, color: Colors.black),
                          ),
                          Text(
                            _data.descricao.toString(),
                            style: TextStyle(
                                fontSize: 10, color: Colors.black45),
                          ),
                        ],
                      ),),
                    ),
                    Container(height: 55,width: 55,child:
                    ButtonTheme(
                      height: 60.0,
                      child: RaisedButton(
                        onPressed: () {
                          _deleteTipoGasto(_data.id);
                        },
                        shape: new RoundedRectangleBorder(
                            borderRadius: new BorderRadius.circular(12.0)),
                        child: Icon(
                          Icons.remove,
                          color: Colors.white,
                        ),
                        color: Colors.blueGrey,
                      ),
                    ),)

                  ],
                ),
              ),),
            )
            .toList();
      } catch (_) {
        print("Não foi possível!");
        /*Toast.show("Não foi possível !", context,
            duration: Toast.LENGTH_LONG, gravity: Toast.CENTER);*/
      }
    });
  }

  _insereTipoReceita() {
    TipoReceita g = TipoReceita(null, _tecNome.text, _tecDescricao.text);
    instanciaControle.insert(g);
    setState(() {
      _setListView();
    });
  }

  _deleteTipoGasto(String id) {
    instanciaControle.deletar(id);
    setState(() {
      _setListView();
    });
  }

  /**
   * Método usado para inicialiar objetos e elementos ao criar a tela
   */
  @override
  void initState() {
    super.initState();

    //gera a listagem de elementos na thread de visão(de forma dinâmica)
    setState(() {
      _setListView();
    });
  }
}
