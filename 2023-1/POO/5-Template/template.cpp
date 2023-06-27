#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

template <typename T1>
void printaVetor(vector<T1> vetor){
    for(auto v : vetor)
        cout << v << " ";
    cout << "\n";
}

template <class T>
T Soma (T a, T b){
    return a + b;
}

template <class T1, class T2>
bool print(T1 a, T2 b){
    cout << a << "  " << b << "\n";
    return true;
}

int main(){
    int a = 10, b = 5;
    double c = 3.4, d = 6.6;

    cout << Soma(a,b) << endl;
    cout << Soma(c,d) << endl;

    cout << print(a, d) << "\n";

    vector <int> vetor = {1,2,3,4,5,6};

    printaVetor(vetor);

}