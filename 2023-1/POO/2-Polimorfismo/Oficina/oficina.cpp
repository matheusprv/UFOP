#include <iostream>
using namespace std;

class Veiculo{
public:
    virtual void veriicarLista(){cout << "Lista\n";}
    virtual void reparar(){cout << "Reparar\n";}
    virtual void limpar(){cout << "Limpar\n";}
    virtual ~Veiculo(){};
};

class Moto : public Veiculo{
public:
    void veriicarLista(){cout << "Listar ajustes para a Moto\n";};
    void reparar(){cout << "Reparar a Moto\n";};
    void limpar(){cout << "Limpar a Moto\n";};
};

class Carro : public Veiculo{
public:
    void veriicarLista(){cout << "Listar ajustes para o Carro\n";};
    void reparar(){cout << "Reparar o Carro\n";};
    void limpar(){cout << "Limpar o Carro\n";};
};

class Oficina{
public:
    Veiculo * proximoVeiculo(int n);
    void manterVeiculo(Veiculo * v);
};

Veiculo * Oficina :: proximoVeiculo(int n){
    cout << n << "\n";

    if(n % 2 == 0) return (new Carro());
    else return (new Moto());
}
void Oficina :: manterVeiculo(Veiculo * v){
    v->veriicarLista();
    v->reparar();
    v->limpar();
}

int main(){
    Oficina oficina;
    Veiculo * v;

    for(int i = 0; i < 7; i++){
        v = oficina.proximoVeiculo(i);
        oficina.manterVeiculo(v);
        delete v;
    }

    return 0;
}