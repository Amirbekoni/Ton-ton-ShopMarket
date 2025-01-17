#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QString>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

    QString getUsername() const;
    QString getPassword() const;
    QString getEmail() const;

private slots:
    void on_regButton_clicked();

    void on_exitBtn_clicked();

private:
    Ui::Registration *ui;
    QString name;
    QString password;
    QString email;
};

#endif // REGISTRATION_H
