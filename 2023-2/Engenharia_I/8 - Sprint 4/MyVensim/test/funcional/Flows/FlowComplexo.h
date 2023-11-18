#ifndef FLOWCOMPLEXO_H
#define FLOWCOMPLEXO_H

#include "../../../src/FlowImpl.h"

/**
* @brief   Definition of class FlowComplexo, which extends the class Flow and implements the executeEquation
*/
class FlowComplexo : public FlowImpl{
public:
    /**
     * @brief   Constructor for the FlowComplexo class with parameters.
     * @param   name Name of the flow.
     * @param   source Pointer to the source system.
     * @param   target Pointer to the target system.
    */
    FlowComplexo(const string & name, System * source, System * target);

    /**
     * @brief   Execute the equation of the flow
     * @return  double value of the result of the equation
    */
    virtual double executeEquation();
};

#endif