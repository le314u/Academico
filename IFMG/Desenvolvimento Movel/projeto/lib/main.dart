import 'package:flutter/material.dart';
import './visao/login.dart';
import 'package:firebase_core/firebase_core.dart';
void main() {
  // it should be the first line in main method
  WidgetsFlutterBinding.ensureInitialized();
  //Inicializa o fireBase
  //Inicializa o APP
  runApp(MaterialApp(
      title: "Fluxo Caixa",
      home: Login()
  ));

}