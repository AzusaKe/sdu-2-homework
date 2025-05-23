#include "passwordauth_window.h"
#include "./ui_passwordauth_window.h"

Passwordauth_Window::Passwordauth_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Passwordauth_Window)
{
    ui->setupUi(this);
    setWindowTitle("用户身份验证...");
}

Passwordauth_Window::~Passwordauth_Window()
{
    delete ui;
}
