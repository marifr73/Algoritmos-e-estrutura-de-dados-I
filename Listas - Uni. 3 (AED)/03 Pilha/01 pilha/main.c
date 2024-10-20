#include "pilha.h"

int main(){
    Pilha *pilha = pilha_criar();
    int i;

    for (i = 0; i < 25; i++) {
        pilha_push(pilha, i + 0.0);
    }

    while (!pilha_vazia(pilha)) {
        printf("%.1f\t", pilha_pop(pilha));
    }

    printf("\n");

    pilha_libera(pilha);
    return 0;
}