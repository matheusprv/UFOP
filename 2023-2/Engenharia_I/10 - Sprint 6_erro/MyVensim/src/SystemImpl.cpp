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

bool SystemImpl :: operator==(const System& s1) const{
    if( name != s1.getName()) return false;
    if( value != s1.getValue()) return false;
    return true;
}

ostream & operator << (ostream & out, const SystemImpl & system){
    out << "Name: " << system.getName() << ", Value: " << system.getValue() << endl;
    return out;
}



//SystemHandle
SystemHandle :: SystemHandle(const string& name, const double& value){
    pImpl_->setName(name);
    pImpl_->setValue(value);
}
SystemHandle :: SystemHandle(System& system){}

SystemHandle :: ~SystemHandle(){}

string SystemHandle :: getName() const{
    return pImpl_->getName();
}
void SystemHandle :: setName(const string & name){
    pImpl_->setName(name);
}

double SystemHandle :: getValue() const{
    return pImpl_->getValue();
}
void SystemHandle :: setValue(const double & value){
    pImpl_->setValue(value);
}

System& SystemHandle :: operator=(const System& system){
    if(this == &system) return *this;

    pImpl_->setName(system.getName());
    pImpl_->setValue(system.getValue());

    return *this;
}

bool SystemHandle :: operator==(const System& s1) const{
    if( pImpl_->getName() != s1.getName()) return false;
    if( pImpl_->getValue() != s1.getValue()) return false;
    return true;
}