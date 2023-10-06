#include <cstdlib>
#include <iostream>

using namespace std;
            
// QUEST�O 1: O c�digo desse exerc�cio � id�ntico ao do exerc�cio anterior. 
//          Por�m o operador "<<" foi sobrecarregado para permitir que 
//          programador implemente de maneira mais f�cil a sa�da do programa.
//          Desta maneira, o codigo a seguir pode ser utilizado para imprimir
//          na tela um objeto "Casa": Casa c1; cout << c1; 
//
//          a) Explique porque o m�todo que sobrecarrega o operador "<<" precisou
//          ser declarado como amigo ("friend") da classe Casa? 
//          b) Explique o funcionamento do novo operador "<<".

/*
    RESPOSTAS:
    a) A sobrecarga do operador << precisa da palavra "friend" pois o << é um operador
    universal e não está na classe especificamente. Dessa forma, para ter acessos a atributos
    e métodos privados.

    b) Com o operador "<<" sobrecarregado, agora, um objeto pode ser impresso na tela simplesmente
    com o comando "cout << objeto", pois a sobrecarga do operador está lidando com a forma como os 
    dados são tratados para serem impressos. 
    Vale ressaltar que, a função recebe um ostream do sistema e o objeto que queremos exibir. Assim,
    colocamos o ostream recebendo os dados da forma como desejamos imprimir para o usuário.
*/
class Casa {
      float orc;
public:
		// Casa( float o ):orc(o){ printf("Casa criada..."); }
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
       friend ostream& operator<<( ostream& s, Casa& c) {  s << c.orc; return s; }
};

// QUEST�O 2: Explique o código abaixo e cada uma das linhas de texto que 
// formam sua sa�da.
/*
    O código instancia um objeto da classe Casa na variavel c1 e referencia o
    mesmo na variavel c2.
    Depois exibe na tela os valores de orc de ambos e altera o orc de c2 para, depois,
    exibir novamente os valores, agora modificados, pois c2 referencia c1, logo os valores
    são os mesmos
*/
int main(int argc, char *argv[])
{
    //Instanciando um objeto c1 da classe Casa com o valor de orc como c7 
    //Referenciando c1 em c2
    Casa c1(7), &c2 = c1;
    
    //Mostrando os valores de orc de c1 e também de c2, que, como é referencia de c1,
    //é o mesmo valor
    cout << "C1: " << c1.getOrc() << ", C2: " << c2.getOrc() << endl;
    //Alterando o valor de orc a partir de c2, mas a modificação reflete em c1,
    //pois ambos compartilham do mesmo endereço de memória para o objeto
    c2.setOrc(3);
    //Mostrando c1 e c2 a partir da sobrecarga do operador "<<"
    //Como c2 é uma referência para c1, os valores são idênticos
    cout << "C1: " << c1 << ", C2: " << c2 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

