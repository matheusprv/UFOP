#include "FlowExponencial.h"

FlowExponencial :: FlowExponencial() : Flow (){}
FlowExponencial :: FlowExponencial(const string & name, System * source, System * target) : Flow (name, source, target) {}
FlowExponencial :: FlowExponencial(const string & name) : Flow (name) {}
FlowExponencial :: FlowExponencial(System * source, System * target) : Flow(source, target) {}
FlowExponencial :: FlowExponencial(Flow & flow) : Flow (flow) {}

FlowExponencial :: ~FlowExponencial(){}

double FlowExponencial :: executeEquation(){
    return 0.01 * getSource()->getValue();
}