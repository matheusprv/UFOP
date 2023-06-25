#ifndef VEICULO_CARGA_H
#define VEICULO_CARGA_H

#include "veiculo.h"
#include <iostream>


class VeiculoCarga : virtual public Veiculo {
    double carga;

public:
    VeiculoCarga(double = 0.0, string = "", double = 0.0, int = 0);

    double getCarga() const;
    void setCarga(double carga);

    double pesoPotencia();

    void serialize(ostream&) const;
    friend ostream& operator <<(ostream& out, const VeiculoCarga &);

};

#endif