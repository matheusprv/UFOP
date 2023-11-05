#include "../src/Flows/FlowComplexo.h"
#include "../src/Flows/FlowLogistico.h"
#include "../src/Flows/FlowExponencial.h"

#include "../src/biblioteca/Model.h"


int main(){
    Model model ("Sistema Exponencial");
    
    System pop1("pop1", 100.0);
    System pop2("pop2", 0.0);

    FlowExponencial exponencial("exponencial", &pop1, &pop2);

    model.add(&pop1);
    model.add(&pop2);
    model.add(&exponencial);

    Model m1 = model;

    Model::containerSystems c = m1.getSystems();

    c[0]->setName("copia1");
    c[1]->setName("copia2");


    model.run(1, 100);

    cout << "Model original\n: ";
    model.showModel();
    cout << endl;

    cout << "Model Copia\n: ";
    m1.showModel();
    cout << endl;
    
    

    return 0;
}