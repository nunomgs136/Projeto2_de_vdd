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
int deleta_cliente(ListaDeClientes *c);
int listar_clientes(ListaDeClientes *c);
//int extrato(Lista_de_coisas(ficapradpskkkk));
int salvarCliente(ListaDeClientes c, char nome[]);
int carregarClientes(ListaDeClientes *c,char nome[]);
#endif //UNTITLED2_BIBLI_H