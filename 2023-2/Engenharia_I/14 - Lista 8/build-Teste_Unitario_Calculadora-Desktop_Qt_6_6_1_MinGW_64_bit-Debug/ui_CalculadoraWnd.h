/********************************************************************************
** Form generated from reading UI file 'CalculadoraWnd.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULADORAWND_H
#define UI_CALCULADORAWND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

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
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(545, 354);
        action_Abrir = new QAction(MainWindow);
        action_Abrir->setObjectName("action_Abrir");
        action_Salvar = new QAction(MainWindow);
        action_Salvar->setObjectName("action_Salvar");
        actionSai_r = new QAction(MainWindow);
        actionSai_r->setObjectName("actionSai_r");
        action_Copia = new QAction(MainWindow);
        action_Copia->setObjectName("action_Copia");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 46, 14));
        textEdit1 = new QTextEdit(centralwidget);
        textEdit1->setObjectName("textEdit1");
        textEdit1->setGeometry(QRect(80, 10, 261, 62));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 110, 46, 14));
        textEdit2 = new QTextEdit(centralwidget);
        textEdit2->setObjectName("textEdit2");
        textEdit2->setGeometry(QRect(80, 90, 261, 64));
        textEditResult = new QTextEdit(centralwidget);
        textEditResult->setObjectName("textEditResult");
        textEditResult->setGeometry(QRect(80, 180, 431, 64));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 210, 52, 16));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(440, 250, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(98, 250, 321, 30));
        label->setLayoutDirection(Qt::RightToLeft);
        label->setAlignment(Qt::AlignCenter);
        execButton = new QPushButton(centralwidget);
        execButton->setObjectName("execButton");
        execButton->setGeometry(QRect(10, 250, 75, 23));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(360, 10, 151, 151));
        radioButtonMult = new QRadioButton(groupBox);
        radioButtonMult->setObjectName("radioButtonMult");
        radioButtonMult->setGeometry(QRect(10, 90, 83, 18));
        radioButtonMult->setChecked(false);
        radioButtonSoma = new QRadioButton(groupBox);
        radioButtonSoma->setObjectName("radioButtonSoma");
        radioButtonSoma->setGeometry(QRect(10, 30, 83, 18));
        radioButtonSoma->setChecked(true);
        radioButtonSub = new QRadioButton(groupBox);
        radioButtonSub->setObjectName("radioButtonSub");
        radioButtonSub->setGeometry(QRect(10, 60, 83, 18));
        radioButtonDiv = new QRadioButton(groupBox);
        radioButtonDiv->setObjectName("radioButtonDiv");
        radioButtonDiv->setGeometry(QRect(10, 120, 83, 18));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 545, 21));
        menuE_xit = new QMenu(menubar);
        menuE_xit->setObjectName("menuE_xit");
        menu_Arquivo = new QMenu(menubar);
        menu_Arquivo->setObjectName("menu_Arquivo");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        label_2->setBuddy(textEdit1);
        label_3->setBuddy(textEdit2);
        label_4->setBuddy(textEditResult);
#endif // QT_CONFIG(shortcut)
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
        QObject::connect(exitButton, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));
        QObject::connect(textEdit1, &QTextEdit::textChanged, textEditResult, qOverload<>(&QTextEdit::clear));
        QObject::connect(textEdit2, &QTextEdit::textChanged, textEditResult, qOverload<>(&QTextEdit::clear));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Minha Calculadora", nullptr));
        action_Abrir->setText(QCoreApplication::translate("MainWindow", "&Abrir", nullptr));
        action_Salvar->setText(QCoreApplication::translate("MainWindow", "&Salvar", nullptr));
        actionSai_r->setText(QCoreApplication::translate("MainWindow", "Sai&r", nullptr));
        action_Copia->setText(QCoreApplication::translate("MainWindow", "&Copia", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Parcela 1:", nullptr));
        textEdit1->setHtml(QCoreApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">0</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Parcela 2:", nullptr));
        textEdit2->setHtml(QCoreApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">0</p></body></html>", nullptr));
        textEditResult->setHtml(QCoreApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">0</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Resultado:", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Sair", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600;\">C A L C U L A D O R A</span></p></body></html>", nullptr));
        execButton->setText(QCoreApplication::translate("MainWindow", "Executar", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Opera\303\247\303\265es", nullptr));
        radioButtonMult->setText(QCoreApplication::translate("MainWindow", "Multipilica\303\247\303\243o", nullptr));
        radioButtonSoma->setText(QCoreApplication::translate("MainWindow", "Soma", nullptr));
        radioButtonSub->setText(QCoreApplication::translate("MainWindow", "Subtra\303\247\303\243o", nullptr));
        radioButtonDiv->setText(QCoreApplication::translate("MainWindow", "Divis\303\243o", nullptr));
        menuE_xit->setTitle(QCoreApplication::translate("MainWindow", "E&xit", nullptr));
        menu_Arquivo->setTitle(QCoreApplication::translate("MainWindow", "&Arquivo", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "&Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORAWND_H
