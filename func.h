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

//Função de valitar data de Resgate
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

//Caluladora de imposto (roubo)
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

struct Data DataAtual() {
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
        fgets(user[c_count].Nome, 50, stdin);
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
        printf("Pressione qualquer tecla para continuar");  
        getchar();
        c_count++;
        i++;
    }
}


// Listar cliente
void list_cliente() {
    ordem();
    getchar();
    int i = 0;
    system(limpa);

    for(i = 0; i < c_count; i++) {
        printf("%d:", i);
        printf("\nNome do Cliente: %s", user[i].Nome);
        printf("CPF do Cliente: %s\n", user[i].CPF);
        printf("Telefne do Cliente: (%d) %d\n", user[i].Fone.DDD, user[i].Fone.numero);
    }
    printf("\nPressione qualquer tecla para continuar");  
    getchar();
}

//Encontrar cliente via CPF
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
        system(limpa);
        printf("Nome do Cliente: %s", user[i].Nome);
        printf("CPF do Cliente: %s", user[i].CPF);
        printf("\nTelefne do Cliente: (%d) %d\n", user[i].Fone.DDD, user[i].Fone.numero);
        printf("Data de nascimento: %d/%d/%d\n", user[i].Nascimento.dia, user[i].Nascimento.mes, user[i].Nascimento.ano);
        printf("\nPressione qualquer tecla para continuar\n"); 
        getchar();
        getchar();
    }
    else {
        system(limpa);
        printf("Cliente não cadastrado!\n");
        printf("Pressione qualquer tecla para continuar\n");  
        getchar();
    }
}

//Retorna a entrada do cliente no vetor
int get_cliente(char cpf[15]) {
    int k = 0;
    int cpf_cmp = 1;
    while(cpf_cmp != 0 || k == 99) {
        cpf_cmp = strcmp(user[k].CPF, cpf);
        k++;
    }
    k--;
    return k;
}

//Cadastrar opção de LCI/LCA
void LCI_LCA() {
        float t = 0;
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
        printf("Pressione qualquer tecla para continuar\n");  
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
        printf("Pressione qualquer tecla para continuar\n");  
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
        printf("Pressione qualquer tecla para continuar\n");  
        getchar();
        inv_count++;
    }
// Fazer aplicação
    void aplicacao() {
        system(limpa);
        int k = 0;
        int x = 0;
        int i = 0;
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

        aplica[id].ID_transacao = id;

        getchar();
        system(limpa);
        printf("Insira o cpf do cliente: ");
        fgets(cpf, 15, stdin);

        k = get_cliente(cpf);

        aplica[id].investimento = inv[x];
        aplica[id].cliente = user[k];

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

        aplica[id].ValorResgate = 0.00;

        id++;
        getchar();

        system(limpa);

        printf("Aplicação concluida!\n");
        getchar();
        
    }

