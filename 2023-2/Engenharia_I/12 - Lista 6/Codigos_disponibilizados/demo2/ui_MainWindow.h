/********************************************************************************
** Form generated from reading ui file 'calculadorawnd.ui'
**
** Created: Mon May 3 15:58:51 2010
**      by: Qt User Interface Compiler version 4.3.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

class Ui_MainWindow
{
public:
    QAction *action_Abrir;
    QAction *action_Salvar;
    QAction *actionSai_r;
    QAction *action_Copia;
    QWidget *centralwidget;
    QLabel *label_2;
    QTextEdit *textEdit1;
    QLabel *label_3;
    QTextEdit *textEdit2;
    QTextEdit *textEditResult;
    QLabel *label_4;
    QPushButton *exitButton;
    QLabel *label;
    QPushButton *execButton;
    QGroupBox *groupBox;
    QRadioButton *radioButtonMult;
    QRadioButton *radioButtonSoma;
    QRadioButton *radioButtonSub;
    QRadioButton *radioButtonDiv;
    QMenuBar *menubar;
    QMenu *menuE_xit;
    QMenu *menu_Arquivo;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(545, 354);
    action_Abrir = new QAction(MainWindow);
    action_Abrir->setObjectName(QString::fromUtf8("action_Abrir"));
    action_Salvar = new QAction(MainWindow);
    action_Salvar->setObjectName(QString::fromUtf8("action_Salvar"));
    actionSai_r = new QAction(MainWindow);
    actionSai_r->setObjectName(QString::fromUtf8("actionSai_r"));
    action_Copia = new QAction(MainWindow);
    action_Copia->setObjectName(QString::fromUtf8("action_Copia"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    label_2 = new QLabel(centralwidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 40, 46, 14));
    textEdit1 = new QTextEdit(centralwidget);
    textEdit1->setObjectName(QString::fromUtf8("textEdit1"));
    textEdit1->setGeometry(QRect(80, 10, 261, 62));
    label_3 = new QLabel(centralwidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(10, 110, 46, 14));
    textEdit2 = new QTextEdit(centralwidget);
    textEdit2->setObjectName(QString::fromUtf8("textEdit2"));
    textEdit2->setGeometry(QRect(80, 90, 261, 64));
    textEditResult = new QTextEdit(centralwidget);
    textEditResult->setObjectName(QString::fromUtf8("textEditResult"));
    textEditResult->setGeometry(QRect(80, 180, 431, 64));
    label_4 = new QLabel(centralwidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(10, 210, 52, 16));
    exitButton = new QPushButton(centralwidget);
    exitButton->setObjectName(QString::fromUtf8("exitButton"));
    exitButton->setGeometry(QRect(440, 250, 75, 23));
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(98, 250, 321, 30));
    label->setLayoutDirection(Qt::RightToLeft);
    label->setAlignment(Qt::AlignCenter);
    execButton = new QPushButton(centralwidget);
    execButton->setObjectName(QString::fromUtf8("execButton"));
    execButton->setGeometry(QRect(10, 250, 75, 23));
    groupBox = new QGroupBox(centralwidget);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(360, 10, 151, 151));
    radioButtonMult = new QRadioButton(groupBox);
    radioButtonMult->setObjectName(QString::fromUtf8("radioButtonMult"));
    radioButtonMult->setGeometry(QRect(10, 90, 83, 18));
    radioButtonMult->setChecked(false);
    radioButtonSoma = new QRadioButton(groupBox);
    radioButtonSoma->setObjectName(QString::fromUtf8("radioButtonSoma"));
    radioButtonSoma->setGeometry(QRect(10, 30, 83, 18));
    radioButtonSoma->setChecked(true);
    radioButtonSub = new QRadioButton(groupBox);
    radioButtonSub->setObjectName(QString::fromUtf8("radioButtonSub"));
    radioButtonSub->setGeometry(QRect(10, 60, 83, 18));
    radioButtonDiv = new QRadioButton(groupBox);
    radioButtonDiv->setObjectName(QString::fromUtf8("radioButtonDiv"));
    radioButtonDiv->setGeometry(QRect(10, 120, 83, 18));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 545, 21));
    menuE_xit = new QMenu(menubar);
    menuE_xit->setObjectName(QString::fromUtf8("menuE_xit"));
    menu_Arquivo = new QMenu(menubar);
    menu_Arquivo->setObjectName(QString::fromUtf8("menu_Arquivo"));
    menuEdit = new QMenu(menubar);
    menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);
    label_2->setBuddy(textEdit1);
    label_3->setBuddy(textEdit2);
    label_4->setBuddy(textEditResult);
    QWidget::setTabOrder(textEdit1, textEdit2);
    QWidget::setTabOrder(textEdit2, textEditResult);
    QWidget::setTabOrder(textEditResult, radioButtonSoma);
    QWidget::setTabOrder(radioButtonSoma, radioButtonSub);
    QWidget::setTabOrder(radioButtonSub, radioButtonMult);
    QWidget::setTabOrder(radioButtonMult, radioButtonDiv);
    QWidget::setTabOrder(radioButtonDiv, execButton);
    QWidget::setTabOrder(execButton, exitButton);

    menubar->addAction(menu_Arquivo->menuAction());
    menubar->addAction(menuEdit->menuAction());
    menubar->addAction(menuE_xit->menuAction());
    menu_Arquivo->addAction(action_Abrir);
    menu_Arquivo->addAction(action_Salvar);
    menu_Arquivo->addSeparator();
    menu_Arquivo->addAction(actionSai_r);
    menuEdit->addAction(action_Copia);

    retranslateUi(MainWindow);
    QObject::connect(exitButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
    QObject::connect(textEdit1, SIGNAL(textChanged()), textEditResult, SLOT(clear()));
    QObject::connect(textEdit2, SIGNAL(textChanged()), textEditResult, SLOT(clear()));

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Minha Calculadora", 0, QApplication::UnicodeUTF8));
    action_Abrir->setText(QApplication::translate("MainWindow", "&Abrir", 0, QApplication::UnicodeUTF8));
    action_Salvar->setText(QApplication::translate("MainWindow", "&Salvar", 0, QApplication::UnicodeUTF8));
    actionSai_r->setText(QApplication::translate("MainWindow", "Sai&r", 0, QApplication::UnicodeUTF8));
    action_Copia->setText(QApplication::translate("MainWindow", "&Copia", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Parcela 1:", 0, QApplication::UnicodeUTF8));
    textEdit1->setHtml(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">0</p></body></html>", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "Parcela 2:", 0, QApplication::UnicodeUTF8));
    textEdit2->setHtml(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">0</p></body></html>", 0, QApplication::UnicodeUTF8));
    textEditResult->setHtml(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">0</p></body></html>", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindow", "Resultado:", 0, QApplication::UnicodeUTF8));
    exitButton->setText(QApplication::translate("MainWindow", "Sair", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600;\">C A L C U L A D O R A</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    execButton->setText(QApplication::translate("MainWindow", "Executar", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("MainWindow", "Opera\303\247\303\265es", 0, QApplication::UnicodeUTF8));
    radioButtonMult->setText(QApplication::translate("MainWindow", "Multipilica\303\247\303\243o", 0, QApplication::UnicodeUTF8));
    radioButtonSoma->setText(QApplication::translate("MainWindow", "Soma", 0, QApplication::UnicodeUTF8));
    radioButtonSub->setText(QApplication::translate("MainWindow", "Subtra\303\247\303\243o", 0, QApplication::UnicodeUTF8));
    radioButtonDiv->setText(QApplication::translate("MainWindow", "Divis\303\243o", 0, QApplication::UnicodeUTF8));
    menuE_xit->setTitle(QApplication::translate("MainWindow", "E&xit", 0, QApplication::UnicodeUTF8));
    menu_Arquivo->setTitle(QApplication::translate("MainWindow", "&Arquivo", 0, QApplication::UnicodeUTF8));
    menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

#endif // UI_MAINWINDOW_H
