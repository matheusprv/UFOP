#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NUM_THREADS 3

int saldo = 0;
char operacao = '_';

void linha_separacao(){
    printf("\n");
    for(int i = 0; i<50; i++) printf("=");
    printf("\n\n");
}

// Funções para threads
void print_numero_thread(char * nome_thread){
    pthread_t tid = pthread_self();
    printf("Nome da thread: %s  |  Thread ID: %lu\n", nome_thread, tid);
}

void encerra_thread(){
    if(operacao == '0'){
        printf("Encerrando thread\n");
        sleep(5);
        pthread_exit(NULL);
    }
}

void * incrementa_saldo(){
    print_numero_thread("Incrementa Saldo");
    while(1){
        if(operacao == '+'){
            saldo += 1000;
            operacao = '_';
        }
        else encerra_thread();
    }
}

void * decrementa_saldo(){
    print_numero_thread("Decrementa Saldo");
    while(1){
        if(operacao == '-'){
            saldo -= 1000;
            operacao = '_';
        }
        else encerra_thread();
    }
}

void * imprime_saldo(){
    print_numero_thread("Imprime Saldo");
    while(1){
        if (operacao == 's'){
            printf("\nSaldo: %d UD\n\n", saldo);
            linha_separacao();
            operacao = '_';
        }
        else encerra_thread();
    }
}

void iniciar_threads(pthread_t * threads){
    pthread_create(&(threads[0]), NULL, incrementa_saldo, NULL);
    pthread_create(&(threads[1]), NULL, decrementa_saldo, NULL);
    pthread_create(&(threads[2]), NULL, imprime_saldo, NULL);
}

// Interação do Usuário
void menu_opcoes(){
    printf("+: incrementar\n");
    printf("-: decrementar\n");
    printf("s: Exibir saldo\n");
    printf("0: sair\n");
    printf("Digite a sua opção: ");
}

char ler_opcao_menu(){
    char entrada_usuario[3];
    fgets(entrada_usuario, 3, stdin);
    entrada_usuario[strlen(entrada_usuario) -1] = '\0';

    // Valor de entrada maior do que o esperado
    if(strlen(entrada_usuario) > 1) return 'X';

    return entrada_usuario[0];
}

void executar_comandos(){

    while(operacao != '0'){
        sleep(1);
        menu_opcoes();
        operacao = ler_opcao_menu();
        linha_separacao();
    }
}

void finaliza_programa(pthread_t * threads){
    for(int i = 0; i < NUM_THREADS; i++){
        printf("\tExecutando o join\n");
        pthread_join(threads[i], NULL);
    }
}

// Main
int main(){

    pthread_t threads[NUM_THREADS];
    iniciar_threads(threads);

    executar_comandos();

    finaliza_programa(threads);

    printf("Saindo\n");

    return 0;
}
