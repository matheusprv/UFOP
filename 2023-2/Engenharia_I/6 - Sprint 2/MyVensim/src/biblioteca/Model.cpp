#include "Model.h"

Model :: Model(){}
Model :: ~Model(){
    for(auto system : systems)
        delete system;

    for(auto flow : flows)
        delete flow;
}

string Model :: getName() const{
    return this->name;
}

void Model :: add(Flow * flow){
    flows.push_back(flow);
}

void Model :: add(System * system){
    systems.push_back(system);
}

bool Model :: run(int tempo_inicial, int tempo_final){

    System* source;
    System* destiny;

    // Vector created to avoid interfereance of intermediate values 
    vector<double> flowValue;
    for(int i = 0; i < flows.size(); i++) 
        flowValue.push_back(0.0);
    

    // Executing the model
    for(int tempo = tempo_inicial; tempo <= tempo_final; tempo++){
        
        for(int i = 0; i < flows.size(); i++)
            flowValue[i] = flows[i]->executeEquation();
        

        for(int i = 0; i < flows.size(); i++){
            source = flows[i]->getSource();
            source->setValue(source->getValue() - flowValue[i]);

            destiny = flows[i]->getTarget();
            destiny->setValue(destiny->getValue() + flowValue[i]);
        }

    }
}

void Model :: showModel(){

}