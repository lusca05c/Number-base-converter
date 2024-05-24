#include <stdio.h>

// Variável global para ser acessada em qualquer lugar do programa
int opcao;

// Função chamada para dar continuidade ao programa em caso de erro do usuário
void welcome() {
    printf("Bem-vindo ao conversor de bases numéricas! KINGSTATION\n\n");
    printf("Qual opção deseja escolher?\n");
    printf("1 - Binário para Decimal\n");
    printf("2 - Binário para Hexadecimal\n");
    printf("3 - Decimal para Binário\n");
    printf("4 - Decimal para Hexadecimal\n");
    printf("5 - Hexadecimal para Binário\n");
    printf("6 - Hexadecimal para Decimal\n");
    printf("7 - Sair do sistema\n");
    scanf("%d", &opcao);
    while (opcao > 7 || opcao < 1) {
        printf("\n\nOPS!\nParece que você não entendeu muito bem, nós não temos essa opção no nosso servidor. Por favor, tente novamente.\n\n\n");
        printf("1 - Binário para Decimal\n");
        printf("2 - Binário para Hexadecimal\n");
        printf("3 - Decimal para Binário\n");
        printf("4 - Decimal para Hexadecimal\n");
        printf("5 - Hexadecimal para Binário\n");
        printf("6 - Hexadecimal para Decimal\n");
        printf("7 - Sair do sistema\n");
        scanf("%d", &opcao);
    }
}

int binarioParaDecimal(int binario) {
    int decimal = 0, potencia = 1, resto;

    while (binario != 0) {
        resto = binario % 10;
        if (resto != 0 && resto != 1) {
            printf("Número inválido!\nSua digitação: %d\nFormatação esperada, ex: 01101\n\n tente novamente...\n\n\n", binario);
            welcome();
            return -1; // Para sinalizar erro
        } else {
            decimal += resto * potencia;
            potencia *= 2;
            binario /= 10;
        }
    }
    return decimal;
}

char* binarioParaHexadecimal(int binario) {
    int valor, cont = 0, resto;
    static char hexadecimalconcreto[100]; // Armazenar o número hexadecimal

    valor = binarioParaDecimal(binario);
    if (valor == -1) {
        return "";
    }

    while (valor != 0) {
        resto = valor % 16;
        if (resto < 10) {
            hexadecimalconcreto[cont] = resto + '0';
        } else {
            hexadecimalconcreto[cont] = resto + 55;
        }
        cont++;
        valor /= 16;
    }
    hexadecimalconcreto[cont] = '\0'; // Finalizar a string

    // Inverter a string
    for (int i = 0; i < cont / 2; i++) {
        char temp = hexadecimalconcreto[i];
        hexadecimalconcreto[i] = hexadecimalconcreto[cont - i - 1];
        hexadecimalconcreto[cont - i - 1] = temp;
    }

    return hexadecimalconcreto;
}

int decimalParaBinario(int decimal) {
    int binario = 0, potencia = 1, resto;
    if (decimal < 0) {
        printf("OPS! Parece que você está tentando converter um número negativo para binário. Infelizmente ainda não conseguimos converter números negativos para binário.\n\n");
    } else {
        while (decimal != 0) {
            resto = decimal % 2;
            binario += resto * potencia;
            potencia *= 10;
            decimal /= 2;
        }
    }
    return binario;
}

char* decimalParaHexadecimal(int decimal) {
    int cont = 0, resto;
    static char hexadecimalconcreto[100]; // Armazenar o número hexadecimal

    if (decimal == 0) {
        hexadecimalconcreto[0] = '0';
        hexadecimalconcreto[1] = '\0';
        return hexadecimalconcreto;
    }

    while (decimal != 0) {
        resto = decimal % 16;
        if (resto < 10) {
            hexadecimalconcreto[cont] = resto + '0';
        } else {
            hexadecimalconcreto[cont] = resto + 55;
        }
        cont++;
        decimal /= 16;
    }
    hexadecimalconcreto[cont] = '\0'; // Finalizar a string

    // Inverter a string
    for (int i = 0; i < cont / 2; i++) {
        char temp = hexadecimalconcreto[i];
        hexadecimalconcreto[i] = hexadecimalconcreto[cont - i - 1];
        hexadecimalconcreto[cont - i - 1] = temp;
    }

    return hexadecimalconcreto;
}

int main() {
    int valor;
    int continuar = 1;

    while (continuar == 1) {
        welcome();
        if (opcao == 1) {
            printf("Digite o número binário que deseja converter para decimal: ");
            scanf("%d", &valor);
            valor = binarioParaDecimal(valor);
            if (valor != -1) {
                printf("O valor em decimal é: %d\n\n", valor);
            }
        } else if (opcao == 2) {
            printf("Digite o número binário que deseja converter para hexadecimal: ");
            scanf("%d", &valor);
            char* hexadecimal = binarioParaHexadecimal(valor);
            if (*hexadecimal != '\0') {
                printf("O valor em hexadecimal é: %s\n\n", hexadecimal);
            }
        } else if (opcao == 3) {
            printf("Digite o número decimal que deseja converter para binário: ");
            scanf("%d", &valor);
            valor = decimalParaBinario(valor);
            printf("O valor em binário é: %d\n\n", valor);
        } else if (opcao == 4) {
            printf("Digite o número decimal que deseja converter para hexadecimal: ");
            scanf("%d", &valor);
            char* hexadecimal = decimalParaHexadecimal(valor);
            printf("O valor em hexadecimal é: %s\n\n", hexadecimal);
        } else if (opcao == 5) {
            printf("Fundamento em construção. Infelizmente lamentamos por ainda não termos essa opção disponível no nosso servidor. Cuidaremos o mais rápido possível para que nossos desenvolvedores sejam atarefados para corrigir tais falhas. Aguarde até a próxima atualização com mais NOVIDADES! :) :)\n\n");
        } else if (opcao == 6) {
            printf("Fundamento em construção. Infelizmente lamentamos por ainda não termos essa opção disponível no nosso servidor. Cuidaremos o mais rápido possível para que nossos desenvolvedores sejam atarefados para corrigir tais falhas. Aguarde até a próxima atualização com mais NOVIDADES! :) :)\n\n");
        } else if (opcao == 7) {
            printf("\nGoodbye!\n");
            return 0;
        }

        // Pergunta ao usuário se deseja continuar
        printf("Deseja continuar executando o programa?\n1 - Sim\n2 - Não\n");
        scanf("%d", &continuar);
        while (continuar != 1 && continuar != 2) {
            printf("Opção inválida! Por favor, escolha 1 para Sim ou 2 para Não.\n");
            printf("Deseja continuar executando o programa?\n1 - Sim\n2 - Não\n");
            scanf("%d", &continuar);
        }
    }

    printf("\nGoodbye!\n");
    return 0;
}