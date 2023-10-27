#include "Flow.h"

Flow :: Flow(){}

Flow :: Flow(string & name, System * source, System * target){
    this->name = name;
    this->source = source;
    this->target = target;
}

Flow :: Flow(string & name){
    this->name = name;
}

Flow :: ~Flow(){
    delete source;
    delete target;
}

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