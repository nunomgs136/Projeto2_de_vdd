# Projeto2_de_vdd
Este código foi feito com a intenção de imitar um sistema de banco. Foram feitas as seguintes funções para o total funcionamento do código:

Principais informações para funcionamento das funções:
* Nós armazenamos os clientes em uma lista com as informações de cada cliente
* As informações são armazenadas em apenas um item da lista através de um struct, além de uma lista para criação do extrato de cada cliente
* Existe um número para indentificar a quantidade de clientes, além de outro para a quantidade de operações feitas pelo cliente, ambas feitas para leitura correta das listas e armazenamento de informações em arquivos externos
* É usado um ponteiro chamado c, que serve para representar o struct ListaDeClientes, que mantém todas as informações necessárias para realizar as funções
* É aplicada uma taxa em operações que envolvem retirada de dinheiro da conta(débito e a conta de origem de uma transferência). Se a conta for de tipo Comum, será aplicada uma taxa de 5%, e uma taxa de 3% se for uma conta de tipo Plus.

OBS: Para a seguinte explicação das funções, está escrito a ação de cada função, com o nome da função no código entre parentêses 

1 - Criar Cliente(cria_cliente) - São pedidos dos clientes todos os seus dados necessário para se criar uma conta - Nome, CPF, tipo desejado da conta(Comum ou Plus), valor de dinheiro inicial na conta e a senha para assim criar a conta do usuário.

2 - Deletar Cliente(deletar_cliente) - Para esta função ocorrer, o usuário deve escrever o CPF da conta que deseja deletar. Após isso, a conta é deletada através de uma mudança de informações da próxima conta na lista para a anterior, além de diminuir a variável de quantidade de clientes para impedir a leitura de células vazias da lista. 

3 - Listar Clientes(listar_clientes) - Esta função foi feita para exibir todos os clientes armazenados, através da leitura da lista de clientes.

4 - Débito(debito) - São comparados todas so CPFs e senhas da lista de clientes com o CPF e senha digitados pelo usuário. Se estas informações condizerem com as informações de alguma célula da lista, o usuário pode inserir o valor que será debitado, assim será usado a função debitoCliente, criada para evitar poluição visual, na qual a mesma faz as operações para retirar o dinheiro da conta do cliente. 

5 - Depósito(deposito) - Nesta função é apenas pedido do usuário um CPF. Como na função de débito, foi criada uma função a parte para evitar uma função com muita poluição visual, desta vez sendo chamada de depositoCliente, que ao contrário da função debitoCliente, adiciona dinheiro à conta ao invés de retirar.

6 - Extrato(carregarExtrato) - Após a comparação do CPF e senhas inseridos com os mesmos dentro da lista, são exibidas as mais recentes operações relacionadas à conta, com exibição do tipo de operação feita, o valor inserido pelo cliente antes da operação, e, se for o caso, a taxa da operação.

7 - Transferência entre contas(transferencia) - Após a comparação do CPF e senha da conta de origem e o CPF do destinatário, são usadas as funções debitoCliente e depositoCliente novamente para concluir a transferência.

0 - Sair - Quando é inserido o número 0, o programa se encerra, assim salvando todas as informações que foram salvas durante o seu uso.

Funções adicionais
* salvarCliente - Esta função é usada para salvar todas as informações dos clientes em um arquivo binário chamado "Clientes".
* carregarClientes - Esta função é usada para ler o arquivo de clientes e inserir todas as informações dentro dele de volta à lista de clientes. Se não for detectado um arquivo, o número de clientes(mostrado pela váriavel qtd) é alterado para igualar a 0, caso não tenha clientes.
* armazenar_extrato - Esta função é usada após cada operação para ser armazenada dentro da lista de operações do cliente, sendo salvos o tipo de operação, o valor inserido e a taxa. Caso seja um depósito, a taxa é automaticamente armazenada como 0.
* escrever_extrato - Esta função foi criada para escrever as operações feitas dentro de um arquivo txt chamado "extrato".
* carregarExtrato - Esta função é usada para ler o arquivo de extrato para assim poder ser exibida para o cliente quando for pedido o extrato.
* printMenu - Para simplificação do código principal, foi feita uma função para exibir o menu de cada ação possível do banco e a tecla que deve ser apertada para iniciar cada ação.
