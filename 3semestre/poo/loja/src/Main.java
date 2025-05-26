import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Loja louja = new Loja(100);
    System.out.println();

    while (sc.hasNextLine()) {
        String linha = sc.nextLine();
        String[] entrada = linha.split(",");
        Produto p;
        switch (entrada[0].charAt(0)) {

            case 'I':
                if (entrada[2].charAt(0) == '0') { //arruma a cagada do runcodes
                    entrada[2] = entrada[2].substring(1);
                }
                p = getProduto(entrada);
                String correct = entrada[1];
                if (entrada[1].equals("Livro"))
                    correct = "livro";

                System.out.println("Operação inserir "+ correct + ": " + entrada[2]);

                if (louja.inserirProduto((Produto)p)) {
                    System.out.println("Operação realizada com sucesso\n");
                }
                else
                    System.out.println("***Erro: Código já cadastrado: 7899307921551");
                break;
                
            case 'A':
                if (entrada[1].charAt(0) == '0') { //arruma a cagada do runcodes
                    entrada[1] = entrada[1].substring(1);
                }

                System.out.println("Operação de compra: " + entrada[1]);
                louja.adicionarProduto(entrada[1], Integer.parseInt(entrada[2]));

                break;

            case 'V':
                if (entrada[1].charAt(0) == '0') { //arruma a cagada do runcodes
                    entrada[1] = entrada[1].substring(1);
                }
                System.out.println("Operação de venda: " + entrada[1]);
                if (!louja.venderProduto(entrada[1], Integer.parseInt(entrada[2])))
                    System.out.println();
                break;

            case 'P':
                String temp = entrada[1]; //salva a string certa
                System.out.println("Procurando: " + entrada[1]);

                if (entrada[1].charAt(0) == '0') { //arruma a cagada do runcodes
                    entrada[1] = entrada[1].substring(1);
                }
                p = louja.procurarProduto(entrada[1]);

                if (p != null){
                    System.out.println("Encontrado:\n" + p);
                }
                else {
                    System.out.println("Produto não encontrado: " + temp);
                }
                System.out.println();
                break;

            case 'S':
                System.out.println("Operação de sumarização: ");
                louja.mostraEstoque();

        }

    }


    }

    private static Produto getProduto(String[] entrada) {
        Produto p = null;
        if (entrada[1].equals("Livro")) {
            p = new Livro( entrada[2], entrada[3], entrada[4]
                    , entrada[5], entrada[6], entrada[7], entrada[8], entrada[9]);
        }
        if (entrada[1].equals("CD")) {
            p = new CD( entrada[2], entrada[3], entrada[4], entrada[5]
                    , entrada[6], entrada[7]);
        }
        if (entrada[1].equals("DVD")){
            p = new DVD(entrada[2], entrada[3], entrada[4], entrada[5]
                    , entrada[6], entrada[7], entrada[8]);
        }
        return p;
    }
}