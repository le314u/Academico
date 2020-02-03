package MODELO;
/**Classe que faz tratamento do cpf
 *private boolean fomatedCpf   
 *private boolean validCpf
 *private String formated
 *private String noFormated
 * @author Lucas Mateus Fernandes
 */
public class Documentos {
	private boolean formatedCpf=false;
	private boolean validCpf=false;
	private String formated="";
	private String noFormated="";
	
	/**
         * Construtor que Valida e Preencher CPF c/ e s/ Formatação
         * @param cpf String com cpf formatado ou não
         */
	public Documentos(String cpf){
		this.validaCpf(cpf);
	}
	
	
	public Documentos(){
	}
	
	
	/**
	 *@return Retorna True ou False para ver se o cpf digitado no contrutor veio com pontuação '14 digitos' ou sem pontuação '11digitos	
	 */	
	public boolean getFomatedCpf() {
		return formatedCpf;
	}

	
	/**
	 *@return Retorna True ou False para ver se o cpf digitado é valido ou nao
	 */	
	public boolean getValidCpf() {
		return validCpf;
	}
	
	
	/**
	 * Faz a verificação do CPF se é valido ou nao
	 *@param cpf - Cpf
	 *@return Retorna True ou False para ver se o cpf digitado é valido ou nao
	 */	
	public boolean validaCpf(String cpf) {
		
		int nponto = 0;
		int nhifen = 0;
		int[] dv1 = new int[11];//coloco 11 mas na vdd usa so 9
		int[] dv2 = new int[11];//assim fica mais facil de fazer o for
		int tamanho=cpf.length();

		//Verifica a quantidade de caracteres
		int indice=0;
		if(!(tamanho==14 || tamanho==11)) {
                        System.out.println("Cpf veio com "+cpf.length()+" caracteres");
			validCpf=false;
			return false;
			//Sem pontuação tamanho é 11 digitos
			//Com pontuação tamanho é 14 = 11 digitos  2 '.' 1'-'
		}
		//Se tiver pontuação Verifica se esta correta
		if(tamanho==14){
			if(cpf.charAt(3)!='.') {
				validCpf=false;
				return false;
			}
			if(cpf.charAt(7)!='.') {
				validCpf=false;
				return false;
			}
			if(cpf.charAt(11)!='-') {
				validCpf=false;
				return false;
			}
                        //Pontuação esta ok
                        
			for (indice = 0; indice < tamanho; indice++) {
				if(cpf.charAt(indice)!='0') {
				//For aninhado evita processamento desneecessário
					if(cpf.charAt(indice)!='1') {
						if(cpf.charAt(indice)!='2') {
							if(cpf.charAt(indice)!='3') {
								if(cpf.charAt(indice)!='4') {
									if(cpf.charAt(indice)!='5') {
										if(cpf.charAt(indice)!='6') {
											if(cpf.charAt(indice)!='7') {
												if(cpf.charAt(indice)!='8') {
													if(cpf.charAt(indice)!='9') {
														if(cpf.charAt(indice)!='.') {
															if(cpf.charAt(indice)!='-') {
																validCpf=false;
																return false;
																//Se não for igual a nenhum digito e nem '.' ou '-' o usuario passou algum caractere invalido
															}else {
																nhifen++;
																if(nhifen >1) {//Evita que tenha mais de 1 hifen
																	System.out.println("Pontuação Incorreta pois Possui + de 1 hifen ");
																	validCpf=false;
																	return false;
																}
																continue;
															}
														}else {
															nponto++;
															if(nponto >2) {//Evita que tenha mais de 2 pontos
																System.out.println("Pontuação Incorreta pois Possui + de 2 pontos ");
																validCpf=false;
																return false;
															}
															continue;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					dv1[(indice-(nhifen+nponto))]=( cpf.charAt(indice)-'0')*(10-(indice-(nhifen+nponto)));
					//Primeiramente multiplica-se os 9 primeiros dígitos pela sequência decrescente de números de 10 à 2 e soma os resultados
					dv2[(indice-(nhifen+nponto))]=( cpf.charAt(indice)-'0')*(11-(indice-(nhifen+nponto)));
					//Primeiramente multiplica-se os 9 primeiros dígitos pela sequência decrescente de números de 10 à 2 e soma os resultados
				}
			}
		}
		if(tamanho==11){
			for (indice = 0; indice < tamanho; indice++) {
				if(cpf.charAt(indice)!='0') {
				//For aninhado evita processamento desneecessário
					if(cpf.charAt(indice)!='1') {
						if(cpf.charAt(indice)!='2') {
							if(cpf.charAt(indice)!='3') {
								if(cpf.charAt(indice)!='4') {
									if(cpf.charAt(indice)!='5') {
										if(cpf.charAt(indice)!='6') {
											if(cpf.charAt(indice)!='7') {
												if(cpf.charAt(indice)!='8') {
													if(cpf.charAt(indice)!='9') {
														validCpf=false;
														System.out.println("Cpf possui Caracteres");
														return false;//Se não for igual a nenhum digito
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}	
				//OBS:AscII 0 é o primeiro digito e 9 o ultimo
				dv1[indice]=(cpf.charAt(indice)-'0')*(10-indice);
				//Primeiramente multiplica-se os 9 primeiros dígitos pela sequência decrescente de números de 10 à 2 e soma os resultados
				dv2[indice]=(cpf.charAt(indice)-'0')*(11-indice);
				//Primeiramente multiplica-se os 10 primeiros dígitos pela sequência decrescente de números de 11 à 2 e soma os resultados
			}
		}

		//Evita lixo
		int total1=0;
		int total2=0;

		//Somatorio
		for (int i = 0; i < 9; i++) { 
			total1+=dv1[i];
			total2+=dv2[i];
		}
		total2+=dv2[9];

		
		if(tamanho==11) {//Verifica se os digitos batem "opção sem formataçao"
			if((cpf.charAt(9)-'0')!=(11-(total1)%11)){
				if(!((cpf.charAt(9)-'0')==0 && (11-(total1)%11)>9)){
					System.out.println("Digito verificador 1 está incorreto");
					validCpf=false;
					return false;
				}
			}
			if((cpf.charAt(10)-'0')!=(11-(total2)%11)) {
				if(!((cpf.charAt(10)-'0')==0 && (11-(total2)%11)>9)){
					System.out.println("Digito verificador 2 está incorreto");
					validCpf=false;
					return false;
				}
			}
			formatedCpf=false;//Seta as variaveis
			noFormated=cpf;//Seta as variaveis
		}else {//Verifica se os digitos batem "opçao com formatação"s
			if(tamanho==14) {
				if((cpf.charAt(12)-'0')!=(11-(total1)%11)) {
					if(!((cpf.charAt(12)-'0')==0 && (11-(total1)%11)>9)){
						System.out.println("Digito verificador 1 está incorreto");
						validCpf=false;
						return false;
					}
				}
				if((cpf.charAt(13)-'0')!=(11-(total2)%11)) {
					if(!((cpf.charAt(13)-'0')==0 && (11-(total2)%11)>9)){
						System.out.println("Digito verificador 2 está incorreto");
						validCpf=false;
						return false;
					}
				}
				formatedCpf=true;//Seta as variaveis
				formated=cpf;
			}
		}
		validCpf=true;
		stringsCpf();
		return true;
			
	}
	/**
         * Iria Implementar um Grafico com a região que o Candidato ganhou mais votos... IRIA
         * @param cpf String com CPF
         * @return Região do Cpf
         */	
	public String regiaoCpf(String cpf) {
		if(validCpf != true) {
			return "Cpf Invalido";
		}
		char digito= ' ';
		
		if(formatedCpf==true) {
			digito=cpf.charAt(10);//9ºDigito
		}else {
			digito=cpf.charAt(8);//9ºDigito
		}
			switch (digito) {
			case '0':
				return "Rio Grande do Sul";
			case '1':
				return "Distrito Federal ou Goiás ou Mato Grosso ou Mato Grosso do Sul ou Tocantins";
			case '2':
				return "Amazonas ou Pará ou Roraima ou Amapá ou Acre ou Rondônia";
			case '3':
				return "Ceará ou Maranhão ou Piauí";
			case '4':
				return "Paraíba ou Pernambuco ou Alagoas ou Rio Grande do Norte";
			case '5':
				return "Bahia ou Sergipe";
			case '6':
				return "Minas Gerais";
			case '7':
				return "Rio de Janeiro ou Espírito Santo";
			case '8':
				return "São Paulo";
			case '9':
				return "Paraná ou Santa Catarina";				
			default:
				return "Cpf Invalido";
			}		
	}
	/**
	 *Seta as Flags informando se esta foramtado e com oseria formatado
	 */	
	public void stringsCpf(){
		String cpf ="";
		if(formatedCpf==true) {
			cpf+=formated.charAt(0);
			cpf+=formated.charAt(1);
			cpf+=formated.charAt(2);
			//.
			cpf+=formated.charAt(4);
			cpf+=formated.charAt(5);
			cpf+=formated.charAt(6);
			//.
			cpf+=formated.charAt(8);
			cpf+=formated.charAt(9);
			cpf+=formated.charAt(10);
			//-
			cpf+=formated.charAt(12);
			cpf+=formated.charAt(13);
			
			this.noFormated=cpf;
		}else {
			cpf+=noFormated.charAt(0);
			cpf+=noFormated.charAt(1);
			cpf+=noFormated.charAt(2);
			cpf+='.';//.
			cpf+=noFormated.charAt(3);
			cpf+=noFormated.charAt(4);
			cpf+=noFormated.charAt(5);
			cpf+='.';//.
			cpf+=noFormated.charAt(6);
			cpf+=noFormated.charAt(7);
			cpf+=noFormated.charAt(8);
			cpf+='-';//-
			cpf+=noFormated.charAt(9);
			cpf+=noFormated.charAt(10);
			
			this.formated=cpf;
		}
		
	}
	/**
	 *@return String- Cpf sem pontuação 11digitos
	 */	
        @Override
	public String toString(){
		return noFormated;	
	}
	/**
	 *@return String- Cpf com pontuação 14digitos
	 */	
	public String toStringPonto(){
		return formated;		
	}
	/**
        * @param cpf String cpf formatado ou não
	 *@return Boolean -Verifica se o cpf é igual "Tanto com pontuação ou sem pontuação'
	 */	
	public boolean equals(String cpf){
            //Verifica se é igual formatado ou não
            		return cpf.equals(formated)||cpf.equals(noFormated);
	}
	
}












