#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>
using namespace std;


int main(){

    vector <double> v(4);

    int posicao;
    double item;

    for(int i = 0; i < 5; i++){
        try{
            if(!(cin >> item >> posicao))
                throw invalid_argument("O argumento deve ser número");
            v.at(posicao) = item;
        }

        catch(out_of_range &e){
            cerr << e.what() << "\n";
        }
        // catch(invalid_argument &e){
        //     cerr << e.what() << endl;
        //     cin.clear();
        //     cin.ignore(numeric_limits<streamsize> :: max(), '\n');
        //}
        catch(...){
            cout << "Erro inesperado";
            cin.clear();
            cin.ignore(numeric_limits<streamsize> :: max(), '\n');
        }
    }

    for(auto i : v)
        cout << i << " - ";
    
    cout << endl; 
    return 0;
}