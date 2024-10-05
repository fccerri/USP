#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *nxt;
}node;

node* removeX (int x, node **ini) { //ta dando seg fault caso ini = null
    if (x<= 0 || *ini == NULL) return *ini;
    
    node *p = *ini;
    node *aux;

    for (int i =0; i<x; i++) {
        aux = p->nxt;
        free(p);
        p = aux;
        
        if (p==NULL) break;
    }
    *ini = p; //evita que ini aponte para memoria não alocada;
    return p;
}

void printList(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->nxt;
    }
    printf("NULL\n");
}

int main() {
    // Alocar memória para nós
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));
    node *fourth = (node *)malloc(sizeof(node));
    node *fifth = (node *)malloc(sizeof(node));

    head = NULL; //ta dando merda 

    // Inicializar valores
    head->data = 1;
    head->nxt = second;

    second->data = 2;
    second->nxt = third;

    third->data = 3;
    third->nxt = fourth;

    fourth->data = 4;
    fourth->nxt = fifth;

    fifth->data = 5;
    fifth->nxt = NULL;

    // Exibir lista original
    printf("Lista original:\n");
    printList(head);

    // Testar removeX
    int elementsToRemove = 3;
    printf("Removendo os primeiros %d elementos...\n", elementsToRemove);
    head = removeX(elementsToRemove, &head);

    // Exibir lista após remoção
    printf("Lista após remoção:\n");
    printList(head);

    // Liberar memória restante
    free(head);
    free(fifth);  // Apenas quarto e quinto nós são deixados
    // Note que não precisamos liberar os três primeiros nós, pois já foram removidos e liberados.

    return 0;
}
