//#define EXERC1

#include <cstdlib>
#include <iostream>

using namespace std;
            
#if defined(EXERC1)
// QUESTÃO 1: Critique o código abaixo e aponte seus problemas com relação:
//          a) � flexibilidade da implementação: alterações em pequenos trechos 
//             do código não deveriam exigir recodificação de outras partes
//          b) � legibilidade do código: lendo o código é fácil entrender os 
//             objetos e processos que ele representa. Qual é seu objetivo?


/*
Resposta:
    a) Dentro da implementação da classe, é interessante o uso da sobrecarga do operador << para não ser
    necessario realizar um get para imprimir o objeto
    
    b) O código tem o objetivo de instanciar um objeto da classe Casa, passando para parametro orc o valor 7.
    Ademais, ele também explora conceitos de instancia de objetos, ponteiros e referencia.

*/

class Casa {
      float orc;
      int a;
public:
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
};

#else
// QUESTAO 2: Corrija os problemas identificado na quest�o 1.
class Casa {
    // Coloque suas correções aqui...
    float orc;
    int a;
public:
    Casa(float orc){
        this->orc = orc;
        cout << "Casa criada..." <<endl;
    }
    void setOrc(float orc){
        this->orc = orc;
    }
    float getOrc(){
        return this->orc;
    }
    friend ostream& operator<<( ostream& s, Casa& c){  
        return s << c.orc; 
    }
};
// ...e aqui se necessário.
#endif

// QUESTAO 3: Explique o c�digo abaixo e cada uma das linhas de texto que 
// formam sua sa�da.
int main(int argc, char *argv[])
{
    // Instancia da classe Casa gerando um objeto c1
    // Apontando c1 em c2 e referenciando em c3
    Casa c1(7), *c2 = &c1, &c3 = c1;
    
    //Exibindo na tela o valor de orc de c1 de forma padrão e depois mudando seu valor
    cout << "C1: " << c1.getOrc() << endl;
    c1.setOrc(3);
    
    //Acessando o valor de orc de c1 através do ponteiro c2 que aponta para c1
    cout << "C2: " << c2->getOrc() << ", ";
    
    //Acessando o valor de orc de c1 através da referência c3 que refere-se a c1
    cout << "C3: " << c3.getOrc() << endl;

    //Exibindo o valor de c2, que é o endereço de c1 e exibindo o endereço de c3, que é o mesmo de c1, por referencia-lo
    cout << "C2: " << c2 << ", C3: " << &c3 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
// QUESTAO 4: Quantas vezes o construtor da classe foi invocado? Por que?
/*
    RESPOSTA: O construtor foi invocado uma vez, para c1. Pois, nas outras vezes foram criadas variáveis 
    que apontam para o endereço de memória de c1, logo, novos objetos não foram instanciados
*/
