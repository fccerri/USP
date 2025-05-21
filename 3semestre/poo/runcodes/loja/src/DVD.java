public class DVD extends Produto{
    String nome;
    String diretor;
    String idioma;
    String genero;
    int ano;
    String nacionalidade;

    public DVD(int codigo, String nome, String nome1, String diretor, String idioma, String genero, int ano, String nacionalidade) {
        super("DVD", codigo, nome, 0);
        this.nome = nome1;
        this.diretor = diretor;
        this.idioma = idioma;
        this.genero = genero;
        this.ano = ano;
        this.nacionalidade = nacionalidade;
    }
}
