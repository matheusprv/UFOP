#include <stdio.h>

int main(){
	float altura, peso;
	
	printf("Entre com o peso:");
	scanf("%f", &peso);
	
	printf("Entre com a altura:");
	scanf("%f", &altura);
	
	float imc = peso/(altura*altura);
	
	if(imc<18.5){
		printf("Abaixo do peso");
	}
	else if(imc<25){
		printf("Peso normal");
	}
	else if(imc<30){
		printf("acima do peso");
	}
	else{
		printf("Obeso");
	}
	return 0;
	
}
