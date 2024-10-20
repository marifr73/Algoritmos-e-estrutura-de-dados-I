#include "lista.h"

int main() {
    Lista2* l = NULL;

    l = l2circ_insere(l, 10);
    l = l2circ_insere(l, 20);
    l = l2circ_insere(l, 30);
    l = l2circ_insere(l, 40);

    printf("Lista circular duplamente encadeada após inserções:\n");
    l2circ_imprime(l);

    while (1) {
        int n;
        printf("Digite o número que deseja remover (ou -1 para sair): ");
        scanf("%d", &n);

        if (n == -1) {
            break;
        }

        if (l2circ_busca(l, n) != NULL) {
            l = l2circ_retira(l, n);
            printf("Lista circular após remover %d:\n", n);
            l2circ_imprime(l);
        } else {
            printf("O número %d não está na lista.\n", n);
        }
    }

    l2circ_libera(l);
    return 0;
}