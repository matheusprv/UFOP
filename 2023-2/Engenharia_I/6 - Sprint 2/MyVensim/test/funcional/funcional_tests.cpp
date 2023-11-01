#include "funcional_tests.h"

void exponentialFuncionalTest(){
    Model * model = new Model("Sistema Exponencial");
    
    System * system1 = new System("pop1", 100.0);
    System * system2 = new System("pop2", 100.0);

    FlowExponencial * exponencial = new FlowExponencial("exponencial", system1, system2);

    model->add(system1);
    model->add(system2);
    model->add(exponencial);

    model->run(1, 100);

    cout << "Imprimindo o modelo" << endl;
    model->showModel();
    cout << endl;
    
    delete model;
    delete system1;
    delete system2;
    delete exponencial;

}