package DAO;

import CONEXAO.*;
import MODELO.Partido;
import MODELO.Candidato;
import MODELO.Documentos;
import JSON.JSONArray;
import JSON.JSONObject;
import com.google.api.services.drive.Drive;
import javax.swing.JOptionPane;


/**Classe para objetos do tipo CandidatoDAO, onde armazena um vetor 'this.Array' com n Candidatos
 * @author Lucas Mateus Fernandes
 */

public class CandidatoDAO extends DAO{
	private final int TAMANHO = 50;
	private int Total = 0;
	private Candidato[] Array = new Candidato[TAMANHO];
	private Candidato celulaVetor = null;
	
	/**Conexao com Google drive*/
	public void Receive() {                
		//String json ="{\"Candidato\":[{\"Numero\":\"11111\",\"NumeroPartido\":\"21\",\"Cpf\":\"066.809.236-03\",\"Nome\":\"Nome1\",\"NomePartido\":\"s1\"},{\"Numero\":\"12345\",\"NumeroPartido\":\"22\",\"Cpf\":\"066.809.236-03\",\"Nome\":\"Nome2\",\"NomePartido\":\"s2\"},{\"Numero\":\"00000\",\"NumeroPartido\":\"23\",\"Cpf\":\"066.809.236-03\",\"Nome\":\"Nome3\",\"NomePartido\":\"s3\"}]}";
                String  json=DownloadJson();
                
                ReadJson(json);
	}
	
	/**Le o Json
	 * @param Sjson - String com Json
	 */
	public void ReadJson(String Sjson) {
            //Cria um Objeto Json com a String passada como parametro
            JSONObject json=new JSONObject(Sjson);
	
            //Quebra o Json no Vetor
            JSONArray jsonCandidatos = json.getJSONArray("Candidato");
	
            //Le o json  Candidato por Candidato
            for (int i = 0; i < jsonCandidatos.length(); i++) {
                //recupera candidato de índice "i" no array 
                JSONObject c = jsonCandidatos.getJSONObject(i);
                
                //Adiciona ao Vetor
                this.CriarCandidato(c.getString("Nome"), c.getString("Numero"),c.getString("Cpf"),c.getString("NumeroPartido"),c.getString("NomePartido"));
            }
		
		
	}
	/**Cria o Json
	 * @return String - contendo o Json de "this.Array"
	 */
	public String makeJson() {
		JSONObject json=new JSONObject();//Superior
		JSONArray candidatos=new JSONArray();
		JSONObject[] candidato=new JSONObject[Total];//Superior
		for (int i = 0; i < Total; i++) {
			//Cria Objetos Json
			candidato[i]=new JSONObject();
			candidato[i].put("Nome",Array[i].getNome());
			candidato[i].put("Numero",""+Array[i].getNumero());//Transformando o int em string
			candidato[i].put("Cpf",Array[i].getCpf());
			candidato[i].put("NomePartido",Array[i].getPartido().getNome());
			candidato[i].put("NumeroPartido",""+Array[i].getPartido().getNumero());//Transformando o int em string
			//Adicionao Objeto Json em um vetor de Jsons
			candidatos.put(candidato[i]);
		}
		json.put("Candidato",candidatos);
		return json.toString();
	}
	/**Cria Candidato e insere em 'this.array'
	 * @param Nome - Nome Candidato
	 * @param Numero - Numero Candidato
	 * @param Cpf - Cpf do Candidato 
	 * @param NumeroPartido - Numero do Partido
	 * @param NomePartido - Nome do Partido
	 * @return Boolean - Confirmando se criou ou nao o candidato
	 * */
        
	public boolean CriarCandidato(String Nome, String Numero, String Cpf, String NumeroPartido,String NomePartido) {
		if (Total < TAMANHO) {//Evita estourar Array
			this.celulaVetor = new Candidato(Nome, Numero, Cpf,NumeroPartido , NomePartido);
			if (celulaVetor != null) {//Evita "lixo" no array
				Array[Total] = this.celulaVetor;
				Total++;
				return true;
			}
		}
		return false;
	}
	public boolean CriarCandidato(String Nome, String Numero, String Cpf, Partido Partido) {
		if (Total < TAMANHO) {//Evita estourar Array
			this.celulaVetor = new Candidato(Nome, Numero, Cpf,Partido);
			if (celulaVetor != null) {//Evita "lixo" no array
				Array[Total] = this.celulaVetor;
				Total++;
				return true;
			}
		}
		return false;
	}
	/**Cria Candidato e insere em 'this.array'
	 * @param candidato - Objeto candidato
	 * @return Boolean -  Confirma se inseriu ou nao o candidato em this this.array
	 */
	public boolean CriarCandidato(Candidato candidato) {
		if (Total <= TAMANHO && candidato != null) {//Evita estourar Array e "lixo" no array
			this.celulaVetor = candidato;
			Array[Total] = this.celulaVetor;
			Total++;
			return true;
		}
		return false;

	}
	/**Para futuras implementações
	 * @param candidato - Objeto candidato
	 */
	public void DeletaCandidato(Candidato candidato) {
		if(candidato ==null) {//evita erro
			return;
		}
		if (Total != 0) {
			for (int i = 0; i < Total; i++) {
				if (Array[i] == candidato) {
					Array[i] = null;
					Array[i] = Array[Total];
					Array[Total] = null;
					Total--;
					return;
				}
			}
		}

	}
	
	/**Numero de pessoas que possui o cpf 'x' em 'this.array'
	 * @param cpf - Cpf do candidato
	 * @return int - Numero de pessoas com cpf 'x'
	 */
	public int intCCPF(String cpf) {
		int contador=0;
		for (int i = 0; i < Total; i++) {
			if(Array[i]!=null) {
				if (Array[i].getCpf().equals(cpf)) {
					contador++;
				}
			}
		}
		return contador;// Não achou
	}
	
	/**Procura e retorna a pessoas que possui o numero 'x' em 'this.array'
	 * @param numero - Numero do candidato
	 * @return Candidato - Retorono o Objeto Candidato presente em this.array que possui o numero x
	 */
	public Candidato ObjectNumero(String numero) {
		int num=Integer.parseInt(numero);
		for (int i = 0; i < Total; i++) {
			if(Array[i]!=null) {
				if (Array[i].getNumero() == num) {
					return Array[i];// Retorna o candidato com Numero procurado
				}
			}
		}
		return null;// Não achou

	}
	/**Numero de pessoas que possui o cpf 'x' em 'this.array'
	 * @param cpf - cpf do candidato
	 * @return Candidato - Retorono o Objeto Candidato presente em this.array que possui o numero x
	 */
	public Candidato ObjectCpf(String cpf) {
		Documentos doc = new Documentos(cpf);

		if (!doc.validaCpf(cpf)) {// é um cpf valido?
			return null;
		}
		cpf = doc.toString();// pega o sem pontuação pois em candidato fica salvo o sem pontuação

		for (int i = 0; i < Total; i++) {
			if(Array[i]!=null) {
				if (Array[i].getCpf().equals(cpf)) {
					return Array[i];// Retorna o candidato com Numero procurado
				}
			}
		}
		return null;// Não achou

	}
        public int getTotal(){
            return Total;
        }
        public Candidato CandidatoIndice(int i){
            return Array[i];
        }  
        
        
        
}
