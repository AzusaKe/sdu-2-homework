#include "p_add_record_window.h"
#include "./ui_p_add_record_window.h"

p_add_record_Window::p_add_record_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::p_add_record_Window)
{
    ui->setupUi(this);
}

p_add_record_Window::~p_add_record_Window()
{
    delete ui;
}
