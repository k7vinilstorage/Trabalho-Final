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

Cliente user[100];