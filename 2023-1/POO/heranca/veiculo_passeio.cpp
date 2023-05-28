#include "veiculo_passeio.h"
#include <iostream>
#include <string>

using std :: string;

VeiculoPasseio :: VeiculoPasseio (double volumeInterno, string nome, double peso, int potencia){
    Veiculo(nome, peso, potencia);
    this->volumeInterno = volumeInterno;
}

double VeiculoPasseio :: getVolumeInterno() const{
    return this->volumeInterno;
}
void VeiculoPasseio :: setVolumeInterno(double volumeInterno){
    this->volumeInterno = volumeInterno;
}   

double VeiculoPasseio :: pesoPotencia(){
    return this->getPeso() / this->getPotencia();
}

void VeiculoPasseio :: serialize(ostream & out) const{
    Veiculo :: serialize(out);
    out << string("\nVolumeInterno: ") << getVolumeInterno();
}

ostream& operator <<(ostream& out, const VeiculoPasseio &obj){
    obj.serialize(out);
    return out;
}