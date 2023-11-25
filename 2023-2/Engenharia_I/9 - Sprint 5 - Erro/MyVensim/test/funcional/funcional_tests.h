#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include <assert.h>
#include <math.h>
using namespace std;

#include "../Flows/FlowComplexo.h"
#include "../Flows/FlowLogistico.h"
#include "../Flows/FlowExponencial.h"

#include "../../src/Model.h"
#include "../../src/System.h"


/**
 * @brief   Compare two floating numbers and check if they equals by checking if their difference is no bigger than 1e-4.
 * @param   n1 First number of the comparison.
 * @param   n2 Second number of the comparsion.
 * @return  True if the difference is in the range, false otherwise.
*/
bool floatingPointComparison(double n1, double n2);

/**
 * @brief   Given a model with exponential equation and two systems, pop1 with value 100 and pop2 with value 0
 *          When the model runs, execute the equations and update the values from time 0 to 100
 *          Then check if pop1 value is 36.6032 and pop2 is 63.3968
*/
void exponentialFuncionalTest();
/**
 * @brief   Given a model with logistical equation and two systems, p1 with value 100 and p2 with value 10
 *          When the model runs, execute the equations and update the values from time 0 to 100
 *          Then check if pop1 value is 88.2167 and pop2 is 21.7833
*/
void logisticalFuncionalTest();
/**
 * @brief   Given a model with complex equation and two systems, q1 and q3 with value 100 and q2, q4 and q5 with value 0, and
 *          flows connection f (q1 to q2), g(q1 to q3), r (q2 to q5), t (q2 to q3), u (q3 to q4) and v (q4 to q3)
 *          When the model runs, execute the equations and update the values from time 0 to 100
 *          Then check if q1 equals 31.8513, q2 equals 18.4003, q3 equals to 77.1143, q4 equals to 56.1728 and q5 equals to 16.4612
*/
void complexFuncionalTest();

#endif