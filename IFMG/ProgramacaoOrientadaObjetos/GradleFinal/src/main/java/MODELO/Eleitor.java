package MODELO;
import java.io.IOException;
import java.security.NoSuchAlgorithmException;
/**Classe que faz tratamento do cpf
 *private String Nome
 *private Documentos Cpf
 *private String TituloEleitor
 *private int UrnaVotacao
 *private Senha ImagemSenha	
 * @author Lucas Mateus Fernandes
 */
public class Eleitor {
	private String Nome;
	private Documentos Cpf;
	private String TituloEleitor;
	private int UrnaVotacao;
	private Senha ImagemSenha;
	
	/** @param tituloEleitor -String com numero do titulo de eleitor
	 */
	public void setTituloEleitor(String tituloEleitor) {
		TituloEleitor = tituloEleitor;
	}
	
	
	/** @return Numero do titulo de eleitor
	 */
	public String getTituloEleitor() {
		return TituloEleitor;
	}
	
	
	/** @param nome Nome do eleitor
	 */
	public void setNome(String nome) {
		Nome = nome;
	}
	
	
	/** @return Nome do eleitor
	 */
	public String getNome() {
		return Nome;
	}
	
	
	/** @return Cpf
	 */
	public String getCpfString() {
		return Cpf.toString();
	}
	
	
	/** @return Object Documents com cpf ja setado
	 */
	public Documentos getCpf() {
		return Cpf;
	}
	
	
	/** So muda o cpf se ele for valido
	 * @param cpf String Cpf
	 */
	public void setCpf(String cpf) {
		Documentos doc=new Documentos();
		if(doc.validaCpf(cpf)) {
			this.Cpf = doc;
		}else {
			System.out.println("Cpf Invalido");
		}
	}
	
	
	/** 
	 * @param urnaVotacao - A urna em que o eleitor vai votar
	 */
	public void setUrnaVotacao(int urnaVotacao) {
		UrnaVotacao = urnaVotacao;
	}
	
	
	/**
	 * @return Numero da urna que o eleitor vota 
	 */
	public int getUrnaVotacao() {
		return UrnaVotacao;
	}
	
	
	/**
         * Cria uma senha hash apartir da imagem do eleitor
	 * @param Path - Caminho do arquivo que contem a imagem 
         * @throws java.security.NoSuchAlgorithmException  ...
         * @throws java.io.IOException  ...
         */
	public void setImagemSenha(String Path) throws NoSuchAlgorithmException, IOException {//Passa o caminho do arquivo
		System.out.println("Carregando Nova Imagem/Senhha");
		this.ImagemSenha = new Senha(Path);
		
	}
	
	
	/** 
	 * @return Retorna hash da senha
	 */
	public String getHash() {//Retorna o Hash da senha
		return ImagemSenha.getHash();
	}
	
	
	/** 
         * 
	 * Usar na Central
	 * Passa a imagem e seta a hash automaticamente
	 * @param ImagemSenha Local da imagem
         * @param TituloEleitor Titulo de Eleitor
         * @param Nome Nome Eleitor
         * @param Cpf String com Cpf foramtado ou não
         * @param UrnaVotacao Numero da Urna em que o Eleitor Vota
         * @throws NoSuchAlgorithmException ...
         * @throws IOException ....
         */
	public Eleitor(String TituloEleitor,String Nome, String Cpf,int UrnaVotacao,String ImagemSenha) throws NoSuchAlgorithmException, IOException {
		System.out.println("Criando Novo Eleitor");
		this.TituloEleitor=TituloEleitor;
		this.Nome=Nome;
		this.Cpf=new Documentos(Cpf);
		this.UrnaVotacao=UrnaVotacao;
		this.ImagemSenha=new Senha(ImagemSenha);
		
	}
	/**
	 * Usar na Urna
	 * Seta a hash que ativa a flag de inconsistencia
	 * @param Hash String contendo a Hash (que vai ser lido do json
         * @param TituloEleitor Titulo de Eleitor
         * @param Nome Nome Eleitor
         * @param Cpf String com Cpf foramtado ou não
         * @param UrnaVotacao Numero da Urna em que o Eleitor Vota
         * @throws NoSuchAlgorithmException ...
         * @throws IOException ...
         */
	public Eleitor(String TituloEleitor,String Nome, String Cpf,String UrnaVotacao,String Hash) throws NoSuchAlgorithmException, IOException {////Import do Json
		Documentos cpf=new Documentos(Cpf);
		if (cpf.getValidCpf()) {		
			this.TituloEleitor=TituloEleitor;
			this.Nome=Nome;
			this.Cpf=cpf;
			this.UrnaVotacao=Integer.parseInt(UrnaVotacao);
			this.ImagemSenha=new Senha("INCONSISTENTE",Hash);//So será permitido setar o Hash por conta do Json
		}
	}
	public Eleitor() {
		// TODO Auto-generated constructor stub
	}
	
	
}
