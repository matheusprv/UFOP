#include "useful_functions.h"

#define NUM_PROCESS 3
#define FILHO 0
#define VARIACAO_SALDO 500

pid_t criar_processo(){
    pid_t pid = fork();
    if(pid == -1){
        printf("Erro ao realizar fork\n");
        exit(1);
    }
    return pid;
}

void matar_processos(pid_t * processos_pid, int total_processos){
    for(int i = 0; i < total_processos; i++){
        kill(processos_pid[i], SIGKILL);
    }
}

void mensagem_e_pid_processo(char * mensagem, pid_t pid){
    linha_separacao();
    printf("%s pelo processo com PID: %d\n", mensagem, pid);
    linha_separacao();
}

void incrementa_saldo(int * pipe_pai_filho, int * pipe_filho_pai){
    int saldo = 0;
    while(1){
        read(pipe_pai_filho[0], &saldo, sizeof(saldo));
        mensagem_e_pid_processo("Incrementando o saldo", getpid());
        saldo += VARIACAO_SALDO;
        write(pipe_filho_pai[1], &saldo, sizeof(saldo));
    }
}
void decrementa_saldo(int * pipe_pai_filho, int * pipe_filho_pai){
    int saldo;
    while(1){
        read(pipe_pai_filho[0], &saldo, sizeof(saldo));
        mensagem_e_pid_processo("Decrementando o saldo", getpid());
        saldo -= VARIACAO_SALDO;
        write(pipe_filho_pai[1], &saldo, sizeof(saldo));
    }
}
void exibe_saldo(int * pipe_pai_filho, int * pipe_filho_pai){
    int saldo;
    while(1){
        read(pipe_pai_filho[0], &saldo, sizeof(saldo));

        char * texto = "Saldo de %d UD sendo exibido";
        char resultado [150];
        sprintf(resultado, texto, saldo);

        mensagem_e_pid_processo(resultado, getpid());

        write(pipe_filho_pai[1], &saldo, sizeof(saldo));
    }
}


typedef struct Process{
    pid_t processos_pid [NUM_PROCESS];

    //Dois pipes para cada operação por serem rápidas e evitar que um dado sofra com condição de corrida nos arquivos de pipe
    int pipe_incremento_pai_filho[2], pipe_incremento_filho_pai[2];
    int pipe_decremento_pai_filho[2], pipe_decremento_filho_pai[2];
    int pipe_leitura_pai_filho[2], pipe_leitura_filho_pai[2];

}Process;

void executar_comandos(Process * processos) {
    char operacao = '_';
    int saldo = 0;

    while (operacao != '0') {
        //Lendo a proxima opcao de item
        menu_opcoes();
        operacao = ler_opcao_menu();

        // Realizando a chamada para a modificação do saldo
        if(operacao == '+'){       
            write(processos->pipe_incremento_pai_filho[1], &saldo, sizeof(saldo));
            read(processos->pipe_incremento_filho_pai[0], &saldo, sizeof(saldo));
        }
        else if(operacao == '-'){
            write(processos->pipe_decremento_pai_filho[1], &saldo, sizeof(saldo));
            read(processos->pipe_decremento_filho_pai[0], &saldo, sizeof(saldo));

        }
        else if(operacao == 's'){
            write(processos->pipe_leitura_pai_filho[1], &saldo, sizeof(saldo));
            read(processos->pipe_leitura_filho_pai[0], &saldo, sizeof(saldo));
        }        
    }
}

int main(){

    Process processos;

    //Criando pipes e verificando se estão funcionando
    if (pipe(processos.pipe_incremento_filho_pai) == -1 || pipe(processos.pipe_decremento_filho_pai) == -1
    ||  pipe(processos.pipe_incremento_pai_filho) == -1 || pipe(processos.pipe_decremento_pai_filho) == -1
    ||  pipe(processos.pipe_leitura_pai_filho) == -1 || pipe(processos.pipe_leitura_filho_pai) == -1) {
        perror("Erro ao criar os pipes");
        exit(EXIT_FAILURE);
    }

    //Criando o primeiro processo filho e definindo a sua funcao
    pid_t pid_incremento = criar_processo();
    processos.processos_pid[0] = pid_incremento;
    if(pid_incremento == 0) incrementa_saldo(processos.pipe_incremento_pai_filho, processos.pipe_incremento_filho_pai);
    else if(pid_incremento == -1)return EXIT_FAILURE;

    //Criando o segundo processo filho e definindo a sua funcao
    pid_t pid_decremento = criar_processo();
    processos.processos_pid[1] = pid_decremento;
    if(pid_decremento == 0) decrementa_saldo(processos.pipe_decremento_pai_filho, processos.pipe_decremento_filho_pai);
    else if(pid_decremento == -1){
        matar_processos(processos.processos_pid, 1);
        return EXIT_FAILURE;
    }

    //Criando o terceiro processo filho e definindo a sua função
    pid_t pid_exibe = criar_processo();
    processos.processos_pid[2] = pid_exibe;
    if(pid_exibe == 0) exibe_saldo(processos.pipe_leitura_pai_filho, processos.pipe_leitura_filho_pai);
    else if(pid_exibe == -1){
        matar_processos(processos.processos_pid, 2);
        return EXIT_FAILURE;
    }    

    executar_comandos(&processos);

    matar_processos(processos.processos_pid, 3);

    return 0;
}