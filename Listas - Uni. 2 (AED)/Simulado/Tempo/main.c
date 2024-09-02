#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 100000

int busca_sequencial(int *entrada, int tamanho) {
    int maior = entrada[0], i;
    for (i = 1; i < tamanho; i++) {
        if (maior < entrada[i]) {
            maior = entrada[i];
        }
    }
    return maior;
}

int busca_binaria(int *entrada, int item, int tamanho) {
    int baixo = 0;
    int alto = tamanho - 1;

    while (baixo <= alto) {
        int meio = (baixo + alto) / 2;
        int chute = entrada[meio];
        if (chute == item) {
            return meio;
        } else if (chute > item) {
            alto = meio - 1;
        } else {
            baixo = meio + 1;
        }
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main(void) {
    int entrada[TAMANHO], i;
    srand(time(NULL));

    for (i = 0; i < TAMANHO; i++) {
        entrada[i] = rand();
    }

    clock_t t1 = clock();
    int maior1 = busca_sequencial(entrada, TAMANHO);
    t1 = clock() - t1;
    printf("\nTempo da busca sequencial: %lf\n", ((double)t1) / (CLOCKS_PER_SEC / 1000));

    clock_t t2 = clock();
    qsort(entrada, TAMANHO, sizeof(int), compare);
    t2 = clock() - t2;
    printf("Tempo de ordenação: %lf\n", ((double)t2) / (CLOCKS_PER_SEC / 1000));

    clock_t t3 = clock();
    int maior2 = busca_binaria(entrada, maior1, TAMANHO);
    t3 = clock() - t3;
    printf("Tempo da busca binária: %lf\n", ((double)t3) / (CLOCKS_PER_SEC / 1000));

    printf("Tempo total da busca binária: %lf\n\n", ((double)(t2 + t3)) / (CLOCKS_PER_SEC / 1000));

    return 0;
}