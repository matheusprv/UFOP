#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(int tid)
{
    sleep(1);
    /*Esta função imprime o identificador do thread e sai.*/
    printf("Hello World. Greetings from thread %d\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    /*O programa principal cria 10 threads e sai.*/
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;
    
    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("Main here. Creating thread %d\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, i);
        if (status != 0)
        {
            printf("Oops. pthread create returned error code %d\n", status);
            exit(-1);
        }
    }

    sleep(4);
    return 0;
}