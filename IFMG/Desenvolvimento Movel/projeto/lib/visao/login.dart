
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:lucas_projeto/splash.dart';
  import 'package:lucas_projeto/visao/cadUser.dart';

//Gera uma celula com button
Widget butonLogin(BuildContext context){
  return RaisedButton(
    onPressed: (){
      // Verifica a autenticacão
    },
    child: Column( children:[Text('Logar')] )
  );
}


class Login extends StatefulWidget {

  @override
  _LoginState createState() => _LoginState();
}

class _LoginState extends State<Login> {

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body:Column(
          children: <Widget>[
            TextField(
              decoration: InputDecoration(
                border: OutlineInputBorder(),
                labelText: 'E-mail',
              ),
            ),
            TextField(
              obscureText: true,
              decoration: InputDecoration(
                border: OutlineInputBorder(),
                labelText: 'Password',
              ),
            ),
            Column(children: [
              RaisedButton(
                child: Text('Logar'),
                onPressed: () {
                  Navigator.pushReplacement(context, MaterialPageRoute(builder: (context) => Splash()));
                }
              ),
              RaisedButton(
                child: Text('Cadastrar'),
                onPressed: () {
                  Navigator.pushReplacement(context, MaterialPageRoute(builder: (context) => CadUser()));
                }
              )
            ])
          ]
        )
    );
  }
       
}