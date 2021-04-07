class User{
  int id;
  String user;
  String senha;

  // criando um construtor
  User(this.id,this.user,this.senha);

  User.map(dynamic obj) {
    this.id = obj['id'];
    this.user = obj['user'];
    this.senha = obj['senha'];
  }

  Map<String, dynamic> toMap() {
    var mapa = new Map<String, dynamic>();
    mapa["id"] = id;
    mapa["user"] = user;
    mapa["senha"] = senha;

    if (id != null){
      mapa["id"] = id;
    }
    return mapa;
  }

  User.fromMap(Map<String, dynamic> mapa) {
    this.id = mapa['id'];
    this.user = mapa['user'];
    this.senha = mapa['senha'];
  }
}