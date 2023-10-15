#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>
using namespace std;

class Disciplina{
    string nome;
    string professor;
    int cargaHoraria;
    int turma;
public:
    Disciplina(string = "", string = "", int = 0, int = 0);
    ~Disciplina();

    
    string getNome() const;
    void setNome(string);

    string getProfessor() const;
    void setProfessor(string);

    int getCargaHoraria() const;
    void setCargaHoraria(int);
    
    int getTurma() const;
    void setTurma(int);

    void serialize(ostream&) const;
    friend ostream & operator << (ostream &, const Disciplina&);

    bool operator<(const Disciplina& outro) const;

};

#endif