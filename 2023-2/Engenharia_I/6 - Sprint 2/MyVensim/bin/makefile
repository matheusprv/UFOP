teste_funcional: Flow.o Model.o System.o FlowComplexo.o FlowExponencial.o FlowLogistico.o ../test/funcional/funcional_tests.cpp  ../test/funcional/main.cpp
	g++ Flow.o FlowComplexo.o FlowExponencial.o FlowLogistico.o Model.o System.o ../test/funcional/funcional_tests.cpp  ../test/funcional/main.cpp -o teste_funcional -Wall


Flow.o: ../src/Flow.cpp
	g++ -c ../src/Flow.cpp -o Flow.o -Wall

Model.o: ../src/Model.cpp
	g++ -c ../src/Model.cpp -o Model.o -Wall

System.o: ../src/System.cpp
	g++ -c ../src/System.cpp -o System.o -Wall


FlowComplexo.o: ../test/funcional/Flows/FlowComplexo.cpp
	g++ -c ../test/funcional/Flows/FlowComplexo.cpp -o FlowComplexo.o -Wall

FlowExponencial.o: ../test/funcional/Flows/FlowExponencial.cpp
	g++ -c ../test/funcional/Flows/FlowExponencial.cpp -o FlowExponencial.o -Wall

FlowLogistico.o: ../test/funcional/Flows/FlowLogistico.cpp
	g++ -c ../test/funcional/Flows/FlowLogistico.cpp -o FlowLogistico.o -Wall