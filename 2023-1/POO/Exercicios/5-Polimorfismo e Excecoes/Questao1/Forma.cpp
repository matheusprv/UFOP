#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

class Forma{
public:
    virtual double getArea() = 0;

};

class FormaBidimensional : public Forma{
public:
};

class Circulo : public FormaBidimensional{
    double x, y, radius;
public:
    Circulo(double x, double y, double radius){
        this->x = x;
        this->y = y;
        this->radius = radius;
    }

    double getArea(){
        return 3.14 * this->radius * this->radius;
    }
};

class Retangulo : public FormaBidimensional{
    double x, y, width, height;
public: 
    Retangulo(double x, double y, double width, double height){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    double getArea(){
        return this->width * this->height;
    }
};

class Triangulo : public FormaBidimensional{
    double x[3];
    double y[3];

public:
    Triangulo(double x1, double y1, double x2, double y2, double x3, double y3){
        this->x[0] = x1;
        this->x[1] = x2;
        this->x[2] = x3;
        this->y[0] = y1;
        this->y[1] = y2;
        this->y[2] = y3;
    }

    double getArea(){
        return (this->x[0] * (this->y[1] - this->y[2]) + this->x[1] * (this->y[2] - this->y[0]) + this->x[2] * (this->y[0] - this->y[1])) / 2;
    }
};

class FormaTridimensional : public Forma{
public:
    virtual double getArea() = 0;
    virtual double getVolume() = 0;
};

class Circunferencia : public FormaTridimensional{
    double x, y, radius;
public: 
    Circunferencia(double x, double y, double radius){
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    double getArea(){
        return 3.14 * this->radius * this->radius;
    }
    double getVolume(){
        return 3.14 * this->radius * this->radius * this->radius;
    }
};

class Cube : public FormaTridimensional{
    double x, y, width, height;
public:
    Cube(double x = 0, double y = 0, double width = 0, double height = 0){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
    double getArea(){
        return this->height * this->width;
    }
    double getVolume(){
        return this->height * this->width * this->height;
    }
};

int main(){

    vector<Forma*> formas;

    Cube * cubo = new Cube(5,10,12,10);
    Triangulo * triangulo = new Triangulo(5,10,12,10,15,15);
    Circulo * circulo = new Circulo(5,12,10);
    Circunferencia * cunferencia = new Circunferencia(5,12,10);

    formas.push_back( cubo );
    formas.push_back( triangulo );
    formas.push_back( circulo );
    formas.push_back( cunferencia );

    for(Forma * forma : formas){
        cout << forma->getArea() << endl;

        if(typeid(*forma) == typeid(class Cube)){
            cout << (dynamic_cast<Cube*>(forma)) -> getVolume() << endl;
        }

        if(typeid(*forma) == typeid(class Circunferencia))
	        cout << (dynamic_cast<Circunferencia*>(forma))->getVolume() << endl;

        cout << "================================================================\n";

    }

    return 0;
}