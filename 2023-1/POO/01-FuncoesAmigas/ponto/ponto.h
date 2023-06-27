#ifndef PONTO_H
#define PONTO

#include <iostream>
using namespace std;

class Ponto{
    int x, y;

public:
    Ponto(int x = 0, int y = 0);
    ~Ponto();
    int getX(); int getY();
    void setX(int x); void setY(int y);

    void operator++(int);

    Ponto operator+(const Ponto&);
    // Ponto& operator=(const Ponto&);

    // friend bool operator == (const Ponto&, const Ponto&);

};


#endif