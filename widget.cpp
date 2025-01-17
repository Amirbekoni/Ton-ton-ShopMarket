#include "widget.h"
#include "ui_widget.h"
#include "mainwindow.h"
#include "loginmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QDate>
#include <QVariant>
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QInputDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , isLoggedIn(false)
{
    ui->setupUi(this);
    setWindowTitle("Ton-ton");

    connect(ui->AddButton, &QPushButton::clicked, this, &Widget::Addition);
    connect(ui->DeleteBtn, &QPushButton::clicked, this, &Widget::Annihilation);
    connect(ui->Backbtn, &QPushButton::clicked, this, &Widget::on_Backbtn_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addProductRow(const QString &productName, double price)
{
    QWidget *rowWidget = new QWidget(this);
    QHBoxLayout *rowLayout = new QHBoxLayout(rowWidget);

    // Create a label for product details
    QLabel *productLabel = new QLabel(QString("%1 - %2").arg(productName).arg(price, 0, 'f', 2), rowWidget);

    QPushButton *editButton = new QPushButton("Edit", rowWidget);
    QPushButton *deleteButton = new QPushButton("Delete", rowWidget);

    rowLayout->addWidget(productLabel);
    rowLayout->addWidget(editButton);
    rowLayout->addWidget(deleteButton);

    rowLayout->setContentsMargins(0, 0, 0, 0); // Remove extra spacing

    rowWidget->setLayout(rowLayout);

    //Add the custom widget to the list
    QListWidgetItem *listItem = new QListWidgetItem(ui->MainList);
    listItem->setSizeHint(rowWidget->sizeHint());
    ui->MainList->setItemWidget(listItem, rowWidget);

    connect(deleteButton, &QPushButton::clicked, this, [this, productName, listItem]() {
        deleteProductRow(productName, listItem);
    });

    connect(editButton, &QPushButton::clicked, this, [this, productName, price, listItem](){
        editProductRow(productName, price, listItem);
    });
}

void Widget::Addition()
{
    if (!LoginManager::isUserLoggedIn()) {
        QMessageBox::warning(this, "Login Required", "Please log in to add a product.");
        return;
    }

    QString productName = ui->productLine->toPlainText().trimmed();
    QString priceText = ui->priceLine->toPlainText().trimmed();
    QString productDate = ui->dateLine->toPlainText().trimmed();

    bool ok;
    double price = priceText.toDouble(&ok);

    if (!productName.isEmpty() && ok && price > 0.0) {
        QDate date;
        if (!productDate.isEmpty()) {
            date = QDate::fromString(productDate, "dd-MM-yyyy");
            if (!date.isValid()) {
                QMessageBox::warning(this, "Invalid Date", "Please enter a valid date in the format dd-MM-yyyy.");
                return;
            }
        }

        QSqlQuery query;
        query.prepare("INSERT INTO products (user_name, product_name, price, date) VALUES (:user_name, :product_name, :price, :date);");
        query.bindValue(":user_name", LoginManager::getLoggedInUser()); // Bind user name
        query.bindValue(":product_name", productName); // Bind product name
        query.bindValue(":price", price); // Bind price

        // Handle optional productDate
        if (productDate.isEmpty()) {
            query.bindValue(":date", QVariant(QVariant::Date)); // Bind NULL if no date provided
        } else {
            // Convert date to YYYY-MM-DD format
            QString formattedDate = date.toString("yyyy-MM-dd");
            query.bindValue(":date", formattedDate); // Bind provided date in the correct format
        }

        if (!query.exec()) {
            qDebug() << "Failed to insert product into database:" << query.lastError().text();
            QMessageBox::critical(this, "Database Error", "Failed to add product to the database.");
            return;
        }

        addProductRow(productName, price);

        ui->productLine->clear();
        ui->priceLine->clear();
        ui->dateLine->clear();

        qDebug() << "Product added successfully.";
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter valid product details.");
    }
}

void Widget::deleteProductRow(const QString &productName, QListWidgetItem *item)
{
    QSqlQuery query;
    query.prepare("DELETE FROM products WHERE user_name = :user_name AND product_name = :product_name");
    query.bindValue(":user_name", LoginManager::getLoggedInUser());
    query.bindValue(":product_name", productName);

    if (query.exec()) {
        delete ui->MainList->takeItem(ui->MainList->row(item));
        qDebug() << "Product deleted successfully.";
    } else {
        qDebug() << "Failed to delete product:" << query.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to delete product from the database.");
    }
}

void Widget::editProductRow(const QString &oldProductName, double oldPrice, QListWidgetItem *item)
{

    bool ok;
    QString newProductName = QInputDialog::getText(this, "Edit Product",
                                                   "Enter new product name:",
                                                   QLineEdit::Normal,
                                                   oldProductName,
                                                   &ok);
    if (!ok || newProductName.isEmpty()) {
        return; // User canceled or entered an empty name
    }

    // Prompt for new price
    double newPrice = QInputDialog::getDouble(this, "Edit Product",
                                              "Enter new price:",
                                              oldPrice, 0.0, 1000000.0, 2, &ok);
    if (!ok) {
        return; // User canceled
    }

    // Update in the database
    QSqlQuery query;
    query.prepare("UPDATE products SET product_name = :new_name, price = :new_price "
                  "WHERE product_name = :old_name AND user_name = :user_name");
    query.bindValue(":new_name", newProductName);
    query.bindValue(":new_price", newPrice);
    query.bindValue(":old_name", oldProductName);
    query.bindValue(":user_name", LoginManager::getLoggedInUser());

    if (query.exec()) {
        // Update the UI
        QWidget *rowWidget = ui->MainList->itemWidget(item);
        QLabel *productLabel = rowWidget->findChild<QLabel *>();
        if (productLabel) {
            productLabel->setText(QString("%1 - %2").arg(newProductName).arg(newPrice, 0, 'f', 2));
        }
        qDebug() << "Product updated successfully.";
    } else {
        qDebug() << "Failed to update product:" << query.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to update product in the database.");
    }
}


void Widget::Annihilation()
{
    if (ui->MainList->count() == 0) {
        QMessageBox::information(this, "No Products", "There are no products to delete.");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM products WHERE user_name = :user_name");
    query.bindValue(":user_name", LoginManager::getLoggedInUser());

    if (query.exec()) {
        ui->MainList->clear();
        qDebug() << "All products deleted from the list and database.";
    } else {
        qDebug() << "Error deleting products: " << query.lastError().text();
    }
}

void Widget::on_Backbtn_clicked()
{
    static MainWindow window;
    window.show();
    this->close();
    qDebug() << "Returning to the main window.";
}

void Widget::loadProducts()
{
    QSqlQuery query;
    query.prepare("SELECT product_name, price FROM products WHERE user_name = :user_name");
    query.bindValue(":user_name", LoginManager::getLoggedInUser());

    if (!query.exec()) {
        qDebug() << "Failed to load products:" << query.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to load products from the database.");
        return;
    }

    ui->MainList->clear();

    while (query.next()) {
        QString productName = query.value(0).toString();
        double price = query.value(1).toDouble();
        addProductRow(productName, price);
    }

    qDebug() << "Products loaded successfully for user:" << LoginManager::getLoggedInUser();
}
