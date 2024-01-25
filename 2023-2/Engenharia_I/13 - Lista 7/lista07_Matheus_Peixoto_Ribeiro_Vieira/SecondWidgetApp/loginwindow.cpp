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
