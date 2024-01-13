#define DEMO2

#if defined( DEMO1 ) // Uso direto da interface 
                     // Vantagem: simplicidade
                     // Problema: não encapsula a interface, dificil de usar
                     // quando a interface precisar ter suas widgets integradas
                     // a outras funções do código

#include <QApplication>
#include <QMessageBox>

#include "ui_MainWindow.h"                     
void operacao( QWidget *parent ){
     QMessageBox::information(parent, "Título da Caixa de Mensagem",
           "Como eu vou acessar os widgets a partir desse metodo.", QMessageBox::Cancel);
}

int main(int argc, char *argv[]) 
 {
     QApplication app(argc, argv);
     QMainWindow *window = new QMainWindow;
     Ui::MainWindow ui;
     ui.setupUi(window);
    
     //  Como conectar o sinal "clicked()" do botão "Executar" da interface ao 
     //  slot que efetivamente executará as operações que constam na interface,
     //  isto é, um slot que invocará o metodo "int operacao(QWidget *parent)"?
     //  PROBLEMAS: 
     //     1) Não existe nem um objeto ou que forneça slots
     //     2) Como acessar as widgets dentro do método "operacao"?
     //  SOLUÇÕES (ruim): 
     //     1) Definir uma classe qualquer só para conseguir um slot
     //     2) Passar o objeto "ui" do tipo "Ui::MainWindow" como parâmetro para
     //        o método "operacao"
     QObject::connect( ui.execButton, SIGNAL( clicked() ), ui.exitButton, SIGNAL( clicked() ));
     window->show();
     return app.exec();
 }

#elif defined( DEMO2 )// Uso através de herança simples
                     // Vantagem: encapsulamento da interface, facil definição
                     // dos slots e acesso direto aos widgets da interface  
                     // Problema: 
#include <QApplication>
#include "MyMainWindow.h"

int main(int argc, char *argv[]) 
{
     QApplication app(argc, argv);
   
     MyMainWindow *window = new MyMainWindow();
     window->show();
   
     return app.exec();
}

#elif defined( DEMO3 )// Uso através de herança múltipla
                     // Vantagem: mais simplicidade, acesso direto como no 
                     //           codigo feito à mão
                     // Problema: não é a abordagem adequada para a 
                     //           composição de multiplas interfaces com o 
                     //           usuário 
#include <QApplication>
#include "MyOtherMainWindow.h"

int main(int argc, char *argv[]) 
{
     QApplication app(argc, argv);
   
     MyOtherMainWindow *window = new MyOtherMainWindow();
     window->show();
   
     return app.exec();
}

#elif defined( DEMO4 )// Identico ao anterios mas com uso de auto-conexoes 

#include <QApplication>
#include "MyAutoMainWindow.h"

int main(int argc, char *argv[]) 
{
     QApplication app(argc, argv);
   
     MyAutoMainWindow *window = new MyAutoMainWindow();
     window->show();
   
     return app.exec();
}
#endif
