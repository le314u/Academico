class Gasto{
  String id;
  String tipo_gasto_id;
  String observacoes;
  String dataHora;
  double valor;

  // criando um construtor
  Gasto(this.id,this.tipo_gasto_id,this.observacoes,this.dataHora,this.valor);

  Gasto.map(dynamic obj) {
    this.id = obj['id'];
    this.tipo_gasto_id = obj['tipo_gasto_id'];
    this.observacoes = obj['observacoes'];
    this.dataHora = obj['dataHora'];
    this.valor = obj['valor'];
  }

  Map<String, dynamic> toMap() {
    var mapa = new Map<String, dynamic>();
    //mapa["id"] = id;
    mapa["tipo_gasto_id"] = tipo_gasto_id;
    mapa["observacoes"] = observacoes;
    mapa["dataHora"] = dataHora;
    mapa["valor"] = valor;

    if (id != null){
      mapa["id"] = id;
    }
    return mapa;
  }

  Gasto.fromMap(Map<String, dynamic> mapa) {
    this.id = mapa['id'];
    this.tipo_gasto_id = mapa['tipo_gasto_id'];
    this.observacoes = mapa['observacoes'];
    this.dataHora = mapa['dataHora'];
    this.valor = mapa['valor'];
  }
}