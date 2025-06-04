#include "passwordmanager_window.h"
#include "./ui_passwordmanager_window.h"
#include "log.h"

Passwordmanager_Window::Passwordmanager_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Passwordmanager_Window)
{
    ui->setupUi(this);
    setWindowTitle("桌面工具-密码管理器");
    ui->passwordmanager_record_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->passwordmanager_record_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->exit_Button,&QPushButton::clicked,this, &Passwordmanager_Window::close);
}

Passwordmanager_Window::~Passwordmanager_Window()
{
    delete ui;
    *(azusa_log::log) << "密码管理器窗口已析构！" << endl;
}
//设置指针函数
void Passwordmanager_Window::set_ptr(passwordmanager *ptr) {
    password_manager_ptr_4 = ptr;
    if (!password_manager_ptr_4) {
        *(azusa_log::log) << "Error: 密码管理器指针为空!" << endl;
        return;
    }
    password_manager_ptr_4->search("");
    password_manager_ptr_4->sort(); // 确保数据已排序
}

void Passwordmanager_Window::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    password_manager_ptr_4->close();
    emit destroyed();
}
