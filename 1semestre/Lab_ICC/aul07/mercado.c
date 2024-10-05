#include <stdio.h>

int main (void) {
    int n =0, qtd_compra, qtd_venda, id;
    float preco_compra, preco_venda, lucro, maior_lucro = 0, total_lucro = 0;
    scanf("%d", &n);
    if (n==0) {
        printf("Sem atividades registradas hoje");
        return 0;
    }

    for (int i = 1; i<=n; i++) {
        scanf("%f%f%d%d", &preco_compra, &preco_venda, &qtd_compra, &qtd_venda);
        lucro = (qtd_venda*preco_venda) - (preco_compra*qtd_compra);
        
        if (lucro>maior_lucro) {
            maior_lucro=lucro;
            id = i;}

        total_lucro += lucro;
    }

    if (total_lucro>0)
    printf("lucro: %.2f\n", total_lucro);

    else printf("prejuizo: %.2f\n", (-1)*total_lucro);

    printf("produto: %d lucro relativo: %.2f", id, maior_lucro);


    return 0;
}