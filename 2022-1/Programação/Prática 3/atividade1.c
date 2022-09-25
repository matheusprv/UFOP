#include <stdio.h>

int main(){
	int ano;
	printf("Entre com o ano:");
	scanf("%d", &ano);
	
	if(ano%4 == 0){
		if(ano%100 !=0 || ano%400 == 0){
			printf("O ano %d é bissexto", ano);
			return 0;
		}
	}
	printf("O ano %d não é bissexto", ano);

	return 0;
}
