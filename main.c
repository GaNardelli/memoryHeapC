#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id_cliente;
    char nome[30];
    int ano_nascimento;
    double montante_contas;

} Cliente;
Cliente *pt;
int size = 10;

void show_menu(){
    printf("1 - Cadastrar Cliente\n");
    printf("2 - Remover Cliente\n");
    printf("3 - Atualizar Montante de Compras\n");
    printf("4 - Zerar todos os Montantes\n");
    printf("5 - Listar o cliente melhor comprador\n");
    printf("6 - Exibir montante de um comprador específico\n");
    printf("7 - Listar todos os clientes\n");
}

void remover_cliente_by_id(int id_selecionado) {
    pt[id_selecionado].id_cliente = -1;
    pt = realloc(pt, size);
}

void incluir_novo_cliente(id_cliente){
    pt[id_cliente].id_cliente = id_cliente;
    printf("\nInsira o nome do cliente: ");
    scanf("%s", pt[id_cliente].nome);
    printf("\nInsira o ano de nascimento: ");
    scanf("%d", &pt[id_cliente].ano_nascimento);
}


int main() {
    // criações de variáveis iniciais
    // Separa um inicial de 10 elementos em memória
    pt = malloc(sizeof(Cliente) * size);
    int keep_runing = 1;
    int id_cliente = 0;

    while (keep_runing == 1) {
        int operacao;
        printf("Qual operação deseja realizar?\n");
        show_menu();
        scanf("%d", &operacao);
        system("clear");
        // cadastrar novo cliente
        switch (operacao){
            case 1:
                if (pt == NULL) {
                    size = size + 10;
                    pt = realloc(pt, size);
                    if (pt == NULL) {
                        printf("\Erro ao armazenar mais informações");
                        break;
                    }
                }
                incluir_novo_cliente(id_cliente);
                id_cliente = id_cliente + 1;
                system("clear");
                break;
            case 2:
                int id_remocao;
                printf("\nQual cliente deseja remover?\n");
                scanf("%d", &id_remocao);
                remover_cliente_by_id(id_remocao);
                id_cliente = id_cliente - 1;
                for (int i = 0 ; i < id_cliente; i++){
                    if (pt[i].id_cliente > id_remocao) {
                        pt[i].id_cliente = pt[i].id_cliente - 1;
                    }
                }
                system("clear");
                break;
            case 3:
                float montante_compra;
                int cliente_selecionado_adicionar, opcao_montante;
                printf("\nPara qual cliente deseja adicionar o montante de compra? (Insira o ID do cliente)");
                scanf("%d", &cliente_selecionado_adicionar);
                printf("\nVoce deseja 1 - Adicionar ou 2 - Subtrair? (Insira o ID do cliente)");
                scanf("%d", &opcao_montante);
                if (opcao_montante == 1) {
                    printf("\nInsira o valor que deseja adicionar para %s - ID: %d ", &pt[cliente_selecionado_adicionar].nome, pt[cliente_selecionado_adicionar].id_cliente);
                    printf("\nMontante: ");
                    scanf("%f", &montante_compra);
                    pt[cliente_selecionado_adicionar].montante_contas = pt[cliente_selecionado_adicionar].montante_contas + montante_compra;
                } else if (opcao_montante == 2) {
                    printf("\nInsira o valor que deseja subtrair para %s - ID: %d ", &pt[cliente_selecionado_adicionar].nome, pt[cliente_selecionado_adicionar].id_cliente);
                    printf("\nMontante: ");
                    scanf("%f", &montante_compra);
                    pt[cliente_selecionado_adicionar].montante_contas = pt[cliente_selecionado_adicionar].montante_contas - montante_compra;
                }
                break;
            case 4:
                int opcao_zerar;
                printf("\nTem certeza que deseja zerar todos os montantes?\n 1- Sim \n 2 - Não");
                scanf("&d", &opcao_zerar);
                if(opcao_zerar == 1) {
                    for (int i = 0 ; i < id_cliente; i++){
                        pt[i].montante_contas = 0;
                    }
                }
                break;
            case 5:
                int melhor_comprador = 0;
                for (int i = 0 ; i < id_cliente; i++){
                    if (pt[i].montante_contas > pt[melhor_comprador].montante_contas) {
                        melhor_comprador = i;
                    }
                }
                printf("Melhor comprador: %s - ID: %d - Montante: %lf", pt[melhor_comprador].nome, pt[melhor_comprador].id_cliente, pt[melhor_comprador].montante_contas);
                break;
            case 6:
                int cliente_selecionado;
                printf("Qual cliente deseja exibir o montante?(Insira o ID)\n");
                scanf("%d", &cliente_selecionado);
                printf("Montante de compras para o cliente: %s - ID: %d", pt[cliente_selecionado].nome, pt[cliente_selecionado].id_cliente);
                printf("Montante: %lf", pt[cliente_selecionado].montante_contas);
                break;
            case 7:
                for (int i = 0 ; i < id_cliente; i++){
                    printf("\nCliente: %s \n ID: %d\n Montante: %lf", pt[i].nome, pt[i].id_cliente, pt[i].montante_contas);
                }
                break;
        }

        printf("\n Deseja continuar com as operacoes?\n1-SIM\n2-NÃO");
        scanf("%d", &keep_runing);
        system("clear");
    }


    free(pt);
}
