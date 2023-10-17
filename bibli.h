#include <stdio.h>
#include <string.h>
#ifndef UNTITLED2_BIBLI_H
#define UNTITLED2_BIBLI_H
typedef struct{
    char nome[30];
    long CPF;
    char tipo_de_conta[5];
    int valor_inicial;
    char senha[20];

}Cliente;
typedef struct{
    Cliente clientes[1000];
    int qtd;
}ListaDeClientes;

void printMenu();
int cria_cliente(ListaDeClientes *c);

int listar_clientes(ListaDeClientes c);
//int extrato(Lista_de_coisas(ficapradpskkkk));
int salvarCliente(ListaDeClientes c, char nome[]);
int carregarClientes(ListaDeClientes *c,char nome[]);
int debitoCliente(Cliente *c,long valor);
int debito(ListaDeClientes *c);
int depositoCliente(Cliente *c,long valor);
int deposito(ListaDeClientes *c);
int transferencia(ListaDeClientes *c);
int deletar_cliente(ListaDeClientes *c);

#endif //UNTITLED2_BIBLI_H