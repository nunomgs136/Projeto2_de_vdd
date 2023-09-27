#include "bibli.h"
#include <stdio.h>
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
    printf("Digite o seu nome: ");
    scanf("%s", c->clientes[c->qtd].nome);
    printf("Digite o seu CPF: ");
    scanf("%s", c->clientes[c->qtd].CPF);
    printf("Digite o tipo da conta: ");
    scanf("%s", c->clientes[c->qtd].tipo_de_conta);
    printf("Digite o seu nome: ");
    scanf("%s", c->clientes[c->qtd].valor_inicial);
    printf("Digite o seu nome: ");
    scanf("%s", c->clientes[c->qtd].senha);
}