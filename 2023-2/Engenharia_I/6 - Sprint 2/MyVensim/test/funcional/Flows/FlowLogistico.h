#ifndef FLOWLOGISTICO_H
#define FLOWLOGISTICO_H

#include "../../../src/Flow.h"

class FlowLogistico : public Flow{
public:
    FlowLogistico();
    FlowLogistico(const string & name, System * source, System * target);

    virtual double executeEquation();
};

#endif