#include <stdio.h>

int main(){
	int n1, n2, n3;
	
	printf("Entre com os números:");
	scanf("%d%d%d", &n1, &n2, &n3);
	
	if(n1>=n2 && n1>=n3){
		if(n2>=n3){
			printf("\nMenor: %d", n3);
			printf("\nIntermediário: %d", n2);
		}
		else{
			printf("\nMenor: %d", n2);
			printf("\nIntermediário: %d", n3);
		}
		printf("\nMaior: %d", n1);
	}
	
	else if(n2>=n3){
		if(n1>=n3){
			printf("\nMenor: %d", n3);
			printf("\nIntermediário: %d", n1);
		}
		else{
			printf("\nMenor: %d", n1);
			printf("\nIntermediário: %d", n3);
		}
		printf("\nMaior: %d", n2);
	}
	
	else{
		if(n1>=n2){
			printf("\nMenor: %d", n2);
			printf("\nIntermediário: %d", n1);
		}
		else{
			printf("\nMenor: %d", n1);
			printf("\nIntermediário: %d", n2);
		}
		printf("\nMaior: %d", n3);
	}
	
	return 0;
}
