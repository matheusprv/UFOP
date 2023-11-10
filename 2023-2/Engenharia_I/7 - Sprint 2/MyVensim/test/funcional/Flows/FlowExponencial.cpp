#include "FlowExponencial.h"

FlowExponencial :: FlowExponencial() : Flow (){}
FlowExponencial :: FlowExponencial(const string & name, System * source, System * target) : Flow (name, source, target) {}

double FlowExponencial :: executeEquation(){
    return 0.01 * getSource()->getValue();
}