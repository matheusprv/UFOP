#include "veiculo_carga.h"
#include <iostream>
#include <string>

using std :: string;

VeiculoCarga :: VeiculoCarga (double carga, string nome, double peso, int potencia) : Veiculo(nome, peso, potencia){
    this->carga = carga;
}

double VeiculoCarga :: getCarga() const{
    return this->carga;
}
void VeiculoCarga :: setCarga(double carga){
    this->carga = carga;
}   

double VeiculoCarga :: pesoPotencia(){
    return (this->getPeso() + this->getCarga()) / this->getPotencia();
}

void VeiculoCarga :: serialize(ostream & out) const{
    Veiculo :: serialize(out);
    out << string("\ncarga: ") << getCarga();
}

ostream& operator <<(ostream& out, const VeiculoCarga &obj){
    obj.serialize(out);
    return out;
}