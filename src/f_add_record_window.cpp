#include "f_add_record_window.h"
#include "./ui_f_add_record_window.h"

f_add_record_Window::f_add_record_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::f_add_record_Window)
{
    ui->setupUi(this);
    setWindowTitle("添加一条账单记录...");
}

f_add_record_Window::~f_add_record_Window()
{
    delete ui;
}