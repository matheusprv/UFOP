#include "unit_flow.h"

void unit_Flow_constructor_default(){
    //Flow complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>();
    assert(flowComplexo->getName() == "");
    assert(flowComplexo->getSource() == NULL);
    assert(flowComplexo->getTarget() == NULL);
    delete flowComplexo;

    //Flow Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>();
    assert(flowExponencial->getName() == "");
    assert(flowExponencial->getSource() == NULL);
    assert(flowExponencial->getTarget() == NULL);
    delete flowExponencial;

    //Flow Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>();
    assert(flowLogistico->getName() == "");
    assert(flowLogistico->getSource() == NULL);
    assert(flowLogistico->getTarget() == NULL);
    delete flowLogistico;
}
void unit_Flow_constructor_complete(){
    System * s1 = new SystemHandle("S1", 100.0);
    System * s2 = new SystemHandle("S2", 0.0);

    //Flow complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>("F1", s1, s2);
    assert(flowComplexo->getName() == "F1");
    assert(flowComplexo->getSource() == s1);
    assert(flowComplexo->getTarget() == s2);
    delete flowComplexo;

    //Flow Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>("F1", s1, s2);
    assert(flowExponencial->getName() == "F1");
    assert(flowExponencial->getSource() == s1);
    assert(flowExponencial->getTarget() == s2);
    delete flowExponencial;

    //Flow Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>("F1", s1, s2);
    assert(flowLogistico->getName() == "F1");
    assert(flowLogistico->getSource() == s1);
    assert(flowLogistico->getTarget() == s2);
    delete flowLogistico;

    delete s1;
    delete s2;

}
void unit_Flow_constructor_name(){
    //Flow complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>("F");
    assert(flowComplexo->getName() == "F");
    assert(flowComplexo->getSource() == NULL);
    assert(flowComplexo->getTarget() == NULL);
    delete flowComplexo;

    //Flow Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>("F");
    assert(flowExponencial->getName() == "F");
    assert(flowExponencial->getSource() == NULL);
    assert(flowExponencial->getTarget() == NULL);
    delete flowExponencial;

    //Flow Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>("F");
    assert(flowLogistico->getName() == "F");
    assert(flowLogistico->getSource() == NULL);
    assert(flowLogistico->getTarget() == NULL);
    delete flowLogistico;
}
void unit_Flow_constructor_source_target(){
    System * s1 = new SystemHandle("S1", 100.0);
    System * s2 = new SystemHandle("S2", 0.0);

    //Flow complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>(s1, s2);
    assert(flowComplexo->getName() == "");
    assert(flowComplexo->getSource() == s1);
    assert(flowComplexo->getTarget() == s2);
    delete flowComplexo;

    //Flow Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>(s1, s2);
    assert(flowExponencial->getName() == "");
    assert(flowExponencial->getSource() == s1);
    assert(flowExponencial->getTarget() == s2);
    delete flowExponencial;

    //Flow Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>(s1, s2);
    assert(flowLogistico->getName() == "");
    assert(flowLogistico->getSource() == s1);
    assert(flowLogistico->getTarget() == s2);
    delete flowLogistico;

    delete s1;
    delete s2;
}
void unit_Flow_constructor_copy(){
    System * s1 = new SystemHandle("S1", 100.0);
    System * s2 = new SystemHandle("S2", 0.0);

    //Flow complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>(s1, s2);
    Flow * complexoCopy = new FlowHandle<FlowComplexo>(*flowComplexo);
    assert(flowComplexo != complexoCopy);
    
    assert(flowComplexo->getName() == complexoCopy->getName());
    delete flowComplexo;
    delete complexoCopy;

    //Flow Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>(s1, s2);
    Flow * exponencialCopy = new FlowHandle<FlowExponencial>(*flowExponencial);
    assert(flowExponencial != exponencialCopy);
    assert(flowExponencial->getName() == exponencialCopy->getName());
    delete flowExponencial;
    delete exponencialCopy;

    //Flow Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>(s1, s2);
    Flow * logisticoCopy = new FlowHandle<FlowLogistico>(*flowLogistico);
    assert(flowLogistico != logisticoCopy);
    assert(flowLogistico->getName() == logisticoCopy->getName());
    delete flowLogistico;
    delete logisticoCopy;

    delete s1;
    delete s2;
}

