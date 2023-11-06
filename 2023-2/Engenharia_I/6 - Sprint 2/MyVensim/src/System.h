#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class System{
    string name;
    double value;

public: 
    // Construtores
    System();
    System(const string& name, const double& value);
    System(const string& name);
    System(const double& value);
    System(System & system);

    // Destrutor
    virtual ~System();

    // Getters e setters
    string getName() const;
    void   setName(const string& name);

    double getValue() const;
    void   setValue(const double& newValue);

    //Sobrecarga de operadores
    System& operator=(const System& system);
    friend ostream & operator << (ostream & out, const System & system);

};

#endif