#ifndef FLOWEXPONENCIAL_H
#define FLOWEXPONENCIAL_H

#include "../../../src/Flow.h"

/**
* @brief   Definition of class FlowExponencial, which extends the class Flow and implements the executeEquation
*/
class FlowExponencial : public Flow{
public:
    /**
     * @brief   Constructor for the FlowExponencial class with parameters.
     * @param   name Name of the flow.
     * @param   source Pointer to the source system.
     * @param   target Pointer to the target system.
     * @return  No return value.
    */
    FlowExponencial(const string & name, System * source, System * target);

    /**
     * @brief   Execute the equation of the flow
     * @param   No parameters.
     * @return  double value of the result of the equation
    */
    virtual double executeEquation();
};

#endif