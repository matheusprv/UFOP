#include <QTest>
#include "MyAutoMainWindow.h"
#include "loginDialogBox.h"

class TestMyAutoMainWindow : public QObject {
    Q_OBJECT

private slots:
    void testButtonClick_data();
    void testButtonClick();
    void testLogin_data();
    void testLogin();
};

void TestMyAutoMainWindow::testButtonClick_data() {
    QTest::addColumn<QString>("input1");
    QTest::addColumn<QString>("input2");
    QTest::addColumn<bool>("sumChecked");
    QTest::addColumn<bool>("subChecked");
    QTest::addColumn<bool>("multChecked");
    QTest::addColumn<bool>("divChecked");
    QTest::addColumn<QString>("expectedResult");

    QTest::newRow("Sum")            << "2" << "3" << true << false << false << false << "5";
    QTest::newRow("Subtraction")    << "5" << "3" << false << true << false << false << "2";
    QTest::newRow("Multiplication") << "2" << "3" << false << false << true << false << "6";
    QTest::newRow("Division")       << "6" << "2" << false << false << false << true << "3";
}

void TestMyAutoMainWindow::testButtonClick() {
    QFETCH(QString, input1);
    QFETCH(QString, input2);
    QFETCH(bool, sumChecked);
    QFETCH(bool, subChecked);
    QFETCH(bool, multChecked);
    QFETCH(bool, divChecked);
    QFETCH(QString, expectedResult);

    MyAutoMainWindow mainWindow;
    mainWindow.show();

    mainWindow.getTextEdit1()->setPlainText(input1);
    mainWindow.getTextEdit2()->setPlainText(input2);
    mainWindow.getRadioButtonSoma()->setChecked(sumChecked);
    mainWindow.getRadioButtonSub()->setChecked(subChecked);
    mainWindow.getRadioButtonMult()->setChecked(multChecked);
    mainWindow.getRadioButtonDiv()->setChecked(divChecked);

    QTest::mouseClick(mainWindow.findChild<QPushButton*>("execButton"), Qt::LeftButton);

    QCOMPARE(mainWindow.getTextEditResult()->toPlainText(), expectedResult);
}

void TestMyAutoMainWindow::testLogin_data(){
    QTest::addColumn<QString>("usuario");
    QTest::addColumn<QString>("senha");
    QTest::addColumn<QDialog::DialogCode>("expectedResult");

    QTest::newRow("CorrectCredentials") << "tiago" << "carneiro" << QDialog::Accepted;
}

void TestMyAutoMainWindow::testLogin() {
    QFETCH(QString, usuario);
    QFETCH(QString, senha);
    QFETCH(QDialog::DialogCode, expectedResult);

    LoginDialog loginDialog;
    loginDialog.getNomeTextEdit()->setPlainText(usuario);
    loginDialog.getSenhaTextEdit()->setPlainText(senha);

    QTest::mouseClick(loginDialog.findChild<QPushButton*>("continueButton"), Qt::LeftButton);

    QVERIFY(loginDialog.result() == QDialog::Accepted);

}

QTEST_MAIN(TestMyAutoMainWindow)
#include "unitTest.moc"
