#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

#include "../../src/FlowImpl.h"
#include "../../src/SystemImpl.h"

#include "../Flows/FlowComplexo.h"
#include "../Flows/FlowExponencial.h"
#include "../Flows/FlowLogistico.h"
#include <math.h>

#include <assert.h>

/**
 * @brief Unit test for Flow's empty constructor
*/
void unit_Flow_constructor_empty();
/**
 * @brief Unit test for Flow's constructor
*/
void unit_Flow_constructor_complete();
/**
 * @brief Unit test for Flow's constructor only with name
*/
void unit_Flow_constructor_name();
/**
 * @brief Unit test for Flow's constructor with source and target
*/
void unit_Flow_constructor_source_target();
/**
 * @brief Unit test for Flow's destructor
*/
void unit_Flow_destructor();
/**
 * @brief Unit test for method getSource()
*/
void unit_Flow_getSource();
/**
 * @brief Unit test for method setSource()
*/
void unit_Flow_setSource();
/**
 * @brief Unit test for method getTarget()
*/
void unit_Flow_getTarget();
/**
 * @brief Unit test for method setTarget()
*/
void unit_Flow_setTarget();
/**
 * @brief Unit test for method getName()
*/
void unit_Flow_getName();
/**
 * @brief Unit test for method setName()
*/
void unit_Flow_setName();
/**
 * @brief Unit test for method executeEquation()
*/
void unit_Flow_execute_equation();

/**
 * @brief Execute all unit tests
*/
void run_unit_test_Flow();

#endif