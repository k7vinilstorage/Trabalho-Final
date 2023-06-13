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
    printf("Cliente cadastrado com código %d\n\n", user[c_count].Nome, c_count);
    c_count++;
}

void show_cadastro() {
    int i = 0;
    printf("Insira o código do cliente: ");
    scanf("%d", &i);
    printf("\nCódigo do Cliente: %d\n", i);
    printf("Nome do Cliente: %s", user[i].Nome);
    printf("CPF do Cliente: %s\n", user[i].CPF);
    printf("Telefne do Cliente: (%d) %d\n\n", user[i].Fone.DDD, user[i].Fone.numero);
}

void list_cliente() {

    
}

