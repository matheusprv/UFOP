#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "../../src/ModelImpl.h"
#include "../../src/FlowImpl.h"
#include "../../src/SystemImpl.h"
#include "../Flows/FlowComplexo.h"
#include "../Flows/FlowExponencial.h"

#include "assert.h"

/**
 * @brief Unit test for an empty constructor of model
*/
void unit_Model_constructor_default();
/**
 * @brief Unit test for a constructor with name of the model
*/
void unit_Model_constructor_name();
/**
 * @brief Unit test for the destrcutor
*/
void unit_Model_destrucotr();
/**
 * @brief Unit test for the method getName
*/
void unit_getName();
/**
 * @brief Unit test formethod setName
*/
void unit_setName();
/**
 * @brief Unit test to check if the begin is the first element of the system container
*/
void unit_Model_systemBegin();
/**
 * @brief Unit test to check if the end is the element after the last one in system container
*/
void unit_Model_systemEnd();
/**
 * @brief Unit test to check if the begin is the first element of the flows container
*/
void unit_Model_flowsBegin();
/**
 * @brief Unit test to check if the end is the element after the last one in flows container
*/
void unit_Model_flowsEnd();
/**
 * @brief Unit test to check if the return value is the correct number of elements in the container
*/
void unit_Model_flowsSize();
/**
 * @brief Unit test to check if the return value is the correct number of elements in the container
*/
void unit_Model_systemSize();
/**
 * @brief Unit test to check if a flow was successfully added into the container of flows
*/
void unit_Model_add_flow();
/**
 * @brief Unit test to check if a flow was successfully added into the container of systems
*/
void unit_Model_add_system();
/**
 * @brief Unit test to check if a flow was successfully removed from the flow's container
*/
void unit_Model_remove_flow();
/**
 * @brief Unit test to check if a flow was successfully removed from the system's container
*/
void unit_Model_remove_system();
/**
 * @brief Unit test to check if the system is running correctly and if the times are correct
*/
void unit_Model_run();

/**
 * @brief Execute the unit tests from the methods implemented on the class Model
*/
void run_unit_test_Model();

#endif