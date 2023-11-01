#include "System.h"


// Construtores
System :: System(){
    name = "";
    value = 0.0;
}

System :: System(const string& name, const double& value){
    this->name = name;
    this->value = value;
}

System :: System(const string& name){
    this->name = name;
    this->value = 0.0;
}

System :: System(const double& value){
    this->name = "";
    this->value = value;
}

System :: System (System & system){
    this->name = system.getName();
    this->value = system.getValue();
}

//Destrutor
System :: ~System(){}

//Getters and setters
string System :: getName() const{
    return this->name;
}
void System :: setName(const string & name){
    this->name = name;
}

double System :: getValue() const{
    return this->value;
}
void System :: setValue(const double & value){
    this->value = value;
}

//Sobrecarga de operadores
System& System :: operator=(const System& system){
    if(this == &system) return *this;

    this->name = system.getName();
    this->value = system.getValue();

    return *this;
}

ostream & operator << (ostream & out, const System & system){
    out << "Name: " << system.getName() << ", Value: " << system.getValue() << endl;
    return out;
}