#include <stdio.h>
#include "f91.h"

int main (){
    int n;
    scanf("%d", &n);
    while(n!=0){
        printf("f91(%d) = %d\n", n, f91(n));
        scanf("%d", &n);
    }

    return 0;
}