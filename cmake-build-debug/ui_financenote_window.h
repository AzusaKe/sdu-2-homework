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

class Ui_Financenote_Window
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *search_lineEdit;
    QPushButton *search_Button;
    QTableView *financenote_record_table;
    QLabel *display_label;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *add_record_Button;
    QSpacerItem *horizontalSpacer;
    QPushButton *exit_Button;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Financenote_Window)
    {
        if (Financenote_Window->objectName().isEmpty())
            Financenote_Window->setObjectName("Financenote_Window");
        Financenote_Window->resize(329, 386);
        centralwidget = new QWidget(Financenote_Window);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        search_lineEdit = new QLineEdit(centralwidget);
        search_lineEdit->setObjectName("search_lineEdit");

        horizontalLayout_4->addWidget(search_lineEdit);

        search_Button = new QPushButton(centralwidget);
        search_Button->setObjectName("search_Button");

        horizontalLayout_4->addWidget(search_Button);


        verticalLayout->addLayout(horizontalLayout_4);

        financenote_record_table = new QTableView(centralwidget);
        financenote_record_table->setObjectName("financenote_record_table");

        verticalLayout->addWidget(financenote_record_table);

        display_label = new QLabel(centralwidget);
        display_label->setObjectName("display_label");

        verticalLayout->addWidget(display_label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        add_record_Button = new QPushButton(centralwidget);
        add_record_Button->setObjectName("add_record_Button");

        horizontalLayout_3->addWidget(add_record_Button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        exit_Button = new QPushButton(centralwidget);
        exit_Button->setObjectName("exit_Button");

        horizontalLayout_3->addWidget(exit_Button);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        Financenote_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Financenote_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 329, 17));
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
        search_Button->setText(QCoreApplication::translate("Financenote_Window", "\346\220\234\347\264\242", nullptr));
        display_label->setText(QCoreApplication::translate("Financenote_Window", "\346\200\273\351\207\221\351\242\235\357\274\232", nullptr));
        add_record_Button->setText(QCoreApplication::translate("Financenote_Window", "\346\267\273\345\212\240\344\270\200\346\235\241\350\264\246\345\215\225\350\256\260\345\275\225", nullptr));
        exit_Button->setText(QCoreApplication::translate("Financenote_Window", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Financenote_Window: public Ui_Financenote_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINANCENOTE_WINDOW_H
