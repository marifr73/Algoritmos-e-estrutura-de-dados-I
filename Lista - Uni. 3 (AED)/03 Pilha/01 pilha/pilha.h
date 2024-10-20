#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct pilha Pilha;

Pilha *pilha_criar(void);

void pilha_push(Pilha *p, float v);

int pilha_vazia(Pilha *p);

float pilha_pop(Pilha *p);

void pilha_libera(Pilha *p);