#ifndef LISTA_SE_H
#define LISTA_SE_H
#include "../../item.h"
#define ERRO -1
#define ORDENADA 0

typedef struct no_ NO;
typedef struct lista_se LISTA_SE;

LISTA_SE *Lista_se_criar(void);
bool lista_se_vazia(LISTA_SE *lista);
void lista_se_inserir(LISTA_SE *lista, ITEM *item);
ITEM *lista_se_remover(LISTA_SE *lista, int chave);
void lista_se_apagar(LISTA_SE **lista);
ITEM *lista_se_get_dados(LISTA_SE *lista, int chave);

#endif
