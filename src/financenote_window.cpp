#include "financenote_window.h"
#include "./ui_financenote_window.h"

Financenote_Window::Financenote_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Financenote_Window)
{
    ui->setupUi(this);
}

Financenote_Window::~Financenote_Window()
{
    delete ui;
}
