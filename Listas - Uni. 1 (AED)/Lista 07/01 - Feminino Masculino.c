#include <stdio.h>
#include <stdlib.h>

typedef enum genero{
    FEMININO = 1,
    MASCULINO,
    NEUTRO
}GENERO;

typedef struct pessoa{
    char nome[21];
    int idade;
    GENERO genero;
}PESSOA;

void preenchar(PESSOA * fm){
    printf("Informe o seu nome: ");
    scanf(" %[^\n]", fm->nome);
    printf("Informe a sua idade: ");
    scanf("%d", &fm->idade);
    printf("Informe o seu genero: \n1 - Feminino\n2 - Masculino\n3 - NEUTRO\n ");
    scanf("%d", &fm->genero);

    switch (fm->genero){
    case FEMININO:
        printf("FEMININO\n");
        break;
    case MASCULINO:
        printf("MASCULINO\n");
        break;
    case NEUTRO:
        printf("NEUTRO\n");
        break;
    default:
        printf("Genero não informado!");
        break;
    }

}

void imprima (PESSOA * fm){
    printf("NOME: %s\nIDADE: %d\nGENERO: %d", fm->nome, fm->idade, fm->genero);
}

int main(){
    PESSOA fm;

    preenchar(&fm);
    imprima(&fm);

    return 0;
}