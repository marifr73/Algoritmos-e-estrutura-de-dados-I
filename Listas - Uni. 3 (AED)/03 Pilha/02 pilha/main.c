#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* p1 = pilha_cria();
    Pilha* p2 = pilha_cria();
    
    pilha_push(&p1, 1.0);
    pilha_push(&p1, 2.0);
    pilha_push(&p1, 3.0);
    
    pilha_push(&p2, 4.0);
    pilha_push(&p2, 5.0);
    pilha_push(&p2, 6.0);

    printf("Pilha p1:\n");
    pilha_imprime(p1);
    
    printf("Pilha p2:\n");
    pilha_imprime(p2);

    printf("\nTopo de p1: %.2f\n", topo(&p1));
    printf("Topo de p2: %.2f\n", topo(&p2));
    
    concatena_pilhas(&p1, &p2);
    
    printf("\nPilha p1 após concatenação:\n");
    pilha_imprime(p1);
    
    while (!pilha_vazia(p1)) {
        printf("%.2f\n", pilha_pop(&p1));
    }
    
    pilha_libera(p1);
    pilha_libera(p2);
    
    return 0;
}
