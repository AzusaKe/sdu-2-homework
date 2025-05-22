/********************************************************************************
** Form generated from reading UI file 'r_add_record_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_R_ADD_RECORD_WINDOW_H
#define UI_R_ADD_RECORD_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_r_add_record_Window
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *r_add_record_Window)
    {
        if (r_add_record_Window->objectName().isEmpty())
            r_add_record_Window->setObjectName("r_add_record_Window");
        r_add_record_Window->resize(800, 600);
        centralwidget = new QWidget(r_add_record_Window);
        centralwidget->setObjectName("centralwidget");
        r_add_record_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(r_add_record_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        r_add_record_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(r_add_record_Window);
        statusbar->setObjectName("statusbar");
        r_add_record_Window->setStatusBar(statusbar);

        retranslateUi(r_add_record_Window);

        QMetaObject::connectSlotsByName(r_add_record_Window);
    } // setupUi

    void retranslateUi(QMainWindow *r_add_record_Window)
    {
        r_add_record_Window->setWindowTitle(QCoreApplication::translate("r_add_record_Window", "r_add_record_Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class r_add_record_Window: public Ui_r_add_record_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_R_ADD_RECORD_WINDOW_H
