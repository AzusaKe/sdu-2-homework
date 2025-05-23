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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Passwordmanager_Window
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *search_lineEdit;
    QPushButton *search_Button;
    QTableView *passwordmanager_record_table;
    QLabel *display_label;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *add_record_Button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exit_Button;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Passwordmanager_Window)
    {
        if (Passwordmanager_Window->objectName().isEmpty())
            Passwordmanager_Window->setObjectName("Passwordmanager_Window");
        Passwordmanager_Window->resize(326, 393);
        centralwidget = new QWidget(Passwordmanager_Window);
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

        passwordmanager_record_table = new QTableView(centralwidget);
        passwordmanager_record_table->setObjectName("passwordmanager_record_table");

        verticalLayout->addWidget(passwordmanager_record_table);

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

        exit_Button = new QPushButton(centralwidget);
        exit_Button->setObjectName("exit_Button");

        horizontalLayout_2->addWidget(exit_Button);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        Passwordmanager_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Passwordmanager_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 326, 17));
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
        exit_Button->setText(QCoreApplication::translate("Passwordmanager_Window", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Passwordmanager_Window: public Ui_Passwordmanager_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDMANAGER_WINDOW_H
