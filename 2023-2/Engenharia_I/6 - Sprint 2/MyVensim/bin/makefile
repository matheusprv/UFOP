teste_funcional: Flow.o FlowComplexo.o FlowExponencial.o FlowLogistico.o Model.o System.o
	g++ Flow.o FlowComplexo.o FlowExponencial.o FlowLogistico.o Model.o System.o ../test/funcional/funcional_tests.cpp  ../test/funcional/main.cpp -o teste_funcional -Wall


teste1: Flow.o FlowComplexo.o FlowExponencial.o FlowLogistico.o Model.o System.o ../test/teste.cpp
	g++ Flow.o FlowComplexo.o FlowExponencial.o FlowLogistico.o Model.o System.o ../test/teste.cpp  -o teste1 -Wall


Flow.o: ../src/biblioteca/Flow.cpp
	g++ -c ../src/biblioteca/Flow.cpp -o Flow.o

Model.o: ../src/biblioteca/Model.cpp
	g++ -c ../src/biblioteca/Model.cpp -o Model.o

System.o: ../src/biblioteca/System.cpp
	g++ -c ../src/biblioteca/System.cpp -o System.o


FlowComplexo.o: ../src/Flows/FlowComplexo.cpp
	g++ -c ../src/Flows/FlowComplexo.cpp -o FlowComplexo.o

FlowExponencial.o: ../src/Flows/FlowExponencial.cpp
	g++ -c ../src/Flows/FlowExponencial.cpp -o FlowExponencial.o

FlowLogistico.o: ../src/Flows/FlowLogistico.cpp
	g++ -c ../src/Flows/FlowLogistico.cpp -o FlowLogistico.o