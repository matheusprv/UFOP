#include "unit_test.h"

void run_unit_test(){
    cout << "Executing unit tests for Flow" << endl;
    run_unit_test_Flow();
    cout << "All Flow's tests were approved" << endl;

    cout << "Executing unit tests for System" << endl;
    run_unit_test_System();
    cout << "All System's tests were approved" << endl;

    cout << "Executing unit tests for Model" << endl;
    run_unit_test_Model();
    cout << "All Model's tests were approved" << endl;

    cout << "Executing unit tests for HandleBody" << endl;
    run_unit_test_handle_body();
    cout << "All Handle Body's tests were approved" << endl;

}