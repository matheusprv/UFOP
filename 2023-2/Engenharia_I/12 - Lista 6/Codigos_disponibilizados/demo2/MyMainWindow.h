#if !defined( MyMainWindow_H )
#define MyMainWindow_H 

#include <QMainWindow>

#include "ui_MainWindow.h"
class MyMainWindow : public QMainWindow
{
     Q_OBJECT
 public:
     MyMainWindow(QWidget *parent = 0);
 private:
     Ui::MainWindow ui; // relacionamento: possui
 public slots:
     void operacao( void );
};

#endif
