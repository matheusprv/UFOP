#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

#include "../../src/SystemImpl.h"
#include <math.h>

#include <assert.h>

/**
 * @brief Make a unit test for the default constructor
*/
void unit_System_constructor_default();
/**
 * @brief Make a unit test for the constructor with all atributes
*/
void unit_System_construtor_with_all_atributes();
/**
 * @brief Make a unit test for the constructor with only the name
*/
void unit_System_construtor_name();
/**
 * @brief Make a unit test for the constructor with only the value
*/
void unit_System_construtor_value();
/**
 * @brief Make a unit test for the copy constructor
*/
void unit_System_construtor_copy();
/**
 * @brief make a unit test for the destructor
*/
void unit_System_destrutor();
/**
 * @brief Make a unit test for the method getName()
*/
void unit_System_getName();
/**
 * @brief Make a unit test for the method setName()
*/
void unit_System_setName();
/**
 * @brief Make a unit test for the method etValue()
*/
void unit_System_getValue();
/**
 * @brief Make a unit test for the method etValue()
*/
void unit_System_setValue();
/**
 * @brief Make a unit test for the == operator
*/
void unit_System_operator_comparison();
/**
 * @brief Make a unit test for the = operator
*/
void unit_System_operator_equals();

/**
 * @brief Execute all the unit tests
*/
void run_unit_test_System();

#endif