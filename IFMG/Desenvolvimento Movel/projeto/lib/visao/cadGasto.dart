import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/painting.dart';
import 'package:flutter/services.dart';
import 'package:flutter/widgets.dart';
import 'package:flutter_masked_text/flutter_masked_text.dart';
import 'package:lucas_projeto/controle/CGasto.dart';
import 'package:lucas_projeto/controle/CTipoGasto.dart';
import 'package:lucas_projeto/controle/_control.dart';
import 'package:lucas_projeto/modelo/bd/bd_fire.dart';
import 'package:lucas_projeto/modelo/beans/gasto.dart';
import 'package:lucas_projeto/modelo/beans/tipoGasto.dart';
import 'package:intl/intl.dart';

class CadGasto extends StatefulWidget {
  @override
  _CadGastoState createState() => _CadGastoState();
}

class _CadGastoState extends State<CadGasto> {
  var instanciaControle = CGasto();
  var instanciaControleAt = CTipoGasto();

  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: Text("Cadastro de Gastos"),
          backgroundColor: Colors.blueGrey,
        ),
        backgroundColor: Colors.white,
        body: Column(
          children: <Widget>[
            //card para inserção
            Padding(
              padding: EdgeInsets.symmetric(horizontal: 10),
              child: Row(
                children: <Widget>[
                  Expanded(
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: <Widget>[
                        Row(
                          children: <Widget>[
                            Expanded(
                              child: Card(
                                child: Padding(
                                  padding: EdgeInsets.symmetric(horizontal: 5),
                                  child: Column(
                                    children: <Widget>[
                                      Text("Tipo de Gasto:",style: TextStyle(fontSize: 10),),
                                      //adiciona o DDB, se ele ainda for null, mostra um
                                      //texto, senão, mostra o próprio DDB
                                      _dropTgs.isEmpty
                                          ? Text(
                                              "Sem Cadastro de Tipos de Gastos",
                                              style: TextStyle(
                                                  fontWeight: FontWeight.bold),
                                            )
                                          : DropdownButton<TipoGasto>(
                                        value: _tgSelecionado,
                                        icon: Icon(Icons.arrow_downward),
                                        isExpanded: true,
                                        iconSize: 21,
                                        elevation: 12,
                                        style: TextStyle(color: Colors.black),
                                        underline: Container(
                                          height: 1,
                                          color: Colors.black54,
                                        ),
                                        onChanged: (TipoGasto novoItemSelecionado) {
                                          setState(() {
                                            _tgSelecionado = novoItemSelecionado;
                                            dropDownSelected(_tgSelecionado);
                                          });
                                        },
                                        items: _dropTgs,
                                      ),
                                    ],
                                    crossAxisAlignment:
                                        CrossAxisAlignment.start,
                                  ),
                                ),
                              ),
                            ),
                            Expanded(
                              child: Card(
                                child: Padding(
                                  padding: EdgeInsets.symmetric(horizontal: 5),
                                  child: Column(
                                    crossAxisAlignment:
                                        CrossAxisAlignment.start,
                                    children: <Widget>[
                                      Text("Valor:",style: TextStyle(fontSize: 10)),
                                      Row(
                                        children: <Widget>[
                                          Expanded(
                                            child: TextField(
                                              controller: _tecValorMascara,//_tecValor,
                                              keyboardType:
                                                  TextInputType.number,
                                              inputFormatters: <
                                                  TextInputFormatter>[
                                                LengthLimitingTextInputFormatter(
                                                    12),
                                                WhitelistingTextInputFormatter
                                                    .digitsOnly,
                                                BlacklistingTextInputFormatter
                                                    .singleLineFormatter,
                                              ],
                                            ),
                                          ),
                                          /*Text(","),
                                          Expanded(
                                            child: TextField(
                                              controller: _tecValorDecimal,
                                              keyboardType:
                                                  TextInputType.number,
                                              inputFormatters: <
                                                  TextInputFormatter>[
                                                LengthLimitingTextInputFormatter(
                                                    2),
                                                WhitelistingTextInputFormatter
                                                    .digitsOnly,
                                                BlacklistingTextInputFormatter
                                                    .singleLineFormatter,
                                              ],
                                            ),
                                          )*/
                                        ],
                                      ),
                                    ],
                                  ),
                                ),
                              ),
                            )
                          ],
                        ),
                        Row(
                          children: <Widget>[
                            Expanded(
                              child: Card(
                                child: Padding(
                                  padding: EdgeInsets.symmetric(horizontal: 5),
                                  child: Row(
                                    children: <Widget>[
                                      Expanded(
                                        child: Column(
                                          crossAxisAlignment:
                                              CrossAxisAlignment.start,
                                          children: <Widget>[
                                            Text("Data:",style: TextStyle(fontSize: 10)),
                                            TextField(
                                              controller: _tecData,
                                              keyboardType:
                                                  TextInputType.datetime,
                                              inputFormatters: <
                                                  TextInputFormatter>[
                                                LengthLimitingTextInputFormatter(
                                                    10),
                                                BlacklistingTextInputFormatter
                                                    .singleLineFormatter,
                                              ],
                                            ),
                                          ],
                                        ),
                                      ),
                                      Container(
                                        height: 50,
                                        width: 55,
                                        child: ButtonTheme(
                                          height: 40.0,
                                          child: RaisedButton(
                                            onPressed: callDatePicker, //() {},
                                            shape: new RoundedRectangleBorder(
                                                borderRadius:
                                                    new BorderRadius.circular(
                                                        12.0)),
                                            child: Icon(
                                              Icons.date_range,
                                              color: Colors.white,
                                            ),
                                            color: Colors.blueGrey,
                                          ),
                                        ),
                                      ),
                                    ],
                                  ),
                                ),
                              ),
                            ),
                            Expanded(
                              child: Card(
                                child: Padding(
                                  padding: EdgeInsets.symmetric(horizontal: 5),
                                  child: Row(
                                    children: <Widget>[
                                      Expanded(
                                        child: Column(
                                          crossAxisAlignment:
                                              CrossAxisAlignment.start,
                                          children: <Widget>[
                                            Text("Hora:",style: TextStyle(fontSize: 10)),
                                            TextField(
                                              controller: _tecHora,
                                              keyboardType:
                                                  TextInputType.datetime,
                                              inputFormatters: <
                                                  TextInputFormatter>[
                                                LengthLimitingTextInputFormatter(
                                                    5),
                                                BlacklistingTextInputFormatter
                                                    .singleLineFormatter,
                                              ],
                                            ),
                                          ],
                                        ),
                                      ),
                                      Container(
                                        height: 50,
                                        width: 55,
                                        child: ButtonTheme(
                                          height: 40.0,
                                          child: RaisedButton(
                                            onPressed: callTimePicker, //() {},
                                            shape: new RoundedRectangleBorder(
                                                borderRadius:
                                                    new BorderRadius.circular(
                                                        12.0)),
                                            child: Icon(
                                              Icons.access_time,
                                              color: Colors.white,
                                            ),
                                            color: Colors.blueGrey,
                                          ),
                                        ),
                                      )
                                    ],
                                  ),
                                ),
                              ),
                            )
                          ],
                        ),
                        Card(
                          child: Padding(
                            padding: EdgeInsets.symmetric(horizontal: 5),
                            child: Column(
                              children: <Widget>[
                                Text("Observações:",style: TextStyle(fontSize: 10)),
                                TextField(
                                  controller: _tecObservacoes,
                                  maxLines: 2,
                                ),
                              ],
                            ),
                          ),
                        )
                      ],
                    ),
                  ),
                ],
              ),
            ),
            Padding(
              padding: EdgeInsets.symmetric(horizontal: 10),
              child: Container(
                width: MediaQuery.of(context).size.width,
                height: 60,
                child: ButtonTheme(
                  height: 60.0,
                  child: RaisedButton(
                    onPressed: () {
                      inserirGasto();
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
              ),
            ),
            Divider(),
            Text("::Dados::"),
            Expanded(
              child: Padding(
                padding: EdgeInsets.all(10),
                child: _listaGastos,
              ),
            )
          ],
        ));
  }

  List<DropdownMenuItem<TipoGasto>> _dropTgs = List();
  List<TipoGasto> _tgs = List(); //lista extraida do BD
  TipoGasto _tgSelecionado =
      TipoGasto('-1', "Sem Cadastro", ""); //objeto selecionado
  DropdownButton _ddb = null; //objeto widget DDB

  /**
   * Método que gera o widget do DDB
   */
  void criaDropDownButtonTipoGasto() async {
    _tgs = await instanciaControleAt.getAllList();

    setState(() {
      TipoGasto tgTeste;
      if (!_tgs.isEmpty) tgTeste = _tgs.elementAt(0);//_tgSelecionado = _tgs.elementAt(0);
      _tgSelecionado = tgTeste;
      _dropTgs =
          _tgs.map<DropdownMenuItem<TipoGasto>>((TipoGasto s) {
            return DropdownMenuItem<TipoGasto>(
                value: s,
                child: Padding(
                  padding: EdgeInsets.all(10.0),
                  child: Row(
                    children: <Widget>[
                      Text(
                        s.nome ,
                        style: TextStyle(color: Colors.black,fontSize: 16),
                        //textScaleFactor: 1.3,
                      ),
                    ],
                  ),
                ));
          }).toList();


      /*_ddb = DropdownButton<TipoGasto>(items: _tgs.map((TipoGasto tgDDB) {
            return DropdownMenuItem<TipoGasto>(
              value: tgDDB,
              child: Text(tgDDB.nome),
            );
          }).toList(),
          onChanged: (TipoGasto novoItemSelecionado) {

            //setando o evento de seleção
            setState(() {
              _tgSelecionado = novoItemSelecionado;
              dropDownSelected(_tgSelecionado);
            });
          },
          value: _tgSelecionado,

      );*/
    });
    //_ddb = ;
  }
  void dropDownSelected(TipoGasto tg){
    setState(() {
      _tgSelecionado = tg;
    });
  }

  @override
  void initState() {
    super.initState();

    //Cria DropDownButton
    criaDropDownButtonTipoGasto();

    //cria lista de gastos cadastrados
    criaListaGastos();

    //inicializa tec de data e hora
    _tecData.text = DateFormat('dd/MM/yyyy').format(finaldate);
    _tecHora.text = DateFormat('kk:mm').format(finaldate);

  }

  //controlador do textField de observações
  TextEditingController _tecObservacoes = TextEditingController();

  //controlador do textField de valor
  //TextEditingController _tecValor = TextEditingController();
  //TextEditingController _tecValorDecimal = TextEditingController();

  //controlador do textField de data
  TextEditingController _tecData = TextEditingController();

  //controlador do textField de hora
  TextEditingController _tecHora = TextEditingController();

  void inserirGasto() {
    try {
      //double valor = double.parse(_tecValor.text + "." + _tecValorDecimal.text);
      double valor = double.parse(_tecValorMascara.text);
      Gasto g = Gasto(
          null,
          _tgSelecionado.id,
          _tecObservacoes.text,
          DateFormat('yyyy-MM-dd').format(finaldate) + " " + _tecHora.text,
          valor);
      instanciaControle.insert(g);
      //TODO atualiza lista de dados
      criaListaGastos();
    } catch (x) {}
  }

  ListView _listaGastos = null;
  List<Gasto> _lg = null;

  criaListaGastos() async {
    //pega lista do BD
    _lg = await instanciaControle.getAllList();

    setState(() {
      //gera o listView
      _listaGastos = ListView.builder(
        itemCount: _lg.length,
        itemBuilder: (context, index) {
          final item = _lg[index];
          return Card(child: Dismissible(
            direction: DismissDirection.horizontal,
            // Cada Dismissible deve conter uma Key.
            // As Keys permitem ao Flutter
            // identificar o widget de forma única
            key: Key(item.id.toString()),
            // Fornecemos uma função que diz ao app
            // o que fazer depois que o item for arrastado
            onDismissed: (direction) {
              // Remove o item da fonte de dados
              setState(() {
                deletaGasto(item.id);
              });
              // Exibe o snackbar
              Scaffold.of(context).showSnackBar(
                SnackBar(
                  content: Text("${item.valor} foi removido"),
                ),
              );
            },
            // Exibe uma cor vermelha de fundo
            // quando o item for arrastado
            background: Container(
              alignment: Alignment.centerLeft,
              color: Colors.red,
              child: Padding(
                padding: EdgeInsets.all(5),
                child: Icon(
                  Icons.delete,
                  color: Colors.white,
                ),
              ),
            ),
            child: ListTile(
              title: Text(
                '${item.valor}',
                style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16),
              ),
              subtitle: Text(
                '${DateFormat('kk:mm dd/MM/yyyy').format(DateTime.parse(item.dataHora))}',
                style: TextStyle(fontWeight: FontWeight.normal, fontSize: 12),
              ),
              onLongPress: () {
                setState(() {
                  showAlert(item);
                });
              },
              onTap: () {
                setState(() {
                  showAlert(item);
                });
              },
            ),
          ),);
        },
      );
    });
  }

  void deletaGasto(String id) async {
    //deleta o gasto
    await instanciaControle.deletar(id);
    //gera novamente a lista de dados a serem exibidos
    criaListaGastos();
  }

  ///////////////////////////////////////
  //DatePicker
  ///////////////////////////////////////
  var finaldate = DateTime.now();

  void callDatePicker() async {
    var order = await getDate();
    setState(() {
      finaldate = order;
      _tecData.text = DateFormat('dd/MM/yyyy').format(order);
    });
  }

  Future<DateTime> getDate() {
    return showDatePicker(
      context: context,
      initialDate: DateTime.now(),
      firstDate: DateTime(2018),
      lastDate: DateTime(2030),
      builder: (BuildContext context, Widget child) {
        return Theme(
          data: ThemeData.light(),
          child: child,
        );
      },
    );
  }
  ///////////////////////////////////////

  ///////////////////////////////////////
  //TimePicker
  ///////////////////////////////////////
  var finaltime = TimeOfDay.now();

  void callTimePicker() async {
    var order = await getTime();
    setState(() {
      finaltime = order;
      _tecHora.text = order.format(context);
    });
  }

  Future<TimeOfDay> getTime() async {
    return await showTimePicker(context: context, initialTime: TimeOfDay.now());
  }
  ///////////////////////////////////////

  /**
   * Neste showAlert, crio um alerta para mostrar os atributos do Gasto
   */
  showAlert(Gasto g) async{
    print("---->1");
    print("---->2");
    print("---->3");
    print("---->4");
    //pega o tipo de gasto para exibição do nome do tipo de gasto no alert
    TipoGasto tg = await instanciaControleAt.get(g.tipo_gasto_id);
    print(tg);

    print("---->5");
    print("---->6");
    //prepara o botão de ok para fechar o alert
    Widget okButton = FlatButton(
      child: Text("OK"),
      onPressed: () {
        Navigator.pop(context);
      },
    );
    // configura o  AlertDialog
    AlertDialog alerta = AlertDialog(
      title: Text("Info. Gasto"),
      content: tg == null?//faz o teste se o tipo de gasto é nulo, se for mostra um progress
      CircularProgressIndicator():
      Text("T.GASTO:${g.tipo_gasto_id.toString()}-${tg.nome};"
          "\nVALOR: ${g.valor};"
          "\nDATA: ${DateFormat("hh:mm dd/MM/yyyy").format(DateTime.parse(g.dataHora))};"
          "\nOBSERVAÇÕES: ${g.observacoes};"),
      actions: [
        okButton,
      ],
    );

    //comando respsonsável por exibir o dialog configurado anteriormente neste método
    showDialog(
      context: context,
      builder: (BuildContext context) {
        return alerta;
      },
    );

    

    
  }

  //controle responsável por criar uma máscara de dinheiro para um TF
  MoneyMaskedTextController _tecValorMascara = MoneyMaskedTextController(decimalSeparator: '.', thousandSeparator: '');
}
