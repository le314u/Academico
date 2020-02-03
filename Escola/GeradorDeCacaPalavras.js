//12:10
/*
Tabela é formada por uma lista de lista
Há 2 tabelas identicas (uma com meta dados) (outra com os caracteres)
sobrepondo as posiçoes das tabelas caso[metaDados]==1 significa que existe um caracter que não pode ser Modificado ou seja existe parte da palavra chave ali
As Palavras não se cruzam
*/

//Criar palavras Cruzadas automaticamente

//Constante
function Date(){
	//Constantes
	this.LETRAS=["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"];
	this.VOGAIS=["A","E","I","O","U"]
	this.CONSOANTES=["B","C","D","F","G","H","J","K","L","M","N","P","Q","R","S","T","V","W","X","Y","Z"];
	this.DIFICULDADE=["Baby","Leve","Easy","Medio","Dificil","ChuckNorris"];
	//Variaveis
	this.Palavras=[]
	//Procedimentos
	this.AddPalavra=function(palavra){
		//Adiciona uma palavra a lista de palavras e ja ordena
		this.Palavras.push(palavra)
		this.Palavras.sort(_ComparaTamanhoString)
	}
	this.RemovePalavra=function(palavra){
		//Adiciona uma palavra a lista de palavras e ja ordena
		indice=this.Palavras.indexOf(palavra)
		if(indice != -1){
			var tpm=this.Palavras[indice]
			this.Palavras[indice]=this.Palavras[this.Palavras.length-1]
			this.Palavras[this.Palavras.length-1]=tpm
			this.Palavras.pop()
			this.Palavras.sort(_ComparaTamanhoString)
		}
	}
	//Procedimentos internos
	function _ComparaTamanhoString(string1,string2){
		//Verifica qual string tem mais caracteres
		return string1.length-string2.length;
	}
}

function Tabela(){
	this.DATE=new Date();
	this.Tabela=null;
	this.MetaTabela=null;
	this.Palavras=this.DATE.Palavras

	this.CriarTabela=function(listaPalavras,TamanhoX,TamanhoY){
		//Cria Tabela
		this.Tabela=_EsqueletoTabela,(TamanhoX,TamanhoY);
		this.MetaTabela=_EsqueletoTabela,(TamanhoX,TamanhoY);
		
		//Para cada tabela (numero de copias) embaralhar
		
	}
	this.EmbaralharTabela=function(){
		//Preenche a tabela com caracteres aleatorios
		for (var i = this.tabela.length - 1; i >= 0; i--) {
			for (var j = this.tabela[i].length - 1; j >= 0; j--) {
				//Se metaTabela == 0 Significa que não existe uma palavra ja inclusa neste local
				if(this.metaTabela[i][j]==0){
					indice=Math.floor(Math.random()*DATE.LETRAS.length)
					this.tabela[i][j]=DATE.LETRAS[indice]
				}
			}
		}
	}
	function _EsqueletoTabela(x,y){
		//Cria uma tabela de "X x Y" sendo todos itens = 0
		var Tabela=Array(x);
		for (var i = Tabela.length - 1; i >= 0; i--) {
			Tabela[i]=Array(y)
			for (var j = Tabela[i].length - 1; j >= 0; j--) {
				Tabela[i][j]=0
			}
		}
		this.Tabela=Tabela
	}
	
	function _AddPalavraLinha(palavra,linha,metaLinha,indiceLinha){
		//So adiciona a palavra se couber na linha
		espacoRestanteLinha=(linha.length)-(indiceLinha+1)//mais 1 pois vetor começa em 0
		tamanhoPalavra=palavra.length
		if(tamanhoPalavra<=espacoRestanteLinha){
			if(!_ComparaMetaDadosLinha(metaLinha,indiceLinha,tamanhoPalavra)){
				return false
			}
			//O range não pode ser mudado caso uma palavra seja fixada
			Aleatoriedade=Math.floor(Math.random()*2)==0?true:false;	
			if(Aleatoriedade){
				//aleatoriamente da "esquerda para direita" ou da "direita para a esquerda"
				palavra.reverse()
			}
			//Add palavra na linha
			for (var i = indiceLinha; i < tamanhoPalavra; i++) {
				linha[i]=palavra[i%indiceLinha]//i%indiceLinha equivale ao indice inicial da palavra
				metaLinha[i]=1
			}
		}
	}
	function _AddPalavraColuna(palavra,tabela,metaTabela,indiceLinha,indiceColuna){
		//So adiciona a palavra se couber na Coluna
		espacoRestante=(tabela.length)-(indiceColuna+1)//mais 1 pois vetor começa em 0
		tamanhoPalavra=palavra.length
		if(tamanhoPalavra<=espacoRestante){
			if(!_ComparaMetaDadosColuna(metaLinha,indiceLinha,indiceColuna,tamanhoPalavra)){
				return false
			}
			//O range não pode ser mudado caso uma palavra seja fixada
			Aleatoriedade=Math.floor(Math.random()*2)==0?true:false;	
			if(Aleatoriedade){
				//aleatoriamente da "esquerda para direita" ou da "direita para a esquerda"
				palavra.reverse()
			}
			//Add palavra na linha
			for (let i = indiceLinha; i < tabela.length; i++) {
				tabela[i][indiceColuna]=palavra[i%indiceLinha]//i%indiceLinha equivale ao indice inicial da palavra
				metaLinha[i][indiceColuna]=1
			}
		}
	}
	function _ComparaMetaDadosLinha(metaDados,indice,tamanhoPalavra){
		//Se no percurso houver 1 significa que não pode ser alterado
		for (var i = indice; i <tamanhoPalavra; i++) {
			if(metaDados[i]==1){
				return false
			}
		}
		return true
	}
	function _ComparaMetaDadosColuna(metaDados,indiceLinha,indiceColuna,tamanho){
		//Se no percurso houver 1 significa que não pode ser alterado
		numeroLinhas=metaDados.length()
		numeroLinhasPercorridas=0;
		for (var i = indiceLinha;(i <numeroLinhas || i < tamanho); i++) {
			numeroLinhasPercorridas++
			if(metaDados[i][indiceColuna]==1){
				return false
			}
		}
		if(numeroLinhasPercorridas < Tamanho){
			return false;
		}
		return true
	}
	function _Range(inicio,fim,incremento){
		direcao=inicio-fim
		listaRange=[];
		if(direcao<0){
			for (let i=fim; i <=inicio; i=i-Math.abs(incremento)) {
				listaRange.push(i);
			}
		}else if(direcao>0){
			for (let i=inicio; i <=fim; i=i+Math.abs(incremento)) {
				listaRange.push(i);
			}
		}else{
			listaRange.push(inicio);
		}
		return listaRange;
	}
}








