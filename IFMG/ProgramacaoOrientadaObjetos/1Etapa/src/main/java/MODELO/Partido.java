package MODELO;
import java.util.Date;

/**Classe que faz tratamento do cpf
*private String Nome;
*private int Numero;
*private Date DataCadastro;
 * @author Lucas Mateus Fernandes
 */

public class Partido {
	private String Nome;
	private int Numero;
	private Date DataCadastro;
	
	/**
	 * 
	 * @param nome Nome do partido
	 * @param numero Numero do partido
	 */
	
	public Partido(String numero,String nome) {
		System.out.println("Criando Partido");
		
		this.Numero=Integer.parseInt(numero);
		this.Nome=nome;
		DataCadastro=null;//So é relevante para a Central		
	}
	public Partido() {
		
	}
	/**
	 * 
	 * @return Object com data de cadastro
	 */
	public Date getDataCadastro() {
		return DataCadastro;
	}
	/**
	 * 
	 * @param nome Nome do partido
	 */
	public void setNome(String nome) {
		this.Nome = nome;
	}
	/**
	 * @return Nome do Partido
	 */
	public String getNome() {
		return Nome;
	}
	/**
	 * 
	 * @return Nome do Partido em CAIXA ALTA
	 */
	public String getNOME() {
		String aux=this.Nome.toUpperCase();//Transforma tudo em caixa alta
		String[] parts = aux.split(" ");//Separa em espaços
		String retorno ="";
		for (int i = 0; i < parts.length; i++) {//Junta tudo ignorando espaço
			retorno+=parts[i];
		}
				
		return retorno;
	}
	/**
	 * @param numero Numero do partido
	 */
	public void setNumero(int numero) {
		Numero = numero;
	}
	/**
	 * 
	 * @return Numero do partido
	 */
	public int getNumero() {
		return Numero;
	}
	/**
	 * @return Numero-Nome partido
	 */
	public String toString(){
		return Numero+"-"+Nome;	
	}
	
}
