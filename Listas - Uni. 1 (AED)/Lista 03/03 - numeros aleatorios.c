#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void possitivo_ou_nao (int *n){
    if(*n > 0){
        printf("O número é positivo! \n");
    }

    else{
        printf ("O número informado não é positivo informe um novo número!");
        do{
            printf("\nInforme um novo número: ");
            scanf("%d", &*n);
        } while (*n < 0);
    }  
}

int **aloca_matriz(int n1, int n2){
    int i;
    int **matriz = (int **)malloc(n1 * sizeof(int *));
    if(matriz == NULL){exit(1);}

    for (i = 0; i < n1; i++) {
        matriz[i] = (int *)malloc(n2 * sizeof(int));
        if(matriz [i] == NULL){exit(1);}
    }
        return matriz;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    /*(unsigned int n) = força somente ao uso de números positivos!*/
    int i, n, j;

    printf("Informe um número positivo: ");
    scanf("%d", &n);

    //Conferir se o número e Possitivo ou não
    possitivo_ou_nao(&n);

    //Alocar a Matriz
    int **matriz = aloca_matriz(n, n);

    //gerar números aleatorios
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100;
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar a memória alocada
    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }

    free(matriz);
    return 0;
}