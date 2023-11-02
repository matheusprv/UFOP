#include "FlowLogistico.h"

FlowLogistico :: FlowLogistico() : Flow (){}
FlowLogistico :: FlowLogistico(const string & name, System * source, System * target) : Flow (name, source, target) {}
FlowLogistico :: FlowLogistico(const string & name) : Flow (name) {}
FlowLogistico :: FlowLogistico(System * source, System * target) : Flow(source, target) {}
FlowLogistico :: FlowLogistico(Flow & flow) : Flow (flow) {}

FlowLogistico :: ~FlowLogistico(){}

double FlowLogistico :: executeEquation(){
    double value = getTarget()->getValue();
    return 0.01 * value * (1 - value / 70);
}