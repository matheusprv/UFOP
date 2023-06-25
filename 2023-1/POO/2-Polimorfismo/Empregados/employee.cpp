#include "employee.h"
#include <iostream>
using namespace std;

Employee :: Employee(string firstName, string lastName, string socialSecurityNumber){
    this->firstName = firstName;
    this->lastName = lastName;
    this->socialSecurityNumber = socialSecurityNumber;
}

string Employee :: getFirstName() const{
    return this->firstName;
}
string Employee :: getLastName() const{
    return this->lastName;
}
string Employee :: getSocialSecurityNumber() const{
    return this->socialSecurityNumber;
}
void Employee :: setFirstName(string FirstName){
    this->firstName = FirstName;
}
void Employee :: setLastName(string LastName){
    this->lastName = LastName;
}
void Employee :: setSocialSecurityNumber(string SocialSecurityNumber){
    this->socialSecurityNumber = SocialSecurityNumber;
}

void Employee :: print() const{
    cout << getFirstName() << " " << this->getLastName() << "\nSSID: " << this->getSocialSecurityNumber() << "\n";
}