package CENTRAL;

import CONEXAO.Quickstart;
import DAO.*;
import JSON.JSONArray;
import JSON.JSONObject;
import MODELO.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import javax.swing.JOptionPane;

import VISAO.TelaCentral;
import com.google.api.services.drive.Drive;
import java.security.GeneralSecurityException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Central {

    private TelaCentral tela = null;
    private CandidatoDAO cDAO = null;
    private EleitorDAO eDAO = null;
    private PartidoDAO pDAO = null;
    private VotoDAO vDAO = null;
    public int[] nVotos = null;

    /**
     * Inicializa a Central , Carrega os dados Salvos, Inicia a tela;
     *
     */
    public Central() {
        //Inicia Central
        this.cDAO = new CandidatoDAO();
        this.eDAO = new EleitorDAO();
        this.pDAO = new PartidoDAO();
        this.vDAO = new VotoDAO();

        //Carrega Dados Da ultima seção 
        try {
            pDAO.Receive();
            System.out.println("Receive Partido");
            //Partido tem que vir antes de Candidato
            cDAO.Receive();
            System.out.println("Receive Candidatos");
            eDAO.Receive();
            System.out.println("Receive Eleitores");
            vDAO.Receive();//Voto tem que vir depois de eleitor e de candidato
            System.out.println("Receive Votos");
        } catch (Exception e) {
            //ERRO
            JOptionPane.showMessageDialog(null, "Erro Ao Baixar do Drive,Verifique sua Conexão");
        }
        if(cDAO.getTotal()==0){
             nVotos = new int[1];
        }else{
            nVotos = new int[cDAO.getTotal()];
        }
        //Cria com o numero total de candidatos

        //Habilita a Tela
        tela = new TelaCentral(this);
        tela.setVisible(true);

    }

    /**
     * Envia um Arquivo para o google Drive
     * @return Se foi possivel salvar no Drive
     */
    public boolean Send() {
        String Path = "./Eleicao.json";
        String Nome = "Eleicao.json";
        //Salva os Arquivos
        //Cria um arquivo
        FileWriter arq;
        try {
            arq = new FileWriter(Path);
            PrintWriter gravarArq = new PrintWriter(arq);//Objeto buffer

            String Json = makeJson();//Convertendo tudo para string

            gravarArq.printf(Json);
            arq.close();
        } catch (IOException e1) {
            e1.printStackTrace();
            JOptionPane.showInternalMessageDialog(null, "Erro Ao criar Arquivo");
        }

        Quickstart drive = new Quickstart();
        Drive conexao = null;
        try {
            //conecta ao Drive
            conexao = drive.Conexao();
            //Apaga o Arquivo que ja estava no Drive
            drive.Delete(conexao, Nome);
            System.out.println("Apagou Arquivo Anterior");
            //Envia o Arquivopara o Drive
            drive.Upload(conexao, Nome, Path);
            System.out.println("Arquivo Enviado");
            return true;
        } catch (Exception ex) {
            return false;
        }

    }

    /**
     * Retorna uma string {Nome:"Candidato",Eleitor:"NumeroDeVotos"}
     *
     * @return Json com o resultado da votacao
     */
    public String Resultado() {
        CalculaVotos();
        return JsonResultado();

    }

    /**
     *
     * @return Json referente ao resutlado da votação
     */
    private String JsonResultado() {
        JSONObject json = new JSONObject();//Json que vai retornar
        JSONArray resultados = new JSONArray();//de Candidatos/Votos
        JSONObject[] resultado = new JSONObject[cDAO.getTotal()];//Superior
        for (int i = 0; i < cDAO.getTotal(); i++) {//Pega a Quantidade de Votos de cada eleitor
            //Cria Objetos Json
            resultado[i] = new JSONObject();
            resultado[i].put("Sigla", cDAO.CandidatoIndice(i).getSigla());
            resultado[i].put("Nome", cDAO.CandidatoIndice(i).getNome());
            resultado[i].put("Votos", "" + nVotoIndice(i));
            //Adicionao Objeto Json em um vetor de Jsons
            resultados.put(resultado[i]);
        };
        json.put("Resultado", resultados);
        return json.toString();
    }

    /**
     *
     * @param CampoPartido Nome do partido
     * @param CampoNomeCandidato Nome do Candidato
     * @param CampoNumeroCandidato Numero do Candidato
     * @param CampoCPF CPF do candidato
     * @return se foi possivel criar o candidato
     */
    public boolean CadastrarCandidato(String CampoPartido, String CampoNomeCandidato, String CampoNumeroCandidato, String CampoCPF,String CampoSigla) throws Throwable {//Passa os N Campos
        
                            //Verifica sigla
                            boolean presidente=false;
                            try {
                                int cod = Estados.valueOf(CampoSigla).getCod();
                                if(cod == Estados.BR.getCod()){
                                    presidente=true;
                                }
                            } catch (Exception e) {
                                //ERRO SIGLA INVALIDA
                            }
       
        
        //Verificando Nome
        if (CampoNomeCandidato.length() == 0) {
            JOptionPane.showMessageDialog(null, "Nome não pode ser Nulo");
            return false;
        }

        //Verificando Numero
        if (CampoNumeroCandidato.length() != 5) {
            JOptionPane.showMessageDialog(null, "Numero do Candidato deve ter 5 Digitos");
            return false;
        } else {
            int numero = 0;
            try {
                Integer.parseInt(CampoNumeroCandidato);
            } catch (Exception e) {
                JOptionPane.showMessageDialog(null, "5 DIGITOS");
                return false;
            }
            if (cDAO.ObjectNumero(CampoNumeroCandidato) != null) {
                JOptionPane.showMessageDialog(null, CampoNumeroCandidato + " ja foi cadastrado");
                return false;
            }
        }

        //Verificando Cpf
        Documentos doc = new Documentos(CampoCPF);
        if (!doc.getValidCpf()) {
            JOptionPane.showMessageDialog(null, "Cpf Invalido");
            return false;
        } else {
            if (cDAO.ObjectCpf(CampoCPF) != null) {
                JOptionPane.showMessageDialog(null, CampoCPF + " CPF ja foi cadastrado");
                return false;
            }
        }

        //Partido
        Partido partido = null;
        boolean criado = false;//Retorno
        //Procura PARTIDO
        //Procura Partido pelo Nome
        partido = pDAO.ObjectNome(CampoPartido);

        if (partido == null) {//Se Não Achou por Nome  Procura o Partido pelo numero

            //Converte string para numero
            try {
                int numeroPartido = Integer.parseInt(CampoPartido);

                //Procura Partido pelo numero
                partido = pDAO.ObjectNumero(numeroPartido);

            } catch (Exception e) {
                JOptionPane.showMessageDialog(null, "Este partido não existe");
                return false;
            }

            if (partido == null) {//Se não achou por numero o Partido não esta cadastrado
                JOptionPane.showMessageDialog(null, "Partido Invalido");

                return false;
            }
        }

        //Procurar se ja existe algum candidato com mesmo numero
        try {
            criado = cDAO.CriarCandidato(CampoNomeCandidato, CampoNumeroCandidato, CampoCPF, partido,CampoSigla);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Erro ao cadastrar");
        }

        //Conseguiu Criar o Candidato
        if (criado == true) {
            Documentos docs = new Documentos(CampoCPF);
            JOptionPane.showMessageDialog(null, "Cadastrado com sucesso \n"
                    + "\nNome:" + CampoNomeCandidato
                    + "\nNumero:" + CampoNumeroCandidato
                    + "\nCPF:" + docs.toStringPonto()
                    + "\nNome Partido:" + partido.getNome()
                    + "\nNumero Partido:" + partido.getNumero());
            return true;
        }
        return false;
    }

    /**
     *
     * @param CampoNumeroPartido Numero do Partido
     * @param CampoNomePartido Nome do partido
     * @return Se foi possivelcriar o Partido
     */
    public boolean CadastrarPartido(String CampoNumeroPartido, String CampoNomePartido) {
        Partido partido = null;
        boolean verificacao = false;
        int numeroPartido = 0;

        //Procura Partidos pelo Nome
        partido = pDAO.ObjectNome(CampoNomePartido);
        if (partido != null) {//Achou com o mesmo nome
            System.out.println("Existe Partido com este nome");
            return false;
        }

        //Procura Partidos pelo Numero
        try {//Tenta Converter String para numero
            numeroPartido = Integer.parseInt(CampoNumeroPartido);//Verifica se é Numero
        } catch (Exception e) {
            System.out.println("Numero Invalido");
            return false;
        }

        partido = pDAO.ObjectNumero(numeroPartido);
        if (partido != null) {//achou com mesmo numero
            System.out.println("Existe Partido com este numero");
            return false;
        } else {
            verificacao = true;
        }

        //Cria Partido
        if (verificacao) {
            if (pDAO.CriarPartido(CampoNumeroPartido, CampoNomePartido)) {
                JOptionPane.showMessageDialog(null, "Partido Criado com sucesso\n"
                        + "\nNumero:" + CampoNumeroPartido
                        + "\nNome:" + CampoNomePartido);
                return true;
            } else {
                JOptionPane.showMessageDialog(null, "Erro ao criar o Partido");
                return false;
            }
        }
        return verificacao;

    }

    /**
     *
     * @param Path Caminho da Foto
     * @param CampoNome Nome
     * @param CampoTitulo Titulo de Eleitor
     * @param CampoCPF CPF do Eleitor
     * @param CampoUrna Urna de Votacao
     * @return Se foi possivel criar o eleitor
     */
    public boolean CriarEleitor(String Path, String CampoNome, String CampoTitulo, String CampoCPF, String CampoUrna) {
        if (eDAO.ObjectCpf(CampoCPF) != null) {
            JOptionPane.showMessageDialog(null, "CPF ja foi cadastrado");
            return false;
        }
        if (eDAO.ObjectTitulo(CampoTitulo) != null) {
            JOptionPane.showMessageDialog(null, "Titulo de Eleitor ja foi cadastrado");
            return false;
        }

        Eleitor eleitor = null;
        int numero = 0;
        eleitor = new Eleitor();
        try {
            eleitor.setImagemSenha(Path);
        } catch (Exception e) {
            return false;
        }
        eleitor.setNome(CampoNome);
        eleitor.setCpf(CampoCPF);
        eleitor.setTituloEleitor(CampoTitulo);
        try {
            numero = Integer.parseInt(CampoUrna);
        } catch (Exception e) {
            System.out.println("Numero Invalido");
            return false;
        }
        eleitor.setUrnaVotacao(numero);
        //Imagem ja foi setada ao carregar a imagem

        if (eDAO.CriarEleitor(eleitor)) {
            JOptionPane.showMessageDialog(null, "Eleitor Cadastrado com Sucesso\n"
                    + "\nNome:" + CampoNome
                    + "\nCPF:" + eleitor.getCpf().toStringPonto()
                    + "\nTitulo Eleitor:" + eleitor.getTituloEleitor()
                    + "\nUrna de Votaçao:" + eleitor.getUrnaVotacao()
                    + "\n\nHash:" + eleitor.getHash());
            return true;
        } else {
            JOptionPane.showMessageDialog(null, "Erro ao cadastrar");
            return false;
        }
    }

    /**
     * @return Retorna o Numero de votos ou seja posiçoes nao nulas de vDAO
     */
    public int TotalVotos() {
        return vDAO.getTotal();
    }

    /**
     * @param i Indice
     * @return Retorna o voto presente em vDAO com indice 'i'
     */
    public Voto VotoIndice(int i) {
        return this.vDAO.VotoIndice(i);
    }

    public Candidato CandidatoIndice(int i) {
        return this.cDAO.CandidatoIndice(i);
    }

    /**
     *
     * @return Retorna o total de candidatos ou seja numeo de posiçoes nao nula
     * de cDAO
     */
    public int TotalCandidatos() {
        return cDAO.getTotal();
    }

    /**
     * Calcula a quantidade de voto de cada eleitor
     */
    private void CalculaVotos() {
        for (int i = 0; i < cDAO.getTotal(); i++) {//Pega a Quantidade de Votos de cada eleitor
            nVotos[i] = vDAO.NVotosCandidato(cDAO.CandidatoIndice(i));
           // System.out.println("Candidato do "+cDAO.CandidatoIndice(i).getSigla()+" "+cDAO.CandidatoIndice(i).getNome() + " possui " + nVotos[i] + " votos");
        };
    }

    /**
     *
     * @return Ventor de inteiros com os indices dos vencedores
     */
    public int[] indiceVencedores() {
        Resultado();
        //Muito Procesasmento Desnecessário porem não estou usando alocamento dinamico
        int maior = nVotos[0];
        int qtdRepeticoes = 0;
        for (int i = 1; i < nVotos.length; i++) {//Começa da segunda posição para evitar erro na qtd de repetição
            if (nVotos[i] >= maior) {
                if (nVotos[i] > maior) {
                    maior = nVotos[i];
                    qtdRepeticoes = 0;
                } else {
                    qtdRepeticoes++;
                }
            }
        }
        if(maior==0){//Significa que o vetor de votos está vazio
            return null;
        }
        //So é necessario este for por não usar alocação dinamica
        int[] indiceVencedores = null;
        if (qtdRepeticoes == 0) {
            indiceVencedores = new int[1];
        } else {
            //quantidade que repetiu a isntancia + a propria instancia
            indiceVencedores = new int[qtdRepeticoes+1];
        }
        
        int jaPreenchido = 0;
        for (int i = 0; i < nVotos.length; i++) {
            if (nVotos[i] == maior) {
                indiceVencedores[jaPreenchido] = i;
                jaPreenchido++;
            }
        }
        
        for (int i = 0; i < jaPreenchido; i++) {
            System.out.println(indiceVencedores[i]);

        }
        return indiceVencedores;
    }

    
    
    
    public int[] indiceVencedores(String Sigla) {
        try {
            Estados.valueOf(Sigla);
        } catch (Exception e) {
            //Erro
            System.out.println("Sigla Incorreta");
        }
        
        Resultado();
        //Muito Procesasmento Desnecessário porem não estou usando alocamento dinamico
        int maior = 0;// nVotos[0];
        int qtdRepeticoes = 0;
        
        for (int i = 0; i < nVotos.length; i++) {//Começa da segunda posição para evitar erro na qtd de repetição
            if(cDAO.CandidatoIndice(i)!=null){
                if(cDAO.CandidatoIndice(i).getSigla().equals(Estados.valueOf(Sigla).getSigla())){//verifica se é do mesmo estado
                    if (nVotos[i] >= maior) {
                        if (nVotos[i] > maior) {
                            maior = nVotos[i];
                            qtdRepeticoes = 0;
                        } else {
                            qtdRepeticoes++;
                        }
                    }
                 }
            }
        }
        if(maior==0){//Significa que o vetor de votos está vazio
            return null;
        }
        //So é necessario este for por não usar alocação dinamica
        int[] indiceVencedores = null;
        if (qtdRepeticoes == 0) {
            indiceVencedores = new int[1];
        } else {
            //quantidade que repetiu a isntancia + a propria instancia
            indiceVencedores = new int[qtdRepeticoes+1];
        }
        
        int jaPreenchido = 0;
        for (int i = 0; i < nVotos.length; i++) {
            if (nVotos[i] == maior) {
                indiceVencedores[jaPreenchido] = i;
                jaPreenchido++;
            }
        }
        
        for (int i = 0; i < jaPreenchido; i++) {
            System.out.println(indiceVencedores[i]);

        }
        return indiceVencedores;
    }

    /**
     * Retorna o numero de votos do candidato de indice 'i'
     *
     * @param i Indice
     * @return numero de votos que o Candidato[i] ganhou
     */
    public int nVotoIndice(int i) {
        return nVotos[i];
    }

    /**
     *
     * @return Json com todos os Dados DAO
     */
    public String makeJson() {
        System.out.println("Criado Json Geral");
        JSONObject json = new JSONObject();//Superior

        JSONObject cJson = new JSONObject(cDAO.makeJson());
        JSONArray jsonCandidato = cJson.getJSONArray("Candidato");//Quebra o Json no Vetor

        JSONObject eJson = new JSONObject(eDAO.makeJson());
        JSONArray jsonEleitor = eJson.getJSONArray("Eleitor");//Quebra o Json no Vetor

        JSONObject pJson = new JSONObject(pDAO.makeJson());
        JSONArray jsonPartido = pJson.getJSONArray("Partido");//Quebra o Json no Vetor

        JSONObject vJson = new JSONObject(vDAO.makeJson());
        JSONArray jsonVoto = vJson.getJSONArray("Voto");//Quebra o Json no Vetor

        json.put("Candidato", jsonCandidato);
        json.put("Eleitor", jsonEleitor);
        json.put("Partido", jsonPartido);
        json.put("Voto", jsonVoto);
        return json.toString();
    }
    //Ver quem ganho retornar maior numero do vetor
}
