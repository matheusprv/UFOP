#include "Model.h"

// Construtores
Model :: Model(){
    name = "";
    systems.clear();
    flows.clear();    
}

Model :: Model(const string & name) : name(name){}

Model :: Model(Model & model){
    this->name = model.getName();
    this->flows.insert(this->flows.begin(), model.flows.begin(), model.flows.end());
    this->systems.insert(this->systems.begin(), model.systems.begin(), model.systems.end());
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

Model::containerSystems Model :: getSystems() const{
    return this->systems;
}
Model::containerFlows Model :: getFlows() const{
    return this->flows;
}

// Sobrecarga de operadores
Model& Model :: operator=(const Model& model){
    if(this == &model) return *this;

    name = model.getName();
    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());
    
    return *this;
}

ostream & operator << (ostream & out, const Model & model){
    out << "Model name: " << model.getName() << endl;

    for(System * system : model.getSystems()){
        out << *system;
    }
    
    return out;
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

bool Model :: run(int tempo_inicial, int tempo_final){

    // Verificando se os tempos são validos
    if(tempo_inicial > tempo_final || tempo_inicial < 0 || tempo_final < 0) return false;

    System *source, *target;
    int flows_size = flowsSize();

    vector<double> v;
    for(int i = 0; i < flows_size; i++) 
        v.push_back(0.0);
    
    // Executando o modelo
    flowsIterator flowIt;
    for(int tempo = tempo_inicial; tempo <= tempo_final; tempo++){
        
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
    cout << *this;
}