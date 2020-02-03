package DAO;

import MODELO.Eleitor;
import java.io.IOException;
import java.security.NoSuchAlgorithmException;

import JSON.JSONArray;
import JSON.JSONException;
import JSON.JSONObject;


/**Classe para objetos do tipo Eleitor, onde armazena um vetor 'this.Array' com n Eleitores
 * @author Lucas Mateus Fernandes
 */
public class EleitorDAO extends DAO{
	
	private final int TAMANHO = 50;
	private int Total = 0;
	public Eleitor[] Array = new Eleitor[TAMANHO];
	private Eleitor celulaVetor = null;

	/**Conexao com Google drive*/
        @Override
	public void Receive() {
		//String json="{\"Eleitor\":[{\"UrnaVotacao\":\"1\",\"Senha\":\"956eee1761b6224b512dcb6491c0355dfe2dad05d242e5f70f97651b3d6674f3\",\"Cpf\":\"066.809.236-03\",\"TituloEleitor\":\"Titulo1\",\"Nome\":\"Nome1\"},{\"UrnaVotacao\":\"2\",\"Senha\":\"6194d7c363019ffff907f3cd33f214980106ccfdd03871defa9e6f726bfa7211\",\"Cpf\":\"066.809.236-03\",\"TituloEleitor\":\"Titulo2\",\"Nome\":\"Nome2\"}]}";
                String  json=DownloadJson();
		try {
			ReadJson(json);
		} catch (NoSuchAlgorithmException | JSONException | IOException e) {
                    // TODO Auto-generated catch block

		}
	}
	
	

         /**Le o Json
	 * @param Sjson - Json 
         * @throws NoSuchAlgorithmException ...
         * @throws JSONException ...
         * @throws IOException ...
         */
	public void ReadJson(String Sjson) throws NoSuchAlgorithmException, JSONException, IOException {
		//Cria um Objeto Json com a String passada como parametro
		JSONObject json=new JSONObject(Sjson);
		
		//Quebra o Json no Vetor
		JSONArray jsonEleitor = json.getJSONArray("Eleitor");
		
		//Le o json  Candidato por Candidato
		for (int i = 0; i < jsonEleitor.length(); i++) {
			//recupera candidato de índice "i" no array 
            JSONObject e = jsonEleitor.getJSONObject(i);
			//Adiciona ao Vetor
            this.CriarEleitor(e.getString("TituloEleitor"), e.getString("Nome"),e.getString("Cpf"),e.getString("UrnaVotacao"),e.getString("Senha"));
			
		}
	}
	/**Cria o Json
	 * @return String - contendo o Json de "this.Array"
	 * */
	public String makeJson() {
		JSONObject json=new JSONObject();//Superior
		JSONArray eleitores=new JSONArray();
		JSONObject[] eleitor=new JSONObject[Total];
		for (int i = 0; i < Total; i++) {
			
			//Cria Objetos Json
			eleitor[i]=new JSONObject();
			eleitor[i].put("UrnaVotacao",""+Array[i].getUrnaVotacao());
			eleitor[i].put("Senha", Array[i].getHash());
			eleitor[i].put("Cpf", Array[i].getCpfString());
			eleitor[i].put("TituloEleitor", Array[i].getTituloEleitor());
			eleitor[i].put("Nome", Array[i].getNome());
			//Adicionao Objeto Json em um vetor de Jsons
			eleitores.put(eleitor[i]);
		}
		json.put("Eleitor",eleitores);
		return json.toString();
	}
	
