import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:lucas_projeto/visao/cadGasto.dart';
import 'package:lucas_projeto/visao/cadReceita.dart';
import 'package:lucas_projeto/visao/cadTipoGasto.dart';
import 'package:lucas_projeto/visao/cadTipoReceita.dart';
import 'package:lucas_projeto/visao/principal.dart';
import 'package:lucas_projeto/visao/relatorios.dart';

//indice de seleção da tela
int _selectedIndex = 0;

//vetor de telas a serem utilizadas
List<Widget> _stOptions = <Widget>[
  Principal(),
  CadGasto(),
  CadReceita(),
  CadTipoGasto(),
  CadTipoReceita(),
  Relatorios(),
];

class Navegar extends StatefulWidget {
  int _opcao;

  //contrutor passando o indice da tela selecionada
  Navegar(this._opcao);

  @override
  _NavegarState createState() => _NavegarState(this._opcao);
}

class _NavegarState extends State<Navegar> {

  //construtor
  _NavegarState(this._opcao);
  int _opcao;

  @override
  void initState() {
    _selectedIndex = _opcao;
  }


  Widget build(BuildContext context) {
    return  Scaffold(
      appBar: AppBar(
        title: Text("lucas_projeto"),
        backgroundColor: Colors.blue,
      ),

      //corpo da aplicação, aqui são setadas as telas
      body: _stOptions.elementAt(_selectedIndex),

      //aqui é construido o NavigationDrawer
      drawer: Drawer(
        child: ListView(
          children: <Widget>[
            //cabeçalho do NavDrawer
            UserAccountsDrawerHeader(
              accountName: Text("lucas_projeto App"),
              accountEmail: Text("Aplicativo de apoio financeiro"),
              decoration: BoxDecoration(
                color: Color(0xFF00ad9e),
                gradient: LinearGradient(
                    colors: [Colors.blue, Colors.blueGrey]),
              ),
              currentAccountPicture: CircleAvatar(
                    radius: 30.0,
                    backgroundImage: NetworkImage(
                        'https://www.ifmg.edu.br/portal/imagens/logovertical.jpg'),
                    backgroundColor: Colors.transparent,
                  ),
              arrowColor: Colors.teal,
            ),

            //lista de opções do NavDrawer
            ListTile(
                leading: Icon(Icons.home),
                title: Text("Principal"),
                subtitle: Text("Tela inicial do App"),
                trailing: Icon(Icons.navigate_next),
                onTap: () {
                  Navigator.pushReplacement(context,MaterialPageRoute(builder: (context) => Navegar(0)));
                }),
            ListTile(
                leading: Icon(Icons.remove_circle),
                title: Text("Gastos"),
                subtitle: Text("Cadastro de gastos"),
                trailing: Icon(Icons.navigate_next),
                onTap: () {
                  Navigator.pushReplacement(context,
                      MaterialPageRoute(builder: (context) => Navegar(1)));
                  //Navigator.pop(context);
                }),
            ListTile(
                leading: Icon(Icons.add_circle),
                title: Text("Receitas"),
                subtitle: Text("Cadastros de receitas"),
                trailing: Icon(Icons.navigate_next),
                onTap: () {
                  Navigator.pushReplacement(
                      context,
                      MaterialPageRoute(builder: (context) => Navegar(2)));
                  //Navigator.pop(context);
                }),
            ListTile(
                leading: Icon(Icons.money_off),
                title: Text("Tipo de gastos"),
                subtitle: Text("Cadastros de tipos de gastos"),
                trailing: Icon(Icons.navigate_next),
                onTap: () {
                  Navigator.push(
                      context,
                      MaterialPageRoute(builder: (context) => CadTipoGasto()));
                  //Navigator.pop(context);
                }),
            ListTile(
                leading: Icon(Icons.attach_money),
                title: Text("Tipo de Receitas"),
                subtitle: Text("Cadastros de tipos de receitas"),
                trailing: Icon(Icons.navigate_next),
                onTap: () {
                  Navigator.push(
                      context,
                      MaterialPageRoute(builder: (context) => CadTipoReceita()));
                  //Navigator.pop(context);
                }),
            ListTile(
                leading: Icon(Icons.list),
                title: Text("Relatórios"),
                subtitle: Text("Relatórios de gastos"),
                trailing: Icon(Icons.navigate_next),
                onTap: () {
                  Navigator.push(context, MaterialPageRoute(builder: (context) => Relatorios()));
                  //Navigator.pop(context);
                })
          ],
        ),
      ),

      //botões do BN
      bottomNavigationBar: BottomNavigationBar(
        items: const <BottomNavigationBarItem>[
          
          BottomNavigationBarItem(
            icon: Icon(Icons.home),
            title: Text('Principal'),
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.remove_circle),
            title: Text('Gastos'),
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.add_circle),
            title: Text('Receitas'),
          )
        ],

        unselectedItemColor: Colors.grey,

        currentIndex: _selectedIndex,

        selectedItemColor: Colors.orange,
        //greenAccent,
        onTap:
        _onItemTapped, //chama o métdodo onItemTapped ao clicar no botao do BTNNavigation
      ),
    );
  }

  @override
  void _onItemTapped(int  index) {
    setState(() {
      _selectedIndex = index;
    });
  }
}