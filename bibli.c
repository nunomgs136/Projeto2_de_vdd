#include "bibli.h"
#include <stdio.h>
#include <string.h>
void printMenu(){
    printf("Menu: \n");
    printf("1. Criar Cliente\n");
    printf("2. Deletar Cliente\n");
    printf("3. Listar Clientes\n");
    printf("4. Débito\n");
    printf("5. Depósito\n");
    printf("6. Extrato\n");
    printf("7. Transferência Entre Contas\n");
    printf("0. Sair\n");
  
}
int cria_cliente(ListaDeClientes *c){
    printf("Digite o seu nome(Apenas use seu primeiro nome): ");
    
    scanf("%s", c->clientes[c->qtd].nome);
    printf("Digite o seu CPF: ");
    scanf("%ld", &c->clientes[c->qtd].CPF);
    printf("Digite o tipo da conta(Comum ou Plus): ");
    scanf("%s", c->clientes[c->qtd].tipo_de_conta);
    printf("Digite o valor inicial da conta: ");
    scanf("%d", &c->clientes[c->qtd].valor_inicial);
    printf("Digite a sua senha: ");
    scanf("%s", c->clientes[c->qtd].senha);
    //Prints para checar funcionamento
    printf("%s\n", c->clientes[c->qtd].nome);
    printf("%ld\n", c->clientes[c->qtd].CPF);
    printf("%s\n", c->clientes[c->qtd].tipo_de_conta);
    printf("%d\n", c->clientes[c->qtd].valor_inicial);
    printf("%s\n", c->clientes[c->qtd].senha);
    c->qtd+=1;
    return 0;
}


