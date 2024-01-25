#include "MyAutoMainWindow.h"
#include <QTextEdit>

MyAutoMainWindow::MyAutoMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    // A linha de codigo comentada abaixo n�o � necess�ria
    //connect( execButton, SIGNAL( clicked() ), this, SLOT( operacao() ));
}

void MyAutoMainWindow::on_execButton_clicked( void ){

     // F�cil acessar widgets e auto-conectado
     
     float parcela1 = textEdit1->toPlainText().toFloat();
     float parcela2 = textEdit2->toPlainText().toFloat();
     
     
     float result = 0;
     if( radioButtonSoma->isChecked() )      result = parcela1 + parcela2;
     else if( radioButtonSub->isChecked() )  result = parcela1 - parcela2;
     else if( radioButtonMult->isChecked() ) result = parcela1 * parcela2;
     else if( radioButtonDiv->isChecked() )  result = parcela1 / parcela2;
     
     QString resultStr;
     resultStr.setNum( result );
     textEditResult->setText( resultStr );

}

void MyAutoMainWindow::on_pushButton_2_clicked(void){
    this->close();
}
