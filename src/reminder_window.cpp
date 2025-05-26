#include "reminder_window.h"
#include "./ui_reminder_window.h"

Reminder_Window::Reminder_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reminder_Window)
{
    ui->setupUi(this);
    setWindowTitle("桌面工具-日程提醒");
    connect(ui->exit_Button,&QPushButton::clicked,this, &Reminder_Window::close);
}

Reminder_Window::~Reminder_Window()
{
    delete ui;
}
//设置指针函数
void Reminder_Window::set_ptr(reminder *ptr) {
    reminder_temp_ptr_3 = ptr;
}

//关闭窗口事件
void Reminder_Window::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    reminder_temp_ptr_3->close();
    emit destroyed();
}
