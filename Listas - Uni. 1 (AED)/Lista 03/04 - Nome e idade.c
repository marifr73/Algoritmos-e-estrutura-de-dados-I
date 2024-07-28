/*Aqui estão as especicações do programa:
- O programa deve começar solicitando ao usuário o número de pessoas que deseja armazenar.
- Em seguida, o programa deve pedir ao usuário que digite o nome completo de cada pessoa.
- Os nomes devem ser armazenados em uma matriz alocada dinamicamente.
- Após o nome, o programa deve solicitar a idade da pessoa.
- As idades devem ser armazenadas em um vetor alocado dinamicamente.
- Após a entrada de todos os nomes e idades, o programa deve exibir os nomes armazenados.
- Certique-se de tratar adequadamente a alocação dinâmica de memória e liberar a memória
alocada corretamente após o uso.
Observação: O programa deve ser capaz de armazenar até 100 nomes completos.*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO_NOME 100

int i;

void alocar_memoria(int np, char ***nomes, int **idades) {
    *nomes = (char **)malloc(np * sizeof(char *));
    for (i = 0; i < np; i++) {
        (*nomes)[i] = (char *)malloc(TAMANHO_MAXIMO_NOME * sizeof(char));
    }
    *idades = (int *)malloc(np * sizeof(int));
}

void ler_dados(int np, char **nomes, int *idades) {
    for (i = 0; i < np; i++) {
        printf("Digite o nome completo da %dº pessoa: ", i + 1);
        scanf(" %[^\n]", nomes[i]);
        printf("Digite a idade da %dº pessoa: ", i + 1);
        scanf("%d", &idades[i]);
    }
}

void exibir_dados(int np, char **nomes, int *idades) {
    printf("\nNomes e idades informados:\n");
    for (i = 0; i < np; i++) {
        printf("%dº Pessoa:\n Nome: %s, Idade: %d\n", i + 1, nomes[i], idades[i]);
    }
}

int main() {
    int np;
    char **nomes;
    int *idades;

    // Solicitar o número de pessoas
    printf("Digite o número de pessoas: ");
    scanf("%d", &np);

    // Alocar memória para nomes e idades
    alocar_memoria(np, &nomes, &idades);

    // Ler os dados das pessoas
    ler_dados(np, nomes, idades);

    // Exibir os dados das pessoas
    exibir_dados(np, nomes, idades);

    // Liberar a memória alocada
    for (i = 0; i < np; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(idades);

    return 0;
}