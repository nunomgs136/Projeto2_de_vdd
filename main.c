
#include <stdio.h>
#include <string.h>
#include "bibli.h"
int main(){
    int opcao;
    do{
        printMenu;
        
        scanf("%d",&opcao);
        
      
        switch(opcao){
            case 1:
                printf("Criar Cliente\n");
                break;
            case 2:
                printf("Deletar Cliente\n");
                break;
            case 3:
                printf("Listar Clientes\n");
                break;
            case 4:
                printf("Débito\n");
                break;
            case 5:
                printf("Depósito\n");
                break;
            case 6:
                printf("Extrato\n");
                break;
            case 7:
                printf("Transferência entre duas contas\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;    
        }




    }while(opcao!=0);
}