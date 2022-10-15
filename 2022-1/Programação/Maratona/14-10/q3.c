#include <stdio.h>

int main(){

    int n, dias = 0;;
    float c;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        dias = 0;
        scanf("%f", &c);
        while(c>1){
            c /= 2;
            dias++;
        }
        printf("%d dias\n",dias);
    }

    return 0;
}