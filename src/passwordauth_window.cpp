#include "passwordauth_window.h"
#include "./ui_passwordauth_window.h"
#include "console_adaption.h"
#include "SHA_256.h"

Passwordauth_Window::Passwordauth_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Passwordauth_Window)
{
    ui->setupUi(this);
    setWindowTitle("用户身份验证...");
    connect(ui->confirm_Button, &QPushButton::clicked, this, &Passwordauth_Window::authenticate);
    connect(ui->exit_Button, &QPushButton::clicked, this, &Passwordauth_Window::close);
}

Passwordauth_Window::~Passwordauth_Window()
{
    delete ui;
}

//设置指针函数
void Passwordauth_Window::set_ptr(passwordmanager *ptr) {
    password_manager_ptr_5 = ptr;
    if (!password_manager_ptr_5->is_new_user_flag()) {
        ui->label->setText("请验证你的用户凭据：");
    }else {
        QMessageBox::warning(this,"尚未创建凭据","该密码管理器尚未创建用户凭据，请先创建用户凭据！", QMessageBox::Ok);
        ui->label->setText("请创建你的用户凭据：");
        ui->confirm_Button->setText("创建");
    }
}

void Passwordauth_Window::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    if (is_authenticated) {
        emit authenticated();
    }else {
        emit destroyed();
    }
}

void Passwordauth_Window::authenticate() {
    try {
        if (!password_manager_ptr_5->is_new_user_flag()) {
            std::string input_password = ui->auth_lineEdit->text().toStdString();
            string temp_input_password = SHA256::sha_256(input_password);
            is_authenticated = password_manager_ptr_5->is_correct_key(temp_input_password);
            *(azusa_log::log) << "身份验证结果：" << (is_authenticated ? "成功" : "失败") << endl;
            if (is_authenticated) {
                *(azusa_log::log) << "身份验证成功！" << endl;
                QMessageBox::information(this, "身份验证成功", "欢迎使用密码管理器！", QMessageBox::Ok);
                password_manager_ptr_5->set_key_graphic(input_password);
                close();
            }else {
                ui->auth_lineEdit->clear();
                QMessageBox::warning(this, "身份验证失败", "密码错误，请重新输入！", QMessageBox::Ok);
            }
        }else {
            password_manager_ptr_5->set_correct_key_sha_256(ui->auth_lineEdit->text().toStdString());
            is_authenticated = true;
            *(azusa_log::log) << "用户凭据已创建！" << endl;
            close();
        }
    }catch (const std::exception& e) {
        *(azusa_log::log) << "Error(Passwordauth_Window::authenticate): " << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }
}


