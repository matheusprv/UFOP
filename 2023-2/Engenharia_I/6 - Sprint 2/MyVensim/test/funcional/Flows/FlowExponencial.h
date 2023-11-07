#ifndef FLOWEXPONENCIAL_H
#define FLOWEXPONENCIAL_H

#include "../../../src/Flow.h"

class FlowExponencial : public Flow{
public:
    FlowExponencial();
    FlowExponencial(const string & name, System * source, System * target);

    virtual double executeEquation();
};

#endif