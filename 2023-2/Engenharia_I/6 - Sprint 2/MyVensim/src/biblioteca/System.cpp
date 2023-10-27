#include <System.h>

System :: System(){}

System :: System(const string& name, const double& value){
    this->name = name;
    this->value = value;
}

System :: ~System(){}

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