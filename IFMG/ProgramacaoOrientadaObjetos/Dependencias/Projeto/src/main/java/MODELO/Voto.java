package MODELO;
import java.util.Date;
/**
 *private Eleitor eleitor 
 *private Candidato candidato
 *private Date data
 *private int NumeroUrna
 * @author lucas
 *
 */
public class Voto {
	private Eleitor eleitor;
	private Candidato candidato;
	private Date data;
	private int NumeroUrna;

	/**
	 * 
	 * @return Object Eleitor
	 */
	public Eleitor getEleitor() {
		return eleitor;
	}
	/**
	 * @return Cpf do Eleitor
	 */
	public String getECPF() {
		return eleitor.getCpfString();
	}
	/**
	 * 
	 * @return Object Candidato
	 */
	public Candidato getCandidato() {
		return candidato;
	}
       
	/**
	 * 
	 * @return Cpf do Candidato
	 */
	public String getCCPF() {
		return candidato.getCpfString();
	}
	/**
	 * @return Long (parametro do date)
	 */
	public long getTime() {
		return data.getTime();
	}
	/**
	 * 
	 * @return Object Date
	 */
	public Date getData() {
		return data;
	}
	/**
	 * 
	 * @return Numero da Urna
	 */
	public int getNumeroUrna() {
		return NumeroUrna;
	}
	/**
	 * 
	 * @param numeroUrna Numero da urna
	 */
	public void setNumeroUrna(int numeroUrna) {
		NumeroUrna = numeroUrna;
	}
	
	public Voto(Eleitor eleitor,Candidato candidato,int NumeroUrna) {
                if(candidato==null){
                    this.candidato=new Candidato("Nulo", "00000", "00000000000","0", "Nulo");
                }else{
                    this.candidato=candidato;
                }
                this.eleitor=eleitor;
		this.NumeroUrna=NumeroUrna;
		data=new Date();
	}
	public Voto(Eleitor eleitor,Candidato candidato,int NumeroUrna,long time) {
		this.eleitor=eleitor;
		this.candidato=candidato;
		this.NumeroUrna=NumeroUrna;
		data=new Date(time);
	}
	public Voto(String eleitorCpf,String candidatoCpf,String NumeroUrna){//import Json
		System.out.println("Criando Voto");
		this.eleitor=eleitor;//Depois tem que procura o eleitor por cpf
		this.candidato=candidato;//Procura o candidato por cpf
		this.NumeroUrna=Integer.parseInt(NumeroUrna);
		data=new Date();
	}
	public Voto(String eleitorCpf,String candidatoCpf,String NumeroUrna,String Data){//import Json
		this.eleitor=eleitor;//Depois tem que procura o eleitor por cpf
		this.candidato=candidato;//Procura o candidato por cpf
		this.NumeroUrna=Integer.parseInt(NumeroUrna);
		data=new Date(Integer.parseInt(Data));
	}
}
