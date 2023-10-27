#include "bibli.h"
#include <stdio.h>
#include <string.h>

void printMenu(){
  //Mostra para o cliente as opções de escolha do hub inicial
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
  //Pegas as inormções de cadastro do novo cliente: 
    //Nome:
    printf("Digite o seu nome(Apenas use seu primeiro nome): ");
    scanf("%s", c->clientes[c->qtd].nome);
  
    //CPF:
    printf("Digite o seu CPF: ");
    scanf("%ld", &c->clientes[c->qtd].CPF);
  
    //Tipo de conta:
    printf("Digite o tipo da conta(Comum ou Plus): ");
    scanf("%s", c->clientes[c->qtd].tipo_de_conta);
  
    //Saldo inicial:
    printf("Digite o valor inicial da conta: ");
    scanf("%lf", &c->clientes[c->qtd].valor_inicial);
  
    //Senha do usuario:
    printf("Digite a sua senha: ");
    scanf("%s", c->clientes[c->qtd].senha);
  
    printf("%s\n", c->clientes[c->qtd].nome);
    printf("%ld\n", c->clientes[c->qtd].CPF);
    printf("%s\n", c->clientes[c->qtd].tipo_de_conta);
    printf("%lf\n", c->clientes[c->qtd].valor_inicial);
    printf("%s\n", c->clientes[c->qtd].senha);
  
  //Incrementa 1 a quantidade de clientes cadastrados
    c->qtd++;
    return 0;
}

int salvarCliente(ListaDeClientes c, char nome[]){
  //Abre o arquivo binario para salva os dados do cliente
    FILE *f = fopen(nome, "wb");
  //Armazena os dados no arquivo 
    fwrite(&c, sizeof(ListaDeClientes),1,f);
    fclose(f);
    return 0;
}

int armazenar_extrato(Cliente *c, char *desc, double valor, double taxa){
  //Aloca as informações fornecidas no parameto dentro do array de extrado do cliente
    strcpy(c->operacoes[c->qtd_extrato].descricao, desc);
    c->operacoes[c->qtd_extrato].valor = valor;
    c->operacoes[c->qtd_extrato].taxa = taxa;
  //Incrementa 1 a quantidade de operações feitas no extrato
    c->qtd_extrato++;
    return 0;
}

