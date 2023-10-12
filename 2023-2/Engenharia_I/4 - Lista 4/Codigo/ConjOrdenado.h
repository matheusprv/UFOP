#include "ConjNaoOrdenado.h"


template<typename T>
class ConjOrdenado : public ConjNaoOrdenado<T> {

public:

    void adicionarElemento(T elemento){
        ConjNaoOrdenado<T> :: adicionarElemento(elemento);

        sort(this->begin(), this->end());
    }

};