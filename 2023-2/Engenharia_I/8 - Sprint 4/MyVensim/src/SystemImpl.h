#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include <string>
#include <iostream>
#include "System.h"

using namespace std;
/**
* @brief   Definition of class SystemImpl, which represents the current value of the system
*/
class SystemImpl : public System{
protected:
    /** @brief Name of the SystemImpl */
    string name;
    /** @brief Current value of the system*/
    double value;

public: 
    // Construtores
    /**
     * @brief   Default constructor for SystemImpl.
    */
    SystemImpl();
    /**
     * @brief   Constructor for SystemImpl with name and value.
     * @param   name Name of the system.
     * @param   value Value of the system.
    */
    SystemImpl(const string& name, const double& value);
    /**
     * @brief   Constructor for SystemImpl with name.
     * @param   name Name of the system.
    */
    SystemImpl(const string& name);
    /**
     * @brief   Constructor for SystemImpl with value.
     * @param   value Value of the system.
    */
    SystemImpl(const double& value);
    /**
     * @brief   Copy constructor for the SystemImpl class.
     * @param   system SystemImpl object to be copied.
    */
    SystemImpl(System & system);

    // Destrutor
    /**
    * @brief   Virtual destructor for the SystemImpl class.
    */
    virtual ~SystemImpl();

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
     * @brief   Overload of operator equals to copy a SystemImpl.
     * @param   system Object to be copied.
     * @return  Reference to the copied SystemImpl.
    */
    System& operator=(const System& system);

    /**
     * @brief   Overload of operator == to compare two systems
     * @param   s1 Object to be compared.
     * @param   s2 Object to be compared.
     * @return  True if they are equals. False otherwise
    */
    bool operator==(const System& s1) const;

    /**
     * @brief   Overload of operator <<.
     * @param   out ostream reference that will display the system.
     * @param   system Object to be displayed.
     * @return  ostream with the system display format.
    */
    friend ostream & operator << (ostream & out, const SystemImpl & system);

};

#endif