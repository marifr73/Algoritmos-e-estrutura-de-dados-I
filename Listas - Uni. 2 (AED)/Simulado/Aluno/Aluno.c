#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int idade;
    char nome[50];
    float n1, n2, n3, media;
} Aluno;

FILE *abreArquivo(char *nome, char *modo) {
    FILE *arquivo = fopen(nome, modo);
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    return arquivo;
}

int comparaDecrescente(const void *a, const void *b) {
    float mediaA = ((Aluno *)a)->media;
    float mediaB = ((Aluno *)b)->media;

    if (mediaA < mediaB) return 1;
    if (mediaA > mediaB) return -1;
    return 0;
}

int main() {
    Aluno vet[100];
    int i = 0, numAlunos = 0;
    FILE *arquivoEntrada, *arquivoSaida;

    arquivoEntrada = abreArquivo("entrada.txt", "r");
    arquivoSaida = abreArquivo("resultados.txt", "w");

    while (fscanf(arquivoEntrada, " %[^ \t]%*c %d %f %f %f\n", vet[i].nome, &vet[i].idade, &vet[i].n1, &vet[i].n2, &vet[i].n3) == 5) {
        vet[i].media = (vet[i].n1 + vet[i].n2 + vet[i].n3) / 3;
        i++;
    }
    numAlunos = i;

    qsort(vet, numAlunos, sizeof(Aluno), comparaDecrescente);

    for (i = 0; i < numAlunos; i++) {
        printf("Nome: %s\nIdade: %d\nMedia: %.1f\n", vet[i].nome, vet[i].idade, vet[i].media);
        fprintf(arquivoSaida, "Nome: %s\nIdade: %d\nMedia: %.1f\n\n", vet[i].nome, vet[i].idade, vet[i].media);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    return 0;
}
