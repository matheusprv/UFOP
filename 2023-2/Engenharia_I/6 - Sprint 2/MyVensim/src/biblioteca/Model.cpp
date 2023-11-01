#include "Model.h"

// Construtores
Model :: Model(){
    this->clear();
}

Model :: Model(const string & name) : name(name){}

Model :: Model(Model & model){
    this->clear();

    this->name = model.getName();
    this->flows.insert(this->flows.begin(), model.flows.begin(), model.flows.end());
    this->systems.insert(this->systems.begin(), model.systems.begin(), model.systems.end());
}

// Destrutor
Model :: ~Model(){
    // for(auto system : systems)
    //     delete system;

    // for(auto flow : flows)
    //     delete flow;
}

// Getters e setters
string Model :: getName() const{
    return this->name;
}
void Model :: setName(const string & name){
    this->name = name;
}

// Sobrecarga de operadores
Model& Model :: operator=(const Model& model){
    if(this == &model) return *this;

    this->clear();

    this->name = model.getName();
    this->systems.insert(this->systems.begin(), model.systems.begin(), model.systems.end());
    this->flows.insert(this->flows.begin(), model.flows.begin(), model.flows.end());
    
    return *this;
}

// Outros métodos
void Model :: clear(){
    this->name.clear();
    this->systems.clear();
    this->flows.clear();
}

bool Model :: add(Flow * flow){
    int original_size = flows.size();
    flows.push_back(flow);
    return (flows.size() > original_size);
}
bool Model :: add(System * system){
    int original_size = systems.size();
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

    System *source, *target;

    // Vector criado para previnir a interferencia de valores intermediarios
    vector<double> flowValue;
    for(int i = 0; i < flows.size(); i++) 
        flowValue.push_back(0.0);
    

    // Executando o modelo
    for(int tempo = tempo_inicial; tempo <= tempo_final; tempo++){
        
        for(int i = 0; i < flows.size(); i++)
            flowValue[i] = flows[i]->executeEquation();

        for(int i = 0; i < flows.size(); i++){
            source = flows[i]->getSource();
            source->setValue(source->getValue() - flowValue[i]);

            target = flows[i]->getTarget();
            target->setValue(target->getValue() + flowValue[i]);
        }

    }

    return true;
}

void Model :: showModel(){

}