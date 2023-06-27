#include <iostream>
#include <stdexcept>
using namespace std;


class NumeroZero : public runtime_error{
public:
    NumeroZero(const string& msg) : runtime_error(msg){};
};

class NumeroNegativo : public runtime_error{
public:
    NumeroNegativo(const string& msg) : runtime_error(msg){};
};

int main(){

    short i;
    

    try{
        if(!(cin >> i))
            throw runtime_error("Run time error");
        if(i == 0){
            throw NumeroZero("i es igual a 0");
        }
        else if(i < 1)
            throw NumeroNegativo("i es negativo");
    }
    // catch(NumeroZero& e){
    //     cout << e.what() << endl;
    // }
    // catch(NumeroNegativo& e){
    //     cout << e.what() << endl;
    // }
    // catch(overflow_error& e){
    //     cout << e.what() << endl;
    // }
    catch(...) {
        cout << "Ocurrio un error inesperado" << endl;
    }


    return 0;
}