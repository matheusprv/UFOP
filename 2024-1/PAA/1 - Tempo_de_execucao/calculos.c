#include <stdio.h>
#include <math.h>

int main(){
    int instancias[] = {10, 20, 30, 40, 50, 60};

    
    double segundos, minutos, horas, dias, mes, anos, decadas ,seculos, milenios;
    for(int i = 0; i < 6; i++){
        
        segundos = pow(3, instancias[i]) * pow(10, -6);
        minutos = segundos / 60.0;
        horas = minutos / 60.0;
        dias = horas / 24.0;
        mes = dias / 30.0;
        anos = dias / 365.0;
        decadas = anos / 10.0;
        seculos = anos / 100.0;
        milenios = anos / 1000.0;


        printf("Instância: %d\n", instancias[i]);
        printf("segundos:  %25lf\n", segundos);
        printf("minutos:   %25lf\n", minutos);
        printf("horas:     %25lf\n", horas);
        printf("dias:      %25lf\n", dias);
        printf("mes:       %25lf\n", mes);
        printf("anos:      %25lf\n", anos);
        printf("decadas:   %25lf\n", decadas);
        printf("seculos:   %25lf\n", seculos);
        printf("milenios:  %25lf\n", milenios);


        printf("\n\n");
    }

    return 0;
}