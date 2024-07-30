/* Arquivo cabeçalho para tipo abstrato de dados (TAD) Aluno */

/* Tipo exportado */
typedef struct aluno Aluno;

/* Função que aloca dinâmicamente uma struct Aluno na memória */

Aluno * aloca_aluno(void);

/* Função para preencher uma struct Aluno. A função recebe um endereço para aluno */

void preenche (Aluno * aluno);

/* Função para imprimir uma struct Aluno. A função recebe um endereço para aluno e imprimir os dados */

void imprime (Aluno * aluno);