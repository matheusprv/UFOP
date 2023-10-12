#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Estudante{
    string nome;
    string matricula;
    float media;

public:
    typedef typename vector<Estudante>::iterator iterator;

    Estudante(string = "", string = "", float = 0.0);
    virtual ~Estudante();

    string getNome() const;
    void setNome(string);

    string getMatricula() const;
    void setMatricula(string);

    float getMedia() const;
    void setMedia(float);

    void serialize(ostream&) const;
    friend ostream & operator<< (ostream &, const Estudante&);

    bool operator<(const Estudante& outro) const;
};


#endif