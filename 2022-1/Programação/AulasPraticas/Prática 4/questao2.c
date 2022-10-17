#include <stdio.h>
#include <math.h>

int calculaRaizes(float a, float b, float c, float *x1, float *x2);

int main(){
	float a, b, c, x1, x2;
	printf("Digite os valores de a, b , c:");
	scanf("%f%f%f", &a, &b, &c);
	
	int resultado = calculaRaizes(a, b, c, &x1, &x2);
	
	if(resultado == 0){
		printf("Não foi possível calcular as raízes!");
	}
	else{
		printf("x1 = %.2f", x1);
		printf("\nx2 = %.2f", x2);
	}
	 
	return 0;
}

int calculaRaizes(float a, float b, float c, float *x1, float *x2){
	float delta = b*b - 4*a*c;
	
	if(delta<0){
		return 0;
	}
	else{
		float raizQuadrada = sqrt(delta);
		*x1 = (-b + raizQuadrada) / (2.0*a);
		*x2 = (-b - raizQuadrada) / (2.0*a);
		return 1;
	}
} 
