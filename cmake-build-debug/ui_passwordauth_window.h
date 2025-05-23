/********************************************************************************
** Form generated from reading UI file 'passwordauth_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDAUTH_WINDOW_H
#define UI_PASSWORDAUTH_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_Passwordauth_Window
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *auth_lineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirm_Button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exit_Button;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Passwordauth_Window)
    {
        if (Passwordauth_Window->objectName().isEmpty())
            Passwordauth_Window->setObjectName("Passwordauth_Window");
        Passwordauth_Window->resize(254, 117);
        centralwidget = new QWidget(Passwordauth_Window);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        auth_lineEdit = new QLineEdit(centralwidget);
        auth_lineEdit->setObjectName("auth_lineEdit");
        auth_lineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(auth_lineEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        confirm_Button = new QPushButton(centralwidget);
        confirm_Button->setObjectName("confirm_Button");

        horizontalLayout->addWidget(confirm_Button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        exit_Button = new QPushButton(centralwidget);
        exit_Button->setObjectName("exit_Button");

        horizontalLayout->addWidget(exit_Button);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        Passwordauth_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Passwordauth_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 254, 17));
        Passwordauth_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Passwordauth_Window);
        statusbar->setObjectName("statusbar");
        Passwordauth_Window->setStatusBar(statusbar);

        retranslateUi(Passwordauth_Window);

        QMetaObject::connectSlotsByName(Passwordauth_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Passwordauth_Window)
    {
        Passwordauth_Window->setWindowTitle(QCoreApplication::translate("Passwordauth_Window", "Passwordauth_Window", nullptr));
        label->setText(QCoreApplication::translate("Passwordauth_Window", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\207\255\346\215\256:", nullptr));
        confirm_Button->setText(QCoreApplication::translate("Passwordauth_Window", "\347\241\256\350\256\244", nullptr));
        exit_Button->setText(QCoreApplication::translate("Passwordauth_Window", "\345\217\226\346\266\210\345\271\266\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Passwordauth_Window: public Ui_Passwordauth_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDAUTH_WINDOW_H
