import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';
import 'package:lucas_projeto/controle/CUser.dart';
import 'package:lucas_projeto/modelo/beans/user.dart';
import 'package:lucas_projeto/visao/login.dart';

class CadUser extends StatefulWidget {
  @override
  _CadUserState createState() => _CadUserState();
}

class _CadUserState extends State<CadUser> {
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("User"),
        backgroundColor: Colors.blueGrey,
      ),
      backgroundColor: Colors.white,
      body: Column(
        children: <Widget>[
          //card para inserção
          Row(
            children: <Widget>[
              Expanded(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: <Widget>[
                    Card(child:
                    Padding(padding: EdgeInsets.all(5),child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: <Widget>[
                        Text("User:",style: TextStyle(fontSize: 10),),
                        TextField(
                          controller: _tecNome,
                        ),
                      ],),),),
                    Card(child:
                    Padding(padding: EdgeInsets.all(5),child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: <Widget>[
                        Text("senha:",style: TextStyle(fontSize: 10)),
                        TextFormField(
                          autofocus: true,
                          obscureText: true,
                          maxLines: 1,
                          controller: _tecDescricao,
                        )
                      ],),),),
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
                      _insereUser();
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
          Divider(height: 10,),
          Row(children:[
            Expanded(
              child:RaisedButton(
                child: Text('Volta tela Login'),
                onPressed: () {
                  Navigator.pushReplacement(context, MaterialPageRoute(builder: (context) => Login()));
                }
              ),)]),
          Text("::Usuarios::"),
          Expanded(
            child: ListView(children: _listViewUser),
          )
        ],
      ),
    );
  }

  //controllers dos texts fields
  TextEditingController _tecNome = TextEditingController();
  TextEditingController _tecDescricao = TextEditingController();

  //lista de tipo de gastos
  List<User> _user = List();

  //listView de tipos de gastos
  List<Widget> _listViewUser = List<Widget>();

  /**
   * Método responsável por construir o listview
   */
  _setListView() async {
    //busca lista de objetos Gasto do BD
    _user = await CUser().getAllList();

    //monta listView já na treade de visualização de forma dinâmica
    setState(() {
      try {
        _listViewUser = _user
            .map(
              (_data) => Card(
                  elevation: 3,
                  child: Container(
                    height: 60,
                    child: Row(
                      children: <Widget>[
                        Expanded(child:
                          Padding(padding: EdgeInsets.all(10),child: Column(
                            crossAxisAlignment: CrossAxisAlignment.start,
                            mainAxisAlignment: MainAxisAlignment.start,
                            children: <Widget>[
                              Text(
                                _data.user.toString(),
                                style: TextStyle(fontSize: 14,color: Colors.black),
                              ),
                            ],),),),
                        Container(height: 55,width: 55,child: ButtonTheme(
                          height: 60.0,
                          child: RaisedButton(
                            onPressed: () {
                              _deleteUser(_data.id);
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
                  )),
            )
            .toList();
      } catch (_) {
        print("Não foi possível!");
        /*Toast.show("Não foi possível!", context,
            duration: Toast.LENGTH_LONG, gravity: Toast.CENTER);*/
      }
    });
  }

  _insereUser() {
    User g = User(null, _tecNome.text, _tecDescricao.text);
    CUser().insert(g);
    setState(() {
      _setListView();
    });
  }

  _deleteUser(int id){
    CUser().deletar(id);
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
