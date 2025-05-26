public class DVD extends Produto {
    String diretor;
    String idioma;
    String genero;
    String ano;
    String nacionalidade;

    public DVD(String codigo, String nome, String diretor, String idioma, String genero, String  ano, String nacionalidade) {
        super("DVD", codigo, nome, 0);
        this.diretor = diretor;
        this.idioma = idioma;
        this.genero = genero;
        this.ano = ano;
        this.nacionalidade = nacionalidade;
    }

    @Override
    public String toString() {
        String s = super.toString();
        s += "Diretor: " + diretor + "\n";
        s += "Gênero: " + genero + "\n";
        s += "Ano: " + ano + "\n";
        s += "Nacionalidade: " + nacionalidade + "\n";
        s += "Idioma: " + idioma;

        return s;
    }

}
