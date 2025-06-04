#include "p_add_record_window.h"
#include "./ui_p_add_record_window.h"

p_add_record_Window::p_add_record_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::p_add_record_Window)
{
    ui->setupUi(this);
    setWindowTitle("添加一条密码记录...");
    connect(ui->exit_Button, &QPushButton::clicked, this, &p_add_record_Window::close);
    connect(ui->add_Button, &QPushButton::clicked, this, &p_add_record_Window::on_add_record_Button_clicked);
}

p_add_record_Window::~p_add_record_Window()
{
    delete ui;
}

void p_add_record_Window::set_ptr(passwordmanager *ptr) {
    password_manager_ptr_6 = ptr;
}

void p_add_record_Window::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    if (password_manager_ptr_6) {
        password_manager_ptr_6->close();
    }
    emit destroyed();
}

void p_add_record_Window::on_add_record_Button_clicked() {
    string site_name = ui->sitename_lineEdit->text().toStdString();
    string username = ui->username_lineEdit->text().toStdString();
    string password = password_manager_ptr_6->encoder(ui->passeord_lineEdit->text().toStdString());

    if (site_name.empty() || username.empty() || password.empty()) {
        QMessageBox::warning(this, "警告", "请填写所有字段！");
        return;
    }

    if (password_manager_ptr_6->is_already_exist(site_name, username, password)) {
        QMessageBox::warning(this, "警告", "该记录已经存在！");
        return;
    }

    password_manager_ptr_6->add_entry(site_name, username, password);
    password_manager_ptr_6->search("");
    password_manager_ptr_6->sort();
    emit refresh(); // 发送刷新信号
    close(); // 关闭窗口
}