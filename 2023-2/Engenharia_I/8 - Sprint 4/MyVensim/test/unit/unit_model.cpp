#include "unit_model.h"

void unit_Model_constructor_default(){
    Model * model = new ModelImpl();

    assert(model->getName() == "");
    assert(model->flowsSize() == 0);
    assert(model->systemsSize() == 0);

    delete model;

}

void unit_Model_constructor_name(){
    Model * model = new ModelImpl("Model");

    assert(model->getName() == "Model");
    assert(model->flowsSize() == 0);
    assert(model->systemsSize() == 0);

    delete model;
}

void unit_Model_destrucotr(){}

void unit_getName(){
    Model * model = new ModelImpl("Model");
    assert(model->getName() == "Model");
    assert(model->getName() != "Modelo");

    delete model;
}
void unit_setName(){
    Model * model = new ModelImpl();
    model->setName("Model");
    assert(model->getName() == "Model");
    assert(model->getName() != "Modelo");

    delete model;
}

void unit_Model_systemBegin(){
    ModelImpl model ("Model");
    
    System * pop1 = new SystemImpl("pop1", 100.0);
    System * pop2 = new SystemImpl("pop2", 0.0);

    model.add(pop1);
    model.add(pop2);

    assert(*(model.systemBegin()) == pop1);
    assert(*(model.systemBegin()) != pop2);

    delete pop1;
    delete pop2;
}
void unit_Model_systemEnd(){
    ModelImpl model ("Model");
    
    System * pop1 = new SystemImpl("pop1", 100.0);
    System * pop2 = new SystemImpl("pop2", 0.0);

    model.add(pop1);
    model.add(pop2);

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

    delete pop1;
    delete pop2;
}


void unit_Model_flowsBegin(){
    FlowComplexo * f = new FlowComplexo("f");
    FlowComplexo * g = new FlowComplexo("g");
    FlowComplexo * r = new FlowComplexo("r");
    FlowComplexo * t = new FlowComplexo("t");
    FlowComplexo * u = new FlowComplexo("u");
    FlowComplexo * v = new FlowComplexo("v");

    ModelImpl model;
    model.add(f);
    model.add(g);
    model.add(r);
    model.add(t);
    model.add(u);
    model.add(v);

    assert(*(model.flowsBegin()) == f);
    assert(*(model.flowsBegin()) != g);
    assert(*(model.flowsBegin()) != r);
    assert(*(model.flowsBegin()) != t);
    assert(*(model.flowsBegin()) != u);
    assert(*(model.flowsBegin()) != v);


    delete f;
    delete g;
    delete r;
    delete t;
    delete u;
    delete v;
}
void unit_Model_flowsEnd(){
    FlowComplexo * f = new FlowComplexo("f");
    FlowComplexo * g = new FlowComplexo("g");
    FlowComplexo * r = new FlowComplexo("r");
    FlowComplexo * t = new FlowComplexo("t");
    FlowComplexo * u = new FlowComplexo("u");
    FlowComplexo * v = new FlowComplexo("v");

    ModelImpl model;

    model.add(f);
    model.add(g);
    model.add(r);
    model.add(t);
    model.add(u);
    model.add(v);

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

    delete f;
    delete g;
    delete r;
    delete t;
    delete u;
    delete v;

}

void unit_Model_flowsSize(){
    FlowComplexo * f = new FlowComplexo("f");
    FlowComplexo * g = new FlowComplexo("g");
    FlowComplexo * r = new FlowComplexo("r");
    FlowComplexo * t = new FlowComplexo("t");
    FlowComplexo * u = new FlowComplexo("u");
    FlowComplexo * v = new FlowComplexo("v");

    ModelImpl model;
    model.add(f);
    model.add(g);
    model.add(r);
    model.add(t);
    model.add(u);
    model.add(v);

    assert(model.flowsSize() == 6);

    delete f;
    delete g;
    delete r;
    delete t;
    delete u;
    delete v;
}
void unit_Model_systemSize(){
    ModelImpl model ("Model");
    
    System * pop1 = new SystemImpl("pop1", 100.0);
    System * pop2 = new SystemImpl("pop2", 0.0);

    model.add(pop1);
    model.add(pop2);

    assert(model.systemsSize() == 2);

    delete pop1;
    delete pop2;
}

void unit_Model_add_flow(){
    Model * modelo = new ModelImpl();

    FlowComplexo * f = new FlowComplexo("f");
    FlowComplexo * g = new FlowComplexo("g");

    assert(modelo->add(f));
    assert(modelo->add(g));

    delete f;
    delete g;
    delete modelo;
}
void unit_Model_add_system(){
    ModelImpl model ("Model");
    
    System * pop1 = new SystemImpl("pop1", 100.0);
    System * pop2 = new SystemImpl("pop2", 0.0);

    assert(model.add(pop1));
    assert(model.add(pop2));

    delete pop1;
    delete pop2;
}

void unit_Model_remove_flow(){
    Model * modelo = new ModelImpl();

    FlowComplexo * f = new FlowComplexo("f");
    FlowComplexo * g = new FlowComplexo("g");

    modelo->add(f);
    modelo->add(g);

    assert(modelo->remove(f));
    assert(modelo->remove(g));

    delete f;
    delete g;
    delete modelo;
}
void unit_Model_remove_system(){
    Model * model = new ModelImpl("Model");
    
    System * pop1 = new SystemImpl("pop1", 100.0);
    System * pop2 = new SystemImpl("pop2", 0.0);

    model->add(pop1);
    model->add(pop2);

    assert(model->remove(pop1));
    assert(model->remove(pop2));

    delete pop1;
    delete pop2;
    delete model;
}

void unit_Model_run(){
    ModelImpl model ("Sistema Exponencial");
    
    System * pop1 = new SystemImpl("pop1", 100.0);
    System * pop2 = new SystemImpl("pop2", 0.0);

    FlowExponencial * exponencial = new FlowExponencial("exponencial", pop1, pop2);

    model.add(pop1);
    model.add(pop2);
    model.add(exponencial);

    assert(model.run(0, 100));
    assert(!model.run(101, 100));
    assert(!model.run(-20, 100));
    assert(!model.run(-200, -100));

    delete exponencial;
    delete pop1;
    delete pop2;
}

void run_unit_test_Model(){
    unit_Model_constructor_default();
    unit_Model_constructor_name();
    unit_Model_destrucotr();
    unit_getName();
    unit_setName();
    unit_Model_systemBegin();
    unit_Model_systemEnd();
    unit_Model_flowsBegin();
    unit_Model_flowsEnd();
    unit_Model_flowsSize();
    unit_Model_systemSize();
    unit_Model_add_flow();
    unit_Model_add_system();
    unit_Model_remove_flow();
    unit_Model_remove_system();
    unit_Model_run();
}