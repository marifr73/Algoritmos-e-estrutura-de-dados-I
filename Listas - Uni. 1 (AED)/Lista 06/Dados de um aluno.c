#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef union documentos {
    char CPF[16];                  
    int titulo_eleitoral, RG, sus, passaporte;
} Documentos;

typedef struct aluno {
    char nome[21];        
    int mat;
    Documentos documentos;
} Aluno;

void preencher_aluno(Aluno *alunos, int n) {
    int opcao, i;
    for (i = 0; i < n; i++) {
        printf("Informe o nome do aluno %d:\n", i + 1);
        scanf(" %[^\n]", alunos[i].nome);
        getchar();
        printf("Informe a matrícula do aluno %d:\n", i + 1);
        scanf("%d", &alunos[i].mat);
        getchar();


        do {
            printf("\nDOCUMENTOS:\n");
            printf("1 – CPF\n");
            printf("2 – RG\n");
            printf("3 – SUS\n");
            printf("4 – Título Eleitoral\n");
            printf("5 – Passaporte\n");
            printf("6 – Sair\n");
            printf("Digite sua opção: ");
            scanf("%d", &opcao);
            getchar();

            switch (opcao) {
                case 1:
                    printf("\nInforme o CPF:\t");
                    scanf(" %[^\n]", alunos[i].documentos.CPF);
                    getchar();
                    break;
                case 2:
                    printf("\nInforme o RG:\t");
                    scanf("%d", &alunos[i].documentos.RG);
                    getchar();
                    break;
                case 3:
                    printf("\nInforme o SUS:\t");
                    scanf("%d", &alunos[i].documentos.sus);
                    getchar();
                    break;
                case 4:
                    printf("\nInforme o Título Eleitoral:\t");
                    scanf("%d", &alunos[i].documentos.titulo_eleitoral);
                    getchar();
                    break;
                case 5:
                    printf("\nInforme o Passaporte:\t");
                    scanf("%d", &alunos[i].documentos.passaporte);
                    getchar();
                    break;
                case 6:
                    printf("\nObrigado por usar este programa!\n");
                    break;
                default:
                    printf("\nOpção inválida.\n");
                    break;
            }
        } while (opcao != 6);
    }
}

void imprimir_aluno(Aluno *alunos, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Aluno(a): %s\nMatrícula: %d.\n", alunos[i].nome, alunos[i].mat);

        if (alunos[i].documentos.CPF > 0) {
            printf("CPF: %s\n", alunos[i].documentos.CPF);
        } else {
            printf("CPF: Não foi informado!\n");
        }
        
        if (alunos[i].documentos.RG > 0) {
            printf("RG: %d\n", alunos[i].documentos.RG);
        } else {
            printf("RG: Não foi informado!\n");
        }
        
        if (alunos[i].documentos.sus > 0) {
            printf("SUS: %d\n", alunos[i].documentos.sus);
        } else {
            printf("SUS: Não foi informado!\n");
        }
        
        if (alunos[i].documentos.titulo_eleitoral != 0) {
            printf("Título Eleitoral: %d\n", alunos[i].documentos.titulo_eleitoral);
        } else {
            printf("Título Eleitoral: Não foi informado!\n");
        }
        
        if (alunos[i].documentos.passaporte > 0) {
            printf("Passaporte: %d\n", alunos[i].documentos.passaporte);
        } else {
            printf("Passaporte: Não foi informado!\n");
        }
        
        printf("\n");
    }
}

int main(){

    setlocale(LC_ALL, "Portugues");
    int n;
    printf("Informe a quantidade de alunos: ");
    scanf("%d", &n);
    getchar();
    
    Aluno *alunos = (Aluno *)malloc(n * sizeof(Aluno));
    
    preencher_aluno(alunos, n);
    imprimir_aluno(alunos, n);
    
    free(alunos); // Libera a memória alocada
    
    return 0;
}