int deletar_cliente(ListaDeClientes *c){
    long cpf;
  //Pega o cpf do cliente que deseja deletar
    printf("Digite o  seu CPF: ");
    scanf("%ld", &cpf);

    for(int i=0; i < c->qtd; i++){

      if(cpf == c->clientes[i].CPF){
        //Substitui o ciente encontrado pelo próximo cliente do array
        for(int j = 0; j < c->qtd;j++){
          c->clientes[j] = c->clientes[j+1];
        //Decrementa 1 a quantidade de clientes cadastrados para não ocorrer problemas 
         
            }
           c->qtd-=1;
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
    //leitura do arquivo
    fread(c,sizeof(ListaDeClientes),1,f);
    fclose(f);
    return 0;
}


int listar_clientes(ListaDeClientes c){
    for(int i = 0; i < c.qtd;i++){
        //informações da array do cliente 
        printf("Nome: %s \n",c.clientes[i].nome);
        printf("CPF: %ld \n", c.clientes[i].CPF);
        printf("Tipo: %s \n",c.clientes[i].tipo_de_conta);
        printf("Senha: %s \n",c.clientes[i].senha);
        printf("Saldo: %.2lf \n",c.clientes[i].valor_inicial);
        printf("\n");
    }
    return 0;}


int debitoCliente(Cliente *c,double valor,char tipo[]){
    //Analiza se a conta do cliente fornecido no parametro é Comum ou Plus
    if(strcmp(c->tipo_de_conta,"Comum") == 0){
        //Faz a operção de debito no cliente Comum dentro do limite da conta
        if((c->valor_inicial - valor*1.05) > (-1000)){
            c->valor_inicial =  c->valor_inicial - valor*1.05;
            //Anexa a operação feita no extrato do cliente
            armazenar_extrato(c,tipo, -valor, valor*0.05);
            return 0;

        }//Aviso caso o debito da conta passe o limite
        else{printf("Saldo insuficiente");
            return 1;}
    }
    else if(strcmp(c->tipo_de_conta,"Plus")==0){
        //Faz a operção de debito no cliente Plus dentro do limite da conta
        if((c->valor_inicial - valor*1.03) > (-5000)){
            c->valor_inicial =  c->valor_inicial - valor*1.03;
            //Anexa a operação feita no extrato do cliente
            armazenar_extrato(c, tipo, -valor, valor*0.03);
            return 0;

        }//Aviso caso o debito da conta passe o limite
        else{printf("Saldo insuficiente");
            return 1;}
    }
}

int debito(ListaDeClientes *c){
    char tipo[] = "Debito";
    char senha [40];
    long cpf;
    double valor;
    //Pede as informações de CPF e senha para o cliente fazer o debito
    printf("Digite o seu cpf: ");
    scanf("%ld", &cpf);
    printf("Digite a senha: ");
    scanf("%s",senha);


    for(int i = 0; i <= c->qtd;i++){
      //Acessar a conta do cliente para fazer o debito 
      if((cpf == c->clientes[i].CPF) && strcmp(senha, c->clientes[i].senha)==0){
        //pedir o valor do debito
        printf("Digite o valor que deseja sacar: ");
        scanf("%lf",&valor);
        //cham a função q executa o debito da conta
        debitoCliente(&c->clientes[i],valor,tipo);
         break;    
      }//caso não achar cliente com o CPF e senha dados
      else if(i == c->qtd){
        printf("CPF ou senha incorretos");
        }
    }
    return 0;
}

int depositoCliente(Cliente *c,double valor,char tipo[]){
     //Anexa a operação feita no extrato do cliente
    armazenar_extrato(c, tipo, valor, valor*0);
    //Faz a operação de depositar na conta 
    c->valor_inicial = c->valor_inicial + valor;
    return 0;
}

int deposito(ListaDeClientes *c){
    char tipo[] = "Deposito";
    long cpf;
    double valor;
  //Pede o CPF da conta q vai der depositada
    printf("Digite o seu CPF: ");
    scanf("%ld",&cpf);
    
    for(int i = 0; i < c->qtd; i++){
        //procura de CPF dentro da array de clientes
        if(cpf == c->clientes[i].CPF){
            //pede o valor a ser depositado
            printf("Digite um valor para depositar: ");
            scanf("%lf",&valor);
          //Chama a funçãao q vai efetuar a deposito na conta
            depositoCliente(&c->clientes[i],valor,tipo);
          //Mostra o saldo do cliente depois de fazer a operação
            printf("Seu saldo atual é: %.2lf\n", c->clientes[i].valor_inicial);
            break;
        }
            //caso não for detectado o CPF dentro do for
        else if(i==c->qtd-1){
          printf("CPF não encontrado \n");
        }
    }
    return 0;
}

int transferencia(ListaDeClientes *c){
    long cpf_origem;
    char senha[40];
    long cpf_destino;
    double valor;
    char tipo[] ="Trasferencia";
    //comparador se a cliente foi encontrado
    int pos_o=-1;
    int pos_d=-1;

  //Pede o CPF e senha da conta origemda transferencia 
    printf("Digite o seu CPF: ");
    scanf("%ld", &cpf_origem);

    printf("Digite a senha: ");
    scanf("%s", senha);

    for(int i=0; i< c->qtd; i++){
      //Acessa a conta origem
        if((cpf_origem == c->clientes[i].CPF) && strcmp(senha, c->clientes[i].senha)==0){
          //Verifica q a conta origem foi acessada
            pos_o=i;
          //Pede o CPF da conta destino 
            printf("Digite o CPF do destinatário: ");
            scanf("%ld",&cpf_destino);

            for(int j=0; j<c->qtd; j++){
              //Confere se a conta do destinatario existe
                if(cpf_destino==c->clientes[j].CPF){
                  //verifica que a conta do destinatário existe
                    pos_d=j;
                    printf("Digite o valor que deseja transferir: ");
                    scanf("%lf",&valor);
                  //verifica se o saldo do cliente é o suficiente
                    if(debitoCliente(&c->clientes[i], valor, tipo)==1){
                        printf("Saldo insuficiente");
                        break;
                    }else{depositoCliente(&c->clientes[j],valor,tipo);
                        printf("Transferência realizada com sucesso");
                        break;
                    }
                }
              //se não for encontrado o cpf do destinatário
            } if(pos_d==-1){
                printf("CPF do destinatario não encontrado");
                return 0;}

        }//se não for encontrado o cpf da origem
    }if(pos_o==-1){
        printf("CPF não encontrado");
        return 0;
    }
    return 0;}

int escrever_extrato(ListaDeClientes *c, char nome[]){
    FILE *f = fopen(nome, "w");
    
    for(int i=0; i<c->qtd; i++){
      //escreve cada operação escrita dentro do array de cada cliente no arquivo
        for(int j=0; j<c->clientes[i].qtd_extrato; j++){
            printf("tipo: %s valor: %.2lf taxa: %.2lf\n", c->clientes[i].operacoes[j].descricao, c->clientes[i].operacoes[j].valor, c->clientes[i].operacoes[j].taxa);

            fprintf(f,"Tipo: %s | Valor: %.2lf | Taxa: %.2lf | Saldo: %.2lf\n", c->clientes[i].operacoes[j].descricao, c->clientes[i].operacoes[j].valor, c->clientes[i].operacoes[j].taxa, c->clientes[i].valor_inicial);
        }
    }

    fclose(f);
    return 0;
}


int carregarExtrato(ListaDeClientes *c,char nome[]){
    long cpf;
    char senha[40];
    int pular_linhas=0;
  
    printf("Digite seu cpf: ");
    scanf("%ld", &cpf);

    printf("Digite sua senha: ");
    scanf("%s", senha);
    //contador de quantas linhas deve pular no arquivo do extrato para achar a operações do cliente 
    for(int i=0; i<c->qtd; i++){
        pular_linhas+=c->clientes[i].qtd_extrato;

        if((cpf == c->clientes[i].CPF) && (strcmp(senha, c->clientes[i].senha)==0)){
          //remove o número de tamanho do extrato do cliente para não imprimir o extrato do próximo cliente
            pular_linhas-=c->clientes[i].qtd_extrato;

            FILE *f = fopen(nome,"r");
            char l[255];

            for(int p=0; p<pular_linhas;p++){
                fgets(l,250,f);
            }
            printf("%d\n",pular_linhas);
            for(int i=c->clientes[i].qtd_extrato-1; i>=0;i--){
                //imprime etxrato
                fgets(l,250,f);
                printf("%s\n", l);
            }
            fclose(f);
            break;
        }
    }
}

