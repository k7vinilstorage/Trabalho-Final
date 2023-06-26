#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Dados.h"

//Valores aproximados devido a imprecisão do float!!
//Valores aproximados devido a imprecisão do float!!

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Funções Validadoras
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

//Função de tempo
int DiferencaDatas(Data data_inicial, Data data_final){
    int diast1;
    int diast2;
    int dif;

    diast1 = data_inicial.dia + data_inicial.mes * 30 + data_inicial.ano * 365;
    diast2 = data_final.dia + data_final.mes * 30 + data_final.ano * 365;
    dif = diast2 - diast1;
    return dif;
}

//Função de validar data de Resgate
int ValidarData_resgate(Data var1, Data var2){ //var1 é a variavel-parametro
    if(var1.dia<1 || var1.dia>30){
        return 0;
    }
    if(var1.mes<1 || var1.mes>12){
        return 0;
    }
    if(var1.ano<1900){
        return 0;
    }
    if(DiferencaDatas(var2, var1) <= 0) {
        return 0;
    }

    return 1; //Se funcionar
}

//Função de conversão de taxa
float tax_conv(float x) {
    float TAXA_CONV, TAXA_TEMP;
    TAXA_TEMP = x/100;
    TAXA_CONV = pow((1 + TAXA_TEMP), 0.002739);
    TAXA_CONV = TAXA_CONV - 1;
    TAXA_CONV = TAXA_CONV * 100;
    return TAXA_CONV;
}

//Caluladora de imposto
float IRPF (float valor, float tax, int TEMPO) {

    float TEMPlucro, IRPF, pow_;

    tax = tax / 100;
    tax = tax + 1;

    if (TEMPO <= 180) {
        pow_ = pow(tax, TEMPO);
        TEMPlucro = ((valor * pow_) - valor);
        IRPF = TEMPlucro * 0.225;
        }
    if (TEMPO >= 181 && TEMPO <= 360) {
        pow_ = pow(tax, TEMPO);
        TEMPlucro = ((valor * pow_) - valor);
        IRPF = TEMPlucro * 0.2;
        }
    if (TEMPO >= 361 && TEMPO <= 720) {
        pow_ = pow(tax, TEMPO);
        TEMPlucro = ((valor * pow_) - valor);
        IRPF = TEMPlucro * 0.175;
        }
    if (TEMPO >= 721) {
        pow_ = pow(tax, TEMPO);
        TEMPlucro = ((valor * pow_) - valor);
        IRPF = TEMPlucro * 0.15;
        }

    return IRPF;
}

// Função validadora de CPF
int validar_cpf(char cpf[15]) {
    int ncpf[11]={0,0,0,0,0,0,0,0,0,0,0};
    int num=0;
    for(int i=0; i<3; i++) {
        ncpf[i]=cpf[i]-48;
    }
    for(int i=4; i<7; i++) {
        ncpf[i-1]=cpf[i]-48;
    }
    for(int i=8; i<11; i++) {
        ncpf[i-2]=cpf[i]-48;
    }
    for (int i=0; i<9; i++) {
        num+=(ncpf[i])*(i+1);
    }
    num=num%11;
    if(num<2) {
        num=0;
    }
    if(num!=cpf[12]-48) {
        return 0;
    } 
    else {
        ncpf[9]=num;
        num=0;
        for (int i=0; i<9; i++) {
            num+=(ncpf[i+1])*(10-i);
        }
        num=num%11;
        num=11-num;
        if(num!=cpf[13]-48) {
            return 0;
        }
        else {
            return 1;
        }
    }
}

//Ordem Alfabetica
void ordem() {
    Cliente temp1;
    int i = 0;
    int z = 0;

    for(z = 0; z < c_count - 1; z++) {
        for(i = 0; i < (c_count - 1); i++) {
            if(strcasecmp(user[i].Nome, user[(i + 1)].Nome) > 0) {
                temp1 = user[(i + 1)];
                user[(i + 1)] = user[i];
                user[i] = temp1;
            }
        }
    }
}

