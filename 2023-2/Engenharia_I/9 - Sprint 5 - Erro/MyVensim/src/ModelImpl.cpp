#include "ModelImpl.h"
#include "SystemImpl.h"
#include "FlowImpl.h"

vector<Model*> ModelImpl::models;

// Construtores
ModelImpl :: ModelImpl(){
    name = "";
    systems.clear();
    flows.clear();    
}

ModelImpl :: ModelImpl(const string & name) : name(name){}

ModelImpl :: ModelImpl(ModelImpl & model){

    flows.clear();
    systems.clear();

    name = model.getName();
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());
    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());
}

// Destrutor
ModelImpl :: ~ModelImpl(){
    //Deleting systems
    systemsIterator systemIT = systemBegin();
    systemsIterator systemEndIT = systemEnd();
    for(;systemIT != systemEndIT; systemIT++)
        delete *(systemIT);
    
    //Deleting flows
    flowsIterator flowIT = flowsBegin();
    flowsIterator flowEndIT = flowsEnd();
    for(;flowIT != flowEndIT; flowIT++)
        delete *(flowIT);

    //Deleting models
    modelsIterator modelIT = models.begin();
    modelsIterator modelEndIT = models.end();
    for(;modelIT != modelEndIT; modelIT++)
        delete *(modelIT);

    systems.clear();
    flows.clear();
    models.clear();
}

// Getters e setters
string ModelImpl :: getName() const{
    return name;
}
void ModelImpl :: setName(const string & name){
    this->name = name;
}

// Informações dos containers
ModelImpl :: systemsIterator ModelImpl :: systemBegin(){
    return systems.begin();
}
ModelImpl :: systemsIterator ModelImpl :: systemEnd(){
    return systems.end();
}

ModelImpl :: flowsIterator ModelImpl :: flowsBegin(){
    return flows.begin();
}
ModelImpl :: flowsIterator ModelImpl :: flowsEnd(){
    return flows.end();
}

ModelImpl :: modelsIterator ModelImpl :: modelsBegin(){
    return models.begin();
}
ModelImpl :: modelsIterator ModelImpl :: modelsEnd(){
    return models.end();
}

int ModelImpl :: flowsSize(){
    return flows.size();
}
int ModelImpl :: systemsSize(){
    return systems.size();
}
int ModelImpl :: modelsSize(){
    return models.size();
}

// Outros métodos
bool ModelImpl :: add(Flow * flow){
    size_t original_size = flows.size();
    flows.push_back(flow);
    return (flows.size() > original_size);
}
bool ModelImpl :: add(System * system){
    size_t original_size = systems.size();
    systems.push_back(system);
    return (systems.size() > original_size);
}
bool ModelImpl :: add(Model * model){
    size_t original_size = models.size();
    models.push_back(model);
    return (models.size() > original_size);
}
bool Model :: add(Model * model){
    return ModelImpl :: add(model);
}

bool ModelImpl :: remove(System* system){
    for(systemsIterator it = systems.begin(); it < systems.end(); it++){
        if(*it == system){
            systems.erase(it);
            return true;
        }
    }
    return false;
}
bool ModelImpl :: remove(Flow* flow){
    for(flowsIterator it = flows.begin(); it < flows.end(); it++){
        if(*it == flow){
            flows.erase(it);
            return true;
        }
    }
    return false;
}

bool ModelImpl :: run(int initial_time, int final_time){

    // Verificando se os tempos são validos
    if(initial_time > final_time || initial_time < 0 || final_time < 0) return false;

    System *source, *target;
    int flows_size = flowsSize();

    vector<double> v;
    for(int i = 0; i < flows_size; i++) 
        v.push_back(0.0);
    
    // Executando o modelo
    flowsIterator flowIt;
    int time;
    for(time = initial_time; time < final_time; time++){
        
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

    return time == final_time;
}

void ModelImpl :: show(){
    systemsIterator it = systemBegin();

    while (it != systemEnd()){
        cout << *it;
    }
}

ModelImpl& ModelImpl :: operator=(const ModelImpl& model){
    if(this == &model) return *this;

    systems.clear();
    flows.clear();

    name = model.getName();

    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());
    
    return *this;
}

Model& ModelImpl :: createModel(string name){
    Model * model = new ModelImpl(name);
    add(model);
    return *model;
}

Model& Model :: createModel(string name){
    return ModelImpl :: createModel(name);
}

System& ModelImpl :: createSystem(string name, double value){
    System * system = new SystemImpl(name, value);
    add(system);
    return *system;
}