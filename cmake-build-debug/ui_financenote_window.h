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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Financenote_Window
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *exit_Button;
    QSpacerItem *horizontalSpacer_4;
    QTableView *financenote_record_table;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *add_record_Button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Financenote_Window)
    {
        if (Financenote_Window->objectName().isEmpty())
            Financenote_Window->setObjectName("Financenote_Window");
        Financenote_Window->resize(800, 600);
        centralwidget = new QWidget(Financenote_Window);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(260, 370, 160, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        exit_Button = new QPushButton(horizontalLayoutWidget);
        exit_Button->setObjectName("exit_Button");

        horizontalLayout_3->addWidget(exit_Button);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        financenote_record_table = new QTableView(centralwidget);
        financenote_record_table->setObjectName("financenote_record_table");
        financenote_record_table->setGeometry(QRect(130, 100, 256, 192));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(460, 230, 160, 80));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        add_record_Button = new QPushButton(centralwidget);
        add_record_Button->setObjectName("add_record_Button");
        add_record_Button->setGeometry(QRect(190, 330, 80, 18));
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
        exit_Button->setText(QCoreApplication::translate("Financenote_Window", "\351\200\200\345\207\272", nullptr));
        add_record_Button->setText(QCoreApplication::translate("Financenote_Window", "\346\267\273\345\212\240\344\270\200\346\235\241\350\264\246\345\215\225\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Financenote_Window: public Ui_Financenote_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINANCENOTE_WINDOW_H
