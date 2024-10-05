#include <stdio.h>

/*
	Agora vejamos o campo "data"
	Certamente ele diz respeito a dados (variaveis) que o seu programa
	manipula.

	vamos declarar um vetor de char de 1000 elementos
	Isso implica num uso adicional de 1000 caracteres a mais com relacao
	ao programa anterior.

	Mas como podemos declarar esta variável?
		- dentro da funcao main (isso seria uma variavel LOCAL da funcao) 
		- ou FORA de qq função, no inicio do código (abaixo dos includes)
			estas sao ditas variáveis GLOBAIS.
	
*/


// vamos começar com variaveis globais.....
// um vetor de char de 1000 elementos. Esta variavel se chama "vetor"
// compare com o campo data do programa anterior.. o que muda???
char vetor[1000];

/*
	Repare que da maneira como declaramos a variavel acima, o valor
	de data EM NADA MUDA com relacao a versao anterior..

	No entanto, o campo bss aumenta em cerca de 1000 bytes, o  que
	era de se esperar.. O que é este tal de bss e qual a diferenca
	para o campo "data" ???

	Para comecar a responder, faca o seguinte:
		- comente a declaracao da variavel "vetor" acima e declare
		- char vetor[10] = {'a'};

*/

int main(void)
{
    printf("Hello World!\n");
    return 0;
}