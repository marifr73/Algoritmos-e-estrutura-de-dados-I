/*Implemente um programa em C que solicite ao usuário o número de linhas e colunas de uma matriz e,
em seguida, aloque dinamicamente memória para armazenar essa matriz. Peça ao usuário que insira
os elementos da matriz e, por fim, imprima a matriz na forma original e transposta.*/

#include<stdio.h>
#include<stdlib.h>

int **aloca_matriz(int x, int y){
    int i;
    int **matriz = (int **)malloc(x * sizeof(int *));
    if(matriz == NULL){exit(1);}

    for (i = 0; i < x; i++) {
        matriz[i] = (int *)malloc(y * sizeof(int));
        if(matriz [i] == NULL){exit(1);}
    }
        return matriz;
}

void preencher_matriz(int x, int y, int **matriz){
    printf("\n Informe os elementos da matriz:\n");
    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimir_matriz_original(int x, int y, int **matriz){
    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            printf("%d \t", matriz[i][j]);
        }
        printf("\n");
    }
}

void matriz_transposta(int x, int y, int **matriz){
    int i, j;
    for (i = 0; i < y; i++) {
        for (j = 0; j < x; j++) {
            printf("%d \t", matriz[j][i]);
        }
        printf("\n");
    }
}

int main(void){

    int x, y;

    printf("Digite o numero de linhas: ");
    scanf("%d", &x);
    printf("Digite o numero de colunas: ");
    scanf("%d", &y);

    // Aloca a Matriz
    int **matriz = aloca_matriz(x, y);
    
    //Elementos da Matriz
    preencher_matriz (x, y, matriz);

    //Imprimir a Matriz original
    printf("\nMatriz Original: \n");
    imprimir_matriz_original (x, y, matriz);

    //Imprimir a Matriz transposta
    printf("\nMatriz Transposta: \n");
    matriz_transposta (x, y, matriz);

    int i;
    // Libera a memória alocada de x e y
    for (i = 0; i < x; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}