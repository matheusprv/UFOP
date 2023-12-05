#include "unit_model.h"

void unit_Model_constructor_default(){
    Model & model = Model::createModel();

    assert(model.getName() == "");
    assert(model.flowsSize() == 0);
    assert(model.systemsSize() == 0);

    delete &model;

}

void unit_Model_constructor_name(){
    Model & model = Model::createModel("Model");

    assert(model.getName() == "Model");
    assert(model.flowsSize() == 0);
    assert(model.systemsSize() == 0);

    delete &model;
}

void unit_Model_createModel(){
    assert(Model::modelsSize() == 0);
    Model& model1 = Model::createModel("Modelo 1");
    assert(Model::modelsSize() == 1);
    
    Model& model2 = Model::createModel("Modelo 2");
    assert(Model::modelsSize() == 2);

    delete &model1;
    assert(Model::modelsSize() == 1);

    Model& model3 = Model::createModel("Modelo 3");
    assert(Model::modelsSize() == 2);

    delete &model2;
    assert(Model::modelsSize() == 1);

    delete &model3;
    assert(Model::modelsSize() == 0);
}

void unit_Model_destructor(){}


void unit_getName(){
    
    Model &model = Model::createModel("Modelo");
    assert(model.getName() == "Modelo");
    assert(model.getName() != "Model");

    delete &model;
}
void unit_setName(){
    Model& model = Model::createModel();
    model.setName("Model");
    assert(model.getName() == "Model");
    assert(model.getName() != "Modelo");

    delete &model;
}

void unit_Model_systemBegin(){
    Model& model = Model::createModel();
    System & pop1 = model.createSystem("pop1", 100.0);
    System & pop2 = model.createSystem("pop2", 0.0);

    assert(*(model.systemBegin()) == &pop1);
    assert(*(model.systemBegin()) != &pop2);

    delete &model;

}
void unit_Model_systemEnd(){
    Model& model = Model::createModel();
    model.createSystem("pop1", 100.0);
    model.createSystem("pop2", 0.0);

    //The end method from a container gives the position after the last one
    //So if I can count until the size of the container, everything is correct
    Model::systemsIterator end = model.systemEnd();
    Model::systemsIterator it = model.systemBegin();
    int counter = 0;

    while(it != end){
        if(it != end) counter ++;
        else break;
        it++;
    }

    assert(counter == model.systemsSize());

    delete &model;
}

void unit_Model_flowsBegin(){

    Model& model = Model::createModel();

    Flow & f = model.createFlow<FlowComplexo>("f");
    Flow & g = model.createFlow<FlowComplexo>("g");
    Flow & r = model.createFlow<FlowComplexo>("r");
    Flow & t = model.createFlow<FlowComplexo>("t");
    Flow & u = model.createFlow<FlowComplexo>("u");
    Flow & v = model.createFlow<FlowComplexo>("v");


    assert(*(model.flowsBegin()) == &f);
    assert(*(model.flowsBegin()) != &g);
    assert(*(model.flowsBegin()) != &r);
    assert(*(model.flowsBegin()) != &t);
    assert(*(model.flowsBegin()) != &u);
    assert(*(model.flowsBegin()) != &v);

    delete &model;

}
void unit_Model_flowsEnd(){
    Model& model = Model::createModel();

    model.createFlow<FlowComplexo>("f");
    model.createFlow<FlowComplexo>("g");
    model.createFlow<FlowComplexo>("r");
    model.createFlow<FlowComplexo>("t");
    model.createFlow<FlowComplexo>("u");
    model.createFlow<FlowComplexo>("v");

    //The end method from a container gives the position after the last one
    //So if I can count until the size of the container, everything is correct
    Model::flowsIterator end = model.flowsEnd();
    Model::flowsIterator it = model.flowsBegin();
    int counter = 0;

    while(it != end){
        if(it != end) counter ++;
        else break;
        it++;
    }

    assert(counter == model.flowsSize());

    delete &model;
}

