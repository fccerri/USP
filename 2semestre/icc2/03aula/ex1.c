#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *nxt;
}node;

void buscaRemove(int y, node **ini) {
    node *p = *ini;

    if (p == NULL) return;
    if ( p->data == y) {
        node *aux = p->nxt;
        free(p);
        p = aux;
        *ini = p; //evita que ini aponte para memoria nao alocada
        return;
    }

    while (p->nxt != NULL && p->nxt->data != y) {
        p = p->nxt;
    }

    if (p->nxt != NULL) {
        node *aux = p->nxt->nxt;
        free(p->nxt);
        p->nxt = aux;
    }
}

void printList(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->nxt;
    }
    printf("NULL\n");
}

int main () {
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));
    node *fourth = (node *)malloc(sizeof(node));

    // Inicializar valores
    head->data = 1;
    head->nxt = second;

    second->data = 2;
    second->nxt = third;

    third->data = 3;
    third->nxt = fourth;

    fourth->data = 4;
    fourth->nxt = NULL;

    // Exibir lista original
    printf("Lista original:\n");
    printList(head);

    // Testar buscaRemove
    int valueToRemove = 3;
    printf("Removendo o valor %d...\n", valueToRemove);
    buscaRemove(valueToRemove, &head);

    // Exibir lista após remoção
    printf("Lista após remoção:\n");
    printList(head);

    // Liberar memória restante
    free(head);
    free(second);
    free(fourth);  // Terceiro nó foi removido

    return 0;
}

