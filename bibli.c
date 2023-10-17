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
    printf("%s\n", c->clientes[c->qtd].nome);
    printf("%ld\n", c->clientes[c->qtd].CPF);
    printf("%s\n", c->clientes[c->qtd].tipo_de_conta);
    printf("%d\n", c->clientes[c->qtd].valor_inicial);
    printf("%s\n", c->clientes[c->qtd].senha);
    c->qtd+=1;
    return 0;
}

int salvarCliente(ListaDeClientes c, char nome[]){
    FILE *f = fopen(nome, "wb");

    fwrite(&c, sizeof(ListaDeClientes),1,f);
    fclose(f);
    return 0;
}
int carregarClientes(ListaDeClientes *c, char nome[]){
    FILE *f = fopen(nome, "rb");
    // checagem para ver se o arquivo tem erro ou nao
    if(f == NULL){
        printf("Erro");
        return 1;
    }

    fread(c,sizeof(ListaDeClientes),1,f);
    fclose(f);
    return 0;
}


int listar_clientes(ListaDeClientes c){
    for(int i = 0; i < c.qtd;i++){

        printf("Nome: %s \n",c.clientes[i].nome);
        printf("CPF: %ld \n", c.clientes[i].CPF);
        printf("Tipo: %s \n",c.clientes[i].tipo_de_conta);
        printf("Senha: %s \n",c.clientes[i].senha);
        printf("Saldo: %d \n",c.clientes[i].valor_inicial);
        printf("\n");
    }
    return 0;}


int debito(ListaDeClientes *c){
//parametro precisa ser ponteiro aparentemente
    char senha [40];
    long cpf;
    int valor;

    printf("Digite o seu cpf: ");
    scanf("%ld", &cpf);
    printf("Digite a senha: ");
    scanf("%s",senha);
    printf("Digite o valor que deseja sacar: ");
    scanf("%d",&valor);

    for(int i = 0; i <= c->qtd;i++){
        if((cpf == c->clientes[i].CPF) && strcmp(senha, c->clientes[i].senha)==0){

            //Operção se a conta for Comum
            if(strcmp(c->clientes[i].tipo_de_conta,"Comum") == 0){

                if((c->clientes[i].valor_inicial - valor*1.05) > (-1000)){
                    c->clientes[i].valor_inicial =  c->clientes[i].valor_inicial - valor*1.05;
                    printf("Seu saldo atual é: %d\n", c->clientes[i].valor_inicial);
                }
                else{
                    printf("Saldo insuficiente\n");
                }

            }

                //Operação se a conta for Plus
            else if(strcmp(c->clientes[i].tipo_de_conta,"Plus") == 0){
                if((c->clientes[i].valor_inicial - valor*1.03) > (-5000)){
                    c->clientes[i].valor_inicial = c->clientes[i].valor_inicial -  valor*1.03;
                    printf("Seu saldo atual é: %d\n", c->clientes[i].valor_inicial);
                }
                else{
                    printf("Saldo insuficiente\n");
                }


            }
        }
    }



    return 0;
}

 