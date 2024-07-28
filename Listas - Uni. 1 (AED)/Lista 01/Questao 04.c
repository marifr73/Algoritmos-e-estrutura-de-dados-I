#include<stdio.h>
#include<locale.h>
#include<math.h>

void calcula_hexagono(float l, float *area, float *perimetro);

int main() {
    setlocale(LC_ALL, "Portuguese");
    float l, a, p;
    printf("Informe o lado do Hexágono: ");
    scanf("%f", &l);
    calcula_hexagono(l, &a, &p);
    printf("Área do hexágono é: %.2f\n", a);
    printf("Perímetro do hexágono é: %.2f\n", p);
    return 0;
}

void calcula_hexagono(float l, float *area, float *perimetro){
    *area = (3 * pow(l, 2) * sqrt(3)) / 2;
    *perimetro = 6 * l;
}