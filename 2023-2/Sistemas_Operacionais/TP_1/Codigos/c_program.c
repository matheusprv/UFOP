#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ANSI_RESET "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"

void print_negrito(char * texto){
    printf("\x1b[1m%s\x1b[0m", texto);
}

void print_linha_separacao(){
    printf("\n=========================================================\n");
}

void ler_arquivo(char * filename){

    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("O arquivo não existe");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)){
        printf("%s", line);
    }

    fclose(file);
    sleep(2);

    print_linha_separacao();
}

char * ler_processos(){
    char * processos = malloc(64 * sizeof(char));
    
    printf("Digite qual(is) processos deseja interromper: ");
    fgets(processos, 64, stdin);
    processos[strlen(processos) -1] = '\0';
    
    return processos;
}

void executar_comando(char * comando, int exibir_linha){
    //Exibindo na tela o comando a ser executado
    char comando_string[100];
    sprintf(comando_string, "Executando o comando: %s\n", comando);
    puts(comando_string);

    //Executando o comando
    sleep(1);
    system(comando);

    if(exibir_linha == 1)
        print_linha_separacao();
}

void comando_com_entrada(char * comando_recebido){
    char comando[256];
    strcpy(comando, comando_recebido);
    
    printf("\n%s\n", comando);

    //Recebendo a entrada da identificacao dos processos
    char processos_identificacao[256];
    strcpy(processos_identificacao, ler_processos());

    //Concatenando o comando com os processos
    strcat(comando, processos_identificacao);

    executar_comando(comando, 0);
    system("ps");

    print_linha_separacao();
}

void renice(){
    char comando[64], pid [20], prioridade[4];
    printf("\nrenice\n");

    //Lendo o PID do processo
    printf("Digite o PID do processo: ");
    scanf("%s", pid);

    //Lendo a nova prioridade do processo
    printf("Digite a nova prioridade do processo: ");
    scanf("%s", prioridade);
    
    //Modificando a string do comando
    sprintf(comando, "renice %s -p %s", prioridade, pid);
    
    executar_comando(comando, 0);
    system("top");
}

void executar_lista_de_comandos(){
    //top
    executar_comando("top", 1);

    //ps
    executar_comando("ps", 1);
    executar_comando("ps aux | grep dummy", 1);

    //pstree
    executar_comando("pstree", 1);

    //Kill
    comando_com_entrada("kill -9 ");

    //Killall
    comando_com_entrada("killall ");

    //pkill
    comando_com_entrada("pkill ");

    //renice
    renice();

}

void executar_dummy_codes(){
    //Sao inciadas instancias de um programa, em segundo plano, que realiza uma iteracao de um loop a cada 2 segundos
    //Estes codigos tem a unica funcao de exemplificar o funcionamento dos comandos que sao solicitados
    char comando[50];
    for (int i = 1; i <= 10; i++) {
        sprintf(comando, "./dummy/dummy_%d &", i);
        system(comando);
    }

    //executando um dummy diferente para evitar que o pkill encerre
    system("./dummy/evita_pkill &");

    sleep(2);
}

int main(){
        
    print_negrito("Exibindo a versão do sistema.\n");
    ler_arquivo("/etc/os-release");

    print_negrito("\nExibindo as informações do aluno.\n");
    ler_arquivo("MatheusPeixoto.txt");

    print_negrito("\nGerando alguns processos para exemplificar os comandos que serão executados a seguir.\n");
    executar_dummy_codes();
    print_linha_separacao();

    print_negrito("\nExecutando os comandos solicitados.\n");
    executar_lista_de_comandos();

    return 0;
}