#include "FlowExponencial.h"

FlowExponencial :: FlowExponencial() : FlowImpl(){}

FlowExponencial :: FlowExponencial(const string & name, System * source, System * target) : FlowImpl (name, source, target) {}

FlowExponencial :: FlowExponencial(const string& name) : FlowImpl(name){}

FlowExponencial :: FlowExponencial(System* source, System* target) : FlowImpl (source, target) {}

double FlowExponencial :: executeEquation(){
    return 0.01 * getSource()->getValue();
}