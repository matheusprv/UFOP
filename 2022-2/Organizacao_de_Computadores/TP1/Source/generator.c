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

Instruction* generateMultiplicationInstructions(int n1, int n2, int execHalt, int salvarValorNaRam){
    //Vetor de instrucoes contendo as duas instrucoes de levar informacao na RAM e o comando de finalizacao mais a quantidade de vezes que o n1 sera multiplicado, ou seja, o n2
    int qtdInstrucoesExtras = execHalt ? 3 : 2;
    if(salvarValorNaRam == 0)
        qtdInstrucoesExtras = 1;

    
    Instruction* instrucoes = (Instruction*) malloc((qtdInstrucoesExtras + n2) * sizeof(Instruction));

    if(salvarValorNaRam == 1){
        //Levando o n1 para a RAM e colocando no endereco 0
        instrucoes[0].opcode = 0;
        instrucoes[0].info1 = n1;//Valor para ser salvo na RAM
        instrucoes[0].info2 = 0;//Posicao na RAM      
    }

    //Levando o valor 0 (termo neutro da soma) para a RAM na posicao 1
    instrucoes[1].opcode = 0;
    instrucoes[1].info1 = 0;//Valor para ser salvo na RAM
    instrucoes[1].info2 = 1;//Posicao na RAM  

    int instrucaoInicial = salvarValorNaRam == 1 ? 2 : 0;

    for(int i = instrucaoInicial; i < n2+instrucaoInicial; i++){
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

Instruction* gerarInstrucoesExponenciacao(int base, int expoente){//a partir de expoentes maior do que 2, dará erro por causa da logica na função de mutiplicacao, ex: 4³ daria 32

    int qtdInstrucoes = 0;
    for(int i=0; i<expoente-1; i++){
        qtdInstrucoes += (base + 3);//Mais um para copiar o valor da posicao 1 para a 0 e outro para adicionar 0 na p0
    }
    qtdInstrucoes+= 3;//Executar o halt e levar os valores iniciais para a RAM

    Instruction* instrucoes = malloc(qtdInstrucoes * sizeof(Instruction));

    Instruction * instrucoesAux;
    int salvarNaRam = 1;
    int posicaoAtual = 0;
    int j;
    for(int i=0; i<expoente-1; i++){
        instrucoesAux = generateMultiplicationInstructions(base, base, 0, salvarNaRam);

        for(j=0; j<base+1+salvarNaRam; j++){
            instrucoes[posicaoAtual] = instrucoesAux[j];
            posicaoAtual++;
        }
        salvarNaRam = 0;

        //Colocando 0 na posicao 0
        instrucoes[posicaoAtual].opcode = 0;
        instrucoes[posicaoAtual].info1 = 0;
        instrucoes[posicaoAtual].info2 = 0;

        posicaoAtual++;

        //somando o que esta na posicao 1 com a 0, para passar o que esta na posicao 1 para a zero
        instrucoes[posicaoAtual].opcode = 1;
        instrucoes[posicaoAtual].info1 = 0;//Posicao do n1
        instrucoes[posicaoAtual].info2 = 1;// Posicao do n2
        instrucoes[posicaoAtual].info3 = 0;// Onde vai salvar

        posicaoAtual++;

        //lembrar que depois disso precisa ser colocado 0 na posicao 1 da ram

        free(instrucoesAux);

    }

    instrucoes[posicaoAtual].opcode = -1;
    instrucoes[posicaoAtual].info1 = -1;
    instrucoes[posicaoAtual].info2 = -1;
    instrucoes[posicaoAtual].info3 = -1;
    return instrucoes;

    //Levar o que esta na posicao 1 para a posicao 0 por meio de uma soma do valor na p1+0 salvando-o na p0

    /*for(int i=0; i<expoente-1; i++){
        for(int k=0; k<expoente-1; k++){
            instrucoesAux = generateMultiplicationInstructions(base, base, 0, 0);
            
            //Aumentando o tamanho do vetor de instrucoes
            tamanhoInstrucoes = (&instrucoes)[0] - instrucoes; //https://arjunsreedharan.org/post/69303442896/how-to-find-the-size-of-an-array-in-c-without

            Instruction* copiaTemporaria = malloc(sizeof(instrucoes));

            for(int j=0; j<tamanhoInstrucoes; j++){
                copiaTemporaria[j] = instrucoes[j];
            }
            free(instrucoes);

            int tamanhoAux = (&instrucoesAux)[0] - instrucoesAux;
            int tamanhoCopiaTemporaria = ((&copiaTemporaria)[0] - copiaTemporaria);
            
            tamanhoInstrucoes =  tamanhoAux + tamanhoCopiaTemporaria + 1;
            instrucoes = malloc(tamanhoInstrucoes * sizeof(Instruction));
            
            //Passar o que está no Aux e o que está na copia para o principal
            for(int j=0; j<tamanhoCopiaTemporaria; j++){
                instrucoes[j] = copiaTemporaria[j];
            }
            free(copiaTemporaria);
            for(int j = 0; j< tamanhoAux; j++){
                instrucoes[j+tamanhoInstrucoes] = instrucoesAux[j];
            }

            free(instrucoesAux);
        }
    }*/
    
    
    
    /*Instruction* instrucoes = (Instruction*) malloc((((expoente-1)*(2 + base))+1) * sizeof(Instruction));
    
    int contador = 0;
    Instruction* instrucoesAuxiliar; //vetor para ir armazenando o retorno da função "generateMultiplicationInstructions"

    for(int i=0; i<expoente-1; i++){
        instrucoesAuxiliar = generateMultiplicationInstructions(base, base, 0, i==0 ? 1 : 0);

        for(int j=0; j<2 + base; j++){
            instrucoes[contador] = instrucoesAuxiliar[j];
            contador++;
        }

        free(instrucoesAuxiliar);
    }

    instrucoes[expoente-1].opcode = -1;
    instrucoes[expoente-1].info1 = -1;
    instrucoes[expoente-1].info2 = -1;
    instrucoes[expoente-1].info3 = -1;

    return instrucoes;*/

} 

Instruction* generateDivisionInstructions(int n1, int n2){
    //n1 = Dividendo
    //n2 = DIvisor

    int qtdInstrucoes = 4;

    Instruction* instrucoes = malloc(qtdInstrucoes * sizeof(Instruction));

    //Levando o n1 para a RAM e colocando no endereco 0
    instrucoes[0].opcode = 0;
    instrucoes[0].info1 = n1;//Valor para ser salvo na RAM
    instrucoes[0].info2 = 0;//Posicao na RAM      

    //Levando n2 para a RAM e colocando no endereco 1
    instrucoes[1].opcode = 0;
    instrucoes[1].info1 = n2;//Valor para ser salvo na RAM
    instrucoes[1].info2 = 1;//Posicao na RAM  

    //Levando o valor 0 para a posicao 2 da RAM para ser o quociente
    instrucoes[2].opcode = 0;
    instrucoes[2].info1 = 1;//Valor para ser salvo na RAM
    instrucoes[2].info2 = 2;//Posicao na RAM 

    //Levando o valor 1 para a posicao 3 da RAM para somar mais um ao quociente
    instrucoes[3].opcode = 0;
    instrucoes[3].info1 = 1;//Valor para ser salvo na RAM
    instrucoes[3].info2 = 3;//Posicao na RAM 


    for(int i=n2; i < n1; i+=n2){

        qtdInstrucoes+=2;

        instrucoes = realloc(instrucoes, qtdInstrucoes*sizeof(Instruction));

        //Subtraindo n2 de n1
        instrucoes[qtdInstrucoes- 2].opcode = 2; //Operacao de subtracao
        instrucoes[qtdInstrucoes- 2].info1 = 0; //Posicao do n1
        instrucoes[qtdInstrucoes- 2].info2 = 1; //Posicao do n2
        instrucoes[qtdInstrucoes- 2].info3 = 0; //Onde ira salvar a subtracao

        //Adicionando mais um no quociente
        instrucoes[qtdInstrucoes - 1].opcode = 1; //Operacao de soma
        instrucoes[qtdInstrucoes - 1].info1 = 2; //Posicao do n1
        instrucoes[qtdInstrucoes - 1].info2 = 3; //Posicao do n2
        instrucoes[qtdInstrucoes - 1].info3 = 2; //Onde ira salvar a soma
        
    }

    //Resto sera a posicao 0
    //O resultado sera a posicao 2

    instrucoes = realloc(instrucoes, (qtdInstrucoes+1) * sizeof(Instruction));

    instrucoes[qtdInstrucoes].opcode = -1;
    instrucoes[qtdInstrucoes].info1 = -1;
    instrucoes[qtdInstrucoes].info2 = -1;
    instrucoes[qtdInstrucoes].info3 = -1;

    return instrucoes;
}

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
