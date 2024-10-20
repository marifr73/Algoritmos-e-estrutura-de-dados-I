#include <stdio.h>
#include "lista2.h"

int main() {
    Lista2* l = lst2_cria();
    
    l = lst2_insere(l, 10);
    l = lst2_insere(l, 20);
    l = lst2_insere(l, 30);

    printf("Lista:\n");
    lst2_imprime(l);

    while (1){
        int n;
        printf("Informe o número que deseja remover (ou -1 para sair): ");
        scanf("%d", &n);

        if (n == -1) {
            break;
        }

        if (lst2_busca(l, n) != NULL) {
            l = lst2_retira(l, n);
            printf("Lista após remover %d:\n", n);
            lst2_imprime(l);
        } else {
            printf("O número %d não está na lista.\n", n);
        }
    }

    lst2_libera(l);

    return 0;
}