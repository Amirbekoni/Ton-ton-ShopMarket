/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *AddButton;
    QPushButton *DeleteBtn;
    QListWidget *MainList;
    QTextEdit *productLine;
    QPushButton *Backbtn;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_3;
    QTextEdit *priceLine;
    QTextBrowser *textBrowser_4;
    QTextEdit *dateLine;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(710, 644);
        AddButton = new QPushButton(Widget);
        AddButton->setObjectName("AddButton");
        AddButton->setGeometry(QRect(530, 10, 151, 61));
        QFont font;
        font.setPointSize(15);
        AddButton->setFont(font);
        DeleteBtn = new QPushButton(Widget);
        DeleteBtn->setObjectName("DeleteBtn");
        DeleteBtn->setGeometry(QRect(520, 570, 151, 61));
        DeleteBtn->setFont(font);
        MainList = new QListWidget(Widget);
        MainList->setObjectName("MainList");
        MainList->setGeometry(QRect(10, 240, 661, 321));
        QFont font1;
        font1.setPointSize(14);
        MainList->setFont(font1);
        productLine = new QTextEdit(Widget);
        productLine->setObjectName("productLine");
        productLine->setGeometry(QRect(240, 10, 231, 61));
        productLine->setFont(font);
        Backbtn = new QPushButton(Widget);
        Backbtn->setObjectName("Backbtn");
        Backbtn->setGeometry(QRect(10, 570, 151, 61));
        Backbtn->setFont(font);
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(8, 10, 221, 61));
        textBrowser->setFont(font);
        textBrowser_3 = new QTextBrowser(Widget);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(10, 90, 221, 61));
        textBrowser_3->setFont(font);
        priceLine = new QTextEdit(Widget);
        priceLine->setObjectName("priceLine");
        priceLine->setGeometry(QRect(240, 90, 231, 61));
        priceLine->setFont(font);
        textBrowser_4 = new QTextBrowser(Widget);
        textBrowser_4->setObjectName("textBrowser_4");
        textBrowser_4->setGeometry(QRect(10, 170, 221, 61));
        textBrowser_4->setFont(font);
        dateLine = new QTextEdit(Widget);
        dateLine->setObjectName("dateLine");
        dateLine->setGeometry(QRect(240, 170, 231, 61));
        dateLine->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Ton-ton", nullptr));
        AddButton->setText(QCoreApplication::translate("Widget", "Add Item", nullptr));
        DeleteBtn->setText(QCoreApplication::translate("Widget", "Delete Items", nullptr));
        productLine->setPlaceholderText(QCoreApplication::translate("Widget", "product name", nullptr));
        Backbtn->setText(QCoreApplication::translate("Widget", "Back to Main", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Name of Product:</span></p></body></html>", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Price:</span></p></body></html>", nullptr));
        priceLine->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        priceLine->setPlaceholderText(QCoreApplication::translate("Widget", "product price", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Date:</p></body></html>", nullptr));
        dateLine->setPlaceholderText(QCoreApplication::translate("Widget", "product date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
