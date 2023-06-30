#include <iostream>
using namespace std;

class Conta{
    static int totalDeContas;
    int x;

public:
    Conta(int x = 0){
        totalDeContas++;
        this->x = x;
    }
    static int getTotalDeContas(){return totalDeContas;}
    
    int getX(){
        return this->x;
    }
};

int Conta::totalDeContas = 0;

int main(){
    cout << Conta::getTotalDeContas();
    Conta c1, c2, c3;
    cout << "\nContas" << Conta::getTotalDeContas();
    cout << "\nContas" << c1.getTotalDeContas();


    cout << "\n";
    return 0;
}