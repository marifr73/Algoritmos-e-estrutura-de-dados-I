#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} Lista;

Lista* ultimo(Lista* l) {
    if (l == NULL) {
        return NULL;
    }

    Lista* p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    return p;
}

Lista* cria_no(int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;
    return novo;
}

int main(){
    Lista* l = cria_no(3);
    l->prox = cria_no(5);
    l->prox->prox = cria_no(8);
    l->prox->prox->prox = cria_no(12);

    Lista* ultimo_no = ultimo(l);
    if (ultimo_no != NULL) {
        printf("O último nó contém o valor: %d\n", ultimo_no->info);
    } else {
        printf("A lista está vazia.\n");
    }

    while (l != NULL) {
        Lista* t = l->prox;
        free(l);
        l = t;
    }
    return 0;
}
