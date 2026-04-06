#include <stdlib.h>


typedef struct Process{

}Process;

typedef struct Transaction{}Transaction;


typedef struct Vertex{
    int round;
    Process source;
    Transaction block;
    Vertex** strongEdges;
    Vertex** weakEdges;
}Vertex;


