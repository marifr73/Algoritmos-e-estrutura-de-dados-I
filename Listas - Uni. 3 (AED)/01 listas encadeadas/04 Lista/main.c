#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} Lista;

Lista* cria_no(int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;
    return novo;
}

int verifica_numero(Lista* l, int n) {
    Lista* p = l;
    while (p != NULL) {
        if (p->info == n) {
            return 1;
        }
        p = p->prox;
    }
    return 0;
}

Lista* retira_n(Lista* l, int n) {
    Lista* p = l;
    Lista* anterior = NULL;
    while (p != NULL) {
        if (p->info == n) {
            if (anterior == NULL) {
                Lista* temp = p;
                p = p->prox;
                free(temp);
                l = p;
            } else {
                anterior->prox = p->prox;
                free(p);
                p = anterior->prox;
            }
        } else {
            anterior = p;
            p = p->prox;
        }
    }
    return l;
}

void imprime_lista(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->prox;
    }
    printf("NULL\n");
}

int main() {
    Lista* l = cria_no(10);
    l->prox = cria_no(20);
    l->prox->prox = cria_no(30);
    l->prox->prox->prox = cria_no(20);
    l->prox->prox->prox->prox = cria_no(40);

    printf("Lista:\n");
    imprime_lista(l);

    int n;
    printf("Digite o número que deseja remover: ");
    scanf("%d", &n);

    if (verifica_numero(l, n)) {
        l = retira_n(l, n);
        printf("Lista após remover %d:\n", n);
        imprime_lista(l);
    } else {
        printf("O número %d não está na lista.\n", n);
    }

    while (l != NULL) {
        Lista* t = l->prox;
        free(l);
        l = t;
    }
    return 0;
}