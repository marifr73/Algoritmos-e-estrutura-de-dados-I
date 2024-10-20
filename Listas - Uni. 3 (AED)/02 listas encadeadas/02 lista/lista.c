#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
    int info;
    struct lista *prox;
};

Lista* cria_no(int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = novo;
    return novo;
}

void lcirc_imprime(Lista* l) {
    if (l == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Lista* p = l;
    do {
        printf("%d -> ", p->info);
        p = p->prox;
    } while (p != l);
    printf("(volta ao início)\n");
}

Lista* lcirc_insere(Lista* l, int valor) {
    Lista* novo = cria_no(valor);
    if (l == NULL) {
        return novo;
    }

    Lista* p = l;
    while (p->prox != l) {
        p = p->prox;
    }
    p->prox = novo;
    novo->prox = l;
    return l;
}

Lista* lcirc_retira(Lista* l, int valor) {
    if (l == NULL) {
        return NULL; 
    }

    Lista* p = l;
    Lista* ant = NULL;

    do {
        if (p->info == valor) {
            if (ant == NULL) {
                Lista* ultimo = l;
                while (ultimo->prox != l) {
                    ultimo = ultimo->prox;
                }
                if (p->prox == l) {
                    free(p);
                    return NULL; 
                } else {
                    l = p->prox;
                    ultimo->prox = l;
                    free(p);
                    return l;
                }
            } else {
                ant->prox = p->prox;
                free(p);
                return l;
            }
        }
        ant = p;
        p = p->prox;
    } while (p != l);

    return l;
}

int lcirc_verifica(Lista* l, int valor) {
    if (l == NULL) {
        return 0;
    }

    Lista* p = l;
    do {
        if (p->info == valor) {
            return 1;
        }
        p = p->prox;
    } while (p != l);

    return 0;
}

void lcirc_libera(Lista* l) {
    if (l == NULL) {
        return;
    }

    Lista* p = l->prox;
    while (p != l) {
        Lista* t = p->prox;
        free(p);
        p = t;
    }
    free(l);
}
