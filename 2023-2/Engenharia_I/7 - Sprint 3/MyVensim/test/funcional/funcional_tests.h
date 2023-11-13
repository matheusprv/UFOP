#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include <assert.h>
#include <math.h>
using namespace std;

#include "Flows/FlowComplexo.h"
#include "Flows/FlowLogistico.h"
#include "Flows/FlowExponencial.h"

#include "../../src/Model.h"

/**
 * @brief   Compare two floating numbers and check if they equals by checking if their difference is no bigger than 1e-4.
 * @param   n1 First number of the comparison.
 * @param   n2 Second number of the comparsion.
 * @return  True if the difference is in the range, false otherwise.
*/
bool floatingPointComparison(double n1, double n2);

/**
 * @brief   Execute the functional test of the exponential flow.
*/
void exponentialFuncionalTest();
/**
 * @brief   Execute the functional test of the logistical flow.
*/
void logisticalFuncionalTest();
/**
 * @brief   Execute the functional test of the complex flow.
*/
void complexFuncionalTest();

#endif