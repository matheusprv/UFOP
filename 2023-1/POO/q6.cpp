#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


using namespace std;

class Veiculo{
    float preco;
    int peso, velocMax;

public:
    
    Veiculo(float preco, int peso, int velocMax){
        this->preco = preco;
        this->peso = peso;
        this->velocMax = velocMax;
    }

    float getPreco(){
        return preco;
    }

    virtual float precioFinal() = 0;

    ostream & serialize(ostream & out) const{
        out << "Preco: " << preco <<
               "\nPeso: " << peso <<
               "\nVelocidade max: " << velocMax << "\n";
        return out;
    }
};


class Carro : public Veiculo{
    string cor, modelo;
public:
    Carro(float preco = 0.0, int peso = 0, int velocMax = 0, string cor = "", string modelo = "") : Veiculo(preco, peso, velocMax){
        this->cor = cor;
        this->modelo = modelo;
    }

    float precioFinal(){
        return this->getPreco() * 1.45;
    }

    string getModelo(){
        return this->modelo;
    }

    friend ostream & operator << (ostream & out, const Carro & c);
};

ostream & operator << (ostream & out, const Carro & c){
    c.serialize(out);
    out << "Cor: " << c.cor << endl
        << "Modelo: " << c.modelo << endl;
    return out;
}


class Caminhao : public Veiculo{
    float cargaMaxima;
    int comprimento;

public:
    Caminhao(float preco, int peso, int velocMax, float cargaMaxima, int comprimento) :
    Veiculo(preco, peso, velocMax){
        this->cargaMaxima = cargaMaxima;
        this->comprimento = comprimento;
    }

    float precioFinal(){
        return this->getPreco() * 1.5;
    }

    friend ostream & operator << (ostream &out, const Caminhao & c);
};
ostream & operator << (ostream & out, const Caminhao & c){
    c.serialize(out);
    out << "Carga maxima: " << c.cargaMaxima << endl
        << "Comprimento: " << c.comprimento << endl;
    return out;
}



bool compara(Veiculo * a, Veiculo * b){

    Carro * carro1 = dynamic_cast<Carro *>(a);
    Carro * carro2 = dynamic_cast<Carro *>(b);

    if(carro1 && carro2){
        return carro1->precioFinal() < carro2->precioFinal();
    }
    return false;

}



typedef vector<Veiculo*>::iterator iterador;

class Concessionario{
    vector<Veiculo*> veiculos;

public:
    Concessionario(){}
    ~Concessionario(){}

    void adicionarVeiculo(Veiculo* veiculo){
        //veiculos.push_back(veiculo);
        veiculos.insert(veiculos.end(), veiculo);
    }

    void carroMaisCaro(){
        vector<Veiculo*>:: iterator it = max_element(veiculos.begin(), veiculos.end(), compara);
        Carro * temp = dynamic_cast<Carro *>(*it);
        cout << *temp;
    }

    vector<Veiculo*> getVeiculos(){
        return this->veiculos;
    }

    vector<iterador> buscaModelos(string modelo){
        vector<iterador> iteradores;

        Carro * temp;
        //Percorrendo o vetor de veiculos
        for(vector<Veiculo*>::iterator v = veiculos.begin(); v != veiculos.end(); v++){
            //Verificando se o veiculo é um carro
            if(typeid(*v) == typeid(class Carro)){
                //Transformando o veículo em carro
                temp = dynamic_cast<Carro *>(*v);
                //Verificando se o modelo é o desejado
                if(temp->getModelo() == modelo){
                    //Adicionando o carro no vetor de iteradores
                    iteradores.push_back(v);
                }
            }
        }
        
        return iteradores;
    }

};


int main(){
    
    Concessionario * c = new Concessionario();
    c->adicionarVeiculo(new Carro(40000, 2, 140, "vermelho", "fox"));
    c->adicionarVeiculo(new Caminhao(90000.0, 7, 110, 10.0F, 11));
    c->adicionarVeiculo(new Carro(22000, 1, 150, "prata", "sandero"));
    c->adicionarVeiculo(new Caminhao(90001.0, 7, 110, 10.0F, 11));
    c->adicionarVeiculo(new Carro(50000, 1, 190, "prata", "fiestinha do amor"));
    c->adicionarVeiculo(new Caminhao(90001.0, 7, 110, 10.0F, 11));

    //c->carroMaisCaro();

    vector<iterador> it = c->buscaModelos("fox");
    cout << it.size() << endl;
    for (iterador iter : it){
        Carro * temp = dynamic_cast<Carro*>(*iter);
        cout << temp << endl;
    }




































































/*
    vector<Veiculo*>::iterator iterador = max_element(veiculos.begin(), veiculos.end(), compara);
    Carro * temp = dynamic_cast<Carro*>(*iterador);
    cout << *temp;
*/
    return 0;


}
