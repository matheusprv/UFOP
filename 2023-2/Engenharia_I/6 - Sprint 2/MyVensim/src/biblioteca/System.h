#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class System{
    string name;
    double value;

public: 
    System();
    System(const string& name, const double& value);

    virtual ~System(){}

    string getName() const;
    void setName(const string& name);

    double getValue() const;
    void setValue(const double& newValue);
};

#endif