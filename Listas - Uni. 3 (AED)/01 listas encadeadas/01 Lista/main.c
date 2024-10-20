#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int info;
    struct no *prox;
} No;

No *adicionar_num(No *lista, int info) {
    No *novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        exit(1);
    }

    novo_no->info = info;
    novo_no->prox = lista;

    return novo_no;
}

int maiores(No *l, int *n) {
    No *atual;
    int i = 0;
    for (atual = l; atual != NULL; atual = atual->prox) {
        if (atual->info > *n) {
            i++;
        }
    }
    return i;
}

void imprime_novo_num(No *lista) {
    No *count;
    for (count = lista; count != NULL; count = count->prox) {
        printf(" %d\t", count->info);
    }
}

void liberar_lista(No *l) {
    No *atual;
    while (l != NULL) {
        atual = l;
        l = l->prox;
        free(atual);
    }
}

int main() {
    No *l = NULL;
    int resultado, n = 4;

    l = adicionar_num(l, 1);
    l = adicionar_num(l, 5);
    l = adicionar_num(l, 8);
    l = adicionar_num(l, 6);

    imprime_novo_num(l);

    resultado = maiores(l, &n);
    printf("\nNumero de nos com valores maiores que %d: %d\n", n, resultado);

    liberar_lista(l);

    return 0;
}
