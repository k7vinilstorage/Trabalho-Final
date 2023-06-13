
/* função de validação de CPF cedida por: 
Nome..: Vinicius Souza Dias
Turma.: EC41A-C11
Data..: 12/06/2023

Precisa de ajustes para ser utilizada na sua implementação enum funcionar 
conforme o enunciado do trabalho final.

*/
int validar_cpf(char cpf[15]){
    // return 0 = false 1 == true
    int soma = 0;
    int resto = 0;

    for(int c = 0; c < 9; c++){

        soma += ((cpf[c] - 48) * (10-c));
    }
    resto = soma % 11;

    if (resto < 2){     
        if(cpf[10]-48 != 0){
            return 0;
        }

    }else{
        if(cpf[10]-48 != 11-resto){
            return 0;   
        }
    }

    soma = (cpf[10] - 48) * 2;

    for(int c = 0; c < 9; c++){

        soma += ((cpf[c] - 48) * (11-c));
    }

    resto = soma % 11;

    if (resto < 2){     
        if(cpf[11] != 0){
            return 0;
        }

    }else{
        if(cpf[11]-48 != 11-resto){
            return 0;   
        }
    }
    return 1;
}