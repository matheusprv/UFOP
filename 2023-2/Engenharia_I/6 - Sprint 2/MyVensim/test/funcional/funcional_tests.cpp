#include "funcional_tests.h"

bool floatingPointComparison(double n1, double n2){   
    return trunc(abs(n1-n2) * 10000) < 1;
}

void exponentialFuncionalTest(){
    cout << "Beggining exponential functional test." << endl;

    Model model ("Sistema Exponencial");
    
    System pop1("pop1", 100.0);
    System pop2("pop2", 0.0);

    FlowExponencial exponencial("exponencial", &pop1, &pop2);

    model.add(&pop1);
    model.add(&pop2);
    model.add(&exponencial);

    model.run(0, 100);

    assert (floatingPointComparison(pop1.getValue(), 36.6032) == true);
    assert (floatingPointComparison(pop2.getValue(), 63.3968) == true);

    cout << "Exponential functional test approved." << endl;
}

void logisticalFuncionalTest(){

    cout << "Beggining logistic functional test." << endl;

    Model model("Sistema logistico");

    System p1("p1", 100.0);
    System p2("p2", 10.0);

    FlowLogistico logistico("logistico", &p1, &p2);

    model.add(&p1);
    model.add(&p2);
    model.add(&logistico);

    model.run(0, 100);

    assert (floatingPointComparison(p1.getValue(), 88.2167) == true);
    assert (floatingPointComparison(p2.getValue(), 21.7833) == true);

    cout << "Logistic functional test approved." << endl;

}

void complexFuncionalTest(){
    cout << "Beggining complex functional test." << endl;

    System Q1("Q1", 100.0); 
    System Q2("Q2", 0.0);
    System Q3("Q3", 100.0);
    System Q4("Q4", 0.0);
    System Q5("Q5", 0.0);

    FlowComplexo f ("f", &Q1, &Q2);
    FlowComplexo g ("g", &Q1, &Q3);
    FlowComplexo r ("r", &Q2, &Q5);
    FlowComplexo t ("t", &Q2, &Q3);
    FlowComplexo u ("u", &Q3, &Q4);
    FlowComplexo v ("v", &Q4, &Q1);

    Model model;
    model.add(&Q1);
    model.add(&Q2);
    model.add(&Q3);
    model.add(&Q4);
    model.add(&Q5);
    model.add(&f);
    model.add(&g);
    model.add(&r);
    model.add(&t);
    model.add(&u);
    model.add(&v);

    model.run(0, 100);

    assert (floatingPointComparison(Q1.getValue(), 31.8513));
    assert (floatingPointComparison(Q2.getValue(), 18.4003));
    assert (floatingPointComparison(Q3.getValue(), 77.1143));
    assert (floatingPointComparison(Q4.getValue(), 56.1728));
    assert (floatingPointComparison(Q5.getValue(), 16.4612));

    cout << "Complex functional test approved." << endl;

}