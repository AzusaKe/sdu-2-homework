#include "reminder_window.h"
#include "./ui_reminder_window.h"

Reminder_Window::Reminder_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reminder_Window)
{
    ui->setupUi(this);
}

Reminder_Window::~Reminder_Window()
{
    delete ui;
}
