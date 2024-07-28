#include <stdio.h>
#include <stdlib.h>

int contar_costa(char **mapa, int m, int n) {
    int costa = 0, i, j;

    // Verificar todas as posições do mapa para contar as áreas da costa
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (mapa[i][j] == '#') {
                
                // Verificar o resto do mapa
                if ((i > 0 && mapa[i-1][j] == '.') || 
                    (i < m - 1 && mapa[i+1][j] == '.') || 
                    (j > 0 && mapa[i][j-1] == '.') || 
                    (j < n - 1 && mapa[i][j+1] == '.')) {
                    costa++;
                }
            }
        }
    }
    return costa;
}

int main() {
    int m, n, i, costa;

    // Loop para garantir que as linhas e colunas estejam dentro do intervalo permitido
    do {
        printf("Informe o número de linhas e colunas do mapa: ");
        scanf("%d %d", &m, &n);
        if (m < 1 || m > 1000 || n < 1 || n > 1000) {
            printf("Os valores de linha e coluna devem estar entre 1 e 1000. Tente novamente.\n");
        }
    } while (m < 1 || m > 1000 || n < 1 || n > 1000);

    // Alocar memória para o mapa
    char **mapa = malloc(m * sizeof(char *));
    for (i = 0; i < m; i++) {
        mapa[i] = malloc((n + 1) * sizeof(char));
    }

    // Ler o mapa
    printf("\nInforme o mapa :\n( . ) para agua e ( # ) para terra:\n");
    for (i = 0; i < m; i++) {
        scanf("%s", mapa[i]);
    }

    // Calcula e exibe o tamanho da costa
    costa = contar_costa(mapa, m, n);
    printf("O tamanho da costa é: %d\n", costa);

    // Liberar memória alocada
    for (i = 0; i < m; i++) {
        free(mapa[i]);
    }
    free(mapa);

    return 0;
}