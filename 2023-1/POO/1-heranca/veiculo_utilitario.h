#ifndef VEICULO_UTILITARIO_H
#define VEICULO_UTILITARIO_H

#include "veiculo.h"
#include "veiculo_carga.h"
#include "veiculo_passeio.h"

#include <iostream>



class VeiculoUtilitario : public VeiculoCarga, public VeiculoPasseio {

public:
    VeiculoUtilitario(double = 0.0, string = "", double = 0.0, int = 0, double = 0.0);

    double pesoPotencia();

    void serialize(ostream&) const;
    friend ostream& operator <<(ostream& out, const VeiculoUtilitario &);

};

#endif