#include <stdio.h>
#include "fila.h"

int main() {
    Fila* f_res = fila_cria();
    Fila* f1 = fila_cria();
    Fila* f2 = fila_cria();

    fila_insere(f1, 1.0);
    fila_insere(f1, 3.0);
    fila_insere(f1, 5.0);

    fila_insere(f2, 2.0);
    fila_insere(f2, 4.0);
    fila_insere(f2, 6.0);

    printf("Fila 1 antes da combinação:\n");
    fila_imprime(f1);
    
    printf("Fila 2 antes da combinação:\n");
    fila_imprime(f2);

    combina_filas(f_res, f1, f2);

    printf("Fila 1 e 2 após a combinação:\n");
    fila_imprime(f_res);

    fila_libera(f_res);
    fila_libera(f1);
    fila_libera(f2);

    return 0;
}