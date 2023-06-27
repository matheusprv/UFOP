#include <iostream>
using namespace std;

class Base {
    static int x;
    int id, id2;

public:
    //Base(int id = 1) : id((++x) * id){}
    Base(int id = 1) {
        this->id = this->id2 = (++x) * id;
    }

    static int getX(){
        return x;
    }

    int getID(){
        return this->id;
    }

    int getID2(){
        return this->id2;
    }

};

int Base :: x = 0;

int main(){
    cout << "Valor atual de X: " << Base :: getX() << endl;

    Base obj1 = Base();
    Base obj2 = Base(50);

    cout << "Objeto 1: " << obj1.getID() << " " << obj1.getID2() << endl;
    cout << "Objeto 2: " << obj2.getID() << " " << obj2.getID2() << endl;
    return 0;
}