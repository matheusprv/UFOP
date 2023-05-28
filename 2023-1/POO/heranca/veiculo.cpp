#include "veiculo.h"
#include <iostream>

Veiculo :: Veiculo(string nome, double peso, int potencia){
    this->nome = nome;
    this->peso = peso;
    this->potencia = potencia;
}

void Veiculo :: setNome(string nome){
    this->nome = nome;
}
void Veiculo :: setPeso(double peso){
    this->peso = peso;
}
void Veiculo :: setPotencia(int potencia){
    this->potencia = potencia;
}

string Veiculo :: getNome() const{
    return this->nome;
}
double Veiculo :: getPeso() const{
    return this->peso;
}
int Veiculo :: getPotencia() const{
    return this->potencia;
}

void Veiculo :: serialize(ostream & out) const{
    out << string("\nNome: ") << getNome()
        << string("\nPeso: ") << getPeso()
        << string("\nPotencia: ") << getPotencia();
}

ostream& operator <<(ostream& out, const Veiculo &obj){
    obj.serialize(out);
    return out;
}