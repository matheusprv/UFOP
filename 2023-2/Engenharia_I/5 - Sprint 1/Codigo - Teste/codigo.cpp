#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <functional>
using namespace std;

class System{
public:
    string name;
    double value;

    System(string name, double value){
        this->name = name;
        this->value = value;
    }

    System(){}

};

class Flow{
public:
    string name;
    System * input;
    System * output;

    function <double(double)> equation;

    double execute_equation(){
        return equation(input->value);
    }
};


int main(){
    System * pop1 = new System("pop1", 100);
    System * pop2 = new System("pop2", 200);

    Flow * exponencial = new Flow("exponencial")
    exponencial.setOrigin(&pop1);
    exponencial.setTarget(&pop2);
    exponencial.setEquation([](double input){
        return input * 0.01;
    });

    Model m;
    m.add(pop1);
    m.add(pop2);
    m.add(exponencial);
    m.run(100);

    return 0;
}