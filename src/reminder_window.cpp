#include "reminder_window.h"
#include "./ui_reminder_window.h"

Reminder_Window::Reminder_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reminder_Window)
{
    ui->setupUi(this);
    setWindowTitle("桌面工具-日程提醒");
}

Reminder_Window::~Reminder_Window()
{
    delete ui;
}
