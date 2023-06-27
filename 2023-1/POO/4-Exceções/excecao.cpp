#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


class DivideByZeroException : public runtime_error{
public:
    DivideByZeroException(const string &msg) :
        runtime_error(msg){}
};

double divisao(int a, int b){
    if(b == 0)
        throw DivideByZeroException("Divisão por zero\n");
    
    return static_cast<double>(a)/b;
}

int main(){

    int a, b;
    double c;

    while(cin >> a >> b){
        try{
            c = divisao(a, b);
            cout << "Resultado: " << c << endl;
        }
        catch(DivideByZeroException &e){
            cerr << "Error: " << e.what() << endl;
        }
        cout << "Digite dois números inteiros diferentes de zero\n";
    }


    return 0;
}