Data DataAtual() {
    time_t tempo=time(NULL); //NULL indica que o valor retornado deve ser armazenado em uma variável do tipo time_t.
    struct tm dataAtual=*localtime(&tempo);

    struct Data data;
    data.dia=dataAtual.tm_mday;
    data.mes=dataAtual.tm_mon + 1; //começa no 0
    data.ano=dataAtual.tm_year + 1900; //começa no 0

    return data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Funções especificas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Função de cadastro
void Cadastro() {
    system(limpa);
    int x = 0;
    int i = 0;
    while(i < 1) {
        getchar();
        printf("Insina o nome do cliente: ");
        fgets(user[c_count].Nome, 50, stdin); //c_count = número de clientes
        for(x = 0; x < 1; x) {
            printf("Insira o CPF do cliente: ");
            fgets(user[c_count].CPF, 15, stdin);
            x = validar_cpf(user[c_count].CPF);
            if(x == 0) {
                printf("CPF inválido!\n");
            }
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
            while(1) {
                printf("Insira a data de nascimento do cliente (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &user[c_count].Nascimento.dia, &user[c_count].Nascimento.mes, &user[c_count].Nascimento.ano);
                if(ValidarData(user[c_count].Nascimento) == 1) {
                    break;
                }
                printf("Data inválida!\n");
            }
            getchar();
        }
        system(limpa);
        printf("Cliente cadastrado!!\n");
        printf("Pressione enter para continuar");  
        getchar();
        c_count++;
        i++;
    }
}

// Listar cliente
void list_cliente() {
    ordem(); // coloca em ordem alfabética
    getchar();
    int i = 0;
    system(limpa);

    for(i = 0; i < c_count; i++) {
        printf("%d:", i);
        printf("\nNome do Cliente: %s", user[i].Nome);
        printf("CPF do Cliente: %s\n", user[i].CPF);
        printf("Telefne do Cliente: (%d) %d\n", user[i].Fone.DDD, user[i].Fone.numero);
    }
    printf("\nPressione enter para continuar");  
    getchar();
}

//Retorna a entrada do cliente no vetor
int get_cliente(char cpf[15]) {
    int k = 0;                   // Esntrada do cliente no vetor user
    int cpf_cmp = 1;
    while(cpf_cmp != 0 || k == 99) {
        if(user[k].CPF[0] == '\0') {
            return 200;
            break;
        }
        cpf_cmp = strcmp(cpf, user[k].CPF);
        k++;
    }
    k--;
    return k;
}

//Encontrar cliente via CPF
void show_cadastro() {
    system(limpa);
    char cpf[15];
    int i = 0;
    getchar();

    while(1) {
        printf("Insira o CPF do cliente: ");
        fgets(cpf, 15, stdin);
        getchar();

        i = get_cliente(cpf);

        if(i == 200) {
            printf("Cliente não cadastrado!\n");
            printf("\nPressione enter para continuar\n"); 
            getchar();
            break;printf("Cliente não cadastrado!\n");
            printf("\nPressione enter para continuar\n"); 
            getchar();
            break;
        }

        system(limpa);
        printf("Nome do Cliente: %s", user[i].Nome);
        printf("CPF do Cliente: %s", user[i].CPF);
        printf("\nTelefne do Cliente: (%d) %d\n", user[i].Fone.DDD, user[i].Fone.numero);
        printf("Data de nascimento: %d/%d/%d\n", user[i].Nascimento.dia, user[i].Nascimento.mes, user[i].Nascimento.ano);
        printf("\nPressione enter para continuar\n"); 
        getchar();
        break;
    }
    
}


//Cadastrar opção de LCI/LCA
void LCI_LCA() {
    float t = 0; // variável temporária para taxa
    system(limpa);
    getchar();
    inv[inv_count].TipoAplicacao = 1;
    printf("Insira o banco emissor: ");
    fgets(inv[inv_count].BancoEmissor, 100, stdin);
    printf("Insira a taxa (ao ano): ");
    scanf("%f", &t);
    inv[inv_count].taxa = tax_conv(t);
    getchar();
    printf("Ativo (S/N): ");
    scanf("%c", &inv[inv_count].ATIVO);
    getchar();
    system(limpa);
    printf("Investimento cadastrado!\n\n");
    printf("Pressione enter para continuar\n");  
    getchar();
    inv_count++;
}

//Cadastrar opção de CDB
void CDB() {
    float t = 0;
    system(limpa);
    getchar();
    inv[inv_count].TipoAplicacao = 2;
    printf("Insira o banco emissor: ");
    fgets(inv[inv_count].BancoEmissor, 100, stdin);
    printf("Insira a taxa (ao ano): ");
    scanf("%f", &t);
    inv[inv_count].taxa = tax_conv(t);
    getchar();
    printf("Ativo (S/N): ");
    scanf("%c", &inv[inv_count].ATIVO);
    getchar();
    system(limpa);
    printf("Investimento cadastrado!\n\n");
    printf("Pressione enter para continuar\n");  
    getchar();
    inv_count++;
}

//Cadastrar opção de fundos
void Fundos() {
    float t = 0;
    system(limpa);
    getchar();
    inv[inv_count].TipoAplicacao = 3;
    printf("Insira o banco emissor: ");
    fgets(inv[inv_count].BancoEmissor, 100, stdin);
    printf("Insira a taxa (ao ano): ");
    scanf("%f", &t);
    inv[inv_count].taxa = tax_conv(t);
    getchar();
    printf("Ativo (S/N): ");
    scanf("%c", &inv[inv_count].ATIVO);
    getchar();
    system(limpa);
    printf("Investimento cadastrado!\n\n");
    printf("Pressione enter para continuar\n");  
    getchar();
    inv_count++;
}

// Menu para criar investimentos
void investimentos_menu() {

    int op = 0;

    while(1) {
        system(limpa);
        printf("##################################\n");
        printf("#                                #\n");
        printf("# Escolha o tipo de investimento #\n");
        printf("#                                #\n");
        printf("##################################\n");
        printf("# 1                      LCI/LCA #\n");
        printf("# 2                           CDB#\n");
        printf("# 3                        Fundos#\n");
        printf("# 0                          Sair#\n");
        printf("##################################\n");
        printf("# Escolha uma opção(0 - 3): ");
        scanf("%d", &op);

        if(op == 1) {
            LCI_LCA();
        }
        else if(op == 2) {
            CDB();
        }
        else if(op == 3) {
            Fundos();
        }
        else if(op == 0) {
            break;
        }
    }
}

// Fazer aplicação
int aplicacao() {
    system(limpa);
    int k = 0; // entrada do cliente no vetor extraida via cpf
    int x = 0; // variavel para recolher o tipo de aplicação
    int i = 0; // contador para loop
    char cpf[15];

    for(i = 0; i < inv_count; i++) {
        if(inv[i].TipoAplicacao == 1) {
            printf("%d)\nAplicação LCI/LCA\n", i);
        }
        else if(inv[i].TipoAplicacao == 2) {
            printf("%d)\nAplicação CDB\n", i);
        }
        else if(inv[i].TipoAplicacao == 3) {
            printf("%d)\nAplicação Fundos\n", i);
        }
        printf("Banco emissor: %s", inv[i].BancoEmissor);
        printf("Taxa: %.3f%% ao dia\n", inv[i].taxa);
        printf("Ativo: %c", inv[i].ATIVO);
        printf("\n");
    }

    while(1) {
        printf("Insira o tipo de aplicação (0 - %d): ", (inv_count - 1));
        scanf("%d", &x);
        if("%d", inv[x].ATIVO == 'S') {
            break;
        }
        printf("Investimento Inativo!\n");
    }

    aplica[id].ID_transacao = id; // define o id para a transação, o qual é incrementado automaticamente

    getchar();
    system(limpa);

    while(1) {
        printf("Insira o cpf do cliente: ");
        fgets(cpf, 15, stdin);
        k = get_cliente(cpf);
        if(k == 200) {
            printf("\nCliente não cadastrado!\n");
            printf("\nPressione enter para continuar\n"); 
            getchar();
            getchar();
            break;
        }
        aplica[id].investimento = inv[x]; // copia as informaçoes de investimento do vetor de investimentos para a transação específica
        aplica[id].cliente = user[k]; // copia as informações do cliente do vetor de clientes para a transação específica 

        printf("Insira o valor da aplicação: ");
        scanf("%f", &aplica[id].ValorAplicacao);

        while(1) {
            printf("Insira a data da aplicação (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &aplica[id].DataAplicacao.dia, &aplica[id].DataAplicacao.mes, &aplica[id].DataAplicacao.ano);
            if(ValidarData(aplica[id].DataAplicacao) == 1) {
                break;
            }
            printf("Data inválida!\n");
        }

        while(1) {
            printf("Insira a data de resgate (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &aplica[id].DataResgate.dia, &aplica[id].DataResgate.mes, &aplica[id].DataResgate.ano);
            if(ValidarData_resgate(aplica[id].DataResgate, aplica[id].DataAplicacao) == 1) {
                break;
            }
            printf("Data inválida!\n");
        }

        aplica[id].ValorResgate = 0.00; // Define o valor de resgate inicial como 0

        id++;
        getchar();

        system(limpa);

        printf("Aplicação concluida!\n");
        printf("Pressione enter para continuar\n");

        getchar();       
    }
}



//Resgate lci com data atual  // retorna o volor de resgade de uma aplicação lci com base na data atual
float resgate_lci(float valor, float tax, Data apli) {
    float resgate_now;
    resgate_now = valor * pow ((1 + (tax / 100)), DiferencaDatas(apli, data_atual));
    return resgate_now;
}

//Resgate cdb com data atual // retorna o volor de resgade de uma aplicação cdb com base na data atual
float resgate_cdb(float valor, float tax, Data apli) {
    float resgate_now, imposto_now;
    resgate_now = valor * pow ((1 + (tax / 100)), DiferencaDatas(apli, data_atual));
    imposto_now = IRPF(valor, tax, DiferencaDatas(apli, data_atual));
    resgate_now = resgate_now - imposto_now;
    return resgate_now;
}

//Resgate fundos com data atual // retorna o volor de resgade de uma aplicação fundos com base na data atual
float resgate_fundos(float valor, float tax, Data apli) {
    float resgate_now, imposto_now;
    resgate_now = valor * pow ((1 + (tax / 100)), DiferencaDatas(apli, data_atual));
    resgate_now = resgate_now * pow(0.99, (DiferencaDatas(apli, data_atual) / 365));
    imposto_now = IRPF(valor, tax, DiferencaDatas(apli, data_atual));
    resgate_now = resgate_now - imposto_now;
    return resgate_now;
}

//Mostrar as aplicações do cliente
void list_aplicacacoes() {
    system(limpa);
    int id[30]; // vetor que armazena as entradas das transações de um cliente
    int j = 0; // entrada do cliente no vetor de clientes
    int k = 0; // variavél intermediária para arazena a entrada de uma transação de um cliente
    int i = 0; // varialvel que armazena o número de transações de um cliente
    int l = 0; // variavel de loop para apresentar as informações do cliente
    float imposto = 0; // variável para o imposto com base na data pre-definida
    float imposto_now = 0; // variavel para o imposto com base na data atual
    float resgate_now = 0; // variavel que armazena o valor de resgate com base na data atual
    int cpf_cmp = 1; // variável para comparação de cpf
    char cpf[15]; // Variável temporáraia para cpf
    getchar();

    //loop whilhe criado para interromper o funcionamento da função caso um cpf não cadastrado seja inserido
    while(1) { 
        printf("Insira o CPF do cliente: ");
        fgets(cpf, 15, stdin);
        j = get_cliente(cpf); //entrada do cliente no vetor de clientes
        if(j == 200) {        //Verifica o retorno da função caso o cpf seja inválido
            printf("\nCliente não cadastrado!\n");
            printf("\nPressione enter para continuar\n"); 
            getchar();
            getchar();
            break;
        }
        printf("Nome do Cliente: %s\n", user[j].Nome);

        // seleciona a entrada da transação do cleinte comparando cpf
        while(k < 99) {
            cpf_cmp = strcmp(aplica[k].cliente.CPF, cpf);
            if(cpf_cmp == 0) {
                id[i] = k; // Define uma entrada no vetor id caso a transação pertença ao cliente
                i++;
            }
            k++;
        }

        //Reliza os calculos para a transação com base em seu tipoe  aprensenta todas as transações do cliente

        for(l = 0; l < i; l++) {
            printf("Id de transação: %d\n", aplica[id[l]].ID_transacao); 
            if(aplica[id[l]].investimento.TipoAplicacao == 1) {
                printf("Tipo de aplicação: LCI/LCA\n");
                aplica[id[l]].ValorResgate = aplica[id[l]].ValorAplicacao * pow ((1 + (aplica[id[l]].investimento.taxa / 100)), DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate));
                resgate_now = resgate_lci(aplica[id[l]].ValorAplicacao, aplica[id[l]].investimento.taxa, aplica[id[l]].DataAplicacao);
            }
            else if(aplica[id[l]].investimento.TipoAplicacao == 2) {
                printf("Tipo de aplicação: CDB\n");
                aplica[id[l]].ValorResgate = aplica[id[l]].ValorAplicacao * pow ((1 + (aplica[id[l]].investimento.taxa / 100)), DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate));
                imposto = IRPF(aplica[id[l]].ValorAplicacao, aplica[id[l]].investimento.taxa, DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate));
                aplica[id[l]].ValorResgate = aplica[id[l]].ValorResgate - imposto;
                resgate_now = resgate_cdb(aplica[id[l]].ValorAplicacao, aplica[id[l]].investimento.taxa, aplica[id[l]].DataAplicacao);
            }
            else if(aplica[id[l]].investimento.TipoAplicacao == 3) {
                printf("Tipo de aplicação: Fundos\n");
                aplica[id[l]].ValorResgate = aplica[id[l]].ValorAplicacao * pow ((1 + (aplica[id[l]].investimento.taxa / 100)), DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate));
                aplica[id[l]].ValorResgate = aplica[id[l]].ValorResgate * pow(0.99, (DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate) / 365));
                imposto = IRPF(aplica[id[l]].ValorAplicacao, aplica[id[l]].investimento.taxa, DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate));
                aplica[id[l]].ValorResgate = aplica[id[l]].ValorResgate - imposto;
                resgate_now = resgate_fundos(aplica[id[l]].ValorAplicacao, aplica[id[l]].investimento.taxa, aplica[id[l]].DataAplicacao);
            }
            printf("Banco Emissor: %s", aplica[id[l]].investimento.BancoEmissor);
            printf("Taxa: %.2f%%\n", aplica[id[l]].investimento.taxa);
            printf("Valor de resgate em %d/%d/%d: %.2f\n", aplica[id[l]].DataResgate.dia, aplica[id[l]].DataResgate.mes, aplica[id[l]].DataResgate.ano, aplica[id[l]].ValorResgate);
            printf("Valor de resgate hoje: %.2f\n", resgate_now);
            printf("\n");
        }
        getchar();
        printf("Pressione enter para continuar\n");
        getchar();
    }
}

