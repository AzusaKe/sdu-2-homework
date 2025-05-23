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
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_r_add_record_Window
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *content_lineEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *priority_spinBox;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *add_Button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exit_Button;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *r_add_record_Window)
    {
        if (r_add_record_Window->objectName().isEmpty())
            r_add_record_Window->setObjectName("r_add_record_Window");
        r_add_record_Window->setEnabled(true);
        r_add_record_Window->resize(277, 189);
        centralwidget = new QWidget(r_add_record_Window);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(17, 48, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName("dateTimeEdit");

        horizontalLayout->addWidget(dateTimeEdit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        content_lineEdit = new QLineEdit(centralwidget);
        content_lineEdit->setObjectName("content_lineEdit");

        horizontalLayout_2->addWidget(content_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        priority_spinBox = new QSpinBox(centralwidget);
        priority_spinBox->setObjectName("priority_spinBox");
        priority_spinBox->setEnabled(true);
        priority_spinBox->setMouseTracking(false);
        priority_spinBox->setMinimum(1);
        priority_spinBox->setMaximum(3);

        horizontalLayout_3->addWidget(priority_spinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

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

        r_add_record_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(r_add_record_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 277, 17));
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
        label->setText(QCoreApplication::translate("r_add_record_Window", "\350\257\267\345\213\277\345\234\250\344\270\255\351\227\264\350\276\223\345\205\245\347\251\272\346\240\274\357\274\201", nullptr));
        label_4->setText(QCoreApplication::translate("r_add_record_Window", "\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("r_add_record_Window", "\344\272\213\351\241\271", nullptr));
        label_2->setText(QCoreApplication::translate("r_add_record_Window", "\344\274\230\345\205\210\347\272\247", nullptr));
        add_Button->setText(QCoreApplication::translate("r_add_record_Window", "\346\267\273\345\212\240", nullptr));
        exit_Button->setText(QCoreApplication::translate("r_add_record_Window", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class r_add_record_Window: public Ui_r_add_record_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_R_ADD_RECORD_WINDOW_H
