#ifndef FLOWEXPONENCIAL_H
#define FLOWEXPONENCIAL_H

#include "../../src/FlowImpl.h"

/**
* @brief   Definition of class FlowExponencial, which extends the class Flow and implements the executeEquation
*/
class FlowExponencial : public FlowImpl{
public:

    /**
     * @brief   Default constructor for FlowExponencial.
    */
    FlowExponencial();

    /**
     * @brief   Constructor for the FlowExponencial class with parameters.
     * @param   name Name of the flow.
     * @param   source Pointer to the source system.
     * @param   target Pointer to the target system.
    */
    FlowExponencial(const string & name, System * source, System * target);

    /**
     * @brief   Constructor for the FlowExponencial class with a name.
     * @param   name Name of the flow.
    */
    FlowExponencial(const string& name);

    /**
     * @brief   Constructor for the FlowExponencial class with source and target systems.
     * @param   source  Pointer to the source system.
     * @param   target  Pointer to the target system.
    */
    FlowExponencial(System* source, System* target);

    /**
     * @brief   Copy constructor for the FlowExponencial class.
     * @param   flow  FlowExponencial object to be copied.
    */
    FlowExponencial(Flow& flow);

    /**
     * @brief   Execute the equation of the flow
     * @return  double value of the result of the equation
    */
    virtual double executeEquation();
};

#endif