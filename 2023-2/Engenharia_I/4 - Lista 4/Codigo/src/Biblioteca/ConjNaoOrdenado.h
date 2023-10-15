#include <vector>
#include <algorithm>
using namespace std;


template<typename T>
class ConjNaoOrdenado{
    vector<T> elementos;

public:
    typedef typename vector<T>::iterator iterator;

    ConjNaoOrdenado(void){}

    virtual ~ConjNaoOrdenado(){}

    virtual void adicionarElemento(T elemento){
        elementos.push_back(elemento);
    }

    void imprimirElementos(){
        for(int i = 0; i < (int) elementos.size(); i++){
            cout << elementos[i] << " | ";
        }
        cout << endl;
    }

    vector<T> getElementos(){
        return this->elementos;
    }
    
    iterator begin( void ) {
		return elementos.begin();
	}
	iterator end( void ){
		return elementos.end();
	}

    int count(){
        int qtd = 0;
        
        iterator inicio = this->begin();
        iterator fim = this->end();
        
        while(inicio != fim){
            qtd ++;
            inicio++;
        }

        return qtd;
    }

    template<typename Func>
    float sum(Func extrairValor){
        float soma = 0.0;

        for(const auto& elemento : this->getElementos())
            soma += extrairValor(elemento);

        return soma;
    }


    template<typename Func>
    float avarage(Func extrairValor){
        float soma = sum(extrairValor);

        return elementos.size() > 0 ? soma / elementos.size() : 0.0;
    }

};