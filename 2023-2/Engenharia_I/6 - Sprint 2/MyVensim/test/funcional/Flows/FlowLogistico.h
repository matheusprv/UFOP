#ifndef FLOWLOGISTICO_H
#define FLOWLOGISTICO_H

#include "../../../src/biblioteca/Flow.h"

class FlowLogistico : public Flow{
public:
    FlowLogistico();
    FlowLogistico(const string & name, System * source, System * target);
    FlowLogistico(const string & name);
    FlowLogistico(System * source, System * target);
    FlowLogistico(Flow & flow);

    virtual ~FlowLogistico();

    virtual double executeEquation();
};

#endif