//Matheus Peixoto Ribeiro Vieira - 22.1.4104
#include <stdio.h>
#include <stdlib.h>

// Recebe uma matriz e seus índices e retorna a matriz transposta
double** transposta(double **A, int m, int n);

// Aloca espaço para uma matriz m x n. Se não for possível criar a matriz retorna NULL
double** criaMatriz(int m, int n);

// libera o espaço utilizado por uma matriz
void liberaMatriz(double** A, int m);

int main(){

    int m, n;

    printf("Digite o valor de m e n: ");
    scanf("%d%d", &m, &n);

    double **matriz = criaMatriz(m, n);

    printf("Digite a matriz:");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

    printf("Transposta:\n");

    double **mTransposta = transposta(matriz, m, n);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%.0lf ", mTransposta[i][j]);
        }
        printf("\n");
    }

    liberaMatriz(matriz, m);
    liberaMatriz(mTransposta, n);

    return 0;
}

double** transposta(double **A, int m, int n){
    double **mTransposta = criaMatriz(n, m);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            mTransposta[j][i] = A[i][j];
        }
    }

    return mTransposta; 
}


double** criaMatriz(int m, int n){
    double **matriz = malloc(m * sizeof(double*));
    for(int i=0; i<m; i++){
        matriz[i] = malloc(n* sizeof(double));
    }
    return matriz;
}

void liberaMatriz(double** A, int m){
    for(int i=0; i<m;i++){
        free(A[i]);
    }
    free(A);
}
