#include <iostream>
#include "veiculo_utilitario.h"
#include <string>

using namespace std;

int main(){

    VeiculoPasseio v1 (300.0, "Fiat Toro", 1500, 400);
    //cout << v1;

    cout << "Nome: " << v1.getNome() << endl;

    return 0;
}