/********************************************************************************
** Form generated from reading UI file 'financenote_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINANCENOTE_WINDOW_H
#define UI_FINANCENOTE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Financenote_Window
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Financenote_Window)
    {
        if (Financenote_Window->objectName().isEmpty())
            Financenote_Window->setObjectName("Financenote_Window");
        Financenote_Window->resize(800, 600);
        centralwidget = new QWidget(Financenote_Window);
        centralwidget->setObjectName("centralwidget");
        Financenote_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Financenote_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        Financenote_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Financenote_Window);
        statusbar->setObjectName("statusbar");
        Financenote_Window->setStatusBar(statusbar);

        retranslateUi(Financenote_Window);

        QMetaObject::connectSlotsByName(Financenote_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Financenote_Window)
    {
        Financenote_Window->setWindowTitle(QCoreApplication::translate("Financenote_Window", "Financenote_Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Financenote_Window: public Ui_Financenote_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINANCENOTE_WINDOW_H
