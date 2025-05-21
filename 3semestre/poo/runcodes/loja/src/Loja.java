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
            
        estoque[tamanhoEstoque] = item;
        tamanhoEstoque++;
        return true;
    }

    public boolean adicionarProduto(Produto item, int quantidade) {
        for (int i = 0; i < tamanhoEstoque; i++) {
            if (item.codigo == estoque[i].codigo) {
                estoque[i].quantidade += quantidade;
                return true;
            }
        }
        return false;
    }

    public boolean comprarProduto(int codigo, int quantidade) {
        for (int i = 0; i < tamanhoEstoque; i++) {
            if (estoque[i].codigo == codigo) {
                if (estoque[i].quantidade >= quantidade) {
                    return true;
                }
                break;
            }
        }   
        return false;
    }
    
    public boolean procurarProduto(int codigo) {
        for (int i = 0; i < tamanhoEstoque; i++) {
            if (estoque[i].codigo == codigo) {
                return true;
    
            }
        }   
        return false;
    }

    public void printaProduto(int codigo) {
        for (int i = 0; i < tamanhoEstoque; i++) {
            if (estoque[i].codigo == codigo) {
                System.out.println(estoque[i]);
                break;
            }
        }   
    }

    public void mostraEstoqueTipo(String tipo) {
        int count = 0;
        for (int i = 0; i < tamanhoEstoque; i++) {
            if (estoque[i].tipo.equals(tipo)) {
                System.out.println(estoque[i]);
                count++;
            }
            System.out.println("Quantidade de " + tipo + "s: " + count);
        }
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
                System.out.println();
            }
        }
    }

}
    
