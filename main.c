#include <stdio.h>
#include <string.h>
#include <math.h>
#include "func.h"

int main() {

    int op = 0;

    while (1) {
        system("clear");
        printf("Bem vindo a central de investimentos!!\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Apresentar Cadastro\n");
        printf("3 - Listar clientes\n");
        printf("4 - Investimento LCI/LCA\n");
        printf("5 - Investimento CDB\n");
        printf("6 - Investimento Fundos\n");
        printf("7 - Criar Transação\n");
        printf("8 - Listar aplicações\n");
        printf("9 - \n");
        printf("0 - Sair\n");
        printf("Escolha uma opção (0 - 9): ");
        scanf("%d", &op);

        if(op == 1) {
            Cadastro();
        }
        else if(op == 2) {
            show_cadastro();
        }
        else if(op == 3) {
            list_cliente();
        }
        else if(op == 4) {
            LCI_LCA();
        }
        else if(op == 5) {
            CDB();
        }
        else if(op == 6) {
            Fundos();
        }
        else if(op == 7) {
            aplicacao();
        }
        else if(op == 8) {
            edit_aplicacao();
        }
        else if(op == 9) {
            list_aplicacacoes();
        }
        else if(op == 0) {
            break;
        }
    }
    return 0;
}