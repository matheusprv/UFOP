#include <QMessageBox>
#include "MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    connect( ui.execButton, SIGNAL( clicked() ), this, SLOT( operacao() ));
}

void MyMainWindow::operacao( void ){
    QMessageBox::information(this, "T�tulo da Caixa de Mensagem",
             "� f�cil acessar as widgets a partir desse m�todo.?", 
             QMessageBox::Cancel);
}
