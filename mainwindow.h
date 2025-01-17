#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registration.h"
#include "login.h"
#include "widget.h"
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_registrationBtn_clicked();
    void on_loginBtn_clicked();

private:
    Ui::MainWindow *ui;
    Registration *registrationWindow;
    Login *loginWindow;
    Widget window;
};

#endif // MAINWINDOW_H
