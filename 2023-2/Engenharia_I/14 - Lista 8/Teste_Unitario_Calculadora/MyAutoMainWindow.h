#if !defined( MyAutoMainWindow_H )
#define MyAutoMainWindow_H 

#include <QMainWindow>

#include "ui_CalculadoraWnd.h"
class MyAutoMainWindow : public QMainWindow, private Ui::MainWindow
{                                 // relacionamento: � um
     Q_OBJECT                     
 public:
     MyAutoMainWindow(QWidget *parent = 0);

    QTextEdit* getTextEdit1() const;
    QTextEdit* getTextEdit2() const;
    QRadioButton* getRadioButtonSoma() const;
    QRadioButton* getRadioButtonSub() const;
    QRadioButton* getRadioButtonMult() const;
    QRadioButton* getRadioButtonDiv() const;
    QTextEdit* getTextEditResult() const;


 public slots:
     void on_execButton_clicked( void );
};

#endif
