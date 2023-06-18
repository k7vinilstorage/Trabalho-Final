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
int ValidarTelefone(int DDD, long int numero){
    if (DDD >= 11 && DDD <= 91) {
        if (numero >= 900000000 && numero <= 999999999 || numero <= 99999999 ) {
            return 1;
        } 
    }
    return 0;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Funções especificas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Função de cadastro

int validar_cpf(char cpf[15]){
    int ncpf[11]={0,0,0,0,0,0,0,0,0,0,0};
    int num=0;
    for(int i=0; i<3; i++){
        ncpf[i]=cpf[i]-48;
    }
    for(int i=4; i<7; i++){
        ncpf[i-1]=cpf[i]-48;
    }
    for(int i=8; i<11; i++){
        ncpf[i-2]=cpf[i]-48;
    }
    for (int i=0; i<9; i++){
        num+=(ncpf[i])*(i+1);
    }
    num=num%11;
    if(num<2){
        num=0;
    }
    if(num!=cpf[12]-48){
        return 0;
    } else{
        ncpf[9]=num;
        num=0;
        for (int i=0; i<9; i++){
            num+=(ncpf[i+1])*(10-i);
        }
        num=num%11;
        num=11-num;
        if(num!=cpf[13]-48){
            return 0;
        }else{
            return 1;
        }
    }
}

void Cadastro() {
    int x = 0;
    int i = 0;
    while(i < 1) {
        getchar();
        printf("Insina o nome do cliente: ");
        fgets(user[c_count].Nome, 50, stdin);
        for(x = 0; x < 1; x) {
            printf("Insira o CPF do cliente: ");
            fgets(user[c_count].CPF, 15, stdin);
            x = validar_cpf(user[c_count].CPF);
            if(x == 0) {
                printf("CPF inválido!\n");
            }
            getchar();
        }

        for(x = 0; x < 1; x) {
            printf("Insira o DDD do Telefone do cliente: ");
            scanf("%d", &user[c_count].Fone.DDD);
            printf("Insira o Telefone do cliente: ");
            scanf("%d", &user[c_count].Fone.numero);
            x = ValidarTelefone(user[c_count].Fone.DDD, user[c_count].Fone.numero);
            if(x == 0) {
                printf("Telefone inválido!\n");
            }
            getchar();
        }

        system("clear");
        printf("Cliente cadastrado!!\n");
        printf("Pressione qualquer tecla para continuar");  
        getchar();
        c_count++;
        i++;
    }
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
        printf("\nTelefne do Cliente: (%d) %d\n", user[i].Fone.DDD, user[i].Fone.numero);
        printf("\nPressione qualquer tecla para continuar\n"); 
        getchar();
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
                printf("Aplicação Fundos\\n");
            }
            printf("Banco emissor: %s", inv[i].BancoEmissor);
            printf("Taxa: %.2f\n", inv[i].taxa);
            printf("Ativo: %c\n", inv[i].ATIVO);
            printf("\n");
        }
        getchar();
        getchar();
    }

    