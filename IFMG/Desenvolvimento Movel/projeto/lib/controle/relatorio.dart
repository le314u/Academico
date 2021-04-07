import 'package:http/http.dart' as http;
import 'dart:convert';
class Relatorio{
  Relatorio();
  Future<String> get() async {
    String url = 'https://economia.awesomeapi.com.br/all/USD-BRL';
    var response = await http.get(
      // Enviando a descrição na url
        Uri.encodeFull(url),
        headers: {
          "Accept": "application/json"
        });
    return json.decode(response.body)['USD']['ask'];
  }
}


