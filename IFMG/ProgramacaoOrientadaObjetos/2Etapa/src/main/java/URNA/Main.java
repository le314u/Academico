package URNA;
import java.io.IOException;
import java.security.NoSuchAlgorithmException;
import VISAO.TelaLogin;


public class Main {

	public static void main(String[] args) throws NoSuchAlgorithmException, IOException {
		System.out.println("Start");
		//Criando Strutura para armazenamento do voto
		Urna instancia=new Urna();
                
		//Cria tela de Login
                TelaLogin ins=new TelaLogin(instancia);
               
                
                while(true){
                    if(ins!=null){
                        if(ins.getUser()==null && ins.getTelaVisivel()==false && ins.getLogado()==false){
                            System.out.println("Esperando Login");
                            ins=null;
                            ins=new TelaLogin(instancia);
                        }
                    }else{
                        System.out.println("Esperando Login");
                        ins=new TelaLogin(instancia);
                    }
                }
	}
}

