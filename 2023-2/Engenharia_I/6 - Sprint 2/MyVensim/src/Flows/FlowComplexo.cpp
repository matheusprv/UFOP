#include "FlowComplexo.h"

FlowComplexo :: FlowComplexo() : Flow (){}
FlowComplexo :: FlowComplexo(const string & name, System * source, System * target) : Flow (name, source, target) {}
FlowComplexo :: FlowComplexo(const string & name) : Flow (name) {}
FlowComplexo :: FlowComplexo(System * source, System * target) : Flow(source, target) {}
FlowComplexo :: FlowComplexo(Flow & flow) : Flow (flow) {}

FlowComplexo :: ~FlowComplexo(){}

double FlowComplexo :: executeEquation(){
    return 0.01 * getSource()->getValue();
}