#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_continueButton_clicked(){
    QMessageBox::information(this, "Título da Caixa de Mensagem",
                 "Mais fácil ainda.", QMessageBox::Cancel);
}
