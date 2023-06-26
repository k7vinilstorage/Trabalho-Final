#include <stdio.h>
#include <string.h>
#include <math.h>
#include "func.h"

//Valores aproximados devido a imprecisão do float!!
//Valores aproximados devido a imprecisão do float!!


int main() {

    #ifdef _WIN32
        strcpy(limpa, "cls");
    #else
        strcpy(limpa, "clear");
    #endif

    int op = 0;

    data_atual = DataAtual();

    while (1) {
        system(limpa);
        printf("##########################################\n");
        printf("#                                        #\n");
        printf("# Bem vindo a central de investimentos!! #\n");
        printf("#                                        #\n");
        printf("##########################################\n");
        printf("# 1                    Cadastrar Cliente #\n");
        printf("# 2                  Apresentar Cadastro #\n");
        printf("# 3                      Listar clientes #\n");
        printf("# 4              Cadastrar investimentos #\n");
        printf("# 5                      Criar Transação #\n");
        printf("# 6                    Listar aplicações #\n");
        printf("# 7                     Mostrar montante #\n");
        printf("# 0                                 Sair #\n");
        printf("##########################################\n");
        printf("Escolha uma opção (0 - 7): ");
        scanf("%d", &op);

        if(op == 1) {
            Cadastro();
        }
        else if(op == 2) {
            if(c_count == 0) {
                system(limpa);
                printf("Não há clientes cadastrados!\n");
                printf("\nPressione enter para continuar"); 
                getchar();
                getchar();
            }
            else {
                show_cadastro();
            }
        }
        else if(op == 3) {
            if(c_count == 0) {
                system(limpa);
                printf("Não há clientes cadastrados!\n");
                printf("\nPressione enter para continuar"); 
                getchar();
                getchar();
            }
            else {
                list_cliente();
            }
        }
        else if(op == 4) {
            investimentos_menu();
        }
        else if(op == 5) {
            if(inv_count == 0) {
                system(limpa);
                printf("Não há investimentos cadastrados!\n");
                printf("\nPressione enter para continuar"); 
                getchar();
                getchar();
            }
            else {
                aplicacao();
            }
        }
        else if(op == 6) {
             if(id == 0) {
                system(limpa);
                printf("Não há Aplicações cadastradas!\n");
                printf("\nPressione enter para continuar"); 
                getchar();
                getchar();
            }
            else {
                list_aplicacacoes();
            }
        }
        else if(op == 7) {
            montante();  
        }
        else if(op == 0) {
            break;
        }
    }
    return 0;
}