#include <stdio.h>
#include "lista.h"

int main() {
    Lista* l = NULL;

    l = lcirc_insere(l, 10);
    l = lcirc_insere(l, 20);
    l = lcirc_insere(l, 30);
    l = lcirc_insere(l, 40);

    printf("Lista circular:\n");
    lcirc_imprime(l);

    while (1) {
        int n;
        printf("Informe o número que deseja remover (ou -1 para sair): ");
        scanf("%d", &n);

        if (n == -1) {
            break;
        }

        if (lcirc_verifica(l, n)) {
            l = lcirc_retira(l, n);
            printf("Lista circular %d:\n", n);
            lcirc_imprime(l);
        } else {
            printf("O número %d não está na lista.\n", n);
        }
    }

    lcirc_libera(l);

    return 0;
}
