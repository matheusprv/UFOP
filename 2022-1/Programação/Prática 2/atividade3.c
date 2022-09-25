#include <stdio.h>

int main(){
	float celsius, fahrenheit, kelvin;
	printf("Entre com o valor em graus Celsius:");
	scanf("%f", &celsius);
	
	fahrenheit = (9.0/5 * celsius) + 32;
	kelvin = celsius + 273.15;
	
	printf("Celsius: c = %.2f", celsius);
	printf("\nFahrenheit: f = %.2f", fahrenheit);
	printf("\nKelvin: k = %.2f", kelvin);
	
	return 0;
}