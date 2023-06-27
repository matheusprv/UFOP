#include "ponto.h"

Ponto :: Ponto (int x, int y) : x(x), y(y){}

Ponto :: ~Ponto(){}

int Ponto :: getX(){
    return this->x;
}

int Ponto :: getY(){
    return this->y;
}

void Ponto :: setX(int x){
    this->x = x;
}

void Ponto :: setY(int y){
    this->y = y;
}

void Ponto :: operator++(int){
    this->x++;
    this->y++;
}

Ponto Ponto :: operator+(const Ponto & P2){
    Ponto temp;
    temp.x = this->x + P2.x;
    temp.y = this->y + P2.y;
    return temp;
}