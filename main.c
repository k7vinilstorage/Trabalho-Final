#include <stdio.h>
#include <string.h>

typedef struct Data{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct Telefone{
    int DDD;
    long int numero; //perguntar ao prof se nao pode substituir por uma string de vetor ou mesmo uma string numerica
}Telefone;

typedef struct Cliente{
    char Nome[50];
    char CPF[15];
    Telefone Fone;
    Data Nascimento;
}Cliente;

typedef struct Investimento{
    int TipoAplicacao;
    Data DataAplicacao;
    float ValorAplicacao;
    float taxa;
    Data DataResgate;
    float ValorResgate;
}Investimento;

int NumeroDigitos(long int num){ //contar quantos digitos têm
    int digitos=0;
    
    
    
}

int ValidarData(Data var1){ //var1 é a variavel-parametro
    if(var1.dia<1 || var1.dia>30){
        return 0;
    }
    if(var1.mes<1 || var1.mes>12){
        return 0;
    }
    if(var1.ano<1900 || var1.ano>***Criar uma struct com a data atual***){
        return 0;
    }
    
    return 1; //Se funcionar
}

int ValidarTelefone(Telefone var2){
    if(var2.DDD<11 || var2.DDD>91){
        return 0;
    }
}

int main()
{


    return 0;
}

