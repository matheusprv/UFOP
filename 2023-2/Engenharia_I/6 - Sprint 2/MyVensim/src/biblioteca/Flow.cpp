#include "Flow.h"

// Construtores 
Flow :: Flow(){
    this->name = "";
    this->source = NULL;
    this->target = NULL;
}

Flow :: Flow(const string & name, System * source, System * target) :
    name(name), source(source), target(target){};

Flow :: Flow(const string & name) : name(name){
    this->source = NULL;
    this->target = NULL;
};

Flow :: Flow(System * source, System * target){
    this->name = "";
    this->source = source;
    this->target = target;
}

Flow :: Flow(Flow & flow){
    this->name = flow.getName();
    this->source = flow.getSource();
    this->target = flow.getTarget();
}

// Destrutor
Flow :: ~Flow(){}

// Getters e setters
void Flow :: setSource(System * source){
    this->source = source;
}
System * Flow :: getSource() const{
    return this->source;
}

System * Flow :: getTarget() const{
    return this->target;
}
void Flow :: setTarget(System * target){
    this->target = target;
}

string Flow :: getName() const{
    return this->name;
}
void Flow :: setName(const string name){
    this->name = name;
}

// Sobrecarga de operadores
Flow& Flow :: operator=(const Flow& flow){
    if(this == &flow) return *this;

    this->name = flow.getName();
    this->source = flow.getSource();
    this->target = flow.getTarget();

    return *this;
}