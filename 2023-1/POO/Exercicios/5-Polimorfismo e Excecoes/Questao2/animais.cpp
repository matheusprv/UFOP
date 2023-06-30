#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;
class Laurasiatheria{
    vector<Laurasiatheria*> vetor;

public:
    void emitirSom(){
        cout << "Laurasiatheria::emitirSom()" << endl;
    };

    void adicionarAnimal(Laurasiatheria * animal){
        vetor.push_back(animal);
    }

    void listAnimal(){
        for(Laurasiatheria * animal : vetor){
            animal->emitirSom();
            cout << "--------------------------------\n";
        }
    }

    virtual ~Laurasiatheria(){
        for(long unsigned int i = 0; i < vetor.size(); i++){
            delete vetor[i];
        }
    }

};

class Carnivora : public Laurasiatheria{
public:
    virtual void emitirSom(){
        cout << "Carnivora::emitirSom()" << endl;
    }
};

class Cao : public Carnivora{
public:
    void emitirSom(){
        cout << "Cao::emitirSom()" << endl;
    }
};

class Gato : public Carnivora{
public:
    void emitirSom(){
        cout << "Gato::emitirSom()" << endl;
    }
};

class Perissodactyla : public Laurasiatheria{
public: 
    virtual void emitirSom(){
        cout << "Perissodactyla::emitirSom()" << endl;
    }
};

class Cavalo : public Perissodactyla{
public:
    void emitirSom(){
        cout << "Cavalo::emitirSom()" << endl;
    }
};

class Artiodactyla : public Laurasiatheria{
    virtual void emitirSom(){
        cout << "Artiodactyla::emitirSom()" << endl;
    }
};

class Porco : public Artiodactyla{
public: 
    void emitirSom(){
        cout << "Porco::emitirSom()" << endl;
    }
};

class Boi : public Artiodactyla{
public: 
    void emitirSom(){
        cout << "Boi::emitirSom()" << endl;
    }
};

int main(){


    // Laurasiatheria animal;
    // animal.adicionarAnimal(new Cao());
    // animal.adicionarAnimal(new Gato());
    // animal.adicionarAnimal(new Porco());
    // animal.adicionarAnimal(new Cavalo());
    // animal.adicionarAnimal(new Boi());

    // animal.listAnimal();

    vector<Laurasiatheria*>animais;

    animais.push_back(new Cao());
    animais.push_back(new Gato());
    animais.push_back(new Porco());
    animais.push_back(new Boi());
    animais.push_back(new Cavalo());

    for (Laurasiatheria * animal : animais){
        animal->emitirSom();
        cout << "--------------------------------\n";
        delete animal;
    }

    return 0;
}