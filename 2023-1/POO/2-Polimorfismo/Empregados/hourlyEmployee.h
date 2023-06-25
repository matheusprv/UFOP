#ifndef HOURLY_H
#define HOURLY_H

#include "employee.h"

class HourlyEmployee : public Employee{
  double wage;
  double hours;

public:
    HourlyEmployee(double wage = 0, double hours = 0, string firstName = "", string lastName = "", string socialSecurityNumber = "");

    double getWage();
    double getHours();

    double setWage(double wage);
    double setHours(double hour);

    virtual double earnings(); //Função virtualmente pura
    virtual void print();
};

#endif