#include <iostream>
#include <typeinfo>
using namespace std;

class Base{
    virtual void f()=0;//método virtualmente puro
};

class Derivada : public Base{void f(){cout << "Derivada";}};
class Derivada2 : public Base{void f(){cout << "Derivada 2";}};

int main(){
    Base * a = new Base;
    Base * b = new Derivada;
    Base * c = new Derivada2;

    Base * vetor[3];
    vetor[0] = a;
    vetor[1] = b;
    vetor[2] = c;

    for(int i = 0; i < 3; i++){
        cout << typeid(vetor[i]).name() << "\n"; // COmo está no vetor de base, irá aparecer a base
    }

    cout << "\n\n";

    for(int i = 0; i < 3; i++){
        cout << typeid(*vetor[i]).name() << "\n"; //Para onde o ponteiro da posição do vetor está apontando? para as classes depois do igual na inicialização do ponteiro
    }

}
