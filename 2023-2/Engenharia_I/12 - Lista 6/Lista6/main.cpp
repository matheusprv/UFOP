#define DEMO4

#if defined( DEMO1 ) // Uso direto da interface  \
    // Vantagem: simplicidade \
    // Problema: n�o encapsula a interface, dificil de usar \
    // quando a interface precisar ter suas widgets integradas \
    // a outras fun��es do c�digo

#include <QApplication>
#include <QMessageBox>

#include "mainwindow .h"
void operacao( QWidget *parent ){
    QMessageBox::information(parent, "T�tulo da Caixa de Mensagem",
                             "Como eu vou acessar os widgets a partir desse metodo.", QMessageBox::Cancel);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;
    Ui::MainWindow ui;
    ui.setupUi(window);

    //  Como conectar o sinal "clicked()" do bot�o "Executar" da interface ao
    //  slot que efetivamente executar� as opera��es que constam na interface,
    //  isto �, um slot que invocar� o metodo "int operacao(QWidget *parent)"?
    //  PROBLEMAS:
    //     1) N�o existe nem um objeto ou que forne�a slots
    //     2) Como acessar as widgets dentro do m�todo "operacao"?
    //  SOLU��ES (ruim):
    //     1) Definir uma classe qualquer s� para conseguir um slot
    //     2) Passar o objeto "ui" do tipo "Ui::MainWindow" como par�metro para
    //        o m�todo "operacao"
    QObject::connect( ui.execButton, SIGNAL( clicked() ), ui.exitButton, SIGNAL( clicked() ));
    window->show();
    return app.exec();
}

#elif defined( DEMO2 )// Uso atrav�s de heran�a simples
// Vantagem: encapsulamento da interface, facil defini��o
// dos slots e acesso direto aos widgets da interface
// Problema:
#include <QApplication>
#include "MyMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyMainWindow *window = new MyMainWindow();
    window->show();

    return app.exec();
}

#elif defined( DEMO3 )// Uso atrav�s de heran�a m�ltipla
// Vantagem: mais simplicidade, acesso direto como no
//           codigo feito � m�o
// Problema: n�o � a abordagem adequada para a
//           composi��o de multiplas interfaces com o
//           usu�rio
#include <QApplication>
#include "MyOtherMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyOtherMainWindow *window = new MyOtherMainWindow();
    window->show();

    return app.exec();
}

#elif defined( DEMO4 )// Identico ao anterios mas com uso de auto-conexoes

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyAutoMainWindow *window = new MyAutoMainWindow();
    window->show();

    return app.exec();
}
#endif
