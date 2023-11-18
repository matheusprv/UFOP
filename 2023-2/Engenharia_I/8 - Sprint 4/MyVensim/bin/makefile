teste_funcional: Flow.o Model.o System.o FlowComplexo.o FlowExponencial.o FlowLogistico.o  Functional_test.o ../test/funcional/main.cpp
	g++ Flow.o FlowComplexo.o FlowExponencial.o FlowLogistico.o Model.o System.o ../test/funcional/funcional_tests.cpp  ../test/funcional/main.cpp -o teste_funcional -Wall


Flow.o: ../src/FlowImpl.cpp ../src/FlowImpl.h
	g++ -c ../src/FlowImpl.cpp -o Flow.o -Wall

Model.o: ../src/ModelImpl.cpp ../src/ModelImpl.h
	g++ -c ../src/ModelImpl.cpp -o Model.o -Wall

System.o: ../src/SystemImpl.cpp ../src/SystemImpl.h
	g++ -c ../src/SystemImpl.cpp -o System.o -Wall


FlowComplexo.o: ../test/funcional/Flows/FlowComplexo.cpp ../test/funcional/Flows/FlowComplexo.h Flow.o
	g++ -c ../test/funcional/Flows/FlowComplexo.cpp -o FlowComplexo.o -Wall

FlowExponencial.o: ../test/funcional/Flows/FlowExponencial.cpp ../test/funcional/Flows/FlowExponencial.h Flow.o
	g++ -c ../test/funcional/Flows/FlowExponencial.cpp -o FlowExponencial.o -Wall

FlowLogistico.o: ../test/funcional/Flows/FlowLogistico.cpp ../test/funcional/Flows/FlowLogistico.h Flow.o
	g++ -c ../test/funcional/Flows/FlowLogistico.cpp -o FlowLogistico.o -Wall


Functional_test.o: ../test/funcional/funcional_tests.cpp ../test/funcional/funcional_tests.o
	g++ -c ../test/funcional/funcional_tests.cpp -o Functional_test.o -Wall