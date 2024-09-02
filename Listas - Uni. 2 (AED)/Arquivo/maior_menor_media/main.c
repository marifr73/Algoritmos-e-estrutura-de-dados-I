#include <stdio.h>
#include <stdlib.h>

FILE *abrir_arquivo(char *nome, char *modo) {
    FILE *arquivo = fopen(nome, modo);
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        exit(1);
    }
    return arquivo;
}

int main() {
    FILE *arquivo_entrada, *arquivo_saida;
    int arr[10], i;
    int menor, maior;
    float media, soma = 0;

    arquivo_entrada = abrir_arquivo("entrada_q2.txt", "r");
    arquivo_saida = abrir_arquivo("saida_q2.txt", "w");

    for (i = 0; i < 10; i++) {
        if (fscanf(arquivo_entrada, "%d", &arr[i]) != 1) {
            fprintf(stderr, "Erro na leitura do arquivo de entrada\n");
            fclose(arquivo_entrada);
            fclose(arquivo_saida);
            exit(1);
        }
    }

    fclose(arquivo_entrada);

    menor = maior = arr[0];

    for (i = 0; i < 10; i++) {
        if (arr[i] < menor) {
            menor = arr[i];
        }
        if (arr[i] > maior) {
            maior = arr[i];
        }
        soma += arr[i];
    }

    media = soma / 10;

    fprintf(arquivo_saida, "Menor elemento: %d\n", menor);
    fprintf(arquivo_saida, "Maior elemento: %d\n", maior);
    fprintf(arquivo_saida, "Média dos elementos: %.2f\n", media);

    fclose(arquivo_saida);

    return 0;
}