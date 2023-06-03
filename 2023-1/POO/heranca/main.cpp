#include <iostream>
#include "veiculo_utilitario.h"
#include <string>

using namespace std;

int main(){

    VeiculoPasseio v1 (300.0, "Fiat Toro", 1500, 400);
    cout << v1.getNome()<<endl;
    cout << v1;

    VeiculoUtilitario v2 (400.0, "Jeep Compass", 1500, 400, 150);
    cout << v2.getNome()<<endl;
    cout << v2;

    //cout << "Nome: " << v1.getNome() << endl;

    return 0;
}