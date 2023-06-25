#include "hourlyEmployee.h"
#include <iostream>
using namespace std;

HourlyEmployee :: HourlyEmployee(double wage = 0, double hours = 0, string firstName = "", string lastName = "", string socialSecurityNumber = "")
    : Employee (firstName, lastName, socialSecurityNumber){
    this->wage = wage;
    this->hours = hours;
}

double HourlyEmployee :: getWage(){
    return this->wage;
}
double HourlyEmployee :: getHours(){
    return this->hours;
}

double HourlyEmployee :: setWage(double wage){
    this->wage = wage;
}
double HourlyEmployee :: setHours(double hour){
    this->hours = hours;
}

double HourlyEmployee :: earnings (){
    return getHours() * getWage();
}

void HourlyEmployee :: print(){
    Employee :: print();
    cout << "Hourly wage: " << getWage() 
        << "Hours worked: " << getHours() << "\n";
}

