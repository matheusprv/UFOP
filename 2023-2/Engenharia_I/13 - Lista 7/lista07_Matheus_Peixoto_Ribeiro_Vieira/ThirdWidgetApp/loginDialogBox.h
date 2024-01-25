#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog: public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

signals:
    void loginSuccessful();

private:
    Ui::LoginDialog *ui;
public slots:
    void on_continueButton_clicked();


};

#endif // LOGINDIALOG_H
