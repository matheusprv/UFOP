#include "loginWindow.h"
#include "ui_loginWindow.h"
#include<QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

#define DEMO3
#ifdef DEMO1
void LoginWindow::on_continueButton_clicked(){
    QString nome = ui->nomeTextEdit->toPlainText();
    QString senha = ui->senhaTextEdit->toPlainText();

    QString resultStr;
    if(nome == "tiago" && senha == "carneiro")
        resultStr = "BEM VINDO";
    else
         resultStr = "SENHA INCORRETA";

    QMessageBox::information(this, "Login", resultStr, QMessageBox::Close);
}
#endif

#ifdef DEMO2

#include "MyAutoMainWindow.h"

void LoginWindow::on_continueButton_clicked(){
    QString nome = ui->nomeTextEdit->toPlainText();
    QString senha = ui->senhaTextEdit->toPlainText();

    if(nome == "tiago" && senha == "carneiro") {
        MyAutoMainWindow w2;
        w2.show();
    }
    else {
         QMessageBox::information(this, "Login", "SENHA INCORRETA", QMessageBox::Close);
    }
}
#endif


#ifdef DEMO3

#include "MyAutoMainWindow.h"

void LoginWindow::on_continueButton_clicked(){
    QString nome = ui->nomeTextEdit->toPlainText();
    QString senha = ui->senhaTextEdit->toPlainText();

    if(nome == "tiago" && senha == "carneiro") {

        // PRIMEIRA SOLUÇÂO
        //tente passar this como parametro para o construtor para ver oq acontece
        //MyAutoMainWindow *w2 = new MyAutoMainWindow(); // cria um leak de memoria pq esse ponteiro nao é acessivel fora desse escopo! Como fazer o delet
        //MyAutoMainWindow *w2 = new MyAutoMainWindow(this);
        //w2->show();

        // SEGUNDA SOLUCAO
        static MyAutoMainWindow w2;
        w2.show();

        //depois adicione a linha abaixo para terminar o programa
        this->close();
    }
    else {
         QMessageBox::information(this, "Login", "SENHA INCORRETA", QMessageBox::Close);
    }
}
#endif
