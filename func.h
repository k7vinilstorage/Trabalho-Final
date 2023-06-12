#include <stdio.h>
#include <string.h>

//Tipo de dados para Data
typedef struct Data{
    int dia;
    int mes;
    int ano;
}Data;

//Tipo de dados para telefone
typedef struct Telefone{
    int DDD;
    long int numero; //perguntar ao prof se nao pode substituir por uma string de vetor ou mesmo uma string numerica
}Telefone;

//Tipo de dados para cliente
typedef struct Cliente{
    char Nome[50];
    char CPF[15];
    Telefone Fone;
    Data Nascimento;
}Cliente;

//Tipo de dados para Investimento
typedef struct Investimento{
    int TipoAplicacao;
    char BancoEmissor [100];
    float taxa;
    char ATIVO;
}Investimento;


//Tipo de dados para transação
typedef struct Transacao{
    int IdCliente;
    Cliente cliente;
    Investimento investimento;
    Data DataAplicacao;
    float ValorAplicacao;
    Data DataResgate;
    float ValorResgate;
}Trasacao;

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
    if(var2.DDD<11 || var2.DDD>91){
        return 0;
    }
}