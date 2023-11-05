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

    //typedefs
    typedef vector<System*> :: iterator systemsIterator;
    typedef vector<Flow*> :: iterator flowsIterator;

    typedef vector<System*> containerSystems;
    typedef vector<Flow*> containerFlows;


    // Construtores
    Model();
    Model(const string & name);
    Model(Model &model);
    
    // Destrutor
    virtual ~Model();

    // Getters e setters
    string getName() const;
    void setName(const string & name);

    containerSystems getSystems() const;
    containerFlows getFlows() const;

    //Sobrecarga de operadores
    Model& operator=(const Model& model);

    // Informações dos containers
    systemsIterator systemBegin();
    systemsIterator systemEnd();

    flowsIterator flowsBegin();
    flowsIterator flowsEnd();

    int flowsSize();
    int systemsSize();

    // Outros métodos
    void clear();

    bool add(Flow * flow);
    bool add(System * system);

    bool remove(Flow * flow);
    bool remove(System * system);

    bool run(int tempo_inicial, int tempo_final);

    void showModel();

};

#endif