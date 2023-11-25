#include "funcional_tests.h"

bool floatingPointComparison(double n1, double n2){   
    return round(fabs(n1 * 1e4 - n2 * 1e4)) < 1;
}

void exponentialFuncionalTest(){
    cout << "Begining exponential functional test." << endl;

    Model * model = Model :: createModel("Sistema exponencial");
    System* pop1 = model->createSystem("pop1", 100.0);
    System* pop2 = model->createSystem("pop2", 0.0);

    model->createFlow<FlowExponencial>("exponencial", pop1, pop2);

    model->run(0, 100);

    assert (floatingPointComparison(pop1->getValue(), 36.6032) == true);
    assert (floatingPointComparison(pop2->getValue(), 63.3968) == true);

    cout << "Exponential functional test approved." << endl;

    delete model;
}

void logisticalFuncionalTest(){
    cout << "Begining logistic functional test." << endl;

    Model * model = Model :: createModel("Sistema logistico");
    System * p1 = model->createSystem("p1", 100.0);
    System * p2 = model->createSystem("p2", 10.0);
    model->createFlow<FlowLogistico>("logistico", p1, p2);

    model->run(0, 100);

    assert (floatingPointComparison(p1->getValue(), 88.2167) == true);
    assert (floatingPointComparison(p2->getValue(), 21.7833) == true);

    cout << "Logistic functional test approved." << endl;

    delete model;
}

void complexFuncionalTest(){
    cout << "Begining complex functional test." << endl;

    Model * model = Model :: createModel("Sistema logistico");

    System * Q1 = model->createSystem("Q1", 100.0); 
    System * Q2 = model->createSystem("Q2", 0.0);
    System * Q3 = model->createSystem("Q3", 100.0);
    System * Q4 = model->createSystem("Q4", 0.0);
    System * Q5 = model->createSystem("Q5", 0.0);

    model->createFlow<FlowComplexo>("f", Q1, Q2);
    model->createFlow<FlowComplexo>("g", Q1, Q3);
    model->createFlow<FlowComplexo>("r", Q2, Q5);
    model->createFlow<FlowComplexo>("t", Q2, Q3);
    model->createFlow<FlowComplexo>("u", Q3, Q4);
    model->createFlow<FlowComplexo>("v", Q4, Q1);

    model->run(0, 100);

    assert (floatingPointComparison(Q1->getValue(), 31.8513));
    assert (floatingPointComparison(Q2->getValue(), 18.4003));
    assert (floatingPointComparison(Q3->getValue(), 77.1143));
    assert (floatingPointComparison(Q4->getValue(), 56.1728));
    assert (floatingPointComparison(Q5->getValue(), 16.4612));
    
    delete model;

    cout << "Complex functional test approved." << endl;
}