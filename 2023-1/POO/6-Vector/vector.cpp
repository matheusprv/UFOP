#include <vector>
#include <list>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int>::iterator iterador;

int main(){

    vector <int> inteiros;
    vector <iterador> pares;

    for(int i=0; i<10; i++) 
        inteiros.push_back(i);
    
    for(vector<int>::iterator it = inteiros.begin(); it != inteiros.end(); it++){
        if(*it % 3 == 0)
            pares.push_back(it);
    }

    for(vector<int>::iterator it : pares){
        cout << *it << endl;
    }
    cout << "================================================================\n";


    vector <int> numeros;
    for(int i = 0; i < 20 ; i++){
        numeros.push_back(rand()%200);
    }

    for(int n : numeros)
        cout << n << "  ";
    cout << endl;

    sort(numeros.begin(), numeros.end());

    //Encontrando o iterador da posicao desejada para inserir um número
    vector<int>::iterator it = numeros.begin();
    for(int i = 0; i < 4; i++)
        it++;
    numeros.insert(it, 1000000);

    for(int n : numeros)
        cout << n << "  ";
    cout << endl;

    numeros.erase(it);

    for(int n : numeros)
        cout << n << "  ";
    cout << endl;
    

    return 0;
}
