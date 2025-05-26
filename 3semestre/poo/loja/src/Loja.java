public class Loja {
    private Produto[] estoque;
    private int tamanhoEstoque;
    private int tamanhoMaximoEstoque;

    public Loja(int tamanho) {
        this.estoque = new Produto[tamanho];
        this.tamanhoEstoque = 0;
        this.tamanhoMaximoEstoque = tamanho;
    }

    public boolean inserirProduto(Produto item) {
        if (tamanhoMaximoEstoque < tamanhoEstoque )
            return false;
        for (int i = 0; i < tamanhoEstoque; i++) {
            if (estoque[i].codigo.equals(item.codigo)) {
                return false;
            }
        }
            
        estoque[tamanhoEstoque] = item;
        tamanhoEstoque++;
        return true;
    }

    public boolean adicionarProduto(String codigo, int quantidade) {
        for (int i = 0; i < tamanhoEstoque; i++) {
            if (estoque[i].codigo.equals(codigo)) {

                estoque[i].quantidade += quantidade;
                System.out.println("Operação realizada com sucesso: " + estoque[i].codigo + "\n");
                return true;
            }
        }
        System.out.println("***Erro: Código inexistente: " + codigo + "\n");
        return false;
    }

    public boolean venderProduto(String codigo, int quantidade) {
        for (int i = 0; i < tamanhoEstoque; i++) {
            if (estoque[i].codigo.equals(codigo)) {
                if (estoque[i].quantidade >= quantidade) {
                    estoque[i].quantidade -= quantidade;
                    System.out.println("Operação realizada com sucesso: " + estoque[i].codigo+ "\n");
                    return true;
                }
                System.out.printf("***Erro: Estoque insuficiente: %s Quantidade: %d\n", codigo, quantidade);
                return false;
            }
        }
        System.out.printf("***Erro: Código inexistente: %s\n", codigo);
        System.out.flush();
        return false;
    }

    public Produto procurarProduto(String criterio) {
        for (int i = 0; i < tamanhoEstoque; i++) {
            if (estoque[i].nome.equals(criterio) || estoque[i].codigo.equals(criterio)) {
                return estoque[i];
            }
        }
        return null;
    }


    public void mostraEstoqueTipo(String tipo) {
        int count = 0;
        for (int i = 0; i < tamanhoEstoque; i++) {
            if (estoque[i].tipo.equals(tipo)) {
                System.out.println(estoque[i]);
                System.out.println("Quantidade: " + estoque[i].quantidade + '\n');
                count += estoque[i].quantidade;
            }
        }
        System.out.println("Quantidade de " + tipo + "s: " + count + '\n');

    }

    public void mostraEstoque() {
        String tipos[] = new String[tamanhoEstoque];
            int qtdTipos = 0;

        for (int i = 0; i < tamanhoEstoque; i++) {
            String tipoAtual = estoque[i].tipo;
            boolean jaEncontrado = false;

            // verifica se o tipo ja foi encontrado
            for (int j = 0; j < qtdTipos; j++) {
                if (tipos[j].equals(tipoAtual)) {
                    jaEncontrado = true;
                    break;
                }
            }

            // add no array caso seja um novo tipo
            if (!jaEncontrado) {
                tipos[qtdTipos] = tipoAtual;
                qtdTipos++;
                mostraEstoqueTipo(tipoAtual); // printa todos os tipos iguais

            }
        }
        System.out.println();

    }


}
    
