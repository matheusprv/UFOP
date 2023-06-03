#include "veiculo_utilitario.h"
#include <iostream>
using std :: cout;

VeiculoUtilitario :: VeiculoUtilitario(double volumeInterno, string nome, double peso, int potencia, double carga) : 
    Veiculo(nome, peso, potencia),
    VeiculoCarga (carga, nome, peso, potencia),
    VeiculoPasseio (volumeInterno, nome, peso, potencia){
}

double VeiculoUtilitario :: pesoPotencia(){
    return VeiculoCarga :: pesoPotencia();
}

void VeiculoUtilitario :: serialize(ostream & out) const{
    Veiculo :: serialize(out);
    out << string("\nCarga: ") << getCarga();
    out << string("\nVolume Interno: ") << getVolumeInterno();
}

ostream& operator <<(ostream& out, const VeiculoUtilitario &obj){
    obj.serialize(out);
    return out;
}