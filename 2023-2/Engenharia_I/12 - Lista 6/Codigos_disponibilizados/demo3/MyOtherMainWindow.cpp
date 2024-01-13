#include <QMessageBox>
#include "MyOtherMainWindow.h"

MyOtherMainWindow::MyOtherMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    connect( execButton, SIGNAL( clicked() ), this, SLOT( operacao() ));
}

void MyOtherMainWindow::operacao( void ){
    QMessageBox::information(this, "Título da Caixa de Mensagem",
             "Mais fácil ainda.", 
             QMessageBox::Cancel);
}
