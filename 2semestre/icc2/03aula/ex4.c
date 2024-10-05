#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *nxt;
}node;

void inverte(node **ini) {
    node *p = *ini, *iniNew, *pNew; int i = -1;
    if (ini == NULL || (*ini)->nxt) return;

    while (p->nxt->nxt != NULL) {
        p = p->nxt;
        i++;
    }

    iniNew = p->nxt;
    p->nxt = NULL;
    pNew = iniNew->nxt;



    for (int n = 0; n<i; n++) {
        p = *ini;
        for (int j = i; j>0; j--) {
            p = p->nxt;
        }
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

    // Testar inverte
    inverte(&head);

    // Exibir lista após remoção
    printf("Lista invertida:\n");
    printList(head);

    // Liberar memória restante
    // free(head);
    // free(second);
    // free(fourth);  

    return 0;

}