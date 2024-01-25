#include "loginDialogBox.h"
#include "ui_logindialogbox.h"
#include<QMessageBox>
#include<QCloseEvent>
#include<QKeyEvent>

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent), ui(new Ui::LoginDialog){
    ui->setupUi(this);
}

LoginDialog::~LoginDialog(){
    delete ui;
}

void LoginDialog::on_continueButton_clicked(){
    QString nome  = ui->nomeTextEdit->toPlainText();
    QString senha = ui->senhaTextEdit->toPlainText();

    QString resultStr;

    if(nome == "tiago" && senha == "carneiro"){
        resultStr = "BEM VINDO";
        this->accept();
        emit loginSuccessful();
    }
    else resultStr = "SENHA INCORRETA";

    QMessageBox::information(this, "Login", resultStr, QMessageBox::Close);
}

