#include "SystemImpl.h"

// Construtores
SystemImpl :: SystemImpl(){
    name = "";
    value = 0.0;
}

SystemImpl :: SystemImpl(const string& name, const double& value){
    this->name = name;
    this->value = value;
}

SystemImpl :: SystemImpl(const string& name){
    this->name = name;
    this->value = 0.0;
}

SystemImpl :: SystemImpl(const double& value){
    this->name = "";
    this->value = value;
}

SystemImpl :: SystemImpl (System & system){
    this->name = system.getName();
    this->value = system.getValue();
}

//Destrutor
SystemImpl :: ~SystemImpl(){}

//Getters and setters
string SystemImpl :: getName() const{
    return name;
}
void SystemImpl :: setName(const string & name){
    this->name = name;
}

double SystemImpl :: getValue() const{
    return value;
}
void SystemImpl :: setValue(const double & value){
    this->value = value;
}

//Sobrecarga de operadores
SystemImpl& SystemImpl :: operator=(const SystemImpl& system){
    if(this == &system) return *this;

    name = system.getName();
    value = system.getValue();

    return *this;
}

bool SystemImpl :: operator==(const System& s1) const{
    if( name != s1.getName()) return false;
    if( value != s1.getValue()) return false;
    return true;
}

ostream & operator << (ostream & out, const SystemImpl & system){
    out << "Name: " << system.getName() << ", Value: " << system.getValue() << endl;
    return out;
}