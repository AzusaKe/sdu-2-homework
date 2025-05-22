#include "passwordauth_window.h"
#include "./ui_passwordauth_window.h"

Passwordauth_Window::Passwordauth_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Passwordauth_Window)
{
    ui->setupUi(this);
}

Passwordauth_Window::~Passwordauth_Window()
{
    delete ui;
}
