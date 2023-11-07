#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include <assert.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

#include "Flows/FlowComplexo.h"
#include "Flows/FlowLogistico.h"
#include "Flows/FlowExponencial.h"

#include "../../src/Model.h"

bool floatingPointComparison(double n1, double n2);

void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif