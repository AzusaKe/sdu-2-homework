/********************************************************************************
** Form generated from reading UI file 'p_add_record_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_P_ADD_RECORD_WINDOW_H
#define UI_P_ADD_RECORD_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_p_add_record_Window
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *p_add_record_Window)
    {
        if (p_add_record_Window->objectName().isEmpty())
            p_add_record_Window->setObjectName("p_add_record_Window");
        p_add_record_Window->resize(800, 600);
        centralwidget = new QWidget(p_add_record_Window);
        centralwidget->setObjectName("centralwidget");
        p_add_record_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(p_add_record_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        p_add_record_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(p_add_record_Window);
        statusbar->setObjectName("statusbar");
        p_add_record_Window->setStatusBar(statusbar);

        retranslateUi(p_add_record_Window);

        QMetaObject::connectSlotsByName(p_add_record_Window);
    } // setupUi

    void retranslateUi(QMainWindow *p_add_record_Window)
    {
        p_add_record_Window->setWindowTitle(QCoreApplication::translate("p_add_record_Window", "p_add_record_Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class p_add_record_Window: public Ui_p_add_record_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P_ADD_RECORD_WINDOW_H
