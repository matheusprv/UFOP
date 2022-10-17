#include <stdio.h>

int main(){
	float x1, x2, x3, y;
	printf("Entre com os valores de x1, x2 e x3:");
	scanf("%f", &x1);
	scanf("%f", &x2);
	scanf("%f", &x3);
	
	y = ((x1 + (x2*x2)+ (x3*x3))*(x1 + (x2*x2)+ (x3*x3))) - (x1*x2*x3)*(x1*x2*x3);
	
	printf("y = %.2f", y);
	
	return 0;
}
