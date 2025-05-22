/********************************************************************************
** Form generated from reading UI file 'passwordauth_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDAUTH_WINDOW_H
#define UI_PASSWORDAUTH_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Passwordauth_Window
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Passwordauth_Window)
    {
        if (Passwordauth_Window->objectName().isEmpty())
            Passwordauth_Window->setObjectName("Passwordauth_Window");
        Passwordauth_Window->resize(800, 600);
        centralwidget = new QWidget(Passwordauth_Window);
        centralwidget->setObjectName("centralwidget");
        Passwordauth_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Passwordauth_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        Passwordauth_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Passwordauth_Window);
        statusbar->setObjectName("statusbar");
        Passwordauth_Window->setStatusBar(statusbar);

        retranslateUi(Passwordauth_Window);

        QMetaObject::connectSlotsByName(Passwordauth_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Passwordauth_Window)
    {
        Passwordauth_Window->setWindowTitle(QCoreApplication::translate("Passwordauth_Window", "Passwordauth_Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Passwordauth_Window: public Ui_Passwordauth_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDAUTH_WINDOW_H