//Calcula o montante de cada tipo de investimento para todas as transações
void montante() {
    system(limpa);
    float montante_lci = 0;
    float montante_cdb = 0;
    float montante_fundos = 0;

    int i = 0;
    for(i = 0; i < 100; i++) {
        if(aplica[i].investimento.TipoAplicacao == 1) {
            montante_lci += resgate_lci(aplica[i].ValorAplicacao, aplica[i].investimento.taxa, aplica[i].DataAplicacao);
        }
    }

    for(i = 0; i < 100; i++) {
        if(aplica[i].investimento.TipoAplicacao == 2) {
            montante_cdb += resgate_cdb(aplica[i].ValorAplicacao, aplica[i].investimento.taxa, aplica[i].DataAplicacao);
        }
    }

    for(i = 0; i < 100; i++) {
        if(aplica[i].investimento.TipoAplicacao == 3) {
            montante_fundos += resgate_fundos(aplica[i].ValorAplicacao, aplica[i].investimento.taxa, aplica[i].DataAplicacao);
        }
    }


    printf("O montante de investimentos lci é: %.2f\n", montante_lci);
    printf("O montante de investimentos cdb é: %.2f\n", montante_cdb);
    printf("O montante de investimentos fundos é: %.2f\n", montante_fundos);
    getchar();
    printf("Pressione enter para continuar\n");
    getchar();
    
}