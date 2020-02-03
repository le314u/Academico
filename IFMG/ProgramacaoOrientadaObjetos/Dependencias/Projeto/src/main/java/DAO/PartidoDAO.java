package DAO;

import MODELO.Partido;
import java.io.IOException;
import java.security.NoSuchAlgorithmException;

import JSON.JSONArray;
import JSON.JSONException;
import JSON.JSONObject;
import java.util.ArrayList;
import java.util.List;

/**Classe para objetos do tipo Partido, onde armazena um vetor 'this.Array' com n Partidos
 * @author Lucas Mateus Fernandes
 */
public class PartidoDAO extends DAO {
	private final int TAMANHO = 50;
	public int Total = 0;
        private List<Partido> Array = new ArrayList<Partido>();
	private Partido celulaVetor = null;

	/**Conexao com Google drive*/
	public void Receive() {
                String  json=DownloadJson();
		try {
			ReadJson(json);
		} catch (NoSuchAlgorithmException | JSONException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	/**Le o Json
	 * @param Sjson - Json
         * @throws NoSuchAlgorithmException ...
         * @throws JSONException ....
         * @throws IOException ....
         */
	public void ReadJson(String Sjson) throws NoSuchAlgorithmException, JSONException, IOException {//Acho que não precisa mas é para futuras Modificações
		//Cria um Objeto Json com a String passada como parametro
		JSONObject json=new JSONObject(Sjson);
		
		//Quebra o Json no Vetor
		JSONArray jsonPartido = json.getJSONArray("Partido");
		
		//Le o json  Candidato por Candidato
		for (int i = 0; i < jsonPartido.length(); i++) {
			//recupera candidato de índice "i" no array 
            JSONObject p = jsonPartido.getJSONObject(i);
			//Adiciona ao Vetor
            this.CriarPartido(p.getString("Numero"),p.getString("Nome"));
			
		}
	}
	
	/**Cria o Json
	 * @return String - contendo o Json de "this.Array"
	 * */
	public String makeJson() {
		JSONObject json=new JSONObject();//Superior
		JSONArray partidos=new JSONArray();
		JSONObject[] partido=new JSONObject[Total];//Superior
		for (int i = 0; i < Total; i++) {
			//Instancia o Objcte
			partido[i]=new JSONObject();
			//Cria Objetos Json
			partido[i].put("Nome", Array.get(i).getNome());
			partido[i].put("Numero",""+Array.get(i).getNumero());
			//Adicionao Objeto Json em um vetor de Jsons
			partidos.put(partido[i]);
		}
		json.put("Partido",partidos);
		return json.toString();
	}
	
	/**Cria o Partido e o insere em 'this.array' 
	 * @param Numero - Numero do Partido
	 * @param Nome - Nome do partido
	 * @return Boolean - Confirmando se criou ou nao o partido
	 * */
	public boolean CriarPartido(String Numero, String Nome) {
		if (Total <= TAMANHO) {//Evita estourar Array
			this.celulaVetor = new Partido(Numero, Nome ) ;
                        System.out.println("OK");
			if (celulaVetor != null) {//Evita "lixo" no array
                            Array.add(this.celulaVetor);
                            //Array.set(++Total, this.celulaVetor);
                            Total++;
                            return true;
			}
		}
		return false;

	}
	/**Cria Eleitor e insere em 'this.array'
	 * @param partido - Objeto Partido
	 * @return Boolean -  Confirma se inseriu ou nao o partido em this this.array
	 */
	public boolean CriarPartido(Partido partido) {
		if (Total <= TAMANHO && partido != null) {//Evita estourar Array e "lixo" no array
			this.celulaVetor = partido;
			Array.add(this.celulaVetor);
                        //Array.set(++Total, this.celulaVetor);
                        Total++;
			return true;
		}
		return false;

	}
	
	/**Procura e retorna a partido que possui o numero 'x' em 'this.array'
	 * @param numero - Numero do partido
	 * @return Partido - Retorona o Objeto partido presente em this.array que possui o numero 'x'
	 */
	public Partido ObjectNumero(int numero) {
		for (int i = 0; i < Total; i++) {
			if(Array.get(i)!=null) {
				if (Array.get(i).getNumero() == numero) {
					return Array.get(i);// Retorna o candidato com Numero procurado
				}
			}
		}
		return null;// Não achou

	}

	/**Procura e retorna a partido que possui o nome 'x' em 'this.array'
	 * @param nome - Nome do partido
	 * @return Partido - Retorona o Objeto partido presente em this.array que possui o nome 'x'
	 */
	public Partido ObjectNome(String nome) {
		for (int i = 0; i < Total; i++) {
			if(Array.get(i)!=null) {
                            if (Array.get(i).getNome().equals(nome)) {
				return Array.get(i);// Retorna o candidato com Numero procurado
                            }
			}
		}
		return null;// Não achou
	}
	
}
