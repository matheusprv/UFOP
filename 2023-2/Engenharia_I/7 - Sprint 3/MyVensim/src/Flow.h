
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
    /** @brief Name of the Flow */
    string name;
    /** @brief Pointer to source System */
    System* source;
    /** @brief Pointer to target System */
    System* target;

public:
    /**
     * @brief   Default constructor for Flow.
    */
    Flow();

    /**
     * @brief   Constructor for the Flow class with parameters.
     * @param   name Name of the flow.
     * @param   source Pointer to the source system.
     * @param   target Pointer to the target system.
    */
    Flow(const string& name, System* source, System* target);

    /**
     * @brief   Constructor for the Flow class with a name.
     * @param   name Name of the flow.
    */
    Flow(const string& name);

    /**
     * @brief   Constructor for the Flow class with source and target systems.
     * @param   source  Pointer to the source system.
     * @param   target  Pointer to the target system.
    */
    Flow(System* source, System* target);

    /**
     * @brief   Copy constructor for the Flow class.
     * @param   flow  Flow object to be copied.
    */
    Flow(Flow& flow);

    /**
     * @brief   Virtual destructor for the Flow class.
    */
    virtual ~Flow();

    /**
     * @brief   Get the source system of the flow.
     * @return  Pointer to the source system.
    */
    System* getSource() const;
    
    /**
     * @brief   Set the source system of the flow.
     * @param   source   Pointer to the source system.
    */
    void setSource(System * source);

    /**
     * @brief   Get the target system of the flow.
     * @return  Pointer to the target system.
    */
    System* getTarget() const;
    
    /**
     * @brief   Set the target system of the flow.
     * @param   target Pointer to the target system.
    */
    void setTarget(System * target);

    /**
     * @brief   Get the name of the flow.
     * @return  Name of the flow.
    */
    string getName() const;

    /**
     * @brief  Set the name of the flow.
     * @param  name Name of the flow.
     * @return No return value.
    */
    void setName(const string name);


    /**
     * @brief   Overload of operator equals to copy a Flow.
     * @param   flow Object to be copied.
     * @return  Reference to the copied Flow.
    */
    Flow& operator=(const Flow& flow);

    /**
     * @brief   Pure virtual function to execute the flow equation.
     * @return  Result of the equation.
    */
    virtual double executeEquation() = 0;

};

#endif
