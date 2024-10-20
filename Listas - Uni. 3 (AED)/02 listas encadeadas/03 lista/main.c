#include <stdio.h>
#include "lista.h"

int main() {
    Lista2* l = NULL;

    l = l2circ_insere(l, 10);
    l = l2circ_insere(l, 20);
    l = l2circ_insere(l, 30);
    l = l2circ_insere(l, 40);

    printf("Lista circular duplamente encadeada:\n");
    l2circ_imprime(l);

    printf("Lista circular duplamente encadeada em ordem reversa:\n");
    l2circ_imprime_rev(l);

    while (1) {
        int n;
        printf("\nDigite o número que deseja remover (ou -1 para sair): ");
        scanf("%d", &n);

        if (n == -1) {
            break;
        }

        if (l2circ_busca(l, n) != NULL) {
            l = l2circ_retira(l, n);
            printf("\nLista circular %d:\n", n);
            l2circ_imprime(l);
            printf("Lista circular reversa %d:\n", n);
            l2circ_imprime_rev(l);
        } else {
            printf("O número %d não está na lista.\n", n);
        }
    }

    l2circ_libera(l);

    return 0;
}
