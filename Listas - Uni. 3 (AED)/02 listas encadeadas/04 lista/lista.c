#include "lista.h"

struct lista2 {
    int info;
    struct lista2 *prox;
    struct lista2 *ant;
};

Lista2* l2circ_cria_no(int valor) {
    Lista2* novo = (Lista2*)malloc(sizeof(Lista2));
    novo->info = valor;
    novo->prox = novo;
    novo->ant = novo;
    return novo;
}

void l2circ_imprime(Lista2* l) {
    if (l == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Lista2* p = l;
    do {
        printf("%d -> ", p->info);
        p = p->prox;
    } while (p != l);
    printf("(volta ao início)\n");
}

Lista2* l2circ_insere(Lista2* l, int valor) {
    Lista2* novo = l2circ_cria_no(valor);
    if (l == NULL) {
        return novo;
    }

    Lista2* ultimo = l->ant;
    novo->prox = l;
    novo->ant = ultimo;
    l->ant = novo;
    ultimo->prox = novo;

    return l;
}

Lista2* l2circ_retira(Lista2* l, int valor) {
    if (l == NULL) {
        return NULL;
    }

    Lista2* p = l;

    do {
        if (p->info == valor) {
            if (p->prox == p) {
                free(p);
                return NULL;
            }

            p->ant->prox = p->prox;
            p->prox->ant = p->ant;

            if (p == l) {
                l = p->prox;
            }

            free(p);
            return l;
        }
        p = p->prox;
    } while (p != l);

    return l;
}

Lista2* l2circ_busca(Lista2* l, int valor) {
    if (l == NULL) {
        return NULL;
    }

    Lista2* p = l;
    do {
        if (p->info == valor) {
            return p;
        }
        p = p->prox;
    } while (p != l);

    return NULL;
}

void l2circ_libera(Lista2* l) {
    if (l == NULL) {
        return;
    }

    Lista2* p = l->prox;
    while (p != l) {
        Lista2* t = p->prox;
        free(p);
        p = t;
    }
    free(l);
}