void unit_Flow_destructor(){}

void unit_Flow_getSource(){
    System * s1 = new SystemHandle("S1", 100.0);
    System * s2 = new SystemHandle("S2", 0.0);

    //Complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>(s1, s2);
    assert(flowComplexo->getSource() == s1);

    //Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>(s1, s2);
    assert(flowLogistico->getSource() == s1);

    //Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>(s1, s2);
    assert(flowExponencial->getSource() == s1);

    delete flowComplexo;
    delete flowLogistico;
    delete flowExponencial;

    delete s1;
    delete s2;
}
void unit_Flow_setSource(){
    System * s1 = new SystemHandle("S1", 100.0);

    //Complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>();
    flowComplexo->setSource(s1);
    assert(flowComplexo->getSource() == s1);

    //Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>();
    flowLogistico->setSource(s1);
    assert(flowLogistico->getSource() == s1);

    //Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>();
    flowExponencial->setSource(s1);
    assert(flowExponencial->getSource() == s1);

    delete flowComplexo;
    delete flowLogistico;
    delete flowExponencial;

    delete s1;
}

void unit_Flow_getTarget(){
    System * s1 = new SystemHandle("S1", 100.0);
    System * s2 = new SystemHandle("S2", 0.0);

    //Complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>(s1, s2);
    assert(flowComplexo->getTarget() == s2);

    //Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>(s1, s2);
    assert(flowLogistico->getTarget() == s2);

    //Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>(s1, s2);
    assert(flowExponencial->getTarget() == s2);

    delete flowComplexo;
    delete flowLogistico;
    delete flowExponencial;

    delete s1;
    delete s2;
}
void unit_Flow_setTarget(){
    System * s1 = new SystemHandle("S1", 100.0);

    //Complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>();
    flowComplexo->setTarget(s1);
    assert(flowComplexo->getTarget() == s1);

    //Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>();
    flowLogistico->setTarget(s1);
    assert(flowLogistico->getTarget() == s1);

    //Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>();
    flowExponencial->setTarget(s1);
    assert(flowExponencial->getTarget() == s1);

    delete flowComplexo;
    delete flowLogistico;
    delete flowExponencial;

    delete s1;
}

void unit_Flow_getName(){
    //Complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>("Flow Complexo");
    assert(flowComplexo->getName() == "Flow Complexo");

    //Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>("Flow Logistico");
    assert(flowLogistico->getName() == "Flow Logistico");

    //Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>("Flow Exponencial");
    assert(flowExponencial->getName() == "Flow Exponencial");

    delete flowComplexo;
    delete flowLogistico;
    delete flowExponencial;
}
void unit_Flow_setName(){
    //Complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>();
    flowComplexo->setName("Flow Complexo");
    assert(flowComplexo->getName() == "Flow Complexo");

    //Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>();
    flowLogistico->setName("Flow Logistico");
    assert(flowLogistico->getName() == "Flow Logistico");

    //Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>();
    flowExponencial->setName("Flow Exponencial");
    assert(flowExponencial->getName() == "Flow Exponencial");

    delete flowComplexo;
    delete flowLogistico;
    delete flowExponencial;
}

