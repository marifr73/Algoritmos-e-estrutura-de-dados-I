#include <stdio.h>
#include <stdlib.h>

#define NUMERO_MAXIMO_DE_ALUNOS 10

int numero_de_questoes(){
    int N;
    printf("Informe quantas questões há na prova: ");
    scanf("%d", &N);
    return N;
}

char* gabarito(int N){
    char *gabarito = (char *)malloc((N + 1) * sizeof(char));
    printf("Digite o gabarito da prova: ");
    scanf("%s", gabarito);
    return gabarito;
}

void respostas_dos_alunos(char respostas[NUMERO_MAXIMO_DE_ALUNOS][100], int N){
    int i;
    for (i = 0; i < NUMERO_MAXIMO_DE_ALUNOS; i++) {
        printf("Digite as respostas do aluno %d: ", i + 1);
        scanf("%s", respostas[i]);
    }
}

void calcular_notas(float notas[NUMERO_MAXIMO_DE_ALUNOS], char respostas[NUMERO_MAXIMO_DE_ALUNOS][100], char *gabarito, int N, int *alunos_aprovados){
    int i, j;
    for (i = 0; i < NUMERO_MAXIMO_DE_ALUNOS; i++) {
        int acertos = 0;
        for (j = 0; j < N; j++) {
            if (respostas[i][j] == gabarito[j]){
                acertos++;
            }
        }
        notas[i] = (10.0 / N) * acertos;
        if (notas[i] >= 6.0) {
            (*alunos_aprovados)++;
        }
    }
}

void exibir_notas(float notas[NUMERO_MAXIMO_DE_ALUNOS]){
    int i;
    printf("\nA nota dos aludos são: \n");
    for (i = 0; i < NUMERO_MAXIMO_DE_ALUNOS; i++) {
        printf("Nota do aluno %d: %.2f\n", i + 1, notas[i]);
    }
}

void porcentagem_aprovacao(int alunos_aprovados){
    float porcentagem = (alunos_aprovados / (float)NUMERO_MAXIMO_DE_ALUNOS) * 100;
    printf("Porcentagem de aprovação: %.2f%%\n", porcentagem);
}

int main(){
    int N = numero_de_questoes();
    char *gabarito_prova = gabarito(N);
    char respostas[NUMERO_MAXIMO_DE_ALUNOS][100];
    float notas[NUMERO_MAXIMO_DE_ALUNOS];
    int alunos_aprovados = 0;

    //ler as respostas dos alunos
    respostas_dos_alunos(respostas, N);

    //calcular as notas dos alunos
    calcular_notas(notas, respostas, gabarito_prova, N, &alunos_aprovados);

    //exibir as notas dos alunos
    exibir_notas(notas);

    //exibir a porcentagem de aprovação
    porcentagem_aprovacao(alunos_aprovados);

    free(gabarito_prova);
    return 0;
}