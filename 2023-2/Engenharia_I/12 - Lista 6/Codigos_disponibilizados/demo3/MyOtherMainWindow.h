#if !defined( MyOtherMainWindow_H )
#define MyOtherMainWindow_H 

#include <QMainWindow>

#include "ui_MainWindow.h"
class MyOtherMainWindow : public QMainWindow, private Ui::MainWindow
{                                 // relacionamento: é um
     Q_OBJECT                     
 public:
     MyOtherMainWindow(QWidget *parent = 0);
 public slots:
     void operacao( void );
};

#endif
