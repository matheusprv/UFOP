#include <stdio.h>
#include <math.h>

void menuPrincipal();
void menuAngulos();
void menuTemperaturas();

float grausParaRadianos(float);
float radianosParaGraus(float);

void calculaCelsius(float);
void calculaFahrenheit(float);
void calculaKelvin(float);

int main(){
    int opcao;

    menuPrincipal();
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            menuAngulos();
            break;
        case 2:
            menuTemperaturas();
            break;

        default:
            printf("Valor inválido");
    }

    return 0;
}

void menuPrincipal(){
    printf("### CONVERSOR DE UNIDADES ###");
	printf("\n1) Angulo");
	printf("\n2) Temperatura");
	printf("\nDigite uma opcao:");
}

void menuAngulos(){
    //Lê a unidade de origem e define qual função realizar
    int unidadeOrigem;
    float valorParaConverter;
	printf("\nQual a unidade de origem?");
	printf("\n1) Graus");
	printf("\n2) Radianos");
	printf("\nSelecione uma opcao: ");
	
	scanf("%d", &unidadeOrigem);
	
	switch(unidadeOrigem){
		case 1:
            printf("\nDigite o valor em Graus: ");
            scanf("%f", &valorParaConverter);
			printf("\nValor em Radianos: %.2f", grausParaRadianos(valorParaConverter));
			break;
		case 2:
            printf("\nDigite o valor em Graus: ");
            scanf("%f", &valorParaConverter);
			printf("\nValor em Graus: %.2f", radianosParaGraus(valorParaConverter));
			break;
		default:
			printf("\nValor inválido");
	}
    
}

float grausParaRadianos(float valorParaConverter){
    return valorParaConverter * M_PI / 180.0;
}

float radianosParaGraus(float valorParaConverter){
    return valorParaConverter * 180.0 / M_PI;
}

void menuTemperaturas(){
    //Lê a unidade de origem e define qual função realizar
    int unidadeOrigem;
    float valorParaConverter, celsius, fahrenheit, kelvin;

	printf("Qual a unidade de origem?");
	printf("\n1) Celsius");
	printf("\n2) Fahrenheit");
	printf("\n3) Kelvin");
	printf("\nSelecione uma opcao: ");
	
	scanf("%d", &unidadeOrigem);
	
	switch(unidadeOrigem){
		case 1:
            printf("\nDigite o valor em Celsius: ");
            scanf("%f", &valorParaConverter);
			calculaCelsius(valorParaConverter);
			break;
		case 2:
            printf("\nDigite o valor em Fahrenheit: ");
            scanf("%f", &valorParaConverter);
			calculaFahrenheit(valorParaConverter);
			break;
		case 3:
            printf("\nDigite o valor em Kelvin: ");
            scanf("%f", &valorParaConverter);
			calculaKelvin(valorParaConverter);
			break;
		default:
			printf("\nValor inválido");
	}
}

void calculaCelsius(float celsius){
    printf("\nValor em Fahrenheit: %.2f", (celsius * (9.0/5.0) + 32));
	printf("\nValor em Kelvin: %.2f", (celsius + 273.15));
}
void calculaFahrenheit(float fahrenheit){
    printf("\nValor em Celsius: %.2f", ((fahrenheit - 32.0) * 5.0/9.0));
    printf("\nValor em Kelvin: %.2f", ((fahrenheit - 32.0) * 5.0/9.0 + 273.15));
}
void calculaKelvin(float kelvin){
    printf("\nValor em Celsius: %.2f", (kelvin - 273.15));
    printf("\nValor em Fahrenheit: %.2f", (kelvin -273.15) * 9.0/5.0 + 32 );
}