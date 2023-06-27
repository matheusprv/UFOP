#include <iostream>
using namespace std;

#ifndef RELOGIO_H
#define RELOGIO_H

class Relogio{
    int h, m, s;

public:
    Relogio(int h = 0, int m = 0, int s = 0);
    ~Relogio();
    void setHora(int h, int m, int s);
    void printHora();
    friend void alteraHMS(Relogio &r);
    friend Relogio duplicaRelogio (Relogio &r);

};
#endif