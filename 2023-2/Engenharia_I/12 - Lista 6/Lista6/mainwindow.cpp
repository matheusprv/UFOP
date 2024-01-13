#include "mainwindow.h"
#include <QTextEdit>
#include <QDoubleSpinBox>

MyAutoMainWindow::MyAutoMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    // A linha de codigo comentada abaixo n�o � necess�ria
    //connect( execButton, SIGNAL( clicked() ), this, SLOT( operacao() ));
}

void MyAutoMainWindow::on_execButton_clicked( void ){

    // F�cil acessar widgets e auto-conectado

    float parcela1 = textEdit1->value();
    float parcela2 = textEdit2->value();


    float result = 0;
    if(radioButtonSoma->isChecked())      result = parcela1 + parcela2;
    else if(radioButtonSub->isChecked())  result = parcela1 - parcela2;
    else if(radioButtonMult->isChecked()) result = parcela1 * parcela2;
    else if(radioButtonDiv->isChecked())  result = parcela1 / parcela2;

    QString resultStr;
    resultStr.setNum( result );
    textEditResult->setText( resultStr );

}

void MyAutoMainWindow :: on_radioButtonSoma_clicked(void){
    on_execButton_clicked();
}
void MyAutoMainWindow :: on_radioButtonMult_clicked(void){
    on_execButton_clicked();
}
void MyAutoMainWindow :: on_radioButtonDiv_clicked(void){
    on_execButton_clicked();
}
void MyAutoMainWindow :: on_radioButtonSub_clicked(void){
    on_execButton_clicked();
}
