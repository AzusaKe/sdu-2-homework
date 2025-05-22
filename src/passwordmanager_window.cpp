#include "passwordmanager_window.h"
#include "./ui_passwordmanager_window.h"

Passwordmanager_Window::Passwordmanager_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Passwordmanager_Window)
{
    ui->setupUi(this);
}

Passwordmanager_Window::~Passwordmanager_Window()
{
    delete ui;
}
