#include "ModelImpl.h"
#include "SystemImpl.h"
#include "FlowImpl.h"

/// @brief Defining a name for the system vector
typedef vector<System*> :: iterator systemsIterator;
/// @brief Defining a name for the flow vector
typedef vector<Flow*> :: iterator flowsIterator;
/// @brief Defining a name for the model vector
typedef vector<Model*> :: iterator modelsIterator;


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
    for(systemsIterator system = systemBegin(); system != systemEnd();system++)
            delete *system;
    
    
    for(flowsIterator flow = flowsBegin(); flow != flowsEnd();flow++)
            delete *flow;


    for(modelsIterator it = modelsBegin(); it < modelsEnd(); it++){
        
        Model* m = dynamic_cast<Model*>(this);

        if(*it == m){
            models.erase(it);
            break;
        }
    }
}

// Getters e setters
string ModelImpl :: getName() const{
    return name;
}
void ModelImpl :: setName(const string & name){
    this->name = name;
}

// Informações dos containers
Model::systemsIterator ModelImpl :: systemBegin(){
    return systems.begin();
}
Model::systemsIterator ModelImpl :: systemEnd(){
    return systems.end();
}

Model::flowsIterator ModelImpl :: flowsBegin(){
    return flows.begin();
}
Model:: flowsIterator ModelImpl :: flowsEnd(){
    return flows.end();
}

Model:: modelsIterator ModelImpl :: modelsBegin(){
    return models.begin();
}
Model:: modelsIterator ModelImpl :: modelsEnd(){
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
int Model :: modelsSize(){
    return ModelImpl::modelsSize();
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
            delete system;
            return true;
        }
    }
    return false;
}
bool ModelImpl :: remove(Flow* flow){
    for(flowsIterator it = flows.begin(); it < flows.end(); it++){
        if(*it == flow){
            flows.erase(it);
            delete flow;
            return true;
        }
    }
    return false;
}
bool ModelImpl :: remove(Model* model){
    for(modelsIterator it = models.begin(); it < models.end(); it++){
        if(*it == model){
            models.erase(it);
            return true;
        }
    }
    return false;
}

int ModelImpl :: run(int initial_time, int final_time){

    // Verificando se os tempos são validos
    if(initial_time > final_time || initial_time < 0 || final_time < 0) return -1;

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

    return time;
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
    Model * model = new ModelHandle(name);
    add(model);
    return *model;
}

Model& Model :: createModel(string name){
    return ModelImpl :: createModel(name);
}

System& ModelImpl :: createSystem(string name, double value){
    System * system = new SystemHandle(name, value);
    add(system);
    return *system;
}




//Model Handle
    ModelHandle :: ModelHandle(const string & name){
        pImpl_->setName(name);
    }

    ModelHandle :: ~ModelHandle(){}

    void ModelHandle :: setName(const string & name){pImpl_->setName(name);}
    string ModelHandle :: getName() const{return pImpl_->getName();}
    systemsIterator ModelHandle :: systemBegin(){return pImpl_->systemBegin();}
    systemsIterator ModelHandle :: systemEnd(){return pImpl_->systemEnd();}
    flowsIterator ModelHandle :: flowsBegin(){return pImpl_->flowsBegin();}
    flowsIterator ModelHandle :: flowsEnd(){return pImpl_->flowsEnd();}
    modelsIterator ModelHandle :: modelsBegin(){return pImpl_->modelsBegin();}
    modelsIterator ModelHandle :: modelsEnd(){return pImpl_->modelsEnd();}
    int ModelHandle :: flowsSize(){return pImpl_->flowsSize();}
    int ModelHandle :: systemsSize(){return pImpl_->systemsSize();}
    int ModelHandle :: modelsSize(){return pImpl_->modelsSize();}
    bool ModelHandle :: remove(Flow * flow){return pImpl_->remove(flow);}
    bool ModelHandle :: remove(System * system){return pImpl_->remove(system);}
    bool ModelHandle :: remove(Model * model){return pImpl_->remove(model);}
    int ModelHandle :: run(int tempo_inicial, int tempo_final){return pImpl_->run(tempo_final, tempo_final);}
    Model& ModelHandle :: createModel(string name){return pImpl_->createModel(name);}
    bool ModelHandle :: add(Flow * flow){return pImpl_->add(flow);}
    bool ModelHandle :: add(System * system){return pImpl_->add(system);}
    bool ModelHandle :: add(Model* model){return pImpl_->add(model);}
    System& ModelHandle :: createSystem(string name, double value){return pImpl_->createSystem(name, value);}
    void ModelHandle :: show(){pImpl_->show();}