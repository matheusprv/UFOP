#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class System {
private:
    string name;
    double value;

public:
    System() {}

    System(const string& name, const double& value) : name(name), value(value) {}

    virtual ~System(){}

    string getName() const {
        return name;
    }

    void setName(const string& newName) {
        name = newName;
    }

    double getValue() const {
        return value;
    }

    void setValue(const double& newValue) {
        value = newValue;
    }

};

class Flow{
    string name;
    System * source;
    System * target;

public:
    Flow(){}
    Flow(string name, System * source, System * target){
        this->name = name;
        this->source = source;
        this->target = target;
    }
    Flow(string name){
        this->name = name;
    }

    virtual ~Flow(){
        delete source;
        delete target;
    }

    System * getSource() const{
        return this->source;
    }

    void setSource(System * source){
        this->source = source;
    }

    void setTarget(System * target){
        this->target = target;
    }

    System * getTarget() const{
        return this->target;
    }

    virtual double executeEquation() = 0;

};

// class MyFlow : public Flow {
// public:
//     MyFlow() : Flow(){}

//     MyFlow(string name, System* source, System* target) : Flow(name, source, target){}

//     MyFlow(string name) : Flow(name){}

//     double executeEquation() override {
//         return 0.01 * this->getSource()->getValue();
//     }
// };

class Model{
    string name;
    vector<System*> systems;
    vector<Flow*> flows;

public:
    Model(){}
    virtual ~Model(){
        for(auto system : systems)
            delete system;
    
        for(auto flow : flows)
            delete flow;
    }

    string getName() const{
        return this->name;
    }

    void add(Flow * flow){
        flows.push_back(flow);
    }

    void add(System * system){
        systems.push_back(system);
    }

    bool run(int tempo_inicial, int tempo_final){

    }

    void showModel(){

    }

};


class MyFlow : public Flow {
public:
    MyFlow() : Flow(){}
    MyFlow(string name, System* source, System* target) : Flow(name, source, target){}
    MyFlow(string name) : Flow(name){}

    double executeEquation() override {
        return 0.01 * this->getSource()->getValue();
    }
};

int main(){
    System * Q1, * Q2, * Q3, * Q4, * Q5;

    MyFlow * f = new MyFlow("f", Q1, Q2);
    MyFlow * g = new MyFlow("g", Q1, Q3);
    MyFlow * r = new MyFlow("r", Q2, Q5);
    MyFlow * t = new MyFlow("t", Q2, Q3);
    MyFlow * u = new MyFlow("u", Q3, Q4);
    MyFlow * v = new MyFlow("v", Q4, Q1);

    Model m;
    m.add(Q1);
    m.add(Q2);
    m.add(Q3);
    m.add(Q4);
    m.add(Q5);
    m.add(f);
    m.add(g);
    m.add(r);
    m.add(t);
    m.add(u);
    m.add(v);

    m.run(1, 100);

    return 0;
}

// 1 - Sistema sozinho
int main(){
    Model m;
    System S1;
    m.add(&S1);
    m.run(1, 100);
    return 0;
}

// 2 - Fluxo sozinho
int main(){
    Model m;
    MyFlow F1;
    m.add(&F1);
    m.run(1, 100);
    return 0;
}

// 3 - Fluxo sem origem conectado a um sistema
int main(){
    Model m;
    MyFlow f1;
    System s1;
    m.add(&f1);
    m.add(&s1);
    f1.setTarget(&s1);
    m.run(1, 100);
    return 0;
}

// 4 - Sistema conectado a um fluxo
int main(){
    Model m;
    System S1;
    MyFlow F1;
    F1.setSource(&S1);
    m.add(&S1);
    m.add(&F1);
    m.run(1, 100);
    return 0;
}

// 5 - Sistema com um fluxo de entrada e outro de saída
int main(){
    Model m;
    System S1;
    MyFlow F1, F2;
    F1.setTarget(&S1);
    F2.setSource(&S1);
    m.add(&S1);
    m.add(&F1);
    m.add(&F2);
    m.run(1, 100);
    return 0;
}

// 6 - Dois sistemas conectados por um fluxo
int main(){
    Model m;
    System S1, S2;
    MyFlow F1;
    F1.setSource(&S1);
    F1.setTarget(&S2);
    m.add(&S1);
    m.add(&S2);
    m.add(&F1);
    m.run(1, 100);
}

// 6.1 - Sobrecarga do construtor
int main(){
    Model m;
    System S1, S2;
    MyFlow F1 ("F1", &S1, &S2);
    m.add(&S1);
    m.add(&S2);
    m.add(&F1);
    m.run(1, 100);
}

// 7 - Um sistema com dois fluxos de saída
int main(){
    Model m;
    System S1;
    MyFlow F1, F2;
    F1.setSource(&S1);
    F2.setSource(&S1);
    m.add(&S1);
    m.add(&F1);
    m.add(&F2);
    m.run(1, 100);
}

// 8 - Sistema com um fluxo de entrada e múltiplos fluxos de saída
int main(){
    Model m;
    System S1;
    MyFlow F1, F2, F3;
    F1.setTarget(&S1);
    F2.setSource(&S1);
    F3.setSource(&S1);
    m.add(&S1);
    m.add(&F1);
    m.add(&F2);
    m.add(&F3);
    m.run(1, 100);
    return 0;
}

// 9 - Sistema recebendo múltiplos fluxos
int main(){
    Model m;
    System S1;
    MyFlow F1, F2;
    F1.setTarget(&S1);
    F2.setTarget(&S1);
    m.add(&S1);
    m.add(&F1);
    m.add(&F2);
    m.run(1, 100);
}

// 10 - Sistema com múltiplos fluxos de entrada e um fluxo de saída
int main(){
    Model m;
    System S1;
    MyFlow F1, F2, F3;
    F1.setTarget(&S1);
    F2.setTarget(&S1);
    F3.setSource(&S1);
    m.add(&S1);
    m.add(&F1);
    m.add(&F2);
    m.add(&F3);
    m.run(1, 100);
}

int main(){
    Model m;
    System S1;
    MyFlow F1, F2, F3, F4;
    F1.setTarget(&S1);
    F2.setTarget(&S1);
    F3.setSource(&S1);
    F4.setSource(&S1);
    m.add(&S1);
    m.add(&F1);
    m.add(&F2);
    m.add(&F3);
    m.run(1, 100);
    return 0;
}

// 12 - Múltiplos sistemas e fluxos
int main(){
    Model m;
    System S1, S2, S3;
    MyFlow F1, F2, F3;
    F1.setTarget(&S1);
    F2.setSource(&S1);
    F2.setTarget(&S2);
    F3.setSource(&S2);
    F3.setTarget(&S3);
    m.run(1, 100);
    return 0;
}