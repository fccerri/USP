public class CD extends Produto{
    String titulo;
    String cantor;
    int numTrilhas;
    String gravadora;
    int ano;

    public CD(int codigo, String nome, String titulo, String cantor, int numTrilhas, String gravadora, int ano) {
        super("CD", codigo, nome, 0);
        this.titulo = titulo;
        this.cantor = cantor;
        this.numTrilhas = numTrilhas;
        this.gravadora = gravadora;
        this.ano = ano;
    }
}
