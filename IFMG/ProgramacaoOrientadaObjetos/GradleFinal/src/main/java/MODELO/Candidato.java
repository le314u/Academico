package MODELO;

/**
 * Classe para objetos do tipo Candidato private String Nome private int Numero
 * private Documentos Cpf private Partido Partido
 *
 * @author Lucas Mateus Fernandes
 */
public class Candidato {

    private String Nome;
    private int Numero;
    private Documentos Cpf;
    private Partido Partido;

    public Candidato() {

    }

    /**
     * Construtor Candidato (Todos Argumentos são String)
     *
     * @param Nome - Nome do Candidato
     * @param Numero - Numero do Candidato
     * @param Cpf - Cpf do Candidato
     * @param NumeroPartido - Numero do Partido
     * @param NomePartido - Nome do Partido
     */
    public Candidato(String Nome, String Numero, String Cpf, String NumeroPartido, String NomePartido) {// Import do
        System.out.println("Criando Candidato");
        if (setCpf(Cpf)) {// Se o cpf não for valido ja aborta
            this.Nome = Nome;
            this.Numero = Integer.parseInt(Numero);
            this.Partido = new Partido(NumeroPartido, NomePartido);
        } else {
            System.out.println("Cpf Invalido");
        }
    }

    public Candidato(String Nome, String Numero, String Cpf, Partido Partido) {// Import do
        System.out.println("Criando Candidato");
        if (setCpf(Cpf)) {// Se o cpf não for valido ja aborta
            this.Nome = Nome;
            this.Numero = Integer.parseInt(Numero);
            this.Partido = Partido;
        } else {
            System.out.println("Cpf Invalido");
        }
    }

    /**
     * @return Nome Candidato
     */
    public String getNome() {
        return Nome;
    }

    /**
     * @param nome Nome Candidato
     */
    public void setNome(String nome) {
        Nome = nome;
    }

    /**
     * @return int Numero Candidato
     */
    public int getNumero() {
        return Numero;
    }

    /**
     * @param numero Numero Candidato
     */
    public void setNumero(int numero) {
        Numero = numero;
    }

    /**
     * @param cpf- Numero Cpf em String
     * @return Boolean - TRUE (se cpf for valido) FALSE(se cpf for invalido)
     */
    public boolean setCpf(String cpf) {
        Documentos doc = new Documentos();
        if (doc.validaCpf(cpf)) {// So muda se o cpf passado for valido
            this.Cpf = doc;
            return true;
        } else {
            System.out.println("CPF Invalido");
        }
        return false;
    }

    /** @return String- Cpf do candidato
     */
    public String getCpfString() {
        return Cpf.toString();
    }

    /** @return Documentos - Objecto Documentos que possui o cpf internamente
     */
    public Documentos getCpf() {
        return Cpf;
    }

    /** @return Partido - Objecto Partido
     */
    public Partido getPartido() {
        return this.Partido;
    }

    /**
     * @return Candidato - Objecto Candidato
     */
    public Candidato getCandidato() {
        return this;
    }

    /**
     * @param partido - Objecto Partido
     */
    public void setPartido(Partido partido) {
        Partido = partido;
    }

    /**
     * @param candidato Objeto Candidato
     * @return Se Candidato são iguais
     */
    public boolean equals(Candidato candidato) {
        //Argumento veio vazio
        if (candidato == null) {
            //System.out.println("Argumento Veio Vazio");
            return false;
        }

        //verifica nome
        if (!(this.Nome.equals(candidato.getNome()))) {
            //System.out.println(this.Nome+" != "+candidato.getNome());
            return false;
        }
        //verifica numero
        if (!(this.Numero == candidato.getNumero())) {
            //System.out.println(this.Numero+" != "+candidato.getNumero());
            return false;
        }

        //Transforma String em cpf
        Documentos aux = new Documentos(candidato.getCpfString());
        //verifica CPF
        if (!(Cpf.toString().equals(aux.toString()))) {
            System.out.println("vindo" + candidato.getCpfString());
            System.out.println(Cpf.toString() + " != " + aux.toString());
            return false;
        }
        //Verifica Partido
        return true;
    }
}
