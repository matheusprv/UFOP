#ifndef VEICULO_H
#define VEICULO_H

#include <string>
#include <ostream>

using std :: string;
using std :: ostream;

class Veiculo{

    string nome;
    double peso;
    int potencia;

public:
    Veiculo(const string& = "", double = 0.0, int = 0);

    void setNome(string nome);
    void setPeso(double peso);
    void setPotencia(int potencia);

    string getNome() const;
    double getPeso() const;
    int getPotencia() const;

    void serialize(ostream&) const;
    friend ostream& operator <<(ostream& out, const Veiculo &);
};


#endif