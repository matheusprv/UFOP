#include "Model.h"

// Construtores
Model :: Model(){
    name = "";
    systems.clear();
    flows.clear();    
}

Model :: Model(const string & name) : name(name){}

Model :: Model(Model & model){

    flows.clear();
    systems.clear();

    name = model.getName();
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());
    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());
}

// Destrutor
Model :: ~Model(){}

// Getters e setters
string Model :: getName() const{
    return name;
}
void Model :: setName(const string & name){
    this->name = name;
}

// Informações dos containers
Model :: systemsIterator Model :: systemBegin(){
    return systems.begin();
}
Model :: systemsIterator Model :: systemEnd(){
    return systems.end();
}

Model :: flowsIterator Model :: flowsBegin(){
    return flows.begin();
}
Model :: flowsIterator Model :: flowsEnd(){
    return flows.end();
}

int Model :: flowsSize(){
    return flows.size();
}
int Model :: systemsSize(){
    return systems.size();
}


// Outros métodos
bool Model :: add(Flow * flow){
    size_t original_size = flows.size();
    flows.push_back(flow);
    return (flows.size() > original_size);
}
bool Model :: add(System * system){
    size_t original_size = systems.size();
    systems.push_back(system);
    return (systems.size() > original_size);
}

bool Model :: remove(System* system){
    for(systemsIterator it = systems.begin(); it < systems.end(); it++){
        if(*it == system){
            systems.erase(it);
            return true;
        }
    }
    return false;
}
bool Model :: remove(Flow* flow){
    for(flowsIterator it = flows.begin(); it < flows.end(); it++){
        if(*it == flow){
            flows.erase(it);
            return true;
        }
    }
    return false;
}

bool Model :: run(int initial_time, int final_time){

    // Verificando se os tempos são validos
    if(initial_time > final_time || initial_time < 0 || final_time < 0) return false;

    System *source, *target;
    int flows_size = flowsSize();

    vector<double> v;
    for(int i = 0; i < flows_size; i++) 
        v.push_back(0.0);
    
    // Executando o modelo
    flowsIterator flowIt;
    for(int time = initial_time; time < final_time; time++){
        
        flowIt = flowsBegin();

        for(int i = 0; i  < flows_size; i++){
            v[i] = (*flowIt)->executeEquation();
            flowIt++;
        }

        flowIt = flowsBegin();
        for(int i = 0; i < flows_size; i++){
            source = (*flowIt)->getSource();
            source->setValue(source->getValue() - v[i]);

            target = (*flowIt)->getTarget();
            target->setValue(target->getValue() + v[i]);

            flowIt++;
        }

    }

    return true;
}

void Model :: show(){
    systemsIterator it = systemBegin();

    while (it != systemEnd()){
        cout << *it;
    }
}

// Sobrecarga de operadores
Model& Model :: operator=(const Model& model){
    if(this == &model) return *this;

    systems.clear();
    flows.clear();

    name = model.getName();

    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());
    
    return *this;
}
