#ifndef FLOW_H
#define FLOW_H

#include "System.h"

#include <string>
using namespace std;

class Flow{
protected:
    string name;
    System * source;
    System * target;

public:
    // Construtores
    Flow();
    Flow(const string & name, System * source, System * target);
    Flow(const string & name);
    Flow(System * source, System * target);
    Flow(Flow & flow);

    // Destrutor
    virtual ~Flow();

    // Getters e setters
    System* getSource() const;
    void    setSource(System * source);

    System* getTarget() const;
    void    setTarget(System * target);

    string getName() const;
    void   setName(const string name);

    // Sobrecarga de operadores
    Flow& operator=(const Flow& flow);

    // Função puramente virtual
    virtual double executeEquation() = 0;

};

#endif