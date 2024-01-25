#include <QApplication>

#define DEMO4

#ifdef DEMO1 // Aplicação com duas janelas? PROBELMAS COM CHAMDAS ASSINCRONAS!

#include "loginWindow.h"
#include "MyAutoMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow w1;
    w1.show();

    MyAutoMainWindow w2;
    w2.show();

    return a.exec();
}

#endif


#ifdef DEMO2 // Arquitetura TOSCA!!!! Onde MainWindow é criada?!?!

#include "loginWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow w1;
    w1.show();

    return a.exec();
}

#endif // Arquitetura continua TOSCA!!!! Mas você o rei da gambiarra ?!?!

#ifdef DEMO3

#include "loginWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow w1;
    w1.show();

    return a.exec();
}

#endif

#ifdef DEMO4

#include "loginDialogBox.h"
#include "MyAutoMainWindow.h"

#include <QDebug>
int main(int argc, char *argv[]) // Arquitetura melhorou muito! Não foi preciso fazer gambiarras. Mas, o QT pode ser usando de forma mais inteligente.
{
    QApplication a(argc, argv);

    MyAutoMainWindow w;
    LoginDialog d;

    QObject::connect(&d, &LoginDialog::loginSuccessful, [&w, &d]() {
        w.show();
        d.hide();
    });

    d.show();

    return a.exec();
}

#endif

