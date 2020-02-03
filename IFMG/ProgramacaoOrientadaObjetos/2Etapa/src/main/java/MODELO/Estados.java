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
public enum Estados {
  

    BR(0,"Brasil","BR","ALL"), 
    AC(1,"Acre","AC","Norte"),
    AL(2,"Alagoas","AL","Nordeste"),
    AP(3,"Amapá","AP","Norte"),
    AM(4,"Amazonas","AM","Norte"),
    BA(5,"Bahia","BA","Nordeste"),
    CE(6,"Ceará","CE","Nordeste"),
    DF(7,"Distrito Federal","DF","Centro-Oeste"),
    ES(8,"Espírito Santo","ES","Sudeste"),
    GO(9,"Goiás","GO","Centro-Oeste"),
    MA(10,"Maranhão","MA","Nordeste"),
    MT(11,"Mato Grosso","MT","Centro-Oeste"),
    MS(12,"Mato Grosso do Sul","MS","Centro-Oeste"),
    MG(13,"Minas Gerais","MG","Sudeste"),
    PA(14,"Pará","PA","Norte"),
    PB(15,"Paraíba","PB","Nordeste"),
    PR(16,"Paraná","PR","Sul"),
    PE(17,"Pernambuco","PE","Nordeste"),
    PI(18,"Piauí","PI","Nordeste"),
    RJ(19,"Rio de Janeiro","RJ","Sudeste"),
    RN(20,"Rio Grande do Norte","RN","Nordeste"),
    RS(21,"Rio Grande do Sul","RS","Sul"),
    RO(22,"Rondônia","RO","Norte"),
    RR(23,"Roraima","RR","Norte"),
    SC(24,"Santa Catarina","SC","Sul"),
    SP(25,"São Paulo","SP","Sudeste"),
    SE(26,"Sergipe","SE","Nordeste"),
    TO(27,"Tocantins","TO","Norte");
    
    private int Cod;
    private String Estado;
    private String Sigla;
    private String Regiao;
    
    Estados(int Cod,String Estado,String Sigla,String Regiao){
        this.Cod=Cod;
        this.Estado=Estado;
        this.Sigla=Sigla;
        this.Regiao=Regiao;
    }

    public int getCod() {
        return Cod;
    }

    public String getEstado() {
        return Estado;
    }

    public String getSigla() {
        return Sigla;
    }

    public String getRegiao() {
        return Regiao;
    }
    
    public boolean valido(String Singla){
        
        return true;
    }
    
}
