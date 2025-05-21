public class Livro extends Produto  {
    String nome;
    String autor;
    String editora;
    int ano;
    String edicao;
    String idioma;
    int paginas;

    public Livro(String tipo, int codigo, String nome, String nome1, String autor, String editora, int ano, String edicao, int paginas, String idioma, int quantidade) {
        super("Livro", codigo, nome, 0);
        this.nome = nome1;
        this.autor = autor;
        this.editora = editora;
        this.ano = ano;
        this.edicao = edicao;
        this.paginas = paginas;
        this.idioma = idioma;
    }


}
