#if !defined( MyAutoMainWindow_H )
#define MyAutoMainWindow_H

#include <QMainWindow>

#include "ui_MainWindow.h"
class MyAutoMainWindow : public QMainWindow, private Ui::MainWindow
{                                 // relacionamento: � um
    Q_OBJECT
public:
    MyAutoMainWindow(QWidget *parent = 0);
public slots:
    void on_execButton_clicked( void );
    void on_radioButtonSoma_clicked(void);
    void on_radioButtonMult_clicked(void);
    void on_radioButtonDiv_clicked(void);
    void on_radioButtonSub_clicked(void);
};

#endif
