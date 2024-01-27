#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include<QMessageBox>



namespace Ui {
class LoginDialog;
}

class LoginDialog: public QDialog
{
    Q_OBJECT
    // Importante para acessar todos os dados privados da classe testada
    friend class TestLoginDialogGUI;

protected:
    virtual void closeEvent(QCloseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    QTextEdit* getNomeTextEdit() const;
    QTextEdit* getSenhaTextEdit() const;

private:
    Ui::LoginDialog *ui;
public slots:
    void on_continueButton_clicked();
};

#endif // LOGINDIALOG_H
