#ifndef VEICULO_PASSEIO_H
#define VEICULO_PASSEIO_H

#include "veiculo.h"
#include <iostream>


class VeiculoPasseio : virtual public Veiculo {
    double volumeInterno;

public:
    VeiculoPasseio(double = 0.0, const string& = "", double = 0.0, int = 0);

    double getVolumeInterno() const;
    void setVolumeInterno(double volumeInterno);

    double pesoPotencia();

    void serialize(ostream&) const;
    friend ostream& operator <<(ostream& out, const VeiculoPasseio &);

};

#endif