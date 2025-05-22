/********************************************************************************
** Form generated from reading UI file 'passwordmanager_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDMANAGER_WINDOW_H
#define UI_PASSWORDMANAGER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Passwordmanager_Window
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Passwordmanager_Window)
    {
        if (Passwordmanager_Window->objectName().isEmpty())
            Passwordmanager_Window->setObjectName("Passwordmanager_Window");
        Passwordmanager_Window->resize(800, 600);
        centralwidget = new QWidget(Passwordmanager_Window);
        centralwidget->setObjectName("centralwidget");
        Passwordmanager_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Passwordmanager_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        Passwordmanager_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Passwordmanager_Window);
        statusbar->setObjectName("statusbar");
        Passwordmanager_Window->setStatusBar(statusbar);

        retranslateUi(Passwordmanager_Window);

        QMetaObject::connectSlotsByName(Passwordmanager_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Passwordmanager_Window)
    {
        Passwordmanager_Window->setWindowTitle(QCoreApplication::translate("Passwordmanager_Window", "Passwordmanager_Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Passwordmanager_Window: public Ui_Passwordmanager_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDMANAGER_WINDOW_H
