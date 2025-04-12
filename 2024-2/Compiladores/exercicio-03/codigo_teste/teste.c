#include <stdio.h>
// body of IMP program
int main() {
   // Vamos apresentar um programa Imp para o cálculo do fatorial de
   // um número inteiro.
   // Primeiro, vamos definir uma variável **n**, de tipo inteiro, e 
   // a inicializamos com o valor **0**.
   int n  = 0 ;
   // Em seguida, realizamos a leitura do valor do fatorial a ser calculado.
   scanf("%d",&n);
   // O próximo passo é definir uma variável inteira para armazenar o resultado
   // final. Vamos iniciá-la com o valor **1**.
   int result  = 1 ;
   // Agora, vamos repetir os próximos passos enquanto o valor **n** for maior que **0**.
   while ( 0 < n ) {
      result = result * n ;
      n = n - 1 ;
   }
   // Terminamos por imprimir o resultado.
   printf("%d",result);
   // Aqui finalizamos o codigo
   return 0;
}
