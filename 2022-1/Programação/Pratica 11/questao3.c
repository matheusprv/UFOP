//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include <stdio.h>
#include <stdlib.h>

int multiplicaMatrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q);
void liberaMatriz(int **, int);

int main(){

    int n, m, p, q;
    int **A, **B, **R;

    printf("Digite os tamanhos da matriz A: ");
    scanf("%d%d", &n, &m);
    A = malloc(n*sizeof(int*));

    printf("Digite os dados da matriz A:\n");
    for(int i=0; i<n; i++){
        A[i] = malloc(m*sizeof(int));
        for(int j=0; j<m; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite os tamanhos da matriz B: ");
    scanf("%d%d", &p, &q);
    
    B = malloc(p*sizeof(int*));
    printf("Digite os dados da matriz B:\n");
    
    for(int i=0; i<p; i++){

        B[i] = malloc(q*sizeof(int));

        for(int j=0; j<q; j++){
            scanf("%d", &B[i][j]);
        }

    }

    if(multiplicaMatrizes(&R, A, n, m, B, p, q)){
        printf("Resultado de A x B:\n");

        for(int i =0; i<n; i++){
            for(int j = 0; j<q; j++){
                printf("%d ", R[i][j]);
            }
            printf("\n");
        }
        liberaMatriz(R, n);
        
    }
    else{
        printf("Não é possível multiplicar as matrizes A e B.\n");
    }
    
    liberaMatriz(A, n);
    liberaMatriz(B, p);
    
    return 0;
}

void liberaMatriz(int **matriz, int i){
    for(int x=0; x<i; x++){
        free(matriz[x]);
    }
    free(matriz);
}

int multiplicaMatrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q){
    if(m == p){
        
        *R = calloc(n, sizeof(int*));
        for(int i=0; i<n; i++)
   		    (*R)[i] = calloc(q, sizeof(int));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < q; j++){
                for (int k = 0; k < m; k++){
                    (*R)[i][j] += A[i][k] * B[k][j];
                }
            }            
        }

        return 1;
    }
    else{
        return 0;
    }
}

//2 3 2 5 9 3 6 8 3 2 2 7 4 3 5 2

