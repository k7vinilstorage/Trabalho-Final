#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Dados.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Funções Validadoras
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Função conta dígitos
int NumeroDigitos(long int num){ //contar quantos digitos têm
    int digitos=0;
    
}

//Função Validadora de Data
int ValidarData(Data var1){ //var1 é a variavel-parametro
    if(var1.dia<1 || var1.dia>30){
        return 0;
    }
    if(var1.mes<1 || var1.mes>12){
        return 0;
    }
    if(var1.ano<1900 || var1.ano>2023){
        return 0;
    }
    
    return 1; //Se funcionar
}

//Função validadora de Telefone
int ValidarTelefone(Telefone var2){
    if (var2.DDD >= 11 && var2.DDD <= 91) {
        if (var2.numero >= 900000000 && var2.numero <= 999999999 || var2.numero <= 99999999 ) {
            return 1;
        } 
    }
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Funções especificas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Função de cadastro

void Cadastro() {
    getchar();
    printf("Insina o nome do cliente: ");
    fgets(user[c_count].Nome, 50, stdin);
    printf("Insira o CPF do cliente: ");
    fgets(user[c_count].CPF, 15, stdin);
    printf("Insira o DDD do Telefone do cliente: ");
    scanf("%d", &user[c_count].Fone.DDD);
    printf("Insira o Telefone do cliente: ");
    scanf("%d", &user[c_count].Fone.numero);
    getchar();
    system("clear");
    printf("Cliente cadastrado!!\n");
    printf("Pressione qualquer tecla para continuar");  
    getchar();
    c_count++;
}

void list_cliente() {
    getchar();
    int i = 0;
    system("clear");

    for(i = 0; i < c_count; i++) {
        printf("%d:", i);
        printf("\nNome do Cliente: %s", user[i].Nome);
        printf("CPF do Cliente: %s\n", user[i].CPF);
    }
    printf("Pressione qualquer tecla para continuar");  
    getchar();
}

void show_cadastro() {
    char cpf[15];
    int cpf_cmp = 1;
    int i = 0;
    getchar();
    printf("Insira o CPF do cliente: ");
    fgets(cpf, 15, stdin);

    while(cpf_cmp != 0 || i == 99) {
        cpf_cmp = strcmp(user[i].CPF, cpf);
        i++;
    }

    i--;

    if(cpf_cmp == 0) {
        system("clear");
        printf("Nome do Cliente: %s", user[i].Nome);
        printf("CPF do Cliente: %s", user[i].CPF);
        printf("Telefne do Cliente: (%d) %d\n", user[i].Fone.DDD, user[i].Fone.numero);
        printf("Pressione qualquer tecla para continuar\n"); 
        getchar();
    }
    else {
        system("clear");
        printf("Cliente não cadastrado!\n");
        printf("Pressione qualquer tecla para continuar\n");  
        getchar();
    }
}

void LCI_LCA() {
        system("clear");
        getchar();
        inv[inv_count].TipoAplicacao = 1;
        printf("Insira o banco emissor: ");
        fgets(inv[inv_count].BancoEmissor, 100, stdin);
        printf("Insira a taxa: ");
        scanf("%f", &inv[inv_count].taxa);
        getchar();
        printf("Ativo (S/N): ");
        scanf("%c", &inv[inv_count].ATIVO);
        getchar();
        system("clear");
        printf("Investimento cadastrado!\n\n");
        printf("Pressione qualquer tecla para continuar\n");  
        getchar();
        inv_count++;
    }

    void CDB() {
        system("clear");
        getchar();
        inv[inv_count].TipoAplicacao = 2;
        printf("Insira o banco emissor: ");
        fgets(inv[inv_count].BancoEmissor, 100, stdin);
        printf("Insira a taxa: ");
        scanf("%f", &inv[inv_count].taxa);
        getchar();
        printf("Ativo (S/N): ");
        scanf("%c", &inv[inv_count].ATIVO);
        getchar();
        system("clear");
        printf("Investimento cadastrado!\n\n");
        printf("Pressione qualquer tecla para continuar\n");  
        getchar();
        inv_count++;
    }

    void Fundos() {
        system("clear");
        getchar();
        inv[inv_count].TipoAplicacao = 3;
        printf("Insira o banco emissor: ");
        fgets(inv[inv_count].BancoEmissor, 100, stdin);
        printf("Insira a taxa: ");
        scanf("%f", &inv[inv_count].taxa);
        getchar();
        printf("Ativo (S/N): ");
        scanf("%c", &inv[inv_count].ATIVO);
        getchar();
        system("clear");
        printf("Investimento cadastrado!\n\n");
        printf("Pressione qualquer tecla para continuar\n");  
        getchar();
        inv_count++;
    }

    void aplica() {
        int i = 0;
        for(i = 0; i < inv_count; i++) {
            if(inv[i].TipoAplicacao == 1) {
                printf("Aplicação LCI/LCA\n");
            }
            else if(inv[i].TipoAplicacao == 2) {
                printf("Aplicação CDB\n");
            }
            else if(inv[i].TipoAplicacao == 3) {
                printf("Aplicação Fundos\n");
            }
            printf("Banco emissor: %s", inv[i].BancoEmissor);
            printf("Taxa: %.2f\n", inv[i].taxa);
            printf("Ativo: %c\n", inv[i].ATIVO);
            printf("\n");
        }
        getchar();
        getchar();
    }