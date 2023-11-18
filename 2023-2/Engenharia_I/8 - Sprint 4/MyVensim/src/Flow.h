
#ifndef FLOW_H
#define FLOW_H

#include "System.h"

#include <string>
using namespace std;

/**
* @brief   Definition of class Flow, which represents a conection between two systems.
*/
class Flow {
protected:
public:
    /**
     * @brief   Virtual destructor for the Flow class.
    */
    virtual ~Flow() {};

    /**
     * @brief   Get the source system of the flow.
     * @return  Pointer to the source system.
    */
    virtual System* getSource() const = 0;
    
    /**
     * @brief   Set the source system of the flow.
     * @param   source   Pointer to the source system.
    */
    virtual void setSource(System * source) = 0;

    /**
     * @brief   Get the target system of the flow.
     * @return  Pointer to the target system.
    */
    virtual System* getTarget() const = 0;
    
    /**
     * @brief   Set the target system of the flow.
     * @param   target Pointer to the target system.
    */
    virtual void setTarget(System * target) = 0;

    /**
     * @brief   Get the name of the flow.
     * @return  Name of the flow.
    */
    virtual string getName() const = 0;

    /**
     * @brief  Set the name of the flow.
     * @param  name Name of the flow.
     * @return No return value.
    */
    virtual void setName(const string name) = 0;


    /**
     * @brief   Overload of operator equals to copy a Flow.
     * @param   flow Object to be copied.
     * @return  Reference to the copied Flow.
    */
    virtual Flow& operator=(const Flow& flow) = 0;

    /**
     * @brief   Pure virtual function to execute the flow equation.
     * @return  Result of the equation.
    */
    virtual double executeEquation() = 0;

};

#endif
