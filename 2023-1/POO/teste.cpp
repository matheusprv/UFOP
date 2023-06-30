#include <vector>
#include <iostream>
using namespace std;

class Cachorro{
public:
    void printaRaca(){cout << "Raça não definida\n";}
};

class Boxer : public Cachorro{
public:
    void printaRaca(){cout << "Boxer\n";}
};

class Cocker : public Cachorro{
public:
    void printaRaca(){cout << "Cocker Spaniel\n";}
};

class Schnauer : public Cachorro{
public:
    virtual void printaRaca(){cout << "Schnauer\n";}
};

class MiniatureSchnauuer : public Cachorro{
public:
    void printaRaca(){cout << "Miniatura Schnauuer\n";}
};

class StandardSchnauer : public Schnauer{
public:
    void printaRaca(){cout << "Standard Schnauuer\n";}
};

class GiantSchnauer : public Schnauer{
    public:
        void printaRaca(){cout << "Giant Schnauuer\n";}
};

int main(){

    Cachorro d;
    Boxer b;
    Cocker c;
    Schnauer s;
    MiniatureSchnauuer ms;
    StandardSchnauer ss;
    GiantSchnauer gs;

    Cachorro * dp;

    dp = &d; dp->printaRaca();
    dp = &b; dp->printaRaca();
    dp = &c; dp->printaRaca();
    dp = &s; dp->printaRaca();
    dp = &ms; dp->printaRaca();
    dp = &ss; dp->printaRaca();
    dp = &gs; dp->printaRaca();



    return 0;
}