	/**Cria EleitorS e insere em 'this.array' Porem a senha é setada na mão
	 * @param TituloEleitor -Titulo Eleitor 
	 * @param Nome - Nome Eleitor
	 * @param Cpf - Cpf do Eleitor 11 digitos
	 * @param UrnaVotacao - Numero da urna de votação
	 * @param Senha - Senha Hash do  do eleitor
	 * @return Boolean - Confirmando se criou ou nao o eleitor
         * @throws java.security.NoSuchAlgorithmException ...
        * @throws java.io.IOException ...
	*/
	public boolean CriarEleitor(String TituloEleitor, String Nome, String Cpf, String UrnaVotacao, String Senha) throws NoSuchAlgorithmException, IOException {
		if (Total <= TAMANHO) {// Evita estourar Array
			this.celulaVetor = new Eleitor(TituloEleitor, Nome, Cpf, UrnaVotacao, Senha);
			if (celulaVetor != null) {// Evita "lixo" no array
				Array[Total] = this.celulaVetor;
				Total++;
				return true;
			}
		}
		return false;

	}

	
        /**Cria Eleitor e insere em 'this.array' Porem a senha é gerada apartir do path
	  * @param TituloEleitor -Titulo Eleitor 
	 * @param Nome - Nome Eleitor
	 * @param Cpf - Cpf do Eleitor 11 digitos
	 * @param UrnaVotacao - Numero da urna de votação
	 * @param Path - Caminha da imagem que vai gerar a hash
	 * @return Boolean - Confirmando se criou ou nao o eleitor
         * @throws NoSuchAlgorithmException ...
         * @throws IOException ...
         */
	public boolean CriarEleitor(String TituloEleitor, String Nome, String Cpf, int UrnaVotacao, String Path) throws NoSuchAlgorithmException, IOException {
		if (Total <= TAMANHO) {// Evita estourar Array
			this.celulaVetor = new Eleitor(TituloEleitor, Nome, Cpf, UrnaVotacao, Path);
			if (celulaVetor != null) {// Evita "lixo" no array
				Array[Total] = this.celulaVetor;
				Total++;
				return true;
			}
		}
		return false;

	}
	/**Cria Eleitor e insere em 'this.array'
	 * @param eleitor - Objeto eleitor
	 * @return Boolean - Confirma se inseriu ou nao o eleitor em this this.array
	 */
	public boolean CriarEleitor(Eleitor eleitor) {
		if (Total <= TAMANHO && eleitor != null) {// Evita estourar Array e "lixo" no array
			this.celulaVetor = eleitor;
			Array[Total] = this.celulaVetor;
			Total++;
			return true;
		}
		return false;

	}
	/**Deleta Eleitor de 'this.array'
	 * @param eleitor - Objeto eleitor
	 */ 
	public void DeletaEleitor(Eleitor eleitor) {
		if(eleitor==null) {//Evita erro 
			return;
		}
		if (Total != 0) {
			for (int i = 0; i < Total; i++) {
				if(Array[i]!=null) {
					if (Array[i] == eleitor) {
						Array[i] = null;
						Array[i] = Array[Total];
						Array[Total] = null;
						Total--;
						return;
					}
				}
			}
		}

	}

	/**Procura e retorna a pessoas que possui o titulo 'x' em 'this.array'
	 * @param titulo - Titulo de eleitor
	 * @return Eleitor - Retorono o Objeto eleitor presente em this.array que possui o titulo 'x'
	 */
	public Eleitor ObjectTitulo(String titulo) {
		for (int i = 0; i < Total; i++) {
			if(Array[i]!=null) {
				if (Array[i].getTituloEleitor().equals(titulo)) {
					return Array[i];// Retorna o eleitor com Numero Titulo de eleitor procurado
				}
			}
		}
		return null;// Não achou

	}
	/**Retorna a pessoa que possui o cpf 'x' em 'this.array'
	 * @param cpf - Numero do eleitor
	 * @return Eleitor - Retorona o Objeto Eleitor presente em this.array que possui o cpf x
	 */
	public Eleitor ObjectCpf(String cpf) {
		for (int i = 0; i < Total; i++) {
			if(Array[i]!=null) {
				if (Array[i].getCpf().equals(cpf)) {
					return Array[i];// Retorna o eleitor com cpf procurado
				}
			}
		}
		return null;// Não achou
	}
	/**Retorna a pessoa que possui presente em 'this.array' que possui a senha hash 'x'
	 * @param hash - Senha Hash do eleitor
	 * @return Eleitor - Retorona o Objeto Eleitor presente em this.array que possui a senha hash x
	 */
	public Eleitor ObjectHash(String hash) {//SeRetorna algo diferente de null é pq Senha deu Match
		for (int i = 0; i < Total; i++) {
			if(Array[i]!=null) {
				if (Array[i].getHash().equals(hash)) {
					return Array[i];// Retorna o eleitor com cpf procurado
				}
			}
		}
		return null;// Não achou
	}
	

        public int getTotal(){
            return Total;
        }
}
