#include "FlowExponencial.h"

FlowExponencial :: FlowExponencial(const string & name, System * source, System * target) : FlowImpl (name, source, target) {}

double FlowExponencial :: executeEquation(){
    return 0.01 * getSource()->getValue();
}