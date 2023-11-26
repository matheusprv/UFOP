teste_funcional: Flow.o Model.o System.o FlowComplexo.o FlowExponencial.o FlowLogistico.o  Functional_test.o ../test/funcional/main.cpp
	g++ Flow.o FlowComplexo.o FlowExponencial.o FlowLogistico.o Model.o System.o ../test/funcional/funcional_tests.cpp  ../test/funcional/main.cpp -o teste_funcional -Wall -g

teste_funcional_executar: Flow.o Model.o System.o FlowComplexo.o FlowExponencial.o FlowLogistico.o  Functional_test.o ../test/funcional/main.cpp
	g++ Flow.o FlowComplexo.o FlowExponencial.o FlowLogistico.o Model.o System.o ../test/funcional/funcional_tests.cpp  ../test/funcional/main.cpp -o teste_funcional -Wall -g
	valgrind --leak-check=yes ./teste_funcional

teste_unitario: Flow.o Model.o System.o FlowComplexo.o FlowExponencial.o FlowLogistico.o Unit_test.o Unit_flow.o Unit_system.o Unit_model.o ../test/unit/main.cpp
	g++ Flow.o FlowComplexo.o FlowExponencial.o FlowLogistico.o Model.o System.o Unit_test.o Unit_flow.o Unit_system.o Unit_model.o ../test/unit/main.cpp  -o teste_unitario -Wall -g

#===============================================================================================================================================================================

MyVensim: Flow.o Model.o System.o
	g++ -c ../src/FlowImpl.cpp ../src/ModelImpl.cpp ../src/SystemImpl.cpp -fpic
	g++ FlowImpl.o ModelImpl.o SystemImpl.o -shared -o lib_MyVensim.so

teste_funcional_dll: MyVensim Functional_test.o FlowComplexo.o FlowExponencial.o FlowLogistico.o ../test/funcional/main.cpp 
	g++ Functional_test.o FlowComplexo.o FlowExponencial.o FlowLogistico.o ../test/funcional/main.cpp -L. -l_MyVensim -o teste_funcional

teste_unitario_dll: MyVensim FlowComplexo.o FlowExponencial.o FlowLogistico.o Unit_test.o Unit_flow.o Unit_system.o Unit_model.o ../test/unit/main.cpp
	g++ FlowComplexo.o FlowExponencial.o FlowLogistico.o Unit_test.o Unit_flow.o Unit_system.o Unit_model.o ../test/unit/main.cpp -L. -l_MyVensim -o teste_unitario -Wall -g

#===============================================================================================================================================================================

Flow.o: ../src/FlowImpl.cpp ../src/Flow.h ../src/FlowImpl.h
	g++ -c ../src/FlowImpl.cpp -o Flow.o -Wall -g

Model.o: ../src/ModelImpl.cpp ../src/Model.h ../src/ModelImpl.h
	g++ -c ../src/ModelImpl.cpp -o Model.o -Wall -g

System.o: ../src/SystemImpl.cpp ../src/System.h ../src/SystemImpl.h
	g++ -c ../src/SystemImpl.cpp -o System.o -Wall -g

#===============================================================================================================================================================================

FlowComplexo.o: ../test/Flows/FlowComplexo.cpp ../test/Flows/FlowComplexo.h Flow.o
	g++ -c ../test/Flows/FlowComplexo.cpp -o FlowComplexo.o -Wall -g

FlowExponencial.o: ../test/Flows/FlowExponencial.cpp ../test/Flows/FlowExponencial.h Flow.o
	g++ -c ../test/Flows/FlowExponencial.cpp -o FlowExponencial.o -Wall -g

FlowLogistico.o: ../test/Flows/FlowLogistico.cpp ../test/Flows/FlowLogistico.h Flow.o
	g++ -c ../test/Flows/FlowLogistico.cpp -o FlowLogistico.o -Wall -g

#===============================================================================================================================================================================

Functional_test.o: ../test/funcional/funcional_tests.cpp
	g++ -c ../test/funcional/funcional_tests.cpp -o Functional_test.o -Wall -g

Unit_test.o: ../test/unit/unit_test.cpp ../test/unit/unit_test.h 
	g++ -c ../test/unit/unit_test.cpp -o Unit_test.o -Wall -g

Unit_flow.o: ../test/unit/unit_flow.cpp ../test/unit/unit_flow.h Flow.o
	g++ -c ../test/unit/unit_flow.cpp -o Unit_flow.o -Wall -g

Unit_system.o: ../test/unit/unit_system.cpp ../test/unit/unit_system.h System.o
	g++ -c ../test/unit/unit_system.cpp -o Unit_system.o -Wall -g

Unit_model.o: ../test/unit/unit_model.cpp ../test/unit/unit_model.h Model.o
	g++ -c ../test/unit/unit_model.cpp -o Unit_model.o -Wall -g
