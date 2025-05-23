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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_f_add_record_Window
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *dateEdit;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *amount_lineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *category_lineEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *add_Button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exit_Button;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *f_add_record_Window)
    {
        if (f_add_record_Window->objectName().isEmpty())
            f_add_record_Window->setObjectName("f_add_record_Window");
        f_add_record_Window->resize(280, 190);
        centralwidget = new QWidget(f_add_record_Window);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName("dateEdit");

        horizontalLayout->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        amount_lineEdit = new QLineEdit(centralwidget);
        amount_lineEdit->setObjectName("amount_lineEdit");

        horizontalLayout_2->addWidget(amount_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        category_lineEdit = new QLineEdit(centralwidget);
        category_lineEdit->setObjectName("category_lineEdit");

        horizontalLayout_3->addWidget(category_lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        add_Button = new QPushButton(centralwidget);
        add_Button->setObjectName("add_Button");

        horizontalLayout_4->addWidget(add_Button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        exit_Button = new QPushButton(centralwidget);
        exit_Button->setObjectName("exit_Button");

        horizontalLayout_4->addWidget(exit_Button);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        f_add_record_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(f_add_record_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 280, 17));
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
        label_4->setText(QCoreApplication::translate("f_add_record_Window", "\350\257\267\345\213\277\345\234\250\344\270\255\351\227\264\350\276\223\345\205\245\347\251\272\346\240\274\357\274\201", nullptr));
        label->setText(QCoreApplication::translate("f_add_record_Window", "\346\227\245\346\234\237\357\274\210YYYY-MM-DD\357\274\211", nullptr));
        label_2->setText(QCoreApplication::translate("f_add_record_Window", "\351\207\221\351\242\235", nullptr));
        label_3->setText(QCoreApplication::translate("f_add_record_Window", "\345\244\207\346\263\250", nullptr));
        add_Button->setText(QCoreApplication::translate("f_add_record_Window", "\346\267\273\345\212\240", nullptr));
        exit_Button->setText(QCoreApplication::translate("f_add_record_Window", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class f_add_record_Window: public Ui_f_add_record_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_ADD_RECORD_WINDOW_H
