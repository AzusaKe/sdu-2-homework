#include "mainwindow.h"
#include "./ui_mainwindow.h"
//构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("桌面工具");
    connect(ui->financenote_Button,&QPushButton::clicked,this, &MainWindow::on_financenote_button_clicked);
    connect(ui->reminder_Button,&QPushButton::clicked,this, &MainWindow::on_reminder_button_clicked);
    connect(ui->passwordmanager_Button,&QPushButton::clicked,this, &MainWindow::on_passwordmanager_button_clicked);
    connect(ui->exit_Button,&QPushButton::clicked,this, &MainWindow::on_exit_button_clicked);
}
//析构函数
MainWindow::~MainWindow()
{
    delete ui;
}
//设置指针函数
void MainWindow::set_ptr_financenote_2(financenote *ptr) {
    finance_note_ptr_2 = ptr;
}

void MainWindow::set_ptr_reminder_2(reminder *ptr) {
    reminder_temp_ptr_2 = ptr;
}

void MainWindow::set_ptr_passwordmanager_2(passwordmanager *ptr) {
    password_manager_ptr_2 = ptr;
}

//窗口功能实现
//记账本按钮
void MainWindow::on_financenote_button_clicked() {
    Financenote_Window *financenote_window = new Financenote_Window(this);
    financenote_window->set_ptr(finance_note_ptr_2);
    this->hide();
    financenote_window->show();
    connect(financenote_window, &Financenote_Window::destroyed, this, &MainWindow::show);
}
//日程提醒按钮
void MainWindow::on_reminder_button_clicked() {
    Reminder_Window *reminder_window = new Reminder_Window(this);
    reminder_window->set_ptr(reminder_temp_ptr_2);
    this->hide();
    reminder_window->show();
    connect(reminder_window, &Reminder_Window::destroyed, this, &MainWindow::show);
}
//密码管理器按钮
void MainWindow::open_passwordmanager_window() {
    Passwordmanager_Window *passwordmanager_window = new Passwordmanager_Window(this);
    passwordmanager_window->set_ptr(password_manager_ptr_2);
    passwordmanager_window->show();
    connect(passwordmanager_window, &Passwordmanager_Window::destroyed, this, &MainWindow::show);
}
//密码管理器身份验证按钮
void MainWindow::on_passwordmanager_button_clicked() {
    Passwordauth_Window *passwordauth_window = new Passwordauth_Window(this);
    this->hide();
    passwordauth_window->show();
    passwordauth_window->set_ptr(password_manager_ptr_2);
    connect(passwordauth_window,SIGNAL(authenticated()),this,SLOT(open_passwordmanager_window()));
    connect(passwordauth_window, &Passwordauth_Window::destroyed, this, &MainWindow::show);
}
//退出按钮
void MainWindow::on_exit_button_clicked() {
    close();
    emit exit();
}
