#include "useful_functions.h"

void linha_separacao() {
    for (int i = 0; i < 75; i++) printf("=");
    printf("\n");
}

void menu_opcoes() {
    printf("+: incrementar\n");
    printf("-: decrementar\n");
    printf("s: Exibir saldo\n");
    printf("0: sair\n");
    printf("Digite a sua opção: ");
}


//Le qual ação o usuário deseja realizar
char ler_opcao_menu() {
    char entrada_usuario[300];
    fgets(entrada_usuario, 300, stdin);
    entrada_usuario[strlen(entrada_usuario) - 1] = '\0';

    // Valor de entrada maior do que o esperado
    if (strlen(entrada_usuario) > 1) return 'X';

    return entrada_usuario[0];
}
