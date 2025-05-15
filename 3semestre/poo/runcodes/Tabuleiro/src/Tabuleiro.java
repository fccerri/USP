public class Tabuleiro {
    private int[][] tabela;
    private int l_vazia, c_vazia; //posição da casa vazia
    private int tamanho; //tamanho do tabuleiro

    public Tabuleiro(int[] numeros) {

        tamanho = (int) Math.sqrt(numeros.length) ; 
        tabela = new int[tamanho][tamanho];
        int count = 0;
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                tabela[i][j] = numeros[count];
                count++;
                if (this.tabela[i][j] == 0) {
                    l_vazia = i;
                    c_vazia = j;
                }
            }
        }

    }

    public void printa_tabuleiro() {
        for (int t = 0; t < tamanho; t++) { //"tampa" da tabela
            System.out.print("+------");
        }
        for (int i = 0; i < tamanho; i++) {

            System.out.print("+\n|");

            for (int j = 0; j < tamanho; j++) {
                if(tabela[i][j] < 10)
                    System.out.print(" "); //correção caso numero<10

                System.out.printf("  %d  |", tabela[i][j]);
            }
            System.out.println();
            for (int t = 0; t < tamanho; t++) { //printa em baixo dos numeros
                System.out.print("+------");
            }
        }
        System.out.print("+\n\n");
    }
    public void move_tabuleiro(String op) {
        int l_update = 0, c_update = 0;
        for (int count = 0; count < op.length(); count++) {
            switch (op.charAt(count)) {
                case 'u': {
                    l_update = 1;
                    c_update = 0;
                    break;
                }
                case 'd': {
                    l_update = -1;
                    c_update = 0;
                    break;
                }
                case 'l': {
                    l_update = 0;
                    c_update = 1;
                    break;
                }
                case 'r': {
                    l_update = 0;
                    c_update = -1;
                    break;
                }
                default: System.out.println("Operação não reconhecida");
            }

            if (l_vazia+l_update >= 0 && l_vazia+l_update < tamanho //verifica validade do movimento
            && c_vazia+c_update < tamanho && c_vazia+c_update >= 0) {
                this.tabela[l_vazia][c_vazia] = this.tabela[l_vazia + l_update][c_vazia + c_update]; //swap
                this.tabela[l_vazia + l_update][c_vazia + c_update] = 0;

                c_vazia += c_update; //att a posição vazia
                l_vazia += l_update;
            }
            printa_tabuleiro();
        }
    }

    public boolean valida_tabuleiro() {
        int count = 0;
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                if (this.tabela[i][j] != count) {
                    return false;
                }
                count++;
            }
        }
        return true;
    }
}

