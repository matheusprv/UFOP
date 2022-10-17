#include <stdio.h>

void converterCelsius(float celsius, float *fahrenheit, float *kelvin);

int main(){
	float celsius, fahrenheit, kelvin;
	
	printf("Digite o valor em Celsius: ");
	scanf("%f", &celsius);
	
	converterCelsius(celsius, &fahrenheit, &kelvin);
	
	printf("Fahrenheit: %.2f\n", fahrenheit);
	printf("Kelvin: %.2f\n", kelvin);
}


void converterCelsius(float celsius, float *fahrenheit, float *kelvin){
	*fahrenheit = celsius * (9.0/5.0) + 32;
	*kelvin = celsius + 273.15;
}
