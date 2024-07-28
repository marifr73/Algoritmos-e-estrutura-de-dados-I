#include<stdio.h>

int main(void) {
int x, *p;
x = 100;
p = &x;
printf("Valor de p = %p\tValor de *p = %d", p, *p);
return 0;
}

//a) Esta mensagem é de erro ou advertência?
// Resposta: Erro
//b) Por que o compilador emite tal mensagem?
// Resposta: O endereço da variável que ele apontará não foi colocado &x
//c) Compile e execute o programa. A execução foi bem sucedida?
// Resposta: Não
//d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida pelo compilador.
// Resposta: Modificado
//e) Compile e execute novamente o programa. A execução foi bem sucedida?
// Resposta: Sim
