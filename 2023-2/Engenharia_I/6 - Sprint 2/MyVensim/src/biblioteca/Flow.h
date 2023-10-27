#ifndef FLOW_H
#define FLOW_H

#include "System.h"

#include <string>
using namespace std;

class Flow{
    string name;
    System * source;
    System * target;

public:
    Flow(){}
    Flow(string & name, System * source, System * target);
    Flow(string & name);

    virtual ~Flow();

    System * getSource() const;
    void setSource(System * source);

    System * getTarget() const;
    void setTarget(System * target);

    virtual double executeEquation() = 0;

};

#endif