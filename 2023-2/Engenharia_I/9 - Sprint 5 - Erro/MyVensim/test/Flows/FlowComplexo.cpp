#include "FlowComplexo.h"

FlowComplexo :: FlowComplexo() : FlowImpl(){}

FlowComplexo :: FlowComplexo(const string & name, System * source, System * target) : FlowImpl (name, source, target) {}

FlowComplexo :: FlowComplexo(const string& name) : FlowImpl(name){}

FlowComplexo :: FlowComplexo(System* source, System* target) : FlowImpl (source, target) {}

FlowComplexo :: FlowComplexo(Flow& flow) : FlowImpl(flow){}

double FlowComplexo :: executeEquation(){
    return 0.01 * getSource()->getValue();
}