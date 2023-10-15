#include "Estudante.h"

Estudante :: Estudante(string nome, string matricula, float media){
    this->nome = nome;
    this->matricula = matricula;
    this->media = media;
}

Estudante :: ~Estudante(){}

string Estudante :: getNome() const{
    return this->nome;
}
void Estudante :: setNome(string nome){
    this->nome = nome;
}

string Estudante :: getMatricula() const{
    return this->matricula;
}
void Estudante :: setMatricula(string matricula){
    this->matricula = matricula;
}

float Estudante :: getMedia() const{
    return this->media;
}
void Estudante :: setMedia(float media){
    this->media = media;
}


void Estudante :: serialize(ostream& out) const{
    out << this->getNome() << " - " << this->getMatricula();
}

ostream & operator<< (ostream & out, const Estudante &estudante){
    estudante.serialize(out);

    return out;
}

bool Estudante :: operator<(const Estudante& outro) const {
    return this->media < outro.media;
}