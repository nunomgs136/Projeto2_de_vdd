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

int deletar_cliente(ListaDeClientes *c){
  long cpf;
  
  printf("Digite o  seu CPF: ");
  scanf("%ld", &cpf);

  for(int i=0; i < c->qtd; i++){

    if(cpf == c->clientes[i].CPF){
      for(int j = 0; j < c->qtd;j++){
         c->clientes[j] = c->clientes[j+1];
         c->qtd-=1;
      }
    }
  }
  
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


int debitoCliente(Cliente *c,long valor){

  if(strcmp(c->tipo_de_conta,"Comum") == 0){
    
    if((c->valor_inicial - valor*1.05) > (-1000)){
         c->valor_inicial =  c->valor_inicial - valor*1.05;
        return 0;
      }else{printf("Saldo insuficiente");
      return 1;}
  }
  else if(strcmp(c->tipo_de_conta,"Plus")==0){
    if((c->valor_inicial - valor*1.03) > (-5000)){
      c->valor_inicial =  c->valor_inicial - valor*1.03;
      return 0;
    }else{printf("Saldo insuficiente");
    return 1;}
  }
}

int debito(ListaDeClientes *c){
//parametro precisa ser ponteiro aparentemente
    char senha [40];
    long cpf;
    int valor;

    printf("Digite o seu cpf: ");
    scanf("%ld", &cpf);
    printf("Digite a senha: ");
    scanf("%s",senha);


    for(int i = 0; i <= c->qtd;i++){
        if((cpf == c->clientes[i].CPF) && strcmp(senha, c->clientes[i].senha)==0){

              printf("Digite o valor que deseja sacar: ");
              scanf("%d",&valor);

            debitoCliente(&c->clientes[i],valor);
        }
    }
return 0;
}

int depositoCliente(Cliente *c,long valor){
  c->valor_inicial = c->valor_inicial + valor;
  return 0;
}

int deposito(ListaDeClientes *c){
    long cpf;
    long valor;
    printf("Digite o seu CPF: ");
    scanf("%ld",&cpf);
    //procura de CPF
    for(int i = 0; i < c->qtd; i++){

        if(cpf == c->clientes[i].CPF){
            printf("Digite um valor para depositar: ");
            scanf("%ld",&valor);
            depositoCliente(&c->clientes[i],valor);
            printf("Seu saldo atual é: %d\n", c->clientes[i].valor_inicial);
            break;
        }
      //caso não for detectado o CPF dentro do for
      else if(i==c->qtd-1){
        printf("CPF não encontrado \n");
        break;
      }
    }
    return 0;
}

int transferencia(ListaDeClientes *c){
  long cpf_origem;
  char senha[40];
  long cpf_destino;
  long valor;
  //comparador se a cliente foi encontrado
  int pos_o=-1;
  int pos_d=-1;

  printf("Digite o seu CPF: ");
  scanf("%ld", &cpf_origem);

  printf("Digite a senha: ");
  scanf("%s", senha);

  for(int i=0; i< c->qtd; i++){
    if((cpf_origem == c->clientes[i].CPF) && strcmp(senha, c->clientes[i].senha)==0){
      pos_o=i;
      printf("Digite o CPF do destinatário: ");
      scanf("%ld",&cpf_destino);

      for(int j=0; j<c->qtd; j++){
        if(cpf_destino==c->clientes[j].CPF){
          pos_d=j;
          printf("Digite o valor que deseja transferir: ");
          scanf("%ld",&valor);
          
            if(debitoCliente(&c->clientes[i], valor)==1){
              printf("Saldo insuficiente");
              break;
            }else{depositoCliente(&c->clientes[j],valor);
                  printf("Transferência realizada com sucesso");
                  break;
                }
          }
      } if(pos_d==-1){
        printf("CPF do destinatario não encontrado");
        return 0;}
        
    }
  }if(pos_o==-1){
    printf("CPF não encontrado");
    return 0;
  }
return 0;}