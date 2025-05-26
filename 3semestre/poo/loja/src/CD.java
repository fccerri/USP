public class CD extends Produto{
    String banda;
    String trilhas;
    String gravadora;
    String ano;

    public CD(String codigo, String nome, String banda, String trilhas, String gravadora, String ano) {
        super("CD", codigo, nome, 0);
        this.banda = banda;
        this.trilhas = trilhas;
        this.gravadora = gravadora;
        this.ano = ano;
    }

    @Override
    public String toString() {
        String s = super.toString();
        s += "Banda: " + banda + "\n";
        s += "Gravadora: " + gravadora + "\n";
        s += "Ano: " + ano + "\n";
        s += "trilhas: " + trilhas;

        return s;
    }
}
