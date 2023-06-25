#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std :: string;

class Employee{
    string firstName;
    string lastName;
    string socialSecurityNumber;

public: 
    Employee(string firstName = "", string lastName = "", string socialSecurityNumber = "");
    string getFirstName() const;
    string getLastName() const;
    string getSocialSecurityNumber() const;
    void setFirstName(string);
    void setLastName(string);
    void setSocialSecurityNumber(string);

    virtual double earnings() const = 0; //Função virtualmente pura
    virtual void print() const;
};

#endif