#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
    char alimento[30];
    char bebida[30];
    char eletronico[30];
} TipoProduto;

typedef struct {
    char nome[100];
    float preco;
    TipoProduto tipo;
    char tipoDescricao[30]; // Campo para armazenar o tipo como string
} Produto;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para preencher as informações do produto
void preencherProduto(Produto *p) {
    int opcao;
    printf("Informe o nome do produto: ");
    scanf(" %[^\n]", p->nome);
    limpar_buffer();

    printf("Informe o preço do produto: ");
    scanf("%f", &p->preco);

    printf("Informe o tipo do produto (1 - ALIMENTO, 2 - BEBIDA, 3 - ELETRONICO): ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            strcpy(p->tipoDescricao, "ALIMENTO");
            printf("Informe o nome do alimento: ");
            scanf(" %[^\n]", p->tipo.alimento);
            limpar_buffer(); 
            break;
        case 2:
            strcpy(p->tipoDescricao, "BEBIDA");
            printf("Informe o nome da bebida: ");
            scanf(" %[^\n]", p->tipo.bebida);
            limpar_buffer();
            break;
        case 3:
            strcpy(p->tipoDescricao, "ELETRONICO");
            printf("Informe o nome do eletrônico: ");
            scanf(" %[^\n]", p->tipo.eletronico);
            limpar_buffer();
            break;
        default:
            printf("Opção inválida!\n");
            exit(1);
    }
}

// Função para imprimir os dados do produto
void imprimirProduto(const Produto *p) {
    printf("\n--- Dados do Produto ---\n");
    printf("Nome: %s\n", p->nome);
    printf("Preço: %.2f\n", p->preco);
    printf("Tipo: %s\n\n", p->tipoDescricao);

    /*A função strcmp é usada para comparar duas strings (sequências de caracteres). Ela está definida na biblioteca <string.h>*/
    if (strcmp(p->tipoDescricao, "ALIMENTO") == 0) {
        printf("Nome do Alimento: %s\n", p->tipo.alimento);
    } else if (strcmp(p->tipoDescricao, "BEBIDA") == 0) {
        printf("Nome da Bebida: %s\n", p->tipo.bebida);
    } else if (strcmp(p->tipoDescricao, "ELETRONICO") == 0) {
        printf("Nome do Eletrônico: %s\n", p->tipo.eletronico);
    }
}

int main() {
    Produto p;

    preencherProduto(&p);
    imprimirProduto(&p);

    return 0;
}