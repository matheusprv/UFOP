#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int saldo = 0;

void print_numero_thread(){
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu\n", tid);
}

void* modifica_saldo(void * operacao){
    
    print_numero_thread();
    
    char op = *((char*)operacao);
    if(op == '+') saldo += 1000;
    else saldo -= 1000;
    
    pthread_exit(NULL);
    // return NULL;
}

void* imprime_saldo(){

    print_numero_thread();
    printf("\nSaldo: %d UD\n", saldo);
    
    pthread_exit(NULL);
    // return NULL;
}

void menu_opcoes(){
    printf("+: incrementar\n");
    printf("-: decrementar\n");
    printf("s: Exibir saldo\n");
    printf("0: sair\n");
    printf("Digite a sua opção: ");
}

void linha_separacao(){
    printf("\n");
    for(int i = 0; i<50; i++) printf("=");
    printf("\n\n");
}

char ler_opcao_menu(){
    char opcao_menu[3];
    fgets(opcao_menu, 3, stdin);
    opcao_menu[strlen(opcao_menu) -1] = '\0';

    // Valor de entrada maior do que o esperado
    if(strlen(opcao_menu) > 1) return 'X';

    return opcao_menu[0];

}

void ir_para_operacao(char opcao_menu){
    
    pthread_t thread;

    switch (opcao_menu){
        case '+':
        case '-':
            pthread_create(&thread, NULL, modifica_saldo, (void*)&opcao_menu);
            break;
        
        case 's':
            pthread_create(&thread, NULL, imprime_saldo, NULL);
            break;

        case '0':
            pthread_exit(NULL);

        default:
            printf("Opção inválida.\n");
            break;       
    }

    pthread_join(thread, NULL);
}

int main(){

    char opcao_menu;

    while(1){
        menu_opcoes();
        
        opcao_menu = ler_opcao_menu();
        ir_para_operacao(opcao_menu);
        
        linha_separacao();
    }

    return 0;
}


//Criar tres threads que ficam rodando eternamente enquanto o programa esta ativo e verificam uma variavel
// para saber qual entrará em ação no momento