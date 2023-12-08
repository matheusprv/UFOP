/*
    Este código possui um problema de condição de corrida pois estamos utilizando o mesmo pipe para a leitura e escrita no processo pai e filho
    Dessa forma, quando incrementamos um dado, imediantamente já pe feita a leitura, porém no lado do processo filho, nada ainda foi feito
    Assim, a computação não é feita corretamente
*/

#include "useful_functions.h"

#define NUM_PROCESS 2
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
    printf("\n%s pelo processo com PID: %d\n", mensagem, pid);
    linha_separacao();
    printf("\n");
}

void incrementa_saldo(int * pipe){
    int saldo = 0;
    int novo_saldo;
    while(1){
        if(read(pipe[0], &novo_saldo, sizeof(novo_saldo)) > 0){
            mensagem_e_pid_processo("Incrementando o saldo", getpid());
            saldo += VARIACAO_SALDO;
            write(pipe[1], &saldo, sizeof(saldo));

        }
    }
}
void decrementa_saldo(int * pipe){
    int saldo;
    do{
        read(pipe[0], &saldo, sizeof(saldo));
        mensagem_e_pid_processo("Decrementando o saldo", getpid());
        saldo -= VARIACAO_SALDO;
        write(pipe[1], &saldo, sizeof(saldo));
    }while(1);
}

typedef struct Process{
    pid_t processos_pid [NUM_PROCESS];
    int pipe_incremento[2], pipe_decremento[2];
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
            write(processos->pipe_incremento[1], &saldo, sizeof(saldo));
            read(processos->pipe_incremento[0], &saldo, sizeof(saldo));
        }
        else if(operacao == '-'){
            write(processos->pipe_decremento[1], &saldo, sizeof(saldo));
            read(processos->pipe_decremento[0], &saldo, sizeof(saldo));

        }
        else if(operacao == 's'){
            mensagem_e_pid_processo("Exibindo o saldo", getpid());
            printf("Saldo atual: %d\n", saldo);
            linha_separacao();
        }        
    }
}

int main(){

    Process processos;

    //Criando pipes e verificando se estão funcionando
    if (pipe(processos.pipe_incremento) == -1 || pipe(processos.pipe_decremento) == -1) {
        perror("Erro ao criar os pipes");
        exit(EXIT_FAILURE);
    }

    //Criando o primeiro processo filho e definindo a sua funcao
    pid_t pid_incremento = criar_processo();
    if(pid_incremento == 0){
        incrementa_saldo(processos.pipe_incremento);
        printf("Incrementa saldo finalizado\n");
        return 0;//Assim que o processo terminar a execução de incrementa_saldo(), ele finaliza, pois sua função foi cumprida
    }
    else if(pid_incremento == -1)return EXIT_FAILURE;

    printf("Passou por aqui;\n");

    //Criando o segundo processo filho e definindo a sua funcao
    pid_t pid_decremento = criar_processo();
    if(pid_decremento == 0){
        while(1) decrementa_saldo(processos.pipe_decremento);
        return 0; //Assim que o processo terminar a execução de decrementa_saldo(), ele finaliza, pois sua função foi cumprida
    }
    else if(pid_decremento == -1){
        matar_processos(processos.processos_pid, 1);
        return EXIT_FAILURE;
    }

    //Salvando os processos no vetor de PIDs
    processos.processos_pid[0] = pid_incremento;
    processos.processos_pid[1] = pid_decremento;

    executar_comandos(&processos);

    matar_processos(processos.processos_pid, 2);

    return 0;
}