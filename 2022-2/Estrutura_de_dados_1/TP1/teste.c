#include <stdio.h>
#include <stdlib.h>
/*

10
0 0 0 0 0 0 0 0 0 0
0 1 0 1 1 1 0 0 0 0
0 0 1 1 1 0 0 1 0 0
0 1 0 1 0 0 0 0 0 0
0 0 0 1 0 1 0 1 0 0
0 0 0 0 1 0 1 0 0 0
0 1 0 1 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 1 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0


0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 1 0 0 0 1 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 1 1 0 1 1 0 0 0
0 0 1 1 1 1 1 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 1 1 0 0 0


*/


int main(){

    int ordem;
    scanf("%d", &ordem);

    //Alocando matriz
    int **matriz = (int **) malloc(ordem*sizeof(int**));
    for(int i=0; i<ordem; i++)
        matriz[i] = (int*) malloc(ordem * sizeof(int*));
        

    //Preenchendo matriz
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            scanf("%d", &matriz[i][j]);
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    //Verificando 
    int colunaInicio, colunaFinal, linhaInicio, linhaFinal; //Variaveis de controle para verificar se está ou não nas bordas da matriz
    int celulasVizinhasVivas = 0; 
    
    for(int linha = 0; linha<ordem; linha++){

        linhaInicio = linha - 1 < 0 ? linha : linha - 1;
        linhaFinal = linha + 1 == ordem ? linha : linha + 1;


        for(int coluna = 0; coluna<ordem; coluna++){

            colunaInicio = coluna - 1 < 0 ? coluna : coluna -1;
            colunaFinal = coluna + 1 == ordem ? coluna : coluna + 1;

            int acaoDaCelulaAtual = 0;

            //Verificando quantidade de células vizinhas vivas
            for(; linhaInicio<linhaFinal; linhaInicio++){

                for(; colunaInicio<colunaFinal; colunaInicio++){

                    if(matriz[linhaInicio][colunaInicio] == 1)
                        celulasVizinhasVivas++;

                }

            }

            if(matriz[linha][coluna] == 1)
                celulasVizinhasVivas--; //Removendo a célula do centro da contagem, caso ela esteja viva

            //printf("matriz[%2d][%2d]: %d\n", linha, coluna, matriz[linha][coluna]);
            //Verificando o que ocorrerá com a célula
            if(matriz[linha][coluna] == 1 ){
                printf("Entrou\n\tQtd celulasVizinhasVivas: %d\n", celulasVizinhasVivas);
                printf("\tColuna Inicio: %2d -- Coluna Final: %2d - LinhaIcio: %2d -- Linha Final: %2d\n", colunaInicio, colunaFinal, linhaInicio, linhaFinal);
                if(celulasVizinhasVivas<2)
                    acaoDaCelulaAtual = 0; //Morte por subpopulação
                
                else if(celulasVizinhasVivas > 3)
                    acaoDaCelulaAtual = 0; //Morte por sufocamento
                
                else
                    acaoDaCelulaAtual = 1; //Se matém viva
                
            }
            else{
                if(celulasVizinhasVivas == 3)
                    acaoDaCelulaAtual = 1;
            }

            matriz[linha][coluna] = acaoDaCelulaAtual;

            celulasVizinhasVivas = 0; 

        }
    }

    //Printando resultado final
    printf("\n");
    for(int i =0; i<ordem; i++){
        for(int j = 0; j<ordem; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    //Desalocando matriz
    for(int i=0; i<ordem; i++)
        free(matriz[i]);
    
    free(matriz);

    matriz = NULL;

    return 0;
}