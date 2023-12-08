#include "useful_functions.h"

#define NUM_THREADS 3
#define VARIACAO_SALDO 500

void mensagem_e_thread(char * mensagem, pthread_t tid){
    linha_separacao();
    printf("%s pelo pela thread de TID %ld\n", mensagem, tid);
    linha_separacao();
}


int saldo = 0;
char operacao = '_';
pthread_mutex_t mutex_operacao = PTHREAD_MUTEX_INITIALIZER;
enum tipo_operacoes {INCREMENTAR, DECREMENTAR, EXIBIR};
pthread_cond_t cond_operacao[] = {PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER};

void reset_operacao(){
    operacao = '_';
}

void obter_mutex(char operacao_desejada, enum tipo_operacoes op){
    pthread_mutex_lock(&mutex_operacao);
    while (operacao != operacao_desejada) {
        pthread_cond_wait(&cond_operacao[op], &mutex_operacao);
    }
}

// Funções para threads
void* incrementa_saldo() {
    
    while (operacao != '0') {
        obter_mutex('+', INCREMENTAR);

        mensagem_e_thread("Incrementando saldo", pthread_self());
        saldo += VARIACAO_SALDO;
        reset_operacao();

        pthread_mutex_unlock(&mutex_operacao);
    }
    pthread_exit(NULL);
}

void* decrementa_saldo() {
   
    while (operacao != '0') {
        obter_mutex('-', DECREMENTAR);
        
        mensagem_e_thread("Decrementando saldo", pthread_self());
        saldo -= VARIACAO_SALDO;
        reset_operacao();
        
        pthread_mutex_unlock(&mutex_operacao);
    }
    pthread_exit(NULL);
}

void* imprime_saldo() {

    while (operacao != '0') {
        obter_mutex('s', EXIBIR);
        
        char * texto = "Saldo de %d UD sendo exibido";
        char mensagem [150];
        sprintf(mensagem, texto, saldo);
        mensagem_e_thread(mensagem, pthread_self());

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

//Executa a leitura dos comandos enquanto ele não for igual a 0, sinalizando o seu fim
void executar_comandos() {
    while (operacao != '0') {
        menu_opcoes();
        pthread_mutex_lock(&mutex_operacao);
        
        operacao = ler_opcao_menu();

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
                break;
        }
        sleep(0.75);
    }
}

void finaliza_programa(pthread_t* threads) {
    for (int i = 0; i < NUM_THREADS; i++) 
        pthread_kill(threads[i], 0);
    //pthread_cancel(threads[i]);
}

// Main
int main() {
    pthread_t threads[NUM_THREADS];
    iniciar_threads(threads);

    executar_comandos();

    finaliza_programa(threads);

    printf("Saindo\n");

    return 0;
}
