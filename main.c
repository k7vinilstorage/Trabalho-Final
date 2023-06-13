#include <stdio.h>
#include <string.h>
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
        printf("7 - \n");
        printf("8 - \n");
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

        }
        else if(op == 5) {

        }
        else if(op == 6) {

        }
        else if(op == 7) {

        }
        else if(op == 8) {

        }
        else if(op == 9) {

        }
    }
    return 0;
}