#include "FlowLogistico.h"

FlowLogistico :: FlowLogistico(const string & name, System * source, System * target) : FlowImpl (name, source, target) {}

double FlowLogistico :: executeEquation(){
    double p2 = getTarget()->getValue();
    return 0.01 * p2 * (1 - p2 / 70);
}