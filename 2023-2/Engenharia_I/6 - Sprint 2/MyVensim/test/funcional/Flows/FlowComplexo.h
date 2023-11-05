#ifndef FLOWCOMPLEXO_H
#define FLOWCOMPLEXO_H

#include "../../../src/biblioteca/Flow.h"

class FlowComplexo : public Flow{
public:
    FlowComplexo();
    FlowComplexo(const string & name, System * source, System * target);
    FlowComplexo(const string & name);
    FlowComplexo(System * source, System * target);
    FlowComplexo(Flow & flow);

    virtual ~FlowComplexo();

    virtual double executeEquation();
};

#endif