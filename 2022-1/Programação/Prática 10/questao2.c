#include <stdio.h>

typedef struct {
    double real;
    double imaginario;
} Complexo;
        
// funcao que retorna x + y
Complexo somaComplexo(Complexo x, Complexo y);
        
// funcao que retorna x - y
Complexo subComplexo(Complexo x, Complexo y);
        
// função que retorna x * y
Complexo multComplexo(Complexo x, Complexo y);

int main(){

    Complexo x, y, resultado;

    printf("Digite os valores de a e b (x = a + bi): ");
    scanf("%lf%lf", &x.real, &x.imaginario);

    printf("Digite os valores de c e d (y = c + di): ");
    scanf("%lf%lf", &y.real, &y.imaginario);

    getchar();

    char operacao;
    printf("Digite a operação (+, - ou *): ");
    scanf("%c", &operacao);

    printf("Resultado: ");
    if(operacao == '+'){
        resultado=somaComplexo(x,y);
    }
    else if(operacao == '-'){
        resultado = subComplexo(x,y);
    }
    else{
        resultado = multComplexo(x,y);
    }

    printf("%.1lf %c %.1lfi\n", resultado.real, operacao, resultado.imaginario);


    return 1;
}

// funcao que retorna x + y
Complexo somaComplexo(Complexo x, Complexo y){
    Complexo resultado;
    resultado.real = x.real + y.real;
    resultado.imaginario = x.imaginario + y.imaginario; 
    return resultado;
}
        
// funcao que retorna x - y
Complexo subComplexo(Complexo x, Complexo y){
    Complexo resultado;
    resultado.real = x.real - y.real;
    resultado.imaginario = x.imaginario - y.imaginario; 
    return resultado;
}
        
// função que retorna x * y
Complexo multComplexo(Complexo x, Complexo y){
    //A - real do x
    //B - imaginario do X
    //C - real do Y
    //D - imaginario do Y
    Complexo resultado;
    resultado.real = (x.real*y.real) - (x.imaginario*y.imaginario);
    resultado.imaginario = (x.real*y.imaginario) + (x.imaginario*y.real);
    return resultado;
}