#include <stdio.h>

void calcula_fatoriais(long long int * fatorial){
    fatorial[0] = 1;
    for(int i = 1; i <= 20; i++){
        fatorial[i] = i * fatorial[i-1];
    }
    
}

int main()
{
    long long int fatoriais [20];
    calcula_fatoriais(fatoriais);
    
    long long int m, n;
    
    while(scanf("%lld%lld", &m, &n) != EOF){
        printf("%lld\n", fatoriais[m] + fatoriais[n]);
    }

    return 0;
}