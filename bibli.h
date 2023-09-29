#include <stdio.h>
#ifndef UNTITLED2_BIBLI_H
#define UNTITLED2_BIBLI_H
typedef struct{
    char nome[300];
    long CPF;
    char tipo_de_conta[5];
    int valor_inicial;
    char senha[300];

}Cliente;
typedef struct{
    Cliente clientes[1000];
    int qtd;
}ListaDeClientes;

void printMenu();
int cria_cliente(ListaDeClientes *c);

#endif //UNTITLED2_BIBLI_H