#include <stdio.h>
#include <assert.h>

#include "../src/Biblioteca/Estudante.h"
#include "../src/Biblioteca/Disciplina.h"
#include "../src/Biblioteca/ConjOrdenado.h"
#include <typeinfo>


ConjNaoOrdenado<Estudante>* geraEstudantes(bool ordenado){
    ConjNaoOrdenado<Estudante>* conjunto;

    if(ordenado) conjunto = new ConjOrdenado<Estudante>;
    else conjunto = new ConjNaoOrdenado<Estudante>;

    conjunto->adicionarElemento(Estudante("Camila", "654321", 6.0));
    conjunto->adicionarElemento(Estudante("Matheus", "123456", 10.0));
    
    return conjunto;
}

ConjNaoOrdenado<Disciplina>* geraDisciplinas(bool ordenado){
    ConjNaoOrdenado<Disciplina>* conjunto;

    if(ordenado) conjunto = new ConjOrdenado<Disciplina>;
    else conjunto = new ConjNaoOrdenado<Disciplina>;

    conjunto->adicionarElemento(Disciplina("ED1", "Pedro", 90, 11));
    conjunto->adicionarElemento(Disciplina("ED2", "Guilherme", 60, 11));
    conjunto->adicionarElemento(Disciplina("Engenharia I", "Tiago", 60, 11));
    return conjunto;
}

template<typename T, typename K>
void testa_conjunto(T estudante, K disciplina){

    //Count
    assert(estudante->count() == 2);
    assert(disciplina->count() == 3);

    //Soma
    assert(estudante->sum([](const Estudante& estudante){
        return estudante.getMedia();
    }) == 16.0);
    assert(disciplina->sum([](const Disciplina& disciplina){
        return disciplina.getCargaHoraria();
    }) == 210);

    //Media
    assert(estudante->avarage([](const Estudante& estudante){
        return estudante.getMedia();
    }) == 8.0);
    assert(disciplina->avarage([](const Disciplina& disciplina){
        return disciplina.getCargaHoraria();
    }) == 70);

    delete estudante;
    delete disciplina;

}


template<typename T, typename Func>
bool testa_ordenacao(T conjunto, Func obterValor){
    auto vetor = conjunto->getElementos();

    for (unsigned int i = 0; i < vetor.size() - 1; ++i) 
        if (obterValor(vetor[i]) > obterValor(vetor[i+1])) 
            return false;

    return true;
}

template<typename T, typename K>
void testa_conjunto_ordenado(T estudante, K disciplina){

    assert (true == testa_ordenacao(estudante, [](const Estudante obj){
        return obj.getMedia();
    }));

    assert (true == testa_ordenacao(disciplina, [](const Disciplina obj){
        return obj.getCargaHoraria();
    }));

    testa_conjunto(estudante, disciplina);
}


int main(){
    cout << "Teste para conjunto nao ordenado" << endl;
    testa_conjunto(geraEstudantes(0), geraDisciplinas(0));

    cout << "Teste para conjunto ordenado" << endl;
    testa_conjunto_ordenado(geraEstudantes(1), geraDisciplinas(1));

    cout << "Teste finalizado" << endl;
}