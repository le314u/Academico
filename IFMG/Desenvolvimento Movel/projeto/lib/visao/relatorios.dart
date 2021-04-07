
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:lucas_projeto/controle/relatorio.dart';

class Relatorios extends StatefulWidget {
  @override
  _RelatoriosState createState() => _RelatoriosState();
}


class _RelatoriosState extends State<Relatorios> {
  String valorDolar = "";
  valor() async {
    String valorDolarGet  = await Relatorio().get();
    setState(() {
      valorDolar = valorDolarGet;
    });
  }

  Widget build(BuildContext context) {
    var appBar2 = AppBar(
        title: Text("Fluxo"),
        backgroundColor: Colors.blue,
      );
    return Scaffold(
      appBar: appBar2,
      body: Center(
        child: Column(
          children: [
            Container(height: 300),
            Text('Dolar esta valendo '+ valorDolar +' fucking reais'),
            RaisedButton(
              child: Text('valor?'),
                onPressed:valor
            )
          ]
            ),
      )
            
    );
  }
}