
logado=0;//sempre entra no site deslogado

function notas (quantia) { 
	/*Calcula as notas*/
	var notas100, notas50, notas20, notas10, notas5, notas2, notas1,resto;
	
	if(quantia >= 100){
		notas100 = parseInt(quantia/100);
		resto = (quantia % 100);
	}
	else{
		resto = quantia;
		notas100 = 0;
	}


	if(resto >= 50){
		notas50 = parseInt(resto/50);
		resto = (resto % 50);
	}
	else{
		notas50 = 0;
	}



	if(resto >= 20){
		notas20 = parseInt(resto/20);
		resto = (resto % 20);
	}
	else{
		notas20 = 0;
	}


	if(resto >= 10){
		notas10 = parseInt(resto/10);
		resto = (resto % 10);
	}
	else{
		notas10 = 0;
	}



	if(resto >= 5){
		notas5 = parseInt(resto/5);
		resto = (resto % 5);
	}
	else{
		notas5 = 0;
	}



	if(resto >= 2){
		notas2 = parseInt(resto/2);
		resto = (resto % 2);
	}
	else{
		notas2 = 0;
	}



	if(resto >= 1){
		notas1 = parseInt(resto/1);
		resto = (resto % 1);
	}
	else{
		notas1 = 0;
	}

	printa(notas1,notas2,notas5,notas10,notas20,notas50,notas100);
}


function login(){
	if(logado==1){
		alert("Você ja esta logado");
	}else{
		/*Printa na tela as tags html*/
		document.getElementById("principal").innerHTML='\
			<div class="centralizado">\
				<form action="javascript:calcula_senha()";>\
					<input type="text" id="login" value="Login">\
					<input type="password" id="password" value="Password">\
					<input type="submit" value="ok">\
				</form>\
			</div>\
		';
	}
}

function calcula_senha(){

	var username=document.getElementById("login").value;
	var password=document.getElementById("password").value;

	if (username === "admin" && password === "admin"){
		logado=1;
		window.alert("Logado");
		
	}
	else{
		if(password==""){
			alert("Você não digitou a senha")

		}else{
			window.alert("Nome de usuário ou senha inválidos");
		}
	}
}


function printa(nota1,nota2,nota5,nota10,nota20,nota50,nota100){
	/*Layout Cedulas*/
	/*Printa na tela as tags html*/
	document.getElementById("principal").innerHTML='\
	<table align=center>\
		<tr>\
			<td>\
				<h2 align=center>\
					<img height=100px width=200px src="./imagens/nota/nota2.jpg">\
					<br>\
					'+nota2+'\
				</h2>\
			</td>\
			<td>\
				<h2 align=center>\
					<img height=100px width=200px src="./imagens/nota/nota5.jpg">\
					<br>\
					'+nota5+'\
				</h2>\
			</td>\
			<td>\
				<h2 align=center>\
					<img height=100px width=200px src="./imagens/nota/nota10.jpg">\
					<br>\
					'+nota10+'\
				</h2>\
			</td>\
		</tr>\
		<td>\
				<h2 align=center>\
					<img height=100px width=200px src="./imagens/nota/nota20.jpg">\
					<br>\
					'+nota20+'\
				</h2>\
			</td>\
			<td>\
				<h2 align=center>\
					<img height=100px width=200px src="./imagens/nota/nota50.jpg">\
					<br>\
					'+nota50+'\
				</h2>\
			</td>\
			<td>\
				<h2 align=center>\
					<img height=100px width=200px src="./imagens/nota/nota100.jpg">\
					<br>\
					'+nota100+'\
				</h2>\
			</td>\
		</tr>\
		<tr>\
			<td colspan="3">\
				<h2 align=center>\
					<img height=75px width=75px src="./imagens/nota/moeda1.png">\
					<h3 align=center>'+nota1+'</h3>\
				</h2>\
			</td>\
		</tr>\
	</table>';	
}

function alerta_fecha(){
	if(logado==1){
		alert("Volte sempre");
		window.close();
	}else{
		alert("Você não está logado");
	}
}

function saque(){
	if(logado==1){
		var valor=prompt("Digite o valor do Saque ","R$");
		if(valor-parseInt(valor)==0){//Aceita apenas valores inteiros
			if(valor>=10 && valor<=2000){//Aceita apenas
				this.notas(valor);
			}else{
				alert("Digite apenas numeros de 10 a 2000");
			}
		}else{
			alert("Digite apenas numeros inteiros");
		}
	}else{
		alert("Você não está logado");
	}
}


/*informações*/
function info(){
	alert("As informações iram abrir em uma outra pagina");
	window.open("info.html","Configurações","height=300px , width=500px");
}

/*configurações*/
function confi(){
	var cor;
	cor="#"+parseInt(Math.random()*10)+parseInt(Math.random()*10)+parseInt(Math.random()*10)+parseInt(Math.random()*10)+parseInt(Math.random()*10)+parseInt(Math.random()*10)
	alert('As configurações estão sendo configuradas conforme foi configurado pelo configurador de configuração"'+cor+'"');
	document.getElementById("bg").style.backgroundColor=cor;
	
}
