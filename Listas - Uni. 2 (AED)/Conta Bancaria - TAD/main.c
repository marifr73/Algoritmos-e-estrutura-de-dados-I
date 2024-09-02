#include<stdio.h>
#include"conta_bancaria.h"

int main(){
    Contabancaria *conta1 = criar_conta("Maria", 23455, 1000.00);
    Contabancaria *conta2 = criar_conta("João", 67890, 1000.00);

    deposita(conta1, 22500.00);
    saca(conta1, 3000.00);
    Saldo(conta1);

    transfere(conta1, conta2, 2000.00);
    Saldo(conta1);
    Saldo(conta2);

    Excluir_conta(conta1);
    Excluir_conta(conta2);

    return 0;
}