void unit_Flow_operator_equals(){
    System * s1 = new SystemHandle("S1", 100.0);
    System * s2 = new SystemHandle("S2", 0.0);

    //Flow complexo
    Flow * flowComplexo = new FlowHandle<FlowComplexo>(s1, s2);
    Flow * complexoCopy = flowComplexo;
    assert(flowComplexo == complexoCopy);
    delete flowComplexo;

    //Flow Exponencial
    Flow * flowExponencial = new FlowHandle<FlowExponencial>(s1, s2);
    Flow * exponencialCopy = flowExponencial;
    assert(flowExponencial == exponencialCopy);
    delete flowExponencial;

    //Flow Logistico
    Flow * flowLogistico = new FlowHandle<FlowLogistico>(s1, s2);
    Flow * logisticoCopy = flowLogistico;
    assert(flowLogistico == logisticoCopy);
    delete flowLogistico;

    delete s1;
    delete s2;
}

void unit_Flow_execute_equation(){
    //Flow complexo
    System * Q1 = new SystemHandle("Q1", 100.0); 
    System * Q2 = new SystemHandle("Q2", 0.0);
    System * Q3 = new SystemHandle("Q3", 100.0);
    System * Q4 = new SystemHandle("Q4", 0.0);
    System * Q5 = new SystemHandle("Q5", 0.0);

    FlowComplexo * f = new FlowComplexo("f", Q1, Q2);
    FlowComplexo * g = new FlowComplexo("g", Q1, Q3);
    FlowComplexo * r = new FlowComplexo("r", Q2, Q5);
    FlowComplexo * t = new FlowComplexo("t", Q2, Q3);
    FlowComplexo * u = new FlowComplexo("u", Q3, Q4);
    FlowComplexo * v = new FlowComplexo("v", Q4, Q1);

    double resultf = f->executeEquation();  
    assert(round(fabs(resultf * 1e4 - 1 * 1e4)) < 1);  

    double resultg = g->executeEquation();
    assert(round(fabs(resultg * 1e4 - 1 * 1e4)) < 1);

    double resultr = r->executeEquation();
    assert(round(fabs(resultr * 1e4 - 0 * 1e4)) < 1);

    double resultt = t->executeEquation();
    assert(round(fabs(resultt * 1e4 - 0 * 1e4)) < 1);

    double resultu = u->executeEquation();
    assert(round(fabs(resultu * 1e4 - 1 * 1e4)) < 1);

    double resultv = v->executeEquation();
    assert(round(fabs(resultv * 1e4 - 0 * 1e4)) < 1);

    delete Q1;
    delete Q2;
    delete Q3;
    delete Q4;
    delete Q5;

    delete f;
    delete g;
    delete r;
    delete t;
    delete u;
    delete v;

    //Flow Exponencial
    System * pop1 = new SystemHandle("pop1", 100);
    System * pop2 = new SystemHandle("pop2", 0);
    Flow * flowComplexo = new FlowHandle<FlowComplexo>("F1", pop1, pop2);
    double result = flowComplexo->executeEquation();
    assert(round(fabs(result * 1e4 - 1 * 1e4)) < 1);

    delete pop1;
    delete pop2;
    delete flowComplexo;

    //Flow Logistico
    System * p1 = new SystemHandle("p1", 100.0);
    System * p2 = new SystemHandle("p2", 10.0);
    Flow * flowLogistico = new FlowHandle<FlowLogistico>("F1", p1, p2);
    assert(round(fabs(flowLogistico->executeEquation() * 1e4 - 0.0857 * 1e4)) < 1);

    delete flowLogistico;
    delete p1;
    delete p2;
}

void run_unit_test_Flow(){
    unit_Flow_constructor_default();
    unit_Flow_constructor_complete();
    unit_Flow_constructor_name();
    unit_Flow_constructor_source_target();
    unit_Flow_constructor_copy();
    unit_Flow_destructor();
    unit_Flow_getSource();
    unit_Flow_setSource();
    unit_Flow_getTarget();
    unit_Flow_setTarget();
    unit_Flow_getName();
    unit_Flow_setName();
    unit_Flow_operator_equals();
    unit_Flow_execute_equation();
}