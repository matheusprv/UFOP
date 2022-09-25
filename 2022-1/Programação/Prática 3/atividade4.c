#include <stdio.h>

int main(){
	float salarioAntigo, salarioNovo;
	int codigoCargo;
	
	printf("Entre com o salário:");
	scanf("%f", &salarioAntigo);
	
	printf("Entre com o código do cargo:");
	scanf("%d", &codigoCargo);
	
	printf("\nAntigo: R$ %.2f", salarioAntigo);
	
	switch (codigoCargo){
		case 100:
			salarioNovo = salarioAntigo * 1.03;
			break;
		case 101:
			salarioNovo = salarioAntigo * 1.05;
			break;
		case 102:
			salarioNovo = salarioAntigo * 1.075;
			break;
		case 201:
			salarioNovo = salarioAntigo * 1.1;
			break;
		default:
			salarioNovo = salarioAntigo * 1.15;
	}
	
	printf("\nNovo: R$ %.2f", salarioNovo);
	printf("\nDiferença: R$ %.2f", salarioNovo-salarioAntigo);
		
	
	return 0;
}
