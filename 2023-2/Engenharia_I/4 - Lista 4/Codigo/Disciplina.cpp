#include "Disciplina.h"

Disciplina :: Disciplina(string nome, string professor, int cargaHoraria, int turma){
    this->nome = nome;
    this->professor = professor;
    this->cargaHoraria = cargaHoraria;
    this->turma = turma;
}

Disciplina :: ~Disciplina(){};

string Disciplina :: getNome() const{
    return this->nome;
}
void Disciplina :: setNome(string nome){
    this->nome = nome;
}

string Disciplina :: getProfessor() const{
    return this->professor;
}
void Disciplina :: setProfessor(string professor){
    this->professor = professor;
}

int Disciplina :: getCargaHoraria() const{
    return this->cargaHoraria;
}
void Disciplina :: setCargaHoraria(int cargaHoraria){
    this->cargaHoraria = cargaHoraria;
}

int Disciplina :: getTurma() const{
    return this->turma;
}
void Disciplina :: setTurma(int turma){
    this->turma = turma;
}

void Disciplina :: serialize(ostream& out) const{
    out << this->nome; 
}

ostream & operator<< (ostream & out, const Disciplina &disciplna){
    disciplna.serialize(out);

    return out;
}

bool Disciplina :: operator<(const Disciplina& outro) const {
    return this->cargaHoraria < outro.cargaHoraria;
}