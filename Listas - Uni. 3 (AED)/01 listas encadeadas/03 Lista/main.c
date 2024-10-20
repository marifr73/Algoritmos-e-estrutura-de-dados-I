#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    float info;
    struct lista *prox;
} Lista;

Lista* cria_no(float valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;
    return novo;
}

Lista* concatena(Lista* l1, Lista* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    Lista* p = l1;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = l2;
    return l1;
}

void imprime_lista(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        printf("%.2f -> ", p->info);
        p = p->prox;
    }
    printf("NULL\n");
}

int main(){
    Lista* l1 = cria_no(1.1);
    l1->prox = cria_no(2.2);
    l1->prox->prox = cria_no(3.3);

    Lista* l2 = cria_no(4.4);
    l2->prox = cria_no(5.5);
    l2->prox->prox = cria_no(6.6);

    Lista* l_concatenada = concatena(l1, l2);

    imprime_lista(l_concatenada);

    while (l_concatenada != NULL) {
        Lista* t = l_concatenada->prox;
        free(l_concatenada);
        l_concatenada = t;
    }

    return 0;
}