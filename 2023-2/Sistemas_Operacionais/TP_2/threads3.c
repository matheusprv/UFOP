#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void linha_separacao() {
    printf("\n");
    for (int i = 0; i < 50; i++) printf("=");
    printf("\n\n");
}
void print_numero_thread(char* nome_thread) {
    pthread_t tid = pthread_self();
    printf("Nome da thread: %20s  |  Thread ID: %lu\n", nome_thread, tid);
}

#define NUM_THREADS 3

int saldo = 0;
char operacao = '_';
pthread_mutex_t mutex_operacao = PTHREAD_MUTEX_INITIALIZER;
enum tipo_operacoes {INCREMENTAR, DECREMENTAR, EXIBIR};
pthread_cond_t cond_operacao[] = {PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER};

void reset_operacao(){
    operacao = '_';
}

void obter_mutex(char operacao_desejada, enum tipo_operacoes op){
    while (operacao != operacao_desejada) {
        pthread_cond_wait(&cond_operacao[op], &mutex_operacao);
    }
}

// Funções para threads
void* incrementa_saldo() {
    print_numero_thread("Incrementa Saldo");
    
    while (operacao != '0') {
        obter_mutex('+', INCREMENTAR);

        if(operacao == '0') break;        

        saldo += 1000;
        reset_operacao();

        pthread_mutex_unlock(&mutex_operacao);
    }
    pthread_exit(NULL);
}

void* decrementa_saldo() {
    print_numero_thread("Decrementa Saldo");
   
    while (operacao != '0') {
        obter_mutex('-', DECREMENTAR);

        if(operacao == '0') break;
        
        saldo -= 1000;
        reset_operacao();
        
        pthread_mutex_unlock(&mutex_operacao);
    }
    pthread_exit(NULL);
}

void* imprime_saldo() {
    print_numero_thread("Imprime Saldo");

    while (operacao != '0') {
        obter_mutex('s', EXIBIR);

        if(operacao == '0') break;
        
        printf("\nSaldo: %d UD\n\n", saldo);
        linha_separacao();
        reset_operacao();

        pthread_mutex_unlock(&mutex_operacao);
    }

    pthread_exit(NULL);
}

void iniciar_threads(pthread_t* threads) {
    pthread_create(&(threads[0]), NULL, incrementa_saldo, NULL);
    pthread_create(&(threads[1]), NULL, decrementa_saldo, NULL);
    pthread_create(&(threads[2]), NULL, imprime_saldo, NULL);
}

// Interação do Usuário
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

//Executa a leitura dos comandos enquanto ele não for igual a 0, sinalizando o seu fim
void executar_comandos() {
    while (operacao != '0') {
        menu_opcoes();
        pthread_mutex_lock(&mutex_operacao);
        
        operacao = ler_opcao_menu();
        linha_separacao();

        pthread_mutex_unlock(&mutex_operacao);

        //Enviando o sinal para a thread correta
        switch (operacao){
            case '+':
                pthread_cond_signal(&cond_operacao[INCREMENTAR]);
                break;
            case '-':
                pthread_cond_signal(&cond_operacao[DECREMENTAR]);
                break;
            case 's':
                pthread_cond_signal(&cond_operacao[EXIBIR]);
                sleep(0.5);
                break;
        }
    }
}

void finaliza_programa(pthread_t* threads) {
    for (int i = 0; i < NUM_THREADS; i++) 
        pthread_cancel(threads[i]);
}

// Main
int main() {
    pthread_t threads[NUM_THREADS];
    iniciar_threads(threads);
    sleep(1);

    executar_comandos();

    finaliza_programa(threads);

    printf("Saindo\n");

    return 0;
}
