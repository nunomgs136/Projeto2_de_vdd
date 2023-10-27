//Henrique Hodel Babler - RA: 24.123.079-6
// Nuno Martins Guilhermino da Silva - RA: 24.123.035-8
#include "bibli.h"
#include <stdio.h>
#include <string.h>

int main() {

    int opcao;
    int cod;


    ListaDeClientes c;
    char nome[9] = "Clientes";
    char nome_extrato[] = "extrato.txt";

    cod = carregarClientes(&c,nome);


    if(cod == 1){
        c.qtd = 0;
    }


    do {
        printf("%d\n",c.qtd);
        printMenu();

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cria_cliente(&c);
                break;
            case 2:
                deletar_cliente(&c);
                break;
            case 3:
                listar_clientes(c);
                break;
            case 4:
                debito(&c);

                break;
            case 5:
                deposito(&c);
                break;
            case 6:
                carregarExtrato(&c,nome_extrato);
                break;
            case 7:
                transferencia(&c);
                break;
            case 0:
                printf("Saindo...\n");
                break;
        }

    } while (opcao != 0);
    salvarCliente(c, nome);
    escrever_extrato(&c, nome_extrato);
}
