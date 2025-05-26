public class Produto {
    String tipo;
    String codigo;
    String nome;
    int quantidade;


    public Produto(String tipo, String codigo, String nome, int quantidade) {
        this.tipo = tipo;
        this.codigo = codigo;
        this.nome = nome;
        this.quantidade = quantidade;
    }

    @Override
    public String toString() {
        String s = "";
        s += tipo + "\n";
        s += "Código: " + codigo + "\n";
        s += "Título: " + nome+"\n";

        return s;
    }


}
