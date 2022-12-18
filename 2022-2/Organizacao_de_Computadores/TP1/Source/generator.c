#include "generator.h"
#include <stdio.h>
#include <stdlib.h>

Instruction* generateRandomInstructions(int ramSize) {
    // 01|22|13|45 => isto é uma instrução
    // 02|33|12|01 => isto é outra instrução
            
    // 0 => salvar na memória
    // 1 => opcode => somar
    // 2 => opcode => subtrair
    //-1 => halt
    
    // 22 => significa um endereço da RAM (10 endereço) 
    // 13 => significa 2o endereço
    // 45 => significa 3o endereco
    //ramSize => ESTA FORA DO INTERVALO DE 0 A ramSize DA MEMÓRIA RAM

    Instruction* instructions = (Instruction*) malloc(10 * sizeof(Instruction));

    for (int i=0; i<9; i++){
        instructions[i].opcode = rand() % 4; //0, 1, 2, 3
        instructions[i].info1 = rand() % ramSize; //0 ... RAM_SIZE
        do {
            instructions[i].info2 = rand() % ramSize; //0 ... RAM_SIZE
        } while (instructions[i].info1 == instructions[i].info2);
        instructions[i].info3 = rand() % ramSize; //0 ... RAM_SIZE
    }
    
    //inserindo a ultima instrucao do programa que nao faz nada que presta
    instructions[9].opcode =-1;
    instructions[9].info1 = -1;
    instructions[9].info2 = -1;
    instructions[9].info3 = -1;
    
    return instructions;
}

Instruction* generateMultiplicationInstructions(int n1, int n2, int execHalt){
    //Vetor de instrucoes contendo as duas instrucoes de levar informacao na RAM e o comando de finalizacao mais a quantidade de vezes que o n1 sera multiplicado, ou seja, o n2
    int qtdInstrucoesExtras = execHalt ? 3 : 2;
    Instruction* instrucoes = (Instruction*) malloc((qtdInstrucoesExtras + n2) * sizeof(Instruction));

    //Levando o n1 para a RAM e colocando no endereco 0
    instrucoes[0].opcode = 0;
    instrucoes[0].info1 = n1;//Valor para ser salvo na RAM
    instrucoes[0].info2 = 0;//Posicao na RAM

    //Levando o valor 0 (termo neutro da soma) para a RAM na posicao 1
    instrucoes[1].opcode = 0;
    instrucoes[1].info1 = 0;//Valor para ser salvo na RAM
    instrucoes[1].info2 = 1;//Posicao na RAM

    for(int i = 2; i < n2+2; i++){
        instrucoes[i].opcode = 1; //Operacao de soma
        instrucoes[i].info1 = 0; //Posicao do n1
        instrucoes[i].info2 = 1; //Posicao do n2
        instrucoes[i].info3 = 1; //Onde irá salvar a soma
    }

    if(execHalt){
        instrucoes[2+n2].opcode = -1;
        instrucoes[2+n2].info1 = -1;
        instrucoes[2+n2].info2 = -1;
        instrucoes[2+n2].info3 = -1;
    }

    return instrucoes;

}

Instruction* gerarInstrucoesExponenciacao(int base, int expoente){

    Instruction* instrucoes = ();


} 

/*Instruction* generateDivisionInstructions(int n1, int n2){
    //Vetor de instrucoes contendo as duas instrucoes de levar informacao na RAM e o comando de finalizacao mais a quantidade de vezes que o n1 sera multiplicado, ou seja, o n2
    Instruction* instrucoes = (Instruction*) malloc((3 + (n1/n2)) * sizeof(Instruction));

    //Levando o n1 para a RAM e colocando no endereco 0
    instrucoes[0].opcode = 0;
    instrucoes[0].info1 = n1;//Valor para ser salvo na RAM
    instrucoes[0].info2 = 0;//Posicao na RAM

    instrucoes[1].opcode = 0;
    instrucoes[1].info1 = n2;//Valor para ser salvo na RAM
    instrucoes[1].info2 = 1;//Posicao na RAM

    for(int i = 2; i < n1/n2+2; i++){
        instrucoes[i].opcode = 2; //Operacao de subtracao
        instrucoes[i].info1 = 0; //Posicao do n1
        instrucoes[i].info2 = 1; //Posicao do n2
        instrucoes[i].info3 = 0; //Onde irá salvar a subtracao
    }

    instrucoes[2+n2].opcode = -1;
    instrucoes[2+n2].info1 = -1;
    instrucoes[2+n2].info2 = -1;
    instrucoes[2+n2].info3 = -1;

    return instrucoes;
}*/

Instruction* readInstructions(char* fileName, int* ramSize) {
    printf("FILE -> %s\n", fileName);
    FILE* file = fopen(fileName, "r"); // Abrindo arquivo no modo leitura
    
    if (file == NULL) {
        printf("Arquivo nao pode ser aberto.\n");
        exit(1);
    }

    int n, i = 0;
    fscanf(file, "%d %d", ramSize, &n);
    Instruction* instructions = (Instruction*) malloc(n * sizeof(Instruction));
    while (i < n) {
        fscanf(file, "%d %d %d %d", &instructions[i].opcode, &instructions[i].info1, &instructions[i].info2, &instructions[i].info3);
        i++;
    }
    fclose(file); // Fechando o arquivo

    return instructions;
}
