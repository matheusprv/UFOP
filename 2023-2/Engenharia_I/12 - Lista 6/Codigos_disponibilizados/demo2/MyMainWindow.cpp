#include <QMessageBox>
#include "MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    connect( ui.execButton, SIGNAL( clicked() ), this, SLOT( operacao() ));
}

void MyMainWindow::operacao( void ){
    QMessageBox::information(this, "Título da Caixa de Mensagem",
             "É fácil acessar as widgets a partir desse método.?", 
             QMessageBox::Cancel);
}
