#include<stdio.h>

typedef enum mes{
    Janeiro = 1,
    Fevereiro,
    Marco,
    Abril,
    Maio,
    Junho,
    Julho,
    Agosto,
    Setembro,
    Outubro,
    Novembro,
    Dezembro
}Mes;

typedef struct data{
    int dia;
    int ano;
    Mes mes;
}Data;

void preenchar (Data *d){
    int mes;
    printf("Informe o ano: ");
    scanf("%d", &d->ano);
    printf("Informe o dia: ");
    scanf("%d", &d->dia);
    printf("Informe o mês do ano: 1 - 12\t");
    scanf("%d", &mes);

    d->mes = (Mes)mes;
    
    switch (d->mes){
        case Janeiro:
            printf("\nJANEIRO\n");
            break;
        case Fevereiro:
            printf("\nFEVEREIRO\n");
            break;
        case Marco:
            printf("\nMARÇO\n");
            break;
        case Abril:
            printf("\nABRIL\n");
            break;
        case Maio:
            printf("\nMAIO\n");
            break;
        case Junho:
            printf("\nJUNHO\n");
            break;
        case Julho:
            printf("\nJULHO\n");
            break;
        case Agosto:
            printf("\nAGOSTO\n");
            break;
        case Setembro:
            printf("\nSETEMBRO\n");
            break;
        case Outubro:
            printf("\nOUTUBRO\n");
            break;
        case Novembro:
            printf("\nNOVEMBRO\n");
            break;
        case Dezembro:
            printf("\nDEZEMBRO\n");
            break;
        default:
            printf("\nMês não cadastrado!\n");
            break;
    }
}

void imprima (Data *data){
    printf("---CALENDÁRIO---\n");
    printf("%d/%d/%d", data->dia, data->mes, data->ano);
}

int main(){
    Data data;
    preenchar(&data);
    imprima(&data);
    return 0;
}