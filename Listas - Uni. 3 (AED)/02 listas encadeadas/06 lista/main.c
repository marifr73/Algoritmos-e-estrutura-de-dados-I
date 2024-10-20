#include "lista.h"

int main() {
    ListaHet *lista;
    lista = cria_ret(5, 10);
    lista->prox = cria_tri(6, 8);
    lista->prox->prox = cria_circ(4);

    float maior_area = max_area(lista);
    printf("A maior área entre os elementos da lista é: %.2f\n", maior_area);

    ListaHet *tmp;
    while (lista != NULL) {
        tmp = lista;
        lista = lista->prox;
        free(tmp->objeto);
        free(tmp);
    }

    return 0;
}
