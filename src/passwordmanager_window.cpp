#include "passwordmanager_window.h"
#include "./ui_passwordmanager_window.h"

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
