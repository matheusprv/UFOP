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
protected:
    /** @brief Name of the System */
    string name;
    /** @brief Current value of the system*/
    double value;

public: 
    // Construtores
    /**
     * @brief   Default constructor for System.
    */
    System();
    /**
     * @brief   Constructor for System with name and value.
     * @param   name Name of the system.
     * @param   value Value of the system.
    */
    System(const string& name, const double& value);
    /**
     * @brief   Constructor for System with name.
     * @param   name Name of the system.
    */
    System(const string& name);
    /**
     * @brief   Constructor for System with value.
     * @param   value Value of the system.
    */
    System(const double& value);
    /**
     * @brief   Copy constructor for the System class.
     * @param   system System object to be copied.
    */
    System(System & system);

    // Destrutor
    /**
    * @brief   Virtual destructor for the System class.
    */
    virtual ~System();

    // Getters e setters
    /**
     * @brief   Get the name of the system.
     * @return  Name of the system.
    */
    string getName() const;
    /**
     * @brief  Set the name of the system.
     * @param  name Name of the system.
     * @return No return value.
    */
    void setName(const string& name);

    /**
     * @brief   Get the value of the system.
     * @return  Value of the system.
    */
    double getValue() const;

    /**
     * @brief  Set the value of the flow.
     * @param  value Value of the flow.
     * @return No return value.
    */
    void setValue(const double& newValue);

    //Sobrecarga de operadores
    /**
     * @brief   Overload of operator equals to copy a System.
     * @param   system Object to be copied.
     * @return  Reference to the copied System.
    */
    System& operator=(const System& system);
    /**
     * @brief   Overload of operator <<.
     * @param   out ostream reference that will display the system.
     * @param   system Object to be displayed.
     * @return  ostream with the system display format.
    */
    friend ostream & operator << (ostream & out, const System & system);

};

#endif