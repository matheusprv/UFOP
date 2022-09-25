#include <stdio.h>

int main(){
	int a, b, c, d, resultadoOperacao;
	printf("Entre com os valores de a, b, c, d:");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	
	resultadoOperacao = (a*a*a)*((b+c)/d);
	
	printf("x = %d", resultadoOperacao);
	
	return 0;
	
}