#include <stdio.h>
#include <string.h>
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
    int i = 0;
    printf("Insira o número do cliente: ");
    scanf("%d", &i);
    printf("Insina o nome do cliente: ");
    fgets(user[i].Nome, 50, stdin);
    printf("Insira o CPF do cliente: ");
    fgets(user[i].CPF, 15, stdin);
    printf("Insira o DDD do Telefone do cliente: ");
    scanf("%d", &user[i].Fone.DDD);
    printf("Insira o Telefone do cliente: ");
    scanf("%d", &user[i].Fone.numero);
}

