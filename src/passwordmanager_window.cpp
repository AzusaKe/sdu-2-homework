#include "passwordmanager_window.h"
#include "./ui_passwordmanager_window.h"
#include "log.h"

Passwordmanager_Window::Passwordmanager_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Passwordmanager_Window)
{
    ui->setupUi(this);
    setWindowTitle("桌面工具-密码管理器");
    connect(ui->exit_Button,&QPushButton::clicked,this, &Passwordmanager_Window::close);
}

Passwordmanager_Window::~Passwordmanager_Window()
{
    delete ui;
    for (QObject *child : children()) {
        *(azusa_log::log) << "正在析构子对象：" << child->objectName().toStdString() << endl;
        delete child; //析构子对象
    }
    *(azusa_log::log) << "密码管理器窗口已析构！" << endl;
}
//设置指针函数
void Passwordmanager_Window::set_ptr(passwordmanager *ptr) {
    password_manager_ptr_4 = ptr;
}

void Passwordmanager_Window::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    password_manager_ptr_4->close();
    emit destroyed();
}
