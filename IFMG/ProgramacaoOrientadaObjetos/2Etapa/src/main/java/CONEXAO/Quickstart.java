package CONEXAO;
import com.google.api.client.auth.oauth2.Credential;
import com.google.api.client.extensions.java6.auth.oauth2.AuthorizationCodeInstalledApp;
import com.google.api.client.extensions.jetty.auth.oauth2.LocalServerReceiver;
import com.google.api.client.googleapis.auth.oauth2.GoogleAuthorizationCodeFlow;
import com.google.api.client.googleapis.auth.oauth2.GoogleClientSecrets;
import com.google.api.client.googleapis.javanet.GoogleNetHttpTransport;
import com.google.api.client.http.FileContent;
import com.google.api.client.http.javanet.NetHttpTransport;
import com.google.api.client.json.JsonFactory;
import com.google.api.client.json.jackson2.JacksonFactory;
import com.google.api.client.util.store.FileDataStoreFactory;
import com.google.api.services.drive.Drive;
import com.google.api.services.drive.DriveScopes;
import com.google.api.services.drive.model.File;
import com.google.api.services.drive.model.FileList;
import java.io.ByteArrayOutputStream;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.security.GeneralSecurityException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Quickstart {
    private static final String APPLICATION_NAME = "Google Drive API Java Quickstart";
    private static final JsonFactory JSON_FACTORY = JacksonFactory.getDefaultInstance();
    private static final String TOKENS_DIRECTORY_PATH = "tokens";

    /**
     * Global instance of the scopes required by this quickstart.
     * If modifying these scopes, delete your previously saved tokens/ folder.
     */
    private static final List<String> SCOPES = new ArrayList<>(DriveScopes.all());
    private static final String CREDENTIALS_FILE_PATH = "/credentials.json";

    /**
     * Creates an authorized Credential object.
     * @param HTTP_TRANSPORT The network HTTP Transport.
     * @return An authorized Credential object. 
     * @throws IOException If the credentials.json file cannot be found. ...
     */
    private static Credential getCredentials(final NetHttpTransport HTTP_TRANSPORT) throws IOException {
        // Load client secrets.
        InputStream in = Quickstart.class.getResourceAsStream(CREDENTIALS_FILE_PATH);
        GoogleClientSecrets clientSecrets = GoogleClientSecrets.load(JSON_FACTORY, new InputStreamReader(in));

        // Build flow and trigger user authorization request.
        GoogleAuthorizationCodeFlow flow = new GoogleAuthorizationCodeFlow.Builder(
                HTTP_TRANSPORT, JSON_FACTORY, clientSecrets, SCOPES)
                .setDataStoreFactory(new FileDataStoreFactory(new java.io.File(TOKENS_DIRECTORY_PATH)))
                .setAccessType("offline")
                .build();
        return new AuthorizationCodeInstalledApp(flow, new LocalServerReceiver()).authorize("user");
    }
    
    /**
     * 
     * @param service Conexao
     * @param fileID Id do arquivo
     * @return String com conteudo do arquivo
     */
    public String read(Drive service,String fileID){
        String fileId = fileID;
        OutputStream outputStream = new ByteArrayOutputStream();
        try {
            service.files().get(fileId)
                    .executeMediaAndDownloadTo(outputStream);
        } catch (IOException ex) {
            Logger.getLogger(Quickstart.class.getName()).log(Level.SEVERE, null, ex);
        }
        return outputStream.toString();
    }
    /**
     * 
     * @param service Conexao
     * @param name Nome do Arquivo
     * @return Id do Arquivo
     */
    public String idFile(Drive service,String name){
       
        try {
            // Print the names and IDs for up to 10 files.
            FileList result = service.files().list()
                    .setPageSize(10)
                    .setFields("nextPageToken, files(id, name)")
                    .execute();
            List<File> files = result.getFiles();
            if (files == null || files.isEmpty()) {
                System.out.println("No files found.");
            } else {
                for (File file : files) {
                    //System.out.println(file.getName());
                    if(file.getName().equals(name)){
                        System.out.printf("%s (%s)\n", file.getName(), file.getId());
                        return file.getId();
                    }
                }
            }
            return null;
        } catch (IOException ex) {
            Logger.getLogger(Quickstart.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }
    
    /**
     * 
     * @return Conexao
     * @throws GeneralSecurityException ...
     * @throws IOException ...
     */
   public Drive Conexao() throws GeneralSecurityException, IOException{
        final NetHttpTransport HTTP_TRANSPORT = GoogleNetHttpTransport.newTrustedTransport();
        Drive service = new Drive.Builder(HTTP_TRANSPORT, JSON_FACTORY, getCredentials(HTTP_TRANSPORT))
                .setApplicationName(APPLICATION_NAME)
                .build();
        return service;
   }   
  /**
   * 
   * @param service Conexão com Drive
   * @param Arquivo Nome do Arquivo
   * @param Caminho Local do Arquivo
   */
   public void Upload(Drive service,String Arquivo,String Caminho){
        File arquivo = new File();
        arquivo.setName(Arquivo);
        java.io.File caminhoArquivo = new java.io.File(Caminho);
        FileContent conteudoArquivo = new FileContent("file/json", caminhoArquivo);
        try {
            File file = service.files().create(arquivo, conteudoArquivo)
                    .setFields("id")
                    .setFields("name")
                    .execute();
        } catch (IOException ex) {
            ex.getMessage();
        }

    }
   
   
   
   
   /**
    *  * Excluir permanentemente um arquivo, ignorando a lixeira.
    * @param service Drive instância do serviço da API.
    * @param Nome Nome do arquivo no Drive
    * @throws IOException ...
    */
    public void Delete(Drive service,String Nome) throws IOException{
        try {
            service.files().delete(this.idFile(service, Nome)).execute();
        } catch (Exception e) {
            System.out.println("Não foi posivel apagar o arquivo "+Nome);
        }
        
   }
}
