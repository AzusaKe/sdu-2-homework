/********************************************************************************
** Form generated from reading UI file 'reminder_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDER_WINDOW_H
#define UI_REMINDER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reminder_Window
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Reminder_Window)
    {
        if (Reminder_Window->objectName().isEmpty())
            Reminder_Window->setObjectName("Reminder_Window");
        Reminder_Window->resize(800, 600);
        centralwidget = new QWidget(Reminder_Window);
        centralwidget->setObjectName("centralwidget");
        Reminder_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Reminder_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        Reminder_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Reminder_Window);
        statusbar->setObjectName("statusbar");
        Reminder_Window->setStatusBar(statusbar);

        retranslateUi(Reminder_Window);

        QMetaObject::connectSlotsByName(Reminder_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Reminder_Window)
    {
        Reminder_Window->setWindowTitle(QCoreApplication::translate("Reminder_Window", "Reminder_Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reminder_Window: public Ui_Reminder_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDER_WINDOW_H
