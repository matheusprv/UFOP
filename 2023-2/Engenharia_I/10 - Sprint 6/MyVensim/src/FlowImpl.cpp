#include "FlowImpl.h"

// Construtores 
FlowImpl :: FlowImpl(){
    this->name = "";
    this->source = NULL;
    this->target = NULL;
}

FlowImpl :: FlowImpl(const string & name, System * source, System * target) :
    name(name), source(source), target(target){};

FlowImpl :: FlowImpl(const string & name) : name(name){
    this->source = NULL;
    this->target = NULL;
};

FlowImpl :: FlowImpl(System * source, System * target){
    this->name = "";
    this->source = source;
    this->target = target;
}

FlowImpl :: FlowImpl(Flow& flow){
    this->name = flow.getName();
    this->source = flow.getSource();
    this->target = flow.getTarget();
}

// Destrutor
FlowImpl :: ~FlowImpl(){}

// Getters e setters
void FlowImpl :: setSource(System * source){
    this->source = source;
}
System * FlowImpl :: getSource() const{
    return source;
}

System * FlowImpl :: getTarget() const{
    return target;
}
void FlowImpl :: setTarget(System * target){
    this->target = target;
}

string FlowImpl :: getName() const{
    return name;
}
void FlowImpl :: setName(const string name){
    this->name = name;
}

// Sobrecarga de operadores
FlowImpl& FlowImpl :: operator=(const FlowImpl& flow){
    if(this == &flow) return *this;

    this->name = flow.getName();
    this->source = flow.getSource();
    this->target = flow.getTarget();

    return *this;
}

bool FlowImpl :: operator==(const Flow& flow) const{
    if(name != flow.getName()) return false;
    if(source != flow.getSource()) return false;
    if(target != flow.getTarget()) return false;
    return true;
}