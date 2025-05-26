#include "financenote_window.h"
#include "./ui_financenote_window.h"

Financenote_Window::Financenote_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Financenote_Window)
{
    ui->setupUi(this);
    setWindowTitle("桌面工具-记账本");
    connect(ui->exit_Button,&QPushButton::clicked,this, &Financenote_Window::close);
}

Financenote_Window::~Financenote_Window()
{
    delete ui;
}
//设置指针函数
void Financenote_Window::set_ptr(financenote *ptr) {
    finance_note_ptr_3 = ptr;
}

void Financenote_Window::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    emit destroyed();
}
