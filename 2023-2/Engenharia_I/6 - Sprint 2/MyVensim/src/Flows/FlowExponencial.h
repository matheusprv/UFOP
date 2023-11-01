#ifndef FLOWEXPONENCIAL_H
#define FLOWEXPONENCIAL_H

#include "../biblioteca/Flow.h"

class FlowExponencial : public Flow{
public:
    FlowExponencial();
    FlowExponencial(const string & name, System * source, System * target);
    FlowExponencial(const string & name);
    FlowExponencial(System * source, System * target);
    FlowExponencial(Flow & flow);

    virtual ~FlowExponencial();

    virtual double executeEquation();
};

#endif