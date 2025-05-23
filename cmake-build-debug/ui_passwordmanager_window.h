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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Passwordmanager_Window
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *search_lineEdit;
    QPushButton *search_Button;
    QTableView *record_table;
    QLabel *display_label;
    QPushButton *add_record_Button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Passwordmanager_Window)
    {
        if (Passwordmanager_Window->objectName().isEmpty())
            Passwordmanager_Window->setObjectName("Passwordmanager_Window");
        Passwordmanager_Window->resize(1065, 831);
        centralwidget = new QWidget(Passwordmanager_Window);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(270, 90, 160, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        search_lineEdit = new QLineEdit(horizontalLayoutWidget);
        search_lineEdit->setObjectName("search_lineEdit");

        horizontalLayout->addWidget(search_lineEdit);

        search_Button = new QPushButton(horizontalLayoutWidget);
        search_Button->setObjectName("search_Button");

        horizontalLayout->addWidget(search_Button);

        record_table = new QTableView(centralwidget);
        record_table->setObjectName("record_table");
        record_table->setGeometry(QRect(270, 190, 256, 192));
        display_label = new QLabel(centralwidget);
        display_label->setObjectName("display_label");
        display_label->setGeometry(QRect(280, 390, 40, 12));
        add_record_Button = new QPushButton(centralwidget);
        add_record_Button->setObjectName("add_record_Button");
        add_record_Button->setGeometry(QRect(270, 430, 80, 18));
        Passwordmanager_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Passwordmanager_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1065, 17));
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
        search_Button->setText(QCoreApplication::translate("Passwordmanager_Window", "\346\220\234\347\264\242", nullptr));
        display_label->setText(QString());
        add_record_Button->setText(QCoreApplication::translate("Passwordmanager_Window", "\346\267\273\345\212\240\344\270\200\346\235\241\345\257\206\347\240\201\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Passwordmanager_Window: public Ui_Passwordmanager_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDMANAGER_WINDOW_H
