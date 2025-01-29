#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registration.h"
#include "login.h"
#include "widget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Ton-ton");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_registrationBtn_clicked()
{
    Registration *regWindow = new Registration(this);
    if(regWindow->exec() == QDialog::Accepted){
        qDebug() << "Welcome!";

        static Widget widgetWindow;

        widgetWindow.loadProducts();
        widgetWindow.show();

        this->close();
    } else {
        qDebug() << "ERROR, registration failed!";
        close();
    }

    delete regWindow;
}


void MainWindow::on_loginBtn_clicked()
{
    Login *loginWindow = new Login(this);
    if (loginWindow->exec() == QDialog::Accepted) {
        static Widget widgetWindow;
        widgetWindow.currentUserName = loginWindow->getName();
        widgetWindow.loadProducts();
        widgetWindow.show();

        this->close();
    } else {
        qDebug() << "ERROR";
    }

    delete loginWindow;
}
