#include "pilha.h"

struct pilha {
    int topo;
    int capacidade;
    float *dados;
};

Pilha *pilha_criar(void) {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = 0;
    p->capacidade = N;
    p->dados = (float *) malloc(p->capacidade * sizeof(float));
    return p;
}

void pilha_push(Pilha *p, float v) {
    if (p->topo == p->capacidade) {
        p->capacidade *= 2;
        p->dados = (float *) realloc(p->dados, p->capacidade * sizeof(float));
        if (p->dados == NULL) {
            printf("Erro ao realocar memória!\n");
            exit(1);
        }
    }
    p->dados[p->topo] = v;
    p->topo++;
}

int pilha_vazia(Pilha *p) {
    return (p->topo == 0);
}

float pilha_pop(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia\n");
        exit(1);
    }
    p->topo--;
    return p->dados[p->topo];
}

void pilha_libera(Pilha *p) {
    free(p->dados);
    free(p); 
}