//Mostrar as aplicações do cliente
void list_aplicacacoes() {
    system(limpa);
    int id[30];
    int j = 0;
    int k = 0;
    int i = 0;
    int l = 0;
    float imposto = 0;
    float imposto_now = 0;
    float resgate_now = 0;
    int cpf_cmp = 1;
    char cpf[15];
    getchar();
    printf("Insira o CPF do cliente: ");
    fgets(cpf, 15, stdin);

    j = get_cliente(cpf);

    printf("Nome do Cliente: %s\n", user[j].Nome);

    while(k < 99) {
        cpf_cmp = strcmp(aplica[k].cliente.CPF, cpf);
        if(cpf_cmp == 0) {
            id[i] = k;
            i++;
        }
        k++;
    }

    for(l = 0; l < i; l++) {
        printf("Id de transação: %d\n", aplica[id[l]].ID_transacao);
        if(aplica[id[l]].investimento.TipoAplicacao == 1) {
            printf("Tipo de aplicação: LCI/LCA\n");
            aplica[id[l]].ValorResgate = aplica[id[l]].ValorAplicacao * pow ((1 + (aplica[id[l]].investimento.taxa / 100)), DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate));
            resgate_now = aplica[id[l]].ValorAplicacao * pow ((1 + (aplica[id[l]].investimento.taxa / 100)), DiferencaDatas(aplica[id[l]].DataAplicacao, data_atual));
        }
        else if(aplica[id[l]].investimento.TipoAplicacao == 2) {
            printf("Tipo de aplicação: CDB\n");
            aplica[id[l]].ValorResgate = aplica[id[l]].ValorAplicacao * pow ((1 + (aplica[id[l]].investimento.taxa / 100)), DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate));
            imposto = IRPF(aplica[id[l]].ValorResgate, aplica[id[l]].investimento.taxa, DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate));
            aplica[id[l]].ValorResgate = aplica[id[l]].ValorResgate - imposto;

            resgate_now = aplica[id[l]].ValorAplicacao * pow ((1 + (aplica[id[l]].investimento.taxa / 100)), DiferencaDatas(aplica[id[l]].DataAplicacao, data_atual));
            imposto_now = IRPF(aplica[id[l]].ValorResgate, aplica[id[l]].investimento.taxa, DiferencaDatas(aplica[id[l]].DataAplicacao, data_atual));
            resgate_now = resgate_now - imposto_now;
        }
        else if(aplica[id[l]].investimento.TipoAplicacao == 3) {
            printf("Tipo de aplicação: Fundos\n");
            aplica[id[l]].ValorResgate = aplica[id[l]].ValorAplicacao * pow ((1 + (aplica[id[l]].investimento.taxa / 100)), DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate));
            aplica[id[l]].ValorResgate = aplica[id[l]].ValorResgate * pow(0.99, (DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate) / 365));
            imposto = IRPF(aplica[id[l]].ValorResgate, aplica[id[l]].investimento.taxa, DiferencaDatas(aplica[id[l]].DataAplicacao, aplica[id[l]].DataResgate));
            aplica[id[l]].ValorResgate = aplica[id[l]].ValorResgate - imposto;

            resgate_now = aplica[id[l]].ValorAplicacao * pow ((1 + (aplica[id[l]].investimento.taxa / 100)), DiferencaDatas(aplica[id[l]].DataAplicacao, data_atual));
            resgate_now = resgate_now * pow(0.99, (DiferencaDatas(aplica[id[l]].DataAplicacao, data_atual) / 365));
            imposto_now = IRPF(aplica[id[l]].ValorResgate, aplica[id[l]].investimento.taxa, DiferencaDatas(aplica[id[l]].DataAplicacao, data_atual));
            resgate_now = resgate_now - imposto_now;
        
        
        }
        printf("Banco Emissor: %s", aplica[id[l]].investimento.BancoEmissor);
        printf("Taxa: %.2f%%\n", aplica[id[l]].investimento.taxa);
        printf("Valor de resgate em %d/%d/%d: %.2f\n", aplica[id[l]].DataResgate.dia, aplica[id[l]].DataResgate.mes, aplica[id[l]].DataResgate.ano, aplica[id[l]].ValorResgate);
        printf("Valor de resgate hoje: %.2f\n", resgate_now);
        printf("\n");
    }
    getchar();
    printf("Pressione qualquer tecla para continuar\n");
    getchar();
}

void edit_aplicacao() {
    char a;
    int i = 0;

    getchar();
    system(limpa);

    printf("Insira o Id da aplicação: ");
    scanf("%d", &i);

    getchar();
    printf("Você deseja alterar a data de resgate ou aumentar o investimento? (D - I): ");
    scanf("%c", &a);

    if (a == 'D') {
        printf("Insira a nova data de resgate (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &aplica[i].DataResgate.dia, &aplica[i].DataResgate.mes, &aplica[i].DataResgate.ano);
    }
    else if (a == 'I') {

    }

}

    