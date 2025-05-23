/********************************************************************************
** Form generated from reading UI file 'p_add_record_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_P_ADD_RECORD_WINDOW_H
#define UI_P_ADD_RECORD_WINDOW_H

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

class Ui_p_add_record_Window
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *sitename_lineEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *username_lineEdit;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *passeord_lineEdit;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *p_add_record_Window)
    {
        if (p_add_record_Window->objectName().isEmpty())
            p_add_record_Window->setObjectName("p_add_record_Window");
        p_add_record_Window->resize(279, 231);
        centralwidget = new QWidget(p_add_record_Window);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

        sitename_lineEdit = new QLineEdit(centralwidget);
        sitename_lineEdit->setObjectName("sitename_lineEdit");

        horizontalLayout_4->addWidget(sitename_lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        username_lineEdit = new QLineEdit(centralwidget);
        username_lineEdit->setObjectName("username_lineEdit");

        horizontalLayout->addWidget(username_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        horizontalLayout_2->addWidget(label_6);

        passeord_lineEdit = new QLineEdit(centralwidget);
        passeord_lineEdit->setObjectName("passeord_lineEdit");
        passeord_lineEdit->setFrame(true);
        passeord_lineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_2->addWidget(passeord_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        p_add_record_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(p_add_record_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 279, 17));
        p_add_record_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(p_add_record_Window);
        statusbar->setObjectName("statusbar");
        p_add_record_Window->setStatusBar(statusbar);

        retranslateUi(p_add_record_Window);

        QMetaObject::connectSlotsByName(p_add_record_Window);
    } // setupUi

    void retranslateUi(QMainWindow *p_add_record_Window)
    {
        p_add_record_Window->setWindowTitle(QCoreApplication::translate("p_add_record_Window", "p_add_record_Window", nullptr));
        label->setText(QCoreApplication::translate("p_add_record_Window", "\350\257\267\345\213\277\345\234\250\344\270\255\351\227\264\350\276\223\345\205\245\347\251\272\346\240\274\357\274\201", nullptr));
        label_2->setText(QCoreApplication::translate("p_add_record_Window", "\347\275\221\347\253\231\345\220\215\347\247\260", nullptr));
        label_3->setText(QCoreApplication::translate("p_add_record_Window", "\344\276\213\357\274\232www.google.com", nullptr));
        label_4->setText(QCoreApplication::translate("p_add_record_Window", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_5->setText(QCoreApplication::translate("p_add_record_Window", "\344\276\213\357\274\232user_name", nullptr));
        label_6->setText(QCoreApplication::translate("p_add_record_Window", "\345\257\206\347\240\201", nullptr));
        passeord_lineEdit->setText(QString());
        pushButton->setText(QCoreApplication::translate("p_add_record_Window", "\346\267\273\345\212\240", nullptr));
        pushButton_2->setText(QCoreApplication::translate("p_add_record_Window", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class p_add_record_Window: public Ui_p_add_record_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P_ADD_RECORD_WINDOW_H
