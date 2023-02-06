#include "r9.h"
#include <stdio.h>

int soma_r9(int n){
    if(n >= 9){
        return n%10 + soma_r9(n/10);
    }
    return n;
}