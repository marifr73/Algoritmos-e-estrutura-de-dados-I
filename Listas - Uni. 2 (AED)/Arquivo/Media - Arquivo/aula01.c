#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE * open_file(char * nome, char * modo){
    FILE * arquivo = fopen(nome, modo);
    if (arquivo == NULL){
        printf("can´t create file\n");
        exit(1);
    } else{
        printf("File created! \n");
    }
    return arquivo;
}

int main(){
    FILE * arquivo_entrada, * arquivo_saida;
    char Nome[20];
    float n1, n2, n3, media;

    arquivo_entrada = open_file("entrada_q3.txt", "r"); //Ler arquivo entrada
    arquivo_saida = open_file("saida_q3.txt", "w"); //Ler arquivo saida

    // Ler os dados detro do arquivo fgets, fgetc, fscanf, sscanf
    while (!feof(arquivo_entrada)){ //enquanto não chega ao final do arquivo
        fscanf(arquivo_entrada, " %[^\t]\t %f\t %f\t %f", Nome, &n1, &n2, &n3); //Ler os dados do arquivo

        //Calcular media
        media = (n1+n2+n3) / 3.0;

        //Escrever no arquivo da saida
        if(media >= 7){
            fprintf(arquivo_saida, "%s\t%.1f\tAprovado", Nome, media);
        } else{
            fprintf(arquivo_saida, "%s\t%.1f\tReprovado", Nome, media);
        }
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    return 0;
}