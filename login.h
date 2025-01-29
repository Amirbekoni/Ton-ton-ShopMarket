#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    QString getName();
    QString getPassword();

private slots:
    void on_loginBtn_clicked();
    void on_loginExit_clicked();
    void enableLoginButton(); // Enable or disable login button based on input fields

private:
    Ui::Login *ui;
    QString name;
    QString password;
};

#endif // LOGIN_H
