/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *loginBtn;
    QPushButton *loginExit;
    QLabel *label;
    QLineEdit *nameLine;
    QLineEdit *passwordLine;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(556, 451);
        loginBtn = new QPushButton(Login);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setGeometry(QRect(60, 310, 141, 61));
        QFont font;
        font.setPointSize(20);
        loginBtn->setFont(font);
        loginExit = new QPushButton(Login);
        loginExit->setObjectName("loginExit");
        loginExit->setGeometry(QRect(270, 310, 141, 61));
        loginExit->setFont(font);
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 20, 141, 61));
        QFont font1;
        font1.setPointSize(25);
        label->setFont(font1);
        nameLine = new QLineEdit(Login);
        nameLine->setObjectName("nameLine");
        nameLine->setGeometry(QRect(190, 90, 351, 51));
        QFont font2;
        font2.setPointSize(16);
        nameLine->setFont(font2);
        passwordLine = new QLineEdit(Login);
        passwordLine->setObjectName("passwordLine");
        passwordLine->setGeometry(QRect(190, 200, 351, 51));
        passwordLine->setFont(font2);
        textBrowser_2 = new QTextBrowser(Login);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(20, 200, 141, 51));
        QFont font3;
        font3.setPointSize(15);
        textBrowser_2->setFont(font3);
        textBrowser_3 = new QTextBrowser(Login);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(20, 90, 141, 51));
        textBrowser_3->setFont(font3);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        loginBtn->setText(QCoreApplication::translate("Login", "Login", nullptr));
        loginExit->setText(QCoreApplication::translate("Login", "Exit", nullptr));
        label->setText(QCoreApplication::translate("Login", "Login", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("Login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">Password:</span></p></body></html>", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("Login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">Nickname:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
