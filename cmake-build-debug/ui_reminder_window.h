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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reminder_Window
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *search_lineEdit;
    QPushButton *search_Button;
    QTableView *reminder_record_table;
    QLabel *display_label;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *add_record_Button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *add_old_record_Button;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *old_record_Button;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *exit_Button;
    QSpacerItem *horizontalSpacer_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Reminder_Window)
    {
        if (Reminder_Window->objectName().isEmpty())
            Reminder_Window->setObjectName("Reminder_Window");
        Reminder_Window->resize(326, 366);
        centralwidget = new QWidget(Reminder_Window);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        search_lineEdit = new QLineEdit(centralwidget);
        search_lineEdit->setObjectName("search_lineEdit");

        horizontalLayout->addWidget(search_lineEdit);

        search_Button = new QPushButton(centralwidget);
        search_Button->setObjectName("search_Button");

        horizontalLayout->addWidget(search_Button);


        verticalLayout->addLayout(horizontalLayout);

        reminder_record_table = new QTableView(centralwidget);
        reminder_record_table->setObjectName("reminder_record_table");

        verticalLayout->addWidget(reminder_record_table);

        display_label = new QLabel(centralwidget);
        display_label->setObjectName("display_label");

        verticalLayout->addWidget(display_label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        add_record_Button = new QPushButton(centralwidget);
        add_record_Button->setObjectName("add_record_Button");

        horizontalLayout_2->addWidget(add_record_Button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        add_old_record_Button = new QPushButton(centralwidget);
        add_old_record_Button->setObjectName("add_old_record_Button");

        horizontalLayout_2->addWidget(add_old_record_Button);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        old_record_Button = new QPushButton(centralwidget);
        old_record_Button->setObjectName("old_record_Button");

        horizontalLayout_2->addWidget(old_record_Button);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        exit_Button = new QPushButton(centralwidget);
        exit_Button->setObjectName("exit_Button");

        horizontalLayout_3->addWidget(exit_Button);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        Reminder_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Reminder_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 326, 17));
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
        search_Button->setText(QCoreApplication::translate("Reminder_Window", "\346\220\234\347\264\242", nullptr));
        display_label->setText(QString());
        add_record_Button->setText(QCoreApplication::translate("Reminder_Window", "\346\267\273\345\212\240\344\270\200\346\235\241\346\227\245\347\250\213\350\256\260\345\275\225", nullptr));
        add_old_record_Button->setText(QCoreApplication::translate("Reminder_Window", "\345\260\206\350\277\207\346\227\266\346\217\220\351\206\222\347\247\273\345\205\245\345\233\236\346\224\266\347\253\231", nullptr));
        old_record_Button->setText(QCoreApplication::translate("Reminder_Window", "\346\237\245\347\234\213\345\233\236\346\224\266\347\253\231", nullptr));
        exit_Button->setText(QCoreApplication::translate("Reminder_Window", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reminder_Window: public Ui_Reminder_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDER_WINDOW_H
