package DAO;

import CONEXAO.Quickstart;
import JSON.JSONArray;
import JSON.JSONObject;
import com.google.api.services.drive.Drive;
import java.io.IOException;
import java.security.GeneralSecurityException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Pega o Cnteudo Json do arquivo no google drive
 * @author lucas
 *
 */
public abstract class DAO {
	private CandidatoDAO cDAO=null;
	private EleitorDAO eDAO=null;
	private PartidoDAO pDAO=null;
	private VotoDAO vDAO=null;
	
	
        public String DownloadJson(){
            String NomeArquivo="Eleicao.json";
            Quickstart drive = new Quickstart();
            Drive conexao;
            try {
                conexao = drive.Conexao();
            } catch (GeneralSecurityException ex) {
               return null;
            } catch (IOException ex) {
               return null;
            }
            String idArq = drive.idFile(conexao,NomeArquivo);
            String jSon=drive.read(conexao,idArq);
            return jSon;
        }
        /**
         * Cada DAO tem o seu receive
         */
        abstract void Receive();
}
