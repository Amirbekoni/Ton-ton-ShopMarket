/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QLabel *label;
    QPushButton *regButton;
    QLineEdit *userName;
    QLineEdit *userPassword;
    QPushButton *exitBtn;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QLineEdit *userEmail;

    void setupUi(QDialog *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName("Registration");
        Registration->resize(504, 407);
        label = new QLabel(Registration);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 10, 131, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        regButton = new QPushButton(Registration);
        regButton->setObjectName("regButton");
        regButton->setGeometry(QRect(30, 320, 141, 61));
        regButton->setFont(font);
        userName = new QLineEdit(Registration);
        userName->setObjectName("userName");
        userName->setGeometry(QRect(210, 90, 261, 51));
        QFont font1;
        font1.setPointSize(16);
        userName->setFont(font1);
        userPassword = new QLineEdit(Registration);
        userPassword->setObjectName("userPassword");
        userPassword->setGeometry(QRect(210, 170, 261, 51));
        userPassword->setFont(font1);
        exitBtn = new QPushButton(Registration);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setGeometry(QRect(210, 320, 141, 61));
        exitBtn->setFont(font);
        textBrowser = new QTextBrowser(Registration);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(30, 90, 141, 51));
        QFont font2;
        font2.setPointSize(15);
        textBrowser->setFont(font2);
        textBrowser_2 = new QTextBrowser(Registration);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(30, 170, 141, 51));
        textBrowser_2->setFont(font2);
        textBrowser_3 = new QTextBrowser(Registration);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(30, 250, 141, 51));
        textBrowser_3->setFont(font2);
        userEmail = new QLineEdit(Registration);
        userEmail->setObjectName("userEmail");
        userEmail->setGeometry(QRect(210, 250, 261, 51));
        userEmail->setFont(font1);

        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QDialog *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Registration", "TonTon", nullptr));
        regButton->setText(QCoreApplication::translate("Registration", "Register", nullptr));
        exitBtn->setText(QCoreApplication::translate("Registration", "Exit", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Registration", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">Username:</span></p></body></html>", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("Registration", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">Password:</span></p></body></html>", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("Registration", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">Email:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
