import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/painting.dart';
import 'package:flutter/services.dart';
import 'package:flutter/widgets.dart';
import 'package:flutter_masked_text/flutter_masked_text.dart';
import 'package:lucas_projeto/controle/CReceita.dart';
import 'package:lucas_projeto/controle/CTipoReceita.dart';
import 'package:lucas_projeto/modelo/beans/receita.dart';
import 'package:lucas_projeto/modelo/beans/tipoReceita.dart';
import 'package:intl/intl.dart';

class CadReceita extends StatefulWidget {
  @override
  _CadReceitaState createState() => _CadReceitaState();
}

class _CadReceitaState extends State<CadReceita> {
  var instanciaControle = CReceita();
  var instanciaControleAt = CTipoReceita();
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: Text("Cadastro de Receitas"),
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
                                      Text("Tipo de Receita:",style: TextStyle(fontSize: 10),),
                                      //adiciona o DDB, se ele ainda for null, mostra um
                                      //texto, senão, mostra o próprio DDB
                                      _dropTgs.isEmpty
                                          ? Text(
                                              "Sem Cadastro de Tipos de Receitas",
                                              style: TextStyle(
                                                  fontWeight: FontWeight.bold),
                                            )
                                          : DropdownButton<TipoReceita>(
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
                                        onChanged: (TipoReceita novoItemSelecionado) {
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
                      inserirReceita();
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
                child: _listaReceitas,
              ),
            )
          ],
        ));
  }

  List<DropdownMenuItem<TipoReceita>> _dropTgs = List();
  List<TipoReceita> _tgs = List(); //lista extraida do BD
  TipoReceita _tgSelecionado =
      TipoReceita('-1', "Sem Cadastro", ""); //objeto selecionado
  DropdownButton _ddb = null; //objeto widget DDB

  /**
   * Método que gera o widget do DDB
   */
  void criaDropDownButtonTipoReceita() async {
    _tgs = await instanciaControleAt.getAllList();

    setState(() {
      TipoReceita tgTeste;
      if (!_tgs.isEmpty) tgTeste = _tgs.elementAt(0);//_tgSelecionado = _tgs.elementAt(0);
      _tgSelecionado = tgTeste;
      _dropTgs =
          _tgs.map<DropdownMenuItem<TipoReceita>>((TipoReceita s) {
            return DropdownMenuItem<TipoReceita>(
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


      /*_ddb = DropdownButton<TipoReceita>(items: _tgs.map((TipoReceita tgDDB) {
            return DropdownMenuItem<TipoReceita>(
              value: tgDDB,
              child: Text(tgDDB.nome),
            );
          }).toList(),
          onChanged: (TipoReceita novoItemSelecionado) {

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
  void dropDownSelected(TipoReceita tg){
    setState(() {
      _tgSelecionado = tg;
    });
  }

  @override
  void initState() {
    super.initState();

    //Cria DropDownButton
    criaDropDownButtonTipoReceita();

    //cria lista de Receitas cadastrados
    criaListaReceitas();

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

  void inserirReceita() {
    try {
      //double valor = double.parse(_tecValor.text + "." + _tecValorDecimal.text);
      double valor = double.parse(_tecValorMascara.text);
      Receita g = Receita(
          null,
          _tgSelecionado.id,
          _tecObservacoes.text,
          DateFormat('yyyy-MM-dd').format(finaldate) + " " + _tecHora.text,
          valor);
      instanciaControle.insert(g);
      //TODO atualiza lista de dados
      criaListaReceitas();
    } catch (x) {}
  }

  ListView _listaReceitas = null;
  List<Receita> _lg = null;

  criaListaReceitas() async {
    //pega lista do BD
    _lg = await instanciaControle.getAllList();

    setState(() {
      //gera o listView
      _listaReceitas = ListView.builder(
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
                deletaReceita(item.id);
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

  void deletaReceita(String id) async {
    //deleta o Receita
    await instanciaControle.deletar(id);
    //gera novamente a lista de dados a serem exibidos
    criaListaReceitas();
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
   * Neste showAlert, crio um alerta para mostrar os atributos do Receita
   */
  showAlert(Receita g) async{
    //pega o tipo de Receita para exibição do nome do tipo de Receita no alert
    TipoReceita tg = await instanciaControleAt.get(g.tipo_receita_id);
    //prepara o botão de ok para fechar o alert
    Widget okButton = FlatButton(
      child: Text("OK"),
      onPressed: () {
        Navigator.pop(context);
      },
    );
    // configura o  AlertDialog
    AlertDialog alerta = AlertDialog(
      title: Text("Info. Receita"),
      content: tg == null?//faz o teste se o tipo de Receita é nulo, se for mostra um progress
      CircularProgressIndicator():
      Text("T.GASTO:${g.tipo_receita_id.toString()}-${tg.nome};"
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
