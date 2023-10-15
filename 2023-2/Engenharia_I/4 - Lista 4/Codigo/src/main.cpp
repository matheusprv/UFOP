#include "Biblioteca/Estudante.h"
#include "Biblioteca/Disciplina.h"
#include "Biblioteca/ConjOrdenado.h"


int main(){

    ConjNaoOrdenado <Estudante> conjunto;
    conjunto.adicionarElemento(Estudante("Camila", "654321", 6.0));
    conjunto.adicionarElemento(Estudante("Matheus", "123456", 10.0));


    ConjOrdenado<Disciplina> conjunto2;
    conjunto2.adicionarElemento(Disciplina("ED1", "Pedro", 90, 11));
    conjunto2.adicionarElemento(Disciplina("ED2", "Guilherme", 60, 11));


    conjunto.imprimirElementos();
    conjunto2.imprimirElementos();


    cout << conjunto2.count() << endl ;

    cout << conjunto2.sum([](const Disciplina& disciplina){
            return disciplina.getCargaHoraria();
        }) << endl;


    cout << conjunto2.avarage([](const Disciplina& disciplina){
        return disciplina.getCargaHoraria();
    }) << endl;

    return 0;

}