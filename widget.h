#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QListWidget>
#include <QLabel>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QString currentUserName; // To store the logged-in user's name
    bool isLoggedIn;         // To track the login status

    void loadProducts();

private slots:
    void Addition();
    void Annihilation();
    void on_Backbtn_clicked();
    void addProductRow(const QString &productName, double price, const QString &imagePath);
    void editProductRow(const QString &oldProductName, double oldPrice, QListWidgetItem *item);
    void on_AddImage_clicked();
private:
    Ui::Widget *ui;
    Database db;

};

#endif
