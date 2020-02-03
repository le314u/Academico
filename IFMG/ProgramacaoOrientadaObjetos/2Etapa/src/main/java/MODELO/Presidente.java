/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package MODELO;

/**
 *
 * @author lucas
 */
public class Presidente extends Candidato {

   
    public Presidente(String Nome, String Numero, String Cpf, String NumeroPartido, String NomePartido,String Sigla) throws Throwable{
        //Chama o construtor do pai
        super(Nome,Numero,Cpf,NumeroPartido,NomePartido);
        //Se o Cpf foi valido continua fazendo o Deputado
        
        if(!(this.getNome()== null ||this.getNome().equals("") ||this.getNome().equals(" "))){
            if(! Sigla.equals(Estados.BR.getSigla())){
                this.finalize();
            }else{
                this.setSigla( Estados.BR.getSigla());
            }
        }
        
    }
    public Presidente(String Nome, String Numero, String Cpf, String NumeroPartido, String NomePartido,int Cod) throws Throwable{
        //Chama o construtor do pai
        super(Nome,Numero,Cpf,NumeroPartido,NomePartido);
        //Se o Cpf foi valido continua fazendo o Deputado
        if(!(this.getNome()== null ||this.getNome().equals("") ||this.getNome().equals(" "))){
            if(Cod != Estados.BR.getCod()){
                this.finalize();
            }else{
                this.setSigla( Estados.BR.getSigla());
            }
        }
        
    }



    public Presidente(String Nome, String Numero, String Cpf, Partido Partido,int Cod) throws Throwable {// Import do
         //Chama o construtor do pai
        super( Nome,  Numero,  Cpf, Partido);
        //Se o Cpf foi valido continua fazendo o Deputado
        if(!(this.getNome()== null ||this.getNome().equals("") ||this.getNome().equals(" "))){
            if(Cod != Estados.BR.getCod()){
                this.finalize();
            }else{
                this.setSigla( Estados.BR.getSigla());
            }
        }
    }
    
    
    public Presidente(String Nome, String Numero, String Cpf,Partido Partido,String Sigla) throws Throwable{
        //Chama o construtor do pai
        super( Nome,  Numero,  Cpf, Partido);
        //Se o Cpf foi valido continua fazendo o Deputado
        if(!(this.getNome()== null ||this.getNome().equals("") ||this.getNome().equals(" "))){
            if(! Sigla.equals(Estados.BR.getSigla())){
                this.finalize();
            }else{
                this.setSigla( Estados.BR.getSigla());
            }
        }   
        
    }
  
}
