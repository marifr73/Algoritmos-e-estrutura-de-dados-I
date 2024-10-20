#include "funcionario.h"

int main() {
    ListaFunc* l = lstfunc_cria();
    
    l = lstfunc_insere(l, 'A', 123, "Alice", 5000.0);
    l = lstfunc_insere(l, 'B', 456, "Bob", 6000.0);
    l = lstfunc_insere(l, 'A', 789, "Charlie", 5500.0);
    l = lstfunc_insere(l, 'C', 101, "David", 7000.0);

    printf("Lista de funcionários:\n");
    lstfunc_imprime(l);

    char depto;
    printf("\nDigite o departamento para calcular a folha de pagamento: ");
    scanf("%c", &depto);

    float total = lstfunc_folha_pagto(l, depto);
    printf("Total da folha de pagamento para o departamento %c: %.2f\n", depto, total);

    lstfunc_libera(l);

    return 0;
}