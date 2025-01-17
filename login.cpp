#include "login.h"
#include "ui_login.h"
#include "loginmanager.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("Login");

    connect(ui->nameLine, &QLineEdit::textChanged, this, &Login::enableLoginButton);
    connect(ui->passwordLine, &QLineEdit::textChanged, this, &Login::enableLoginButton);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginBtn_clicked()
{
    QString username = ui->nameLine->text().trimmed();
    QString password = ui->passwordLine->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
        return;
    }

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE name = :name AND password = :password");
    query.bindValue(":name", username);
    query.bindValue(":password", hashedPassword);  // Compare with hashed password

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to execute query: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        LoginManager::setLoggedInUser(username);
        accept();
    } else {
        QMessageBox::warning(this, "Login Error", "Incorrect username or password.");
    }
}

void Login::on_loginExit_clicked()
{
    this->close();
}

void Login::enableLoginButton()
{
    ui->loginBtn->setEnabled(!ui->nameLine->text().isEmpty() && !ui->passwordLine->text().isEmpty());
}

QString Login::getName()
{
    return name;
}

QString Login::getPassword()
{
    return password;
}
