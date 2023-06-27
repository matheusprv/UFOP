#include "ponto.h"

int main(){

    Ponto p1 = Ponto(5, 10);
    Ponto p2 = Ponto(23, 57);

    Ponto p3 = p1+p2;

    cout << p3.getX() << endl;

    p3++;

    cout << p3.getX() << endl;


    return 0;
}