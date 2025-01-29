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
#include <QFileDialog>
#include <QFile>
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , isLoggedIn(false)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Ton-ton");

    connect(ui->AddButton, &QPushButton::clicked, this, &Widget::Addition);
    connect(ui->DeleteBtn, &QPushButton::clicked, this, &Widget::Annihilation);
    connect(ui->Backbtn, &QPushButton::clicked, this, &Widget::on_Backbtn_clicked);
    connect(ui->AddImage, &QPushButton::clicked, this, &Widget::on_AddImage_clicked);

    loadProducts();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addProductRow(const QString &productName, double price, const QString &imagePath) {
    QWidget *rowWidget = new QWidget(this);
    QHBoxLayout *rowLayout = new QHBoxLayout(rowWidget);

    QLabel *productLabel = new QLabel(QString("%1 - %2").arg(productName).arg(price, 0, 'f', 2), rowWidget);
    QLabel *imageLabel = new QLabel(rowWidget);

    if (!imagePath.isEmpty()) {
        QPixmap pixmap(imagePath);
        if (pixmap.isNull()) {
            qDebug() << "Failed to load image:" << imagePath;
        } else {
            imageLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        }
    }

    QPushButton *editButton = new QPushButton("Edit", rowWidget);
    QPushButton *deleteButton = new QPushButton("Delete", rowWidget);

    rowLayout->addWidget(imageLabel);
    rowLayout->addWidget(productLabel);
    rowLayout->addWidget(editButton);
    rowLayout->addWidget(deleteButton);
    rowLayout->setContentsMargins(0, 0, 0, 0);

    rowWidget->setLayout(rowLayout);

    QListWidgetItem *listItem = new QListWidgetItem(ui->MainList);
    listItem->setSizeHint(rowWidget->sizeHint());
    ui->MainList->setItemWidget(listItem, rowWidget);

    connect(deleteButton, &QPushButton::clicked, this, [this, productName, listItem]() {
        QSqlQuery query;
        query.prepare("DELETE FROM products WHERE product_name = :product_name");
        query.bindValue(":product_name", productName);

        if (query.exec()) {
            ui->MainList->takeItem(ui->MainList->row(listItem));
            qDebug() << "Product deleted successfully.";
        } else {
            qDebug() << "Failed to delete product:" << query.lastError().text();
            QMessageBox::critical(this, "Database Error", "Failed to delete product from the database.");
        }
    });

    connect(editButton, &QPushButton::clicked, this, [this, productName, price, listItem]() {
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

    bool ok;
    double price = priceText.toDouble(&ok);

    if (!productName.isEmpty() && ok && price > 0.0) {
        QSqlQuery query;
        query.prepare("INSERT INTO products (user_name, product_name, price) VALUES (:user_name, :product_name, :price)");
        query.bindValue(":user_name", LoginManager::getLoggedInUser());
        query.bindValue(":product_name", productName);
        query.bindValue(":price", price);

        if (!query.exec()) {
            qDebug() << "Failed to insert product into database:" << query.lastError().text();
            QMessageBox::critical(this, "Database Error", "Failed to add product to the database.");
            return;
        }

        // Provide a default image path as an empty string
        addProductRow(productName, price, "");

        ui->productLine->clear();
        ui->priceLine->clear();
        qDebug() << "Product added successfully.";
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter valid product details.");
    }
}

void Widget::editProductRow(const QString &oldProductName, double oldPrice, QListWidgetItem *item)
{
    bool ok;
    QString newProductName = QInputDialog::getText(this, "Edit Product", "Enter new product name:",
                                                   QLineEdit::Normal, oldProductName, &ok);
    if (!ok || newProductName.isEmpty()) return;

    double newPrice = QInputDialog::getDouble(this, "Edit Product", "Enter new price:",
                                              oldPrice, 0.0, 1000000.0, 2, &ok);
    if (!ok) return;

    QSqlQuery query;
    query.prepare("UPDATE products SET product_name = :new_name, price = :new_price "
                  "WHERE product_name = :old_name AND user_name = :user_name");
    query.bindValue(":new_name", newProductName);
    query.bindValue(":new_price", newPrice);
    query.bindValue(":old_name", oldProductName);
    query.bindValue(":user_name", LoginManager::getLoggedInUser());

    if (query.exec()) {
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
    query.prepare("SELECT product_name, price, image_path FROM products WHERE user_name = :user_name");
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
        QString imagePath = query.value(2).toString();
        qDebug() << "Product:" << productName << "Price:" << price << "Image path:" << imagePath;
        addProductRow(productName, price, imagePath);
    }


    qDebug() << "Products loaded successfully for user:" << LoginManager::getLoggedInUser();
}

void Widget::on_AddImage_clicked()
{
    static bool isProcessing = false;

    if (isProcessing) {
        qDebug() << "Image upload process is already in progress.";
        return;  // Prevent re-entry if already processing
    }

    isProcessing = true;  // Lock the flag

    // Open file dialog
    QString filePath = QFileDialog::getOpenFileName(this, "Select Image", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp)");

    if (filePath.isEmpty()) {
        qDebug() << "No file selected. Dialog canceled.";
        isProcessing = false;
        return;
    }

    // Prepare the target directory
    QString targetDir = QDir::currentPath() + "/product_images";
    QDir dir(targetDir);
    if (!dir.exists() && !dir.mkpath(targetDir)) {
        QMessageBox::critical(this, "Directory Creation Error", "Failed to create the directory for saving the image.");
        isProcessing = false;
        return;
    }

    // Copy the selected file to the target directory
    QString fileName = QFileInfo(filePath).fileName();
    QString targetFilePath = targetDir + "/" + fileName;
    qDebug() << "Image path being saved:" << targetFilePath;

    if (QFile::copy(filePath, targetFilePath)) {
        QMessageBox::information(this, "Image added.", "Image successfully added to the product.");
        qDebug() << "Image copied to" << targetFilePath;

        // Get product name from the UI
        QString productName = ui->productLine->toPlainText().trimmed();
        if (productName.isEmpty()) {
            QMessageBox::warning(this, "Product name missing", "Please enter a product name.");
            isProcessing = false;
            return;
        }

        // Update the database with the image path
        QSqlQuery query;
        query.prepare("UPDATE products SET image_path = :image_path WHERE user_name = :user_name AND product_name = :product_name");
        query.bindValue(":image_path", targetFilePath);
        query.bindValue(":user_name", LoginManager::getLoggedInUser());
        query.bindValue(":product_name", productName);

        if (!query.exec()) {
            qDebug() << "Failed to update image path in database:" << query.lastError().text();
            QMessageBox::critical(this, "Database Error", "Failed to save image path to the database.");
        } else {
            qDebug() << "Image path saved successfully.";
        }
    } else {
        QMessageBox::critical(this, "Error", "Failed to copy the image file.");
        qDebug() << "Failed to copy file to" << targetFilePath;
    }

    isProcessing = false;  // Release the flag
    return;
}

