import java.util.Scanner;

/*
- Private: uma classe private significa que esse membro só pode ser acessado dentro da própria classe que foi definido
- Construtor: é um metodo que tem o mesmo nome da classe
    -não tem tidpo delcarado
    -é possíver ter mais do que um construtor
    -todos os membros precisam ser declarados e ter um tipo
- Verificação estática de tipos
-Casting obrigatorio em casos de perda de informação
-variaveis são locasi
-Break label: - 
*/

public class Cadeira {
    private String posicao;
    private boolean ocupado;

    public Cadeira() {
    }

    public Cadeira(String p, boolean oc) {
    }

    public void sentar() {
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String teste = sc.next();

            System.out.println("Hello" + teste + "World!");

        sc.close();

    }
}