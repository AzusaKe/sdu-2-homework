#include "r_add_record_window.h"
#include "./ui_r_add_record_window.h"

r_add_record_Window::r_add_record_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::r_add_record_Window)
{
    ui->setupUi(this);
}

r_add_record_Window::~r_add_record_Window()
{
    delete ui;
}
