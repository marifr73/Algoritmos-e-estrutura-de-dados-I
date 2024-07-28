#include<stdio.h>
#include<stdlib.h>

void lerRespostas(int N, char **sexo, char **opiniao){
    *sexo = (char *) malloc(N * sizeof(char));
    *opiniao = (char *) malloc(N * sizeof(char));
    
    if (*sexo == NULL || *opiniao == NULL) {
        printf("No memory\n");
        exit(1);
    }

    int i;

    for (i = 0; i < N; i++){
        printf("\nDigite o sexo da pessoa %d (M/F): ", i + 1);
        scanf(" %c", &(*sexo)[i]);
        printf("Gostou do produto? (S/N): ");
        scanf(" %c", &(*opiniao)[i]);
    }
}

double calcular_porc_femin_gostou(int N, char *sexo, char *opiniao){
    int totalFeminino = 0;
    int gostaramFeminino = 0;
    int i;

    for (i = 0; i < N; i++){
        if (sexo[i] == 'F' || sexo[i] == 'f'){
            totalFeminino++;
            if (opiniao[i] == 'S' || opiniao[i] == 's'){
                gostaramFeminino++;
            }
        }
    }
    
    if (totalFeminino > 0){
        return (gostaramFeminino * 100.0) / totalFeminino;
    } else {
        return 0;
    }
}

double calcular_porc_masc_nao_gostou(int N, char *sexo, char *opiniao){
    int totalMasculino = 0;
    int naoGostaramMasculino = 0;
    int i;

    for (i = 0; i < N; i++){
        if (sexo[i] == 'M' || sexo[i] == 'm'){
            totalMasculino++;
            if (opiniao[i] == 'N' || opiniao[i] == 'n'){
                naoGostaramMasculino++;
            }
        }
    }
    
    if (totalMasculino > 0) {
        return (naoGostaramMasculino * 100.0) / totalMasculino;
    } else {
        return 0;
    }
}

int main(){
    int N;
    
    printf("\nDigite o número de pessoas entrevistadas: ");
    scanf("%d", &N);
    
    char *sexo;
    char *opiniao;
    
    lerRespostas(N, &sexo, &opiniao);
    
    double pgf = calcular_porc_femin_gostou(N, sexo, opiniao);
    double pngm = calcular_porc_masc_nao_gostou(N, sexo, opiniao);
    
    printf("\nPorcentagem de pessoas do sexo feminino que gostaram do produto: %.2f%%\n", pgf);
    printf("\nPorcentagem de pessoas do sexo masculino que nao gostaram do produto: %.2f%%\n\n", pngm);
    
    free(sexo);
    free(opiniao);
    
    return 0;
}