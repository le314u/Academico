import 'package:lucas_projeto/modelo/bd/bd_core.dart';
import 'package:lucas_projeto/modelo/beans/user.dart';

class CUser{

  Future<int> insert(User g) async {
    int id = await BdCore.instance.insert(g.toMap(),BdCore.tableUser);
    print('linha inserida id: $id');
    return id;
  }
  Future<int> update(User g) async {
    final linhasAfetadas = await BdCore.instance.update(g.toMap(),BdCore.tableUser);
    print('atualizadas $linhasAfetadas linha(s)');
    return linhasAfetadas;
  }
  Future<int> deletar(int id) async {
    final linhaDeletada = await BdCore.instance.delete(id, BdCore.tableUser);
    print('Deletada(s) $linhaDeletada linha(s): linha $id');
    return linhaDeletada;
  }

  Future<List<Map<String, dynamic>>> getAll() async {
    final todasLinhas = await BdCore.instance.queryAllRows(BdCore.tableUser);
    print('Consulta todas as linhas:');
    todasLinhas.forEach((row) => print(row));
    return todasLinhas;
  }

  Future<List<User>> getAllList() async {
    final todasLinhas = await BdCore.instance.queryAllRows(BdCore.tableUser);
    List<User> lg = List.generate(todasLinhas.length, (i) {
      return User(
          todasLinhas[i]['id'],
          todasLinhas[i]['user'],
          todasLinhas[i]['senha']
      );
    });
    return lg;
  }

  Future<User> get(int id) async {
    String sql = ""
        "SELECT * "
        "FROM User"
        "WHERE id = $id;";
    final todasLinhas = await BdCore.instance.querySQL(sql);
    List<User> lg = List.generate(todasLinhas.length, (i) {
      return User(
          todasLinhas[i]['id'],
          todasLinhas[i]['user'],
          todasLinhas[i]['senha'],
      );
    });
    User c = null;
    try {
      c = lg.elementAt(0);
    }catch(_){}
    return c;
  }
/*
  ///Select na tabela de pessoas fazendo join com a tabela de clientes,
  ///retornando a lista de todos os clientes tambem com as informações da tabela pessoa.
  Future<List<PessoaAmbulante>> getAllListAmbulante() async {
    String sql =
        "SELECT "
        " ambulante.id as id, "
        " pessoa.nome as nome, "
        " pessoa.sobrenome as sobrenome, "
        " pessoa.cpf as cpf, "
        " pessoa.observacao as observacao, "
        " ambulante.latitude as latitude, "
        " ambulante.longitude as longitude "

        "FROM "
        " pessoa INNER JOIN ambulante ON(pessoa.id = ambulante.pessoa_id);";

    final todasLinhas = await BdCore.instance.querySQL(sql);
    List<PessoaAmbulante> lc = List.generate(todasLinhas.length, (i) {
      return PessoaAmbulante(
          todasLinhas[i]['id'],
          todasLinhas[i]['nome'],
          todasLinhas[i]['sobrenome'],
          todasLinhas[i]['cpf'],
          todasLinhas[i]['obsevacao'],
          todasLinhas[i]['latitude'],
          todasLinhas[i]['longitude']
      );
    });
    return lc;
  }
*/
}
