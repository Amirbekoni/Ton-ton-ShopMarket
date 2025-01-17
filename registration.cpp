#include "registration.h"
#include "ui_registration.h"
#include "loginmanager.h"
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

Registration::Registration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Registration)
{
    ui->setupUi(this);
    setWindowTitle("Registration");
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_regButton_clicked()
{
    name = ui->userName->text().trimmed();
    password = ui->userPassword->text();
    email = ui->userEmail->text().trimmed();

    if (name.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
        return;
    }

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    QSqlQuery query;
    query.prepare("INSERT INTO users (name, password, email) VALUES(:name, :password, :email)");
    query.bindValue(":name", name);
    query.bindValue(":password", hashedPassword);
    query.bindValue(":email", email);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to insert data into the database: " + query.lastError().text());
        return;
    }

    LoginManager::setLoggedInUser(name);

    accept();
}


QString Registration::getUsername() const
{
    return name;
}

QString Registration::getPassword() const
{
    return password;
}

QString Registration::getEmail() const
{
    return email;
}

void Registration::on_exitBtn_clicked()
{
    this->close();
}
