public class Livro extends Produto  {
    String nome;
    String autor;
    String editora;
    String ano;
    String edicao;
    String idioma;
    String paginas;

    public Livro( String codigo, String nome, String autor, String editora, String ano, String edicao, String paginas, String idioma) {
        super("Livro", codigo, nome, 0);
        this.autor = autor;
        this.editora = editora;
        this.ano = ano;
        this.edicao = edicao;
        this.paginas = paginas;
        this.idioma = idioma;
    }

    @Override
    public String toString() {
        String s = super.toString();
        s += "Autor: " + autor + "\n";
        s += "Editora: " + editora + "\n";
        s += "Edição: " + edicao + "\n";
        s += "Ano: " + ano + "\n";
        s += "Páginas: " + paginas + "\n";
        s += "Idioma: " + idioma;

        return s;
    }



}
