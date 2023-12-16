main: Produtor.o Buffer.o Consumidor.o
	g++ Produtor.o Buffer.o Consumidor.o -o ProdutorConsumidor ../src/main.cpp -g -Wall

Produtor.o: ../src/Produtor.h ../src/Produtor.cpp
	g++ -c ../src/Produtor.cpp -o Produtor.o -g -Wall

Consumidor.o: ../src/Consumidor.h ../src/Consumidor.cpp
	g++ -c ../src/Consumidor.cpp -o Consumidor.o -g -Wall

Buffer.o: ../src/Buffer.h ../src/Buffer.cpp
	g++ -c ../src/Buffer.cpp -o Buffer.o -g -Wall