#ifndef FLOWCOMPLEXO_H
#define FLOWCOMPLEXO_H

#include "../../../src/Flow.h"

class FlowComplexo : public Flow{
public:
    FlowComplexo();
    FlowComplexo(const string & name, System * source, System * target);

    virtual ~FlowComplexo();

    virtual double executeEquation();
};

#endif