#ifndef MODEL_H
#define MODEL_H

#include "System.h"
#include "Flow.h"
#include <vector>

class Model{
    string name;
    vector<System*> systems;
    vector<Flow*> flows;

public:
    Model();
    
    virtual ~Model();

    string getName() const;

    void add(Flow * flow);

    void add(System * system);

    bool run(int tempo_inicial, int tempo_final);

    void showModel();

};

#endif