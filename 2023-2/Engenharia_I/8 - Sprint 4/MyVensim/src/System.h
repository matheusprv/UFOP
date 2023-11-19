#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;
/**
* @brief   Definition of class System, which represents the current value of the system
*/
class System{
public: 
    // Destrutor
    /**
    * @brief   Virtual destructor for the System class.
    */
    virtual ~System(){};

    // Getters e setters
    /**
     * @brief   Get the name of the system.
     * @return  Name of the system.
    */
    virtual string getName() const = 0;
    /**
     * @brief  Set the name of the system.
     * @param  name Name of the system.
     * @return No return value.
    */
    virtual void setName(const string& name) = 0;

    /**
     * @brief   Get the value of the system.
     * @return  Value of the system.
    */
    virtual double getValue() const = 0;

    /**
     * @brief  Set the value of the flow.
     * @param  value Value of the flow.
     * @return No return value.
    */
    virtual void setValue(const double& newValue) = 0;

    //Sobrecarga de operadores
    /**
     * @brief   Overload of operator equals to copy a System.
     * @param   system Object to be copied.
     * @return  Reference to the copied System.
    */
    virtual System& operator=(const System& system) = 0;
    /**
     * @brief   Overload of operator == to compare two systems
     * @param   s1 Object to be compared.
     * @return  True if they are equals. False otherwise
    */
    virtual bool operator==(const System& s1) const = 0;
    /**
     * @brief   Overload of operator <<.
     * @param   out ostream reference that will display the system.
     * @param   system Object to be displayed.
     * @return  ostream with the system display format.
    */
    friend ostream & operator << (ostream & out, const System & system);

};

#endif