void unit_Model_modelsBegin(){
    Model & model1 = Model::createModel("Modelo1");
    Model & model2 = Model::createModel("Modelo2");

    assert(*(model1.modelsBegin()) == &model1);
    assert(*(model1.modelsBegin()) != &model2);

    delete &model1;
    delete &model2;
}
void unit_Model_modelsEnd(){
    Model & model1 = Model::createModel("Modelo1");
    Model & model2 = Model::createModel("Modelo2");
    //The end method from a container gives the position after the last one
    //So if I can count until the size of the container, everything is correct
    Model::modelsIterator end = model1.modelsEnd();
    Model::modelsIterator it = model1.modelsBegin();
    int counter = 0;

    while(it != end){
        if(it != end) counter ++;
        else break;
        it++;
    }

    assert(counter == model1.modelsSize());

    delete &model1;
    delete &model2;
}

void unit_Model_flowsSize(){
    Model& model = Model::createModel();

    model.createFlow<FlowComplexo>("f");
    model.createFlow<FlowComplexo>("g");
    model.createFlow<FlowComplexo>("r");
    model.createFlow<FlowComplexo>("t");
    model.createFlow<FlowComplexo>("u");
    model.createFlow<FlowComplexo>("v");

    assert(model.flowsSize() == 6);

    delete &model;
}
void unit_Model_systemSize(){
    Model& model = Model::createModel();
    model.createSystem("pop1", 100.0);
    model.createSystem("pop2", 0.0);

    assert(model.systemsSize() == 2);

    delete &model;
}
void unit_Model_modelsSize(){
    Model & model1 = Model::createModel("Modelo1");
    Model & model2 = Model::createModel("Modelo2");

    assert(Model::modelsSize() == 2);

    delete &model1;
    delete &model2;
}

void unit_Model_createFlow(){
    Model& model = Model::createModel();

    model.createFlow<FlowComplexo>("f");
    model.createFlow<FlowComplexo>("g");

    assert(model.flowsSize() == 2);

    delete &model;
}
void unit_Model_createSystem(){
    Model& model = Model::createModel();
    System &pop1 = model.createSystem("pop1", 100.0);
    System &pop2 = model.createSystem("pop2", 0.0);

    Model::systemsIterator it = model.systemBegin();
    assert(*it == &pop1);
    it++;
    assert(*it == &pop2);

    delete &model;
}

void unit_Model_remove_flow(){
    Model& model = Model::createModel();

    Flow &f = model.createFlow<FlowComplexo>("f");
    Flow &g = model.createFlow<FlowComplexo>("g");

    assert(model.remove(&f));
    assert(model.remove(&g));

    delete &model;
}
void unit_Model_remove_system(){
    Model& model = Model::createModel();
    System &pop1 = model.createSystem("pop1", 100.0);
    System &pop2 = model.createSystem("pop2", 0.0);

    assert(model.remove(&pop1));
    assert(model.remove(&pop2));

    delete &model;
}

void unit_Model_run(){
    Model& model = Model::createModel();

    assert(model.run(0, 100) == 100);
    assert(model.run(101, 100) == -1);
    assert(model.run(-20, 100) == -1);
    assert(model.run(-200, -100) == -1);

    delete &model;
}

void run_unit_test_Model(){
    unit_Model_constructor_default();
    unit_Model_constructor_name();
    unit_Model_createModel();
    unit_Model_destructor();
    unit_Model_createSystem();
    unit_Model_createFlow();
    unit_getName();
    unit_setName();
    unit_Model_systemBegin();
    unit_Model_systemEnd();
    unit_Model_flowsBegin();
    unit_Model_flowsEnd();
    unit_Model_modelsBegin();
    unit_Model_modelsEnd();
    unit_Model_flowsSize();
    unit_Model_systemSize();
    unit_Model_modelsSize();
    unit_Model_remove_flow();
    unit_Model_remove_system();
    unit_Model_run();
}