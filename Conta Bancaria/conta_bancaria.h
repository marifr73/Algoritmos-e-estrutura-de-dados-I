#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H

typedef struct contabancaria Contabancaria;

/*Função que aloca memoria para struct conta e retorna sem endereço parms:
    char * titular: nome do titular da conta
    double saldo: saldo sisponivel na conta
    int numero: numero da conta
*/
Contabancaria * criar_conta (char *titular, int numero, double saldo);

/*Função que simula a operação de deposita parms: 
    Contabancaria * conta: Representa conta bancaria
    double novo_saldo: saldo para ser adicionado na conta
*/
void deposita (Contabancaria *conta, double novo_saldo);

/*Função que simula a operação de sacar valor de uma conta parms:
    Contabancaria * conta: Representa conta bancaria
    double valor: valor que será decrementado da conta 
*/
void saca (Contabancaria* conta, double valor);

/*Função que simula a  transferencia de valores entre contas parms:
    Contabancaria * conta_origem: Conta de onde o valor será tranferido
    Contabancaria * conta_destino: Conta para onde o valor será recebido
    double valor: Valor que sera transferido
*/
void transfere(Contabancaria *conta_origem, Contabancaria *conta_destino, double valor);

/*Função que simula o retorna o saldo da conta parms:
    Contabancaria * conta: Representa conta bancária
*/
double Saldo (Contabancaria* conta);

/*Função que libera a memória alocada*/
void Excluir_conta (Contabancaria * conta);

#endif