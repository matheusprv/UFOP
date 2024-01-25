/********************************************************************************
** Form generated from reading UI file 'logindialogbox.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOGBOX_H
#define UI_LOGINDIALOGBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QPushButton *continueButton;
    QPushButton *sairButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QTextEdit *nomeTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QTextEdit *senhaTextEdit;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(400, 300);
        LoginDialog->setContextMenuPolicy(Qt::DefaultContextMenu);
        continueButton = new QPushButton(LoginDialog);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(270, 240, 75, 23));
        sairButton = new QPushButton(LoginDialog);
        sairButton->setObjectName("sairButton");
        sairButton->setGeometry(QRect(190, 240, 75, 23));
        verticalLayoutWidget = new QWidget(LoginDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(60, 30, 301, 166));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        nomeTextEdit = new QTextEdit(verticalLayoutWidget);
        nomeTextEdit->setObjectName("nomeTextEdit");

        horizontalLayout_2->addWidget(nomeTextEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        senhaTextEdit = new QTextEdit(verticalLayoutWidget);
        senhaTextEdit->setObjectName("senhaTextEdit");

        horizontalLayout_3->addWidget(senhaTextEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

#if QT_CONFIG(shortcut)
        label->setBuddy(nomeTextEdit);
        label_2->setBuddy(senhaTextEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(LoginDialog);
        QObject::connect(sairButton, &QPushButton::clicked, LoginDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        continueButton->setText(QCoreApplication::translate("LoginDialog", "&continuar", nullptr));
        sairButton->setText(QCoreApplication::translate("LoginDialog", "&sair", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "&Nome:", nullptr));
        label_2->setText(QCoreApplication::translate("LoginDialog", "&Senha:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOGBOX_H
