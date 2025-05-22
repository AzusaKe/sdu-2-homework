/********************************************************************************
** Form generated from reading UI file 'f_add_record_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_ADD_RECORD_WINDOW_H
#define UI_F_ADD_RECORD_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_f_add_record_Window
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *f_add_record_Window)
    {
        if (f_add_record_Window->objectName().isEmpty())
            f_add_record_Window->setObjectName("f_add_record_Window");
        f_add_record_Window->resize(800, 600);
        centralwidget = new QWidget(f_add_record_Window);
        centralwidget->setObjectName("centralwidget");
        f_add_record_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(f_add_record_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        f_add_record_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(f_add_record_Window);
        statusbar->setObjectName("statusbar");
        f_add_record_Window->setStatusBar(statusbar);

        retranslateUi(f_add_record_Window);

        QMetaObject::connectSlotsByName(f_add_record_Window);
    } // setupUi

    void retranslateUi(QMainWindow *f_add_record_Window)
    {
        f_add_record_Window->setWindowTitle(QCoreApplication::translate("f_add_record_Window", "f_add_record_Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class f_add_record_Window: public Ui_f_add_record_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_ADD_RECORD_WINDOW_H
