import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //declaração de variaveis
        String str_numeros, op;
        Scanner sc = new Scanner(System.in);

        str_numeros = sc.nextLine(); //leitura e tratamento da string de numeros
        String[] strArray = str_numeros.split(" ");
        int[] numeros = new int[strArray.length];
        for (int i = 0; i < strArray.length; i++) {
                numeros[i] = Integer.parseInt(strArray[i]);
        }

        Tabuleiro tab = new Tabuleiro(numeros); //seta e printa o tabuleiro
        tab.printa_tabuleiro();

        op = sc.nextLine(); //le e faz as operações de movimento
        tab.move_tabuleiro(op);

        System.out.print("Posicao final: "); //print da linha final
        if (tab.valida_tabuleiro())
            System.out.print("true");
        else
            System.out.print("false");

    }
}