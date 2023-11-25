#include "funcional_tests.h"

bool floatingPointComparison(double n1, double n2){   
    return round(fabs(n1 * 1e4 - n2 * 1e4)) < 1;
}

void exponentialFuncionalTest(){
    cout << "Beggining exponential functional test." << endl;

    Model& model = Model :: createModel("Sistema exponencial");
    System* pop1 = &model.createSystem("pop1", 100.0);
    System* pop2 = &model.createSystem("pop2", 0.0);

    model.createFlow<FlowExponencial>("exponencial", pop1, pop2);

    model.run(0, 100);

    assert (floatingPointComparison(pop1->getValue(), 36.6032) == true);
    assert (floatingPointComparison(pop2->getValue(), 63.3968) == true);

    cout << "Exponential functional test approved." << endl;

    delete &model;

}

void logisticalFuncionalTest(){
    /*
    cout << "Beggining logistic functional test." << endl;

    ModelImpl model("Sistema logistico");

    System * p1 = new SystemImpl("p1", 100.0);
    System * p2 = new SystemImpl("p2", 10.0);

    FlowLogistico * logistico = new FlowLogistico ("logistico", p1, p2);

    model.add(p1);
    model.add(p2);
    model.add(logistico);

    model.run(0, 100);

    assert (floatingPointComparison(p1->getValue(), 88.2167) == true);
    assert (floatingPointComparison(p2->getValue(), 21.7833) == true);

    cout << "Logistic functional test approved." << endl;

    delete logistico;
    delete p1;
    delete p2;*/
}

void complexFuncionalTest(){
    /*cout << "Beggining complex functional test." << endl;

    System * Q1 = new SystemImpl("Q1", 100.0); 
    System * Q2 = new SystemImpl("Q2", 0.0);
    System * Q3 = new SystemImpl("Q3", 100.0);
    System * Q4 = new SystemImpl("Q4", 0.0);
    System * Q5 = new SystemImpl("Q5", 0.0);

    FlowComplexo * f = new FlowComplexo("f", Q1, Q2);
    FlowComplexo * g = new FlowComplexo("g", Q1, Q3);
    FlowComplexo * r = new FlowComplexo("r", Q2, Q5);
    FlowComplexo * t = new FlowComplexo("t", Q2, Q3);
    FlowComplexo * u = new FlowComplexo("u", Q3, Q4);
    FlowComplexo * v = new FlowComplexo("v", Q4, Q1);

    ModelImpl model;
    model.add(Q1);
    model.add(Q2);
    model.add(Q3);
    model.add(Q4);
    model.add(Q5);
    model.add(f);
    model.add(g);
    model.add(r);
    model.add(t);
    model.add(u);
    model.add(v);

    model.run(0, 100);

    assert (floatingPointComparison(Q1->getValue(), 31.8513));
    assert (floatingPointComparison(Q2->getValue(), 18.4003));
    assert (floatingPointComparison(Q3->getValue(), 77.1143));
    assert (floatingPointComparison(Q4->getValue(), 56.1728));
    assert (floatingPointComparison(Q5->getValue(), 16.4612));

    cout << "Complex functional test approved." << endl;


    delete f;
    delete g;
    delete r;
    delete t;
    delete u;
    delete v;

    delete Q1;
    delete Q2;
    delete Q3;
    delete Q4;
    delete Q5;*/
}