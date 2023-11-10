#include "FlowComplexo.h"

FlowComplexo :: FlowComplexo(const string & name, System * source, System * target) : Flow (name, source, target) {}

double FlowComplexo :: executeEquation(){
    return 0.01 * getSource()->getValue();
}