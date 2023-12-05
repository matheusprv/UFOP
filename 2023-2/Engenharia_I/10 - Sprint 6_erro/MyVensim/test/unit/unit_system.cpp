#include "unit_system.h"

void unit_System_constructor_default(){
    System * system = new SystemHandle();

    assert(system->getName() == "");
    assert(system->getValue() == 0.0);
    delete system;
}
void unit_System_construtor_with_all_atributes(){
    System * system = new SystemHandle("Sistema1", 100);

    assert(system->getName() == "Sistema1");
    assert(round(fabs(system->getValue() * 1e4 - 100.0 * 1e4)) < 1);
    delete system;
}
void unit_System_construtor_name(){
    System * system = new SystemHandle("Sistema1");

    assert(system->getName() == "Sistema1");
    assert(round(fabs(system->getValue() * 1e4 - 0 * 1e4)) < 1);

    delete system;
}
void unit_System_construtor_value(){
    System * system = new SystemHandle(100);

    assert(system->getName() == "");
    assert(round(fabs(system->getValue() * 1e4 - 100.0 * 1e4)) < 1);
    delete system;
}
void unit_System_construtor_copy(){
    System * system = new SystemHandle("Sistema1", 100);
    System * system2 = new SystemHandle(*system);
    System * system3 = new SystemHandle("Sistema3", 100);

    assert(system != system2);
    assert((*system) == (*system2));
    assert(!((*system) == (*system3)));

    delete system;
    delete system2;
    delete system3;
}

void unit_System_destrutor(){}

void unit_System_getName(){
    System * system = new SystemHandle("Sistema1", 100);
    assert(system->getName() == "Sistema1");
    assert(system->getName() != "Sistema");
    delete system;
}
void unit_System_setName(){
    System * system = new SystemHandle();
    system->setName("Sistema1");
    assert(system->getName() == "Sistema1");
    assert(system->getName() != "Sistema");
    delete system;
}

void unit_System_getValue(){
    System * system = new SystemHandle("Sistema1", 100);

    assert(round(fabs(system->getValue() * 1e4 - 100.0 * 1e4)) < 1);
    assert(!(round(fabs(system->getValue() * 1e4 - 100.001 * 1e4)) < 1));

    delete system;
}
void unit_System_setValue(){
    System * system = new SystemHandle();
    system->setValue(100);
    assert(round(fabs(system->getValue() * 1e4 - 100.0 * 1e4)) < 1);
    assert(!(round(fabs(system->getValue() * 1e4 - 100.001 * 1e4)) < 1));
    delete system;
}

void unit_System_operator_comparison(){
    System * system = new SystemHandle("Sistema1", 100);
    System * system2 = system;
    System * system3 = new SystemHandle("Sistema3", 100);

    assert((*system) == (*system2)); 
    assert(!((*system) == (*system3))); 

    delete system;
    delete system3;
}

void unit_System_operator_equals(){
    System * system = new SystemHandle("Sistema1", 100);
    System * system2 = system;
    System * system3 = new SystemHandle("Sistema3", 100);

    assert(system == system2); 
    assert(system != system3); 

    delete system;
    delete system3;

}


void run_unit_test_System(){
    unit_System_constructor_default();
    unit_System_construtor_with_all_atributes();
    unit_System_construtor_name();
    unit_System_construtor_value();
    unit_System_construtor_copy();
    unit_System_destrutor();
    unit_System_getName();
    unit_System_setName();
    unit_System_getValue();
    unit_System_setValue();
    unit_System_operator_comparison();
    unit_System_operator_equals();
}