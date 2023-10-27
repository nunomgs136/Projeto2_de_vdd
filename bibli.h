#include <stdio.h>
#include <string.h>
#ifndef UNTITLED2_BIBLI_H
#define UNTITLED2_BIBLI_H

typedef struct{
    char descricao[13];
    double valor;
    double taxa;
}Extrato;

typedef struct{
    char nome[30];
    long CPF;
    char tipo_de_conta[5];
    double valor_inicial;
    char senha[20];
    Extrato operacoes[100];
    int qtd_extrato;

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
int debitoCliente(Cliente *c,double valor, char tipo[]);
int debito(ListaDeClientes *c);
int depositoCliente(Cliente *c,double valor,char tipo[]);
int deposito(ListaDeClientes *c);
int transferencia(ListaDeClientes *c);
int deletar_cliente(ListaDeClientes *c);
int armazenar_extrato(Cliente *c, char *desc, double valor, double taxa);
int escrever_extrato(ListaDeClientes *c,char nome[]);
int carregarExtrato(ListaDeClientes *c,char nome[]);


#endif //UNTITLED2_BIBLI_H