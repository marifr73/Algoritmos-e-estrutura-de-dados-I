#include <stdio.h>
#include "vetor.h"
#include "lista.h"

int main() {
    printf("Fila usando vetor:\n");
    FilaVetor* fv = fila_vetor_cria();
    fila_vetor_insere(fv, 10.0);
    fila_vetor_insere(fv, 20.0);
    fila_vetor_insere(fv, 30.0);
    fila_vetor_imprime(fv);
    printf("Retirando: %.2f\n", fila_vetor_retira(fv));
    fila_vetor_imprime(fv);
    fila_vetor_libera(fv);

    printf("\nFila usando lista encadeada:\n");
    FilaLista* fl = fila_lista_cria();
    fila_lista_insere(fl, 10.0);
    fila_lista_insere(fl, 20.0);
    fila_lista_insere(fl, 30.0);
    fila_lista_imprime(fl);
    printf("Retirando: %.2f\n", fila_lista_retira(fl));
    fila_lista_imprime(fl);
    fila_lista_libera(fl);

    return 0;
}