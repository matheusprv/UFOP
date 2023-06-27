#include <iostream>
using namespace std;

class Mamiferos{
public:
    virtual void emitirSom(){ cout << "Som do mamifero. \n"; }
};


class Cachorro : public Mamiferos{
public: 
    void emitirSom(){cout << "Woof Woof\n";} 
};

class Gato : public Mamiferos{
public: 
    void emitirSom(){cout << "Miau Miau\n";} 
};

class Vaca : public Mamiferos{
public: 
    void emitirSom(){cout << "Moo Moo\n";} 
};

int main(){
    //-Todos os prints serão "Som do mamifero", pois a classe derivada está sendo transformada em classe base
    // Mamiferos mamiferos_estaticos[4] = {Cachorro(),Gato(),Vaca(),Cachorro()};
    // for(int i = 0; i < 4; i++){
    //     mamiferos_estaticos[i].emitirSom();
    // }

    cout << "\n\n";

    Mamiferos * dp;
    Cachorro d;
    Gato g;
    Vaca v;

    dp = &d; dp->emitirSom();
    dp = &g; dp->emitirSom();
    dp = &v; dp->emitirSom();

    cout << "\n\n";

    //Para que o polimorfismo ocorra, o vetor da classe base precisa receber ponteiros da classe derivada
    Mamiferos * mamiferos[4] = {
        new Cachorro(), //"Woof Woof"
        new Gato(), //"Miau Miau"
        new Vaca(), //"Moo Moo"
        new Cachorro() //"Woof Woof"
    };

    for(Mamiferos * mam : mamiferos)
        mam->emitirSom();

    for(int i = 0; i < 4; i++){
        delete(mamiferos[i]);
    }

    return 0;
}